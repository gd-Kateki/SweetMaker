#include "pch-cpp.hpp"





template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*,T1,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*,T1,T2,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker;
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1* p1, T2* p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		R ret;
		void* params[2] = { p1, p2 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, &ret);
		return ret;
	}
};
template <typename T1, typename T2>
struct InterfaceActionInvoker2
{
	typedef void (*Action)(void*,T1,T2,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*,T1,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4;
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4<R, T1*, T2*, T3, T4>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3 p3, T4 p4)
	{
		R ret;
		void* params[4] = { p1, p2, &p3, &p4 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E;
struct Enumerator_tC1F0E9CA9DC16B5DAF7219CEFDC81D297D74BB4D;
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081;
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC;
struct IEnumerator_1_t41A31EBCC681A6EEBAF4ADF87E8BFA44F565113F;
struct IEnumerator_1_t63A7D8D61E466681FD5C14A1D1BCC426980B452A;
struct IEnumerator_1_tDD2627FCFC71A4FFD903B4AEF273FF46FFBDFF80;
struct IEnumerator_1_tA7A4B24874B32CD986FBECFEC3CFC24A296E89EF;
struct IEnumerator_1_t1DE90964025F3E49484DDA43335AF57CECEAFBFF;
struct IEnumerator_1_t97F735EEDAEF171C04912900C50BD67549E7C34C;
struct IEnumerator_1_tDFDA733A40523681099DF822E97AA4397205F8E5;
struct IEnumerator_1_tC027B9C75091151E01521B33507D9483DDF76923;
struct IEnumerator_1_t2F3426234216B43F059E29CBD94B030FE9450DF5;
struct IEnumerator_1_t9E3E38E99D632155CF320317E81CD3B58180AACB;
struct IEnumerator_1_tCAF0556CFF26D996657B0C5552E18C822AFC05F7;
struct IEnumerator_1_t695C7AC3690631EAEA8C52BD4B17D470FADBEBBA;
struct IEnumerator_1_t05A7E2833DD4038C49FF40712F1051225E9705BA;
struct IEnumerator_1_t664B99C800E4590E71725CFAB0C2B3FBCB419C9E;
struct IEnumerator_1_t6A805AFB7C443AA0883CD0050C54894D87931011;
struct IEnumerator_1_t93968BD445EE7F0C80FAF8340134732F5881D878;
struct IEnumerator_1_t395C5CF5FCF2B997FAC0955A183CF5FA39C933BE;
struct IEnumerator_1_t1514FD9C50C06BDCD5DA7C55B55DE17C7FDE0503;
struct IEnumerator_1_tC30F33471F90268743D1B5BFF5DEB85251DAA71F;
struct IEnumerator_1_tD73EA1F1978A7CA85C06B27D02A5A05B23119451;
struct IEnumerator_1_t36008B50B666F186D530018949C3F8A3339A2539;
struct IEnumerator_1_tECA846C09C760C99B5624DB8C103636A4397ECF0;
struct IEnumerator_1_t06C61C9C5EDD1EFFA8CE8635457E6498926CEED9;
struct IEnumerator_1_tB446602003D78E4BD60A174A51A08312D4746354;
struct IEnumerator_1_t402833552EE251A8377359B2B083EB70C4FF7A48;
struct IEnumerator_1_t200423412A1CD57E0138FA44A44DA490630991C1;
struct IEnumerator_1_t667F7992B8BEB12827F403D7F8F4BCC277699E3A;
struct IEnumerator_1_t3B4CEFC3DC07E2B7EDFBC4F488E49B7DBE0633F8;
struct IEnumerator_1_tA68BEC0BC67553AAC01F11F393567975FE28365E;
struct IEnumerator_1_t80CC1A3ACCFB2E5D70761311ABF7A236C06FF27F;
struct IEnumerator_1_t051A74A73D8BE323DF998BE5A584C2E99109BC68;
struct IEnumerator_1_tCA35A58C5D88A50EF51925435FAF1C0C9E33C220;
struct IEnumerator_1_tD63B5AA3CD1F742143F212308AA086D055EE73BF;
struct IEnumerator_1_tB41B292FAFD525FC5C54D7E469F0BA1A193CA8B1;
struct IEnumerator_1_t75CB2681E18F7F2791528FA2CA60361FDB5DA08D;
struct IList_1_t220F757C91A42A0840E5D43DD2ED9096538684B6;
struct IList_1_t499E984C486A3745CB8E5A0573E515E8FA31C8BD;
struct IList_1_t6FBDBA046A8046DF805DDD78676E382C5175BCA8;
struct IList_1_tDCD0A5542134A8A01C50F0162F2B0A7DBFA289F2;
struct IList_1_tF228F8B23FEE2408C543C11E93C047A95B77F18C;
struct IList_1_t679CD13112B47A9ADFFCF97AB99AE17744DEEC39;
struct IList_1_tC0D84E53E2BA19E57062F4B5A0CCBD0AC0F555A6;
struct IList_1_t18AE8B6F25252935E7ADCDF4D60B65EF893E9C14;
struct IList_1_t54E80E2B0C58F936DFF71D278F42F1C3A882A608;
struct IList_1_tB2C767A1BD619B9C475FAE6702609A7CFCE68BA4;
struct IList_1_t158D47E17E57E686EEFE175B5606062B9FD20399;
struct IList_1_t15C490787A3CCC830BAC7CEEC3A06D3AA61B76AE;
struct IList_1_t6807CE7C4C885B824D8D56FA229CBB5B59642F1D;
struct IList_1_t5D3CA1FE42E42AF74C9F884ED5A562CCF309F70F;
struct IList_1_t6440CF01C77A2C7322B08F1C640B0BD1278F8FBD;
struct IList_1_t54B68D844A2A3029DA0F33A4BFD70431FE34156D;
struct IList_1_t893EDAEF107BB18A047B48A59CB64A51F2C30B51;
struct IList_1_t30A49CDF39E9753B83C1DAB58C23130A2B81475F;
struct IList_1_t946944518D652A2AB2BCAC5D9722D57B5D595AB7;
struct IList_1_tA8BD4291FBB3B3A63533756F82C29D3466BCC3DD;
struct IList_1_tDA58822CBCC8167FBBFC46E76E57A1A77FE717A9;
struct IList_1_t696ACB5313078AD7CC30C81B980F1484EB273DC3;
struct IList_1_t1D12D38B77F7866B04F1000ECA2A4BF2C947CA30;
struct IList_1_tE8673857917D81F98A9AAC97E868062F9BA0D6A7;
struct IList_1_t884EE2EF81C6F986C4DE6CAAE33365464DA763CD;
struct IList_1_tDA4887D2A023EA214C7D142C6839579227C6BEEB;
struct IList_1_t7C17CC33E66DD6DEA3C3F9CA222F7513ADDDD203;
struct IList_1_t3F4B2BE32FA06C7471D430706D261903EB4839AB;
struct IList_1_t9B1C9DEA3CE0BCF2B401AC28B2FD16B66987E70B;
struct IList_1_tE6D72BD6F36F1D58EBA6E877E58D1B72D04B618E;
struct IList_1_tCE74E2521AF1ACBB17BB681EC29F50B3D7980DD5;
struct IList_1_tE4CEE46FEC77EA9531D86BA6143B88BD552C924B;
struct IList_1_tD94B850C56F352B7B71F0830644D6E5EA673F7E1;
struct IList_1_t41FA9096CA232ED8994E946EAB2D217879BB6A2D;
struct IList_1_t9B0304D21093B2CA79004E2B83505377CA032ABA;
struct IList_1_t13B380CBDCD18242A588CE4E55C47DC977C90296;
struct IList_1_tF858DF66E565F8D4335E4B5E75948F82A7B5D682;
struct IList_1_t680CC6FF5DD6F91CF06EFC06CB80CE072FC9176C;
struct IList_1_t7DC7A22F42EEFA1E8D796516A9F22282DF4EB5FA;
struct IList_1_t8AC59FFD0F90EC2DAD4C3FA39B2A5851F9D2987A;
struct List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A;
struct ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068;
struct ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470;
struct ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C;
struct ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39;
struct ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC;
struct ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF;
struct ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A;
struct ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E;
struct ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5;
struct ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4;
struct ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F;
struct ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878;
struct ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F;
struct ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE;
struct ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7;
struct ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3;
struct ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178;
struct ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794;
struct ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261;
struct ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D;
struct ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE;
struct ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB;
struct ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9;
struct ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17;
struct ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7;
struct ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7;
struct ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F;
struct ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D;
struct ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8;
struct ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239;
struct ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3;
struct ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F;
struct ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8;
struct ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA;
struct ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C;
struct ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263;
struct ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8;
struct TrueReadOnlyCollection_1_tB5F9BFA643D0B6B89EEC3ED99B9ADB907576B273;
struct DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC;
struct DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23;
struct DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1;
struct DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74;
struct KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93;
struct KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE;
struct KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA;
struct KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61;
struct NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522;
struct NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3;
struct NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D;
struct NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61;
struct NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA;
struct NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD;
struct NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376;
struct NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320;
struct NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1;
struct NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623;
struct StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164;
struct ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB;
struct ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700;
struct ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E;
struct ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C;
struct ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB;
struct ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30;
struct ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19;
struct ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E;
struct ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D;
struct ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695;
struct ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3;
struct AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8;
struct AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268;
struct AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct Exception_t;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1;
IL2CPP_EXTERN_C String_t* _stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8;
IL2CPP_EXTERN_C String_t* _stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED;
IL2CPP_EXTERN_C String_t* _stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC;
struct DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23;
struct DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1;
struct DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74;
struct KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93;
struct KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE;
struct KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA;
struct KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61;
struct NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522;
struct NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3;
struct NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D;
struct NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61;
struct NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA;
struct NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD;
struct NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376;
struct NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320;
struct NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1;
struct NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623;
struct StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164;
struct ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB;
struct ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700;
struct ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E;
struct ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C;
struct ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB;
struct ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30;
struct ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19;
struct ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E;
struct ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D;
struct ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695;
struct ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3;
struct AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8;
struct AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268;
struct AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5  : public RuntimeObject
{
};
struct Enumerator_tC1F0E9CA9DC16B5DAF7219CEFDC81D297D74BB4D  : public RuntimeObject
{
	ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* ____builder;
	int32_t ____version;
	int32_t ____index;
	Il2CppSharedGenericObject* ____current;
};
struct Enumerator_t80FD5046ECCBFF50D4CD855B7B13C05C89E66E69 : public RuntimeObject {};
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081  : public RuntimeObject
{
};
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC  : public RuntimeObject
{
};
struct ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068  : public RuntimeObject
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ____items;
	int32_t ____size;
	int32_t ____version;
};
struct ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470  : public RuntimeObject
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ____items;
	int32_t ____size;
	int32_t ____version;
};
struct ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t7EE457D5FC476D90C1B3A215E29A968D7A401470  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t7BDC9C0713EF7C1FF600E0BD08F21F5319CE41B5  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t712BA93C06093A15EEFB5B0714B10451CCD81DCD  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t2EB12A3377F8ABB4A3C862EA9BC4CA105699506F  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t282EE6B1F3F0D8DC7FAD25D1C2D5A240E0FF0A7C  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 
{
	int32_t ___key;
	Il2CppSharedGenericObject* ___value;
};
struct KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 
{
	Il2CppSharedGenericObject* ___key;
	bool ___value;
};
struct KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 
{
	Il2CppSharedGenericObject* ___key;
	Il2CppSharedGenericObject* ___value;
};
struct NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct Nullable_1_t365991B3904FDA7642A788423B28692FDC7CDB17 
{
	bool ___hasValue;
	int64_t ___value;
};
struct StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 
{
	Il2CppSharedGenericObject* ___Value1;
	Il2CppSharedGenericObject* ___Value2;
};
struct TrueReadOnlyCollection_1_tB5F9BFA643D0B6B89EEC3ED99B9ADB907576B273  : public ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263
{
};
struct TrueReadOnlyCollection_1_t75B148B212697F1795828F9E34F7984842ADFC03  : public ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8
{
};
struct ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD 
{
	int32_t ___Item1;
	Il2CppSharedGenericObject* ___Item2;
};
struct ValueTuple_2_tFEE748B3D02F0FB25BD73A22DD90DF98F3894254 
{
	Il2CppSharedGenericObject* ___Item1;
	int32_t ___Item2;
};
struct ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 
{
	Il2CppSharedGenericObject* ___Item1;
	float ___Item2;
};
struct ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A 
{
	Il2CppSharedGenericObject* ___Item1;
	Il2CppSharedGenericObject* ___Item2;
};
struct ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A 
{
	Il2CppSharedGenericObject* ___Item1;
	int32_t ___Item2;
};
struct AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB 
{
	float ___start;
	float ___end;
	uint32_t ___order;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___sprites;
};
struct AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB_marshaled_pinvoke
{
	float ___start;
	float ___end;
	uint32_t ___order;
	Il2CppSafeArray* ___sprites;
};
struct AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB_marshaled_com
{
	float ___start;
	float ___end;
	uint32_t ___order;
	Il2CppSafeArray* ___sprites;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___flags;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___flags_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___hi_OffsetPadding[4];
			int32_t ___hi;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___hi_OffsetPadding_forAlignmentOnly[4];
			int32_t ___hi_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___lo_OffsetPadding[8];
			int32_t ___lo;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___lo_OffsetPadding_forAlignmentOnly[8];
			int32_t ___lo_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___mid_OffsetPadding[12];
			int32_t ___mid;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___mid_OffsetPadding_forAlignmentOnly[12];
			int32_t ___mid_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___ulomidLE_OffsetPadding[8];
			uint64_t ___ulomidLE;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___ulomidLE_OffsetPadding_forAlignmentOnly[8];
			uint64_t ___ulomidLE_forAlignmentOnly;
		};
	};
};
struct EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 
{
	union
	{
		struct
		{
			uint64_t ___m_rawData;
		};
		uint8_t EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8__padding[8];
	};
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D 
{
	float ___m_XMin;
	float ___m_YMin;
	float ___m_Width;
	float ___m_Height;
};
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849 
{
	String_t* ___m_String;
	int32_t ___m_Index;
	int32_t ___m_Length;
};
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke
{
	char* ___m_String;
	int32_t ___m_Index;
	int32_t ___m_Length;
};
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com
{
	Il2CppChar* ___m_String;
	int32_t ___m_Index;
	int32_t ___m_Length;
};
struct Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A 
{
	int32_t ___m_X;
	int32_t ___m_Y;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct TextureIdentifier_tA1CDC255400F534A6496877CC86C07B80C45A199 
{
	uint64_t ___value;
};
struct Nullable_1_t072551AA1AA8366A46F232F8180C34AA0CFFACBB 
{
	bool ___hasValue;
	Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F ___value;
};
struct ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___Item1;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___Item2;
};
struct ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 
{
	Il2CppSharedGenericObject* ___Item1;
	ValueTuple_2_tFEE748B3D02F0FB25BD73A22DD90DF98F3894254 ___Item2;
};
struct ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A 
{
	TextureIdentifier_tA1CDC255400F534A6496877CC86C07B80C45A199 ___Item1;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___Item2;
};
struct ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 
{
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___Item1;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___Item2;
	Il2CppSharedGenericObject* ___Item3;
};
struct ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD 
{
	Il2CppSharedGenericObject* ___Item1;
	Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F ___Item2;
	Il2CppSharedGenericObject* ___Item3;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 
{
	intptr_t ___m_Ptr;
	int32_t ___m_Version;
};
struct EventModifiers_tB9DEEF73F8FC4C312B8E0C34336C7D9C3023B270 
{
	int32_t ___value__;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct ExceptionArgument_t60E7F8D9DE5362CBE9365893983C30302D83B778 
{
	int32_t ___value__;
};
struct ExceptionResource_t609A85E253A4E615583553D91D839E2E79FDFBD9 
{
	int32_t ___value__;
};
struct KeyCode_t75B9ECCC26D858F55040DDFF9523681E996D17E9 
{
	int32_t ___value__;
};
struct RenderGraphResourceType_t5F552AF06E38DEC5775B77F13C8783A895FCD086 
{
	int32_t ___value__;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB 
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___text;
	bool ___hasEscapes;
};
struct JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_pinvoke
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke ___text;
	int32_t ___hasEscapes;
};
struct JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_com
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com ___text;
	int32_t ___hasEscapes;
};
struct JsonValueType_t36BA339F107E5E9C0966C45F896E27F3BCC5A2AB 
{
	int32_t ___value__;
};
struct NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t76F16C71E23AB5F30821F9564775BA0C510012AA 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tB946AB7C39022A3069BADCA1BFB2EB857A84AAD9 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tD3E166440DED38454F2B25BF9A375A5EBF8C47AB 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 
{
	String_t* ___paymentMode;
	Nullable_1_t072551AA1AA8366A46F232F8180C34AA0CFFACBB ___price;
	String_t* ___displayPrice;
	String_t* ___periodUnit;
	Nullable_1_t365991B3904FDA7642A788423B28692FDC7CDB17 ___periodValue;
	Nullable_1_t365991B3904FDA7642A788423B28692FDC7CDB17 ___periodCount;
	String_t* ___type;
	String_t* ___id;
};
struct AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3_marshaled_pinvoke
{
	char* ___paymentMode;
	Nullable_1_t072551AA1AA8366A46F232F8180C34AA0CFFACBB ___price;
	char* ___displayPrice;
	char* ___periodUnit;
	Nullable_1_t365991B3904FDA7642A788423B28692FDC7CDB17 ___periodValue;
	Nullable_1_t365991B3904FDA7642A788423B28692FDC7CDB17 ___periodCount;
	char* ___type;
	char* ___id;
};
struct AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3_marshaled_com
{
	Il2CppChar* ___paymentMode;
	Nullable_1_t072551AA1AA8366A46F232F8180C34AA0CFFACBB ___price;
	Il2CppChar* ___displayPrice;
	Il2CppChar* ___periodUnit;
	Nullable_1_t365991B3904FDA7642A788423B28692FDC7CDB17 ___periodValue;
	Nullable_1_t365991B3904FDA7642A788423B28692FDC7CDB17 ___periodCount;
	Il2CppChar* ___type;
	Il2CppChar* ___id;
};
struct ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C 
{
	uint32_t ___m_VersionIndex;
	uint32_t ___m_Validity;
	int32_t ___m_Type;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct JsonValue_t01DB320267C848E729A400EF2345979978F851D2 
{
	int32_t ___type;
	bool ___boolValue;
	double ___realValue;
	int64_t ___integerValue;
	JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB ___stringValue;
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___arrayValue;
	Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E* ___objectValue;
	RuntimeObject* ___anyValue;
};
struct JsonValue_t01DB320267C848E729A400EF2345979978F851D2_marshaled_pinvoke
{
	int32_t ___type;
	int32_t ___boolValue;
	double ___realValue;
	int64_t ___integerValue;
	JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_pinvoke ___stringValue;
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___arrayValue;
	Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E* ___objectValue;
	Il2CppIUnknown* ___anyValue;
};
struct JsonValue_t01DB320267C848E729A400EF2345979978F851D2_marshaled_com
{
	int32_t ___type;
	int32_t ___boolValue;
	double ___realValue;
	int64_t ___integerValue;
	JsonString_tE22CDDA995FEFF514F3F334C93B6AB31B49773CB_marshaled_com ___stringValue;
	List_1_t4A80BCCFB0BC8742C8BB601365DB07226750573A* ___arrayValue;
	Dictionary_2_t6682243BDABA638FCBE4F1D9875B5B1455A7686E* ___objectValue;
	Il2CppIUnknown* ___anyValue;
};
struct KeyEvent_tCBB9830C9FA6B909A5A6BD122FF4B532126E7674 
{
	int32_t ___U3CkeyU3Ek__BackingField;
	int32_t ___U3CmodifiersU3Ek__BackingField;
};
struct DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 
{
	NativeArray_1_t76F16C71E23AB5F30821F9564775BA0C510012AA ___array;
	int32_t ___framesRemaining;
};
struct DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___array;
	int32_t ___framesRemaining;
};
struct DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 
{
	NativeArray_1_tB946AB7C39022A3069BADCA1BFB2EB857A84AAD9 ___array;
	int32_t ___framesRemaining;
};
struct DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F 
{
	NativeArray_1_tD3E166440DED38454F2B25BF9A375A5EBF8C47AB ___array;
	int32_t ___framesRemaining;
};
struct KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 
{
	Il2CppSharedGenericObject* ___key;
	JsonValue_t01DB320267C848E729A400EF2345979978F851D2 ___value;
};
struct ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE 
{
	KeyEvent_tCBB9830C9FA6B909A5A6BD122FF4B532126E7674 ___Item1;
	int32_t ___Item2;
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388 
{
	ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C ___handle;
	bool ___builtin;
};
struct TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388_marshaled_pinvoke
{
	ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C ___handle;
	int32_t ___builtin;
};
struct TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388_marshaled_com
{
	ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C ___handle;
	int32_t ___builtin;
};
struct ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 
{
	TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388 ___Item1;
	int32_t ___Item2;
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
	RuntimeObject* ____actualValue;
};
struct EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___Value;
};
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields
{
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* ___defaultComparer;
};
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC_StaticFields
{
	EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* ___defaultComparer;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppSharedGenericObject* m_Items[1];

	inline Il2CppSharedGenericObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Il2CppSharedGenericObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC  : public RuntimeArray
{
	ALIGN_FIELD (8) DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 m_Items[1];

	inline DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 value)
	{
		m_Items[index] = value;
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23  : public RuntimeArray
{
	ALIGN_FIELD (8) DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F m_Items[1];

	inline DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F value)
	{
		m_Items[index] = value;
	}
};
struct DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1  : public RuntimeArray
{
	ALIGN_FIELD (8) DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 m_Items[1];

	inline DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 value)
	{
		m_Items[index] = value;
	}
};
struct DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74  : public RuntimeArray
{
	ALIGN_FIELD (8) DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F m_Items[1];

