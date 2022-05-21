/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
    /* 8 normal colors */
    "#32302f", /* black   */
    "#ea6962", /* red     */
    "#a9b665", /* green   */
    "#e78a4e", /* yellow  */
    "#7daea3", /* blue    */
    "#d3869b", /* magenta */
    "#89b482", /* cyan    */
    "#d4be98", /* white   */

    /* 8 bright colors */
    "#32302f", /* black   */
    "#ea6962", /* red     */
    "#a9b665", /* green   */
    "#e78a4e", /* yellow  */
    "#7daea3", /* blue    */
    "#d3869b", /* magenta */
    "#89b482", /* cyan    */
    "#d4be98", /* white   */

    [255] = 0,

    /* more colors can be added after 255 to use with DefaultXX */
    "#add8e6", /* 256 -> cursor */
    "#555555", /* 257 -> rev cursor*/
    "#1d2021", /* background */
    "#d4be98", /* foreground */
};
