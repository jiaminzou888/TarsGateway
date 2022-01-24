// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 3.0.4.
// **********************************************************************

#ifndef __VERIFY_H_
#define __VERIFY_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"
#include "promise/promise.h"
#include "servant/Application.h"


namespace Base
{
    enum E_VERIFY_CODE
    {
        EVC_TOKEN_EXPIRE = -3,
        EVC_ERR_TOKEN = -2,
        EVC_SYS_ERR = -1,
        EVC_SUCC = 0,
    };
    inline string etos(const E_VERIFY_CODE & e)
    {
        switch(e)
        {
            case EVC_TOKEN_EXPIRE: return "EVC_TOKEN_EXPIRE";
            case EVC_ERR_TOKEN: return "EVC_ERR_TOKEN";
            case EVC_SYS_ERR: return "EVC_SYS_ERR";
            case EVC_SUCC: return "EVC_SUCC";
            default: return "";
        }
    }
    inline int stoe(const string & s, E_VERIFY_CODE & e)
    {
        if(s == "EVC_TOKEN_EXPIRE")  { e=EVC_TOKEN_EXPIRE; return 0;}
        if(s == "EVC_ERR_TOKEN")  { e=EVC_ERR_TOKEN; return 0;}
        if(s == "EVC_SYS_ERR")  { e=EVC_SYS_ERR; return 0;}
        if(s == "EVC_SUCC")  { e=EVC_SUCC; return 0;}

        return -1;
    }