	inline DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F value)
	{
		m_Items[index] = value;
	}
};
struct KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 m_Items[1];

	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
};
struct KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 m_Items[1];

	inline KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
	}
	inline KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
	}
};
struct KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 m_Items[1];

	inline KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 m_Items[1];

	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&((m_Items + index)->___value))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___anyValue), (void*)NULL);
		#endif
	}
	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((&((m_Items + index)->___value))->___stringValue))->___text))->___m_String), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___arrayValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___objectValue), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___anyValue), (void*)NULL);
		#endif
	}
};
struct NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C m_Items[1];

	inline NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C value)
	{
		m_Items[index] = value;
	}
};
struct NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 m_Items[1];

	inline NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 value)
	{
		m_Items[index] = value;
	}
};
struct NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD m_Items[1];

	inline NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD value)
	{
		m_Items[index] = value;
	}
};
struct NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 m_Items[1];

	inline NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 value)
	{
		m_Items[index] = value;
	}
};
struct NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C m_Items[1];

	inline NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C value)
	{
		m_Items[index] = value;
	}
};
struct NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B m_Items[1];

	inline NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B value)
	{
		m_Items[index] = value;
	}
};
struct NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 m_Items[1];

	inline NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 value)
	{
		m_Items[index] = value;
	}
};
struct NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A m_Items[1];

	inline NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A value)
	{
		m_Items[index] = value;
	}
};
struct NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 m_Items[1];

	inline NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 value)
	{
		m_Items[index] = value;
	}
};
struct NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623  : public RuntimeArray
{
	ALIGN_FIELD (8) NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 m_Items[1];

	inline NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 value)
	{
		m_Items[index] = value;
	}
};
struct StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164  : public RuntimeArray
{
	ALIGN_FIELD (8) StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 m_Items[1];

	inline StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Value1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Value2), (void*)NULL);
		#endif
	}
	inline StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Value1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Value2), (void*)NULL);
		#endif
	}
};
struct ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 m_Items[1];

	inline ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 value)
	{
		m_Items[index] = value;
	}
};
struct ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD m_Items[1];

	inline ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item2), (void*)NULL);
	}
	inline ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item2), (void*)NULL);
	}
};
struct ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 m_Items[1];

	inline ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 value)
	{
		m_Items[index] = value;
	}
};
struct ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 m_Items[1];

	inline ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___Item2))->___Item1), (void*)NULL);
		#endif
	}
	inline ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___Item2))->___Item1), (void*)NULL);
		#endif
	}
};
struct ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 m_Items[1];

	inline ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
	}
	inline ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
	}
};
struct ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A m_Items[1];

	inline ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item2), (void*)NULL);
		#endif
	}
	inline ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item2), (void*)NULL);
		#endif
	}
};
struct ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A m_Items[1];

	inline ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
	}
	inline ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
	}
};
struct ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE m_Items[1];

	inline ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE value)
	{
		m_Items[index] = value;
	}
};
struct ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A m_Items[1];

	inline ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A value)
	{
		m_Items[index] = value;
	}
};
struct ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 m_Items[1];

	inline ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item3), (void*)NULL);
	}
	inline ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item3), (void*)NULL);
	}
};
struct ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD m_Items[1];

	inline ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item3), (void*)NULL);
		#endif
	}
	inline ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item3), (void*)NULL);
		#endif
	}
};
struct AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8  : public RuntimeArray
{
	ALIGN_FIELD (8) AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB m_Items[1];

	inline AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___sprites), (void*)NULL);
	}
	inline AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___sprites), (void*)NULL);
	}
};
struct AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268  : public RuntimeArray
{
	ALIGN_FIELD (8) AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 m_Items[1];

	inline AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___paymentMode), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___displayPrice), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___periodUnit), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___type), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___id), (void*)NULL);
		#endif
	}
	inline AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___paymentMode), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___displayPrice), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___periodUnit), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___type), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___id), (void*)NULL);
		#endif
	}
};
struct AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A  : public RuntimeArray
{
	ALIGN_FIELD (8) AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 m_Items[1];

