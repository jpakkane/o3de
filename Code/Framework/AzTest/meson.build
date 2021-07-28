aztest_files = []

subdir('AzTest')

aztest_lib = static_library('AzTest',
  aztest_files,
  include_directories: ['AzTest/Platform/Linux'],
  dependencies: [azcore_dep, rapidjson_dep, gmock_dep, gtest_dep],
)
