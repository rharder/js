#include "dmzJsModuleUiV8QtBasic.h"
#include <dmzJsV8UtilConvert.h>
#include <QtGui/QLineEdit>


dmz::V8Value
dmz::JsModuleUiV8QtBasic::_lineEdit_text (const v8::Arguments &Args) {

   v8::HandleScope scope;
   V8Value result = v8::Undefined ();

   JsModuleUiV8QtBasic *self = _to_self (Args);

   if (self) {

      QWidget *widget = self->_to_qt_widget (Args.This ());

      if (widget) {

         QLineEdit *line = qobject_cast<QLineEdit *>(widget);

         if (line) {

            if (Args.Length ()) {

               line->setText (v8_to_string (Args[0]).get_buffer ());
            }
            else {

               result = v8::String::New (qPrintable(line->text ()));
            }
         }
      }
   }

   return scope.Close (result);
}


dmz::V8Value
dmz::JsModuleUiV8QtBasic::_lineEdit_clear (const v8::Arguments &Args) {

   v8::HandleScope scope;
   V8Value result = v8::Undefined ();

   JsModuleUiV8QtBasic *self = _to_self (Args);

   if (self) {

      QWidget *widget = self->_to_qt_widget (Args.This ());

      if (widget) {

         QLineEdit *line = qobject_cast<QLineEdit *>(widget);

         if (line) {

            line->clear ();
         }
      }
   }

   return scope.Close (result);
}


dmz::V8Value
dmz::JsModuleUiV8QtBasic::_lineEdit_undo (const v8::Arguments &Args) {

   v8::HandleScope scope;
   V8Value result = v8::Undefined ();

   JsModuleUiV8QtBasic *self = _to_self (Args);

   if (self) {

      QWidget *widget = self->_to_qt_widget (Args.This ());

      if (widget) {

         QLineEdit *line = qobject_cast<QLineEdit *>(widget);

         if (line) {

            line->undo ();
         }
      }
   }

   return scope.Close (result);
}


dmz::V8Value
dmz::JsModuleUiV8QtBasic::_lineEdit_redo (const v8::Arguments &Args) {

   v8::HandleScope scope;
   V8Value result = v8::Undefined ();

   JsModuleUiV8QtBasic *self = _to_self (Args);

   if (self) {

      QWidget *widget = self->_to_qt_widget (Args.This ());

      if (widget) {

         QLineEdit *line = qobject_cast<QLineEdit *>(widget);

         if (line) {

            line->redo ();
         }
      }
   }

   return scope.Close (result);
}


void
dmz::JsModuleUiV8QtBasic::_init_lineEdit () {

   v8::HandleScope scope;

   _lineEditTemp = V8FunctionTemplatePersist::New (v8::FunctionTemplate::New ());
   _lineEditTemp->Inherit (_widgetTemp);

   V8ObjectTemplate instance = _lineEditTemp->InstanceTemplate ();
   instance->SetInternalFieldCount (1);

   V8ObjectTemplate proto = _lineEditTemp->PrototypeTemplate ();
   proto->Set ("text", v8::FunctionTemplate::New (_lineEdit_text, _self));
   proto->Set ("clear", v8::FunctionTemplate::New (_lineEdit_clear, _self));
   proto->Set ("undo", v8::FunctionTemplate::New (_lineEdit_undo, _self));
   proto->Set ("redo", v8::FunctionTemplate::New (_lineEdit_redo, _self));
}
