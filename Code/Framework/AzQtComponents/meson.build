azqtcomponents_files = []

subdir('AzQtComponents')

azqtcomponents_lib = shared_library('AzQtComponents',
    azqtcomponents_files,
    cpp_args: ['-DMESON_BUILD'],
    dependencies: [azcore_dep, azframework_dep, qt5svg_dep, qt5xml_dep, qt5_dep],
)
