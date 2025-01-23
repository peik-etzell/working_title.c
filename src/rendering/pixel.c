#include "pixel.h"

#include <assert.h>

// https://stackoverflow.com/a/74186686
// Converted to C code with python script
static const int n_ascii = 92;
static const struct {
    float luminance;
    char ascii;
} ascii_luminance_table[] = {
    {0, ' '},        {0.0751f, '`'}, {0.0829f, '.'}, {0.0848f, '-'},
    {0.1227f, '\''}, {0.1403f, ':'}, {0.1559f, '_'}, {0.185f, ','},
    {0.2183f, '^'},  {0.2417f, '='}, {0.2571f, ';'}, {0.2852f, '>'},
    {0.2902f, '<'},  {0.2919f, '+'}, {0.3099f, '!'}, {0.3192f, 'r'},
    {0.3232f, 'c'},  {0.3294f, '*'}, {0.3384f, '/'}, {0.3609f, 'z'},
    {0.3619f, '?'},  {0.3667f, 's'}, {0.3737f, 'L'}, {0.3747f, 'T'},
    {0.3838f, 'v'},  {0.3921f, ')'}, {0.396f, 'J'},  {0.3984f, '7'},
    {0.3993f, '('},  {0.4075f, '|'}, {0.4091f, 'F'}, {0.4101f, 'i'},
    {0.42f, '{'},    {0.423f, 'C'},  {0.4247f, '}'}, {0.4274f, 'f'},
    {0.4293f, 'I'},  {0.4328f, '3'}, {0.4382f, '1'}, {0.4385f, 't'},
    {0.442f, 'l'},   {0.4473f, 'u'}, {0.4477f, '['}, {0.4503f, 'n'},
    {0.4562f, 'e'},  {0.458f, 'o'},  {0.461f, 'Z'},  {0.4638f, '5'},
    {0.4667f, 'Y'},  {0.4686f, 'x'}, {0.4693f, 'j'}, {0.4703f, 'y'},
    {0.4833f, 'a'},  {0.4881f, ']'}, {0.4944f, '2'}, {0.4953f, 'E'},
    {0.4992f, 'S'},  {0.5509f, 'w'}, {0.5567f, 'q'}, {0.5569f, 'k'},
    {0.5591f, 'P'},  {0.5602f, '6'}, {0.5602f, 'h'}, {0.565f, '9'},
    {0.5776f, 'd'},  {0.5777f, '4'}, {0.5818f, 'V'}, {0.587f, 'p'},
    {0.5972f, 'O'},  {0.5999f, 'G'}, {0.6043f, 'b'}, {0.6049f, 'U'},
    {0.6093f, 'A'},  {0.6099f, 'K'}, {0.6465f, 'X'}, {0.6561f, 'H'},
    {0.6595f, 'm'},  {0.6631f, '8'}, {0.6714f, 'R'}, {0.6759f, 'D'},
    {0.6809f, '#'},  {0.6816f, '$'}, {0.6925f, 'B'}, {0.7039f, 'g'},
    {0.7086f, '0'},  {0.7235f, 'M'}, {0.7302f, 'N'}, {0.7332f, 'W'},
    {0.7602f, 'Q'},  {0.7834f, '%'}, {0.8037f, '&'}, {0.9999f, '@'},
};

// Binary search for close match to wanted luminance value
// lo inclusive, hi inclusive, indices
static char lum2char_rec(int lo, int hi, float luminance) {
    assert(0 <= lo && lo < n_ascii);
    assert(0 <= hi && hi < n_ascii);

    if (lo >= hi) return ascii_luminance_table[hi].ascii;

    int med = (lo + hi) >> 1;
    if (luminance > ascii_luminance_table[med].luminance)
        return lum2char_rec(med + 1, hi, luminance);

    return lum2char_rec(lo, med, luminance);
}

char lum2char(float luminance) {
    assert(luminance >= 0);
    assert(luminance <= 1);
    assert(ascii_luminance_table[n_ascii - 1].ascii == '@');

    return lum2char_rec(0, n_ascii - 1, luminance);
}