	inline AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 value)
	{
		m_Items[index] = value;
	}
};


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, Il2CppSharedGenericObject* ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_EnsureCapacity_mE51DEC740B84D2ED1BA90157DF16E404819D25BB_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_IndexOf_m035160F7F44A3FC62835CC498A0C353827F573BC_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_RemoveAt_mF7AE2A8A24BEB275E49BF3F9B354A8BDA792171D_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m98C7BD6716BA17D25F8B9B4BD047C68BDEB19815_gshared (Enumerator_tC1F0E9CA9DC16B5DAF7219CEFDC81D297D74BB4D* __this, ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* ___0_builder, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_GetEnumerator_m47DE3657EA69A40875AF5EEFE0F0825319BC3EAA_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_ValidateNullValue_m5A0D9264CEB21C6D6E4894A8DC0FEB534711B90E_gshared (RuntimeObject* ___0_value, String_t* ___1_argument, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_Add_m27FBB2D810E0A0AD5DF459762BF64D4B63333D83_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_get_Count_m69CF2D9BF6F3E0F171B32C9129028208C163EF76_fshared_inline (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_IsCompatibleObject_mC7DC4275D0F4319AA58B02AD81E9B189857EC1E0_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_Contains_m47B0FE6D4FFF67C6AAAEDDCFCBA96922A7507D70_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_Insert_m9DDF62E919A397122ED64466833E33480EA94980_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_Remove_m16C754184D14C2E64F71386B150F02685E2C017F_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* ReadOnlyCollectionBuilder_1_get_Item_mBE6E2D88C69F6514FEE466701A475692D700D3BE_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_set_Item_m71A1888718F07FB7C27E03A0323479CC64FB9D60_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ReadOnlyCollectionBuilder_1_ToArray_m27A440E47420469361CDEE5C9B0D78C99F8E6DFD_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrueReadOnlyCollection_1__ctor_mD57EF5451712C65DFCEE4477FCDFD1E8E86143FE_gshared (TrueReadOnlyCollection_1_tB5F9BFA643D0B6B89EEC3ED99B9ADB907576B273* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_set_Capacity_mABDF1BEC26DE10439C869B5479ACCFFBF2B3DEBA_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m685E33687041AE241CB9AF46CD74A0D14F29375B (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF6E466AF68CFEC8F47F7CF45C4133EF69DDF248A (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m884266F7C492DE4AFA45B5059E72AB8AADFE1701 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC11B95DC5BCB94CAE3AFA3D16E8D584D5611EC8F (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m838B5E6314B03A3AB9923223BB4821D618210436 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2052E4178AF32DCCB3A36700D775691B7754B687 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m0977A268DF5A5540454EFACC58FF2C010A86CD3D (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mFFF2618F4888C7AB1485B1076C10EFD688BC7AD2 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0DA883888751E89AA69F98E60BAFF8FBABB38C60 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE00C5E66D753E1071BE29CCFB9B1297D147ABF76 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m4C16309031446534F4776B705DB4BF2FD0882362 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9244F5B1663BCC1829687A2C005146A449BE2A5E (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m71745ADD92D415DAACD7C285EA848CBB6B673B9B (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFD9D85FA10DC0E3CD95A7B801591CCF2DFAFD142 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD99308B65BA325981719086EA118A7F077305500 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m27BE264B56B78111130857D7F1C06E5C73CAA860 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mC0963FC6DD3F96602A2147E4A82AB5E3D0A374F1_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m06899F73FBFA0C918BAF26D47FE4BC69B0401960_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m998337273E514908027348F2AE19B89774318265_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m1C8B6015B945A9698E7DFC6E25D174AE08D88435_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mF7848E82A84A97D12EB2BEEE2C100A517E39F449_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD8FA777AE0AB15400CFAE1A41A905CDB5D21A19C_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3548041444A48A8090ECF81F9137AFE70B0BFC35_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2812D6D8A58856AF787AE4999E9C5F037CD707EA_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6D64B6B073FD1CF4D831ECFE05E1623A75FB96F5_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8716C838CA177C8AB0EA887D0B855BBD3B876695_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m75BDDF78FE058AD7B469434093D7A0D2998E10E7_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m28F2D0F0B3F893D1802E4D7B17256C66AEC58BBF_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m37C1965F27A1810D3AAA1331497EFA1D51A975A1_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m601594B931ACDA13FE772739FA4D3CEDB95165A8_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m1275764B723E3599AF2891F21C8F96CE3635C4BA_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mBD2424B8EBC3D9058E16CED4581527606F63F012_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8A97077239C70BE9C9375F2127C82F3C283E81A3 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF7AA90D7AC9126E9396188FEADDDAE16BD698924 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mBE15981470D788343F71D108AD20D6B88C99B199 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD789D84F5F7E12E4F6F6C7659ECB705958FE8531 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mAB482F95F7DAD8E45AEFC9D68113DC67B5A5FF18 (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m182F39AC5FB4735C49EE66373D712B20B3FF5FA2 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91996AFFF42C95AF18381233760D0FE8FB91D9CF (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m880B9A3177AA9FABE2C74EAAE1C697D1A6FB344A (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mD6A2DD10645C3C99E93B0A5D35C167ED7BA3B2B9 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mB6E515FF09DE1EE6B9C37CFC896EE7F4CA113045 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m4CAC8D293E40FB4526D9C23196EACF849F429379 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5550CBD835D9F269CB5920858A48CE8147947A92 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m16D553F92458225BB8CE5B325E381F38E84F3A3F (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m24AE4FAC7DBAB5FE4C92AEE7F9E04E80D5C7FF98 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC8653C9B3196644FFCCDE9279DFC1E25D1DB6D89 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5C407CE31DA6DAB79055A3C67C72D7674F358E03 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m479FD11AA0603AE8828762261714E8C366F349C6 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m7221B30E09E70A275D9F6D234544A9F037EC0E3D (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91A164D681D8812A4148D2561B6ECEC02CD61C49 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m71CEFBE6F99A20BB57961EC3A8455CA7919F7150 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m90E7B655CC2C12EC37423A97EBB21DB1680BE06B (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFDF4573C72E27A48C6A8BAE4DFE0C5EBD25CCA98 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF127107360D2211BEFC85AAEE36D96F6408B065E (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9229451605652B5DB71F8B8FE73569DEFFA6094D (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m1F139D4AE644DB044C847F0F70224AD21C6F70FB (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m17BEF3D58FBEC0BEF9235AE0049F72FD06EFC57F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3EDD912161578F48F5E76C01D7C19F8F98B5617E (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB9392399119A83D55E96CED8494B18D93A4B5899 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m1E0EFF605A7C6AFE538C0AA18CC455215DF08677 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE45427E8FB79B15653D9795E67A727F7532F235B (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m2506B3215547F42B9D6E73C07F394B8CCC14EDA2 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m774093B34CAD7C830556A1CD6D842A18A7A9FDF8 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m3BA31B14BBC7A97723D334EE4916E6B9CE7AE4AB (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mB69CBF81CE741C05119502E3BBE6A16168167183 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m21357843C08DD018321DEC0F827058249C12FFE6 (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mF638FA3440A3F8803CF8FD7C4E6C5165141DE67D (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mB0E24DAF8C568571332AF177303189F62090F44D (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m188B55BB38B193FE525D0168DD93F727B284303C (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3E4CA572BF4E2858AABCCDEA7E1B9639139ED95D (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m65881C5133BEFF21657BE17CDA6B0D53F0C1A069 (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m813EBFE05B405D460C626549A2B1C08B46AF26DB_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m00E361BD734D56DCB64859EFC32906149A15CAA4_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF30016445EF74DDD420AF1ADE0DEB973FCC37DA2_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD1E73B41F1D7A726922A535E3AC85C4570EA465D_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m22CBB31C2006C251E77F8CC2DB25A12D03D5BD01 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAF4CA48061578EA8B528540FAD8A11B4C7AEDC23 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB424DEE3614BE559019564915A0EA182D174E1D8 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC64BC7655EDC71AE828DA48A855B7B11FAD88E1A (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m85793655936FB0984A1437FA8ECE7C861B160646_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m37AF7A81489AFACD3B812FF86BF68E379082C395_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m8EB998278F51347C4335B03C22BFB855F9DC51F0_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m12554E59854370E4B6082003EABA5DA03A3B680A_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m441E8A559A937B2AA5BFBB1EC47DB85C7D41FB30 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0679C85B7420BD4BE52693726F3A0013CE0CFD86 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD7B1ABB0F30B168A850EE84B657E2691ADE472D1 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m020859FBB1F4F960CF018EE5ABFE2D4CF402EDB1 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mAC01605A25EA01A4162FCE81666FB6171F97F73F_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2B0739599199C6A9CA68E76243B82FC95AFE51D1_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6FDC3360288048A079D7BC0765A793E2D58C8382_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5C2C3C21DB3D20012826C34FDA5F9E30F535B4EA_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6759710C359F915427FA51E39C33D643F6BAC85F_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2EB896A15558B789AE100FB4897DC14AA432461B_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9FCF331B6C2A5F3A5ECC3945D34D5D0814BB37A1_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD2FB104B201A6DE074BE32296004577183D14894_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6337979AD706638A60D4AFA07D502AE6FF632E2B_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m33945B9FF3F43E48AF59D3668CAFC751AAD0104A_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m458363841FB434CC5EF70D2D94CC5118F3120EF3_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9165843F35CE2EC52317581AF71C7430C75EA8C6_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m7FAF007DE7EE5211977590CB5AB494F2B7F30880_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m6CBCF4F8E88F394DC8D0C83A34A273EB4711DFAD_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m1574622B122C5C819CDF2B52F913B7F029E1A8AE_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE1D3AF35A8338D68A1D96381AFF9AF8494C6E6AA_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mBAA33C444E3938A042923D39724E03326EE8B24A_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF27356D302C16DB6F6D0050D55AF437BBF77EDE5_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m827FFBAD02BB6E948B151CF1B7FF3FBA94103463_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mABEA50A98CFC875525107305139F54234862B41C_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6446FB01DDEB8F7C437FC2CC0A5F5733EF70552D (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m81E917BEA2914B04D9EF4D97564BFC50DB5C506F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mE77F913CCFF9E1305F3BC87C4355AE2F0E57D3E3 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC3D2945DCADDB4638731ABC140B447B953139CD5 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m592D5F512E13B72776FD22657D3914D6175A7BB0_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAA5EF416789EF268D338EDA3CA5646845E9359FD_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m119E4EE9C57EC91ECF98FD691A5DB45B73DFD6B0_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mED49053F7FEA4AF9AE64E66AA79A0679B2BF89CC_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE1C93AAD70F6223EAE9A21DED15E2A4D67061146_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC8346D99AEB0B3F66D7435BA57A24061B724C8E5_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mCA566CF8841B3859F7D5B9A3BE333DDF08EAFCCF_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mFA374F7FE0EA2D33D5547CE13F88627B41F9B404_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m11B7E7B09BC365660BE64984527A5A808A671A1D (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8F8678284BE3C77A1B662031EFA148C2799B9879 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB5CB8F733B8D8EA77F0F14325CC976C7A45E7995 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9F4573CEEB963B0B9FAC662F7210150A67189CF3 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m00D77F6AA6972CFF4B6A58882717FAF6DDBE0639 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFC73528B5D35D41C03C78E4D8316F63E8D94501C (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m80B4A89CA0CEE0CA1B26BAA6E6E967EC0BB1D451 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE2C36182593633F35CF539C68782AB51913697C1 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m46B28078AF43B3418EFBF649AE59DF831EEEB731 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF533CD6CA43BB8725B7B7F42FA27C815727C3355 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mA2DF0C486FDCE07EDD28180F3667A86F91C69C74 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2A5E17B439B8A1DC1FE1E7017EC0C5F58DD2596D (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530_gshared (const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_inline (const RuntimeMethod* method)
{
	return ((  __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* (*) (const RuntimeMethod*))Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41 (RuntimeArray* ___0_sourceArray, int32_t ___1_sourceIndex, RuntimeArray* ___2_destinationArray, int32_t ___3_destinationIndex, int32_t ___4_length, const RuntimeMethod* method) ;
inline int32_t Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, Il2CppSharedGenericObject* ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Il2CppSharedGenericObject*, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline void ReadOnlyCollectionBuilder_1_EnsureCapacity_mE51DEC740B84D2ED1BA90157DF16E404819D25BB (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_min, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, int32_t, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_EnsureCapacity_mE51DEC740B84D2ED1BA90157DF16E404819D25BB_gshared)(__this, ___0_min, method);
}
inline EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline)(method);
}
inline int32_t ReadOnlyCollectionBuilder_1_IndexOf_m035160F7F44A3FC62835CC498A0C353827F573BC (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, Il2CppSharedGenericObject*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_IndexOf_m035160F7F44A3FC62835CC498A0C353827F573BC_gshared)(__this, ___0_item, method);
}
inline void ReadOnlyCollectionBuilder_1_RemoveAt_mF7AE2A8A24BEB275E49BF3F9B354A8BDA792171D (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, int32_t, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_RemoveAt_mF7AE2A8A24BEB275E49BF3F9B354A8BDA792171D_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_m98C7BD6716BA17D25F8B9B4BD047C68BDEB19815 (Enumerator_tC1F0E9CA9DC16B5DAF7219CEFDC81D297D74BB4D* __this, ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* ___0_builder, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tC1F0E9CA9DC16B5DAF7219CEFDC81D297D74BB4D*, ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, const RuntimeMethod*))Enumerator__ctor_m98C7BD6716BA17D25F8B9B4BD047C68BDEB19815_gshared)(__this, ___0_builder, method);
}
inline RuntimeObject* ReadOnlyCollectionBuilder_1_GetEnumerator_m47DE3657EA69A40875AF5EEFE0F0825319BC3EAA (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_GetEnumerator_m47DE3657EA69A40875AF5EEFE0F0825319BC3EAA_gshared)(__this, method);
}
inline void ReadOnlyCollectionBuilder_1_ValidateNullValue_m5A0D9264CEB21C6D6E4894A8DC0FEB534711B90E (RuntimeObject* ___0_value, String_t* ___1_argument, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, String_t*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_ValidateNullValue_m5A0D9264CEB21C6D6E4894A8DC0FEB534711B90E_gshared)(___0_value, ___1_argument, method);
}
inline void ReadOnlyCollectionBuilder_1_Add_m27FBB2D810E0A0AD5DF459762BF64D4B63333D83 (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, Il2CppSharedGenericObject*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_Add_m27FBB2D810E0A0AD5DF459762BF64D4B63333D83_gshared)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* Error_InvalidTypeException_m434387C9B5952F3087CD01FEA17199E22AADA89C (RuntimeObject* ___0_value, Type_t* ___1_type, String_t* ___2_paramName, const RuntimeMethod* method) ;
inline int32_t ReadOnlyCollectionBuilder_1_get_Count_mC5999DCAC16DD6BDFDE95A9330B2F2B12B4BABDC_inline (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_get_Count_m69CF2D9BF6F3E0F171B32C9129028208C163EF76_fshared_inline)(__this, method);
}
inline bool ReadOnlyCollectionBuilder_1_IsCompatibleObject_mC7DC4275D0F4319AA58B02AD81E9B189857EC1E0 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_IsCompatibleObject_mC7DC4275D0F4319AA58B02AD81E9B189857EC1E0_gshared)(___0_value, method);
}
inline bool ReadOnlyCollectionBuilder_1_Contains_m47B0FE6D4FFF67C6AAAEDDCFCBA96922A7507D70 (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, Il2CppSharedGenericObject*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_Contains_m47B0FE6D4FFF67C6AAAEDDCFCBA96922A7507D70_gshared)(__this, ___0_item, method);
}
inline void ReadOnlyCollectionBuilder_1_Insert_m9DDF62E919A397122ED64466833E33480EA94980 (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_Insert_m9DDF62E919A397122ED64466833E33480EA94980_gshared)(__this, ___0_index, ___1_item, method);
}
inline bool ReadOnlyCollectionBuilder_1_Remove_m16C754184D14C2E64F71386B150F02685E2C017F (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, Il2CppSharedGenericObject*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_Remove_m16C754184D14C2E64F71386B150F02685E2C017F_gshared)(__this, ___0_item, method);
}
inline Il2CppSharedGenericObject* ReadOnlyCollectionBuilder_1_get_Item_mBE6E2D88C69F6514FEE466701A475692D700D3BE (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, int32_t, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_get_Item_mBE6E2D88C69F6514FEE466701A475692D700D3BE_gshared)(__this, ___0_index, method);
}
inline void ReadOnlyCollectionBuilder_1_set_Item_m71A1888718F07FB7C27E03A0323479CC64FB9D60 (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_set_Item_m71A1888718F07FB7C27E03A0323479CC64FB9D60_gshared)(__this, ___0_index, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ReadOnlyCollectionBuilder_1_ToArray_m27A440E47420469361CDEE5C9B0D78C99F8E6DFD (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method)
{
	return ((  __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_ToArray_m27A440E47420469361CDEE5C9B0D78C99F8E6DFD_gshared)(__this, method);
}
inline void TrueReadOnlyCollection_1__ctor_mD57EF5451712C65DFCEE4477FCDFD1E8E86143FE (TrueReadOnlyCollection_1_tB5F9BFA643D0B6B89EEC3ED99B9ADB907576B273* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (TrueReadOnlyCollection_1_tB5F9BFA643D0B6B89EEC3ED99B9ADB907576B273*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, const RuntimeMethod*))TrueReadOnlyCollection_1__ctor_mD57EF5451712C65DFCEE4477FCDFD1E8E86143FE_gshared)(__this, ___0_list, method);
}
inline void ReadOnlyCollectionBuilder_1_set_Capacity_mABDF1BEC26DE10439C869B5479ACCFFBF2B3DEBA (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068*, int32_t, const RuntimeMethod*))ReadOnlyCollectionBuilder_1_set_Capacity_mABDF1BEC26DE10439C869B5479ACCFFBF2B3DEBA_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* Error_InvalidNullValue_mD3F707613D9B6413719EB3549DAF5406FBD60199 (Type_t* ___0_type, String_t* ___1_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC (int32_t ___0_argument, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA (int32_t ___0_resource, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC (RuntimeArray* __this, int32_t ___0_dimension, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m685E33687041AE241CB9AF46CD74A0D14F29375B (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF6E466AF68CFEC8F47F7CF45C4133EF69DDF248A (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m884266F7C492DE4AFA45B5059E72AB8AADFE1701 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC11B95DC5BCB94CAE3AFA3D16E8D584D5611EC8F (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m838B5E6314B03A3AB9923223BB4821D618210436 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2052E4178AF32DCCB3A36700D775691B7754B687 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m0977A268DF5A5540454EFACC58FF2C010A86CD3D (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mFFF2618F4888C7AB1485B1076C10EFD688BC7AD2 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0DA883888751E89AA69F98E60BAFF8FBABB38C60 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE00C5E66D753E1071BE29CCFB9B1297D147ABF76 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m4C16309031446534F4776B705DB4BF2FD0882362 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9244F5B1663BCC1829687A2C005146A449BE2A5E (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m71745ADD92D415DAACD7C285EA848CBB6B673B9B (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFD9D85FA10DC0E3CD95A7B801591CCF2DFAFD142 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD99308B65BA325981719086EA118A7F077305500 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m27BE264B56B78111130857D7F1C06E5C73CAA860 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ___0_value, const RuntimeMethod* method) ;
inline int32_t ReadOnlyCollection_1_get_Count_mC0963FC6DD3F96602A2147E4A82AB5E3D0A374F1 (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_mC0963FC6DD3F96602A2147E4A82AB5E3D0A374F1_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m06899F73FBFA0C918BAF26D47FE4BC69B0401960 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m06899F73FBFA0C918BAF26D47FE4BC69B0401960_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m998337273E514908027348F2AE19B89774318265 (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A*, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m998337273E514908027348F2AE19B89774318265_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_m1C8B6015B945A9698E7DFC6E25D174AE08D88435 (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A*, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_m1C8B6015B945A9698E7DFC6E25D174AE08D88435_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_mF7848E82A84A97D12EB2BEEE2C100A517E39F449 (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_mF7848E82A84A97D12EB2BEEE2C100A517E39F449_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_mD8FA777AE0AB15400CFAE1A41A905CDB5D21A19C (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_mD8FA777AE0AB15400CFAE1A41A905CDB5D21A19C_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m3548041444A48A8090ECF81F9137AFE70B0BFC35 (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E*, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m3548041444A48A8090ECF81F9137AFE70B0BFC35_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_m2812D6D8A58856AF787AE4999E9C5F037CD707EA (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E*, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_m2812D6D8A58856AF787AE4999E9C5F037CD707EA_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_m6D64B6B073FD1CF4D831ECFE05E1623A75FB96F5 (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m6D64B6B073FD1CF4D831ECFE05E1623A75FB96F5_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m8716C838CA177C8AB0EA887D0B855BBD3B876695 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m8716C838CA177C8AB0EA887D0B855BBD3B876695_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m75BDDF78FE058AD7B469434093D7A0D2998E10E7 (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5*, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m75BDDF78FE058AD7B469434093D7A0D2998E10E7_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_m28F2D0F0B3F893D1802E4D7B17256C66AEC58BBF (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5*, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_m28F2D0F0B3F893D1802E4D7B17256C66AEC58BBF_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_m37C1965F27A1810D3AAA1331497EFA1D51A975A1 (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m37C1965F27A1810D3AAA1331497EFA1D51A975A1_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m601594B931ACDA13FE772739FA4D3CEDB95165A8 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m601594B931ACDA13FE772739FA4D3CEDB95165A8_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m1275764B723E3599AF2891F21C8F96CE3635C4BA (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m1275764B723E3599AF2891F21C8F96CE3635C4BA_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_mBD2424B8EBC3D9058E16CED4581527606F63F012 (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4*, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_mBD2424B8EBC3D9058E16CED4581527606F63F012_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8A97077239C70BE9C9375F2127C82F3C283E81A3 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF7AA90D7AC9126E9396188FEADDDAE16BD698924 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mBE15981470D788343F71D108AD20D6B88C99B199 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD789D84F5F7E12E4F6F6C7659ECB705958FE8531 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mAB482F95F7DAD8E45AEFC9D68113DC67B5A5FF18 (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m182F39AC5FB4735C49EE66373D712B20B3FF5FA2 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91996AFFF42C95AF18381233760D0FE8FB91D9CF (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m880B9A3177AA9FABE2C74EAAE1C697D1A6FB344A (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mD6A2DD10645C3C99E93B0A5D35C167ED7BA3B2B9 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mB6E515FF09DE1EE6B9C37CFC896EE7F4CA113045 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m4CAC8D293E40FB4526D9C23196EACF849F429379 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5550CBD835D9F269CB5920858A48CE8147947A92 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m16D553F92458225BB8CE5B325E381F38E84F3A3F (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m24AE4FAC7DBAB5FE4C92AEE7F9E04E80D5C7FF98 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC8653C9B3196644FFCCDE9279DFC1E25D1DB6D89 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5C407CE31DA6DAB79055A3C67C72D7674F358E03 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m479FD11AA0603AE8828762261714E8C366F349C6 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m7221B30E09E70A275D9F6D234544A9F037EC0E3D (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91A164D681D8812A4148D2561B6ECEC02CD61C49 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m71CEFBE6F99A20BB57961EC3A8455CA7919F7150 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m90E7B655CC2C12EC37423A97EBB21DB1680BE06B (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFDF4573C72E27A48C6A8BAE4DFE0C5EBD25CCA98 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF127107360D2211BEFC85AAEE36D96F6408B065E (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9229451605652B5DB71F8B8FE73569DEFFA6094D (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m1F139D4AE644DB044C847F0F70224AD21C6F70FB (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m17BEF3D58FBEC0BEF9235AE0049F72FD06EFC57F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3EDD912161578F48F5E76C01D7C19F8F98B5617E (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB9392399119A83D55E96CED8494B18D93A4B5899 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m1E0EFF605A7C6AFE538C0AA18CC455215DF08677 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE45427E8FB79B15653D9795E67A727F7532F235B (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m2506B3215547F42B9D6E73C07F394B8CCC14EDA2 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m774093B34CAD7C830556A1CD6D842A18A7A9FDF8 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m3BA31B14BBC7A97723D334EE4916E6B9CE7AE4AB (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mB69CBF81CE741C05119502E3BBE6A16168167183 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m21357843C08DD018321DEC0F827058249C12FFE6 (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mF638FA3440A3F8803CF8FD7C4E6C5165141DE67D (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mB0E24DAF8C568571332AF177303189F62090F44D (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m188B55BB38B193FE525D0168DD93F727B284303C (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3E4CA572BF4E2858AABCCDEA7E1B9639139ED95D (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m65881C5133BEFF21657BE17CDA6B0D53F0C1A069 (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ___0_value, const RuntimeMethod* method) ;
inline int32_t ReadOnlyCollection_1_get_Count_m813EBFE05B405D460C626549A2B1C08B46AF26DB (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m813EBFE05B405D460C626549A2B1C08B46AF26DB_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m00E361BD734D56DCB64859EFC32906149A15CAA4 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m00E361BD734D56DCB64859EFC32906149A15CAA4_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_mF30016445EF74DDD420AF1ADE0DEB973FCC37DA2 (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE*, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328, const RuntimeMethod*))ReadOnlyCollection_1_Contains_mF30016445EF74DDD420AF1ADE0DEB973FCC37DA2_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_mD1E73B41F1D7A726922A535E3AC85C4570EA465D (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE*, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_mD1E73B41F1D7A726922A535E3AC85C4570EA465D_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m22CBB31C2006C251E77F8CC2DB25A12D03D5BD01 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAF4CA48061578EA8B528540FAD8A11B4C7AEDC23 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB424DEE3614BE559019564915A0EA182D174E1D8 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC64BC7655EDC71AE828DA48A855B7B11FAD88E1A (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ___0_value, const RuntimeMethod* method) ;
inline int32_t ReadOnlyCollection_1_get_Count_m85793655936FB0984A1437FA8ECE7C861B160646 (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m85793655936FB0984A1437FA8ECE7C861B160646_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m37AF7A81489AFACD3B812FF86BF68E379082C395 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m37AF7A81489AFACD3B812FF86BF68E379082C395_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m8EB998278F51347C4335B03C22BFB855F9DC51F0 (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9*, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m8EB998278F51347C4335B03C22BFB855F9DC51F0_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_m12554E59854370E4B6082003EABA5DA03A3B680A (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9*, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_m12554E59854370E4B6082003EABA5DA03A3B680A_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m441E8A559A937B2AA5BFBB1EC47DB85C7D41FB30 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0679C85B7420BD4BE52693726F3A0013CE0CFD86 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD7B1ABB0F30B168A850EE84B657E2691ADE472D1 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m020859FBB1F4F960CF018EE5ABFE2D4CF402EDB1 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ___0_value, const RuntimeMethod* method) ;
inline int32_t ReadOnlyCollection_1_get_Count_mAC01605A25EA01A4162FCE81666FB6171F97F73F (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_mAC01605A25EA01A4162FCE81666FB6171F97F73F_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m2B0739599199C6A9CA68E76243B82FC95AFE51D1 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m2B0739599199C6A9CA68E76243B82FC95AFE51D1_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m6FDC3360288048A079D7BC0765A793E2D58C8382 (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7*, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m6FDC3360288048A079D7BC0765A793E2D58C8382_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_m5C2C3C21DB3D20012826C34FDA5F9E30F535B4EA (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7*, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_m5C2C3C21DB3D20012826C34FDA5F9E30F535B4EA_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_m6759710C359F915427FA51E39C33D643F6BAC85F (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m6759710C359F915427FA51E39C33D643F6BAC85F_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m2EB896A15558B789AE100FB4897DC14AA432461B (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m2EB896A15558B789AE100FB4897DC14AA432461B_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m9FCF331B6C2A5F3A5ECC3945D34D5D0814BB37A1 (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7*, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m9FCF331B6C2A5F3A5ECC3945D34D5D0814BB37A1_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_mD2FB104B201A6DE074BE32296004577183D14894 (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7*, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_mD2FB104B201A6DE074BE32296004577183D14894_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_m6337979AD706638A60D4AFA07D502AE6FF632E2B (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m6337979AD706638A60D4AFA07D502AE6FF632E2B_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m33945B9FF3F43E48AF59D3668CAFC751AAD0104A (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m33945B9FF3F43E48AF59D3668CAFC751AAD0104A_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m458363841FB434CC5EF70D2D94CC5118F3120EF3 (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m458363841FB434CC5EF70D2D94CC5118F3120EF3_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_m9165843F35CE2EC52317581AF71C7430C75EA8C6 (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_m9165843F35CE2EC52317581AF71C7430C75EA8C6_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_m7FAF007DE7EE5211977590CB5AB494F2B7F30880 (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m7FAF007DE7EE5211977590CB5AB494F2B7F30880_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_m6CBCF4F8E88F394DC8D0C83A34A273EB4711DFAD (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_m6CBCF4F8E88F394DC8D0C83A34A273EB4711DFAD_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m1574622B122C5C819CDF2B52F913B7F029E1A8AE (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m1574622B122C5C819CDF2B52F913B7F029E1A8AE_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_mE1D3AF35A8338D68A1D96381AFF9AF8494C6E6AA (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_mE1D3AF35A8338D68A1D96381AFF9AF8494C6E6AA_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_mBAA33C444E3938A042923D39724E03326EE8B24A (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_mBAA33C444E3938A042923D39724E03326EE8B24A_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_mF27356D302C16DB6F6D0050D55AF437BBF77EDE5 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_mF27356D302C16DB6F6D0050D55AF437BBF77EDE5_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m827FFBAD02BB6E948B151CF1B7FF3FBA94103463 (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8*, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m827FFBAD02BB6E948B151CF1B7FF3FBA94103463_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_mABEA50A98CFC875525107305139F54234862B41C (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8*, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_mABEA50A98CFC875525107305139F54234862B41C_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6446FB01DDEB8F7C437FC2CC0A5F5733EF70552D (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m81E917BEA2914B04D9EF4D97564BFC50DB5C506F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mE77F913CCFF9E1305F3BC87C4355AE2F0E57D3E3 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC3D2945DCADDB4638731ABC140B447B953139CD5 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ___0_value, const RuntimeMethod* method) ;
inline int32_t ReadOnlyCollection_1_get_Count_m592D5F512E13B72776FD22657D3914D6175A7BB0 (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_m592D5F512E13B72776FD22657D3914D6175A7BB0_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_mAA5EF416789EF268D338EDA3CA5646845E9359FD (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_mAA5EF416789EF268D338EDA3CA5646845E9359FD_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_m119E4EE9C57EC91ECF98FD691A5DB45B73DFD6B0 (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3*, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4, const RuntimeMethod*))ReadOnlyCollection_1_Contains_m119E4EE9C57EC91ECF98FD691A5DB45B73DFD6B0_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_mED49053F7FEA4AF9AE64E66AA79A0679B2BF89CC (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3*, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_mED49053F7FEA4AF9AE64E66AA79A0679B2BF89CC_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_get_Count_mE1C93AAD70F6223EAE9A21DED15E2A4D67061146 (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F*, const RuntimeMethod*))ReadOnlyCollection_1_get_Count_mE1C93AAD70F6223EAE9A21DED15E2A4D67061146_gshared)(__this, method);
}
inline bool ReadOnlyCollection_1_IsCompatibleObject_mC8346D99AEB0B3F66D7435BA57A24061B724C8E5 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1_IsCompatibleObject_mC8346D99AEB0B3F66D7435BA57A24061B724C8E5_gshared)(___0_value, method);
}
inline bool ReadOnlyCollection_1_Contains_mCA566CF8841B3859F7D5B9A3BE333DDF08EAFCCF (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F*, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD, const RuntimeMethod*))ReadOnlyCollection_1_Contains_mCA566CF8841B3859F7D5B9A3BE333DDF08EAFCCF_gshared)(__this, ___0_value, method);
}
inline int32_t ReadOnlyCollection_1_IndexOf_mFA374F7FE0EA2D33D5547CE13F88627B41F9B404 (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F*, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD, const RuntimeMethod*))ReadOnlyCollection_1_IndexOf_mFA374F7FE0EA2D33D5547CE13F88627B41F9B404_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m11B7E7B09BC365660BE64984527A5A808A671A1D (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8F8678284BE3C77A1B662031EFA148C2799B9879 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB5CB8F733B8D8EA77F0F14325CC976C7A45E7995 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9F4573CEEB963B0B9FAC662F7210150A67189CF3 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m00D77F6AA6972CFF4B6A58882717FAF6DDBE0639 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFC73528B5D35D41C03C78E4D8316F63E8D94501C (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m80B4A89CA0CEE0CA1B26BAA6E6E967EC0BB1D451 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE2C36182593633F35CF539C68782AB51913697C1 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m46B28078AF43B3418EFBF649AE59DF831EEEB731 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF533CD6CA43BB8725B7B7F42FA27C815727C3355 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mA2DF0C486FDCE07EDD28180F3667A86F91C69C74 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2A5E17B439B8A1DC1FE1E7017EC0C5F58DD2596D (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ___0_value, const RuntimeMethod* method) ;
inline EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530_gshared)(method);
}
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 70839
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1__ctor_m434ED7461C2E7568BCD6BA4A788C4BB69D8E35D5_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0;
		L_0 = Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 70840
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1__ctor_mDF70775C4782DF5F52064B794FF3EBF23A88471D_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_1 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_0015:
	{
		int32_t L_2 = ___0_capacity;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		__this->____items = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_3);
		return;
	}
}
// Method Definition Index: 70841
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_set_Capacity_mABDF1BEC26DE10439C869B5479ACCFFBF2B3DEBA_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = ___0_value;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((((int32_t)L_3) == ((int32_t)L_5)))
		{
			goto IL_005a;
		}
	}
	{
		int32_t L_6 = ___0_value;
		if ((((int32_t)L_6) <= ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_7 = ___0_value;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_8 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		V_0 = L_8;
		int32_t L_9 = __this->____size;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0047;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = V_0;
		int32_t L_12 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, 0, (RuntimeArray*)L_11, 0, L_12, NULL);
	}

IL_0047:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_13 = V_0;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
		return;
	}

IL_004f:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14;
		L_14 = Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->____items = L_14;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_14);
	}

IL_005a:
	{
		return;
	}
}
// Method Definition Index: 70842
// Method Definition Index: 70843
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_IndexOf_m035160F7F44A3FC62835CC498A0C353827F573BC_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->____items;
		Il2CppSharedGenericObject* L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return L_3;
	}
}
// Method Definition Index: 70844
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_Insert_m9DDF62E919A397122ED64466833E33480EA94980_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) <= ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) == ((uint32_t)L_5))))
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_6 = __this->____size;
		ReadOnlyCollectionBuilder_1_EnsureCapacity_mE51DEC740B84D2ED1BA90157DF16E404819D25BB(__this, ((int32_t)il2cpp_codegen_add(L_6, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
	}

IL_0032:
	{
		int32_t L_7 = ___0_index;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0058;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_9 = __this->____items;
		int32_t L_10 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = __this->____size;
		int32_t L_14 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, 1)), ((int32_t)il2cpp_codegen_subtract(L_13, L_14)), NULL);
	}

IL_0058:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_15 = __this->____items;
		int32_t L_16 = ___0_index;
		Il2CppSharedGenericObject* L_17 = ___1_item;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(L_16), (Il2CppSharedGenericObject*)L_17);
		int32_t L_18 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_18, 1));
		int32_t L_19 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_19, 1));
		return;
	}
}
// Method Definition Index: 70845
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_RemoveAt_mF7AE2A8A24BEB275E49BF3F9B354A8BDA792171D_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_000d;
		}
	}
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_1) < ((int32_t)L_2)))
		{
			goto IL_0018;
		}
	}

IL_000d:
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_3 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0018:
	{
		int32_t L_4 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_4, 1));
		int32_t L_5 = ___0_index;
		int32_t L_6 = __this->____size;
		if ((((int32_t)L_5) >= ((int32_t)L_6)))
		{
			goto IL_004c;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_9 = __this->____items;
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		int32_t L_12 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, ((int32_t)il2cpp_codegen_add(L_8, 1)), (RuntimeArray*)L_9, L_10, ((int32_t)il2cpp_codegen_subtract(L_11, L_12)), NULL);
	}

IL_004c:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_13 = __this->____items;
		int32_t L_14 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_15 = V_0;
		NullCheck(L_13);
		(L_13)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (Il2CppSharedGenericObject*)L_15);
		int32_t L_16 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_16, 1));
		return;
	}
}
// Method Definition Index: 70846
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* ReadOnlyCollectionBuilder_1_get_Item_mBE6E2D88C69F6514FEE466701A475692D700D3BE_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		Il2CppSharedGenericObject* L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		return L_6;
	}
}
// Method Definition Index: 70847
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_set_Item_m71A1888718F07FB7C27E03A0323479CC64FB9D60_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = ___0_index;
		Il2CppSharedGenericObject* L_5 = ___1_value;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (Il2CppSharedGenericObject*)L_5);
		int32_t L_6 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_6, 1));
		return;
	}
}
// Method Definition Index: 70848
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_Add_m27FBB2D810E0A0AD5DF459762BF64D4B63333D83_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->____items;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		if ((!(((uint32_t)L_0) == ((uint32_t)L_2))))
		{
			goto IL_001e;
		}
	}
	{
		int32_t L_3 = __this->____size;
		ReadOnlyCollectionBuilder_1_EnsureCapacity_mE51DEC740B84D2ED1BA90157DF16E404819D25BB(__this, ((int32_t)il2cpp_codegen_add(L_3, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
	}

IL_001e:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		int32_t L_5 = __this->____size;
		V_0 = L_5;
		int32_t L_6 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		int32_t L_7 = V_0;
		Il2CppSharedGenericObject* L_8 = ___0_item;
		NullCheck(L_4);
		(L_4)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (Il2CppSharedGenericObject*)L_8);
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 70849
// Method Definition Index: 70850
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_Contains_m47B0FE6D4FFF67C6AAAEDDCFCBA96922A7507D70_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_1 = NULL;
	int32_t V_2 = 0;
	{
		Il2CppSharedGenericObject* L_0 = ___0_item;
		if (L_0)
		{
			goto IL_0030;
		}
	}
	{
		V_0 = 0;
		goto IL_0025;
	}

IL_000c:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->____items;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Il2CppSharedGenericObject* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		if (L_4)
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}

IL_0021:
	{
		int32_t L_5 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0025:
	{
		int32_t L_6 = V_0;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) < ((int32_t)L_7)))
		{
			goto IL_000c;
		}
	}
	{
		return (bool)0;
	}

IL_0030:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_8;
		L_8 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		V_1 = L_8;
		V_2 = 0;
		goto IL_0055;
	}

IL_003a:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_9 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = __this->____items;
		int32_t L_11 = V_2;
		NullCheck(L_10);
		int32_t L_12 = L_11;
		Il2CppSharedGenericObject* L_13 = (L_10)->GetAt(static_cast<il2cpp_array_size_t>(L_12));
		Il2CppSharedGenericObject* L_14 = ___0_item;
		NullCheck(L_9);
		bool L_15;
		L_15 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_9, L_13, L_14);
		if (!L_15)
		{
			goto IL_0051;
		}
	}
	{
		return (bool)1;
	}

IL_0051:
	{
		int32_t L_16 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_16, 1));
	}

IL_0055:
	{
		int32_t L_17 = V_2;
		int32_t L_18 = __this->____size;
		if ((((int32_t)L_17) < ((int32_t)L_18)))
		{
			goto IL_003a;
		}
	}
	{
		return (bool)0;
	}
}
// Method Definition Index: 70851
// Method Definition Index: 70852
// Method Definition Index: 70853
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_Remove_m16C754184D14C2E64F71386B150F02685E2C017F_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		Il2CppSharedGenericObject* L_0 = ___0_item;
		int32_t L_1;
		L_1 = ReadOnlyCollectionBuilder_1_IndexOf_m035160F7F44A3FC62835CC498A0C353827F573BC(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		ReadOnlyCollectionBuilder_1_RemoveAt_mF7AE2A8A24BEB275E49BF3F9B354A8BDA792171D(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7));
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 70854
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_GetEnumerator_m47DE3657EA69A40875AF5EEFE0F0825319BC3EAA_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tC1F0E9CA9DC16B5DAF7219CEFDC81D297D74BB4D* L_0 = (Enumerator_tC1F0E9CA9DC16B5DAF7219CEFDC81D297D74BB4D*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 8));
		Enumerator__ctor_m98C7BD6716BA17D25F8B9B4BD047C68BDEB19815(L_0, __this, NULL);
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 70855
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_System_Collections_IEnumerable_GetEnumerator_m0A8081D95D269B431496FB0C5AB0146E817BF608_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0;
		L_0 = ReadOnlyCollectionBuilder_1_GetEnumerator_m47DE3657EA69A40875AF5EEFE0F0825319BC3EAA(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 70856
// Method Definition Index: 70857
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_System_Collections_IList_Add_m1FFFDA47A95F2010CA3F0CDE2A996E46021A5320_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_value;
		ReadOnlyCollectionBuilder_1_ValidateNullValue_m5A0D9264CEB21C6D6E4894A8DC0FEB534711B90E(L_0, _stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}
	try
	{
		RuntimeObject* L_1 = ___0_value;
		ReadOnlyCollectionBuilder_1_Add_m27FBB2D810E0A0AD5DF459762BF64D4B63333D83(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		goto IL_0030;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0019;
		}
		throw e;
	}

CATCH_0019:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		Exception_t* L_6;
		L_6 = Error_InvalidTypeException_m434387C9B5952F3087CD01FEA17199E22AADA89C(L_3, L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0030:
	{
		int32_t L_7;
		L_7 = ReadOnlyCollectionBuilder_1_get_Count_mC5999DCAC16DD6BDFDE95A9330B2F2B12B4BABDC_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_7, 1));
	}
}
// Method Definition Index: 70858
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_System_Collections_IList_Contains_m794279343D9901470EA1790C98B8E92246DD2EBB_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollectionBuilder_1_IsCompatibleObject_mC7DC4275D0F4319AA58B02AD81E9B189857EC1E0(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollectionBuilder_1_Contains_m47B0FE6D4FFF67C6AAAEDDCFCBA96922A7507D70(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 70859
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_System_Collections_IList_IndexOf_mD0A2B994ED8AAD91D57C77E5CFC1B89B0B4B2643_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollectionBuilder_1_IsCompatibleObject_mC7DC4275D0F4319AA58B02AD81E9B189857EC1E0(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollectionBuilder_1_IndexOf_m035160F7F44A3FC62835CC498A0C353827F573BC(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 70860
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_IList_Insert_m70346628AA7F6CA869A76C65B1DFE33B3D57A22A_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ReadOnlyCollectionBuilder_1_ValidateNullValue_m5A0D9264CEB21C6D6E4894A8DC0FEB534711B90E(L_0, _stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		ReadOnlyCollectionBuilder_1_Insert_m9DDF62E919A397122ED64466833E33480EA94980(__this, L_1, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 17));
		goto IL_0031;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_001a;
		}
		throw e;
	}

CATCH_001a:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		Exception_t* L_7;
		L_7 = Error_InvalidTypeException_m434387C9B5952F3087CD01FEA17199E22AADA89C(L_4, L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0031:
	{
		return;
	}
}
// Method Definition Index: 70861
// Method Definition Index: 70862
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_IList_Remove_m12469477709CACEA25627E870C20AF0AFAE2F5FD_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollectionBuilder_1_IsCompatibleObject_mC7DC4275D0F4319AA58B02AD81E9B189857EC1E0(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollectionBuilder_1_Remove_m16C754184D14C2E64F71386B150F02685E2C017F(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 70863
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_System_Collections_IList_get_Item_m13F2D80995402FEE24AE7BB6D087F282D6D15BFC_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		Il2CppSharedGenericObject* L_1;
		L_1 = ReadOnlyCollectionBuilder_1_get_Item_mBE6E2D88C69F6514FEE466701A475692D700D3BE(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (RuntimeObject*)L_1;
	}
}
// Method Definition Index: 70864
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_IList_set_Item_m35EC6754175258D920FA13101A73257E4137BCC6_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ReadOnlyCollectionBuilder_1_ValidateNullValue_m5A0D9264CEB21C6D6E4894A8DC0FEB534711B90E(L_0, _stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		ReadOnlyCollectionBuilder_1_set_Item_m71A1888718F07FB7C27E03A0323479CC64FB9D60(__this, L_1, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		goto IL_0031;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_001a;
		}
		throw e;
	}

CATCH_001a:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		Exception_t* L_7;
		L_7 = Error_InvalidTypeException_m434387C9B5952F3087CD01FEA17199E22AADA89C(L_4, L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0031:
	{
		return;
	}
}
// Method Definition Index: 70865
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_ICollection_CopyTo_m12BAF1C5293B7F696453A72CCB740F51B2A35F2A_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = il2cpp_codegen_array_get_rank(L_2);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0022;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0022:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = __this->____items;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7 = ___1_index;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, L_6, L_7, L_8, NULL);
		return;
	}
}
// Method Definition Index: 70866
// Method Definition Index: 70867
// Method Definition Index: 70868
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ReadOnlyCollectionBuilder_1_ToArray_m27A440E47420469361CDEE5C9B0D78C99F8E6DFD_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_0);
		V_0 = L_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = V_0;
		int32_t L_4 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_2, 0, (RuntimeArray*)L_3, 0, L_4, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = V_0;
		return L_5;
	}
}
// Method Definition Index: 70869
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263* ReadOnlyCollectionBuilder_1_ToReadOnlyCollection_m73583AEAD578218F3319098C87C2ECB9026E6990_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->____items;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		if ((!(((uint32_t)L_0) == ((uint32_t)L_2))))
		{
			goto IL_0019;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		V_0 = L_3;
		goto IL_0020;
	}

IL_0019:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4;
		L_4 = ReadOnlyCollectionBuilder_1_ToArray_m27A440E47420469361CDEE5C9B0D78C99F8E6DFD(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_4;
	}

IL_0020:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5;
		L_5 = Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->____items = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_5);
		__this->____size = 0;
		int32_t L_6 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = V_0;
		TrueReadOnlyCollection_1_tB5F9BFA643D0B6B89EEC3ED99B9ADB907576B273* L_8 = (TrueReadOnlyCollection_1_tB5F9BFA643D0B6B89EEC3ED99B9ADB907576B273*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		TrueReadOnlyCollection_1__ctor_mD57EF5451712C65DFCEE4477FCDFD1E8E86143FE(L_8, L_7, NULL);
		return (ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263*)L_8;
	}
}
// Method Definition Index: 70870
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_EnsureCapacity_mE51DEC740B84D2ED1BA90157DF16E404819D25BB_gshared (ReadOnlyCollectionBuilder_1_t8550E6B95F6234B1A5625122654919E1C7839068* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_002e;
		}
	}
	{
		V_0 = 4;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0021;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
	}

IL_0021:
	{
		int32_t L_6 = V_0;
		int32_t L_7 = ___0_min;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		int32_t L_8 = ___0_min;
		V_0 = L_8;
	}

IL_0027:
	{
		int32_t L_9 = V_0;
		ReadOnlyCollectionBuilder_1_set_Capacity_mABDF1BEC26DE10439C869B5479ACCFFBF2B3DEBA(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
	}

IL_002e:
	{
		return;
	}
}
// Method Definition Index: 70871
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_IsCompatibleObject_mC7DC4275D0F4319AA58B02AD81E9B189857EC1E0_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		RuntimeObject* L_0 = ___0_value;
		if (((Il2CppSharedGenericObject*)IsInst((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_2 = V_0;
		return (bool)((((RuntimeObject*)(Il2CppSharedGenericObject*)L_2) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 70872
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_ValidateNullValue_m5A0D9264CEB21C6D6E4894A8DC0FEB534711B90E_gshared (RuntimeObject* ___0_value, String_t* ___1_argument, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		RuntimeObject* L_0 = ___0_value;
		if (L_0)
		{
			goto IL_0024;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_1 = V_0;
		if (!L_1)
		{
			goto IL_0024;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		String_t* L_4 = ___1_argument;
		Exception_t* L_5;
		L_5 = Error_InvalidNullValue_mD3F707613D9B6413719EB3549DAF5406FBD60199(L_3, L_4, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_5, method);
	}

IL_0024:
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 70839
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1__ctor_m250934FFE92E68EB52BFA1DEEA225C006567E7E5_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0;
		L_0 = ((  __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 70840
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1__ctor_mB7397A597A8123C1146146FB19367CA32645A803_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_1 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_0015:
	{
		int32_t L_2 = ___0_capacity;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		__this->____items = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_3);
		return;
	}
}
// Method Definition Index: 70841
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_set_Capacity_mE67D65656DDB9AE1C58561936CD1EF7A50E4DA7C_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = ___0_value;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((((int32_t)L_3) == ((int32_t)L_5)))
		{
			goto IL_005a;
		}
	}
	{
		int32_t L_6 = ___0_value;
		if ((((int32_t)L_6) <= ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_7 = ___0_value;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_8 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		V_0 = L_8;
		int32_t L_9 = __this->____size;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0047;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = V_0;
		int32_t L_12 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, 0, (RuntimeArray*)L_11, 0, L_12, NULL);
	}

IL_0047:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_13 = V_0;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
		return;
	}

IL_004f:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14;
		L_14 = ((  __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->____items = L_14;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_14);
	}

IL_005a:
	{
		return;
	}
}
// Method Definition Index: 70842
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_get_Count_m69CF2D9BF6F3E0F171B32C9129028208C163EF76_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 70843
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_IndexOf_m230054649C9E9B91CD99DA0F363651A29A18B6D8_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? ___0_item : &___0_item), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = InvokerFuncInvoker4< int32_t, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Il2CppFullySharedGenericAny, int32_t, int32_t >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? L_1: *(void**)L_1), 0, L_2);
		return L_3;
	}
}
// Method Definition Index: 70844
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_Insert_mCC5CF7CBE8C56BCA2DCB0BFD28EE1A45EEE4A172_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) <= ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) == ((uint32_t)L_5))))
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_6 = __this->____size;
		((  void (*) (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(__this, ((int32_t)il2cpp_codegen_add(L_6, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
	}

IL_0032:
	{
		int32_t L_7 = ___0_index;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0058;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_9 = __this->____items;
		int32_t L_10 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = __this->____size;
		int32_t L_14 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, 1)), ((int32_t)il2cpp_codegen_subtract(L_13, L_14)), NULL);
	}

IL_0058:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_15 = __this->____items;
		int32_t L_16 = ___0_index;
		il2cpp_codegen_memcpy(L_17, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? ___1_item : &___1_item), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		NullCheck(L_15);
		il2cpp_codegen_memcpy((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)), L_17, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), (void**)(L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)), (void*)L_17);
		int32_t L_18 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_18, 1));
		int32_t L_19 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_19, 1));
		return;
	}
}
// Method Definition Index: 70845
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_RemoveAt_m39375336E09168B3D4FFADA6675E57994B75FB7E_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	memset(V_0, 0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_000d;
		}
	}
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_1) < ((int32_t)L_2)))
		{
			goto IL_0018;
		}
	}

