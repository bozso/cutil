#ifndef CPPUTIL_RESULT_OPTION_H
#define CPPUTIL_RESULT_OPTION_H

#include "id.h"

typedef enum OptionTag {
    OptionSome,
    OptionNone,
} OptionTag;

typedef struct Option {
    OptionTag tag;
    result_id id;
} Option;

Option option_some(result_id id);
Option option_none(void);

#endif
