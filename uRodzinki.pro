QT += quick quickcontrols2

SOURCES += \
        src/main.cpp

RESOURCES += \
	uRodzinki.qrc

OTHER_FILES = \
	qml/main.qml \
	qml/DataModel.qml \
	qml/PersonDelegate.qml \
	js/Utils.js

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