IL_000d:
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_3 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0018:
	{
		int32_t L_4 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_4, 1));
		int32_t L_5 = ___0_index;
		int32_t L_6 = __this->____size;
		if ((((int32_t)L_5) >= ((int32_t)L_6)))
		{
			goto IL_004c;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_9 = __this->____items;
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		int32_t L_12 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, ((int32_t)il2cpp_codegen_add(L_8, 1)), (RuntimeArray*)L_9, L_10, ((int32_t)il2cpp_codegen_subtract(L_11, L_12)), NULL);
	}

IL_004c:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_13 = __this->____items;
		int32_t L_14 = __this->____size;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		il2cpp_codegen_memcpy(L_15, V_0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		NullCheck(L_13);
		il2cpp_codegen_memcpy((L_13)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_14)), L_15, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), (void**)(L_13)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_14)), (void*)L_15);
		int32_t L_16 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_16, 1));
		return;
	}
}
// Method Definition Index: 70846
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_get_Item_mBEEFA08F78CF92A07877C3B05F4507CE013B7DC4_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		il2cpp_codegen_memcpy(L_6, (L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_5)), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		il2cpp_codegen_memcpy(il2cppRetVal, L_6, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		return;
	}
}
// Method Definition Index: 70847
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_set_Item_m0F01A105DF646D259D03E3088CA5B17925BAC43A_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		int32_t L_4 = ___0_index;
		il2cpp_codegen_memcpy(L_5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? ___1_value : &___1_value), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		NullCheck(L_3);
		il2cpp_codegen_memcpy((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)), L_5, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), (void**)(L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)), (void*)L_5);
		int32_t L_6 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_6, 1));
		return;
	}
}
// Method Definition Index: 70848
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_Add_m0528305BD67E04F82A8F4EC8BDFD887D3FFD701F_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = __this->____items;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		if ((!(((uint32_t)L_0) == ((uint32_t)L_2))))
		{
			goto IL_001e;
		}
	}
	{
		int32_t L_3 = __this->____size;
		((  void (*) (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(__this, ((int32_t)il2cpp_codegen_add(L_3, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
	}

IL_001e:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		int32_t L_5 = __this->____size;
		V_0 = L_5;
		int32_t L_6 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		int32_t L_7 = V_0;
		il2cpp_codegen_memcpy(L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? ___0_item : &___0_item), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		NullCheck(L_4);
		il2cpp_codegen_memcpy((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)), L_8, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), (void**)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)), (void*)L_8);
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 70849
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_Clear_m96C2B04252182D9DDB022663C77731F047552C67_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if ((((int32_t)L_0) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = __this->____items;
		int32_t L_2 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_1, 0, L_2, NULL);
		__this->____size = 0;
	}

IL_0022:
	{
		int32_t L_3 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_3, 1));
		return;
	}
}
// Method Definition Index: 70850
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_Contains_mE6C66F860D3341CBA7A2D084DC75827B94995837_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	const Il2CppFullySharedGenericAny L_5 = L_0;
	const Il2CppFullySharedGenericAny L_15 = L_0;
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* V_1 = NULL;
	int32_t V_2 = 0;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? ___0_item : &___0_item), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		bool L_1 = il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_0);
		if (L_1)
		{
			goto IL_0030;
		}
	}
	{
		V_0 = 0;
		goto IL_0025;
	}

