azcore_files = []

subdir('AzCore')

azcore_lib = static_library('AzCore',
    azcore_files,
    include_directories: 'Platform/Linux',
    dependencies: [rapidjson_dep, rapidxml_dep, zstd_dep]
    )
