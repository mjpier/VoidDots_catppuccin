/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
    /* 8 normal colors */
    "#6e6c7e", /* black   */
    "#e38c8f", /* red     */
    "#b1e3ad", /* green   */
    "#ebddaa", /* yellow  */
    "#a4b9ef", /* blue    */
    "#c6aae8", /* magenta */
    "#e5b4e2", /* cyan    */
    "#dadae8", /* white   */

    /* 8 bright colors */
    "#6e6c7e", /* black   */
    "#e38c8f", /* red     */
    "#b1e3ad", /* green   */
    "#ebddaa", /* yellow  */
    "#a4b9ef", /* blue    */
    "#c6aae8", /* magenta */
    "#e5b4e2", /* cyan    */
    "#dadae8", /* white   */

    [255] = 0,

    /* more colors can be added after 255 to use with DefaultXX */
    "#dadae8", /* 256 -> cursor */
    "#1e1e2e", /* 257 -> rev cursor*/
    "#1e1e2e", /* background */
    "#dadae8", /* foreground */
};