IL_000c:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		il2cpp_codegen_memcpy(L_5, (L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		bool L_6 = il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_5);
		if (L_6)
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, 1));
	}

IL_0025:
	{
		int32_t L_8 = V_0;
		int32_t L_9 = __this->____size;
		if ((((int32_t)L_8) < ((int32_t)L_9)))
		{
			goto IL_000c;
		}
	}
	{
		return (bool)0;
	}

IL_0030:
	{
		EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* L_10;
		L_10 = ((  EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		V_1 = L_10;
		V_2 = 0;
		goto IL_0055;
	}

IL_003a:
	{
		EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* L_11 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = __this->____items;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		il2cpp_codegen_memcpy(L_15, (L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_14)), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		il2cpp_codegen_memcpy(L_16, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? ___0_item : &___0_item), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		NullCheck(L_11);
		bool L_17;
		L_17 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(8, L_11, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? L_15: *(void**)L_15), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? L_16: *(void**)L_16));
		if (!L_17)
		{
			goto IL_0051;
		}
	}
	{
		return (bool)1;
	}

IL_0051:
	{
		int32_t L_18 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}

IL_0055:
	{
		int32_t L_19 = V_2;
		int32_t L_20 = __this->____size;
		if ((((int32_t)L_19) < ((int32_t)L_20)))
		{
			goto IL_003a;
		}
	}
	{
		return (bool)0;
	}
}
// Method Definition Index: 70851
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_CopyTo_mD4D52FA043D25FB3DC095C23FD4E3A3A44A5BA35_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = ___0_array;
		int32_t L_2 = ___1_arrayIndex;
		int32_t L_3 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_0, 0, (RuntimeArray*)L_1, L_2, L_3, NULL);
		return;
	}
}
// Method Definition Index: 70852
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_System_Collections_Generic_ICollectionU3CTU3E_get_IsReadOnly_m1DD27BB25B29255A180020923925DB9940DAC38D_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 70853
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_Remove_mB7617C1B280DAB2A7016677226C196E5949FADE8_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? ___0_item : &___0_item), SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		int32_t L_1;
		L_1 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		((  void (*) (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7));
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 70854
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_GetEnumerator_mBF312A19AD4C3692472CE306D658F430938583B4_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t80FD5046ECCBFF50D4CD855B7B13C05C89E66E69* L_0 = (Enumerator_t80FD5046ECCBFF50D4CD855B7B13C05C89E66E69*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 8));
		((  void (*) (Enumerator_t80FD5046ECCBFF50D4CD855B7B13C05C89E66E69*, ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 70855
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_System_Collections_IEnumerable_GetEnumerator_m4E322850074BCA8CB2E8D0C1808ED817B7B93BB3_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0;
		L_0 = ((  RuntimeObject* (*) (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 70856
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_System_Collections_IList_get_IsReadOnly_m6C804BF42FCE7C87AF830A9A03C82BCEE69F1D09_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 70857
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_System_Collections_IList_Add_mC315B1BD9975FCF36C943DB410E98807C5AB392A_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_value;
		((  void (*) (RuntimeObject*, String_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(L_0, _stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}
	try
	{
		RuntimeObject* L_1 = ___0_value;
		void* L_3 = UnBox_Any(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_2);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_3)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_3))));
		goto IL_0030;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0019;
		}
		throw e;
	}

CATCH_0019:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_4 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_5 = ___0_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		Exception_t* L_8;
		L_8 = Error_InvalidTypeException_m434387C9B5952F3087CD01FEA17199E22AADA89C(L_5, L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_8, method);
	}

IL_0030:
	{
		int32_t L_9;
		L_9 = ((  int32_t (*) (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_9, 1));
	}
}
// Method Definition Index: 70858
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_System_Collections_IList_Contains_mF83E9D29FF61AC04DCC314D055E19AC39A890E8D_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_3);
		bool L_5;
		L_5 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		return L_5;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 70859
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_System_Collections_IList_IndexOf_m4A3ECEF60E1D4A360157CC1E7A735C4653605490_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_3);
		int32_t L_5;
		L_5 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		return L_5;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 70860
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_IList_Insert_m1693E139C1F9660532D19331BE296B8DE5595946_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		((  void (*) (RuntimeObject*, String_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(L_0, _stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_3);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 17)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 17), __this, L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		goto IL_0031;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_001a;
		}
		throw e;
	}

CATCH_001a:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_6 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		Exception_t* L_9;
		L_9 = Error_InvalidTypeException_m434387C9B5952F3087CD01FEA17199E22AADA89C(L_6, L_8, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0031:
	{
		return;
	}
}
// Method Definition Index: 70861
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_System_Collections_IList_get_IsFixedSize_mCF189E78FF5AE932EB92B4FC4777BE4B54CBAD9E_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 70862
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_IList_Remove_m10A15392AD932A3DF41F607C342E6907933E5DB7_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_3);
		bool L_5;
		L_5 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 70863
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_System_Collections_IList_get_Item_mB304EB54646EA1127AEFFCDFD67D55A610CDFCA2_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19), __this, L_0, (Il2CppFullySharedGenericAny*)L_1);
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_1);
		return L_2;
	}
}
// Method Definition Index: 70864
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_IList_set_Item_m379F32349A5F51DD45C28A465938473136E309ED_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		((  void (*) (RuntimeObject*, String_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(L_0, _stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2), L_3);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20), __this, L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		goto IL_0031;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_001a;
		}
		throw e;
	}

CATCH_001a:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_6 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		Exception_t* L_9;
		L_9 = Error_InvalidTypeException_m434387C9B5952F3087CD01FEA17199E22AADA89C(L_6, L_8, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral46F273EF641E07D271D91E0DC24A4392582671F8)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0031:
	{
		return;
	}
}
// Method Definition Index: 70865
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_System_Collections_ICollection_CopyTo_m185ABD6F8F8392C5ABB1424AF35D4D93ACF596A5_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = il2cpp_codegen_array_get_rank(L_2);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0022;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0022:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = __this->____items;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7 = ___1_index;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, L_6, L_7, L_8, NULL);
		return;
	}
}
// Method Definition Index: 70866
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_System_Collections_ICollection_get_IsSynchronized_m82796367A13DDF90DA3D17C56AD1DB695B1772F2_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 70867
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollectionBuilder_1_System_Collections_ICollection_get_SyncRoot_m309394D8E2C1EE981D439DC1F2CC59BE2D134B6B_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (RuntimeObject*)__this;
	}
}
// Method Definition Index: 70868
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ReadOnlyCollectionBuilder_1_ToArray_m1802775EC669ACD2D1ECED4B18B0DF0339E7E0F3_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_0);
		V_0 = L_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = V_0;
		int32_t L_4 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_2, 0, (RuntimeArray*)L_3, 0, L_4, NULL);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = V_0;
		return L_5;
	}
}
// Method Definition Index: 70869
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8* ReadOnlyCollectionBuilder_1_ToReadOnlyCollection_m17809585AA08EEB82BDFD1E21857871DA5BA829A_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = __this->____items;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		if ((!(((uint32_t)L_0) == ((uint32_t)L_2))))
		{
			goto IL_0019;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		V_0 = L_3;
		goto IL_0020;
	}

IL_0019:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4;
		L_4 = ((  __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* (*) (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_4;
	}

IL_0020:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5;
		L_5 = ((  __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->____items = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_5);
		__this->____size = 0;
		int32_t L_6 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = V_0;
		TrueReadOnlyCollection_1_t75B148B212697F1795828F9E34F7984842ADFC03* L_8 = (TrueReadOnlyCollection_1_t75B148B212697F1795828F9E34F7984842ADFC03*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (TrueReadOnlyCollection_1_t75B148B212697F1795828F9E34F7984842ADFC03*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)))(L_8, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return (ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8*)L_8;
	}
}
// Method Definition Index: 70870
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_EnsureCapacity_mCEFA7FD2BC6D88F51D9E74DF54AFB780C39394E7_fshared (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_002e;
		}
	}
	{
		V_0 = 4;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0021;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
	}

IL_0021:
	{
		int32_t L_6 = V_0;
		int32_t L_7 = ___0_min;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		int32_t L_8 = ___0_min;
		V_0 = L_8;
	}

