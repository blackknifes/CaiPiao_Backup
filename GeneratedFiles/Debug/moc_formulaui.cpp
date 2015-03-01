/****************************************************************************
** Meta object code from reading C++ file 'formulaui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../formulaui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formulaui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FormulaUI_t {
    QByteArrayData data[9];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormulaUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormulaUI_t qt_meta_stringdata_FormulaUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FormulaUI"
QT_MOC_LITERAL(1, 10, 14), // "FormulaChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "TrueFormula*"
QT_MOC_LITERAL(4, 39, 8), // "initFunc"
QT_MOC_LITERAL(5, 48, 17), // "generateFormulate"
QT_MOC_LITERAL(6, 66, 17), // "predictNextLotter"
QT_MOC_LITERAL(7, 84, 14), // "ChangedFormula"
QT_MOC_LITERAL(8, 99, 12) // "initFuncSlot"

    },
    "FormulaUI\0FormulaChanged\0\0TrueFormula*\0"
    "initFunc\0generateFormulate\0predictNextLotter\0"
    "ChangedFormula\0initFuncSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormulaUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

       0        // eod
};

void FormulaUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormulaUI *_t = static_cast<FormulaUI *>(_o);
        switch (_id) {
        case 0: _t->FormulaChanged((*reinterpret_cast< TrueFormula*(*)>(_a[1]))); break;
        case 1: _t->initFunc(); break;
        case 2: _t->generateFormulate(); break;
        case 3: _t->predictNextLotter(); break;
        case 4: _t->ChangedFormula((*reinterpret_cast< TrueFormula*(*)>(_a[1]))); break;
        case 5: _t->initFuncSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FormulaUI::*_t)(TrueFormula * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FormulaUI::FormulaChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (FormulaUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FormulaUI::initFunc)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FormulaUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FormulaUI.data,
      qt_meta_data_FormulaUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FormulaUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormulaUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FormulaUI.stringdata))
        return static_cast<void*>(const_cast< FormulaUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int FormulaUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FormulaUI::FormulaChanged(TrueFormula * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormulaUI::initFunc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
