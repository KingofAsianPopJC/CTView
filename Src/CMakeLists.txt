CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT (CTViewer)

FIND_PACKAGE(VTK REQUIRED)
IF(VTK_FOUND)
    INCLUDE(${VTK_USE_FILE})
ELSE ()
    MASSAGE(FATAL_ERROR "Cannnot build without ITK. Please set VTK_DIR.")
ENDIF()

FIND_PACKAGE(ITK REQUIRED)
IF(ITK_FOUND)
    INCLUDE(${ITK_USE_FILE})
ELSE ()
    MASSAGE(FATAL_ERROR "Cannnot build without ITK. Please set ITK_DIR.")
ENDIF()

IF(ITKVtkGlue_LOADED)
   FIND_PACKAGE(VTK REQUIRED)
   INCLUDE(${VTK_USE_FILE})
ELSE()
   MASSAGE(FATAL_ERROR "You need to select ITKVtkGlue when compile ITK.")
ENDIF()

INCLUDE_DIRECTORIES(ImageIO)
INCLUDE_DIRECTORIES(InterFace)
INCLUDE_DIRECTORIES(ImageDisplay)
INCLUDE_DIRECTORIES(ImageInteractor)

ADD_EXECUTABLE(CTViewer main.cpp)

ADD_SUBDIRECTORY(ImageIO)
ADD_SUBDIRECTORY(InterFace)
ADD_SUBDIRECTORY(ImageDisplay)
ADD_SUBDIRECTORY(ImageInteractor)

TARGET_LINK_LIBRARIES(CTViewer
                      ImageIO 
					  InterFace 
					  ImageDisplay 
                                                                                  ImageInteractor
					  ${VTK_LIBRARIES} 
					  ${ITK_LIBRARIES})