    struct VerifyReq : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "Base.VerifyReq";
        }
        static string MD5()
        {
            return "fa4e636b1a9ceaaacc9ebe2e6dcf4115";
        }
        VerifyReq()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            token = "";
            verifyHeaders.clear();
            body.clear();
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(token, 1);
            if (verifyHeaders.size() > 0)
            {
                _os.write(verifyHeaders, 2);
            }
            if (body.size() > 0)
            {
                _os.write(body, 3);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(token, 1, true);
            _is.read(verifyHeaders, 2, false);
            _is.read(body, 3, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["token"] = tars::JsonOutput::writeJson(token);
            p->value["verifyHeaders"] = tars::JsonOutput::writeJson(verifyHeaders);
            p->value["body"] = tars::JsonOutput::writeJson(body);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(token,pObj->value["token"], true);
            tars::JsonInput::readJson(verifyHeaders,pObj->value["verifyHeaders"], false);
            tars::JsonInput::readJson(body,pObj->value["body"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(token,"token");
            _ds.display(verifyHeaders,"verifyHeaders");
            _ds.display(body,"body");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(token, true);
            _ds.displaySimple(verifyHeaders, true);
            _ds.displaySimple(body, false);
            return _os;
        }
    public:
        std::string token;
        map<std::string, std::string> verifyHeaders;
        vector<tars::Char> body;
    };
    inline bool operator==(const VerifyReq&l, const VerifyReq&r)
    {
        return l.token == r.token && l.verifyHeaders == r.verifyHeaders && l.body == r.body;
    }
    inline bool operator!=(const VerifyReq&l, const VerifyReq&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const VerifyReq&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,VerifyReq&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct VerifyRsp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "Base.VerifyRsp";
        }
        static string MD5()
        {
            return "d42e5716eca49c942897abfb5af8d00f";
        }
        VerifyRsp()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            ret = 0;
            uid = "";
            context = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(ret, 1);
            if (uid != "")
            {
                _os.write(uid, 2);
            }
            if (context != "")
            {
                _os.write(context, 3);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(ret, 1, true);
            _is.read(uid, 2, false);
            _is.read(context, 3, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["ret"] = tars::JsonOutput::writeJson(ret);
            p->value["uid"] = tars::JsonOutput::writeJson(uid);
            p->value["context"] = tars::JsonOutput::writeJson(context);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(ret,pObj->value["ret"], true);
            tars::JsonInput::readJson(uid,pObj->value["uid"], false);
            tars::JsonInput::readJson(context,pObj->value["context"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(ret,"ret");
            _ds.display(uid,"uid");
            _ds.display(context,"context");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(ret, true);
            _ds.displaySimple(uid, true);
            _ds.displaySimple(context, false);
            return _os;
        }
    public:
        tars::Int32 ret;
        std::string uid;
        std::string context;
    };
    inline bool operator==(const VerifyRsp&l, const VerifyRsp&r)
    {
        return l.ret == r.ret && l.uid == r.uid && l.context == r.context;
    }
    inline bool operator!=(const VerifyRsp&l, const VerifyRsp&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const VerifyRsp&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,VerifyRsp&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }


    /* callback of async proxy for client */
    class VerifyPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~VerifyPrxCallback(){}
        virtual void callback_verify(tars::Int32 ret,  const Base::VerifyRsp& rsp)
        { throw std::runtime_error("callback_verify() override incorrect."); }
        virtual void callback_verify_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_verify_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __Verify_all[]=
            {
                "verify"
            };
            pair<string*, string*> r = equal_range(__Verify_all, __Verify_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Verify_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_verify_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    Base::VerifyRsp rsp;
                    _is.read(rsp, 2, true);
                    ServantProxyThreadData *pSptd = ServantProxyThreadData::getData();
                    if (pSptd && pSptd->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = pSptd->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                            _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(pSptd->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "verify", 0, _trace_param_, "");
                    }

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response->context);

                    callback_verify(_ret, rsp);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<VerifyPrxCallback> VerifyPrxCallbackPtr;

    //callback of promise async proxy for client
    class VerifyPrxCallbackPromise: public tars::ServantProxyCallback
    {
    public:
        virtual ~VerifyPrxCallbackPromise(){}
    public:
        struct Promiseverify: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            Base::VerifyRsp rsp;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< VerifyPrxCallbackPromise::Promiseverify > PromiseverifyPtr;

        VerifyPrxCallbackPromise(const tars::Promise< VerifyPrxCallbackPromise::PromiseverifyPtr > &promise)
        : _promise_verify(promise)
        {}
        
        virtual void callback_verify(const VerifyPrxCallbackPromise::PromiseverifyPtr &ptr)
        {
            _promise_verify.setValue(ptr);
        }
        virtual void callback_verify_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:verify_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_verify.setException(tars::copyException(str, ret));
        }

    protected:
        tars::Promise< VerifyPrxCallbackPromise::PromiseverifyPtr > _promise_verify;

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __Verify_all[]=
            {
                "verify"
            };

            pair<string*, string*> r = equal_range(__Verify_all, __Verify_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Verify_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_verify_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);

                    VerifyPrxCallbackPromise::PromiseverifyPtr ptr = new VerifyPrxCallbackPromise::Promiseverify();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                        _is.read(ptr->rsp, 2, true);
                    }
                    catch(std::exception &ex)
                    {
                        callback_verify_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_verify_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = msg->response->context;

                    callback_verify(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<VerifyPrxCallbackPromise> VerifyPrxCallbackPromisePtr;

    /* callback of coroutine async proxy for client */
    class VerifyCoroPrxCallback: public VerifyPrxCallback
    {
    public:
        virtual ~VerifyCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __Verify_all[]=
            {
                "verify"
            };

            pair<string*, string*> r = equal_range(__Verify_all, __Verify_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Verify_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_verify_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        Base::VerifyRsp rsp;
                        _is.read(rsp, 2, true);
                        setResponseContext(msg->response->context);

                        callback_verify(_ret, rsp);

                    }
                    catch(std::exception &ex)
                    {
                        callback_verify_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_verify_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<VerifyCoroPrxCallback> VerifyCoroPrxCallbackPtr;

    /* proxy for client */
    class VerifyProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 verify(const Base::VerifyReq & req,Base::VerifyRsp &rsp,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            _os.write(rsp, 2);
            ServantProxyThreadData *pSptd = ServantProxyThreadData::getData();
            if (pSptd && pSptd->_traceCall)
            {
                pSptd->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = pSptd->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value["req"] = tars::JsonOutput::writeJson(req);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(pSptd->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "verify", 0, _trace_param_, "");
            }

            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"verify", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(rsp, 2, true);
            if (pSptd && pSptd->_traceCall)
            {
                string _trace_param_;
                int _trace_param_flag_ = pSptd->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(pSptd->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "verify", 0, _trace_param_, "");
            }

            return _ret;
        }

        void async_verify(VerifyPrxCallbackPtr callback,const Base::VerifyReq &req,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            ServantProxyThreadData *pSptd = ServantProxyThreadData::getData();
            if (pSptd && pSptd->_traceCall)
            {
                pSptd->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = pSptd->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value["req"] = tars::JsonOutput::writeJson(req);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(pSptd->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "verify", 0, _trace_param_, "");
            }
            tars_invoke_async(tars::TARSNORMAL,"verify", _os, context, _mStatus, callback);
        }
        
        tars::Future< VerifyPrxCallbackPromise::PromiseverifyPtr > promise_async_verify(const Base::VerifyReq &req,const map<string, string>& context)
        {
            tars::Promise< VerifyPrxCallbackPromise::PromiseverifyPtr > promise;
            VerifyPrxCallbackPromisePtr callback = new VerifyPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"verify", _os, context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_verify(VerifyCoroPrxCallbackPtr callback,const Base::VerifyReq &req,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"verify", _os, context, _mStatus, callback, true);
        }

        VerifyProxy* tars_hash(int64_t key)
        {
            return (VerifyProxy*)ServantProxy::tars_hash(key);
        }

        VerifyProxy* tars_consistent_hash(int64_t key)
        {
            return (VerifyProxy*)ServantProxy::tars_consistent_hash(key);
        }

        VerifyProxy* tars_open_trace(bool traceParam = false)
        {
            return (VerifyProxy*)ServantProxy::tars_open_trace(traceParam);
        }

        VerifyProxy* tars_set_timeout(int msecond)
        {
            return (VerifyProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "VerifyProxy"; }
    };
    typedef tars::TC_AutoPtr<VerifyProxy> VerifyPrx;

    /* servant for server */
    class Verify : public tars::Servant
    {
    public:
        virtual ~Verify(){}
        virtual tars::Int32 verify(const Base::VerifyReq & req,Base::VerifyRsp &rsp,tars::TarsCurrentPtr current) = 0;
        static void async_response_verify(tars::TarsCurrentPtr current, tars::Int32 _ret, const Base::VerifyRsp &rsp)
        {
            size_t _rsp_len_ = 0;
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("tars_ret", _ret);
                tarsAttr.put("rsp", rsp);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
                _rsp_len_ = sTupResponseBuffer.size();
            }
            else if (current->getRequestVersion() == JSONVERSION)
            {
                tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                _p->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                vector<char> sJsonResponseBuffer;
                tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
                _rsp_len_ = sJsonResponseBuffer.size();
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(rsp, 2);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
                _rsp_len_ = _os.getLength();
            }
            if (current->isTraced())
            {
                string _trace_param_;
                int _trace_param_flag_ = ServantProxyThreadData::needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, current->getTraceKey(), _rsp_len_);
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(current->getTraceKey(), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "verify", 0, _trace_param_, "");
            }

        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __Base__Verify_all[]=
            {
                "verify"
            };

            pair<string*, string*> r = equal_range(__Base__Verify_all, __Base__Verify_all+1, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Base__Verify_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    Base::VerifyReq req;
                    Base::VerifyRsp rsp;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("req", req);
                        tarsAttr.getByDefault("rsp", rsp, rsp);
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                        tars::JsonInput::readJson(req, _jsonPtr->value["req"], true);
                        tars::JsonInput::readJson(rsp, _jsonPtr->value["rsp"], false);
                    }
                    else
                    {
                        _is.read(req, 1, true);
                        _is.read(rsp, 2, false);
                    }
                    ServantProxyThreadData *pSptd = ServantProxyThreadData::getData();
                    if (pSptd && pSptd->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = pSptd->needTraceParam(ServantProxyThreadData::TraceContext::EST_SR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _p_->value["req"] = tars::JsonOutput::writeJson(req);
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(pSptd->getTraceKey(ServantProxyThreadData::TraceContext::EST_SR), TRACE_ANNOTATION_SR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "verify", 0, _trace_param_, "");
                    }

                    tars::Int32 _ret = verify(req,rsp, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION)
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("tars_ret", _ret);
                            tarsAttr.put("rsp", rsp);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else if (_current->getRequestVersion() == JSONVERSION)
                        {
                            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                            _p->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                            tars::TC_Json::writeValue(_p, _sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.write(rsp, 2);
                            _os.swap(_sResponseBuffer);
                        }
                        if (pSptd && pSptd->_traceCall)
                        {
                            string _trace_param_;
                            int _trace_param_flag_ = pSptd->needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, _sResponseBuffer.size());
                            if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                            {
                                tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                                _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                                _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                                _trace_param_ = tars::TC_Json::writeValue(_p_);
                            }
                            else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                            {
                                _trace_param_ = "{\"trace_param_over_max_len\":true}";
                            }
                            TARS_TRACE(pSptd->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "verify", 0, _trace_param_, "");
                        }

                    }
                    else if(pSptd && pSptd->_traceCall)
                    {
                        _current->setTrace(pSptd->_traceCall, pSptd->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS));
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
