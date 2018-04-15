#if defined(__ANDROID__) && (__ANDROID_API__ < 21)
#include <locale.h>
#include <limits.h>

locale_t newlocale(int category_mask, const char* locale, locale_t base) {
  return LC_GLOBAL_LOCALE;
}

void freelocale(locale_t loc) {
}

char *setlocale(int category, const char *locale) {
  return (char*) "C";
}

locale_t uselocale(locale_t loc)
{
  return LC_GLOBAL_LOCALE;
}

struct lconv* localeconv(void) {
  static struct lconv C_LCONV[1] = { {
      .decimal_point = ".",
      .thousands_sep = "",
      .grouping = "",
      .int_curr_symbol = "",
      .currency_symbol = "",
      .mon_decimal_point = "",
      .mon_thousands_sep = "",
      .mon_grouping = "",
      .positive_sign = "",
      .negative_sign = "",
      .int_frac_digits = CHAR_MAX,
      .frac_digits = CHAR_MAX,
      .p_cs_precedes = CHAR_MAX,
      .p_sep_by_space = CHAR_MAX,
      .n_cs_precedes = CHAR_MAX,
      .n_sep_by_space = CHAR_MAX,
      .p_sign_posn = CHAR_MAX,
      .n_sign_posn = CHAR_MAX,
      .int_p_cs_precedes = CHAR_MAX,
      .int_p_sep_by_space = CHAR_MAX,
      .int_n_cs_precedes = CHAR_MAX,
      .int_n_sep_by_space = CHAR_MAX,
      .int_p_sign_posn = CHAR_MAX,
      .int_n_sign_posn = CHAR_MAX,
    }};

  return C_LCONV;
}
#endif
