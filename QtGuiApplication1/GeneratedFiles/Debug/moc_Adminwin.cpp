/****************************************************************************
** Meta object code from reading C++ file 'Adminwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Adminwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Adminwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Adminwin_t {
    QByteArrayData data[10];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Adminwin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Adminwin_t qt_meta_stringdata_Adminwin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Adminwin"
QT_MOC_LITERAL(1, 9, 26), // "on_pushButton_find_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(4, 63, 28), // "on_pushButton_delete_clicked"
QT_MOC_LITERAL(5, 92, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 114, 9), // "connected"
QT_MOC_LITERAL(7, 124, 10), // "ready_read"
QT_MOC_LITERAL(8, 135, 11), // "send_server"
QT_MOC_LITERAL(9, 147, 7) // "message"

    },
    "Adminwin\0on_pushButton_find_clicked\0"
    "\0on_pushButton_add_clicked\0"
    "on_pushButton_delete_clicked\0"
    "on_pushButton_clicked\0connected\0"
    "ready_read\0send_server\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Adminwin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void Adminwin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Adminwin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_find_clicked(); break;
        case 1: _t->on_pushButton_add_clicked(); break;
        case 2: _t->on_pushButton_delete_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->connected(); break;
        case 5: _t->ready_read(); break;
        case 6: _t->send_server((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Adminwin::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Adminwin.data,
    qt_meta_data_Adminwin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Adminwin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Adminwin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Adminwin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Adminwin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
