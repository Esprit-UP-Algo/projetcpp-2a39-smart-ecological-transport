/****************************************************************************
** Meta object code from reading C++ file 'retours.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gogreen/retours.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'retours.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_retours_t {
    QByteArrayData data[15];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_retours_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_retours_t qt_meta_stringdata_retours = {
    {
QT_MOC_LITERAL(0, 0, 7), // "retours"
QT_MOC_LITERAL(1, 8, 18), // "on_ajouter_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 36), // "on_comboBox_trie_currentIndex..."
QT_MOC_LITERAL(4, 65, 4), // "arg1"
QT_MOC_LITERAL(5, 70, 33), // "on_lineEdit_recherche_textCha..."
QT_MOC_LITERAL(6, 104, 23), // "on_generate_pdf_clicked"
QT_MOC_LITERAL(7, 128, 23), // "on_tab_stations_clicked"
QT_MOC_LITERAL(8, 152, 5), // "index"
QT_MOC_LITERAL(9, 158, 20), // "on_deleteBtn_clicked"
QT_MOC_LITERAL(10, 179, 22), // "on_modifierBtn_clicked"
QT_MOC_LITERAL(11, 202, 15), // "on_send_clicked"
QT_MOC_LITERAL(12, 218, 15), // "on_save_clicked"
QT_MOC_LITERAL(13, 234, 16), // "returnToHomepage"
QT_MOC_LITERAL(14, 251, 4) // "stat"

    },
    "retours\0on_ajouter_clicked\0\0"
    "on_comboBox_trie_currentIndexChanged\0"
    "arg1\0on_lineEdit_recherche_textChanged\0"
    "on_generate_pdf_clicked\0on_tab_stations_clicked\0"
    "index\0on_deleteBtn_clicked\0"
    "on_modifierBtn_clicked\0on_send_clicked\0"
    "on_save_clicked\0returnToHomepage\0stat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_retours[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void retours::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        retours *_t = static_cast<retours *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouter_clicked(); break;
        case 1: _t->on_comboBox_trie_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_recherche_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_generate_pdf_clicked(); break;
        case 4: _t->on_tab_stations_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_deleteBtn_clicked(); break;
        case 6: _t->on_modifierBtn_clicked(); break;
        case 7: _t->on_send_clicked(); break;
        case 8: _t->on_save_clicked(); break;
        case 9: _t->returnToHomepage(); break;
        case 10: _t->stat(); break;
        default: ;
        }
    }
}

const QMetaObject retours::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_retours.data,
      qt_meta_data_retours,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *retours::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *retours::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_retours.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int retours::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
