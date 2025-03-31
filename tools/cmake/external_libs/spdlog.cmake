include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog"
    GIT_TAG v1.15.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)
