QT += core gui widgets
CONFIG += c++17

SOURCES += \
    main.cpp \
    Model/Attivita.cpp \
    Model/Appuntamento.cpp \
    Model/Compito.cpp \
    Model/Promemoria.cpp \
    Model/Registro.cpp \
    Model/VisitorJson.cpp \
    Model/LettoreJson.cpp \
    Model/VisitorFiltroTipo.cpp \
    View/AbstractEditorAttivita.cpp \
    View/EditorAppuntamento.cpp \
    View/EditorCompito.cpp \
    View/EditorPromemoria.cpp \
    View/VisitorFormEdit.cpp \
    View/MainWindow.cpp

HEADERS += \
    Model/Attivita.h \
    Model/VisitorAttivita.h \
    Model/Appuntamento.h \
    Model/Compito.h \
    Model/Promemoria.h \
    Model/Registro.h \
    Model/VisitorJson.h \
    Model/LettoreJson.h \
    Model/VisitorFiltroTipo.h \
    View/AbstractEditorAttivita.h \
    View/EditorAppuntamento.h \
    View/EditorCompito.h \
    View/EditorPromemoria.h \
    View/VisitorFormEdit.h \
    View/MainWindow.h

TARGET = GestioneAttivita
