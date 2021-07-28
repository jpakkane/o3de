aztest_files = []

subdir('AzTest')

aztest_lib = static_library('AzTest',
  aztest_files,
  include_directories: ['../AzCore', '../AzCore/Platform/Linux', 'AzTest/Platform/Linux'],
  dependencies: [rapidjson_dep, gmock_dep, gtest_dep],
)
