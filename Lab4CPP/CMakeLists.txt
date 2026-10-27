add_executable(KruskalMST kruskal_mst.cpp)
target_include_directories(KruskalMST PUBLIC ../LibraryCPPTemplate)

foreach(test_name tree split one triangle empty bidir)
    add_test(NAME Kruskal_${test_name} COMMAND ${CMAKE_COMMAND}
        -DPROGRAM=$<TARGET_FILE:KruskalMST>
        -DINPUT=${CMAKE_CURRENT_SOURCE_DIR}/sample_${test_name}.txt
        -DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/sample_${test_name}_expected.txt
        -P ${CMAKE_CURRENT_SOURCE_DIR}/check_output.cmake)
endforeach()
