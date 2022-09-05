QT += quick quickcontrols2 core

SOURCES += \
        src/main.cpp \
        src/persons_model.cpp

RESOURCES += \
	uRodzinki.qrc

OTHER_FILES = \
	qml/main.qml \
	qml/PersonDelegate.qml \

DISTFILES += \
	android/AndroidManifest.xml \
	android/build.gradle \
	android/gradle.properties \
	android/gradle/wrapper/gradle-wrapper.jar \
	android/gradle/wrapper/gradle-wrapper.properties \
	android/gradlew \
	android/gradlew.bat \
	android/res/values/libs.xml \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:RC_ICONS += res/window_icon.ico

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
	ANDROID_PACKAGE_SOURCE_DIR = \
		$$PWD/android
}

HEADERS += \
	src/persons_model.hpp


