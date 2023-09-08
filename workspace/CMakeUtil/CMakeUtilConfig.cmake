
function(include_relative fileName)
    include(${CMAKE_CURRENT_LIST_DIR}/${fileName}.cmake)
endfunction()

include_relative(Common)
include_relative(AddSubdirectory)
include_relative(Namespace)
include_relative(Target)
include_relative(CreateLibrary)
include_relative(CreateMain)
include_relative(TargetLinkLibrary)
include_relative(Install)

include_relative(GTest)
include_relative(LLVM)
