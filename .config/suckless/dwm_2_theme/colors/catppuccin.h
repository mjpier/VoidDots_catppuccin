/* Colors */
static const char black[]           = "#1e1d2d";
static const char gray2[]           = "#282737"; // unfocused window border
static const char gray3[]           = "#585767";
static const char gray4[]           = "#282737";
static const char red[]             = "#f28fad"; // focused window border
static const char green[]           = "#abe9b3";
static const char blue[]            = "#96cdfb";
static const char red2[]            = "#f8bd96";
static const char yellow[]          = "#fae3b0";
static const char magenta[]         = "#d5aeea";

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
