QT += widgets
requires(qtConfig(listview))

SOURCES   = adddialog.cpp \
            addresswidget.cpp \
            contact.cpp \
            finddialog.cpp \
            findtab.cpp \
            main.cpp \
            mainwindow.cpp \
            tablemodel.cpp
HEADERS   = adddialog.h \
            addresswidget.h \
            contact.h \
            finddialog.h \
            findtab.h \
            mainwindow.h \
            tablemodel.h

# install
target.path = .
INSTALLS += target
