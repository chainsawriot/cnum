// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// c2integer_conv
long long c2integer_conv(const std::vector<std::string> number, const List conv_t);
RcppExport SEXP _cnum_c2integer_conv(SEXP numberSEXP, SEXP conv_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string> >::type number(numberSEXP);
    Rcpp::traits::input_parameter< const List >::type conv_t(conv_tSEXP);
    rcpp_result_gen = Rcpp::wrap(c2integer_conv(number, conv_t));
    return rcpp_result_gen;
END_RCPP
}
// c2integer_literal
std::string c2integer_literal(const std::vector<std::string> number, const List conv_t);
RcppExport SEXP _cnum_c2integer_literal(SEXP numberSEXP, SEXP conv_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string> >::type number(numberSEXP);
    Rcpp::traits::input_parameter< const List >::type conv_t(conv_tSEXP);
    rcpp_result_gen = Rcpp::wrap(c2integer_literal(number, conv_t));
    return rcpp_result_gen;
END_RCPP
}
// integer2c
std::string integer2c(const std::string number, const List conv_t);
RcppExport SEXP _cnum_integer2c(SEXP numberSEXP, SEXP conv_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type number(numberSEXP);
    Rcpp::traits::input_parameter< const List >::type conv_t(conv_tSEXP);
    rcpp_result_gen = Rcpp::wrap(integer2c(number, conv_t));
    return rcpp_result_gen;
END_RCPP
}
// integer2c_literal
std::string integer2c_literal(const std::string number, const List conv_t);
RcppExport SEXP _cnum_integer2c_literal(SEXP numberSEXP, SEXP conv_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type number(numberSEXP);
    Rcpp::traits::input_parameter< const List >::type conv_t(conv_tSEXP);
    rcpp_result_gen = Rcpp::wrap(integer2c_literal(number, conv_t));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_cnum_c2integer_conv", (DL_FUNC) &_cnum_c2integer_conv, 2},
    {"_cnum_c2integer_literal", (DL_FUNC) &_cnum_c2integer_literal, 2},
    {"_cnum_integer2c", (DL_FUNC) &_cnum_integer2c, 2},
    {"_cnum_integer2c_literal", (DL_FUNC) &_cnum_integer2c_literal, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_cnum(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
