const core = Process.getModuleByName('libQt5Core.so.5');
const qvarLlong = new NativeFunction(core.getExportByName('_ZN8QVariantC1Ex'),'void',['pointer','int64']);
const qvarDtor = new NativeFunction(core.getExportByName('_ZN8QVariantD1Ev'),'void',['pointer']);
const userType = new NativeFunction(core.getExportByName('_ZNK8QVariant8userTypeEv'),'int',['pointer']);
const toLlong = new NativeFunction(core.getExportByName('_ZNK8QVariant10toLongLongEPb'),'long',['pointer','pointer']);
const qstrAssign = new NativeFunction(core.getExportByName('_ZN7QStringaSERKS_'),'pointer',['pointer','pointer']);
const fromUtf8h = new NativeFunction(core.getExportByName('_ZN7QString15fromUtf8_helperEPKci'),'pointer',['pointer','int']);
const opNew = new NativeFunction(Process.getModuleByName('libstdc++.so.6.0.33').getExportByName('_Znwm'),'pointer',['ulong']);
const opCtor = new NativeFunction(ptr('0x00899fba'),'void',['pointer']);
const DISPATCH = ptr('0x00a418c4');
const dispatchFn = new NativeFunction(DISPATCH,'void',['pointer','pointer','uint','pointer','pointer']);
const SCI_CLEARALL=2004, SCI_ADDTEXT=2003, SCI_SETSEL=2160, SCI_GETSELSTART=2143, SCI_GETSELEND=2145, SCI_GETTEXTLENGTH=2006;
let editor=null, armed=null, result=null;
function mkVar(v){const m=Memory.alloc(16);qvarLlong(m,int64(v));return m;}
function mkNull(){const m=Memory.alloc(24);m.writeByteArray(new Array(24).fill(0));return m;}
function rdLong(a,cmd,av){const r=mkNull();dispatchFn(r,a,cmd,mkVar(av),mkNull());const v=toLlong(r,NULL).toString();qvarDtor(r);return v;}
Interceptor.attach(DISPATCH,{onEnter(a){
  if(editor===null && !a[1].isNull()){editor=a[1];send({t:'ed',v:editor.toString()});}
  if(armed!==null&&editor!==null){const r=armed;armed=null;
    try{
      const ed=editor;
      const doc=ed.add(0x1098).readPointer();
      const memo=doc.add(0xe0).readPointer();
      rdLong(ed,SCI_CLEARALL,0);
      if(r.doc && r.doc.length>0){
        const buf=Memory.allocUtf8String(r.doc);
        const ret=mkNull();
        dispatchFn(ret,ed,SCI_ADDTEXT,mkVar(r.doc.length),mkVar(int64(buf.toString().slice(2),16)));
        qvarDtor(ret);
      }
      if(r.selA !== undefined && r.selB !== undefined && r.selB>r.selA){
        const ret=mkNull();
        dispatchFn(ret,ed,SCI_SETSEL,mkVar(r.selA),mkVar(r.selB));
        qvarDtor(ret);
      }
      const op=opNew(0x68);
      send({t:'dbg',v:'op='+op.toString()});
      opCtor(op);
      send({t:'dbg',v:'ctor ok'});
      const findQ=fromUtf8h(Memory.allocUtf8String(r.find), r.find.length);
      const replQ=fromUtf8h(Memory.allocUtf8String(r.repl||''), (r.repl||'').length);
      qstrAssign(memo.add(0x28), findQ);
      qstrAssign(memo.add(0x20), replQ);
      Memory.writeU32(op.add(0x0c), r.flags||0);
      Memory.writeU8(op.add(0x10), r.type||4);
      qstrAssign(op.add(0x18), findQ);
      qstrAssign(op.add(0x20), replQ);
      const ret2=mkNull();
      dispatchFn(ret2,ed,r.cmd,mkVar(int64(op.toString().slice(2),16)),mkNull());
      const out={t:userType(ret2),v:toLlong(ret2,NULL).toString()};
      qvarDtor(ret2);
      out.sel=[rdLong(ed,SCI_GETSELSTART,0),rdLong(ed,SCI_GETSELEND,0)];
      out.docLen=rdLong(ed,SCI_GETTEXTLENGTH,0);
      result=out;
    }catch(e){send({t:'err',v:String(e)+' @'+(e.stack||'').split('\n')[1]});result={err:String(e)};}
  }
}});
rpc.exports.ed = function(){return editor===null?null:editor.toString();};
rpc.exports.arm = function(job){if(armed!==null)return false;armed=job;result=null;return true;};
rpc.exports.poll = function(){return result;};
rpc.exports.pending = function(){return armed!==null;};
rpc.exports.peek = function(){ if(editor===null) return null;
  const doc=editor.add(0x1098).readPointer();
  const memo=doc.add(0xe0).readPointer();
  function hx(p,n){return Array.from(new Uint8Array(p.readByteArray(n))).map(x=>('0'+x.toString(16)).slice(-2)).join('');}
  return {editor:editor.toString(),doc:doc.toString(),memoHex:hx(memo,0x48)};
};
