/* Colors */
static const char black[]           = "#1d2021";
static const char gray2[]           = "#282b2c"; // unfocused window border
static const char gray3[]           = "#5d6061";
static const char gray4[]           = "#282b2c";
static const char red[]             = "#770000"; // focused window border
static const char green[]           = "#a9b665";
static const char blue[]            = "#7daea3";
static const char red2[]            = "#ea6962";
static const char yellow[]          = "#e78a4e";
static const char magenta[]         = "#d3869b";

static const char *colors[][3]      = {
    /*              fg              bg      border  */
    [SchemeNorm]    = { gray3,      black,  gray2 },
    [SchemeSel]     = { gray4,      black,  red   },
    [SchemeTitle]   = { blue,       black,  black },
    [SchemeTag]     = { gray3,      black,  black },
    [SchemeTag1]    = { blue,       black,  black },
    [SchemeTag2]    = { red2,       black,  black },
    [SchemeTag3]    = { yellow,     black,  black },
    [SchemeTag4]    = { green,      black,  black },
    [SchemeTag5]    = { magenta,    black,  black },
    [SchemeLayout]  = { green,      black,  black },
};
