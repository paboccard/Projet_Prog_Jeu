/****************************************************************************
** Meta object code from reading C++ file 'Controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Gauffre/Controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[18];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Controller_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 6),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 9),
QT_MOC_LITERAL(4, 29, 16),
QT_MOC_LITERAL(5, 46, 5),
QT_MOC_LITERAL(6, 52, 1),
QT_MOC_LITERAL(7, 54, 16),
QT_MOC_LITERAL(8, 71, 13),
QT_MOC_LITERAL(9, 85, 10),
QT_MOC_LITERAL(10, 96, 7),
QT_MOC_LITERAL(11, 104, 4),
QT_MOC_LITERAL(12, 109, 4),
QT_MOC_LITERAL(13, 114, 4),
QT_MOC_LITERAL(14, 119, 4),
QT_MOC_LITERAL(15, 124, 12),
QT_MOC_LITERAL(16, 137, 4),
QT_MOC_LITERAL(17, 142, 1)
    },
    "Controller\0iaPlay\0\0configure\0"
    "gaufreHoverEnter\0Point\0p\0gaufreHoverLeave\0"
    "gaufrePressed\0slotConfig\0newGame\0save\0"
    "load\0undo\0redo\0slotLoadGame\0Game\0g\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08,
       3,    0,   75,    2, 0x08,
       4,    1,   76,    2, 0x08,
       7,    1,   79,    2, 0x08,
       8,    1,   82,    2, 0x08,
       9,    0,   85,    2, 0x08,
      10,    0,   86,    2, 0x08,
      11,    0,   87,    2, 0x08,
      12,    0,   88,    2, 0x08,
      13,    0,   89,    2, 0x08,
      14,    0,   90,    2, 0x08,
      15,    1,   91,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        switch (_id) {
        case 0: _t->iaPlay(); break;
        case 1: _t->configure(); break;
        case 2: _t->gaufreHoverEnter((*reinterpret_cast< Point(*)>(_a[1]))); break;
        case 3: _t->gaufreHoverLeave((*reinterpret_cast< Point(*)>(_a[1]))); break;
        case 4: _t->gaufrePressed((*reinterpret_cast< Point(*)>(_a[1]))); break;
        case 5: _t->slotConfig(); break;
        case 6: _t->newGame(); break;
        case 7: _t->save(); break;
        case 8: _t->load(); break;
        case 9: _t->undo(); break;
        case 10: _t->redo(); break;
        case 11: _t->slotLoadGame((*reinterpret_cast< Game(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, 0, 0}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
