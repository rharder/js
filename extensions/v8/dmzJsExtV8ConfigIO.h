#ifndef DMZ_JS_EXT_V8_CONFIG_IO_DOT_H
#define DMZ_JS_EXT_V8_CONFIG_IO_DOT_H

#include <dmzJsExtV8.h>
#include <dmzJsV8UtilHelpers.h>
#include <dmzRuntimeConfig.h>
#include <dmzRuntimeLog.h>
#include <dmzRuntimePlugin.h>
#include <dmzTypesStringContainer.h>

namespace dmz {

   class JsModuleV8;
   class JsModuleRuntimeV8;
   class JsModuleTypesV8;

   class JsExtV8ConfigIO :
         public Plugin,
         public JsExtV8 {

      public:
         JsExtV8ConfigIO (const PluginInfo &Info, Config &local);
         ~JsExtV8ConfigIO ();

         // Plugin Interface
         virtual void update_plugin_state (
            const PluginStateEnum State,
            const UInt32 Level);

         virtual void discover_plugin (
            const PluginDiscoverEnum Mode,
            const Plugin *PluginPtr);

         // JsExtV8 Interface
         virtual void update_js_module_v8 (const ModeEnum Mode, JsModuleV8 &module);
         virtual void update_js_context_v8 (v8::Handle<v8::Context> context);
         virtual void update_js_ext_v8_state (const StateEnum State);

         virtual void release_js_instance_v8 (
            const Handle InstanceHandle,
            const String &InstanceName,
            v8::Handle<v8::Object> &instance);

      protected:
         // JsExtV8ConfigIO Interface
         struct ArgStruct {

            String archive;
            StringContainer files;
            Config data;
            UInt32 mode;
            UInt32 type;
            Log *log;

            ArgStruct () : mode (0), type (0), log (0) {;}
         };

         static JsExtV8ConfigIO *_to_self (const v8::Arguments &Args);
         static V8Value _io_read (const v8::Arguments &Args);
         static V8Value _io_write (const v8::Arguments &Args);

         ArgStruct _to_args (V8Value value);
         void _init (Config &local);

         Log _log;

         JsModuleV8 *_core;
         JsModuleRuntimeV8 *_runtime;
         JsModuleTypesV8 *_types;

         V8InterfaceHelper _ioApi;

         v8::Handle<v8::Context> _v8Context;

         V8ValuePersist _self;
         V8StringPersist _fileStr;
         V8StringPersist _fileListStr;
         V8StringPersist _archiveStr;
         V8StringPersist _dataStr;
         V8StringPersist _typeStr;
         V8StringPersist _modeStr;
         V8StringPersist _logStr;

      private:
         JsExtV8ConfigIO ();
         JsExtV8ConfigIO (const JsExtV8ConfigIO &);
         JsExtV8ConfigIO &operator= (const JsExtV8ConfigIO &);
   };
};


inline dmz::JsExtV8ConfigIO *
dmz::JsExtV8ConfigIO::_to_self (const v8::Arguments &Args) {

   return (dmz::JsExtV8ConfigIO *)v8::External::Unwrap (Args.Data ());
}

#endif // DMZ_JS_EXT_V8_CONFIG_IO_DOT_H
