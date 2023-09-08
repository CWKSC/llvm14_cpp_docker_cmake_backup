#pragma once

#include <string>
#include <vector>

#include "../Common/Token/BaseToken/BaseToken.h"
#include "PureStruct/TaggingResult.h"

TaggingResult tagging(const std::vector<BaseToken> &tokenList);