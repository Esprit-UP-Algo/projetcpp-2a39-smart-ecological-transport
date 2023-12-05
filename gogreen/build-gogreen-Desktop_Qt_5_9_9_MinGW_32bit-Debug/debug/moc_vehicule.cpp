/****************************************************************************
** Meta object code from reading C++ file 'vehicule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gogreen/vehicule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vehicule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Vehicule_t {
    QByteArrayData data[12];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Vehicule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Vehicule_t qt_meta_stringdata_Vehicule = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Vehicule"
QT_MOC_LITERAL(1, 9, 16), // "on_ajout_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "on_supp_clicked"
QT_MOC_LITERAL(4, 43, 19), // "on_modifier_clicked"
QT_MOC_LITERAL(5, 63, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(6, 85, 4), // "arg1"
QT_MOC_LITERAL(7, 90, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(8, 114, 16), // "on_tab_v_clicked"
QT_MOC_LITERAL(9, 131, 5), // "index"
QT_MOC_LITERAL(10, 137, 17), // "on_ch_textChanged"
QT_MOC_LITERAL(11, 155, 24) // "on_pushButton_19_clicked"

    },
    "Vehicule\0on_ajout_clicked\0\0on_supp_clicked\0"
    "on_modifier_clicked\0on_comboBox_activated\0"
    "arg1\0on_pushButton_3_clicked\0"
    "on_tab_v_clicked\0index\0on_ch_textChanged\0"
    "on_pushButton_19_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vehicule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
      10,    1,   64,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void Vehicule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Vehicule *_t = static_cast<Vehicule *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajout_clicked(); break;
        case 1: _t->on_supp_clicked(); break;
        case 2: _t->on_modifier_clicked(); break;
        case 3: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_tab_v_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_ch_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_19_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Vehicule::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Vehicule.data,
      qt_meta_data_Vehicule,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Vehicule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vehicule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Vehicule.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Vehicule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
