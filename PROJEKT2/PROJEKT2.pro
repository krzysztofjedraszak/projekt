TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/Qt/SFML-2.5.1/include"
LIBS += -L"C:/Qt/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    aktualny_wynik.h \
    cukierek.h \
    elementsceny.h \
    najlepszy_wynik.h \
    plansza.h \
    zegar.h \
    znacznik.h

SOURCES += \
    aktualny_wynik.cpp \
    cukierek.cpp \
    elementsceny.cpp \
    main.cpp \
    najlepszy_wynik.cpp \
    plansza.cpp \
    zegar.cpp \
    znacznik.cpp

