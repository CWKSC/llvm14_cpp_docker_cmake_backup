#pragma once

#include <string>
#include <vector>

#include "../Common/Token/BaseToken/BaseToken.h"

#include "PureStruct/LexingResult.h"
#include "PureStruct/LimitCountInfo.h"

LexingResult lexing(std::string text, bool isForward = true,
                    LimitCountInfo limitTimesInfo = LimitCountInfo());
