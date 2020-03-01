#' @describeIn conversion Convert Chinese Numerals to Arabic Numerals.
#'
#' @examples
#' \dontrun{
#' c2num("hello")
#' }
#'
#' @export
#'
c2num <- function(x, lang = "tc", mode = "casual", financial = FALSE, literal = FALSE) {
  if (length(x) > 1) {
    return(sapply(x, function(y) c2num(y, lang, mode, financial)))
  }
  if (!is.character(x)) {
    message("`x` coerced into character.")
    x <- as.character(x)
  }

  conv_t <- conv_table(lang, mode, financial)
  scale_t <- conv_t[["scale_t"]]
  dot <- conv_t[["dot"]]

  number_split <- split_numeral(x, conv_t, mode)

  if (grepl(conv_t[["neg"]], number_split[1])) {
    neg <- "-"
    number_split <- number_split[-1]
  } else {
    neg <- ""
  }

  i <- grep(dot, number_split) # index of dot
  j <- ifelse(any(number_split %in% scale_t$c), # index of last scale char
              max(which(number_split %in% scale_t$c)), 0)
  if (length(i) == 1) {
    if (i < j & j == length(number_split)) {
      # the position of dot is before a scale char: a numeral with single scale char
      converted <- as.numeric(paste0(neg, c2integer(number_split[1:(i - 1)], conv_t),
                                     c2decimal(number_split[i:(length(number_split) - 1)], conv_t)))
      converted <- converted * 10^(scale_t$n[scale_t$c == number_split[j]] - 1)
    } else {
      if (literal) {
        converted <- as.numeric(paste0(neg, gsub("\\.", "", c2integer_literal(number_split[1:(i - 1)], conv_t)),
                                       c2decimal(number_split[i:length(number_split)], conv_t)))
      } else {
        converted <- as.numeric(paste0(neg, c2integer(number_split[1:(i - 1)], conv_t),
                                       c2decimal(number_split[i:length(number_split)], conv_t)))
      }
    }
  } else if (length(i) == 0) {
    if (literal) {
      converted <- as.numeric(paste0(neg, c2integer_literal(number_split, conv_t)))
    } else {
      converted <- as.numeric(paste0(neg, c2integer(number_split, conv_t)))
    }
  } else {
    stop("`x` must not contain more than one occurance of `", dot, "`.")
  }
  if (x != num2c(converted, lang, mode, financial, literal)) {
    if (x != num2c(converted, lang, mode, financial, literal, single = TRUE)) {
      stop("`x` is not valid Chinese numeral.")
    }
  }
  converted
}