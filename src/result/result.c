#include "result/result.h"

bool is_error(Result const res) { return res.status == Error; }
