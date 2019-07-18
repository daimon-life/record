
#ifndef SAFE_CLOSE
#define	SAFE_CLOSE(p)		            { if(p != NULL) { fclose(p);     (p)=NULL; } }
#endif

#ifndef SAFE_CLOSESOCK
#define	SAFE_CLOSESOCK(p)		        { if(p != -1) { closesocket(p);     (p)=-1; } }
#endif

#ifndef SAFE_DELETE
#define	SAFE_DELETE(p)       	        { if(p) { delete (p);     (p)=NULL; } }
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)                 { if (p) { (p)->Release(); (p) = NULL; } }
#endif // SAFE_RELEASE

#ifndef SAFE_DELETE_ARRAY
#define	SAFE_DELETE_ARRAY(p)	        { if(p) { delete [] (p);   (p)=NULL; } }
#endif

#ifndef SAFE_FREE
#define SAFE_FREE(p)                    { if (p) { free((p)); (p)= NULL; } }
#endif

// 返回值判断 {{
#ifndef IS_SUCCEED
#define IS_SUCCEED(ret)                 ((ret) == emRC_OK)
#endif

#ifndef IS_FAILED
#define IS_FAILED(ret)                  ((ret) != emRC_OK)
#endif

#ifndef CHECK_BREAK
#define CHECK_BREAK(bIsBreak)           if ((bIsBreak)) { break; }
#endif

#ifndef CHECK_CONTINUE
#define CHECK_CONTINUE(bIsContinue)     if ((bIsContinue)) { continue; }
#endif

#ifndef CHECK_RETURN
#define CHECK_RETURN(bIsReturn)           if ((bIsReturn)) { return; }
#endif

#ifndef CHECK_RETURN_RET
#define CHECK_RETURN_RET(bIsReturn,nRet)	if ((bIsReturn)) { return nRet; }
#endif