IL_0027:
	{
		int32_t L_9 = V_0;
		((  void (*) (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
	}

IL_002e:
	{
		return;
	}
}
// Method Definition Index: 70871
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollectionBuilder_1_IsCompatibleObject_m4182A9D16A594A96171C6B2500175BD08CD2BEF6_fshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	memset(V_0, 0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInst((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		il2cpp_codegen_memcpy(L_2, V_0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		bool L_3 = !il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_2);
		bool L_4 = L_3;
		return L_4;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 70872
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollectionBuilder_1_ValidateNullValue_m9A9AAC00AF379D1A4AC78A929F7E29A3A7C14681_fshared (RuntimeObject* ___0_value, String_t* ___1_argument, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	CHECKED_LOCAL(Type_t_StaticInit);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	memset(V_0, 0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
	{
		RuntimeObject* L_0 = ___0_value;
		if (L_0)
		{
			goto IL_0024;
		}
	}
	{
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		il2cpp_codegen_memcpy(L_1, V_0, SizeOf_T_tF7F5D54E165224B75F6839AD6F38D3E1EA213057);
		bool L_2 = il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_1);
		if (!L_2)
		{
			goto IL_0024;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5 = ___1_argument;
		Exception_t* L_6;
		L_6 = Error_InvalidNullValue_mD3F707613D9B6413719EB3549DAF5406FBD60199(L_4, L_5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0024:
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m685E33687041AE241CB9AF46CD74A0D14F29375B (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ReadOnlyCollection_1_get_Item_mEBD42AD012EFE7A1910937E713DD5AB722CD8613 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m884266F7C492DE4AFA45B5059E72AB8AADFE1701 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m7D73EAE96C93B4A7F580811D230BFA42CDB7DD8C (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m0D253BA6255C9D9234169280DF9CAF6D48FAAC09 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC11B95DC5BCB94CAE3AFA3D16E8D584D5611EC8F (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mC4FD28F6482257D37B5258CE74264CEFAB820369 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mEB9EB7095B23B44F8F14F21FA7D8676D1E1073C2 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m685E33687041AE241CB9AF46CD74A0D14F29375B(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_t2B402FF2AC2B32AA6CC9A5004046806319D243DC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_35;
			L_35 = InterfaceFuncInvoker1< DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mF91E576830715C1BC10E213A8335C4994E1122E7 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF6E466AF68CFEC8F47F7CF45C4133EF69DDF248A (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699));
		DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m2CDBC987328D0A4C7C3D53A94B8131CF425D985E (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF6E466AF68CFEC8F47F7CF45C4133EF69DDF248A(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m884266F7C492DE4AFA45B5059E72AB8AADFE1701(__this, ((*(DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mC4C000C4F111A8FDEE3D570C357DE04C07D2D409 (ReadOnlyCollection_1_tE1E1623260F50B25EF98DCA6C8483A3150D2228C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF6E466AF68CFEC8F47F7CF45C4133EF69DDF248A(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mC11B95DC5BCB94CAE3AFA3D16E8D584D5611EC8F(__this, ((*(DeferredArray_tB1EEA722CAEFADCA5DB101F288131BDB91341699*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m838B5E6314B03A3AB9923223BB4821D618210436 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ReadOnlyCollection_1_get_Item_m8CAFB900E919C9B368C965920C6B5C58F9949695 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m0977A268DF5A5540454EFACC58FF2C010A86CD3D (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m1F4E49EF3FBED0D0288BF21D013781F18FB4E17A (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m1395E9F514C380126D51E7FA4E9474225F2FABA7 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mFFF2618F4888C7AB1485B1076C10EFD688BC7AD2 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m4C5973BEFB28DBA8998AABDA851505227AA0DA67 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mC6C2C5FC384E2ECF64FE6804312783BC27FA8CDC (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m838B5E6314B03A3AB9923223BB4821D618210436(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_t3BD4EFCB3657D71410023E0F5130F15EF7A21B23*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_35;
			L_35 = InterfaceFuncInvoker1< DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m601B43E18FB1AF5EF577DAAB6550C10E8D8331E0 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2052E4178AF32DCCB3A36700D775691B7754B687 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F));
		DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m51360C5128C218815CE27E93C6A7A69A216AFEF0 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2052E4178AF32DCCB3A36700D775691B7754B687(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m0977A268DF5A5540454EFACC58FF2C010A86CD3D(__this, ((*(DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m5708D5712EE24BE80D248054FD6F8301E69D17C5 (ReadOnlyCollection_1_t2DA6C24CC896BEFD6DA7C7716A49F4D7560F3D39* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2052E4178AF32DCCB3A36700D775691B7754B687(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mFFF2618F4888C7AB1485B1076C10EFD688BC7AD2(__this, ((*(DeferredArray_t2BECE302ECB2543D3E0082C7F2B5721514E6270F*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0DA883888751E89AA69F98E60BAFF8FBABB38C60 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ReadOnlyCollection_1_get_Item_mA786D6BC2F8936DE572747C916650D835C00BCE5 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m4C16309031446534F4776B705DB4BF2FD0882362 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m81A9F797604A2D0EEE171DD90B8DFBDA3E340370 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m72C3B834A28953CE869BEC101AF1A288C3BE5A5C (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9244F5B1663BCC1829687A2C005146A449BE2A5E (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mCEF1E97A973E01B5C000F1E71A7DA5FDA8F8EDB0 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m05CD623643CE29D0D26B0F62BDBAB7721C5D4D4B (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m0DA883888751E89AA69F98E60BAFF8FBABB38C60(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_tB4ED071664EA73A4D56895411476AB8A983CBCF1*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_35;
			L_35 = InterfaceFuncInvoker1< DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m388110CD12D54BEB2C74C894C2A575E311088A8B (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE00C5E66D753E1071BE29CCFB9B1297D147ABF76 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819));
		DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m334AEF35B289E091477877AC2F76B598B154169E (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mE00C5E66D753E1071BE29CCFB9B1297D147ABF76(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m4C16309031446534F4776B705DB4BF2FD0882362(__this, ((*(DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m620ACC02A1074AFB1BD31E1CF7B6431874F75B15 (ReadOnlyCollection_1_t84E34036DE2DB092AE83E6D8D0CB44542ADBEAFC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mE00C5E66D753E1071BE29CCFB9B1297D147ABF76(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m9244F5B1663BCC1829687A2C005146A449BE2A5E(__this, ((*(DeferredArray_t550A0C1FE3282F51201CDCB03B920FD2C8F8A819*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m71745ADD92D415DAACD7C285EA848CBB6B673B9B (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ReadOnlyCollection_1_get_Item_mB754BA5BF5F34552D27F40F19A3BB2E0F3B27AD3 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD99308B65BA325981719086EA118A7F077305500 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mDBD20F0FF1559964656B864524BA8E7DAFCFCB30 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m7BE6729CCC0BF93184799A044DF675A326150280 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m27BE264B56B78111130857D7F1C06E5C73CAA860 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mCC6CD8BB5EC513A8113380F6D12C8F7C633FFC21 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m515E269D74EA46763E9E96B36B312C0787FAA47C (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m71745ADD92D415DAACD7C285EA848CBB6B673B9B(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< DeferredArrayU5BU5D_t6D635F4C80672BA27F457BDBCE514AD117AC2D74*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_35;
			L_35 = InterfaceFuncInvoker1< DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mB088507168ED4BB90C9EC67FFF5ABFE718DFCAE7 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_2;
		L_2 = InterfaceFuncInvoker1< DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFD9D85FA10DC0E3CD95A7B801591CCF2DFAFD142 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F));
		DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m2C31D03298CEF3B2D04953E1FF5FD128AA1C8561 (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFD9D85FA10DC0E3CD95A7B801591CCF2DFAFD142(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mD99308B65BA325981719086EA118A7F077305500(__this, ((*(DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m7D880370CB184D9E7AB9836A89A7304993849B2A (ReadOnlyCollection_1_tAF1348CE6C859AC048F871265928A0CA08BD98BF* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFD9D85FA10DC0E3CD95A7B801591CCF2DFAFD142(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m27BE264B56B78111130857D7F1C06E5C73CAA860(__this, ((*(DeferredArray_t021DC9D34F571CC415C56616800D2AB61451C85F*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mC0963FC6DD3F96602A2147E4A82AB5E3D0A374F1_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ReadOnlyCollection_1_get_Item_m87F5F983692A8F7F049C30AE576A64628825670F_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m998337273E514908027348F2AE19B89774318265_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mC4D1A9B38DD6E6B10741E7B0DF59EE090FA39CB0_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m5B2033EE008880BA5A245A6B729103756E779F95_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m1C8B6015B945A9698E7DFC6E25D174AE08D88435_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m601335E1CF6B2C0988EC5FE1A48DC8D7DDB95B09_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mB9B4509659E1A36B706CEED7321FD4BE55D9F5BE_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mC0963FC6DD3F96602A2147E4A82AB5E3D0A374F1(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_35;
			L_35 = InterfaceFuncInvoker1< KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mE56E8FCD14FE851402EF95B513F8D9DF6E32AEA5_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m06899F73FBFA0C918BAF26D47FE4BC69B0401960_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55));
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mD05E149EE4DF8A56D348CCDED2ACF113B53ACFE5_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m06899F73FBFA0C918BAF26D47FE4BC69B0401960(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m998337273E514908027348F2AE19B89774318265(__this, ((*(KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m4CCC493E6A5B8D261AADA518C7596BD47346F726_gshared (ReadOnlyCollection_1_tEE45B9D6F9D801AF392A14866B2D28D1AF43C83A* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m06899F73FBFA0C918BAF26D47FE4BC69B0401960(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m1C8B6015B945A9698E7DFC6E25D174AE08D88435(__this, ((*(KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mF7848E82A84A97D12EB2BEEE2C100A517E39F449_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ReadOnlyCollection_1_get_Item_m8EBAA067A588ACF7802304FB6AA88F25E07356D2_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3548041444A48A8090ECF81F9137AFE70B0BFC35_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mFD471BB206010974C8308AC24389D5082A1A4287_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m7AE1A0AC7A04FF70D69EC68268F0B91AB677E489_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2812D6D8A58856AF787AE4999E9C5F037CD707EA_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m267C2E51A46DE84EBEFE12B6C7E9163068629617_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m86F124F5B1975216679926E0793BD5A02ADD7221_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mF7848E82A84A97D12EB2BEEE2C100A517E39F449(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t8BE324D16F7949CCB61C579C5F4884F179B3F6FE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_35;
			L_35 = InterfaceFuncInvoker1< KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m5962EE16D9C8F00CC344BB614D84C9D8C8EA0CF9_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD8FA777AE0AB15400CFAE1A41A905CDB5D21A19C_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453));
		KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mC6F0BB7A7AA4AE15B47AA2B4809A5DCFB0D4A5CF_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mD8FA777AE0AB15400CFAE1A41A905CDB5D21A19C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m3548041444A48A8090ECF81F9137AFE70B0BFC35(__this, ((*(KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m14AE19C4D235ABC89823269E1589023A7846C822_gshared (ReadOnlyCollection_1_tF6196946DF2CE0FA25B82D5FACC665AC83D6A82E* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mD8FA777AE0AB15400CFAE1A41A905CDB5D21A19C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m2812D6D8A58856AF787AE4999E9C5F037CD707EA(__this, ((*(KeyValuePair_2_t69CD47690E0865123AE83CBCF76FBF5613F8F453*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6D64B6B073FD1CF4D831ECFE05E1623A75FB96F5_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ReadOnlyCollection_1_get_Item_m699F4E359994D43B4AF96E2FAA62A70857530D81_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m75BDDF78FE058AD7B469434093D7A0D2998E10E7_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m1B53997C8C69807F47715D86807228C2282C3697_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mDE1687BE6271CC75BB3A350B38C03247D01C2C11_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m28F2D0F0B3F893D1802E4D7B17256C66AEC58BBF_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m26664E9B626FC28267B29D0D4F0E0B5CF8DB4AE8_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mFB95CB86294DD42764F0657553E8C24820CE3419_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m6D64B6B073FD1CF4D831ECFE05E1623A75FB96F5(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t78D9368B607748564E2110C38FC6FCC5150E8DDA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_35;
			L_35 = InterfaceFuncInvoker1< KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mDCB0392C5C992720147FE1271F01165F95797ED7_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8716C838CA177C8AB0EA887D0B855BBD3B876695_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826));
		KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m37AA89FB0E29F2749B11285B444202DF12D23911_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m8716C838CA177C8AB0EA887D0B855BBD3B876695(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m75BDDF78FE058AD7B469434093D7A0D2998E10E7(__this, ((*(KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mAB1789BCF86DD593737EC27484609F4E74AEDCEF_gshared (ReadOnlyCollection_1_t6BC2DCBE8EB131D79FE145A3861C3786E17D3CA5* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m8716C838CA177C8AB0EA887D0B855BBD3B876695(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m28F2D0F0B3F893D1802E4D7B17256C66AEC58BBF(__this, ((*(KeyValuePair_2_tEB5CFC17B6D8F2A082613AF75FCB091A2A4EB826*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m37C1965F27A1810D3AAA1331497EFA1D51A975A1_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ReadOnlyCollection_1_get_Item_m1D0BE9DD9F6C77C6AB76BF592BB737749FDA8AC1_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m1275764B723E3599AF2891F21C8F96CE3635C4BA_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m717D98DD8D89C38BB3B062FAB6042B71EDCB285B_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m7EDC6397DE4B5BC948E9D0436DBAC2DF12F8DDCF_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mBD2424B8EBC3D9058E16CED4581527606F63F012_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mB5FD6B3B424CC0C17ADEBBBA89AE0D927694F563_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m8BEAB0128E74A40FF762A5E0B5590BA400D59912_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m37C1965F27A1810D3AAA1331497EFA1D51A975A1(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t899E6C9DD89ED99CCF993FA90A368CCB9286EC61*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_35;
			L_35 = InterfaceFuncInvoker1< KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mDCF9C33B69A77558A9CAB9A1CD892E89B2BCC2A3_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_2;
		L_2 = InterfaceFuncInvoker1< KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m601594B931ACDA13FE772739FA4D3CEDB95165A8_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764));
		KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m300770270DE8D5C24F54682E5266AFDED21FC62A_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m601594B931ACDA13FE772739FA4D3CEDB95165A8(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m1275764B723E3599AF2891F21C8F96CE3635C4BA(__this, ((*(KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m5373FE061713574B8537102BC74485EB07A10750_gshared (ReadOnlyCollection_1_tBD4CCEBC45FD27F930F251750EDEF0FE0F9067F4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m601594B931ACDA13FE772739FA4D3CEDB95165A8(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mBD2424B8EBC3D9058E16CED4581527606F63F012(__this, ((*(KeyValuePair_2_tBACD60E472B89AFFBC34B7B0D1E260E20392A764*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8A97077239C70BE9C9375F2127C82F3C283E81A3 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ReadOnlyCollection_1_get_Item_m40C106B8CA3870D1798C7C834AFE5C3270650ABC (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mBE15981470D788343F71D108AD20D6B88C99B199 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m960E93D04F7BB4C3196EDABBF8269A2CC2DC6067 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m7CD2E917812626CEAE332A9FDF4B6DB1A4539E1D (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD789D84F5F7E12E4F6F6C7659ECB705958FE8531 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m93ECE25F91F8E3EC14960A6B5A768181AEFF2EBB (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mABABF6012465B12EA33B1AFF2A77B1DD4BDE1DC7 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m8A97077239C70BE9C9375F2127C82F3C283E81A3(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_tA4169A0FB467A7CC805A274BAA933F0DAE293522*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_35;
			L_35 = InterfaceFuncInvoker1< NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mE4FB5677A2AFD228A37989BF6D810AFC864322AC (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF7AA90D7AC9126E9396188FEADDDAE16BD698924 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C));
		NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mEF70EF82062C13A6FD3594CC5AC18DDFDE31DF20 (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF7AA90D7AC9126E9396188FEADDDAE16BD698924(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mBE15981470D788343F71D108AD20D6B88C99B199(__this, ((*(NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mE09E978D305CC389B3B37EBDCFA98D9CB57BE80E (ReadOnlyCollection_1_tB76E98FC73705D2AC28EA90D4EC4CB91CAEDD46F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF7AA90D7AC9126E9396188FEADDDAE16BD698924(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mD789D84F5F7E12E4F6F6C7659ECB705958FE8531(__this, ((*(NativeArray_1_t1E4E343391EE676E3EE93E992C0AE9BDDD5E5C4C*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mAB482F95F7DAD8E45AEFC9D68113DC67B5A5FF18 (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ReadOnlyCollection_1_get_Item_m6378D284A2C1CAE78DC5C88EC20B4D3B7ED437BD (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91996AFFF42C95AF18381233760D0FE8FB91D9CF (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m30009E15C56609BB3886702EDAC955B538B24AC1 (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m9883C977AD4FFE8FB4773CAB9490760F7664556D (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m880B9A3177AA9FABE2C74EAAE1C697D1A6FB344A (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mEF16766FE21DBE5CFF25786E3575AD393FCD77BC (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mDC1A59CE4F6A75E2AC41DCBF7F34B84D58BD0091 (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mAB482F95F7DAD8E45AEFC9D68113DC67B5A5FF18(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_t75698E5C2142DD4A324DD38EE484D69C8FD2CFD3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_35;
			L_35 = InterfaceFuncInvoker1< NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mA39FA944285BA334E2F6A3B769A757AA100E3F66 (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m182F39AC5FB4735C49EE66373D712B20B3FF5FA2 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3));
		NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m1EDC4EA609E713EC60FF5EDC0CFC354413B57E8F (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m182F39AC5FB4735C49EE66373D712B20B3FF5FA2(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m91996AFFF42C95AF18381233760D0FE8FB91D9CF(__this, ((*(NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mA2D6E1694EE93ADFBB5650306D5712A4A2FD2B03 (ReadOnlyCollection_1_t0D56A0B09546E9F141C635D6C4F759EE9A3B9878* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m182F39AC5FB4735C49EE66373D712B20B3FF5FA2(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m880B9A3177AA9FABE2C74EAAE1C697D1A6FB344A(__this, ((*(NativeArray_1_tF9AAF96E0048E8B93F277A9EAD3955253C6B34C3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mD6A2DD10645C3C99E93B0A5D35C167ED7BA3B2B9 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ReadOnlyCollection_1_get_Item_m96801DE441E269D45A75087F608AF91FB487EA18 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m4CAC8D293E40FB4526D9C23196EACF849F429379 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m679FCB6BEC2AAC001DFBFA4AF239BB66D2D82D21 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m2F2BA77D96D20FB4CBD93C22136C8C56BE238584 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5550CBD835D9F269CB5920858A48CE8147947A92 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mC03772647AF92C4CD78B8F95BC64A1BE2CBA1C07 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mF5686907C679E6E3CAC0BF3104C6A6473556C690 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mD6A2DD10645C3C99E93B0A5D35C167ED7BA3B2B9(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_t48F28BC4076C1A1608AA864367077AD64E04C11D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_35;
			L_35 = InterfaceFuncInvoker1< NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mDA1A6C37432F5641C6926B4A6972390FF48BAA15 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mB6E515FF09DE1EE6B9C37CFC896EE7F4CA113045 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD));
		NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m37C1E821DE130C84F7370F46B0556F4E04E3DC87 (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mB6E515FF09DE1EE6B9C37CFC896EE7F4CA113045(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m4CAC8D293E40FB4526D9C23196EACF849F429379(__this, ((*(NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m14D01AA220BAF27401A450B5B7CCF43A26E0EFBA (ReadOnlyCollection_1_tD8E444758C2B4F97F35F47C75733B6B72311798F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mB6E515FF09DE1EE6B9C37CFC896EE7F4CA113045(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m5550CBD835D9F269CB5920858A48CE8147947A92(__this, ((*(NativeArray_1_tDCB166A7D351D6EEDCDE6CB91075388DEEA5E3CD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m16D553F92458225BB8CE5B325E381F38E84F3A3F (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ReadOnlyCollection_1_get_Item_mCE9D95F37D96010E1E46A31C8FECBCA8E79EC6C7 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC8653C9B3196644FFCCDE9279DFC1E25D1DB6D89 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m1E1E07B120AB90D255A0C501A62DADD3739EA902 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m87F86036E138932A24D2687522A2AB87101FA042 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5C407CE31DA6DAB79055A3C67C72D7674F358E03 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m2D45F8000A19EC8AF63395A32FD9B047A017A0C1 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mD8FD01CFDD7266E6AEF7245A79605548E0562BEF (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m16D553F92458225BB8CE5B325E381F38E84F3A3F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeArray_1U5BU5D_tB9179B8E492F9CEBC40651BF1C66A50255128C61*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_35;
			L_35 = InterfaceFuncInvoker1< NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mF8DDB9E747245460D291D3930506F9BDBCF99D1A (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_2;
		L_2 = InterfaceFuncInvoker1< NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m24AE4FAC7DBAB5FE4C92AEE7F9E04E80D5C7FF98 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57));
		NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mAE621D1D14DA22580F6A2353D90BB95CD4E0C923 (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m24AE4FAC7DBAB5FE4C92AEE7F9E04E80D5C7FF98(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mC8653C9B3196644FFCCDE9279DFC1E25D1DB6D89(__this, ((*(NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m0302DDB48E3868DCA5AB21AD4A5381CD0B74B56C (ReadOnlyCollection_1_tC6B1FE82DA5F2D752FD7AAF8B3602A6A7B8296AE* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m24AE4FAC7DBAB5FE4C92AEE7F9E04E80D5C7FF98(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m5C407CE31DA6DAB79055A3C67C72D7674F358E03(__this, ((*(NativeArray_1_tA250DFA6F2B09B543458A4231692763973E84C57*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m479FD11AA0603AE8828762261714E8C366F349C6 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ReadOnlyCollection_1_get_Item_mE11CB36C60A306CA314AF5076F5DBADF401FC0A2 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91A164D681D8812A4148D2561B6ECEC02CD61C49 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mC695D4779A3EC8046EC93798A513DF8536F6DC93 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mC8953A5D07AC0F33DF2C93C3F8C5D12735CC6BAD (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m71CEFBE6F99A20BB57961EC3A8455CA7919F7150 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m48BAE7AC5C032B8D3CEB679253700DA126D138E3 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mD3A2FA2E5A84975F5BC3D79DF4D2BF656B288926 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m479FD11AA0603AE8828762261714E8C366F349C6(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_tA2658F536BAB96D3A40A226CE9FCC90F25ADC8FA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_35;
			L_35 = InterfaceFuncInvoker1< NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m977FF595D501F322FCADBBB1293DEE4D7CD58C33 (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m7221B30E09E70A275D9F6D234544A9F037EC0E3D (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C));
		NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m0785994BFB96319A5771EC70372EBFBA360A8C5E (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m7221B30E09E70A275D9F6D234544A9F037EC0E3D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m91A164D681D8812A4148D2561B6ECEC02CD61C49(__this, ((*(NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mADAD08167D06FAB10CB355969184859FAAF4ADCD (ReadOnlyCollection_1_t24841FDB9600CDE25CF2E865408C4CD8652BF7F7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m7221B30E09E70A275D9F6D234544A9F037EC0E3D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m71CEFBE6F99A20BB57961EC3A8455CA7919F7150(__this, ((*(NativeSlice_1_tD082749657486F7547D4E8EBD2FFB858BA6CD98C*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m90E7B655CC2C12EC37423A97EBB21DB1680BE06B (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ReadOnlyCollection_1_get_Item_mA05837108CB33750F6B5C5AE7D13B6145AA55120 (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF127107360D2211BEFC85AAEE36D96F6408B065E (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mB8CBD5A8E8742BF5A1EFE82BCFD90E042A9E03D3 (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mDA2F489CF5F8FE67D5AA81B0DC52187A4CBF5752 (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9229451605652B5DB71F8B8FE73569DEFFA6094D (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m641422859776F5EA559056B8C5750AF25E7ED765 (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m137B18DDE22D6A70183597CF66B5736DA1075FAD (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m90E7B655CC2C12EC37423A97EBB21DB1680BE06B(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t4AA4AF19AB9FDDBD4CC8C6F7E4A9C6AC063C09FD*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_35;
			L_35 = InterfaceFuncInvoker1< NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m6F840C831B3F27397220011291F9E6AF1A690163 (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFDF4573C72E27A48C6A8BAE4DFE0C5EBD25CCA98 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B));
		NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mAF552CE56ECCC77337E4F05B992335F06DCCF03E (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFDF4573C72E27A48C6A8BAE4DFE0C5EBD25CCA98(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mF127107360D2211BEFC85AAEE36D96F6408B065E(__this, ((*(NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m3D593C1923C6E384DA1E7ACB0C124FF489BE5288 (ReadOnlyCollection_1_tCDCE8AA9C0E38704960C02BBBFE7EE9BA3CE89E3* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFDF4573C72E27A48C6A8BAE4DFE0C5EBD25CCA98(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m9229451605652B5DB71F8B8FE73569DEFFA6094D(__this, ((*(NativeSlice_1_t1108006793B0D86DFCF2E4481CD5E5E32AFF591B*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m1F139D4AE644DB044C847F0F70224AD21C6F70FB (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ReadOnlyCollection_1_get_Item_m1318850CDCF8CC85F56D5F09F278979ACBBECDEC (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3EDD912161578F48F5E76C01D7C19F8F98B5617E (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m25B83A58F3A457AEE51B4BA0AFF8FA92F561D610 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mB4707B2043FE679D41D7BB9DEF9159BBC7CB5F78 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB9392399119A83D55E96CED8494B18D93A4B5899 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m5ED9DF363E9F8622699FEACF05306DD24A778F63 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m044B33936BF08E42AF5A6ADEA30CD1D8399AB1E7 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m1F139D4AE644DB044C847F0F70224AD21C6F70FB(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_tDC36ACB61BCAC1B7A036318D24BE1BCB309EC376*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_35;
			L_35 = InterfaceFuncInvoker1< NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m0A33EA2BCDCE6C77CAD293FBE71119B91085B53D (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m17BEF3D58FBEC0BEF9235AE0049F72FD06EFC57F (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0));
		NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mBA2D21B6E7D37D20AFA09D792725BDDF9E40C3EF (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m17BEF3D58FBEC0BEF9235AE0049F72FD06EFC57F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m3EDD912161578F48F5E76C01D7C19F8F98B5617E(__this, ((*(NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m979576AFB61AB8491901F3A0EE011AEC986E79B4 (ReadOnlyCollection_1_tCC07111583221315005E4E1E874F689440FA7178* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m17BEF3D58FBEC0BEF9235AE0049F72FD06EFC57F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mB9392399119A83D55E96CED8494B18D93A4B5899(__this, ((*(NativeSlice_1_t84638F9F5F454538786C27E8F639E0B602DB00D0*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m1E0EFF605A7C6AFE538C0AA18CC455215DF08677 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ReadOnlyCollection_1_get_Item_m10575B299C797BD100EE5C1525C70A9BC5321EC2 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m2506B3215547F42B9D6E73C07F394B8CCC14EDA2 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m991ECEAE7FEE19276416507DDFFF0FB8F4204D8F (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mEF780551B85AB70B29F595BD65E11B021926C360 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m774093B34CAD7C830556A1CD6D842A18A7A9FDF8 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m7D6B6450820056C6300A8F66EC2441C693F136DF (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mFFBC3EBB0A18030C00B3500D1F35C7CC20607210 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m1E0EFF605A7C6AFE538C0AA18CC455215DF08677(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t2F30D5283C1DFCDDB22E354B120151CB6D5E2320*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_35;
			L_35 = InterfaceFuncInvoker1< NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m789A3DC6A217D81D208DC156D588CDBAB8E0042A (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE45427E8FB79B15653D9795E67A727F7532F235B (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A));
		NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m766DC97577D1930C104C8EBD6CE2CDDD4B7BD291 (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mE45427E8FB79B15653D9795E67A727F7532F235B(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m2506B3215547F42B9D6E73C07F394B8CCC14EDA2(__this, ((*(NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m2D61D7172348611A445AD8C213C5A7FEF28A68CA (ReadOnlyCollection_1_t2245CEADA11E6FEBA5175FE80F72F1EC6303D794* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mE45427E8FB79B15653D9795E67A727F7532F235B(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m774093B34CAD7C830556A1CD6D842A18A7A9FDF8(__this, ((*(NativeSlice_1_t0D1A1AB7A9C4768B84EB7420D04A90920533C78A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m3BA31B14BBC7A97723D334EE4916E6B9CE7AE4AB (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ReadOnlyCollection_1_get_Item_mF78823A75F543FE39BE1593416C0013AD071BE6C (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m21357843C08DD018321DEC0F827058249C12FFE6 (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mFBC2E9DC627A03E8F0E965C122E976E28229DC2F (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mEF90514140DBDDDFE77E5021C0D147306ED6BB71 (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mF638FA3440A3F8803CF8FD7C4E6C5165141DE67D (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m628186FB98277E9FBA92D00842DC0FA6A86979D5 (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mCF6665363CC40972B252CCE71978589447B93377 (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m3BA31B14BBC7A97723D334EE4916E6B9CE7AE4AB(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t16C12F471D23F4C960D0CF0233390A24D85676C1*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_35;
			L_35 = InterfaceFuncInvoker1< NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m64D191F1D2A211C759CCED2332797EA94BA2B3BD (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mB69CBF81CE741C05119502E3BBE6A16168167183 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2));
		NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m9543660DCDFAA6DEEC62027270D66C4AED4C601F (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mB69CBF81CE741C05119502E3BBE6A16168167183(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m21357843C08DD018321DEC0F827058249C12FFE6(__this, ((*(NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m76A8C6D3EEBF108D1B1919882C34D4AADB22B7A7 (ReadOnlyCollection_1_t86BCA7134ABD8077F6D16A9EA271254CDCB49261* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mB69CBF81CE741C05119502E3BBE6A16168167183(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mF638FA3440A3F8803CF8FD7C4E6C5165141DE67D(__this, ((*(NativeSlice_1_t66375568C4FF313931F4D2F646D64FE6A406BAD2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mB0E24DAF8C568571332AF177303189F62090F44D (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ReadOnlyCollection_1_get_Item_mBBBF373AC58DD2DA8A48EF192BF687AAC6DF5C78 (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3E4CA572BF4E2858AABCCDEA7E1B9639139ED95D (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mFE07C0A91E708F5E8E4323335D8D5C2344F75C53 (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m44BC1D4D03915497823C0805B569F9B765394BDB (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m65881C5133BEFF21657BE17CDA6B0D53F0C1A069 (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m791E0FBB3BC9AF94DDA390EF804242E725006AE5 (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m9249CF82D55A3C4E968238CEF40F9365D207D8DA (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mB0E24DAF8C568571332AF177303189F62090F44D(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< NativeSlice_1U5BU5D_t010FDB7575A78BB3EB09D1D008F9835266FF7623*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_35;
			L_35 = InterfaceFuncInvoker1< NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mB3CE7F90C7D52939223AD6540F7AD3F29A54552B (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_2;
		L_2 = InterfaceFuncInvoker1< NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m188B55BB38B193FE525D0168DD93F727B284303C (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9));
		NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m698C083A44C7BC5E48DF63A43E1EB71F19275C2D (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m188B55BB38B193FE525D0168DD93F727B284303C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m3E4CA572BF4E2858AABCCDEA7E1B9639139ED95D(__this, ((*(NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mE3FE1C29590A8F2D80BADBA94437162995213426 (ReadOnlyCollection_1_tDAF439ECFF6B5073A5E3A78B62C04D6235A0E86D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m188B55BB38B193FE525D0168DD93F727B284303C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m65881C5133BEFF21657BE17CDA6B0D53F0C1A069(__this, ((*(NativeSlice_1_t8E27FA1E73FC8A04E990C238360882D58A2DB2F9*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m813EBFE05B405D460C626549A2B1C08B46AF26DB_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ReadOnlyCollection_1_get_Item_mB4E0AACE1E224C9BA1381224138C5B79D4748E9A_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_2;
		L_2 = InterfaceFuncInvoker1< StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF30016445EF74DDD420AF1ADE0DEB973FCC37DA2_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m8FCCDEB79256E8B730A748883C826E9CFAE19AAE_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m0FD5C8437326127128CB67B35A3F00B969953C41_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD1E73B41F1D7A726922A535E3AC85C4570EA465D_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m34FE78412A6FA77B1A03DBEF7A1DDA06FDE8FCAB_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_2;
		L_2 = InterfaceFuncInvoker1< StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mFC78E0E876A756776A67A7E4338476061B403BE0_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m813EBFE05B405D460C626549A2B1C08B46AF26DB(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< StructMultiKey_2U5BU5D_tA56341715009B7858EEBA042587F979F0AD96164*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_35;
			L_35 = InterfaceFuncInvoker1< StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m3625E12ABCC89EB78C375AFEC569A448D2D8B761_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_2;
		L_2 = InterfaceFuncInvoker1< StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m00E361BD734D56DCB64859EFC32906149A15CAA4_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328));
		StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m04E1E0F7BCF65A8A6DE2F7D8773D36E0CC3AF66E_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m00E361BD734D56DCB64859EFC32906149A15CAA4(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mF30016445EF74DDD420AF1ADE0DEB973FCC37DA2(__this, ((*(StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mFD2C653232DEAFF3C8C612878F4987EF1B84D21F_gshared (ReadOnlyCollection_1_t63526E4478CB766D21E269CE216293C74EE536DE* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m00E361BD734D56DCB64859EFC32906149A15CAA4(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mD1E73B41F1D7A726922A535E3AC85C4570EA465D(__this, ((*(StructMultiKey_2_t5D4B566D2815511893ECD555824F93E19E448328*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m22CBB31C2006C251E77F8CC2DB25A12D03D5BD01 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ReadOnlyCollection_1_get_Item_m90BBC978A1C5613DDCF356DD31643FA73A6FCE95 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB424DEE3614BE559019564915A0EA182D174E1D8 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m68D7F8593EC46ACB7CB9C26EDAA3083AEA5D6171 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m826DE7409E563FF0C2CAF12EDDD0CABC08007740 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC64BC7655EDC71AE828DA48A855B7B11FAD88E1A (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m3C79E44FFDF14A7BCB61FEE2C2051A06E6E299AD (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m8D2C82C528E77F6DA4849FE78A87AD9800E0B2A6 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m22CBB31C2006C251E77F8CC2DB25A12D03D5BD01(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tDF72D915A7D87E646152784F08D18AB2CB4F5EEB*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mA969EC4A1F65069B5AB448E03F3538BA632D1C32 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAF4CA48061578EA8B528540FAD8A11B4C7AEDC23 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7));
		ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m081B5EEF0A7D5A7A274D0863E8D24C64314C1552 (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAF4CA48061578EA8B528540FAD8A11B4C7AEDC23(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mB424DEE3614BE559019564915A0EA182D174E1D8(__this, ((*(ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m0A0B9BE4E87B92DEFAB1B8878B6A86D77A79785E (ReadOnlyCollection_1_t9ABA2F249E47094B62BA5E3B8A43A57048FB9FBB* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAF4CA48061578EA8B528540FAD8A11B4C7AEDC23(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mC64BC7655EDC71AE828DA48A855B7B11FAD88E1A(__this, ((*(ValueTuple_2_t2213E297C2566AA4A7DCFBBE72C1DD9A274C79F7*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m85793655936FB0984A1437FA8ECE7C861B160646_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ReadOnlyCollection_1_get_Item_mDE3C7F298106AE6A51765BB31FC9D69F734F29D9_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m8EB998278F51347C4335B03C22BFB855F9DC51F0_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m09088598B777692F2A518C85E3C18AA03ED7D9B7_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mCFED9347F7E40DA70D49430DD1584A30E1C7DDAA_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m12554E59854370E4B6082003EABA5DA03A3B680A_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m294CF8DE679784D7E44F361A3E16C4D7A6B8A5CC_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m08B6D33B0D72C2D3E2BE7F6BDBC6E1F48F30A484_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m85793655936FB0984A1437FA8ECE7C861B160646(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t565D3943BB9F0476E2027F363DCCC0CC4C71C700*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m99B58C528D94F11BFCEBD2B4CCCCB7389DDADFA1_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m37AF7A81489AFACD3B812FF86BF68E379082C395_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD));
		ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mD1E80647A63CC5F166F9323BDF9F7D1542B00388_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m37AF7A81489AFACD3B812FF86BF68E379082C395(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m8EB998278F51347C4335B03C22BFB855F9DC51F0(__this, ((*(ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m1A9A0CF940A5C282F45FDE614A7C26E1C8F89A72_gshared (ReadOnlyCollection_1_t4B91063AF8C62FE6B1445065C5081099403D99D9* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m37AF7A81489AFACD3B812FF86BF68E379082C395(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m12554E59854370E4B6082003EABA5DA03A3B680A(__this, ((*(ValueTuple_2_tE3CBF4947E2EEAEB4DC6C2F7877FFDA4AFCF3FAD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m441E8A559A937B2AA5BFBB1EC47DB85C7D41FB30 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ReadOnlyCollection_1_get_Item_mA0F20E04ECF93557D70948F9270F07242EA00655 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD7B1ABB0F30B168A850EE84B657E2691ADE472D1 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m80472FB8A6E31ED4485EAF2D86915226E82903BE (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m0B51E38E6A5670CF81B3AAA33B8AC0FB729D6FBE (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m020859FBB1F4F960CF018EE5ABFE2D4CF402EDB1 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m865725C60D1C92BE0C85D12478FDDD18DE85EB14 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m6E8C0B4AD3607CFF53AE24810B2498B4D3E7C998 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m441E8A559A937B2AA5BFBB1EC47DB85C7D41FB30(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t94F4FA2E89C57493E80D51EADC9801AB9656DF6E*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m1CC1566D7AB7D08A39BD99E7E1E0D8F27544FEC2 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0679C85B7420BD4BE52693726F3A0013CE0CFD86 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67));
		ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m06111CD1EFFA641B866F7936F9E22F9574C290F4 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0679C85B7420BD4BE52693726F3A0013CE0CFD86(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mD7B1ABB0F30B168A850EE84B657E2691ADE472D1(__this, ((*(ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mCB53D4F3AF9177C7E88AF9E896C3F70FBD2EB399 (ReadOnlyCollection_1_t4284485828F2833F95EE330C4692595BDC27CD17* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0679C85B7420BD4BE52693726F3A0013CE0CFD86(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m020859FBB1F4F960CF018EE5ABFE2D4CF402EDB1(__this, ((*(ValueTuple_2_t441643900DE75EDC780AF50BC751CFA37BAA7C67*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
// Method Definition Index: 11027
// Method Definition Index: 11028
// Method Definition Index: 11029
// Method Definition Index: 11030
// Method Definition Index: 11031
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
// Method Definition Index: 11052
// Method Definition Index: 11053
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mAC01605A25EA01A4162FCE81666FB6171F97F73F_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ReadOnlyCollection_1_get_Item_m856A105BE7A5AB3C2741BD2D84D8E082D3EAB396_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6FDC3360288048A079D7BC0765A793E2D58C8382_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mF68171103936F5C524E70C27471B719DC8A80C80_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m8616BF06A6F25032EFBB4B752285A1947A7F0ACB_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m5C2C3C21DB3D20012826C34FDA5F9E30F535B4EA_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m0924FDC5B65CDF67D7FE853CAC02A732F3B22860_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mC8A247150197644A132D861B0DA55ADF4E587852_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mAC01605A25EA01A4162FCE81666FB6171F97F73F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t5A7297970D64653C5F0088EAAD4B926069F3A46C*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m329E0561DAD14EAED656B811FFA700CBFD3D58F3_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2B0739599199C6A9CA68E76243B82FC95AFE51D1_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3));
		ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mC638A45E5277967C0D82F5B61C44719652F048B1_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2B0739599199C6A9CA68E76243B82FC95AFE51D1(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m6FDC3360288048A079D7BC0765A793E2D58C8382(__this, ((*(ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mB526B7BFD93D3BFFF18E02916CDE50F1FF60C9EF_gshared (ReadOnlyCollection_1_t2339C350198EF9D7052178172CCB934B163D1FD7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2B0739599199C6A9CA68E76243B82FC95AFE51D1(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m5C2C3C21DB3D20012826C34FDA5F9E30F535B4EA(__this, ((*(ValueTuple_2_t0F8FDE8D64168388D40D48A8E5CD6AD3003B43E3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6759710C359F915427FA51E39C33D643F6BAC85F_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ReadOnlyCollection_1_get_Item_m307C05511E2808F88C24AC41A14147C053206AF6_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9FCF331B6C2A5F3A5ECC3945D34D5D0814BB37A1_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mF427749851083F2190560A10C3233FD0A5997285_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m11A26C537B6C97144BB175F10D0DD87E74342E7A_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD2FB104B201A6DE074BE32296004577183D14894_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m21C0B3617677B7F92B32D5BC40FD12FE5E8415CB_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m9A6FC62CDA81F0229FE4956A4444C8BC04636100_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m6759710C359F915427FA51E39C33D643F6BAC85F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tD58EF90589DE83B320BC017FAAA8BE18644946BB*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m14946D90CE124B294990503EE34CAA26CCB99CC6_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2EB896A15558B789AE100FB4897DC14AA432461B_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8));
		ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m04C7F7C5EDCC7DFE5E09C8968E4EF15FC964F48F_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2EB896A15558B789AE100FB4897DC14AA432461B(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m9FCF331B6C2A5F3A5ECC3945D34D5D0814BB37A1(__this, ((*(ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m65FC51275C3E984C8FBFF2F1F49592EA6ABA881F_gshared (ReadOnlyCollection_1_t5D1A90B4ECB04F85E4541F4133BA2262BC5D74E7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2EB896A15558B789AE100FB4897DC14AA432461B(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mD2FB104B201A6DE074BE32296004577183D14894(__this, ((*(ValueTuple_2_t608D7FAF3B041070486F5AD5D28444C28295C8D8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6337979AD706638A60D4AFA07D502AE6FF632E2B_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ReadOnlyCollection_1_get_Item_m6608863B5CF08ABD84249158D661A8AF7E54A8AF_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m458363841FB434CC5EF70D2D94CC5118F3120EF3_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m44865EBE8CBB12A638AE9A408535E7A1DF2BB9C3_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m044603BDAD095C96A9D4A106EE274C7C4280D748_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9165843F35CE2EC52317581AF71C7430C75EA8C6_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mB32BF5C1AB699633291D8ADA6625C1C1F67FCABD_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m0D485E3BB2BDCE1B698D5135D87CDBDA0C14CD0A_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m6337979AD706638A60D4AFA07D502AE6FF632E2B(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t14B49D3FEF67CBC376374065CA30D764F833ED30*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mB33282CBB8F5165ABAC944F925F201134E834C98_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m33945B9FF3F43E48AF59D3668CAFC751AAD0104A_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A));
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m432EB95471BA28625364D9DBA0C56B8791B1741D_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m33945B9FF3F43E48AF59D3668CAFC751AAD0104A(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m458363841FB434CC5EF70D2D94CC5118F3120EF3(__this, ((*(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mC2018C0C13E71F6FCA32DA87C841A1EEA3B72A21_gshared (ReadOnlyCollection_1_t85FC3E58ED27CDEF69A7E892FC2BCAD6FCAF5B2F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m33945B9FF3F43E48AF59D3668CAFC751AAD0104A(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m9165843F35CE2EC52317581AF71C7430C75EA8C6(__this, ((*(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m7FAF007DE7EE5211977590CB5AB494F2B7F30880_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ReadOnlyCollection_1_get_Item_m8E114FFE63C5D190FF9E98EA3056EF5BC6CCFC15_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m1574622B122C5C819CDF2B52F913B7F029E1A8AE_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m9523CF0041C1556F1F80AAAC5B6FF057A82030D4_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m37D2F215D712FA98142B01BE440F719CFE737D8F_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE1D3AF35A8338D68A1D96381AFF9AF8494C6E6AA_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m0331FDE62906634A34ED8A17B42750423822EA3D_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mDE40F6E2D332B788C1CF8BC7AC171DF70AC93ACB_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m7FAF007DE7EE5211977590CB5AB494F2B7F30880(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_t8FBCDB97DBD335F8EA00F11B435C6FB7BD88DC19*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m9CF10953B4220BE7818E72E872A0C4E8E6DFB0E3_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m6CBCF4F8E88F394DC8D0C83A34A273EB4711DFAD_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A));
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mCE2FE4D0AC5F84252DD2DFC8D353ADE0A63787D3_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m6CBCF4F8E88F394DC8D0C83A34A273EB4711DFAD(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m1574622B122C5C819CDF2B52F913B7F029E1A8AE(__this, ((*(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m56C6BAD70A7502D0437A16676A4CC0840FCF0423_gshared (ReadOnlyCollection_1_tB195E9BFD1BCE4CABD5A32410E6D7F40DA61C87D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m6CBCF4F8E88F394DC8D0C83A34A273EB4711DFAD(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mE1D3AF35A8338D68A1D96381AFF9AF8494C6E6AA(__this, ((*(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
// Method Definition Index: 11027
// Method Definition Index: 11028
// Method Definition Index: 11029
// Method Definition Index: 11030
// Method Definition Index: 11031
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
// Method Definition Index: 11052
// Method Definition Index: 11053
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
// Method Definition Index: 11027
// Method Definition Index: 11028
// Method Definition Index: 11029
// Method Definition Index: 11030
// Method Definition Index: 11031
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
// Method Definition Index: 11052
// Method Definition Index: 11053
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mBAA33C444E3938A042923D39724E03326EE8B24A_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ReadOnlyCollection_1_get_Item_mDF7A451DA16026009C682DA61D05295CA6A526B8_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m827FFBAD02BB6E948B151CF1B7FF3FBA94103463_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m903238EEA64657911E9D7B06B03F933FB05F9B16_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m22E9157F78A39E86A09F39276196732F122133BF_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mABEA50A98CFC875525107305139F54234862B41C_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mF813ECE9BECD7FFC71E8F007444817A9119A9D1E_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m489AC29A4485A71DDDEA796F51FC1609D5A84F7F_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mBAA33C444E3938A042923D39724E03326EE8B24A(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tA00E3E3F73FBC47A5F640D4A0E80AC0D1725BD9E*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m659FEFC797895BBBD26F934A9047C9C38751B17D_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF27356D302C16DB6F6D0050D55AF437BBF77EDE5_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE));
		ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m11AED20D69E2A49B4BB578D8B46B0597BBEAB4A6_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF27356D302C16DB6F6D0050D55AF437BBF77EDE5(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m827FFBAD02BB6E948B151CF1B7FF3FBA94103463(__this, ((*(ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m2871ECE69C20CBA7B4D93C03291E81D8796D9D38_gshared (ReadOnlyCollection_1_t64744639C891F76DBE5EACA43B0C982707EB99E8* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF27356D302C16DB6F6D0050D55AF437BBF77EDE5(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mABEA50A98CFC875525107305139F54234862B41C(__this, ((*(ValueTuple_2_t0A96E043A7E5674155FA717C6511EDFFDF318BFE*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m6446FB01DDEB8F7C437FC2CC0A5F5733EF70552D (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ReadOnlyCollection_1_get_Item_m6C082E3922FCE5186A6BFBF5DD88CB2B40787FB8 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mE77F913CCFF9E1305F3BC87C4355AE2F0E57D3E3 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m3CAE6EBA74517E3BFB1F715E818D8BB1D7C59786 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m8621011D167C69599A570F5EE0B4874364617F1C (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC3D2945DCADDB4638731ABC140B447B953139CD5 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m99141A1CF20C53D3359DD8D00E2EE98870C65440 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m5CD6C76904266EA1EF4601E581A33945D4F85867 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m6446FB01DDEB8F7C437FC2CC0A5F5733EF70552D(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< ValueTuple_2U5BU5D_tC292D7A40A701EFEA380E934BDAB6B47EF51B69D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mF8DFF910CBBBBA61F630F66809A070E5B294EBA1 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m81E917BEA2914B04D9EF4D97564BFC50DB5C506F (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A));
		ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m0EF4E1D494AC76DB91D6D5336F100DFDC8A3871B (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m81E917BEA2914B04D9EF4D97564BFC50DB5C506F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mE77F913CCFF9E1305F3BC87C4355AE2F0E57D3E3(__this, ((*(ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mF1234E1E4C86C6AC970920111A48B1EAC5067024 (ReadOnlyCollection_1_t0F878A002120C8BA2C383296795D3638EAEB5239* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m81E917BEA2914B04D9EF4D97564BFC50DB5C506F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mC3D2945DCADDB4638731ABC140B447B953139CD5(__this, ((*(ValueTuple_2_t66C82960295DE11A5326D3FF7142662DC4C8C68A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m592D5F512E13B72776FD22657D3914D6175A7BB0_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ReadOnlyCollection_1_get_Item_m5ADFE659D8C86BD009B177D738EA7B81C394B27A_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m119E4EE9C57EC91ECF98FD691A5DB45B73DFD6B0_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m2E96949A66E5776D6DB042DB7156C544D58990AB_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m9642734FEE6368A0B10BDB27BA475EE812CF50B7_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mED49053F7FEA4AF9AE64E66AA79A0679B2BF89CC_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m47BFFD201AC9928042E874D0FB0638FCEE12571A_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m22B8E40EC13AB4343CFC95D4A6B2B0C707652B9D_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m592D5F512E13B72776FD22657D3914D6175A7BB0(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_3U5BU5D_t3F0023205A30D06F175ACCAF7386C2CF78D05695*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mA62548090B4306DB9C001632D185825B98573081_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAA5EF416789EF268D338EDA3CA5646845E9359FD_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4));
		ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m94A164F4E9A1351ACB697813AE4451063F127451_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAA5EF416789EF268D338EDA3CA5646845E9359FD(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m119E4EE9C57EC91ECF98FD691A5DB45B73DFD6B0(__this, ((*(ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m6C8D9EAB968E9E737299DA42D1425164AF399878_gshared (ReadOnlyCollection_1_t13F13F3D995B403760B07AA7988B18D7C757F5B3* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAA5EF416789EF268D338EDA3CA5646845E9359FD(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mED49053F7FEA4AF9AE64E66AA79A0679B2BF89CC(__this, ((*(ValueTuple_3_t082BBE6EEA5644021C2B34E882901856A6CF8BD4*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE1C93AAD70F6223EAE9A21DED15E2A4D67061146_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ReadOnlyCollection_1_get_Item_mB0358E083E015C32CAFCF87D04A0394C5776F511_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mCA566CF8841B3859F7D5B9A3BE333DDF08EAFCCF_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_1 = ___0_value;
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m5C998BC2D3646CB88EA526FC650B10E06BB6D708_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m5A805BECE0DFFFD3481281FCF1A948C5F7CF2330_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mFA374F7FE0EA2D33D5547CE13F88627B41F9B404_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mB322D21999FD8DD96F1E56070F7177B4CB7E5811_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m2AE401AF5EC470AB9CF64D5AA7A0D2832DB82705_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_mE1C93AAD70F6223EAE9A21DED15E2A4D67061146(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck((RuntimeObject*)L_12);
		InterfaceActionInvoker2< ValueTuple_3U5BU5D_t9C34394AB8496BAEC6ECEB7080E2CB472B9760B3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck((RuntimeObject*)L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), (RuntimeObject*)L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_35;
			L_35 = InterfaceFuncInvoker1< ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mE55AD08741E31BA90694C1AFF89A479B5A01E388_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_2;
		L_2 = InterfaceFuncInvoker1< ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC8346D99AEB0B3F66D7435BA57A24061B724C8E5_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD));
		ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m871DFEE01F035CDB823C879B9238257A65A2C71D_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC8346D99AEB0B3F66D7435BA57A24061B724C8E5(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mCA566CF8841B3859F7D5B9A3BE333DDF08EAFCCF(__this, ((*(ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m420B6BB7D2E06FA1936890179F71EA253B74B975_gshared (ReadOnlyCollection_1_t830895C3741CB124EB28FB6313FC1C9840C09B6F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC8346D99AEB0B3F66D7435BA57A24061B724C8E5(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mFA374F7FE0EA2D33D5547CE13F88627B41F9B404(__this, ((*(ValueTuple_3_t0095E6027CA7C8A0F1B72F11C4F723A669487CAD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
// Method Definition Index: 11027
// Method Definition Index: 11028
// Method Definition Index: 11029
// Method Definition Index: 11030
// Method Definition Index: 11031
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
// Method Definition Index: 11052
// Method Definition Index: 11053
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m11B7E7B09BC365660BE64984527A5A808A671A1D (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ReadOnlyCollection_1_get_Item_mD17156C080A7ECB449B9DBED9872F85FCE2A107F (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_2;
		L_2 = InterfaceFuncInvoker1< AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB5CB8F733B8D8EA77F0F14325CC976C7A45E7995 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m0A0EF58758995A2C3FCDB5CDC805842035CD8D2D (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mBA777889AF5F6A8F618D222D93C9152D9701D507 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m9F4573CEEB963B0B9FAC662F7210150A67189CF3 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m3DBFFB36933F49E12CB946A3EEA5A7A61E545AC8 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_2;
		L_2 = InterfaceFuncInvoker1< AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m23AB0D95E108EC4772D3190FF6F4624306DAAAB6 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m11B7E7B09BC365660BE64984527A5A808A671A1D(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< AngleRangeInfoU5BU5D_t8AE5F89B8CA102A1093EFEA4E67B9364AC690BC8*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_35;
			L_35 = InterfaceFuncInvoker1< AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mE8BEFE1100BD0EECBFEF772B5BA8E840041B8F4B (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_2;
		L_2 = InterfaceFuncInvoker1< AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8F8678284BE3C77A1B662031EFA148C2799B9879 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB));
		AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mF92E9C3A7E9D2D28F4DDFA219290EC422802446F (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m8F8678284BE3C77A1B662031EFA148C2799B9879(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mB5CB8F733B8D8EA77F0F14325CC976C7A45E7995(__this, ((*(AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m2A272EB57B16B1F5ACA5F17F865E75E0F3D913B1 (ReadOnlyCollection_1_t12AA48B74450A6CEBB711A45E377EECE8EFACEF8* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m8F8678284BE3C77A1B662031EFA148C2799B9879(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m9F4573CEEB963B0B9FAC662F7210150A67189CF3(__this, ((*(AngleRangeInfo_t54B4C94C605EABEC2D401C612F1D8CCB42985DBB*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m00D77F6AA6972CFF4B6A58882717FAF6DDBE0639 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ReadOnlyCollection_1_get_Item_mA7550378A93B226324B95EF38F829DB657B8AFB7 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_2;
		L_2 = InterfaceFuncInvoker1< AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m80B4A89CA0CEE0CA1B26BAA6E6E967EC0BB1D451 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mB86AC3ABE12DFD2A59AADCB8A75ADD76991840B7 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m52E46DBF49B91B605F5EEA187651D75C2AC7479B (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE2C36182593633F35CF539C68782AB51913697C1 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m753377FDD96B19AE09FB008685A72DF4BF0AC2C7 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_2;
		L_2 = InterfaceFuncInvoker1< AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mDAA11DADD406A6B1FEFE9B8EA926AFE4C3BE0A44 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m00D77F6AA6972CFF4B6A58882717FAF6DDBE0639(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< AppleOfferInfoResponseU5BU5D_t6C225EBF8A8228F32945D753BB72B5ADD6C70268*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_35;
			L_35 = InterfaceFuncInvoker1< AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m24F0DB4AF5CB98E48F571506122619C955894643 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_2;
		L_2 = InterfaceFuncInvoker1< AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFC73528B5D35D41C03C78E4D8316F63E8D94501C (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3));
		AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m2EE00EB3D180ABDAE83A6DC047AABC914EFEF4B3 (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFC73528B5D35D41C03C78E4D8316F63E8D94501C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m80B4A89CA0CEE0CA1B26BAA6E6E967EC0BB1D451(__this, ((*(AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m4A6CA70E89933C822074FC3A16D95A2B7C1198DC (ReadOnlyCollection_1_t3982A5527537E551D1FEE8FD939A33016DF3D1AA* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFC73528B5D35D41C03C78E4D8316F63E8D94501C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mE2C36182593633F35CF539C68782AB51913697C1(__this, ((*(AppleOfferInfoResponse_tA42D5D46B1A06DB614392F3D70B12830963A9BC3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m46B28078AF43B3418EFBF649AE59DF831EEEB731 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0);
		return L_1;
	}
}
// Method Definition Index: 11027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ReadOnlyCollection_1_get_Item_m09EFCB7EA9BA79A4F08C0255BE9FDBC908AE5B16 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_2;
		L_2 = InterfaceFuncInvoker1< AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mA2DF0C486FDCE07EDD28180F3667A86F91C69C74 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mCAE7B9C8501418F5963D8FC6A8501013D48FF627 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mF68C7B98BE6B1D5938CCF7BBC2169ADC214D1D3C (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_0);
		return L_1;
	}
}
// Method Definition Index: 11031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2A5E17B439B8A1DC1FE1E7017EC0C5F58DD2596D (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m74A9F18E88FA4AD2F10732D81ADFFA2240A31576 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_2;
		L_2 = InterfaceFuncInvoker1< AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m430E9AA0613867F573DFB74D2A64F63FFDA3949C (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A* V_0 = NULL;
	Type_t* V_1 = NULL;
	Type_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0030;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0030:
	{
		RuntimeArray* L_6 = ___0_array;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		int32_t L_8 = ___1_index;
		int32_t L_9;
		L_9 = ReadOnlyCollection_1_get_Count_m46B28078AF43B3418EFBF649AE59DF831EEEB731(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_7, L_8))) >= ((int32_t)L_9)))
		{
			goto IL_0046;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0046:
	{
		RuntimeArray* L_10 = ___0_array;
		V_0 = ((AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< AsyncGPUReadbackRequestU5BU5D_t46ECEC53F54368195362A44D194E7055B374DC7A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_15 = ___0_array;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = il2cpp_codegen_object_get_type(L_15);
		NullCheck(L_16);
		Type_t* L_17;
		L_17 = VirtualFuncInvoker0< Type_t* >::Invoke(48, L_16);
		V_1 = L_17;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 12)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		V_2 = L_19;
		Type_t* L_20 = V_1;
		Type_t* L_21 = V_2;
		NullCheck(L_20);
		bool L_22;
		L_22 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_20, L_21);
		if (L_22)
		{
			goto IL_008c;
		}
	}
	{
		Type_t* L_23 = V_2;
		Type_t* L_24 = V_1;
		NullCheck(L_23);
		bool L_25;
		L_25 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(24, L_23, L_24);
		if (L_25)
		{
			goto IL_008c;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_008c:
	{
		RuntimeArray* L_26 = ___0_array;
		V_3 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_26, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = V_3;
		if (L_27)
		{
			goto IL_009b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_009b:
	{
		RuntimeObject* L_28 = __this->___list;
		NullCheck(L_28);
		int32_t L_29;
		L_29 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_28);
		V_4 = L_29;
	}
	try
	{
		{
			V_5 = 0;
			goto IL_00cd_1;
		}

IL_00ad_1:
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_30 = V_3;
			int32_t L_31 = ___1_index;
			int32_t L_32 = L_31;
			___1_index = ((int32_t)il2cpp_codegen_add(L_32, 1));
			RuntimeObject* L_33 = __this->___list;
			int32_t L_34 = V_5;
			NullCheck(L_33);
			AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_35;
			L_35 = InterfaceFuncInvoker1< AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_36 = L_35;
			RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_36);
			NullCheck(L_30);
			ArrayElementTypeCheck (L_30, L_37);
			(L_30)->SetAt(static_cast<il2cpp_array_size_t>(L_32), (RuntimeObject*)L_37);
			int32_t L_38 = V_5;
			V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		}

IL_00cd_1:
		{
			int32_t L_39 = V_5;
			int32_t L_40 = V_4;
			if ((((int32_t)L_39) < ((int32_t)L_40)))
			{
				goto IL_00ad_1;
			}
		}
		{
			goto IL_00dd;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00d5;
		}
		throw e;
	}

CATCH_00d5:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_41 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00dd;
	}

IL_00dd:
	{
		return;
	}
}
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m49B172339462FAB2ABD5B327876729E9B2F94EDC (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_2;
		L_2 = InterfaceFuncInvoker1< AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mF533CD6CA43BB8725B7B7F42FA27C815727C3355 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7));
		AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m3547C8AE8E1AA11931DB48132A26841CA5494A96 (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF533CD6CA43BB8725B7B7F42FA27C815727C3355(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mA2DF0C486FDCE07EDD28180F3667A86F91C69C74(__this, ((*(AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m69F193B5BAAD49534A8E1AF51950A334F146357B (ReadOnlyCollection_1_t701C0435FAF0B47AAEB3EC60E75F95154E49FA4C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mF533CD6CA43BB8725B7B7F42FA27C815727C3355(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m2A5E17B439B8A1DC1FE1E7017EC0C5F58DD2596D(__this, ((*(AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11025
// Method Definition Index: 11026
// Method Definition Index: 11027
// Method Definition Index: 11028
// Method Definition Index: 11029
// Method Definition Index: 11030
// Method Definition Index: 11031
// Method Definition Index: 11032
// Method Definition Index: 11033
// Method Definition Index: 11034
// Method Definition Index: 11035
// Method Definition Index: 11036
// Method Definition Index: 11037
// Method Definition Index: 11038
// Method Definition Index: 11039
// Method Definition Index: 11040
// Method Definition Index: 11041
// Method Definition Index: 11042
// Method Definition Index: 11043
// Method Definition Index: 11044
// Method Definition Index: 11045
// Method Definition Index: 11046
// Method Definition Index: 11047
// Method Definition Index: 11048
// Method Definition Index: 11049
// Method Definition Index: 11050
// Method Definition Index: 11051
// Method Definition Index: 11052
// Method Definition Index: 11053
// Method Definition Index: 11054
// Method Definition Index: 11055
// Method Definition Index: 11056
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 3281
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(EmptyArray_1_t6C301AAECD8237FCD6328D15A5BC0071D53D11A1_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(EmptyArray_1_t6C301AAECD8237FCD6328D15A5BC0071D53D11A1_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ((EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 0)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 11530
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_0 = NULL;
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_0 = ((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 70842
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ReadOnlyCollectionBuilder_1_get_Count_m69CF2D9BF6F3E0F171B32C9129028208C163EF76_fshared_inline (ReadOnlyCollectionBuilder_1_t61293EE63E1CD022C5212FE61E22D8EB013B6470* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
