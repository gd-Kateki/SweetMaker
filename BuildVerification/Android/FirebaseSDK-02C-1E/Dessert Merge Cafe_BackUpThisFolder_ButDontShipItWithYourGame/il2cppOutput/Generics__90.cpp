#include "pch-cpp.hpp"





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
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,invokeData.method);
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
template <typename R, typename T1, typename T2>
struct InterfaceFuncInvoker2
{
	typedef R (*Func)(void*,T1,T2,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
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
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3* p3)
	{
		void* params[3] = { p1, &p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, params[2]);
	}
};
template <typename R>
struct InvokerFuncInvoker0
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj)
	{
		R ret;
		method->invoker_method(methodPtr, method, obj, NULL, &ret);
		return ret;
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

struct Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588;
struct EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6;
struct EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3;
struct EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187;
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC;
struct EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668;
struct EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38;
struct HashSetPropertyBag_1_tAA71EF2902794249B4D5127D03BA186EC5310BED;
struct HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1;
struct HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB;
struct HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA;
struct HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2;
struct HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B;
struct HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243;
struct HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87;
struct ICollection_1_t1155FC43C49FF5EA4422852129E51706E434D5BE;
struct ICollection_1_t048CC5FC450D66E71D7FF26795D93F2E1D1FED12;
struct ICollection_1_t1EE0E7ED969BF34D22715C0AD5DD5DABAED4CEC7;
struct ICollection_1_t828FEFDDBF830D003AFB480F0898186B499E26B0;
struct ICollection_1_tD48600DAC12B9C8EF571F89859FB62EAAC0480A7;
struct ICollection_1_t22419C4E4B157D4C36F10BC734577F050F099F7C;
struct IEnumerable_1_tA2D20239D57D72C5735C153127ECE35F2DAFCC00;
struct IEnumerable_1_t0705CC93F5983E73D60DDB3F3098A71F651BFF0C;
struct IEnumerable_1_tD1F3053EE627DE721E73FD67FD821A99CB4C35D3;
struct IEnumerable_1_tCE758D940790D6D0D56B457E522C195F8C413AF2;
struct IEnumerable_1_t5359DEC999AA35C7E2DE775B0455A4760550ED7F;
struct IEnumerable_1_tE1213A4B493AFC0D39430F0CA5C8664E4C15A296;
struct IEnumerator_1_tC6BB77939BAAA6819A26F494777F9BBD8C04AA60;
struct IEnumerator_1_t842D019876487B2E6D3BB24F849475DF22876461;
struct IEnumerator_1_t1401D3FCD547C06EE678A4053B8731809F86D662;
struct IEnumerator_1_tD6A90A7446DA8E6CF865EDFBBF18C1200BB6D452;
struct IEnumerator_1_t6999C610E1C05F2C90151CD5C41E24528ACB3255;
struct IEnumerator_1_tDB76B45124D1569F782EAE2F47993DF076758957;
struct IEqualityComparer_1_t697947236421E8B0401335F7E1E24D21284E9D2E;
struct IEqualityComparer_1_t0FD77626ECC867C51E80375D213A11E13F49043A;
struct IEqualityComparer_1_tC2F75F0AFCCD4E374F38138CBDE3C28822418718;
struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
struct IEqualityComparer_1_tEA6D87A5AB670819FF91305D215B209552281584;
struct IEqualityComparer_1_t6FE30305ED686025427F2E3AF3C177EA120CF9A5;
struct IEqualityComparer_1_t7FB55DF8C4C70E44E492EAF04BACA67FA273F857;
struct IEqualityComparer_1_t341DBC625B94A179D2F2C3E3CF45C76E281F4612;
struct IEqualityComparer_1_t47CC0B235E693652D181B679FF6D61A469ECC122;
struct ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20;
struct ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150;
struct ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47;
struct Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08;
struct Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B;
struct Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3;
struct Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3;
struct Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD;
struct Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC;
struct SetElementProperty_t289C8D92DD4214A46FC3E74E8FE7C6EDE8B1C0C9;
struct Stack_1_t8A69A1B0DE92EA0F504C742E29AE30CC75B506A0;
struct Stack_1_t2CB236599BE1BE25AA9FC0C3F10A27404E72E223;
struct UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF;
struct UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409;
struct UnityAction_1_t980FBD10D55F595EE81A8BC767D6819F54D8A642;
struct SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3;
struct SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4;
struct SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF;
struct SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7;
struct SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0;
struct SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C;
struct SlotU5BU5D_tA31D0003F69C4AB4359EFBC24DAE89573BB7D025;
struct SlotU5BU5D_t07FCA100BAB3D53C17B55BC073D41006B19C4D70;
struct SlotU5BU5D_t2B9148416634BCB8743E1F61254B305F1882FF1D;
struct ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9;
struct EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1;
struct PropertyPathPartU5BU5D_t7994D542F14DDDDEABB1792C335C20149399AEBB;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct IFormatterConverter_t726606DAC82C384B08C82471313C340968DDB609;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct String_t;
struct Type_t;
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral07624473F417C06C74D59C64840A1532FCE2C626;
IL2CPP_EXTERN_C String_t* _stringLiteral0F19052576940E4C653C32FF5A8A81D0ABB73F97;
IL2CPP_EXTERN_C String_t* _stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414;
IL2CPP_EXTERN_C String_t* _stringLiteral325E9B626B8674DB0D0742BC125F644ED8FFFFCB;
IL2CPP_EXTERN_C String_t* _stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B;
IL2CPP_EXTERN_C String_t* _stringLiteral469F05BE9BB4C7903C353D0EB9F6384C84A48B25;
IL2CPP_EXTERN_C String_t* _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0;
IL2CPP_EXTERN_C String_t* _stringLiteral91930CCAB5CB8F6F327407F9A14CF42F57A0F27B;
IL2CPP_EXTERN_C String_t* _stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085;
IL2CPP_EXTERN_C String_t* _stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED;
IL2CPP_EXTERN_C String_t* _stringLiteralC00660333703C551EA80371B54D0ADCEB74C33B4;
IL2CPP_EXTERN_C String_t* _stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7;
IL2CPP_EXTERN_C String_t* _stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E;
IL2CPP_EXTERN_C String_t* _stringLiteralC5ABE84F2ABF009EBC68D2A32EF8C171B074F922;
IL2CPP_EXTERN_C String_t* _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
IL2CPP_EXTERN_C String_t* _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
IL2CPP_EXTERN_C String_t* _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1;
IL2CPP_EXTERN_C String_t* _stringLiteralE2EEFB4BE0C9F57BA62E733F26387F8BA68AF67C;
IL2CPP_EXTERN_C String_t* _stringLiteralE8697FF635A0BB21392DD8D91CB3D0303148C10A;
IL2CPP_EXTERN_C String_t* _stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;
struct PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_com;
struct PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_pinvoke;

struct SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3;
struct SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4;
struct SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF;
struct SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7;
struct SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0;
struct SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C;
struct ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C;
struct EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9;
struct EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5;
struct PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CU3Ec_tDC5AC4C57D5D24496026F6F41261DB057567262F  : public RuntimeObject
{
};
struct U3CU3Ec_t0FF56B0CA81E481CEA50A59D56491E25FF6104C7  : public RuntimeObject
{
};
struct EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6  : public RuntimeObject
{
};
struct EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3  : public RuntimeObject
{
};
struct EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187  : public RuntimeObject
{
};
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC  : public RuntimeObject
{
};
struct EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668  : public RuntimeObject
{
};
struct EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38  : public RuntimeObject
{
};
struct HashSetPool_1_tCDE4475FE632D305A8B40C161E3E5D5E24FB73B2  : public RuntimeObject
{
};
struct HashSetPool_1_t703447E09A777B65F717CFC90E4FB4CA574AADA6  : public RuntimeObject
{
};
struct HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_tCDDE0D4E484190F2564386ADAA84BA615850DD8C  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_tA31D0003F69C4AB4359EFBC24DAE89573BB7D025* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_tD7C5CB4AA796FB70BE1FB3BB598BF7B3BD245035  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_t07FCA100BAB3D53C17B55BC073D41006B19C4D70* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_t2B9148416634BCB8743E1F61254B305F1882FF1D* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20  : public RuntimeObject
{
	Stack_1_t8A69A1B0DE92EA0F504C742E29AE30CC75B506A0* ___m_Stack;
	UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF* ___m_ActionOnGet;
	UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF* ___m_ActionOnRelease;
	bool ___m_CollectionCheck;
	int32_t ___U3CcountAllU3Ek__BackingField;
};
struct ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150  : public RuntimeObject
{
	Stack_1_t2CB236599BE1BE25AA9FC0C3F10A27404E72E223* ___m_Stack;
	UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409* ___m_ActionOnGet;
	UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409* ___m_ActionOnRelease;
	bool ___m_CollectionCheck;
	int32_t ___U3CcountAllU3Ek__BackingField;
};
struct BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1  : public RuntimeObject
{
	int32_t ____length;
	int32_t* ____arrayPtr;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____array;
	bool ____useStackAlloc;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37  : public RuntimeObject
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___m_members;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___m_data;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___m_types;
	Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588* ___m_nameToIndex;
	int32_t ___m_currMember;
	RuntimeObject* ___m_converter;
	String_t* ___m_fullTypeName;
	String_t* ___m_assemName;
	Type_t* ___objectType;
	bool ___isFullTypeNameSetExplicit;
	bool ___isAssemblyNameSetExplicit;
	bool ___requireSameTokenInPartialTrust;
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
struct ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 
{
	int32_t ___uniqueCount;
	int32_t ___unfoundCount;
};
struct ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA 
{
	int32_t ___uniqueCount;
	int32_t ___unfoundCount;
};
struct ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D 
{
	int32_t ___uniqueCount;
	int32_t ___unfoundCount;
};
struct ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA 
{
	int32_t ___uniqueCount;
	int32_t ___unfoundCount;
};
struct ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 
{
	int32_t ___uniqueCount;
	int32_t ___unfoundCount;
};
struct ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 
{
	int32_t ___uniqueCount;
	int32_t ___unfoundCount;
};
struct Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376 
{
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ____set;
	int32_t ____index;
	int32_t ____version;
	int32_t ____current;
};
struct PooledObject_tF0578D2ED5B0FC8E22A1DB912ED155A6A5F7F8E7 
{
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___m_ToReturn;
	ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* ___m_Pool;
};
struct PooledObject_t432123EBFF2674A3A6835051E8FF82B14E1A757A 
{
	HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* ___m_ToReturn;
	ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150* ___m_Pool;
};
struct PooledObject_t42DFE6F40709CEDB91999103D5FA096C28E0A1DD 
{
	Il2CppSharedGenericObject* ___m_ToReturn;
	ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47* ___m_Pool;
};
struct Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 
{
	int32_t ___hashCode;
	int32_t ___next;
	int32_t ___value;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
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
struct EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF 
{
	uint64_t ___Value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 
{
	String_t* ___m_StringOriginalCase;
	String_t* ___m_StringLowerCase;
};
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_pinvoke
{
	char* ___m_StringOriginalCase;
	char* ___m_StringLowerCase;
};
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_com
{
	Il2CppChar* ___m_StringOriginalCase;
	Il2CppChar* ___m_StringLowerCase;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
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
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct LongDoubleUnion_t17011746129284B81F310F56E20D549A6F6710D0 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___longValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___longValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___doubleValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___doubleValue_forAlignmentOnly;
		};
	};
};
struct Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C 
{
	HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ____set;
	int32_t ____index;
	int32_t ____version;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ____current;
};
struct Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F 
{
	HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ____set;
	int32_t ____index;
	int32_t ____version;
	EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ____current;
};
struct Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2 
{
	HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ____set;
	int32_t ____index;
	int32_t ____version;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ____current;
};
struct HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F 
{
	uint8_t* ___Ptr;
	uint64_t* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC 
{
	uint8_t* ___Ptr;
	Il2CppFullySharedGenericStruct* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB 
{
	int32_t ___hashCode;
	int32_t ___next;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___value;
};
struct Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F 
{
	int32_t ___hashCode;
	int32_t ___next;
	EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___value;
};
struct Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992 
{
	int32_t ___hashCode;
	int32_t ___next;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___value;
};
struct ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___Item1;
	Il2CppSharedGenericObject* ___Item2;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
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
struct InstantiationKind_t9B77929786BCA193B4A916F2F25793598CF0DF7D 
{
	int32_t ___value__;
};
struct NativeArrayOptions_t3E979EEF4B4840228A7692A97DA07553C6465F1D 
{
	int32_t ___value__;
};
struct PropertyPathPartKind_t82152825D88A0E450DDCE8503272A10595047F87 
{
	int32_t ___value__;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct StreamingContextStates_t5EE358E619B251608A9327618C7BFE8638FC33C1 
{
	int32_t ___value__;
};
struct AlignOfHelper_1_t10CEB3B5C979FADE1F3F9B38C6D77C6319AFF57C 
{
	uint8_t ___dummy;
	HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F ___data;
};
struct Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC 
{
	HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ____set;
	int32_t ____index;
	int32_t ____version;
	ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ____current;
};
struct NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct PropertyBag_1_t474B4314A78E9CC97DD8CF6E3ADACCDDAFB0841A  : public RuntimeObject
{
	int32_t ___U3CInstantiationKindU3Ek__BackingField;
};
struct Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637 
{
	int32_t ___hashCode;
	int32_t ___next;
	ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___value;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF 
{
	int32_t ___m_Kind;
	String_t* ___m_Name;
	int32_t ___m_Index;
	RuntimeObject* ___m_Key;
};
struct PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_pinvoke
{
	int32_t ___m_Kind;
	char* ___m_Name;
	int32_t ___m_Index;
	Il2CppIUnknown* ___m_Key;
};
struct PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_com
{
	int32_t ___m_Kind;
	Il2CppChar* ___m_Name;
	int32_t ___m_Index;
	Il2CppIUnknown* ___m_Key;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 
{
	RuntimeObject* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_pinvoke
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_com
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08  : public MulticastDelegate_t
{
};
struct Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B  : public MulticastDelegate_t
{
};
struct Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3  : public MulticastDelegate_t
{
};
struct Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3  : public MulticastDelegate_t
{
};
struct Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD  : public MulticastDelegate_t
{
};
struct SetPropertyBagBase_2_t535BA9B7846680B8FE7F234EEED4881B81612A78  : public PropertyBag_1_t474B4314A78E9CC97DD8CF6E3ADACCDDAFB0841A
{
	SetElementProperty_t289C8D92DD4214A46FC3E74E8FE7C6EDE8B1C0C9* ___m_Property;
};
struct UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF  : public MulticastDelegate_t
{
};
struct UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409  : public MulticastDelegate_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 
{
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF ___m_Part0;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF ___m_Part1;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF ___m_Part2;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF ___m_Part3;
	PropertyPathPartU5BU5D_t7994D542F14DDDDEABB1792C335C20149399AEBB* ___m_AdditionalParts;
	int32_t ___U3CLengthU3Ek__BackingField;
};
struct PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79_marshaled_pinvoke
{
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_pinvoke ___m_Part0;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_pinvoke ___m_Part1;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_pinvoke ___m_Part2;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_pinvoke ___m_Part3;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_pinvoke* ___m_AdditionalParts;
	int32_t ___U3CLengthU3Ek__BackingField;
};
struct PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79_marshaled_com
{
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_com ___m_Part0;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_com ___m_Part1;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_com ___m_Part2;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_com ___m_Part3;
	PropertyPathPart_tFB308743948D2298957DC1898D90AF2ACFED9DFF_marshaled_com* ___m_AdditionalParts;
	int32_t ___U3CLengthU3Ek__BackingField;
};
struct SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7 
{
	HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ____set;
	int32_t ____index;
	int32_t ____version;
	PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ____current;
};
struct HashSetPropertyBag_1_tAA71EF2902794249B4D5127D03BA186EC5310BED  : public SetPropertyBagBase_2_t535BA9B7846680B8FE7F234EEED4881B81612A78
{
};
struct Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC  : public MulticastDelegate_t
{
};
struct Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1 
{
	int32_t ___hashCode;
	int32_t ___next;
	PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___value;
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
	RuntimeObject* ____actualValue;
};
struct U3CU3Ec_tDC5AC4C57D5D24496026F6F41261DB057567262F_StaticFields
{
	U3CU3Ec_tDC5AC4C57D5D24496026F6F41261DB057567262F* ___U3CU3E9;
};
struct U3CU3Ec_t0FF56B0CA81E481CEA50A59D56491E25FF6104C7_StaticFields
{
	U3CU3Ec_t0FF56B0CA81E481CEA50A59D56491E25FF6104C7* ___U3CU3E9;
};
struct EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6_StaticFields
{
	EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* ___defaultComparer;
};
struct EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3_StaticFields
{
	EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* ___defaultComparer;
};
struct EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187_StaticFields
{
	EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* ___defaultComparer;
};
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields
{
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* ___defaultComparer;
};
struct EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668_StaticFields
{
	EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* ___defaultComparer;
};
struct EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38_StaticFields
{
	EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* ___defaultComparer;
};
struct HashSetPool_1_tCDE4475FE632D305A8B40C161E3E5D5E24FB73B2_StaticFields
{
	ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* ___s_Pool;
};
struct HashSetPool_1_t703447E09A777B65F717CFC90E4FB4CA574AADA6_StaticFields
{
	ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150* ___s_Pool;
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
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
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
struct SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_StaticFields
{
	String_t* ___s_nullMessage;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3  : public RuntimeArray
{
	ALIGN_FIELD (8) Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637 m_Items[1];

	inline Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___Item2), (void*)NULL);
	}
	inline Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___Item2), (void*)NULL);
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C  : public RuntimeArray
{
	ALIGN_FIELD (8) ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 m_Items[1];

	inline ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item2), (void*)NULL);
	}
	inline ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___Item2), (void*)NULL);
	}
};
struct SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4  : public RuntimeArray
{
	ALIGN_FIELD (8) Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB m_Items[1];

	inline Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB value)
	{
		m_Items[index] = value;
	}
};
struct EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9  : public RuntimeArray
{
	ALIGN_FIELD (8) EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 m_Items[1];

	inline EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 value)
	{
		m_Items[index] = value;
	}
};
struct SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF  : public RuntimeArray
{
	ALIGN_FIELD (8) Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F m_Items[1];

	inline Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F value)
	{
		m_Items[index] = value;
	}
};
struct EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25  : public RuntimeArray
{
	ALIGN_FIELD (8) EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF m_Items[1];

	inline EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF value)
	{
		m_Items[index] = value;
	}
};
struct SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7  : public RuntimeArray
{
	ALIGN_FIELD (8) Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 m_Items[1];

	inline Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 value)
	{
		m_Items[index] = value;
	}
};
struct SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0  : public RuntimeArray
{
	ALIGN_FIELD (8) Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992 m_Items[1];

	inline Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___m_StringLowerCase), (void*)NULL);
		#endif
	}
	inline Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___m_StringLowerCase), (void*)NULL);
		#endif
	}
};
struct InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5  : public RuntimeArray
{
	ALIGN_FIELD (8) InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 m_Items[1];

	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringLowerCase), (void*)NULL);
		#endif
	}
	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_StringLowerCase), (void*)NULL);
		#endif
	}
};
struct SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C  : public RuntimeArray
{
	ALIGN_FIELD (8) Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1 m_Items[1];

	inline Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part0))->___m_Name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part0))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part1))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part1))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part2))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part2))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part3))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part3))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___m_AdditionalParts), (void*)NULL);
		#endif
	}
	inline Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part0))->___m_Name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part0))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part1))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part1))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part2))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part2))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part3))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((&((m_Items + index)->___value))->___m_Part3))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___m_AdditionalParts), (void*)NULL);
		#endif
	}
};
struct PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1  : public RuntimeArray
{
	ALIGN_FIELD (8) PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 m_Items[1];

	inline PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part0))->___m_Name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part0))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part1))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part1))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part2))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part2))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part3))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part3))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_AdditionalParts), (void*)NULL);
		#endif
	}
	inline PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part0))->___m_Name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part0))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part1))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part1))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part2))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part2))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part3))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___m_Part3))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_AdditionalParts), (void*)NULL);
		#endif
	}
};


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool HashMapHelper_1_get_IsCreated_mFD6A2975F04E9C84A9886543625D8E8BCA71E398_fshared_inline (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_CalcCapacityCeilPow2_m9E11DDA5C0E69FAD3BB1FB92BB81D4B3CFFBADC5_fshared_inline (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetBucketSize_m2A7DED1791178844328490156FD5FF62C0684DDD_fshared (int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t HashMapHelper_1_CalculateDataSize_m0C67007EE834531E10390239B3C023F0E6DAC734 (int32_t ___0_capacity, int32_t ___1_bucketCapacity, int32_t ___2_sizeOfTValue, int64_t* ___3_outKeyOffset, int64_t* ___4_outNextOffset, int64_t* ___5_outBucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Clear_m08F7FBA8BE840C96DBB073B5BFBC33BC2745AEBE_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Init_m3FE834D3E93E89E94B27E96CB7539E27E42C1CD4 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_capacity, int32_t ___1_sizeOfValueT, int32_t ___2_minGrowth, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Dispose_mB9A6E998C327368FCA81FFF52F90700CE2557703_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mF8220FD740AC717FEB8B7460771A3B6FD63D53A3 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_ResizeExact_m5451A2FE0928DD096B06F1B5224ED1C86072B737 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_newCapacity, int32_t ___1_newBucketCapacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_TryAdd_mC9B7159FF845CE72FCB51815FE2FB4A632268B05 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271 (uint8_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_Find_m06E689F8DF7198DACBC06242493F0B0FCB91B5AA (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Resize_m6E701545E3A7E5295D279C25C44CCD6D9DDD87B8 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_newCapacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC1C144C4AC4D9B3B2C30F06F88CB6E6AB475125E_inline (void* ___0_destination, int32_t ___1_index, uint64_t ___2_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetBucket_m3345CE3D37BC07CAFC78C5829BEBBFD3C15CC771_inline (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t* ___0_key, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t UnsafeUtility_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8F5B829A65BCE22A8B2364D1C303A1E2876A3898_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashMapHelper_1_MoveNextSearch_m5B2FF1D7B41C3BA34939652BB8BB2629DD498626_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t* ___0_bucketIndex, int32_t* ___1_nextIndex, int32_t* ___2_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B CollectionHelper_CreateNativeArray_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC727918BA8092015B5AC1386101D4D0E3DF17816 (int32_t ___0_length, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* ObjectPool_1_Get_mC477E9202FD626D53F1175EF625DF47A96A39DE1_gshared (ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PooledObject_t42DFE6F40709CEDB91999103D5FA096C28E0A1DD ObjectPool_1_Get_m4E923E4311EA500B7240A9EFFB9119B714AAFD10_gshared (ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47* __this, Il2CppSharedGenericObject** ___0_v, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ObjectPool_1_Release_mDA498404E0FED30B2CC57A73B32D49F043D3E629_gshared (ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47* __this, Il2CppSharedGenericObject* ___0_element, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityAction_1__ctor_mEFEA54F750A1FFB6264069F934F996B052C6FD49_gshared (UnityAction_1_t980FBD10D55F595EE81A8BC767D6819F54D8A642* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ObjectPool_1__ctor_m4581D16C68999546FCC08E2F103FBF180AC9F74F_gshared (ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47* __this, UnityAction_1_t980FBD10D55F595EE81A8BC767D6819F54D8A642* ___0_actionOnGet, UnityAction_1_t980FBD10D55F595EE81A8BC767D6819F54D8A642* ___1_actionOnRelease, bool ___2_collectionCheck, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m14AD1C1CA129FB480E87E3E87E07A80A4116E6AC_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m8F1F54847D80FB44D78C4C2348B4E276FAFDFBE6_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mC55BC901428ADE93E9D697C2F480CCDCD68225D5_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m5D556866CC79848C93CBE9EA11913A938B7714E9_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_set1, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m7FF70E808B0B1514D7B78FE4C60F28001291E7EA_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m72DE47E8E620210513B082CBA1E297529F2F784A_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m2C4EA13B68542A21E8981DD0E05F20466A088119_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m6416C7AB136F0AA15420624327EE27778D5A830A_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_index, int32_t ___1_hashCode, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mFC04995DA22DA1C00773DA838F6BF5BD57386F08_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m486EC9E4B561CEAE79EE39104CC24E6064F21F0F_gshared (Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC* __this, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m9BDEA1D1C55D8CE94C0A62F57F80C5C524634092_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m402E179A83E6B20C2C11DFF0562DB0F1C77A4E9B_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 HashSet_1_CheckUniqueAndUnfoundElements_mCDDB1BEE21C233C8B06AC6C1D951FC0F3DF765BB_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m94A03798DE3ED2CCEBF84727F779A9A09E2866D6_gshared_inline (Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m6B69D10A56A2048DDFBA6320F30C8A88474F0952_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_mB5EC93ED1317A5C581250CEBF083ED19ACEC5680_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_mD2206425C110AF13BF45E25072B54509B6A31FCB_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_mC8707235E125D21EF8B82C07F7DF31501E7EDCFB_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m7E77CEB0BDFF8900C4DEAA7A5E1E21DDB52F3BEF_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* EqualityComparer_1_get_Default_m16781A8E4EDB2114168E318B51C5081028E57F3D_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m243CD293A2127B3FAE419703CC89640A6F570E28 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA9B40FD1D35748AA889DF20A2045FF6FDF153B5F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m884A133C560BC45033194B8F8B72BEB5C1ECD001 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m745C3AA0C82ABD3EACFE9AD11FB39B801138F98F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_set1, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_mFED69AC25A7BEEFA40379F9BFEE13A78C6A733F9 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m9F38BC09C26BE8AB8CD88B95B5D9BF5596333949 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mA664CEC5ECB3F67F7A34810662A0A8EA5B05E0F4 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m90BF44FD415BD8D59609DFCE9A93FDA2AF29F14E (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mA51FE1D72D825FC764AA4ED6C347ACD2CAF61E4C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_index, int32_t ___1_hashCode, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mAF5149C72B493BC5D95BE4EC13A429A05773FFF6 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m38217C0101E1F461019404AAF3395993EB1CF941 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m04CB2B4FC5D114776861F1B52AF0F57CBAE649D1 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m72FD8FF16B6F691518A0FBE35F111468EA68A558 (Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C* __this, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mE58E698435830C5C358B353C4399919DC77F0D6C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_mB976C7D04D778F1FB1639F6E23FABA39C2EF175F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA HashSet_1_CheckUniqueAndUnfoundElements_mD12B1A14A687B718C5D814FA14C404D3F328BF0D (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m2F110E2073E6471BD12C32F8EA63B0673BEFB275_inline (Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m4C39EA4316F83D39009A5EBE10E207279EAC85EA (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_mE64511C2F4ED7CDD466E4FC9AD6170447674A565 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_mF06BBDACC9FB3F0629936C128349062594CD65E6 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m4F9D37448BAEF8FE526453CB58B1EF11EB5D5C8C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_mCCA47E61CC24F37E672A305FA0614E2FD661A73C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* EqualityComparer_1_get_Default_m116EA0543E757039FC0248582114CD5078435378_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m81358023B845A4D3270030000BC6377A25AF109A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m943B4F9475E84832B1690AE207920F0EB091C98C (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m2E7B8F4B50CB641ECAEA9DDCA03F85C59DBFCD0E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m4CE29AA365BD937A2E12C794E09E19D0CB20B8EE (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_set1, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m9212C09A26DCBF451C4EDFDC285795EAF0EE5494 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m388FABC9629D7B7DBEE9104461A18D3A467ADE8A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mCD4A87BDC9C79126CA4FA60ABC8116E47DE58F9C (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m09FAE505BEBF4191B480224176E6298AEAD543DD (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mE41A53D868E2ADA467E2C6304A0B806E7F5213BB (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_index, int32_t ___1_hashCode, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mC1CC3F3C8532776B1CBD8C19E8F245F33DCE066A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m077082839BDD06A5353FADE1CEDBE8FD44F9CFAD (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m1D8319452756E92FD985CBEFBFDEBBB83C5D036E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m23E682237EE2BDF19D5BB21ABA68C2B0384B4CE0 (Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F* __this, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m78D58EDF20BAF924E06F4F0C973DE3C511293551 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_mBFE3C57E264F8C227BEEBC200760FA83D1969B39 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D HashSet_1_CheckUniqueAndUnfoundElements_m63C187EFD30928C462894D854942F13172A814AA (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mBC57F9AAD95FE4E1D54D4F368A162D155516B547_inline (Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m05814B20238F59F43308AD5D54B3F0F877919CC1 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m7AF79FED0EEF23B2F3FEEA789D4662599CA67EF0 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m2C7BDBAF64D2BA51F63BDB50FEE2FA43BA8C7B0E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m0B7B5FA01B6EAB629850CEDBD4C42CF166F3B07E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m60DE8DED336AAAF63A6DC608722E57026FEBCD9F (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mD01A3150BFA527119EBAB7922A64F4BB94CC293D (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mC8EB7E5E12FA6F38890EB2435FF06B81B3BBBB0A (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA74E823F988E9515688F756D0DD9223AE0248596 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m2D30A02470631B29664BF3981E958399DCD05E59 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_set1, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m76A9036184E9E454D1A7553EF88A707525F27A8A (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m8DCCD8BD41DA4D933EB974678D99E0FFEAC5A21C (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m324C75B2D781E7BF38384F10C30AEC7668EB7CDA (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mFDA37D3F003EF52B5E93673AE3ED38E04D5DB500 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m6D3D24A6F1E5CB0ABD85841349382CE64EF2F690 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_index, int32_t ___1_hashCode, int32_t ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_m43D6B3CAAED91ED49E0194803AC6BA67ADF6439B (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m8C50FFBACD63C1AA40F63C5C9CAA1811F5988F97 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m3C27BBD4EFB01EA7A8B2DE3F0E12CD9E449950DF (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mFE3FD5858B2622B0DB3A98E965A87270E087E292 (Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376* __this, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mAFBFB4E9CC9508A1AE5E2FD2A63AEE373D77C409 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m631F3C7D7E456054B308DEE064BF085F8EC99211 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA HashSet_1_CheckUniqueAndUnfoundElements_m1FE7B070F6F535246DE7D39D368813B4CBE80B61 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mD16C664FFE93598D1C12AC86190D12B0F90B5419_inline (Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3* __this, int32_t ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mF4C8539185EBCAAE0803DF227E006B701007DD65 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m6B2495F23F97908BC4EE3B987C1F16093E922C62 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m7EE99125BBB78B18669A0B9760A5F6E4A01454FF (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m98A9F88FF94538B5EECB0F87E1E3B3572E02ACA1 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m25B685122812ED3363A4B27873DF75996E749592 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* EqualityComparer_1_get_Default_m33839529811E5B677FAC3708C8617567B0D8A1AB_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA593337684C1715F8F7DDDE4399536CB8767D9AE (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m48DF5063EEA93A7753ECFC022584BC5879F67BB3 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mE79F5A3C8490054B23264CA3292ED4ECD6AE7A1E (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_mEE3BE892E186C9374F85D41990FB9EC272705F9C (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_set1, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m9D129AAD52690789DC1E875DA22208A523541411 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m12456C0B5F2BD37BD07B7CFDA9F116F25281B6D1 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mE7E76F7B64EAB9DB84193329E6DE509AA98D922A (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mF4BE03AACFEFADB2AF97B062CCBF788B4B45B8D3 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mE3EB6B7254469CC1B786252C4CC9E221D59D5D70 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_index, int32_t ___1_hashCode, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mA1B61994FAB542B6C40F2B1F6BDD417501CDA050 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_mA1CB8FE8A84C5D1386228D2ABBC9BCB047D163AB (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mCCACCE15A67A4C2F57BBCEE9FF8856544DC2CF2F (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m95D3F3FF905181D3CD46CD2426F4F37FD426B81C (Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2* __this, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mEE0682F788B7CB4A00C5FD93576ABF58350CF2FD (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m12E8284DE8488A7F7F3CEAE63485C6EB5F76E8D2 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 HashSet_1_CheckUniqueAndUnfoundElements_mFCC18A0BCB2346E051DD0AEA2F8405D0EC725C7C (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m8B4BDF53D356DC2B6824AECCDFD936A57EBBA0FD_inline (Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mDCCB1329C655014754502005D24A65823666CA5A (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m601FAA1088C6E2673429E100BD859DC44074A8B7 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m75E93F1A8CC2B3C092B09C717B5F4B3612FC7DBB (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m208059B8D89BB100809C7CA51253201A3B504A0B (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m6D06F796CE11E1A2F42C845B3EAB89DF9EAC166D (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* EqualityComparer_1_get_Default_m4A0896866DFD0BFADEBA26A14A4072AC9D9917D8_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mFC3ABD9B392DE2F40985925ABC08BA1459B5F6E4 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mD073B28596FF3A83B06D2C917FCF2D10F5D94372 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m6697C93FA4EE093921C5765C6F3484777246EE12 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m3EB2FC760B463CDCE0838CAFB44F137DB6A77BFF (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_set1, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_mF6B7A9579D122B655180B1B56EB3DA87F3D46167 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m47155C7D260A5C12CC93E90A14D4554D17E37F1F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m39B566378AD1EF02E6E6D135E8F5AA7216EFB45F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mBEF82257C8F5AFE73305A602536496BE0E512E23 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m0594A940F2ADB614CAA703B0F1DFCD15A6CA6329 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_index, int32_t ___1_hashCode, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mE4C9D1F8BFD05EA7EDAD5D186153A5135AE293ED (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m54D386E54FD853D8B410D65049B7B5E9D96244BD (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m47AF3F67F0D00BF19747208D1B3A3233AEDBC95A (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m460D0268E0EAD8DDF942699DB292BA7FC04B31BD (Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7* __this, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mD7019504367CF88BF03BF13365DBA24FA58FAE84 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m040CA79E19A6BFFD5B55F6C138D8C9ED5861E21F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 HashSet_1_CheckUniqueAndUnfoundElements_m621B1D60770E2C41C97F50A937FA2A145CC4C647 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mD00114316CACFD296E750222C808E712960B78FF_inline (Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mDB799908FE78068E57CBAC14B4E85314BC5F7ABE (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m3CD22E798A2CE8BA8CA466AA43AC54CD8523C5EC (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m048FA262F10970373C3496B36D2BAC845C2F9B6E (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_mBFF089381B4F9F83CAB4B68BF69351CDB316A5F0 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_mF9A798624F165D0C90626783F1E8C5FF54524C56 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m36ACB11EACD25CAC24617BB81FC5C3AA11976B6D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC71868C665A692778D508E69E8AF1A631E0CD348_inline (void* ___0_destination, int32_t ___1_index, uint64_t ___2_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t UnsafeUtilityInternal_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mA5895D44428BCE7F38A3E30CA324F5E0E599364F_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* EqualityComparer_1_CreateComparer_m2EA0FB1D5B051AA3C02FF460F77C79F729B43097_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* EqualityComparer_1_CreateComparer_m5C45453CBD8B5F1DD5C8F3C77D3B5F80BB1B4B70 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* EqualityComparer_1_CreateComparer_m3E6DFD6F7D0BC2435CC38857D363A06C9F737722 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* EqualityComparer_1_CreateComparer_m5641C6C3F2BDF42B483859C7C1A734FB901C288B (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* EqualityComparer_1_CreateComparer_m4E64AAE802462A678408F709D7B1A2E4F1FD603F (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t10CEB3B5C979FADE1F3F9B38C6D77C6319AFF57C_mE4C1913654DEBAAC6B7EC085814397556183951E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mF4BBC9CA9F485924727D26DA8F0ED7E229C1C2D1_inline (const RuntimeMethod* method) ;

inline bool HashMapHelper_1_get_IsCreated_m7746B3C9062DD56F40051CB3DBAC195B521EF2B6_inline (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*, const RuntimeMethod*))HashMapHelper_1_get_IsCreated_mFD6A2975F04E9C84A9886543625D8E8BCA71E398_fshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_lzcnt_m4BDBABBBAA2F9B553AE1155DFBDB552E23BB2F73_inline (int32_t ___0_x, const RuntimeMethod* method) ;
inline int32_t HashMapHelper_1_CalcCapacityCeilPow2_m1ADD3BBB4D070AF33497AB7614730E3C4EE7BFC0_inline (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*, int32_t, const RuntimeMethod*))HashMapHelper_1_CalcCapacityCeilPow2_m9E11DDA5C0E69FAD3BB1FB92BB81D4B3CFFBADC5_fshared_inline)(__this, ___0_capacity, method);
}
inline int32_t HashMapHelper_1_GetBucketSize_m699C65123EC7032084E8AB6BA8EE0D04700F2AEF (int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int32_t, const RuntimeMethod*))HashMapHelper_1_GetBucketSize_m2A7DED1791178844328490156FD5FF62C0684DDD_fshared)(___0_capacity, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t HashMapHelper_1_CalculateDataSize_m0C67007EE834531E10390239B3C023F0E6DAC734 (int32_t ___0_capacity, int32_t ___1_bucketCapacity, int32_t ___2_sizeOfTValue, int64_t* ___3_outKeyOffset, int64_t* ___4_outNextOffset, int64_t* ___5_outBucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5 (int64_t ___0_size, int32_t ___1_align, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_allocator, const RuntimeMethod* method) ;
inline void HashMapHelper_1_Clear_m1705509FB37ACE8797711638BAB75F71BDE021EC (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, const RuntimeMethod* method)
{
	((  void (*) (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*, const RuntimeMethod*))HashMapHelper_1_Clear_m08F7FBA8BE840C96DBB073B5BFBC33BC2745AEBE_fshared)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Init_m3FE834D3E93E89E94B27E96CB7539E27E42C1CD4 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_capacity, int32_t ___1_sizeOfValueT, int32_t ___2_minGrowth, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline void HashMapHelper_1_Dispose_m046F1E45B82D1EDE4F6585986BCA47BA1716C0F1 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, const RuntimeMethod* method)
{
	((  void (*) (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*, const RuntimeMethod*))HashMapHelper_1_Dispose_mB9A6E998C327368FCA81FFF52F90700CE2557703_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mF8220FD740AC717FEB8B7460771A3B6FD63D53A3 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_ceilpow2_m6873BD56787A2362EE6780DD54A9847561B11629_inline (int32_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_ResizeExact_m5451A2FE0928DD096B06F1B5224ED1C86072B737 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_newCapacity, int32_t ___1_newBucketCapacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_TryAdd_mC9B7159FF845CE72FCB51815FE2FB4A632268B05 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177 (void* ___0_destination, void* ___1_source, int64_t ___2_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271 (uint8_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92 (uint64_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_Find_m06E689F8DF7198DACBC06242493F0B0FCB91B5AA (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Resize_m6E701545E3A7E5295D279C25C44CCD6D9DDD87B8 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_newCapacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC1C144C4AC4D9B3B2C30F06F88CB6E6AB475125E_inline (void* ___0_destination, int32_t ___1_index, uint64_t ___2_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetBucket_m3345CE3D37BC07CAFC78C5829BEBBFD3C15CC771_inline (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t* ___0_key, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t UnsafeUtility_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8F5B829A65BCE22A8B2364D1C303A1E2876A3898_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UInt64_Equals_mB642AC4A6A1261E0FB36D7F1F2D77940790FAA81 (uint64_t* __this, uint64_t ___0_obj, const RuntimeMethod* method) ;
inline bool HashMapHelper_1_MoveNextSearch_mE0266FCE6EB2A2B1D3D3BBC219A4E03AF73DCD16 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t* ___0_bucketIndex, int32_t* ___1_nextIndex, int32_t* ___2_index, const RuntimeMethod* method)
{
	return ((  bool (*) (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*, int32_t*, int32_t*, int32_t*, const RuntimeMethod*))HashMapHelper_1_MoveNextSearch_m5B2FF1D7B41C3BA34939652BB8BB2629DD498626_fshared)(__this, ___0_bucketIndex, ___1_nextIndex, ___2_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B CollectionHelper_CreateNativeArray_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC727918BA8092015B5AC1386101D4D0E3DF17816 (int32_t ___0_length, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemSet_m4CD74CD43260EB2962A46F57E0D93DD5C332FC2B (void* ___0_destination, uint8_t ___1_value, int64_t ___2_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) ;
inline HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ObjectPool_1_Get_mC7EA455A853C47435D58F14E4AEE2A478D1EDA54 (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* __this, const RuntimeMethod* method)
{
	return ((  HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* (*) (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20*, const RuntimeMethod*))ObjectPool_1_Get_mC477E9202FD626D53F1175EF625DF47A96A39DE1_gshared)(__this, method);
}
inline PooledObject_tF0578D2ED5B0FC8E22A1DB912ED155A6A5F7F8E7 ObjectPool_1_Get_mA791397D45446D728240C874EB1853108B33C6BD (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* __this, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2** ___0_v, const RuntimeMethod* method)
{
	return ((  PooledObject_tF0578D2ED5B0FC8E22A1DB912ED155A6A5F7F8E7 (*) (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20*, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2**, const RuntimeMethod*))ObjectPool_1_Get_m4E923E4311EA500B7240A9EFFB9119B714AAFD10_gshared)(__this, ___0_v, method);
}
inline void ObjectPool_1_Release_m4C16FE356E556464270B5BF3BE9F49ED4A1979D0 (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* __this, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_element, const RuntimeMethod* method)
{
	((  void (*) (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20*, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2*, const RuntimeMethod*))ObjectPool_1_Release_mDA498404E0FED30B2CC57A73B32D49F043D3E629_gshared)(__this, ___0_element, method);
}
inline void UnityAction_1__ctor_m2852CF8FCEBCAE485F8F43CD4A6DD64D53B76B71 (UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF*, RuntimeObject*, intptr_t, const RuntimeMethod*))UnityAction_1__ctor_mEFEA54F750A1FFB6264069F934F996B052C6FD49_gshared)(__this, ___0_object, ___1_method, method);
}
inline void ObjectPool_1__ctor_m7987C522CD796BB6C78908999127474CE691CE4B (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* __this, UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF* ___0_actionOnGet, UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF* ___1_actionOnRelease, bool ___2_collectionCheck, const RuntimeMethod* method)
{
	((  void (*) (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20*, UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF*, UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF*, bool, const RuntimeMethod*))ObjectPool_1__ctor_m4581D16C68999546FCC08E2F103FBF180AC9F74F_gshared)(__this, ___0_actionOnGet, ___1_actionOnRelease, ___2_collectionCheck, method);
}
inline EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_gshared_inline)(method);
}
inline void HashSet_1__ctor_m14AD1C1CA129FB480E87E3E87E07A80A4116E6AC (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, RuntimeObject*, const RuntimeMethod*))HashSet_1__ctor_m14AD1C1CA129FB480E87E3E87E07A80A4116E6AC_gshared)(__this, ___0_comparer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline void HashSet_1__ctor_m8F1F54847D80FB44D78C4C2348B4E276FAFDFBE6 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, int32_t, RuntimeObject*, const RuntimeMethod*))HashSet_1__ctor_m8F1F54847D80FB44D78C4C2348B4E276FAFDFBE6_gshared)(__this, ___0_capacity, ___1_comparer, method);
}
inline void HashSet_1__ctor_mC55BC901428ADE93E9D697C2F480CCDCD68225D5 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))HashSet_1__ctor_mC55BC901428ADE93E9D697C2F480CCDCD68225D5_gshared)(__this, ___0_collection, ___1_comparer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
inline bool HashSet_1_AreEqualityComparersEqual_m5D556866CC79848C93CBE9EA11913A938B7714E9 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_set1, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___1_set2, const RuntimeMethod* method)
{
	return ((  bool (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, const RuntimeMethod*))HashSet_1_AreEqualityComparersEqual_m5D556866CC79848C93CBE9EA11913A938B7714E9_gshared)(___0_set1, ___1_set2, method);
}
inline void HashSet_1_CopyFrom_m7FF70E808B0B1514D7B78FE4C60F28001291E7EA (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_source, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, const RuntimeMethod*))HashSet_1_CopyFrom_m7FF70E808B0B1514D7B78FE4C60F28001291E7EA_gshared)(__this, ___0_source, method);
}
inline int32_t HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, int32_t, const RuntimeMethod*))HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61_gshared)(__this, ___0_capacity, method);
}
inline void HashSet_1_UnionWith_m72DE47E8E620210513B082CBA1E297529F2F784A (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, RuntimeObject*, const RuntimeMethod*))HashSet_1_UnionWith_m72DE47E8E620210513B082CBA1E297529F2F784A_gshared)(__this, ___0_other, method);
}
inline void HashSet_1_TrimExcess_m2C4EA13B68542A21E8981DD0E05F20466A088119 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, const RuntimeMethod*))HashSet_1_TrimExcess_m2C4EA13B68542A21E8981DD0E05F20466A088119_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9 (int32_t ___0_oldSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042 (RuntimeArray* __this, const RuntimeMethod* method) ;
inline void HashSet_1_AddValue_m6416C7AB136F0AA15420624327EE27778D5A830A (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_index, int32_t ___1_hashCode, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___2_value, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, int32_t, int32_t, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*))HashSet_1_AddValue_m6416C7AB136F0AA15420624327EE27778D5A830A_gshared)(__this, ___0_index, ___1_hashCode, ___2_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
inline bool HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*))HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74_gshared)(__this, ___0_value, method);
}
inline int32_t HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*))HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7_gshared)(__this, ___0_item, method);
}
inline void HashSet_1_CopyTo_mFC04995DA22DA1C00773DA838F6BF5BD57386F08 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C*, int32_t, int32_t, const RuntimeMethod*))HashSet_1_CopyTo_mFC04995DA22DA1C00773DA838F6BF5BD57386F08_gshared)(__this, ___0_array, ___1_arrayIndex, ___2_count, method);
}
inline void Enumerator__ctor_m486EC9E4B561CEAE79EE39104CC24E6064F21F0F (Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC* __this, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_set, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC*, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, const RuntimeMethod*))Enumerator__ctor_m486EC9E4B561CEAE79EE39104CC24E6064F21F0F_gshared)(__this, ___0_set, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, int32_t ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, RuntimeObject* ___1_value, Type_t* ___2_type, const RuntimeMethod* method) ;
inline void HashSet_1_CopyTo_m9BDEA1D1C55D8CE94C0A62F57F80C5C524634092 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C*, const RuntimeMethod*))HashSet_1_CopyTo_m9BDEA1D1C55D8CE94C0A62F57F80C5C524634092_gshared)(__this, ___0_array, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationException__ctor_m0AAFE2ABD0A74F3E783AD5B5FE842DE460168DB0 (SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline int32_t HashSet_1_get_Count_m5BEC231429D800AFD5D691C317D39991E78ED415_inline (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, const RuntimeMethod*))HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline)(__this, method);
}
inline bool HashSet_1_ContainsAllElements_m402E179A83E6B20C2C11DFF0562DB0F1C77A4E9B (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, const RuntimeMethod* method)
{
	return ((  bool (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, RuntimeObject*, const RuntimeMethod*))HashSet_1_ContainsAllElements_m402E179A83E6B20C2C11DFF0562DB0F1C77A4E9B_gshared)(__this, ___0_other, method);
}
inline ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 HashSet_1_CheckUniqueAndUnfoundElements_mCDDB1BEE21C233C8B06AC6C1D951FC0F3DF765BB (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method)
{
	return ((  ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, RuntimeObject*, bool, const RuntimeMethod*))HashSet_1_CheckUniqueAndUnfoundElements_mCDDB1BEE21C233C8B06AC6C1D951FC0F3DF765BB_gshared)(__this, ___0_other, ___1_returnIfUnfound, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85 (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, RuntimeObject* ___1_actualValue, String_t* ___2_message, const RuntimeMethod* method) ;
inline bool Predicate_1_Invoke_m94A03798DE3ED2CCEBF84727F779A9A09E2866D6_inline (Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_obj, const RuntimeMethod* method)
{
	return ((  bool (*) (Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08*, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*))Predicate_1_Invoke_m94A03798DE3ED2CCEBF84727F779A9A09E2866D6_gshared_inline)(__this, ___0_obj, method);
}
inline bool HashSet_1_Remove_m6B69D10A56A2048DDFBA6320F30C8A88474F0952 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*))HashSet_1_Remove_m6B69D10A56A2048DDFBA6320F30C8A88474F0952_gshared)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472 (int32_t ___0_min, const RuntimeMethod* method) ;
inline void HashSet_1_SetCapacity_mB5EC93ED1317A5C581250CEBF083ED19ACEC5680 (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_newSize, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, int32_t, const RuntimeMethod*))HashSet_1_SetCapacity_mB5EC93ED1317A5C581250CEBF083ED19ACEC5680_gshared)(__this, ___0_newSize, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41 (RuntimeArray* ___0_sourceArray, int32_t ___1_sourceIndex, RuntimeArray* ___2_destinationArray, int32_t ___3_destinationIndex, int32_t ___4_length, const RuntimeMethod* method) ;
inline void HashSet_1_IncreaseCapacity_mD2206425C110AF13BF45E25072B54509B6A31FCB (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method)
{
	((  void (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, const RuntimeMethod*))HashSet_1_IncreaseCapacity_mD2206425C110AF13BF45E25072B54509B6A31FCB_gshared)(__this, method);
}
inline bool HashSet_1_Contains_mC8707235E125D21EF8B82C07F7DF31501E7EDCFB (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*))HashSet_1_Contains_mC8707235E125D21EF8B82C07F7DF31501E7EDCFB_gshared)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C (int32_t ___0_n, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3 (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* __this, int32_t* ___0_bitArrayPtr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19 (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_bitArray, int32_t ___1_length, const RuntimeMethod* method) ;
inline int32_t HashSet_1_InternalIndexOf_m7E77CEB0BDFF8900C4DEAA7A5E1E21DDB52F3BEF (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*))HashSet_1_InternalIndexOf_m7E77CEB0BDFF8900C4DEAA7A5E1E21DDB52F3BEF_gshared)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2 (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* __this, int32_t ___0_bitPosition, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86 (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* __this, int32_t ___0_bitPosition, const RuntimeMethod* method) ;
inline RuntimeObject* HashSet_1_get_Comparer_m80A6402575D85864B54FC22D2F4DC295D24349DE_inline (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*, const RuntimeMethod*))HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* EqualityComparer_1_get_Default_m16781A8E4EDB2114168E318B51C5081028E57F3D_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m243CD293A2127B3FAE419703CC89640A6F570E28 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA9B40FD1D35748AA889DF20A2045FF6FDF153B5F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m884A133C560BC45033194B8F8B72BEB5C1ECD001 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m745C3AA0C82ABD3EACFE9AD11FB39B801138F98F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_set1, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_mFED69AC25A7BEEFA40379F9BFEE13A78C6A733F9 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m9F38BC09C26BE8AB8CD88B95B5D9BF5596333949 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mA664CEC5ECB3F67F7A34810662A0A8EA5B05E0F4 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m90BF44FD415BD8D59609DFCE9A93FDA2AF29F14E (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mA51FE1D72D825FC764AA4ED6C347ACD2CAF61E4C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_index, int32_t ___1_hashCode, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mAF5149C72B493BC5D95BE4EC13A429A05773FFF6 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m38217C0101E1F461019404AAF3395993EB1CF941 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m04CB2B4FC5D114776861F1B52AF0F57CBAE649D1 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m72FD8FF16B6F691518A0FBE35F111468EA68A558 (Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C* __this, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mE58E698435830C5C358B353C4399919DC77F0D6C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* ___0_array, const RuntimeMethod* method) ;
inline int32_t HashSet_1_get_Count_mF365E179072ED1AEFA61D53FE7638C3BE82A2104_inline (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB*, const RuntimeMethod*))HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_mB976C7D04D778F1FB1639F6E23FABA39C2EF175F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA HashSet_1_CheckUniqueAndUnfoundElements_mD12B1A14A687B718C5D814FA14C404D3F328BF0D (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m2F110E2073E6471BD12C32F8EA63B0673BEFB275_inline (Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m4C39EA4316F83D39009A5EBE10E207279EAC85EA (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_mE64511C2F4ED7CDD466E4FC9AD6170447674A565 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_mF06BBDACC9FB3F0629936C128349062594CD65E6 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m4F9D37448BAEF8FE526453CB58B1EF11EB5D5C8C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_mCCA47E61CC24F37E672A305FA0614E2FD661A73C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) ;
inline RuntimeObject* HashSet_1_get_Comparer_m974F0A080C6E904F6E2EA9FDBFD34D3CAA616287_inline (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB*, const RuntimeMethod*))HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* EqualityComparer_1_get_Default_m116EA0543E757039FC0248582114CD5078435378_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m81358023B845A4D3270030000BC6377A25AF109A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m943B4F9475E84832B1690AE207920F0EB091C98C (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m2E7B8F4B50CB641ECAEA9DDCA03F85C59DBFCD0E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m4CE29AA365BD937A2E12C794E09E19D0CB20B8EE (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_set1, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m9212C09A26DCBF451C4EDFDC285795EAF0EE5494 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m388FABC9629D7B7DBEE9104461A18D3A467ADE8A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mCD4A87BDC9C79126CA4FA60ABC8116E47DE58F9C (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m09FAE505BEBF4191B480224176E6298AEAD543DD (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mE41A53D868E2ADA467E2C6304A0B806E7F5213BB (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_index, int32_t ___1_hashCode, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mC1CC3F3C8532776B1CBD8C19E8F245F33DCE066A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m077082839BDD06A5353FADE1CEDBE8FD44F9CFAD (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m1D8319452756E92FD985CBEFBFDEBBB83C5D036E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m23E682237EE2BDF19D5BB21ABA68C2B0384B4CE0 (Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F* __this, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m78D58EDF20BAF924E06F4F0C973DE3C511293551 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* ___0_array, const RuntimeMethod* method) ;
inline int32_t HashSet_1_get_Count_m89A384E693796B3524241507B9CB798808BC9EC1_inline (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA*, const RuntimeMethod*))HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_mBFE3C57E264F8C227BEEBC200760FA83D1969B39 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D HashSet_1_CheckUniqueAndUnfoundElements_m63C187EFD30928C462894D854942F13172A814AA (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mBC57F9AAD95FE4E1D54D4F368A162D155516B547_inline (Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m05814B20238F59F43308AD5D54B3F0F877919CC1 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m7AF79FED0EEF23B2F3FEEA789D4662599CA67EF0 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m2C7BDBAF64D2BA51F63BDB50FEE2FA43BA8C7B0E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m0B7B5FA01B6EAB629850CEDBD4C42CF166F3B07E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m60DE8DED336AAAF63A6DC608722E57026FEBCD9F (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) ;
inline RuntimeObject* HashSet_1_get_Comparer_m0FDDAF4C5EBE9F2D935DA5791373DD5DFE439913_inline (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA*, const RuntimeMethod*))HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mD01A3150BFA527119EBAB7922A64F4BB94CC293D (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mC8EB7E5E12FA6F38890EB2435FF06B81B3BBBB0A (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA74E823F988E9515688F756D0DD9223AE0248596 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m2D30A02470631B29664BF3981E958399DCD05E59 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_set1, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m76A9036184E9E454D1A7553EF88A707525F27A8A (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m8DCCD8BD41DA4D933EB974678D99E0FFEAC5A21C (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m324C75B2D781E7BF38384F10C30AEC7668EB7CDA (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mFDA37D3F003EF52B5E93673AE3ED38E04D5DB500 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m6D3D24A6F1E5CB0ABD85841349382CE64EF2F690 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_index, int32_t ___1_hashCode, int32_t ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_m43D6B3CAAED91ED49E0194803AC6BA67ADF6439B (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m8C50FFBACD63C1AA40F63C5C9CAA1811F5988F97 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m3C27BBD4EFB01EA7A8B2DE3F0E12CD9E449950DF (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mFE3FD5858B2622B0DB3A98E965A87270E087E292 (Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376* __this, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mAFBFB4E9CC9508A1AE5E2FD2A63AEE373D77C409 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) ;
inline int32_t HashSet_1_get_Count_mB717B519B4FBD92488427A6798B491B5FA5FB185_inline (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2*, const RuntimeMethod*))HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m631F3C7D7E456054B308DEE064BF085F8EC99211 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA HashSet_1_CheckUniqueAndUnfoundElements_m1FE7B070F6F535246DE7D39D368813B4CBE80B61 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mD16C664FFE93598D1C12AC86190D12B0F90B5419_inline (Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3* __this, int32_t ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mF4C8539185EBCAAE0803DF227E006B701007DD65 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m6B2495F23F97908BC4EE3B987C1F16093E922C62 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m7EE99125BBB78B18669A0B9760A5F6E4A01454FF (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m98A9F88FF94538B5EECB0F87E1E3B3572E02ACA1 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m25B685122812ED3363A4B27873DF75996E749592 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) ;
inline RuntimeObject* HashSet_1_get_Comparer_m2DD3885BF267920FC8AD5DCD6EA6A6250ABFE3AD_inline (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2*, const RuntimeMethod*))HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* EqualityComparer_1_get_Default_m33839529811E5B677FAC3708C8617567B0D8A1AB_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA593337684C1715F8F7DDDE4399536CB8767D9AE (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m48DF5063EEA93A7753ECFC022584BC5879F67BB3 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mE79F5A3C8490054B23264CA3292ED4ECD6AE7A1E (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_mEE3BE892E186C9374F85D41990FB9EC272705F9C (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_set1, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m9D129AAD52690789DC1E875DA22208A523541411 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m12456C0B5F2BD37BD07B7CFDA9F116F25281B6D1 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mE7E76F7B64EAB9DB84193329E6DE509AA98D922A (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mF4BE03AACFEFADB2AF97B062CCBF788B4B45B8D3 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mE3EB6B7254469CC1B786252C4CC9E221D59D5D70 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_index, int32_t ___1_hashCode, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mA1B61994FAB542B6C40F2B1F6BDD417501CDA050 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_mA1CB8FE8A84C5D1386228D2ABBC9BCB047D163AB (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mCCACCE15A67A4C2F57BBCEE9FF8856544DC2CF2F (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m95D3F3FF905181D3CD46CD2426F4F37FD426B81C (Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2* __this, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mEE0682F788B7CB4A00C5FD93576ABF58350CF2FD (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_array, const RuntimeMethod* method) ;
inline int32_t HashSet_1_get_Count_m857945CD468754937686144F8926EEDE2761F10F_inline (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B*, const RuntimeMethod*))HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m12E8284DE8488A7F7F3CEAE63485C6EB5F76E8D2 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 HashSet_1_CheckUniqueAndUnfoundElements_mFCC18A0BCB2346E051DD0AEA2F8405D0EC725C7C (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m8B4BDF53D356DC2B6824AECCDFD936A57EBBA0FD_inline (Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mDCCB1329C655014754502005D24A65823666CA5A (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m601FAA1088C6E2673429E100BD859DC44074A8B7 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m75E93F1A8CC2B3C092B09C717B5F4B3612FC7DBB (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m208059B8D89BB100809C7CA51253201A3B504A0B (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m6D06F796CE11E1A2F42C845B3EAB89DF9EAC166D (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) ;
inline RuntimeObject* HashSet_1_get_Comparer_m3673F5CEB28586D9A02F64FD041905DB01F396C5_inline (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B*, const RuntimeMethod*))HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* EqualityComparer_1_get_Default_m4A0896866DFD0BFADEBA26A14A4072AC9D9917D8_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mFC3ABD9B392DE2F40985925ABC08BA1459B5F6E4 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mD073B28596FF3A83B06D2C917FCF2D10F5D94372 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m6697C93FA4EE093921C5765C6F3484777246EE12 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m3EB2FC760B463CDCE0838CAFB44F137DB6A77BFF (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_set1, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___1_set2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_mF6B7A9579D122B655180B1B56EB3DA87F3D46167 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m47155C7D260A5C12CC93E90A14D4554D17E37F1F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m39B566378AD1EF02E6E6D135E8F5AA7216EFB45F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mBEF82257C8F5AFE73305A602536496BE0E512E23 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m0594A940F2ADB614CAA703B0F1DFCD15A6CA6329 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_index, int32_t ___1_hashCode, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___2_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mE4C9D1F8BFD05EA7EDAD5D186153A5135AE293ED (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m54D386E54FD853D8B410D65049B7B5E9D96244BD (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m47AF3F67F0D00BF19747208D1B3A3233AEDBC95A (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m460D0268E0EAD8DDF942699DB292BA7FC04B31BD (Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7* __this, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_set, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mD7019504367CF88BF03BF13365DBA24FA58FAE84 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* ___0_array, const RuntimeMethod* method) ;
inline int32_t HashSet_1_get_Count_m471850B27F3237B4897DC9C958FAD020EA7185A3_inline (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243*, const RuntimeMethod*))HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m040CA79E19A6BFFD5B55F6C138D8C9ED5861E21F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 HashSet_1_CheckUniqueAndUnfoundElements_m621B1D60770E2C41C97F50A937FA2A145CC4C647 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mD00114316CACFD296E750222C808E712960B78FF_inline (Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mDB799908FE78068E57CBAC14B4E85314BC5F7ABE (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m3CD22E798A2CE8BA8CA466AA43AC54CD8523C5EC (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_newSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m048FA262F10970373C3496B36D2BAC845C2F9B6E (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_mBFF089381B4F9F83CAB4B68BF69351CDB316A5F0 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_mF9A798624F165D0C90626783F1E8C5FF54524C56 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) ;
inline RuntimeObject* HashSet_1_get_Comparer_m29781E9115A82E322DEE968C24FD049F711CE494_inline (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243*, const RuntimeMethod*))HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_lzcnt_mCD77943688E8533316BC0238E5B9344B6433E3C0_inline (uint32_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m36ACB11EACD25CAC24617BB81FC5C3AA11976B6D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC71868C665A692778D508E69E8AF1A631E0CD348_inline (void* ___0_destination, int32_t ___1_index, uint64_t ___2_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t UnsafeUtilityInternal_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mA5895D44428BCE7F38A3E30CA324F5E0E599364F_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
inline EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* EqualityComparer_1_CreateComparer_m2EA0FB1D5B051AA3C02FF460F77C79F729B43097 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m2EA0FB1D5B051AA3C02FF460F77C79F729B43097_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* EqualityComparer_1_CreateComparer_m5C45453CBD8B5F1DD5C8F3C77D3B5F80BB1B4B70 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* EqualityComparer_1_CreateComparer_m3E6DFD6F7D0BC2435CC38857D363A06C9F737722 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* EqualityComparer_1_CreateComparer_m5641C6C3F2BDF42B483859C7C1A734FB901C288B (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* EqualityComparer_1_CreateComparer_m4E64AAE802462A678408F709D7B1A2E4F1FD603F (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t10CEB3B5C979FADE1F3F9B38C6D77C6319AFF57C_mE4C1913654DEBAAC6B7EC085814397556183951E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mF4BBC9CA9F485924727D26DA8F0ED7E229C1C2D1_inline (const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 65476
// Method Definition Index: 65477
// Method Definition Index: 65478
// Method Definition Index: 65479
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashMapHelper_1_get_IsEmpty_m43D793E3832A861D018F35EB587F3BEF810320D5 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0;
		L_0 = HashMapHelper_1_get_IsCreated_m7746B3C9062DD56F40051CB3DBAC195B521EF2B6_inline(__this, NULL);
		if (!L_0)
		{
			goto IL_0012;
		}
	}
	{
		int32_t L_1 = __this->___Count;
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}

IL_0012:
	{
		return (bool)1;
	}
}
// Method Definition Index: 65480
// Method Definition Index: 65481
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Init_m3FE834D3E93E89E94B27E96CB7539E27E42C1CD4 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_capacity, int32_t ___1_sizeOfValueT, int32_t ___2_minGrowth, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	{
		__this->___Count = 0;
		int32_t L_0 = ___2_minGrowth;
		int32_t L_1;
		L_1 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(1, L_0, NULL);
		int32_t L_2;
		L_2 = math_lzcnt_m4BDBABBBAA2F9B553AE1155DFBDB552E23BB2F73_inline(((int32_t)il2cpp_codegen_subtract(L_1, 1)), NULL);
		uint8_t L_3 = (il2cpp_codegen_conv<uint8_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_subtract(((int32_t)32), L_2)),NULL));
		__this->___Log2MinGrowth = (int32_t)L_3;
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = HashMapHelper_1_CalcCapacityCeilPow2_m1ADD3BBB4D070AF33497AB7614730E3C4EE7BFC0_inline(__this, L_4, NULL);
		___0_capacity = L_5;
		int32_t L_6 = ___0_capacity;
		__this->___Capacity = L_6;
		int32_t L_7 = ___0_capacity;
		int32_t L_8;
		L_8 = HashMapHelper_1_GetBucketSize_m699C65123EC7032084E8AB6BA8EE0D04700F2AEF(L_7, NULL);
		__this->___BucketCapacity = L_8;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_9 = ___3_allocator;
		__this->___Allocator = L_9;
		int32_t L_10 = ___1_sizeOfValueT;
		__this->___SizeOfTValue = L_10;
		int32_t L_11 = ___0_capacity;
		int32_t L_12 = __this->___BucketCapacity;
		int32_t L_13 = ___1_sizeOfValueT;
		int64_t L_14;
		L_14 = HashMapHelper_1_CalculateDataSize_m0C67007EE834531E10390239B3C023F0E6DAC734(L_11, L_12, L_13, (&V_0), (&V_1), (&V_2), NULL);
		V_3 = L_14;
		int64_t L_15 = V_3;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_16 = ___3_allocator;
		void* L_17;
		L_17 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_15, ((int32_t)64), L_16, NULL);
		__this->___Ptr = (uint8_t*)L_17;
		uint8_t* L_18 = __this->___Ptr;
		int64_t L_19 = V_0;
		intptr_t L_20 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_19,NULL));
		__this->___Keys = (uint64_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_18, L_20));
		uint8_t* L_21 = __this->___Ptr;
		int64_t L_22 = V_1;
		intptr_t L_23 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_22,NULL));
		__this->___Next = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_21, L_23));
		uint8_t* L_24 = __this->___Ptr;
		int64_t L_25 = V_2;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_25,NULL));
		__this->___Buckets = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_24, L_26));
		HashMapHelper_1_Clear_m1705509FB37ACE8797711638BAB75F71BDE021EC(__this, NULL);
		return;
	}
}
// Method Definition Index: 65482
// Method Definition Index: 65483
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* HashMapHelper_1_Alloc_m189C86EBD70DEFE60E6DA324AE43F92B4585F5AD (int32_t ___0_capacity, int32_t ___1_sizeOfValueT, int32_t ___2_minGrowth, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* V_0 = NULL;
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		int32_t L_2;
		L_2 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_inline(NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		void* L_4;
		L_4 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_1, L_2, L_3, NULL);
		V_0 = (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*)L_4;
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_5 = V_0;
		int32_t L_6 = ___0_capacity;
		int32_t L_7 = ___1_sizeOfValueT;
		int32_t L_8 = ___2_minGrowth;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_9 = ___3_allocator;
		HashMapHelper_1_Init_m3FE834D3E93E89E94B27E96CB7539E27E42C1CD4((HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*)L_5, L_6, L_7, L_8, L_9, NULL);
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_10 = V_0;
		return L_10;
	}
}
// Method Definition Index: 65484
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Free_m3831736BE88C52F6C014977B0B07D017B0FA9246 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* ___0_data, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_0 = ___0_data;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0010;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_2 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE8697FF635A0BB21392DD8D91CB3D0303148C10A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0010:
	{
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_3 = ___0_data;
		HashMapHelper_1_Dispose_m046F1E45B82D1EDE4F6585986BCA47BA1716C0F1((HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*)L_3, NULL);
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_4 = ___0_data;
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_5 = ___0_data;
		NullCheck(L_5);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_6 = L_5->___Allocator;
		Unmanaged_Free_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mF8220FD740AC717FEB8B7460771A3B6FD63D53A3(L_4, L_6, NULL);
		return;
	}
}
// Method Definition Index: 65485
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Resize_m6E701545E3A7E5295D279C25C44CCD6D9DDD87B8 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_newCapacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_newCapacity;
		int32_t L_1 = __this->___Count;
		int32_t L_2;
		L_2 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(L_0, L_1, NULL);
		___0_newCapacity = L_2;
		int32_t L_3 = ___0_newCapacity;
		int32_t L_4;
		L_4 = HashMapHelper_1_GetBucketSize_m699C65123EC7032084E8AB6BA8EE0D04700F2AEF(L_3, NULL);
		int32_t L_5;
		L_5 = math_ceilpow2_m6873BD56787A2362EE6780DD54A9847561B11629_inline(L_4, NULL);
		V_0 = L_5;
		int32_t L_6 = __this->___Capacity;
		int32_t L_7 = ___0_newCapacity;
		if ((!(((uint32_t)L_6) == ((uint32_t)L_7))))
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_8 = __this->___BucketCapacity;
		int32_t L_9 = V_0;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_002d;
		}
	}
	{
		return;
	}

IL_002d:
	{
		int32_t L_10 = ___0_newCapacity;
		int32_t L_11 = V_0;
		HashMapHelper_1_ResizeExact_m5451A2FE0928DD096B06F1B5224ED1C86072B737(__this, L_10, L_11, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return;
	}
}
// Method Definition Index: 65486
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_ResizeExact_m5451A2FE0928DD096B06F1B5224ED1C86072B737 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_newCapacity, int32_t ___1_newBucketCapacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	uint8_t* V_4 = NULL;
	uint64_t* V_5 = NULL;
	int32_t* V_6 = NULL;
	int32_t* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	{
		int32_t L_0 = ___0_newCapacity;
		int32_t L_1 = ___1_newBucketCapacity;
		int32_t L_2 = __this->___SizeOfTValue;
		int64_t L_3;
		L_3 = HashMapHelper_1_CalculateDataSize_m0C67007EE834531E10390239B3C023F0E6DAC734(L_0, L_1, L_2, (&V_0), (&V_1), (&V_2), NULL);
		V_3 = L_3;
		uint8_t* L_4 = __this->___Ptr;
		V_4 = L_4;
		uint64_t* L_5 = __this->___Keys;
		V_5 = L_5;
		int32_t* L_6 = __this->___Next;
		V_6 = L_6;
		int32_t* L_7 = __this->___Buckets;
		V_7 = L_7;
		int32_t L_8 = __this->___BucketCapacity;
		int64_t L_9 = V_3;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_10 = __this->___Allocator;
		void* L_11;
		L_11 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_9, ((int32_t)64), L_10, NULL);
		__this->___Ptr = (uint8_t*)L_11;
		uint8_t* L_12 = __this->___Ptr;
		int64_t L_13 = V_0;
		intptr_t L_14 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_13,NULL));
		__this->___Keys = (uint64_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_12, L_14));
		uint8_t* L_15 = __this->___Ptr;
		int64_t L_16 = V_1;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_16,NULL));
		__this->___Next = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_15, L_17));
		uint8_t* L_18 = __this->___Ptr;
		int64_t L_19 = V_2;
		intptr_t L_20 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_19,NULL));
		__this->___Buckets = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_18, L_20));
		int32_t L_21 = ___0_newCapacity;
		__this->___Capacity = L_21;
		int32_t L_22 = ___1_newBucketCapacity;
		__this->___BucketCapacity = L_22;
		HashMapHelper_1_Clear_m1705509FB37ACE8797711638BAB75F71BDE021EC(__this, NULL);
		V_8 = 0;
		V_9 = L_8;
		goto IL_00f6;
	}

IL_0096:
	{
		int32_t* L_23 = V_7;
		int32_t L_24 = V_8;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_24,NULL));
		int32_t L_26 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_23, ((intptr_t)il2cpp_codegen_multiply(L_25, 4)))));
		V_10 = L_26;
		goto IL_00eb;
	}

IL_00a3:
	{
		uint64_t* L_27 = V_5;
		int32_t L_28 = V_10;
		intptr_t L_29 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_28,NULL));
		uint32_t L_30 = sizeof(uint64_t);
		int32_t L_31;
		L_31 = HashMapHelper_1_TryAdd_mC9B7159FF845CE72FCB51815FE2FB4A632268B05(__this, (uint64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_27, ((intptr_t)il2cpp_codegen_multiply(L_29, (int32_t)L_30)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11));
		V_11 = L_31;
		uint8_t* L_32 = __this->___Ptr;
		int32_t L_33 = __this->___SizeOfTValue;
		int32_t L_34 = V_11;
		uint8_t* L_35 = V_4;
		int32_t L_36 = __this->___SizeOfTValue;
		int32_t L_37 = V_10;
		int32_t L_38 = __this->___SizeOfTValue;
		int64_t L_39 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_38,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_32, ((int32_t)il2cpp_codegen_multiply(L_33, L_34)))), (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_35, ((int32_t)il2cpp_codegen_multiply(L_36, L_37)))), L_39, NULL);
		int32_t* L_40 = V_6;
		int32_t L_41 = V_10;
		intptr_t L_42 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_41,NULL));
		int32_t L_43 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_40, ((intptr_t)il2cpp_codegen_multiply(L_42, 4)))));
		V_10 = L_43;
	}

IL_00eb:
	{
		int32_t L_44 = V_10;
		if ((!(((uint32_t)L_44) == ((uint32_t)(-1)))))
		{
			goto IL_00a3;
		}
	}
	{
		int32_t L_45 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_45, 1));
	}

IL_00f6:
	{
		int32_t L_46 = V_8;
		int32_t L_47 = V_9;
		if ((((int32_t)L_46) < ((int32_t)L_47)))
		{
			goto IL_0096;
		}
	}
	{
		uint8_t* L_48 = V_4;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_49 = __this->___Allocator;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_48, L_49, NULL);
		return;
	}
}
// Method Definition Index: 65487
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_TrimExcess_m04BCC69C27584E1D817DA390238771A6B5354E7B (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___Count;
		int32_t L_1;
		L_1 = HashMapHelper_1_CalcCapacityCeilPow2_m1ADD3BBB4D070AF33497AB7614730E3C4EE7BFC0_inline(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = HashMapHelper_1_GetBucketSize_m699C65123EC7032084E8AB6BA8EE0D04700F2AEF(L_3, NULL);
		HashMapHelper_1_ResizeExact_m5451A2FE0928DD096B06F1B5224ED1C86072B737(__this, L_2, L_4, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return;
	}
}
// Method Definition Index: 65488
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t HashMapHelper_1_CalculateDataSize_m0C67007EE834531E10390239B3C023F0E6DAC734 (int32_t ___0_capacity, int32_t ___1_bucketCapacity, int32_t ___2_sizeOfTValue, int64_t* ___3_outKeyOffset, int64_t* ___4_outNextOffset, int64_t* ___5_outBucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	{
		uint32_t L_0 = sizeof(uint64_t);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_0 = L_2;
		int32_t L_3 = ___2_sizeOfTValue;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		int32_t L_5 = ___0_capacity;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		V_1 = ((int64_t)il2cpp_codegen_multiply(L_4, L_6));
		int32_t L_7 = ___0_capacity;
		int64_t L_8 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_7,NULL));
		V_2 = ((int64_t)il2cpp_codegen_multiply(L_1, L_8));
		int64_t L_9 = V_0;
		int32_t L_10 = ___0_capacity;
		int64_t L_11 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_10,NULL));
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_9, L_11));
		int64_t L_12 = V_0;
		int32_t L_13 = ___1_bucketCapacity;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		V_4 = ((int64_t)il2cpp_codegen_multiply(L_12, L_14));
		int64_t L_15 = V_1;
		int64_t L_16 = V_2;
		int64_t L_17 = V_3;
		int64_t L_18 = V_4;
		int64_t* L_19 = ___3_outKeyOffset;
		int64_t L_20 = V_1;
		*(L_19) = L_20;
		int64_t* L_21 = ___4_outNextOffset;
		int64_t* L_22 = ___3_outKeyOffset;
		int64_t L_23 = *(L_22);
		int64_t L_24 = V_2;
		*(L_21) = ((int64_t)il2cpp_codegen_add(L_23, L_24));
		int64_t* L_25 = ___5_outBucketOffset;
		int64_t* L_26 = ___4_outNextOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_15, L_16)), L_17)), L_18));
	}
}
// Method Definition Index: 65489
// Method Definition Index: 65490
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetBucket_m3345CE3D37BC07CAFC78C5829BEBBFD3C15CC771 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t* ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint64_t V_0 = 0;
	{
		uint64_t* L_0 = ___0_key;
		uint64_t L_1 = (*(uint64_t*)L_0);
		V_0 = L_1;
		int32_t L_2;
		L_2 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92((&V_0), NULL);
		uint64_t L_3 = (il2cpp_codegen_conv<uint64_t,int32_t,int32_t,false,false>(L_2,NULL));
		int32_t L_4 = __this->___BucketCapacity;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_subtract(L_4, 1)),NULL));
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)((int64_t)L_3&L_5)),NULL));
		return L_6;
	}
}
// Method Definition Index: 65491
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_TryAdd_mC9B7159FF845CE72FCB51815FE2FB4A632268B05 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t* ___0_key, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		uint64_t* L_0 = ___0_key;
		uint64_t L_1 = (*(uint64_t*)L_0);
		int32_t L_2;
		L_2 = HashMapHelper_1_Find_m06E689F8DF7198DACBC06242493F0B0FCB91B5AA(__this, L_1, NULL);
		if ((!(((uint32_t)(-1)) == ((uint32_t)L_2))))
		{
			goto IL_00d8;
		}
	}
	{
		int32_t L_3 = __this->___AllocatedIndex;
		int32_t L_4 = __this->___Capacity;
		if ((((int32_t)L_3) < ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = __this->___FirstFreeIdx;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_6 = __this->___Capacity;
		if ((!(((uint32_t)L_6) == ((uint32_t)((int32_t)536870912)))))
		{
			goto IL_0038;
		}
	}
	{
		return (-1);
	}

IL_0038:
	{
		int32_t L_7 = __this->___Capacity;
		int32_t L_8 = __this->___Log2MinGrowth;
		int32_t L_9;
		L_9 = HashMapHelper_1_CalcCapacityCeilPow2_m1ADD3BBB4D070AF33497AB7614730E3C4EE7BFC0_inline(__this, ((int32_t)il2cpp_codegen_add(L_7, ((int32_t)(1<<((int32_t)(L_8&((int32_t)31))))))), NULL);
		V_2 = L_9;
		int32_t L_10 = V_2;
		HashMapHelper_1_Resize_m6E701545E3A7E5295D279C25C44CCD6D9DDD87B8(__this, L_10, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
	}

IL_0058:
	{
		int32_t L_11 = __this->___FirstFreeIdx;
		V_0 = L_11;
		int32_t L_12 = V_0;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		int32_t* L_13 = __this->___Next;
		int32_t L_14 = V_0;
		intptr_t L_15 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_14,NULL));
		int32_t L_16 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_13, ((intptr_t)il2cpp_codegen_multiply(L_15, 4)))));
		__this->___FirstFreeIdx = L_16;
		goto IL_0089;
	}

IL_0077:
	{
		int32_t L_17 = __this->___AllocatedIndex;
		V_3 = L_17;
		int32_t L_18 = V_3;
		__this->___AllocatedIndex = ((int32_t)il2cpp_codegen_add(L_18, 1));
		int32_t L_19 = V_3;
		V_0 = L_19;
	}

IL_0089:
	{
		uint64_t* L_20 = __this->___Keys;
		int32_t L_21 = V_0;
		uint64_t* L_22 = ___0_key;
		uint64_t L_23 = (*(uint64_t*)L_22);
		UnsafeUtility_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC1C144C4AC4D9B3B2C30F06F88CB6E6AB475125E_inline((void*)L_20, L_21, L_23, NULL);
		uint64_t* L_24 = ___0_key;
		int32_t L_25;
		L_25 = HashMapHelper_1_GetBucket_m3345CE3D37BC07CAFC78C5829BEBBFD3C15CC771_inline(__this, L_24, NULL);
		V_1 = L_25;
		int32_t* L_26 = __this->___Next;
		int32_t L_27 = V_0;
		intptr_t L_28 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_27,NULL));
		int32_t* L_29 = __this->___Buckets;
		int32_t L_30 = V_1;
		intptr_t L_31 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_30,NULL));
		int32_t L_32 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_29, ((intptr_t)il2cpp_codegen_multiply(L_31, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_26, ((intptr_t)il2cpp_codegen_multiply(L_28, 4))))) = L_32;
		int32_t* L_33 = __this->___Buckets;
		int32_t L_34 = V_1;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_34,NULL));
		int32_t L_36 = V_0;
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_33, ((intptr_t)il2cpp_codegen_multiply(L_35, 4))))) = L_36;
		int32_t L_37 = __this->___Count;
		__this->___Count = ((int32_t)il2cpp_codegen_add(L_37, 1));
		int32_t L_38 = V_0;
		return L_38;
	}

IL_00d8:
	{
		return (-1);
	}
}
// Method Definition Index: 65492
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_Find_m06E689F8DF7198DACBC06242493F0B0FCB91B5AA (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t* V_2 = NULL;
	uint64_t V_3 = 0;
	{
		int32_t L_0 = __this->___AllocatedIndex;
		if ((((int32_t)L_0) <= ((int32_t)0)))
		{
			goto IL_0063;
		}
	}
	{
		int32_t L_1;
		L_1 = HashMapHelper_1_GetBucket_m3345CE3D37BC07CAFC78C5829BEBBFD3C15CC771_inline(__this, (&___0_key), NULL);
		V_0 = L_1;
		int32_t* L_2 = __this->___Buckets;
		int32_t L_3 = V_0;
		intptr_t L_4 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_3,NULL));
		int32_t L_5 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_2, ((intptr_t)il2cpp_codegen_multiply(L_4, 4)))));
		V_1 = L_5;
		int32_t L_6 = V_1;
		int32_t L_7 = __this->___Capacity;
		if ((!(((uint32_t)L_6) < ((uint32_t)L_7))))
		{
			goto IL_0063;
		}
	}
	{
		int32_t* L_8 = __this->___Next;
		V_2 = L_8;
		goto IL_0044;
	}

IL_0031:
	{
		int32_t* L_9 = V_2;
		int32_t L_10 = V_1;
		intptr_t L_11 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_10,NULL));
		int32_t L_12 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_9, ((intptr_t)il2cpp_codegen_multiply(L_11, 4)))));
		V_1 = L_12;
		int32_t L_13 = V_1;
		int32_t L_14 = __this->___Capacity;
		if ((!(((uint32_t)L_13) >= ((uint32_t)L_14))))
		{
			goto IL_0044;
		}
	}
	{
		return (-1);
	}

IL_0044:
	{
		uint64_t* L_15 = __this->___Keys;
		int32_t L_16 = V_1;
		uint64_t L_17;
		L_17 = UnsafeUtility_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8F5B829A65BCE22A8B2364D1C303A1E2876A3898_inline((void*)L_15, L_16, NULL);
		V_3 = L_17;
		uint64_t L_18 = ___0_key;
		bool L_19;
		L_19 = UInt64_Equals_mB642AC4A6A1261E0FB36D7F1F2D77940790FAA81((&V_3), L_18, NULL);
		if (!L_19)
		{
			goto IL_0031;
		}
	}
	{
		int32_t L_20 = V_1;
		return L_20;
	}

IL_0063:
	{
		return (-1);
	}
}
// Method Definition Index: 65494
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_TryRemove_m4701ABBC6676B47F65C285E6F58A8FC15046FDBC (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	uint64_t V_4 = 0;
	{
		int32_t L_0 = __this->___Capacity;
		if (!L_0)
		{
			goto IL_00de;
		}
	}
	{
		V_0 = 0;
		int32_t L_1;
		L_1 = HashMapHelper_1_GetBucket_m3345CE3D37BC07CAFC78C5829BEBBFD3C15CC771_inline(__this, (&___0_key), NULL);
		V_1 = L_1;
		V_2 = (-1);
		int32_t* L_2 = __this->___Buckets;
		int32_t L_3 = V_1;
		intptr_t L_4 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_3,NULL));
		int32_t L_5 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_2, ((intptr_t)il2cpp_codegen_multiply(L_4, 4)))));
		V_3 = L_5;
		goto IL_00b9;
	}

IL_002a:
	{
		uint64_t* L_6 = __this->___Keys;
		int32_t L_7 = V_3;
		uint64_t L_8;
		L_8 = UnsafeUtility_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8F5B829A65BCE22A8B2364D1C303A1E2876A3898_inline((void*)L_6, L_7, NULL);
		V_4 = L_8;
		uint64_t L_9 = ___0_key;
		bool L_10;
		L_10 = UInt64_Equals_mB642AC4A6A1261E0FB36D7F1F2D77940790FAA81((&V_4), L_9, NULL);
		if (!L_10)
		{
			goto IL_00aa;
		}
	}
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = V_2;
		if ((((int32_t)L_12) >= ((int32_t)0)))
		{
			goto IL_006a;
		}
	}
	{
		int32_t* L_13 = __this->___Buckets;
		int32_t L_14 = V_1;
		intptr_t L_15 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_14,NULL));
		int32_t* L_16 = __this->___Next;
		int32_t L_17 = V_3;
		intptr_t L_18 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_17,NULL));
		int32_t L_19 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_16, ((intptr_t)il2cpp_codegen_multiply(L_18, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_13, ((intptr_t)il2cpp_codegen_multiply(L_15, 4))))) = L_19;
		goto IL_0082;
	}

IL_006a:
	{
		int32_t* L_20 = __this->___Next;
		int32_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_21,NULL));
		int32_t* L_23 = __this->___Next;
		int32_t L_24 = V_3;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_24,NULL));
		int32_t L_26 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_23, ((intptr_t)il2cpp_codegen_multiply(L_25, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_20, ((intptr_t)il2cpp_codegen_multiply(L_22, 4))))) = L_26;
	}

IL_0082:
	{
		int32_t* L_27 = __this->___Next;
		int32_t L_28 = V_3;
		intptr_t L_29 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_28,NULL));
		int32_t L_30 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_27, ((intptr_t)il2cpp_codegen_multiply(L_29, 4)))));
		int32_t* L_31 = __this->___Next;
		int32_t L_32 = V_3;
		intptr_t L_33 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_32,NULL));
		int32_t L_34 = __this->___FirstFreeIdx;
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_31, ((intptr_t)il2cpp_codegen_multiply(L_33, 4))))) = L_34;
		int32_t L_35 = V_3;
		__this->___FirstFreeIdx = L_35;
		V_3 = L_30;
		goto IL_00c9;
	}

IL_00aa:
	{
		int32_t L_36 = V_3;
		V_2 = L_36;
		int32_t* L_37 = __this->___Next;
		int32_t L_38 = V_3;
		intptr_t L_39 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_38,NULL));
		int32_t L_40 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_37, ((intptr_t)il2cpp_codegen_multiply(L_39, 4)))));
		V_3 = L_40;
	}

IL_00b9:
	{
		int32_t L_41 = V_3;
		if ((((int32_t)L_41) < ((int32_t)0)))
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_42 = V_3;
		int32_t L_43 = __this->___Capacity;
		if ((((int32_t)L_42) < ((int32_t)L_43)))
		{
			goto IL_002a;
		}
	}

IL_00c9:
	{
		int32_t L_44 = __this->___Count;
		int32_t L_45 = V_0;
		__this->___Count = ((int32_t)il2cpp_codegen_subtract(L_44, L_45));
		int32_t L_46 = V_0;
		if (L_46)
		{
			goto IL_00dc;
		}
	}
	{
		return (-1);
	}

IL_00dc:
	{
		int32_t L_47 = V_0;
		return L_47;
	}

IL_00de:
	{
		return (-1);
	}
}
// Method Definition Index: 65495
// Method Definition Index: 65496
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashMapHelper_1_MoveNext_m0A740C2CCE3B328233475E6A6B72FB93A04345EC (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t* ___0_bucketIndex, int32_t* ___1_nextIndex, int32_t* ___2_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___1_nextIndex;
		int32_t L_1 = *(L_0);
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_001a;
		}
	}
	{
		int32_t* L_2 = ___2_index;
		int32_t* L_3 = ___1_nextIndex;
		int32_t L_4 = *(L_3);
		*(L_2) = L_4;
		int32_t* L_5 = ___1_nextIndex;
		int32_t* L_6 = __this->___Next;
		int32_t* L_7 = ___1_nextIndex;
		int32_t L_8 = *(L_7);
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		*(L_5) = L_10;
		return (bool)1;
	}

IL_001a:
	{
		int32_t* L_11 = ___0_bucketIndex;
		int32_t* L_12 = ___1_nextIndex;
		int32_t* L_13 = ___2_index;
		bool L_14;
		L_14 = HashMapHelper_1_MoveNextSearch_mE0266FCE6EB2A2B1D3D3BBC219A4E03AF73DCD16(__this, L_11, L_12, L_13, NULL);
		return L_14;
	}
}
// Method Definition Index: 65497
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B HashMapHelper_1_GetKeyArray_m209EC0493C9A9AF188B9E83420D9127B9FD44B11 (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->___Count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = ___0_allocator;
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_2;
		L_2 = CollectionHelper_CreateNativeArray_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC727918BA8092015B5AC1386101D4D0E3DF17816(L_0, L_1, 0, NULL);
		V_0 = L_2;
		V_1 = 0;
		V_2 = 0;
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&V_0))->___m_Length);
		V_3 = L_3;
		int32_t L_4 = __this->___BucketCapacity;
		V_4 = L_4;
		goto IL_0065;
	}

IL_0024:
	{
		int32_t* L_5 = __this->___Buckets;
		int32_t L_6 = V_1;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_005c;
	}

IL_0034:
	{
		int32_t L_9 = V_2;
		int32_t L_10 = L_9;
		V_2 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		uint64_t* L_11 = __this->___Keys;
		int32_t L_12 = V_5;
		uint64_t L_13;
		L_13 = UnsafeUtility_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8F5B829A65BCE22A8B2364D1C303A1E2876A3898_inline((void*)L_11, L_12, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(uint64_t, ((&V_0))->___m_Buffer, L_10, (L_13));
		int32_t* L_14 = __this->___Next;
		int32_t L_15 = V_5;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		int32_t L_17 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(L_16, 4)))));
		V_5 = L_17;
	}

IL_005c:
	{
		int32_t L_18 = V_5;
		if ((!(((uint32_t)L_18) == ((uint32_t)(-1)))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0065:
	{
		int32_t L_20 = V_1;
		int32_t L_21 = V_4;
		if ((((int32_t)L_20) >= ((int32_t)L_21)))
		{
			goto IL_006e;
		}
	}
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_3;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_0024;
		}
	}

IL_006e:
	{
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_24 = V_0;
		return L_24;
	}
}
// Method Definition Index: 65500
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_CheckIndexOutOfBounds_m7EB02C31AEF75D2293BB11F923B526E83A5440CA (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, int32_t ___0_idx, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_idx;
		int32_t L_1 = __this->___Capacity;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_001f;
		}
	}
	{
		int32_t L_2 = ___0_idx;
		int32_t L_3 = L_2;
		RuntimeObject* L_4 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_3);
		String_t* L_5;
		L_5 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral325E9B626B8674DB0D0742BC125F644ED8FFFFCB)), L_4, NULL);
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_6 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_6, L_5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_001f:
	{
		return;
	}
}
// Method Definition Index: 65501
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_CheckCapacity_mB047CAC9962C5676A01A5DFA70DC58E9C5CEADEC (int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) <= ((int32_t)((int32_t)536870912))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_2);
		int32_t L_4 = ((int32_t)536870912);
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral0F19052576940E4C653C32FF5A8A81D0ABB73F97)), L_3, L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0028:
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
// Method Definition Index: 65476
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_CalcCapacityCeilPow2_m9E11DDA5C0E69FAD3BB1FB92BB81D4B3CFFBADC5_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___Count;
		int32_t L_1;
		L_1 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(1, L_0, NULL);
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(L_1, L_2, NULL);
		___0_capacity = L_3;
		int32_t L_4 = ___0_capacity;
		int32_t L_5 = __this->___Log2MinGrowth;
		int32_t L_6;
		L_6 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(L_4, ((int32_t)(1<<((int32_t)(L_5&((int32_t)31))))), NULL);
		int32_t L_7;
		L_7 = math_ceilpow2_m6873BD56787A2362EE6780DD54A9847561B11629_inline(L_6, NULL);
		return L_7;
	}
}
// Method Definition Index: 65477
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetBucketSize_m2A7DED1791178844328490156FD5FF62C0684DDD_fshared (int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		return ((int32_t)il2cpp_codegen_multiply(L_0, 2));
	}
}
// Method Definition Index: 65478
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashMapHelper_1_get_IsCreated_mFD6A2975F04E9C84A9886543625D8E8BCA71E398_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t* L_0 = __this->___Ptr;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 65479
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashMapHelper_1_get_IsEmpty_mE0B74C2611A6136BF9AB2B9588804B95871588A4_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		bool L_0;
		L_0 = ((  bool (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))(__this, NULL);
		if (!L_0)
		{
			goto IL_0012;
		}
	}
	{
		int32_t L_1 = __this->___Count;
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}

IL_0012:
	{
		return (bool)1;
	}
}
// Method Definition Index: 65480
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Clear_m08F7FBA8BE840C96DBB073B5BFBC33BC2745AEBE_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = __this->___Buckets;
		int32_t L_1 = __this->___BucketCapacity;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemSet_m4CD74CD43260EB2962A46F57E0D93DD5C332FC2B((void*)L_0, (uint8_t)((int32_t)255), ((int64_t)il2cpp_codegen_multiply(L_2, L_3)), NULL);
		int32_t* L_4 = __this->___Next;
		int32_t L_5 = __this->___Capacity;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemSet_m4CD74CD43260EB2962A46F57E0D93DD5C332FC2B((void*)L_4, (uint8_t)((int32_t)255), ((int64_t)il2cpp_codegen_multiply(L_6, L_7)), NULL);
		__this->___Count = 0;
		__this->___FirstFreeIdx = (-1);
		__this->___AllocatedIndex = 0;
		return;
	}
}
// Method Definition Index: 65481
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Init_m927F4885890F61CA66BFC81AB69DC7930051AD6C_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t ___0_capacity, int32_t ___1_sizeOfValueT, int32_t ___2_minGrowth, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	{
		__this->___Count = 0;
		int32_t L_0 = ___2_minGrowth;
		int32_t L_1;
		L_1 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(1, L_0, NULL);
		int32_t L_2;
		L_2 = math_lzcnt_m4BDBABBBAA2F9B553AE1155DFBDB552E23BB2F73_inline(((int32_t)il2cpp_codegen_subtract(L_1, 1)), NULL);
		uint8_t L_3 = (il2cpp_codegen_conv<uint8_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_subtract(((int32_t)32), L_2)),NULL));
		__this->___Log2MinGrowth = (int32_t)L_3;
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = ((  int32_t (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)))(__this, L_4, NULL);
		___0_capacity = L_5;
		int32_t L_6 = ___0_capacity;
		__this->___Capacity = L_6;
		int32_t L_7 = ___0_capacity;
		int32_t L_8;
		L_8 = ((  int32_t (*) (int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)))(L_7, NULL);
		__this->___BucketCapacity = L_8;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_9 = ___3_allocator;
		__this->___Allocator = L_9;
		int32_t L_10 = ___1_sizeOfValueT;
		__this->___SizeOfTValue = L_10;
		int32_t L_11 = ___0_capacity;
		int32_t L_12 = __this->___BucketCapacity;
		int32_t L_13 = ___1_sizeOfValueT;
		int64_t L_14;
		L_14 = ((  int64_t (*) (int32_t, int32_t, int32_t, int64_t*, int64_t*, int64_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(L_11, L_12, L_13, (&V_0), (&V_1), (&V_2), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		V_3 = L_14;
		int64_t L_15 = V_3;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_16 = ___3_allocator;
		void* L_17;
		L_17 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_15, ((int32_t)64), L_16, NULL);
		__this->___Ptr = (uint8_t*)L_17;
		uint8_t* L_18 = __this->___Ptr;
		int64_t L_19 = V_0;
		intptr_t L_20 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_19,NULL));
		__this->___Keys = (Il2CppFullySharedGenericStruct*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_18, L_20));
		uint8_t* L_21 = __this->___Ptr;
		int64_t L_22 = V_1;
		intptr_t L_23 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_22,NULL));
		__this->___Next = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_21, L_23));
		uint8_t* L_24 = __this->___Ptr;
		int64_t L_25 = V_2;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_25,NULL));
		__this->___Buckets = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_24, L_26));
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))(__this, NULL);
		return;
	}
}
// Method Definition Index: 65482
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Dispose_mB9A6E998C327368FCA81FFF52F90700CE2557703_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t* L_0 = __this->___Ptr;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = __this->___Allocator;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_0, L_1, NULL);
		uintptr_t L_2 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		__this->___Ptr = (uint8_t*)L_2;
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		__this->___Keys = (Il2CppFullySharedGenericStruct*)L_3;
		uintptr_t L_4 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		__this->___Next = (int32_t*)L_4;
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		__this->___Buckets = (int32_t*)L_5;
		__this->___Count = 0;
		__this->___BucketCapacity = 0;
		return;
	}
}
// Method Definition Index: 65483
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* HashMapHelper_1_Alloc_mA587387A73A1ABBDF140977263E65406EB478C9B_fshared (int32_t ___0_capacity, int32_t ___1_sizeOfValueT, int32_t ___2_minGrowth, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* V_0 = NULL;
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		int32_t L_2;
		L_2 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		void* L_4;
		L_4 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_1, L_2, L_3, NULL);
		V_0 = (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*)L_4;
		HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* L_5 = V_0;
		int32_t L_6 = ___0_capacity;
		int32_t L_7 = ___1_sizeOfValueT;
		int32_t L_8 = ___2_minGrowth;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_9 = ___3_allocator;
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t, int32_t, int32_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)))((HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*)L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* L_10 = V_0;
		return L_10;
	}
}
// Method Definition Index: 65484
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Free_m1ED84E39838BC07764D22979A69F466B5437B4B4_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* ___0_data, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* L_0 = ___0_data;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0010;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_2 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE8697FF635A0BB21392DD8D91CB3D0303148C10A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0010:
	{
		HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* L_3 = ___0_data;
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)))((HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*)L_3, NULL);
		HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* L_4 = ___0_data;
		HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* L_5 = ___0_data;
		NullCheck(L_5);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_6 = L_5->___Allocator;
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8)))(L_4, L_6, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		return;
	}
}
// Method Definition Index: 65485
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_Resize_mC3DBB7AC2D19CA5947C27ABAF144A44EDC4CBC9F_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t ___0_newCapacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_newCapacity;
		int32_t L_1 = __this->___Count;
		int32_t L_2;
		L_2 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(L_0, L_1, NULL);
		___0_newCapacity = L_2;
		int32_t L_3 = ___0_newCapacity;
		int32_t L_4;
		L_4 = ((  int32_t (*) (int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)))(L_3, NULL);
		int32_t L_5;
		L_5 = math_ceilpow2_m6873BD56787A2362EE6780DD54A9847561B11629_inline(L_4, NULL);
		V_0 = L_5;
		int32_t L_6 = __this->___Capacity;
		int32_t L_7 = ___0_newCapacity;
		if ((!(((uint32_t)L_6) == ((uint32_t)L_7))))
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_8 = __this->___BucketCapacity;
		int32_t L_9 = V_0;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_002d;
		}
	}
	{
		return;
	}

IL_002d:
	{
		int32_t L_10 = ___0_newCapacity;
		int32_t L_11 = V_0;
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9)))(__this, L_10, L_11, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return;
	}
}
// Method Definition Index: 65486
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_ResizeExact_m1D828032D51F4A98A49FCBD93E69F6B6266C052B_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t ___0_newCapacity, int32_t ___1_newBucketCapacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	uint8_t* V_4 = NULL;
	Il2CppFullySharedGenericStruct* V_5 = NULL;
	int32_t* V_6 = NULL;
	int32_t* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	{
		int32_t L_0 = ___0_newCapacity;
		int32_t L_1 = ___1_newBucketCapacity;
		int32_t L_2 = __this->___SizeOfTValue;
		int64_t L_3;
		L_3 = ((  int64_t (*) (int32_t, int32_t, int32_t, int64_t*, int64_t*, int64_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(L_0, L_1, L_2, (&V_0), (&V_1), (&V_2), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		V_3 = L_3;
		uint8_t* L_4 = __this->___Ptr;
		V_4 = L_4;
		Il2CppFullySharedGenericStruct* L_5 = __this->___Keys;
		V_5 = L_5;
		int32_t* L_6 = __this->___Next;
		V_6 = L_6;
		int32_t* L_7 = __this->___Buckets;
		V_7 = L_7;
		int32_t L_8 = __this->___BucketCapacity;
		int64_t L_9 = V_3;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_10 = __this->___Allocator;
		void* L_11;
		L_11 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_9, ((int32_t)64), L_10, NULL);
		__this->___Ptr = (uint8_t*)L_11;
		uint8_t* L_12 = __this->___Ptr;
		int64_t L_13 = V_0;
		intptr_t L_14 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_13,NULL));
		__this->___Keys = (Il2CppFullySharedGenericStruct*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_12, L_14));
		uint8_t* L_15 = __this->___Ptr;
		int64_t L_16 = V_1;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_16,NULL));
		__this->___Next = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_15, L_17));
		uint8_t* L_18 = __this->___Ptr;
		int64_t L_19 = V_2;
		intptr_t L_20 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_19,NULL));
		__this->___Buckets = (int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_18, L_20));
		int32_t L_21 = ___0_newCapacity;
		__this->___Capacity = L_21;
		int32_t L_22 = ___1_newBucketCapacity;
		__this->___BucketCapacity = L_22;
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))(__this, NULL);
		V_8 = 0;
		V_9 = L_8;
		goto IL_00f6;
	}

IL_0096:
	{
		int32_t* L_23 = V_7;
		int32_t L_24 = V_8;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_24,NULL));
		int32_t L_26 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_23, ((intptr_t)il2cpp_codegen_multiply(L_25, 4)))));
		V_10 = L_26;
		goto IL_00eb;
	}

IL_00a3:
	{
		Il2CppFullySharedGenericStruct* L_27 = V_5;
		int32_t L_28 = V_10;
		intptr_t L_29 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_28,NULL));
		uint32_t L_30 = SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA;
		int32_t L_31;
		L_31 = ((  int32_t (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11)))(__this, (Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_27, ((intptr_t)il2cpp_codegen_multiply(L_29, (int32_t)L_30)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11));
		V_11 = L_31;
		uint8_t* L_32 = __this->___Ptr;
		int32_t L_33 = __this->___SizeOfTValue;
		int32_t L_34 = V_11;
		uint8_t* L_35 = V_4;
		int32_t L_36 = __this->___SizeOfTValue;
		int32_t L_37 = V_10;
		int32_t L_38 = __this->___SizeOfTValue;
		int64_t L_39 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_38,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_32, ((int32_t)il2cpp_codegen_multiply(L_33, L_34)))), (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_35, ((int32_t)il2cpp_codegen_multiply(L_36, L_37)))), L_39, NULL);
		int32_t* L_40 = V_6;
		int32_t L_41 = V_10;
		intptr_t L_42 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_41,NULL));
		int32_t L_43 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_40, ((intptr_t)il2cpp_codegen_multiply(L_42, 4)))));
		V_10 = L_43;
	}

IL_00eb:
	{
		int32_t L_44 = V_10;
		if ((!(((uint32_t)L_44) == ((uint32_t)(-1)))))
		{
			goto IL_00a3;
		}
	}
	{
		int32_t L_45 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_45, 1));
	}

IL_00f6:
	{
		int32_t L_46 = V_8;
		int32_t L_47 = V_9;
		if ((((int32_t)L_46) < ((int32_t)L_47)))
		{
			goto IL_0096;
		}
	}
	{
		uint8_t* L_48 = V_4;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_49 = __this->___Allocator;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_48, L_49, NULL);
		return;
	}
}
// Method Definition Index: 65487
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_TrimExcess_m11F65CDF4D06B72940C6253AB3E86A6EA8E3962E_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___Count;
		int32_t L_1;
		L_1 = ((  int32_t (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)))(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = ((  int32_t (*) (int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)))(L_3, NULL);
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9)))(__this, L_2, L_4, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return;
	}
}
// Method Definition Index: 65488
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t HashMapHelper_1_CalculateDataSize_m391E36E42648D8D3005D220873B0F2245C662BEA_fshared (int32_t ___0_capacity, int32_t ___1_bucketCapacity, int32_t ___2_sizeOfTValue, int64_t* ___3_outKeyOffset, int64_t* ___4_outNextOffset, int64_t* ___5_outBucketOffset, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	{
		uint32_t L_0 = SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA;
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_0 = L_2;
		int32_t L_3 = ___2_sizeOfTValue;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		int32_t L_5 = ___0_capacity;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		V_1 = ((int64_t)il2cpp_codegen_multiply(L_4, L_6));
		int32_t L_7 = ___0_capacity;
		int64_t L_8 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_7,NULL));
		V_2 = ((int64_t)il2cpp_codegen_multiply(L_1, L_8));
		int64_t L_9 = V_0;
		int32_t L_10 = ___0_capacity;
		int64_t L_11 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_10,NULL));
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_9, L_11));
		int64_t L_12 = V_0;
		int32_t L_13 = ___1_bucketCapacity;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		V_4 = ((int64_t)il2cpp_codegen_multiply(L_12, L_14));
		int64_t L_15 = V_1;
		int64_t L_16 = V_2;
		int64_t L_17 = V_3;
		int64_t L_18 = V_4;
		int64_t* L_19 = ___3_outKeyOffset;
		int64_t L_20 = V_1;
		*(L_19) = L_20;
		int64_t* L_21 = ___4_outNextOffset;
		int64_t* L_22 = ___3_outKeyOffset;
		int64_t L_23 = *(L_22);
		int64_t L_24 = V_2;
		*(L_21) = ((int64_t)il2cpp_codegen_add(L_23, L_24));
		int64_t* L_25 = ___5_outBucketOffset;
		int64_t* L_26 = ___4_outNextOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_15, L_16)), L_17)), L_18));
	}
}
// Method Definition Index: 65489
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetCount_mC24710C302A59B9751759EF7F815AF1E624D02B7_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->___AllocatedIndex;
		if ((((int32_t)L_0) > ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		return 0;
	}

IL_000b:
	{
		V_0 = 0;
		int32_t L_1 = __this->___FirstFreeIdx;
		V_1 = L_1;
		goto IL_0027;
	}

IL_0016:
	{
		int32_t L_2 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_2, 1));
		int32_t* L_3 = __this->___Next;
		int32_t L_4 = V_1;
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_3, ((intptr_t)il2cpp_codegen_multiply(L_5, 4)))));
		V_1 = L_6;
	}

IL_0027:
	{
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_8 = __this->___Capacity;
		int32_t L_9 = __this->___AllocatedIndex;
		int32_t L_10;
		L_10 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(L_8, L_9, NULL);
		int32_t L_11 = V_0;
		return ((int32_t)il2cpp_codegen_subtract(L_10, L_11));
	}
}
// Method Definition Index: 65490
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetBucket_mE1172E80C9E112134E2C0611F1583E709528EFB1_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, Il2CppFullySharedGenericStruct* ___0_key, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
	void* L_2 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10)));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericStruct V_0 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	memset(V_0, 0, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_key;
		il2cpp_codegen_memcpy(L_1, L_0, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		Il2CppConstrainedCallData L_3;
		Il2CppMethodPointer L_4 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 12), (void*)(Il2CppFullySharedGenericStruct*)V_0, &L_3, L_2);
		typedef int32_t ( *func_L_5)(void*,const RuntimeMethod*);
		int32_t L_6 = ((func_L_5)L_4)(L_3.thisPtr,L_3.method);
		uint64_t L_7 = (il2cpp_codegen_conv<uint64_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = __this->___BucketCapacity;
		int64_t L_9 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_subtract(L_8, 1)),NULL));
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)((int64_t)L_7&L_9)),NULL));
		return L_10;
	}
}
// Method Definition Index: 65491
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_TryAdd_mEA7DF62C16993CE3B2D2C3C6484114D7C2526580_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, Il2CppFullySharedGenericStruct* ___0_key, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	const Il2CppFullySharedGenericStruct L_23 = L_1;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_key;
		il2cpp_codegen_memcpy(L_1, L_0, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		int32_t L_2;
		L_2 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13), __this, L_1);
		if ((!(((uint32_t)(-1)) == ((uint32_t)L_2))))
		{
			goto IL_00d8;
		}
	}
	{
		int32_t L_3 = __this->___AllocatedIndex;
		int32_t L_4 = __this->___Capacity;
		if ((((int32_t)L_3) < ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = __this->___FirstFreeIdx;
		if ((((int32_t)L_5) >= ((int32_t)0)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_6 = __this->___Capacity;
		if ((!(((uint32_t)L_6) == ((uint32_t)((int32_t)536870912)))))
		{
			goto IL_0038;
		}
	}
	{
		return (-1);
	}

IL_0038:
	{
		int32_t L_7 = __this->___Capacity;
		int32_t L_8 = __this->___Log2MinGrowth;
		int32_t L_9;
		L_9 = ((  int32_t (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)))(__this, ((int32_t)il2cpp_codegen_add(L_7, ((int32_t)(1<<((int32_t)(L_8&((int32_t)31))))))), NULL);
		V_2 = L_9;
		int32_t L_10 = V_2;
		((  void (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14)))(__this, L_10, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
	}

IL_0058:
	{
		int32_t L_11 = __this->___FirstFreeIdx;
		V_0 = L_11;
		int32_t L_12 = V_0;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		int32_t* L_13 = __this->___Next;
		int32_t L_14 = V_0;
		intptr_t L_15 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_14,NULL));
		int32_t L_16 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_13, ((intptr_t)il2cpp_codegen_multiply(L_15, 4)))));
		__this->___FirstFreeIdx = L_16;
		goto IL_0089;
	}

IL_0077:
	{
		int32_t L_17 = __this->___AllocatedIndex;
		V_3 = L_17;
		int32_t L_18 = V_3;
		__this->___AllocatedIndex = ((int32_t)il2cpp_codegen_add(L_18, 1));
		int32_t L_19 = V_3;
		V_0 = L_19;
	}

IL_0089:
	{
		Il2CppFullySharedGenericStruct* L_20 = __this->___Keys;
		int32_t L_21 = V_0;
		Il2CppFullySharedGenericStruct* L_22 = ___0_key;
		il2cpp_codegen_memcpy(L_23, L_22, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 15)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 15), NULL, (void*)L_20, L_21, L_23);
		Il2CppFullySharedGenericStruct* L_24 = ___0_key;
		int32_t L_25;
		L_25 = ((  int32_t (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16)))(__this, L_24, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16));
		V_1 = L_25;
		int32_t* L_26 = __this->___Next;
		int32_t L_27 = V_0;
		intptr_t L_28 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_27,NULL));
		int32_t* L_29 = __this->___Buckets;
		int32_t L_30 = V_1;
		intptr_t L_31 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_30,NULL));
		int32_t L_32 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_29, ((intptr_t)il2cpp_codegen_multiply(L_31, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_26, ((intptr_t)il2cpp_codegen_multiply(L_28, 4))))) = L_32;
		int32_t* L_33 = __this->___Buckets;
		int32_t L_34 = V_1;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_34,NULL));
		int32_t L_36 = V_0;
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_33, ((intptr_t)il2cpp_codegen_multiply(L_35, 4))))) = L_36;
		int32_t L_37 = __this->___Count;
		__this->___Count = ((int32_t)il2cpp_codegen_add(L_37, 1));
		int32_t L_38 = V_0;
		return L_38;
	}

IL_00d8:
	{
		return (-1);
	}
}
// Method Definition Index: 65492
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_Find_m230136C2D470770694EF15C9C0F2637F623E02BD_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, Il2CppFullySharedGenericStruct ___0_key, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
	void* L_19 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10)));
	const Il2CppFullySharedGenericStruct L_17 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	const Il2CppFullySharedGenericStruct L_18 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t* V_2 = NULL;
	Il2CppFullySharedGenericStruct V_3 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	memset(V_3, 0, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	{
		int32_t L_0 = __this->___AllocatedIndex;
		if ((((int32_t)L_0) <= ((int32_t)0)))
		{
			goto IL_0063;
		}
	}
	{
		int32_t L_1;
		L_1 = ((  int32_t (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16)))(__this, (Il2CppFullySharedGenericStruct*)___0_key, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16));
		V_0 = L_1;
		int32_t* L_2 = __this->___Buckets;
		int32_t L_3 = V_0;
		intptr_t L_4 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_3,NULL));
		int32_t L_5 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_2, ((intptr_t)il2cpp_codegen_multiply(L_4, 4)))));
		V_1 = L_5;
		int32_t L_6 = V_1;
		int32_t L_7 = __this->___Capacity;
		if ((!(((uint32_t)L_6) < ((uint32_t)L_7))))
		{
			goto IL_0063;
		}
	}
	{
		int32_t* L_8 = __this->___Next;
		V_2 = L_8;
		goto IL_0044;
	}

IL_0031:
	{
		int32_t* L_9 = V_2;
		int32_t L_10 = V_1;
		intptr_t L_11 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_10,NULL));
		int32_t L_12 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_9, ((intptr_t)il2cpp_codegen_multiply(L_11, 4)))));
		V_1 = L_12;
		int32_t L_13 = V_1;
		int32_t L_14 = __this->___Capacity;
		if ((!(((uint32_t)L_13) >= ((uint32_t)L_14))))
		{
			goto IL_0044;
		}
	}
	{
		return (-1);
	}

IL_0044:
	{
		Il2CppFullySharedGenericStruct* L_15 = __this->___Keys;
		int32_t L_16 = V_1;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 17)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 17), NULL, (void*)L_15, L_16, (Il2CppFullySharedGenericStruct*)L_17);
		il2cpp_codegen_memcpy(V_3, L_17, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		il2cpp_codegen_memcpy(L_18, ___0_key, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		Il2CppConstrainedCallData L_20;
		Il2CppMethodPointer L_21 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 18), (void*)(Il2CppFullySharedGenericStruct*)V_3, &L_20, L_19);
		bool L_22 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericStruct >::Invoke(L_21, L_20.method,L_20.thisPtr, L_18);
		if (!L_22)
		{
			goto IL_0031;
		}
	}
	{
		int32_t L_23 = V_1;
		return L_23;
	}

IL_0063:
	{
		return (-1);
	}
}
// Method Definition Index: 65494
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_TryRemove_mF0EBAE2241D4A51420C87201DDFF160F83CC271B_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, Il2CppFullySharedGenericStruct ___0_key, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
	void* L_10 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10)));
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	const Il2CppFullySharedGenericStruct L_9 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Il2CppFullySharedGenericStruct V_4 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	memset(V_4, 0, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	{
		int32_t L_0 = __this->___Capacity;
		if (!L_0)
		{
			goto IL_00de;
		}
	}
	{
		V_0 = 0;
		int32_t L_1;
		L_1 = ((  int32_t (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16)))(__this, (Il2CppFullySharedGenericStruct*)___0_key, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16));
		V_1 = L_1;
		V_2 = (-1);
		int32_t* L_2 = __this->___Buckets;
		int32_t L_3 = V_1;
		intptr_t L_4 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_3,NULL));
		int32_t L_5 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_2, ((intptr_t)il2cpp_codegen_multiply(L_4, 4)))));
		V_3 = L_5;
		goto IL_00b9;
	}

IL_002a:
	{
		Il2CppFullySharedGenericStruct* L_6 = __this->___Keys;
		int32_t L_7 = V_3;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 17)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 17), NULL, (void*)L_6, L_7, (Il2CppFullySharedGenericStruct*)L_8);
		il2cpp_codegen_memcpy(V_4, L_8, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		il2cpp_codegen_memcpy(L_9, ___0_key, SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
		Il2CppConstrainedCallData L_11;
		Il2CppMethodPointer L_12 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 18), (void*)(Il2CppFullySharedGenericStruct*)V_4, &L_11, L_10);
		bool L_13 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericStruct >::Invoke(L_12, L_11.method,L_11.thisPtr, L_9);
		if (!L_13)
		{
			goto IL_00aa;
		}
	}
	{
		int32_t L_14 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_14, 1));
		int32_t L_15 = V_2;
		if ((((int32_t)L_15) >= ((int32_t)0)))
		{
			goto IL_006a;
		}
	}
	{
		int32_t* L_16 = __this->___Buckets;
		int32_t L_17 = V_1;
		intptr_t L_18 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_17,NULL));
		int32_t* L_19 = __this->___Next;
		int32_t L_20 = V_3;
		intptr_t L_21 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_20,NULL));
		int32_t L_22 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_19, ((intptr_t)il2cpp_codegen_multiply(L_21, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_16, ((intptr_t)il2cpp_codegen_multiply(L_18, 4))))) = L_22;
		goto IL_0082;
	}

IL_006a:
	{
		int32_t* L_23 = __this->___Next;
		int32_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_24,NULL));
		int32_t* L_26 = __this->___Next;
		int32_t L_27 = V_3;
		intptr_t L_28 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_27,NULL));
		int32_t L_29 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_26, ((intptr_t)il2cpp_codegen_multiply(L_28, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_23, ((intptr_t)il2cpp_codegen_multiply(L_25, 4))))) = L_29;
	}

IL_0082:
	{
		int32_t* L_30 = __this->___Next;
		int32_t L_31 = V_3;
		intptr_t L_32 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_31,NULL));
		int32_t L_33 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_30, ((intptr_t)il2cpp_codegen_multiply(L_32, 4)))));
		int32_t* L_34 = __this->___Next;
		int32_t L_35 = V_3;
		intptr_t L_36 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_35,NULL));
		int32_t L_37 = __this->___FirstFreeIdx;
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_34, ((intptr_t)il2cpp_codegen_multiply(L_36, 4))))) = L_37;
		int32_t L_38 = V_3;
		__this->___FirstFreeIdx = L_38;
		V_3 = L_33;
		goto IL_00c9;
	}

IL_00aa:
	{
		int32_t L_39 = V_3;
		V_2 = L_39;
		int32_t* L_40 = __this->___Next;
		int32_t L_41 = V_3;
		intptr_t L_42 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_41,NULL));
		int32_t L_43 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_40, ((intptr_t)il2cpp_codegen_multiply(L_42, 4)))));
		V_3 = L_43;
	}

IL_00b9:
	{
		int32_t L_44 = V_3;
		if ((((int32_t)L_44) < ((int32_t)0)))
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_45 = V_3;
		int32_t L_46 = __this->___Capacity;
		if ((((int32_t)L_45) < ((int32_t)L_46)))
		{
			goto IL_002a;
		}
	}

IL_00c9:
	{
		int32_t L_47 = __this->___Count;
		int32_t L_48 = V_0;
		__this->___Count = ((int32_t)il2cpp_codegen_subtract(L_47, L_48));
		int32_t L_49 = V_0;
		if (L_49)
		{
			goto IL_00dc;
		}
	}
	{
		return (-1);
	}

IL_00dc:
	{
		int32_t L_50 = V_0;
		return L_50;
	}

IL_00de:
	{
		return (-1);
	}
}
// Method Definition Index: 65495
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashMapHelper_1_MoveNextSearch_m5B2FF1D7B41C3BA34939652BB8BB2629DD498626_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t* ___0_bucketIndex, int32_t* ___1_nextIndex, int32_t* ___2_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		int32_t* L_0 = ___0_bucketIndex;
		int32_t L_1 = *(L_0);
		V_0 = L_1;
		int32_t L_2 = __this->___BucketCapacity;
		V_1 = L_2;
		goto IL_0039;
	}

IL_000c:
	{
		int32_t* L_3 = __this->___Buckets;
		int32_t L_4 = V_0;
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_3, ((intptr_t)il2cpp_codegen_multiply(L_5, 4)))));
		V_2 = L_6;
		int32_t L_7 = V_2;
		if ((((int32_t)L_7) == ((int32_t)(-1))))
		{
			goto IL_0035;
		}
	}
	{
		int32_t* L_8 = ___2_index;
		int32_t L_9 = V_2;
		*(L_8) = L_9;
		int32_t* L_10 = ___0_bucketIndex;
		int32_t L_11 = V_0;
		*(L_10) = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t* L_12 = ___1_nextIndex;
		int32_t* L_13 = __this->___Next;
		int32_t L_14 = V_2;
		intptr_t L_15 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_14,NULL));
		int32_t L_16 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_13, ((intptr_t)il2cpp_codegen_multiply(L_15, 4)))));
		*(L_12) = L_16;
		return (bool)1;
	}

IL_0035:
	{
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0039:
	{
		int32_t L_18 = V_0;
		int32_t L_19 = V_1;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_000c;
		}
	}
	{
		int32_t* L_20 = ___2_index;
		*(L_20) = (-1);
		int32_t* L_21 = ___0_bucketIndex;
		int32_t L_22 = __this->___BucketCapacity;
		*(L_21) = L_22;
		int32_t* L_23 = ___1_nextIndex;
		*(L_23) = (-1);
		return (bool)0;
	}
}
// Method Definition Index: 65496
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashMapHelper_1_MoveNext_mC9D28D7DE9EB2A526DFD790777D5E118D33E86BC_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t* ___0_bucketIndex, int32_t* ___1_nextIndex, int32_t* ___2_index, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___1_nextIndex;
		int32_t L_1 = *(L_0);
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_001a;
		}
	}
	{
		int32_t* L_2 = ___2_index;
		int32_t* L_3 = ___1_nextIndex;
		int32_t L_4 = *(L_3);
		*(L_2) = L_4;
		int32_t* L_5 = ___1_nextIndex;
		int32_t* L_6 = __this->___Next;
		int32_t* L_7 = ___1_nextIndex;
		int32_t L_8 = *(L_7);
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		*(L_5) = L_10;
		return (bool)1;
	}

IL_001a:
	{
		int32_t* L_11 = ___0_bucketIndex;
		int32_t* L_12 = ___1_nextIndex;
		int32_t* L_13 = ___2_index;
		bool L_14;
		L_14 = ((  bool (*) (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC*, int32_t*, int32_t*, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 20)))(__this, L_11, L_12, L_13, NULL);
		return L_14;
	}
}
// Method Definition Index: 65497
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 HashMapHelper_1_GetKeyArray_m8C41E3030AFCF52994AB7EAFD3A1CBD600466A9D_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
	const Il2CppFullySharedGenericStruct L_13 = alloca(SizeOf_TKey_t349D5E2348DC065C1656895AA09EC3114157BDEA);
	//<source_info:<no-source>:1>
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->___Count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = ___0_allocator;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_2;
		L_2 = ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (int32_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 21)))(L_0, L_1, 0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 21));
		V_0 = L_2;
		V_1 = 0;
		V_2 = 0;
		int32_t L_3;
		L_3 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 22)))((&V_0), NULL);
		V_3 = L_3;
		int32_t L_4 = __this->___BucketCapacity;
		V_4 = L_4;
		goto IL_0065;
	}

IL_0024:
	{
		int32_t* L_5 = __this->___Buckets;
		int32_t L_6 = V_1;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_005c;
	}

IL_0034:
	{
		int32_t L_9 = V_2;
		int32_t L_10 = L_9;
		V_2 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		Il2CppFullySharedGenericStruct* L_11 = __this->___Keys;
		int32_t L_12 = V_5;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 17)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 17), NULL, (void*)L_11, L_12, (Il2CppFullySharedGenericStruct*)L_13);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 23)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 23), (&V_0), L_10, L_13);
		int32_t* L_14 = __this->___Next;
		int32_t L_15 = V_5;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		int32_t L_17 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(L_16, 4)))));
		V_5 = L_17;
	}

IL_005c:
	{
		int32_t L_18 = V_5;
		if ((!(((uint32_t)L_18) == ((uint32_t)(-1)))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0065:
	{
		int32_t L_20 = V_1;
		int32_t L_21 = V_4;
		if ((((int32_t)L_20) >= ((int32_t)L_21)))
		{
			goto IL_006e;
		}
	}
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_3;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_0024;
		}
	}

IL_006e:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_24 = V_0;
		return L_24;
	}
}
// Method Definition Index: 65500
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_CheckIndexOutOfBounds_mDCEA1C2E040CE097BFFA931B9AEE32C201AA467E_fshared (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t ___0_idx, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_idx;
		int32_t L_1 = __this->___Capacity;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_001f;
		}
	}
	{
		int32_t L_2 = ___0_idx;
		int32_t L_3 = L_2;
		RuntimeObject* L_4 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_3);
		String_t* L_5;
		L_5 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral325E9B626B8674DB0D0742BC125F644ED8FFFFCB)), L_4, NULL);
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_6 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_6, L_5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_001f:
	{
		return;
	}
}
// Method Definition Index: 65501
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashMapHelper_1_CheckCapacity_mC1FA3EF072EB64DF9F09EDAD94364D72FC5CCFB2_fshared (int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) <= ((int32_t)((int32_t)536870912))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_2);
		int32_t L_4 = ((int32_t)536870912);
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral0F19052576940E4C653C32FF5A8A81D0ABB73F97)), L_3, L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0028:
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
// Method Definition Index: 30652
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* HashSetPool_1_Get_mA86D8D11E69A509E3507C51AE8FE2C06F7E9CA88 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* L_0 = ((HashSetPool_1_tCDE4475FE632D305A8B40C161E3E5D5E24FB73B2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool;
		NullCheck(L_0);
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_1;
		L_1 = ObjectPool_1_Get_mC7EA455A853C47435D58F14E4AEE2A478D1EDA54(L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		return L_1;
	}
}
// Method Definition Index: 30653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PooledObject_tF0578D2ED5B0FC8E22A1DB912ED155A6A5F7F8E7 HashSetPool_1_Get_m6B7DE609547BD0FF02BE79F03155879003C9C990 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2** ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* L_0 = ((HashSetPool_1_tCDE4475FE632D305A8B40C161E3E5D5E24FB73B2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool;
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2** L_1 = ___0_value;
		NullCheck(L_0);
		PooledObject_tF0578D2ED5B0FC8E22A1DB912ED155A6A5F7F8E7 L_2;
		L_2 = ObjectPool_1_Get_mA791397D45446D728240C874EB1853108B33C6BD(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		return L_2;
	}
}
// Method Definition Index: 30654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSetPool_1_Release_m67F5B9F0FEB289567F64E0F32F550B8518AAFBD4 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_toRelease, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* L_0 = ((HashSetPool_1_tCDE4475FE632D305A8B40C161E3E5D5E24FB73B2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool;
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_1 = ___0_toRelease;
		NullCheck(L_0);
		ObjectPool_1_Release_m4C16FE356E556464270B5BF3BE9F49ED4A1979D0(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		return;
	}
}
// Method Definition Index: 30655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSetPool_1__cctor_m7519A0B46A510B7D2CF8149A8D7693CC4B55F2C0 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(U3CU3Ec_tC25A6FA319E71E5C9DC585592EB36EC9F5EB02D8_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(U3CU3Ec_tC25A6FA319E71E5C9DC585592EB36EC9F5EB02D8_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)),il2cpp_codegen_runtime_class_init_inline);
		U3CU3Ec_tDC5AC4C57D5D24496026F6F41261DB057567262F* L_0 = ((U3CU3Ec_tDC5AC4C57D5D24496026F6F41261DB057567262F_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))->___U3CU3E9;
		UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF* L_1 = (UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF*)il2cpp_codegen_object_new(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		UnityAction_1__ctor_m2852CF8FCEBCAE485F8F43CD4A6DD64D53B76B71(L_1, L_0, (intptr_t)((void*)il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)), NULL);
		ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20* L_2 = (ObjectPool_1_tB6C1ADE468B79790CF1560D0005261278AD02E20*)il2cpp_codegen_object_new(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		ObjectPool_1__ctor_m7987C522CD796BB6C78908999127474CE691CE4B(L_2, (UnityAction_1_tE91D7881104262139C090ED0EADCBE71D6E519AF*)NULL, L_1, (bool)1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		((HashSetPool_1_tCDE4475FE632D305A8B40C161E3E5D5E24FB73B2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((HashSetPool_1_tCDE4475FE632D305A8B40C161E3E5D5E24FB73B2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool), (void*)L_2);
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
// Method Definition Index: 30652
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* HashSetPool_1_Get_mF44FDE252EA5D4E55773EE003CC29AD9CF6394F7_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150* L_0 = ((HashSetPool_1_t703447E09A777B65F717CFC90E4FB4CA574AADA6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool;
		NullCheck(L_0);
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_1;
		L_1 = InvokerFuncInvoker0< HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), L_0);
		return L_1;
	}
}
// Method Definition Index: 30653
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PooledObject_t432123EBFF2674A3A6835051E8FF82B14E1A757A HashSetPool_1_Get_mE3F0BA3CFD1753DFAEBADD152F27DF9506395EA0_fshared (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87** ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150* L_0 = ((HashSetPool_1_t703447E09A777B65F717CFC90E4FB4CA574AADA6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool;
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87** L_1 = ___0_value;
		NullCheck(L_0);
		PooledObject_t432123EBFF2674A3A6835051E8FF82B14E1A757A L_2;
		L_2 = InvokerFuncInvoker1< PooledObject_t432123EBFF2674A3A6835051E8FF82B14E1A757A, HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87** >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 30654
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSetPool_1_Release_mAD67B6A9557295CD786CA50619536ED6F823E6F8_fshared (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* ___0_toRelease, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(HashSetPool_1_t6E1F0A3C618746CD2652CD1D2B5019950C080D86_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150* L_0 = ((HashSetPool_1_t703447E09A777B65F717CFC90E4FB4CA574AADA6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool;
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_1 = ___0_toRelease;
		NullCheck(L_0);
		InvokerActionInvoker1< HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3), L_0, L_1);
		return;
	}
}
// Method Definition Index: 30655
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSetPool_1__cctor_m870F053DDD336DB877E3F699952F5901872D3D85_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(U3CU3Ec_tC25A6FA319E71E5C9DC585592EB36EC9F5EB02D8_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(U3CU3Ec_tC25A6FA319E71E5C9DC585592EB36EC9F5EB02D8_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)),il2cpp_codegen_runtime_class_init_inline);
		U3CU3Ec_t0FF56B0CA81E481CEA50A59D56491E25FF6104C7* L_0 = ((U3CU3Ec_t0FF56B0CA81E481CEA50A59D56491E25FF6104C7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))->___U3CU3E9;
		UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409* L_1 = (UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409*)il2cpp_codegen_object_new(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		((  void (*) (UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409*, RuntimeObject*, intptr_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)))(L_1, (RuntimeObject*)L_0, (intptr_t)((void*)il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)), NULL);
		ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150* L_2 = (ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150*)il2cpp_codegen_object_new(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		((  void (*) (ObjectPool_1_t6F33411F617840F00758893EC96921D38A8F5150*, UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409*, UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409*, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9)))(L_2, (UnityAction_1_tF5283D973651D2E4DD18F58A603DA7FE709C7409*)NULL, L_1, (bool)1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		((HashSetPool_1_t703447E09A777B65F717CFC90E4FB4CA574AADA6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((HashSetPool_1_t703447E09A777B65F717CFC90E4FB4CA574AADA6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_Pool), (void*)L_2);
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
// Method Definition Index: 87875
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSetPropertyBag_1_get_InstantiationKind_m542C648FC9442316698457076FBC5B8C17656097_fshared (HashSetPropertyBag_1_tAA71EF2902794249B4D5127D03BA186EC5310BED* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (int32_t)(1);
	}
}
// Method Definition Index: 87876
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* HashSetPropertyBag_1_Instantiate_m40B346AADC5FFAA079D2DD84ED0FD4843585E19E_fshared (HashSetPropertyBag_1_tAA71EF2902794249B4D5127D03BA186EC5310BED* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_0 = (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		((  void (*) (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_0;
	}
}
// Method Definition Index: 87877
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSetPropertyBag_1__ctor_m97B9FF0A7C7B1247E10A3C8A5114080B3A6571D1_fshared (HashSetPropertyBag_1_tAA71EF2902794249B4D5127D03BA186EC5310BED* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (SetPropertyBagBase_2_t535BA9B7846680B8FE7F234EEED4881B81612A78*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))((SetPropertyBagBase_2_t535BA9B7846680B8FE7F234EEED4881B81612A78*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
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
// Method Definition Index: 71561
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m564812AF239845394206139C6CA43B36FC968517_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_0;
		L_0 = EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m14AD1C1CA129FB480E87E3E87E07A80A4116E6AC(__this, (RuntimeObject*)L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return;
	}
}
// Method Definition Index: 71562
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m14AD1C1CA129FB480E87E3E87E07A80A4116E6AC_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_comparer;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_1;
		L_1 = EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		___0_comparer = (RuntimeObject*)L_1;
	}

IL_0010:
	{
		RuntimeObject* L_2 = ___0_comparer;
		__this->____comparer = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_2);
		__this->____lastIndex = 0;
		__this->____count = 0;
		__this->____freeList = (-1);
		__this->____version = 0;
		return;
	}
}
// Method Definition Index: 71563
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m6F3782E3B04CF0B29DE0FDC75F40C22F49A3C1E9_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_1;
		L_1 = EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m8F1F54847D80FB44D78C4C2348B4E276FAFDFBE6(__this, L_0, (RuntimeObject*)L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 71564
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m1F80D584814F9433E85C0CE385C182670821894C_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_collection;
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_1;
		L_1 = EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mC55BC901428ADE93E9D697C2F480CCDCD68225D5(__this, L_0, (RuntimeObject*)L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
// Method Definition Index: 71565
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mC55BC901428ADE93E9D697C2F480CCDCD68225D5_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B8_0 = 0;
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_m14AD1C1CA129FB480E87E3E87E07A80A4116E6AC(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		RuntimeObject* L_1 = ___0_collection;
		if (L_1)
		{
			goto IL_0015;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral469F05BE9BB4C7903C353D0EB9F6384C84A48B25)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0015:
	{
		RuntimeObject* L_3 = ___0_collection;
		V_0 = ((HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_4 = V_0;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m5D556866CC79848C93CBE9EA11913A938B7714E9(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_7 = V_0;
		HashSet_1_CopyFrom_m7FF70E808B0B1514D7B78FE4C60F28001291E7EA(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return;
	}

IL_0030:
	{
		RuntimeObject* L_8 = ___0_collection;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_9 = V_1;
		if (!L_9)
		{
			goto IL_0042;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_10);
		G_B8_0 = L_11;
		goto IL_0043;
	}

IL_0042:
	{
		G_B8_0 = 0;
	}

IL_0043:
	{
		V_2 = G_B8_0;
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		RuntimeObject* L_14 = ___0_collection;
		HashSet_1_UnionWith_m72DE47E8E620210513B082CBA1E297529F2F784A(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		int32_t L_15 = __this->____count;
		if ((((int32_t)L_15) <= ((int32_t)0)))
		{
			goto IL_0074;
		}
	}
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_16 = __this->____slots;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = __this->____count;
		if ((((int32_t)((int32_t)(L_17/L_18))) <= ((int32_t)3)))
		{
			goto IL_0074;
		}
	}
	{
		HashSet_1_TrimExcess_m2C4EA13B68542A21E8981DD0E05F20466A088119(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}

IL_0074:
	{
		return;
	}
}
// Method Definition Index: 71566
// Method Definition Index: 71567
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m7FF70E808B0B1514D7B78FE4C60F28001291E7EA_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_0 = ___0_source;
		NullCheck(L_0);
		int32_t L_1 = L_0->____count;
		V_0 = L_1;
		int32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_000b;
		}
	}
	{
		return;
	}

IL_000b:
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_3 = ___0_source;
		NullCheck(L_3);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = L_3->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = L_5;
		int32_t L_6 = V_0;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(((int32_t)il2cpp_codegen_add(L_6, 1)), NULL);
		int32_t L_8 = V_1;
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0065;
		}
	}
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_9 = ___0_source;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = L_9->____buckets;
		NullCheck((RuntimeArray*)L_10);
		RuntimeObject* L_11;
		L_11 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_10, NULL);
		__this->____buckets = ((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var)));
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_12 = ___0_source;
		NullCheck(L_12);
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_13 = L_12->____slots;
		NullCheck((RuntimeArray*)L_13);
		RuntimeObject* L_14;
		L_14 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_13, NULL);
		__this->____slots = ((SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)((SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))));
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_15 = ___0_source;
		NullCheck(L_15);
		int32_t L_16 = L_15->____lastIndex;
		__this->____lastIndex = L_16;
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_17 = ___0_source;
		NullCheck(L_17);
		int32_t L_18 = L_17->____freeList;
		__this->____freeList = L_18;
		goto IL_00c7;
	}

IL_0065:
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_19 = ___0_source;
		NullCheck(L_19);
		int32_t L_20 = L_19->____lastIndex;
		V_2 = L_20;
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_21 = ___0_source;
		NullCheck(L_21);
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_22 = L_21->____slots;
		V_3 = L_22;
		int32_t L_23 = V_0;
		int32_t L_24;
		L_24 = HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		V_4 = 0;
		V_5 = 0;
		goto IL_00ba;
	}

IL_0083:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_25 = V_3;
		int32_t L_26 = V_5;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		V_6 = L_27;
		int32_t L_28 = V_6;
		if ((((int32_t)L_28) < ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		int32_t L_29 = V_4;
		int32_t L_30 = V_6;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_31 = V_3;
		int32_t L_32 = V_5;
		NullCheck(L_31);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_33 = ((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->___value;
		HashSet_1_AddValue_m6416C7AB136F0AA15420624327EE27778D5A830A(__this, L_29, L_30, L_33, NULL);
		int32_t L_34 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b4:
	{
		int32_t L_35 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_35, 1));
	}

IL_00ba:
	{
		int32_t L_36 = V_5;
		int32_t L_37 = V_2;
		if ((((int32_t)L_36) < ((int32_t)L_37)))
		{
			goto IL_0083;
		}
	}
	{
		int32_t L_38 = V_4;
		__this->____lastIndex = L_38;
	}

IL_00c7:
	{
		int32_t L_39 = V_0;
		__this->____count = L_39;
		return;
	}
}
// Method Definition Index: 71568
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m8F1F54847D80FB44D78C4C2348B4E276FAFDFBE6_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_m14AD1C1CA129FB480E87E3E87E07A80A4116E6AC(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0016;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0016:
	{
		int32_t L_3 = ___0_capacity;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0022:
	{
		return;
	}
}
// Method Definition Index: 71569
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_System_Collections_Generic_ICollectionU3CTU3E_Add_m92899370E51FEF38115D78D41408154BF494E592_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return;
	}
}
// Method Definition Index: 71570
// Method Definition Index: 71571
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_mC8707235E125D21EF8B82C07F7DF31501E7EDCFB_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* V_2 = NULL;
	int32_t V_3 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0080;
		}
	}
	{
		V_0 = 0;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_2;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_3 = __this->____slots;
		V_2 = L_3;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		int32_t L_5 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->____buckets;
		NullCheck(L_6);
		int32_t L_7 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_6)->max_length),NULL));
		NullCheck(L_4);
		int32_t L_8 = ((int32_t)(L_5%L_7));
		int32_t L_9 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_9, 1));
		goto IL_007c;
	}

IL_002f:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_10 = V_2;
		int32_t L_11 = V_3;
		NullCheck(L_10);
		int32_t L_12 = ((L_10)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		int32_t L_13 = V_1;
		if ((!(((uint32_t)L_12) == ((uint32_t)L_13))))
		{
			goto IL_005a;
		}
	}
	{
		RuntimeObject* L_14 = __this->____comparer;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_15 = V_2;
		int32_t L_16 = V_3;
		NullCheck(L_15);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_17 = ((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)))->___value;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_18 = ___0_item;
		NullCheck(L_14);
		bool L_19;
		L_19 = InterfaceFuncInvoker2< bool, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_14, L_17, L_18);
		if (!L_19)
		{
			goto IL_005a;
		}
	}
	{
		return (bool)1;
	}

IL_005a:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_006b;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_006b:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_007c:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_002f;
		}
	}

IL_0080:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71572
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mA71EBC18574CB4919DB2247CB61D54CBDAED8D8F_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_0 = ___0_array;
		int32_t L_1 = ___1_arrayIndex;
		int32_t L_2 = __this->____count;
		HashSet_1_CopyTo_mFC04995DA22DA1C00773DA838F6BF5BD57386F08(__this, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71573
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m6B69D10A56A2048DDFBA6320F30C8A88474F0952_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* V_4 = NULL;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0154;
		}
	}
	{
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_2;
		int32_t L_3 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = ((int32_t)(L_3%L_5));
		V_2 = (-1);
		V_3 = 0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_6 = __this->____slots;
		V_4 = L_6;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		int32_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
		goto IL_014c;
	}

IL_003b:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_11 = V_4;
		int32_t L_12 = V_5;
		NullCheck(L_11);
		int32_t L_13 = ((L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_12)))->___hashCode;
		int32_t L_14 = V_0;
		if ((!(((uint32_t)L_13) == ((uint32_t)L_14))))
		{
			goto IL_0123;
		}
	}
	{
		RuntimeObject* L_15 = __this->____comparer;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_16 = V_4;
		int32_t L_17 = V_5;
		NullCheck(L_16);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_18 = ((L_16)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_19 = ___0_item;
		NullCheck(L_15);
		bool L_20;
		L_20 = InterfaceFuncInvoker2< bool, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0123;
		}
	}
	{
		int32_t L_21 = V_2;
		if ((((int32_t)L_21) >= ((int32_t)0)))
		{
			goto IL_008c;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = __this->____buckets;
		int32_t L_23 = V_1;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_24 = V_4;
		int32_t L_25 = V_5;
		NullCheck(L_24);
		int32_t L_26 = ((L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_25)))->___next;
		NullCheck(L_22);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(L_23), (int32_t)((int32_t)il2cpp_codegen_add(L_26, 1)));
		goto IL_00a7;
	}

IL_008c:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_27 = V_4;
		int32_t L_28 = V_2;
		NullCheck(L_27);
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_29 = V_4;
		int32_t L_30 = V_5;
		NullCheck(L_29);
		int32_t L_31 = ((L_29)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_30)))->___next;
		((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next = L_31;
	}

IL_00a7:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_32 = V_4;
		int32_t L_33 = V_5;
		NullCheck(L_32);
		((L_32)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_33)))->___hashCode = (-1);
	}
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_34 = V_4;
		int32_t L_35 = V_5;
		NullCheck(L_34);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69* L_36 = (ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69*)(&((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_35)))->___value);
		il2cpp_codegen_initobj(L_36, sizeof(ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69));
	}

IL_00d1:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_37 = V_4;
		int32_t L_38 = V_5;
		NullCheck(L_37);
		int32_t L_39 = __this->____freeList;
		((L_37)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_38)))->___next = L_39;
		int32_t L_40 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_subtract(L_40, 1));
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = __this->____count;
		if (L_42)
		{
			goto IL_0119;
		}
	}
	{
		__this->____lastIndex = 0;
		__this->____freeList = (-1);
		goto IL_0121;
	}

IL_0119:
	{
		int32_t L_43 = V_5;
		__this->____freeList = L_43;
	}

IL_0121:
	{
		return (bool)1;
	}

IL_0123:
	{
		int32_t L_44 = V_3;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_45 = V_4;
		NullCheck(L_45);
		int32_t L_46 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_45)->max_length),NULL));
		if ((((int32_t)L_44) < ((int32_t)L_46)))
		{
			goto IL_0135;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_47 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_47, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_47, method);
	}

IL_0135:
	{
		int32_t L_48 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_48, 1));
		int32_t L_49 = V_5;
		V_2 = L_49;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_50 = V_4;
		int32_t L_51 = V_5;
		NullCheck(L_50);
		int32_t L_52 = ((L_50)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_51)))->___next;
		V_5 = L_52;
	}

IL_014c:
	{
		int32_t L_53 = V_5;
		if ((((int32_t)L_53) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0154:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC HashSet_1_GetEnumerator_mCA52D8356647970F020C2CAFD4823DA324547BFD_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m486EC9E4B561CEAE79EE39104CC24E6064F21F0F((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 71577
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mDAE75872746AF1EE1A693297ABC36809877952EA_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m486EC9E4B561CEAE79EE39104CC24E6064F21F0F((&L_0), __this, NULL);
		Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71578
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_IEnumerable_GetEnumerator_m6ABC883977660C183AB5729BC76C90AEC66A484A_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m486EC9E4B561CEAE79EE39104CC24E6064F21F0F((&L_0), __this, NULL);
		Enumerator_t1EDD97E4638A8D6E1CE50C5872B9D0924198E7DC L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_GetObjectData_m61C08D175C084B5BA340D91F0C49C514FE37C285_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* V_0 = NULL;
	String_t* G_B4_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_1 = NULL;
	String_t* G_B3_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_1 = NULL;
	int32_t G_B5_0 = 0;
	String_t* G_B5_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		int32_t L_3 = __this->____version;
		NullCheck(L_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_2, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_3, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeObject* L_5 = __this->____comparer;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 27)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		NullCheck(L_4);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_4, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, (RuntimeObject*)L_5, L_7, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_8 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = __this->____buckets;
		if (!L_9)
		{
			G_B4_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
			G_B4_1 = L_8;
			goto IL_0052;
		}
		G_B3_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
		G_B3_1 = L_8;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		NullCheck(L_10);
		int32_t L_11 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_10)->max_length),NULL));
		G_B5_0 = L_11;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0053;
	}

IL_0052:
	{
		G_B5_0 = 0;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0053:
	{
		NullCheck(G_B5_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B5_2, G_B5_1, G_B5_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = __this->____buckets;
		if (!L_12)
		{
			goto IL_0089;
		}
	}
	{
		int32_t L_13 = __this->____count;
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_14 = (ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C*)(ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29), (uint32_t)L_13);
		V_0 = L_14;
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_15 = V_0;
		HashSet_1_CopyTo_m9BDEA1D1C55D8CE94C0A62F57F80C5C524634092(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_16 = ___0_info;
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_17 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		NullCheck(L_16);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_16, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, (RuntimeObject*)L_17, L_19, NULL);
	}

IL_0089:
	{
		return;
	}
}
// Method Definition Index: 71580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_OnDeserialization_mCDAE70A972410314F994CEACFE4014CD560F688E_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* V_1 = NULL;
	int32_t V_2 = 0;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = __this->____siInfo;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		return;
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = __this->____siInfo;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_1, _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865, NULL);
		V_0 = L_2;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 32)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		NullCheck(L_3);
		RuntimeObject* L_6;
		L_6 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_3, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20))));
		__this->____freeList = (-1);
		int32_t L_7 = V_0;
		if (!L_7)
		{
			goto IL_00ad;
		}
	}
	{
		int32_t L_8 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_8);
		__this->____buckets = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_9);
		int32_t L_10 = V_0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_11 = (SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)(SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_10);
		__this->____slots = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_11);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_12 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_13 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_14;
		L_14 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_13, NULL);
		NullCheck(L_12);
		RuntimeObject* L_15;
		L_15 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_12, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, L_14, NULL);
		V_1 = ((ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C*)CastclassSealed((RuntimeObject*)L_15, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29)));
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_16 = V_1;
		if (L_16)
		{
			goto IL_008f;
		}
	}
	{
		SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7* L_17 = (SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_il2cpp_TypeInfo_var)));
		SerializationException__ctor_m0AAFE2ABD0A74F3E783AD5B5FE842DE460168DB0(L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC5ABE84F2ABF009EBC68D2A32EF8C171B074F922)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_008f:
	{
		V_2 = 0;
		goto IL_00a5;
	}

IL_0093:
	{
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_18 = V_1;
		int32_t L_19 = V_2;
		NullCheck(L_18);
		int32_t L_20 = L_19;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_21 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_20));
		bool L_22;
		L_22 = HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74(__this, L_21, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_2;
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_25 = V_1;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((((int32_t)L_24) < ((int32_t)L_26)))
		{
			goto IL_0093;
		}
	}
	{
		goto IL_00b4;
	}

IL_00ad:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00b4:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_27 = __this->____siInfo;
		NullCheck(L_27);
		int32_t L_28;
		L_28 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_27, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		__this->____version = L_28;
		__this->____siInfo = (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____siInfo), (void*)(SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL);
		return;
	}
}
// Method Definition Index: 71581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Add_mAE3033F13EE78980ED4B45CF8455C47542C48178_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_1;
	}
}
// Method Definition Index: 71582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m72DE47E8E620210513B082CBA1E297529F2F784A_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_2);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_4 = V_0;
					if (!L_4)
					{
						goto IL_0039;
					}
				}
				{
					RuntimeObject* L_5 = V_0;
					NullCheck((RuntimeObject*)L_5);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_5);
				}

IL_0039:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_6 = V_0;
				NullCheck(L_6);
				ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_7;
				L_7 = InterfaceFuncInvoker0< ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_6);
				V_1 = L_7;
				ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_8 = V_1;
				bool L_9;
				L_9 = HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
			}

IL_0026_1:
			{
				RuntimeObject* L_10 = V_0;
				NullCheck((RuntimeObject*)L_10);
				bool L_11;
				L_11 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_10);
				if (L_11)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_003a;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003a:
	{
		return;
	}
}
// Method Definition Index: 71583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_SetEquals_m353610338964010EFD96760159AB60C4CB59BEEB_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		if ((!(((RuntimeObject*)(RuntimeObject*)L_2) == ((RuntimeObject*)(HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*)__this))))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)1;
	}

IL_0014:
	{
		RuntimeObject* L_3 = ___0_other;
		V_0 = ((HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_4 = V_0;
		if (!L_4)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m5D556866CC79848C93CBE9EA11913A938B7714E9(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_003f;
		}
	}
	{
		int32_t L_7 = __this->____count;
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = HashSet_1_get_Count_m5BEC231429D800AFD5D691C317D39991E78ED415_inline(L_8, NULL);
		if ((((int32_t)L_7) == ((int32_t)L_9)))
		{
			goto IL_0037;
		}
	}
	{
		return (bool)0;
	}

IL_0037:
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_10 = V_0;
		bool L_11;
		L_11 = HashSet_1_ContainsAllElements_m402E179A83E6B20C2C11DFF0562DB0F1C77A4E9B(__this, (RuntimeObject*)L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return L_11;
	}

IL_003f:
	{
		RuntimeObject* L_12 = ___0_other;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_13 = V_1;
		if (!L_13)
		{
			goto IL_005c;
		}
	}
	{
		int32_t L_14 = __this->____count;
		if (L_14)
		{
			goto IL_005c;
		}
	}
	{
		RuntimeObject* L_15 = V_1;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_15);
		if ((((int32_t)L_16) <= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}
	{
		return (bool)0;
	}

IL_005c:
	{
		RuntimeObject* L_17 = ___0_other;
		ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 L_18;
		L_18 = HashSet_1_CheckUniqueAndUnfoundElements_mCDDB1BEE21C233C8B06AC6C1D951FC0F3DF765BB(__this, L_17, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_2 = L_18;
		ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 L_19 = V_2;
		int32_t L_20 = L_19.___uniqueCount;
		int32_t L_21 = __this->____count;
		if ((!(((uint32_t)L_20) == ((uint32_t)L_21))))
		{
			goto IL_007d;
		}
	}
	{
		ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 L_22 = V_2;
		int32_t L_23 = L_22.___unfoundCount;
		return (bool)((((int32_t)L_23) == ((int32_t)0))? 1 : 0);
	}

IL_007d:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m9BDEA1D1C55D8CE94C0A62F57F80C5C524634092_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_0 = ___0_array;
		int32_t L_1 = __this->____count;
		HashSet_1_CopyTo_mFC04995DA22DA1C00773DA838F6BF5BD57386F08(__this, L_0, 0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71585
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mFC04995DA22DA1C00773DA838F6BF5BD57386F08_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_0 = ___0_array;
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
		int32_t L_2 = ___1_arrayIndex;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_3 = ___1_arrayIndex;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_6 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC00660333703C551EA80371B54D0ADCEB74C33B4)), L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0028:
	{
		int32_t L_7 = ___2_count;
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_0042;
		}
	}
	{
		int32_t L_8 = ___2_count;
		int32_t L_9 = L_8;
		RuntimeObject* L_10 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_9);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_11 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral07624473F417C06C74D59C64840A1532FCE2C626)), L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0042:
	{
		int32_t L_12 = ___1_arrayIndex;
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_13 = ___0_array;
		NullCheck(L_13);
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		if ((((int32_t)L_12) > ((int32_t)L_14)))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_15 = ___2_count;
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_16 = ___0_array;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = ___1_arrayIndex;
		if ((((int32_t)L_15) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18)))))
		{
			goto IL_005b;
		}
	}

IL_0050:
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_19 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_005b:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0097;
	}

IL_0061:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_20 = __this->____slots;
		int32_t L_21 = V_1;
		NullCheck(L_20);
		int32_t L_22 = ((L_20)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_21)))->___hashCode;
		if ((((int32_t)L_22) < ((int32_t)0)))
		{
			goto IL_0093;
		}
	}
	{
		ValueTuple_2U5BU5D_tF33B437F2A1E3ACE3B309C4A32BC53F5C9FB390C* L_23 = ___0_array;
		int32_t L_24 = ___1_arrayIndex;
		int32_t L_25 = V_0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_26 = __this->____slots;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_28 = ((L_26)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_27)))->___value;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_24, L_25))), (ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69)L_28);
		int32_t L_29 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0093:
	{
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_0097:
	{
		int32_t L_31 = V_1;
		int32_t L_32 = __this->____lastIndex;
		if ((((int32_t)L_31) >= ((int32_t)L_32)))
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___2_count;
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0061;
		}
	}

IL_00a4:
	{
		return;
	}
}
// Method Definition Index: 71586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_RemoveWhere_m0F8AD377D6D7CE66827BF70F8151983D9D2D54E0_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE2EEFB4BE0C9F57BA62E733F26387F8BA68AF67C)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0054;
	}

IL_0014:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_2 = __this->____slots;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = ((L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0050;
		}
	}
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_5 = __this->____slots;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_7 = ((L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		V_2 = L_7;
		Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08* L_8 = ___0_match;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_9 = V_2;
		NullCheck(L_8);
		bool L_10;
		L_10 = Predicate_1_Invoke_m94A03798DE3ED2CCEBF84727F779A9A09E2866D6_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0050;
		}
	}
	{
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_11 = V_2;
		bool L_12;
		L_12 = HashSet_1_Remove_m6B69D10A56A2048DDFBA6320F30C8A88474F0952(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		if (!L_12)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0050:
	{
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0054:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = __this->____lastIndex;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_17 = V_0;
		return L_17;
	}
}
// Method Definition Index: 71587
// Method Definition Index: 71588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m2C4EA13B68542A21E8981DD0E05F20466A088119_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_0025;
		}
	}
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
		__this->____slots = (SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)(SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)NULL);
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		return;
	}

IL_0025:
	{
		int32_t L_2 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_3;
		L_3 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_2, NULL);
		V_0 = L_3;
		int32_t L_4 = V_0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_5 = (SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)(SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		V_1 = L_5;
		int32_t L_6 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_2 = L_7;
		V_3 = 0;
		V_4 = 0;
		goto IL_00a2;
	}

IL_0046:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_8 = __this->____slots;
		int32_t L_9 = V_4;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_009c;
		}
	}
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_11 = V_1;
		int32_t L_12 = V_3;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_13 = __this->____slots;
		int32_t L_14 = V_4;
		NullCheck(L_13);
		int32_t L_15 = L_14;
		Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637 L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (Slot_tF7BC554020DED904D1B1A0E276A5AECD0BAC3637)L_16);
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_17 = V_1;
		int32_t L_18 = V_3;
		NullCheck(L_17);
		int32_t L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_0;
		V_5 = ((int32_t)(L_19%L_20));
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_21 = V_1;
		int32_t L_22 = V_3;
		NullCheck(L_21);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_2;
		int32_t L_24 = V_5;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		int32_t L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		((L_21)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_22)))->___next = ((int32_t)il2cpp_codegen_subtract(L_26, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = V_2;
		int32_t L_28 = V_5;
		int32_t L_29 = V_3;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)il2cpp_codegen_add(L_29, 1)));
		int32_t L_30 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_009c:
	{
		int32_t L_31 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_00a2:
	{
		int32_t L_32 = V_4;
		int32_t L_33 = __this->____lastIndex;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_34 = V_3;
		__this->____lastIndex = L_34;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_35 = V_1;
		__this->____slots = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_35);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_2;
		__this->____buckets = L_36;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_36);
		__this->____freeList = (-1);
		return;
	}
}
// Method Definition Index: 71589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_5 = (SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)(SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		__this->____slots = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 71590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_mD2206425C110AF13BF45E25072B54509B6A31FCB_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____count;
		if ((((int32_t)L_2) > ((int32_t)L_3)))
		{
			goto IL_0020;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral91930CCAB5CB8F6F327407F9A14CF42F57A0F27B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = V_0;
		HashSet_1_SetCapacity_mB5EC93ED1317A5C581250CEBF083ED19ACEC5680(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 71591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_mB5EC93ED1317A5C581250CEBF083ED19ACEC5680_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_newSize, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* V_0 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		int32_t L_0 = ___0_newSize;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_1 = (SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)(SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_0);
		V_0 = L_1;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_2 = __this->____slots;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_3 = __this->____slots;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_4 = V_0;
		int32_t L_5 = __this->____lastIndex;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, L_5, NULL);
	}

IL_0023:
	{
		int32_t L_6 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_1 = L_7;
		V_2 = 0;
		goto IL_0058;
	}

IL_002e:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_8 = V_0;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		int32_t L_11 = ___0_newSize;
		V_3 = ((int32_t)(L_10%L_11));
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_12 = V_0;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = V_1;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = L_15;
		int32_t L_17 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___next = ((int32_t)il2cpp_codegen_subtract(L_17, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_1;
		int32_t L_19 = V_3;
		int32_t L_20 = V_2;
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(L_19), (int32_t)((int32_t)il2cpp_codegen_add(L_20, 1)));
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_0058:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = __this->____lastIndex;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_002e;
		}
	}
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_24 = V_0;
		__this->____slots = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_24);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_25 = V_1;
		__this->____buckets = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_25);
		return;
	}
}
// Method Definition Index: 71592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_m39D9018FFBC75B3AED0F7D0CC273134414126D74_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1;
		L_1 = HashSet_1_Initialize_m96749721F83CA22878807246E520E3690436AD61(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0010:
	{
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_2 = ___0_value;
		int32_t L_3;
		L_3 = HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_3;
		int32_t L_4 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		V_1 = ((int32_t)(L_4%L_6));
		V_2 = 0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_7 = __this->____slots;
		V_3 = L_7;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		int32_t L_11 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		goto IL_008b;
	}

IL_003a:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_12 = V_3;
		int32_t L_13 = V_5;
		NullCheck(L_12);
		int32_t L_14 = ((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		int32_t L_15 = V_0;
		if ((!(((uint32_t)L_14) == ((uint32_t)L_15))))
		{
			goto IL_0067;
		}
	}
	{
		RuntimeObject* L_16 = __this->____comparer;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_17 = V_3;
		int32_t L_18 = V_5;
		NullCheck(L_17);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___value;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_20 = ___0_value;
		NullCheck(L_16);
		bool L_21;
		L_21 = InterfaceFuncInvoker2< bool, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_16, L_19, L_20);
		if (!L_21)
		{
			goto IL_0067;
		}
	}
	{
		return (bool)0;
	}

IL_0067:
	{
		int32_t L_22 = V_2;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_23 = V_3;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		if ((((int32_t)L_22) < ((int32_t)L_24)))
		{
			goto IL_0078;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_25 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_25, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_25, method);
	}

IL_0078:
	{
		int32_t L_26 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_27 = V_3;
		int32_t L_28 = V_5;
		NullCheck(L_27);
		int32_t L_29 = ((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_5 = L_29;
	}

IL_008b:
	{
		int32_t L_30 = V_5;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_31 = __this->____freeList;
		if ((((int32_t)L_31) < ((int32_t)0)))
		{
			goto IL_00b6;
		}
	}
	{
		int32_t L_32 = __this->____freeList;
		V_4 = L_32;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_33 = V_3;
		int32_t L_34 = V_4;
		NullCheck(L_33);
		int32_t L_35 = ((L_33)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_34)))->___next;
		__this->____freeList = L_35;
		goto IL_00ef;
	}

IL_00b6:
	{
		int32_t L_36 = __this->____lastIndex;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_37 = V_3;
		NullCheck(L_37);
		int32_t L_38 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_37)->max_length),NULL));
		if ((!(((uint32_t)L_36) == ((uint32_t)L_38))))
		{
			goto IL_00d9;
		}
	}
	{
		HashSet_1_IncreaseCapacity_mD2206425C110AF13BF45E25072B54509B6A31FCB(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_39 = __this->____slots;
		V_3 = L_39;
		int32_t L_40 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = __this->____buckets;
		NullCheck(L_41);
		int32_t L_42 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_41)->max_length),NULL));
		V_1 = ((int32_t)(L_40%L_42));
	}

IL_00d9:
	{
		int32_t L_43 = __this->____lastIndex;
		V_4 = L_43;
		int32_t L_44 = __this->____lastIndex;
		__this->____lastIndex = ((int32_t)il2cpp_codegen_add(L_44, 1));
	}

IL_00ef:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_45 = V_3;
		int32_t L_46 = V_4;
		NullCheck(L_45);
		int32_t L_47 = V_0;
		((L_45)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_46)))->___hashCode = L_47;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_48 = V_3;
		int32_t L_49 = V_4;
		NullCheck(L_48);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_50 = ___0_value;
		((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value = L_50;
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___Item2), (void*)NULL);
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_51 = V_3;
		int32_t L_52 = V_4;
		NullCheck(L_51);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_53 = __this->____buckets;
		int32_t L_54 = V_1;
		NullCheck(L_53);
		int32_t L_55 = L_54;
		int32_t L_56 = (L_53)->GetAt(static_cast<il2cpp_array_size_t>(L_55));
		((L_51)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_52)))->___next = ((int32_t)il2cpp_codegen_subtract(L_56, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = __this->____buckets;
		int32_t L_58 = V_1;
		int32_t L_59 = V_4;
		NullCheck(L_57);
		(L_57)->SetAt(static_cast<il2cpp_array_size_t>(L_58), (int32_t)((int32_t)il2cpp_codegen_add(L_59, 1)));
		int32_t L_60 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_60, 1));
		int32_t L_61 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_61, 1));
		return (bool)1;
	}
}
// Method Definition Index: 71593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m6416C7AB136F0AA15420624327EE27778D5A830A_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, int32_t ___0_index, int32_t ___1_hashCode, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_hashCode;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		V_0 = ((int32_t)(L_0%L_2));
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_3 = __this->____slots;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = ___1_hashCode;
		((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)))->___hashCode = L_5;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_6 = __this->____slots;
		int32_t L_7 = ___0_index;
		NullCheck(L_6);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_8 = ___2_value;
		((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value = L_8;
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___Item2), (void*)NULL);
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_9 = __this->____slots;
		int32_t L_10 = ___0_index;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___next = ((int32_t)il2cpp_codegen_subtract(L_14, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = __this->____buckets;
		int32_t L_16 = V_0;
		int32_t L_17 = ___0_index;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(L_16), (int32_t)((int32_t)il2cpp_codegen_add(L_17, 1)));
		return;
	}
}
// Method Definition Index: 71594
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m402E179A83E6B20C2C11DFF0562DB0F1C77A4E9B_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	{
		RuntimeObject* L_0 = ___0_other;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_0030;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck((RuntimeObject*)L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_3);
				}

IL_0030:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_5;
				L_5 = InterfaceFuncInvoker0< ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_4);
				V_1 = L_5;
				ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_6 = V_1;
				bool L_7;
				L_7 = HashSet_1_Contains_mC8707235E125D21EF8B82C07F7DF31501E7EDCFB(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
				if (L_7)
				{
					goto IL_001d_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0033;
			}

IL_001d_1:
			{
				RuntimeObject* L_8 = V_0;
				NullCheck((RuntimeObject*)L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_8);
				if (L_9)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0031;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0031:
	{
		return (bool)1;
	}

IL_0033:
	{
		bool L_10 = V_2;
		return L_10;
	}
}
// Method Definition Index: 71595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m7E77CEB0BDFF8900C4DEAA7A5E1E21DDB52F3BEF_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* V_2 = NULL;
	int32_t V_3 = 0;
	{
		V_0 = 0;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_0 = ___0_item;
		int32_t L_1;
		L_1 = HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_1;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_2 = __this->____slots;
		V_2 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = __this->____buckets;
		int32_t L_4 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NullCheck(L_3);
		int32_t L_7 = ((int32_t)(L_4%L_6));
		int32_t L_8 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		goto IL_0074;
	}

IL_0027:
	{
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_9 = V_2;
		int32_t L_10 = V_3;
		NullCheck(L_9);
		int32_t L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___hashCode;
		int32_t L_12 = V_1;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_12))))
		{
			goto IL_0052;
		}
	}
	{
		RuntimeObject* L_13 = __this->____comparer;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_14 = V_2;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_16 = ((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)))->___value;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_17 = ___0_item;
		NullCheck(L_13);
		bool L_18;
		L_18 = InterfaceFuncInvoker2< bool, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_13, L_16, L_17);
		if (!L_18)
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_19 = V_3;
		return L_19;
	}

IL_0052:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_0063;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_0063:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tF3058D6C608D0404043E2F300E311C8CC89956D3* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_0074:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_0027;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 71596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 HashSet_1_CheckUniqueAndUnfoundElements_mCDDB1BEE21C233C8B06AC6C1D951FC0F3DF765BB_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	RuntimeObject* V_6 = NULL;
	ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 V_7;
	memset((&V_7), 0, sizeof(V_7));
	int32_t V_8 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_004f;
		}
	}
	{
		V_5 = 0;
		RuntimeObject* L_1 = ___0_other;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_1);
		V_6 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_3 = V_6;
					if (!L_3)
					{
						goto IL_003b;
					}
				}
				{
					RuntimeObject* L_4 = V_6;
					NullCheck((RuntimeObject*)L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_4);
				}

IL_003b:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0025_1;
			}

IL_0015_1:
			{
				RuntimeObject* L_5 = V_6;
				NullCheck(L_5);
				ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_6;
				L_6 = InterfaceFuncInvoker0< ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_5);
				int32_t L_7 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_7, 1));
				goto IL_003c;
			}

IL_0025_1:
			{
				RuntimeObject* L_8 = V_6;
				NullCheck((RuntimeObject*)L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_8);
				if (L_9)
				{
					goto IL_0015_1;
				}
			}
			{
				goto IL_003c;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003c:
	{
		(&V_0)->___uniqueCount = 0;
		int32_t L_10 = V_5;
		(&V_0)->___unfoundCount = L_10;
		ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 L_11 = V_0;
		return L_11;
	}

IL_004f:
	{
		int32_t L_12 = __this->____lastIndex;
		int32_t L_13;
		L_13 = BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C(L_12, NULL);
		V_1 = L_13;
		int32_t L_14 = V_1;
		if ((((int32_t)L_14) > ((int32_t)((int32_t)100))))
		{
			goto IL_006f;
		}
	}
	{
		int32_t L_15 = V_1;
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		if ((uintptr_t)L_16 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_17 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_16, 4));
		int8_t* L_18;
		if (L_17 == 0)
		{
			L_18 = NULL;
		}
		else
		{
			L_18 = (int8_t*)alloca(L_17);
			memset(L_18, 0, L_17);
		}
		int32_t L_19 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_20 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3(L_20, (int32_t*)L_18, L_19, NULL);
		V_2 = L_20;
		goto IL_007c;
	}

IL_006f:
	{
		int32_t L_21 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_21);
		int32_t L_23 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_24 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19(L_24, L_22, L_23, NULL);
		V_2 = L_24;
	}

IL_007c:
	{
		V_3 = 0;
		V_4 = 0;
		RuntimeObject* L_25 = ___0_other;
		NullCheck(L_25);
		RuntimeObject* L_26;
		L_26 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_25);
		V_6 = L_26;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d1:
			{
				{
					RuntimeObject* L_27 = V_6;
					if (!L_27)
					{
						goto IL_00dc;
					}
				}
				{
					RuntimeObject* L_28 = V_6;
					NullCheck((RuntimeObject*)L_28);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_28);
				}

IL_00dc:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00c6_1;
			}

IL_008b_1:
			{
				RuntimeObject* L_29 = V_6;
				NullCheck(L_29);
				ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_30;
				L_30 = InterfaceFuncInvoker0< ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_29);
				V_7 = L_30;
				ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_31 = V_7;
				int32_t L_32;
				L_32 = HashSet_1_InternalIndexOf_m7E77CEB0BDFF8900C4DEAA7A5E1E21DDB52F3BEF(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
				V_8 = L_32;
				int32_t L_33 = V_8;
				if ((((int32_t)L_33) < ((int32_t)0)))
				{
					goto IL_00bd_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_34 = V_2;
				int32_t L_35 = V_8;
				NullCheck(L_34);
				bool L_36;
				L_36 = BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2(L_34, L_35, NULL);
				if (L_36)
				{
					goto IL_00c6_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_37 = V_2;
				int32_t L_38 = V_8;
				NullCheck(L_37);
				BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86(L_37, L_38, NULL);
				int32_t L_39 = V_4;
				V_4 = ((int32_t)il2cpp_codegen_add(L_39, 1));
				goto IL_00c6_1;
			}

IL_00bd_1:
			{
				int32_t L_40 = V_3;
				V_3 = ((int32_t)il2cpp_codegen_add(L_40, 1));
				bool L_41 = ___1_returnIfUnfound;
				if (!L_41)
				{
					goto IL_00c6_1;
				}
			}
			{
				goto IL_00dd;
			}

IL_00c6_1:
			{
				RuntimeObject* L_42 = V_6;
				NullCheck((RuntimeObject*)L_42);
				bool L_43;
				L_43 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_42);
				if (L_43)
				{
					goto IL_008b_1;
				}
			}
			{
				goto IL_00dd;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00dd:
	{
		int32_t L_44 = V_4;
		(&V_0)->___uniqueCount = L_44;
		int32_t L_45 = V_3;
		(&V_0)->___unfoundCount = L_45;
		ElementCount_t88C411D310F29FE91F6FFD283F14156137C1D033 L_46 = V_0;
		return L_46;
	}
}
// Method Definition Index: 71597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m5D556866CC79848C93CBE9EA11913A938B7714E9_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___0_set1, HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* ___1_set2, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_0 = ___0_set1;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = HashSet_1_get_Comparer_m80A6402575D85864B54FC22D2F4DC295D24349DE_inline(L_0, NULL);
		HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* L_2 = ___1_set2;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = HashSet_1_get_Comparer_m80A6402575D85864B54FC22D2F4DC295D24349DE_inline(L_2, NULL);
		NullCheck((RuntimeObject*)L_1);
		bool L_4;
		L_4 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, (RuntimeObject*)L_1, (RuntimeObject*)L_3);
		return L_4;
	}
}
// Method Definition Index: 71598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m8D311F3A95546DB384DFAE5F216C2053D4AC0DD7_gshared (HashSet_1_t6060A1D985F1AF4B0F6D1B3E0605FBE5475895D1* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000a;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____comparer;
		ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 L_2 = ___0_item;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_1, L_2);
		return ((int32_t)(L_3&((int32_t)2147483647LL)));
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
// Method Definition Index: 71561
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m94FE79F7F3B495C525ADEACFE755A72F5B839629 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_0;
		L_0 = EqualityComparer_1_get_Default_m16781A8E4EDB2114168E318B51C5081028E57F3D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m243CD293A2127B3FAE419703CC89640A6F570E28(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return;
	}
}
// Method Definition Index: 71562
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m243CD293A2127B3FAE419703CC89640A6F570E28 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_comparer;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_1;
		L_1 = EqualityComparer_1_get_Default_m16781A8E4EDB2114168E318B51C5081028E57F3D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		___0_comparer = L_1;
	}

IL_0010:
	{
		RuntimeObject* L_2 = ___0_comparer;
		__this->____comparer = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_2);
		__this->____lastIndex = 0;
		__this->____count = 0;
		__this->____freeList = (-1);
		__this->____version = 0;
		return;
	}
}
// Method Definition Index: 71563
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mC112E55E58FC5D7CD86F728FFCFF8DCD111B225F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_1;
		L_1 = EqualityComparer_1_get_Default_m16781A8E4EDB2114168E318B51C5081028E57F3D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mA9B40FD1D35748AA889DF20A2045FF6FDF153B5F(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 71564
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mB3721A2F8570649CC2D6F7CD106CF4394458E428 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_collection;
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_1;
		L_1 = EqualityComparer_1_get_Default_m16781A8E4EDB2114168E318B51C5081028E57F3D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m884A133C560BC45033194B8F8B72BEB5C1ECD001(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
// Method Definition Index: 71565
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m884A133C560BC45033194B8F8B72BEB5C1ECD001 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B8_0 = 0;
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_m243CD293A2127B3FAE419703CC89640A6F570E28(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		RuntimeObject* L_1 = ___0_collection;
		if (L_1)
		{
			goto IL_0015;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral469F05BE9BB4C7903C353D0EB9F6384C84A48B25)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0015:
	{
		RuntimeObject* L_3 = ___0_collection;
		V_0 = ((HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_4 = V_0;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m745C3AA0C82ABD3EACFE9AD11FB39B801138F98F(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_7 = V_0;
		HashSet_1_CopyFrom_mFED69AC25A7BEEFA40379F9BFEE13A78C6A733F9(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return;
	}

IL_0030:
	{
		RuntimeObject* L_8 = ___0_collection;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_9 = V_1;
		if (!L_9)
		{
			goto IL_0042;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_10);
		G_B8_0 = L_11;
		goto IL_0043;
	}

IL_0042:
	{
		G_B8_0 = 0;
	}

IL_0043:
	{
		V_2 = G_B8_0;
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = HashSet_1_Initialize_m9F38BC09C26BE8AB8CD88B95B5D9BF5596333949(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		RuntimeObject* L_14 = ___0_collection;
		HashSet_1_UnionWith_mA664CEC5ECB3F67F7A34810662A0A8EA5B05E0F4(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		int32_t L_15 = __this->____count;
		if ((((int32_t)L_15) <= ((int32_t)0)))
		{
			goto IL_0074;
		}
	}
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_16 = __this->____slots;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = __this->____count;
		if ((((int32_t)((int32_t)(L_17/L_18))) <= ((int32_t)3)))
		{
			goto IL_0074;
		}
	}
	{
		HashSet_1_TrimExcess_m90BF44FD415BD8D59609DFCE9A93FDA2AF29F14E(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}

IL_0074:
	{
		return;
	}
}
// Method Definition Index: 71566
// Method Definition Index: 71567
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_mFED69AC25A7BEEFA40379F9BFEE13A78C6A733F9 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_0 = ___0_source;
		NullCheck(L_0);
		int32_t L_1 = L_0->____count;
		V_0 = L_1;
		int32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_000b;
		}
	}
	{
		return;
	}

IL_000b:
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_3 = ___0_source;
		NullCheck(L_3);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = L_3->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = L_5;
		int32_t L_6 = V_0;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(((int32_t)il2cpp_codegen_add(L_6, 1)), NULL);
		int32_t L_8 = V_1;
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0065;
		}
	}
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_9 = ___0_source;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = L_9->____buckets;
		NullCheck((RuntimeArray*)L_10);
		RuntimeObject* L_11;
		L_11 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_10, NULL);
		__this->____buckets = ((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var)));
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_12 = ___0_source;
		NullCheck(L_12);
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_13 = L_12->____slots;
		NullCheck((RuntimeArray*)L_13);
		RuntimeObject* L_14;
		L_14 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_13, NULL);
		__this->____slots = ((SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)((SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))));
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_15 = ___0_source;
		NullCheck(L_15);
		int32_t L_16 = L_15->____lastIndex;
		__this->____lastIndex = L_16;
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_17 = ___0_source;
		NullCheck(L_17);
		int32_t L_18 = L_17->____freeList;
		__this->____freeList = L_18;
		goto IL_00c7;
	}

IL_0065:
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_19 = ___0_source;
		NullCheck(L_19);
		int32_t L_20 = L_19->____lastIndex;
		V_2 = L_20;
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_21 = ___0_source;
		NullCheck(L_21);
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_22 = L_21->____slots;
		V_3 = L_22;
		int32_t L_23 = V_0;
		int32_t L_24;
		L_24 = HashSet_1_Initialize_m9F38BC09C26BE8AB8CD88B95B5D9BF5596333949(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		V_4 = 0;
		V_5 = 0;
		goto IL_00ba;
	}

IL_0083:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_25 = V_3;
		int32_t L_26 = V_5;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		V_6 = L_27;
		int32_t L_28 = V_6;
		if ((((int32_t)L_28) < ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		int32_t L_29 = V_4;
		int32_t L_30 = V_6;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_31 = V_3;
		int32_t L_32 = V_5;
		NullCheck(L_31);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_33 = ((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->___value;
		HashSet_1_AddValue_mA51FE1D72D825FC764AA4ED6C347ACD2CAF61E4C(__this, L_29, L_30, L_33, NULL);
		int32_t L_34 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b4:
	{
		int32_t L_35 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_35, 1));
	}

IL_00ba:
	{
		int32_t L_36 = V_5;
		int32_t L_37 = V_2;
		if ((((int32_t)L_36) < ((int32_t)L_37)))
		{
			goto IL_0083;
		}
	}
	{
		int32_t L_38 = V_4;
		__this->____lastIndex = L_38;
	}

IL_00c7:
	{
		int32_t L_39 = V_0;
		__this->____count = L_39;
		return;
	}
}
// Method Definition Index: 71568
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA9B40FD1D35748AA889DF20A2045FF6FDF153B5F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_m243CD293A2127B3FAE419703CC89640A6F570E28(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0016;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0016:
	{
		int32_t L_3 = ___0_capacity;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = HashSet_1_Initialize_m9F38BC09C26BE8AB8CD88B95B5D9BF5596333949(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0022:
	{
		return;
	}
}
// Method Definition Index: 71569
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_System_Collections_Generic_ICollectionU3CTU3E_Add_m9F7F84D9E2C82BD4CCD11BD61A390710B4BEE78F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mAF5149C72B493BC5D95BE4EC13A429A05773FFF6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return;
	}
}
// Method Definition Index: 71570
// Method Definition Index: 71571
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m4F9D37448BAEF8FE526453CB58B1EF11EB5D5C8C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* V_2 = NULL;
	int32_t V_3 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0080;
		}
	}
	{
		V_0 = 0;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m38217C0101E1F461019404AAF3395993EB1CF941(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_2;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_3 = __this->____slots;
		V_2 = L_3;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		int32_t L_5 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->____buckets;
		NullCheck(L_6);
		int32_t L_7 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_6)->max_length),NULL));
		NullCheck(L_4);
		int32_t L_8 = ((int32_t)(L_5%L_7));
		int32_t L_9 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_9, 1));
		goto IL_007c;
	}

IL_002f:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_10 = V_2;
		int32_t L_11 = V_3;
		NullCheck(L_10);
		int32_t L_12 = ((L_10)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		int32_t L_13 = V_1;
		if ((!(((uint32_t)L_12) == ((uint32_t)L_13))))
		{
			goto IL_005a;
		}
	}
	{
		RuntimeObject* L_14 = __this->____comparer;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_15 = V_2;
		int32_t L_16 = V_3;
		NullCheck(L_15);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_17 = ((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)))->___value;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_18 = ___0_item;
		NullCheck(L_14);
		bool L_19;
		L_19 = InterfaceFuncInvoker2< bool, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_14, L_17, L_18);
		if (!L_19)
		{
			goto IL_005a;
		}
	}
	{
		return (bool)1;
	}

IL_005a:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_006b;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_006b:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_007c:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_002f;
		}
	}

IL_0080:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71572
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m9ED20C49B157A3B6F47ED942167D9EC839EA572E (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_0 = ___0_array;
		int32_t L_1 = ___1_arrayIndex;
		int32_t L_2 = __this->____count;
		HashSet_1_CopyTo_m04CB2B4FC5D114776861F1B52AF0F57CBAE649D1(__this, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71573
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m4C39EA4316F83D39009A5EBE10E207279EAC85EA (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* V_4 = NULL;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0154;
		}
	}
	{
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m38217C0101E1F461019404AAF3395993EB1CF941(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_2;
		int32_t L_3 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = ((int32_t)(L_3%L_5));
		V_2 = (-1);
		V_3 = 0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_6 = __this->____slots;
		V_4 = L_6;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		int32_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
		goto IL_014c;
	}

IL_003b:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_11 = V_4;
		int32_t L_12 = V_5;
		NullCheck(L_11);
		int32_t L_13 = ((L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_12)))->___hashCode;
		int32_t L_14 = V_0;
		if ((!(((uint32_t)L_13) == ((uint32_t)L_14))))
		{
			goto IL_0123;
		}
	}
	{
		RuntimeObject* L_15 = __this->____comparer;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_16 = V_4;
		int32_t L_17 = V_5;
		NullCheck(L_16);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_18 = ((L_16)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_19 = ___0_item;
		NullCheck(L_15);
		bool L_20;
		L_20 = InterfaceFuncInvoker2< bool, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0123;
		}
	}
	{
		int32_t L_21 = V_2;
		if ((((int32_t)L_21) >= ((int32_t)0)))
		{
			goto IL_008c;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = __this->____buckets;
		int32_t L_23 = V_1;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_24 = V_4;
		int32_t L_25 = V_5;
		NullCheck(L_24);
		int32_t L_26 = ((L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_25)))->___next;
		NullCheck(L_22);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(L_23), (int32_t)((int32_t)il2cpp_codegen_add(L_26, 1)));
		goto IL_00a7;
	}

IL_008c:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_27 = V_4;
		int32_t L_28 = V_2;
		NullCheck(L_27);
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_29 = V_4;
		int32_t L_30 = V_5;
		NullCheck(L_29);
		int32_t L_31 = ((L_29)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_30)))->___next;
		((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next = L_31;
	}

IL_00a7:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_32 = V_4;
		int32_t L_33 = V_5;
		NullCheck(L_32);
		((L_32)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_33)))->___hashCode = (-1);
		goto IL_00d1;
	}

IL_00d1:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_34 = V_4;
		int32_t L_35 = V_5;
		NullCheck(L_34);
		int32_t L_36 = __this->____freeList;
		((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_35)))->___next = L_36;
		int32_t L_37 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_subtract(L_37, 1));
		int32_t L_38 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_38, 1));
		int32_t L_39 = __this->____count;
		if (L_39)
		{
			goto IL_0119;
		}
	}
	{
		__this->____lastIndex = 0;
		__this->____freeList = (-1);
		goto IL_0121;
	}

IL_0119:
	{
		int32_t L_40 = V_5;
		__this->____freeList = L_40;
	}

IL_0121:
	{
		return (bool)1;
	}

IL_0123:
	{
		int32_t L_41 = V_3;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_42 = V_4;
		NullCheck(L_42);
		int32_t L_43 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_42)->max_length),NULL));
		if ((((int32_t)L_41) < ((int32_t)L_43)))
		{
			goto IL_0135;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_44 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_0135:
	{
		int32_t L_45 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_45, 1));
		int32_t L_46 = V_5;
		V_2 = L_46;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_47 = V_4;
		int32_t L_48 = V_5;
		NullCheck(L_47);
		int32_t L_49 = ((L_47)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_48)))->___next;
		V_5 = L_49;
	}

IL_014c:
	{
		int32_t L_50 = V_5;
		if ((((int32_t)L_50) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0154:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C HashSet_1_GetEnumerator_mA4808824813A48093808F9E8D47320EF97FCF307 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m72FD8FF16B6F691518A0FBE35F111468EA68A558((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 71577
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m6ED57D3D9FD7CF4F007765789D263D887FD8ABFA (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m72FD8FF16B6F691518A0FBE35F111468EA68A558((&L_0), __this, NULL);
		Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71578
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_IEnumerable_GetEnumerator_m950C73885284246F528155E290F1CD17B1987CBC (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m72FD8FF16B6F691518A0FBE35F111468EA68A558((&L_0), __this, NULL);
		Enumerator_tEF6E35B89BE9A9D5D970471AB655B2DF7CF2E44C L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_GetObjectData_m51F9FD2A7980F28A8D0736B33606186F020C8CDD (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* V_0 = NULL;
	String_t* G_B4_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_1 = NULL;
	String_t* G_B3_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_1 = NULL;
	int32_t G_B5_0 = 0;
	String_t* G_B5_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		int32_t L_3 = __this->____version;
		NullCheck(L_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_2, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_3, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeObject* L_5 = __this->____comparer;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 27)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		NullCheck(L_4);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_4, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, L_7, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_8 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = __this->____buckets;
		if (!L_9)
		{
			G_B4_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
			G_B4_1 = L_8;
			goto IL_0052;
		}
		G_B3_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
		G_B3_1 = L_8;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		NullCheck(L_10);
		int32_t L_11 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_10)->max_length),NULL));
		G_B5_0 = L_11;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0053;
	}

IL_0052:
	{
		G_B5_0 = 0;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0053:
	{
		NullCheck(G_B5_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B5_2, G_B5_1, G_B5_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = __this->____buckets;
		if (!L_12)
		{
			goto IL_0089;
		}
	}
	{
		int32_t L_13 = __this->____count;
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_14 = (EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9*)(EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29), (uint32_t)L_13);
		V_0 = L_14;
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_15 = V_0;
		HashSet_1_CopyTo_mE58E698435830C5C358B353C4399919DC77F0D6C(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_16 = ___0_info;
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_17 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		NullCheck(L_16);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_16, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, (RuntimeObject*)L_17, L_19, NULL);
	}

IL_0089:
	{
		return;
	}
}
// Method Definition Index: 71580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_OnDeserialization_m5AE955C33A6B3ABC706BE0D82C462B63CC36820E (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* V_1 = NULL;
	int32_t V_2 = 0;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = __this->____siInfo;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		return;
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = __this->____siInfo;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_1, _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865, NULL);
		V_0 = L_2;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 32)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		NullCheck(L_3);
		RuntimeObject* L_6;
		L_6 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_3, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20))));
		__this->____freeList = (-1);
		int32_t L_7 = V_0;
		if (!L_7)
		{
			goto IL_00ad;
		}
	}
	{
		int32_t L_8 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_8);
		__this->____buckets = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_9);
		int32_t L_10 = V_0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_11 = (SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)(SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_10);
		__this->____slots = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_11);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_12 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_13 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_14;
		L_14 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_13, NULL);
		NullCheck(L_12);
		RuntimeObject* L_15;
		L_15 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_12, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, L_14, NULL);
		V_1 = ((EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9*)CastclassSealed((RuntimeObject*)L_15, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29)));
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_16 = V_1;
		if (L_16)
		{
			goto IL_008f;
		}
	}
	{
		SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7* L_17 = (SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_il2cpp_TypeInfo_var)));
		SerializationException__ctor_m0AAFE2ABD0A74F3E783AD5B5FE842DE460168DB0(L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC5ABE84F2ABF009EBC68D2A32EF8C171B074F922)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_008f:
	{
		V_2 = 0;
		goto IL_00a5;
	}

IL_0093:
	{
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_18 = V_1;
		int32_t L_19 = V_2;
		NullCheck(L_18);
		int32_t L_20 = L_19;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_21 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_20));
		bool L_22;
		L_22 = HashSet_1_AddIfNotPresent_mAF5149C72B493BC5D95BE4EC13A429A05773FFF6(__this, L_21, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_2;
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_25 = V_1;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((((int32_t)L_24) < ((int32_t)L_26)))
		{
			goto IL_0093;
		}
	}
	{
		goto IL_00b4;
	}

IL_00ad:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00b4:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_27 = __this->____siInfo;
		NullCheck(L_27);
		int32_t L_28;
		L_28 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_27, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		__this->____version = L_28;
		__this->____siInfo = (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____siInfo), (void*)(SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL);
		return;
	}
}
// Method Definition Index: 71581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Add_mEF2032E85A90C5A9FE2E025C342CA259A5399F16 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mAF5149C72B493BC5D95BE4EC13A429A05773FFF6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_1;
	}
}
// Method Definition Index: 71582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mA664CEC5ECB3F67F7A34810662A0A8EA5B05E0F4 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_2);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_4 = V_0;
					if (!L_4)
					{
						goto IL_0039;
					}
				}
				{
					RuntimeObject* L_5 = V_0;
					NullCheck(L_5);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
				}

IL_0039:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_6 = V_0;
				NullCheck(L_6);
				EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_7;
				L_7 = InterfaceFuncInvoker0< EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_6);
				V_1 = L_7;
				EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_8 = V_1;
				bool L_9;
				L_9 = HashSet_1_AddIfNotPresent_mAF5149C72B493BC5D95BE4EC13A429A05773FFF6(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
			}

IL_0026_1:
			{
				RuntimeObject* L_10 = V_0;
				NullCheck(L_10);
				bool L_11;
				L_11 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_10);
				if (L_11)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_003a;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003a:
	{
		return;
	}
}
// Method Definition Index: 71583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_SetEquals_m017CB77DF9C6DA93B5757ADBC87B77D8B22F12AA (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		if ((!(((RuntimeObject*)(RuntimeObject*)L_2) == ((RuntimeObject*)(HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB*)__this))))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)1;
	}

IL_0014:
	{
		RuntimeObject* L_3 = ___0_other;
		V_0 = ((HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_4 = V_0;
		if (!L_4)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m745C3AA0C82ABD3EACFE9AD11FB39B801138F98F(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_003f;
		}
	}
	{
		int32_t L_7 = __this->____count;
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = HashSet_1_get_Count_mF365E179072ED1AEFA61D53FE7638C3BE82A2104_inline(L_8, NULL);
		if ((((int32_t)L_7) == ((int32_t)L_9)))
		{
			goto IL_0037;
		}
	}
	{
		return (bool)0;
	}

IL_0037:
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_10 = V_0;
		bool L_11;
		L_11 = HashSet_1_ContainsAllElements_mB976C7D04D778F1FB1639F6E23FABA39C2EF175F(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return L_11;
	}

IL_003f:
	{
		RuntimeObject* L_12 = ___0_other;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_13 = V_1;
		if (!L_13)
		{
			goto IL_005c;
		}
	}
	{
		int32_t L_14 = __this->____count;
		if (L_14)
		{
			goto IL_005c;
		}
	}
	{
		RuntimeObject* L_15 = V_1;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_15);
		if ((((int32_t)L_16) <= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}
	{
		return (bool)0;
	}

IL_005c:
	{
		RuntimeObject* L_17 = ___0_other;
		ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA L_18;
		L_18 = HashSet_1_CheckUniqueAndUnfoundElements_mD12B1A14A687B718C5D814FA14C404D3F328BF0D(__this, L_17, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_2 = L_18;
		ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA L_19 = V_2;
		int32_t L_20 = L_19.___uniqueCount;
		int32_t L_21 = __this->____count;
		if ((!(((uint32_t)L_20) == ((uint32_t)L_21))))
		{
			goto IL_007d;
		}
	}
	{
		ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA L_22 = V_2;
		int32_t L_23 = L_22.___unfoundCount;
		return (bool)((((int32_t)L_23) == ((int32_t)0))? 1 : 0);
	}

IL_007d:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mE58E698435830C5C358B353C4399919DC77F0D6C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_0 = ___0_array;
		int32_t L_1 = __this->____count;
		HashSet_1_CopyTo_m04CB2B4FC5D114776861F1B52AF0F57CBAE649D1(__this, L_0, 0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71585
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m04CB2B4FC5D114776861F1B52AF0F57CBAE649D1 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_0 = ___0_array;
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
		int32_t L_2 = ___1_arrayIndex;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_3 = ___1_arrayIndex;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_6 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC00660333703C551EA80371B54D0ADCEB74C33B4)), L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0028:
	{
		int32_t L_7 = ___2_count;
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_0042;
		}
	}
	{
		int32_t L_8 = ___2_count;
		int32_t L_9 = L_8;
		RuntimeObject* L_10 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_9);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_11 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral07624473F417C06C74D59C64840A1532FCE2C626)), L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0042:
	{
		int32_t L_12 = ___1_arrayIndex;
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_13 = ___0_array;
		NullCheck(L_13);
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		if ((((int32_t)L_12) > ((int32_t)L_14)))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_15 = ___2_count;
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_16 = ___0_array;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = ___1_arrayIndex;
		if ((((int32_t)L_15) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18)))))
		{
			goto IL_005b;
		}
	}

IL_0050:
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_19 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_005b:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0097;
	}

IL_0061:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_20 = __this->____slots;
		int32_t L_21 = V_1;
		NullCheck(L_20);
		int32_t L_22 = ((L_20)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_21)))->___hashCode;
		if ((((int32_t)L_22) < ((int32_t)0)))
		{
			goto IL_0093;
		}
	}
	{
		EntityIdU5BU5D_t8A607D0FD754ABFC6D83D6B358F75FEE0F9B6FB9* L_23 = ___0_array;
		int32_t L_24 = ___1_arrayIndex;
		int32_t L_25 = V_0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_26 = __this->____slots;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_28 = ((L_26)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_27)))->___value;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_24, L_25))), (EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8)L_28);
		int32_t L_29 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0093:
	{
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_0097:
	{
		int32_t L_31 = V_1;
		int32_t L_32 = __this->____lastIndex;
		if ((((int32_t)L_31) >= ((int32_t)L_32)))
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___2_count;
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0061;
		}
	}

IL_00a4:
	{
		return;
	}
}
// Method Definition Index: 71586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_RemoveWhere_mDF56CE4D67168BAA79739E2EDEBF5DEEE093785E (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE2EEFB4BE0C9F57BA62E733F26387F8BA68AF67C)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0054;
	}

IL_0014:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_2 = __this->____slots;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = ((L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0050;
		}
	}
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_5 = __this->____slots;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_7 = ((L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		V_2 = L_7;
		Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B* L_8 = ___0_match;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_9 = V_2;
		NullCheck(L_8);
		bool L_10;
		L_10 = Predicate_1_Invoke_m2F110E2073E6471BD12C32F8EA63B0673BEFB275_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0050;
		}
	}
	{
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_11 = V_2;
		bool L_12;
		L_12 = HashSet_1_Remove_m4C39EA4316F83D39009A5EBE10E207279EAC85EA(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		if (!L_12)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0050:
	{
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0054:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = __this->____lastIndex;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_17 = V_0;
		return L_17;
	}
}
// Method Definition Index: 71587
// Method Definition Index: 71588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m90BF44FD415BD8D59609DFCE9A93FDA2AF29F14E (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_0025;
		}
	}
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
		__this->____slots = (SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)(SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)NULL);
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		return;
	}

IL_0025:
	{
		int32_t L_2 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_3;
		L_3 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_2, NULL);
		V_0 = L_3;
		int32_t L_4 = V_0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_5 = (SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)(SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		V_1 = L_5;
		int32_t L_6 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_2 = L_7;
		V_3 = 0;
		V_4 = 0;
		goto IL_00a2;
	}

IL_0046:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_8 = __this->____slots;
		int32_t L_9 = V_4;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_009c;
		}
	}
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_11 = V_1;
		int32_t L_12 = V_3;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_13 = __this->____slots;
		int32_t L_14 = V_4;
		NullCheck(L_13);
		int32_t L_15 = L_14;
		Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (Slot_t864090C53F16AB23F10CD5181950BF6DFE61B3BB)L_16);
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_17 = V_1;
		int32_t L_18 = V_3;
		NullCheck(L_17);
		int32_t L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_0;
		V_5 = ((int32_t)(L_19%L_20));
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_21 = V_1;
		int32_t L_22 = V_3;
		NullCheck(L_21);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_2;
		int32_t L_24 = V_5;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		int32_t L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		((L_21)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_22)))->___next = ((int32_t)il2cpp_codegen_subtract(L_26, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = V_2;
		int32_t L_28 = V_5;
		int32_t L_29 = V_3;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)il2cpp_codegen_add(L_29, 1)));
		int32_t L_30 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_009c:
	{
		int32_t L_31 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_00a2:
	{
		int32_t L_32 = V_4;
		int32_t L_33 = __this->____lastIndex;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_34 = V_3;
		__this->____lastIndex = L_34;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_35 = V_1;
		__this->____slots = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_35);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_2;
		__this->____buckets = L_36;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_36);
		__this->____freeList = (-1);
		return;
	}
}
// Method Definition Index: 71589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m9F38BC09C26BE8AB8CD88B95B5D9BF5596333949 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_5 = (SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)(SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		__this->____slots = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 71590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_mF06BBDACC9FB3F0629936C128349062594CD65E6 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____count;
		if ((((int32_t)L_2) > ((int32_t)L_3)))
		{
			goto IL_0020;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral91930CCAB5CB8F6F327407F9A14CF42F57A0F27B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = V_0;
		HashSet_1_SetCapacity_mE64511C2F4ED7CDD466E4FC9AD6170447674A565(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 71591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_mE64511C2F4ED7CDD466E4FC9AD6170447674A565 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_newSize, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* V_0 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		int32_t L_0 = ___0_newSize;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_1 = (SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)(SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_0);
		V_0 = L_1;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_2 = __this->____slots;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_3 = __this->____slots;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_4 = V_0;
		int32_t L_5 = __this->____lastIndex;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, L_5, NULL);
	}

IL_0023:
	{
		int32_t L_6 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_1 = L_7;
		V_2 = 0;
		goto IL_0058;
	}

IL_002e:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_8 = V_0;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		int32_t L_11 = ___0_newSize;
		V_3 = ((int32_t)(L_10%L_11));
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_12 = V_0;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = V_1;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = L_15;
		int32_t L_17 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___next = ((int32_t)il2cpp_codegen_subtract(L_17, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_1;
		int32_t L_19 = V_3;
		int32_t L_20 = V_2;
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(L_19), (int32_t)((int32_t)il2cpp_codegen_add(L_20, 1)));
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_0058:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = __this->____lastIndex;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_002e;
		}
	}
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_24 = V_0;
		__this->____slots = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_24);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_25 = V_1;
		__this->____buckets = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_25);
		return;
	}
}
// Method Definition Index: 71592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mAF5149C72B493BC5D95BE4EC13A429A05773FFF6 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1;
		L_1 = HashSet_1_Initialize_m9F38BC09C26BE8AB8CD88B95B5D9BF5596333949(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0010:
	{
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_2 = ___0_value;
		int32_t L_3;
		L_3 = HashSet_1_InternalGetHashCode_m38217C0101E1F461019404AAF3395993EB1CF941(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_3;
		int32_t L_4 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		V_1 = ((int32_t)(L_4%L_6));
		V_2 = 0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_7 = __this->____slots;
		V_3 = L_7;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		int32_t L_11 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		goto IL_008b;
	}

IL_003a:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_12 = V_3;
		int32_t L_13 = V_5;
		NullCheck(L_12);
		int32_t L_14 = ((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		int32_t L_15 = V_0;
		if ((!(((uint32_t)L_14) == ((uint32_t)L_15))))
		{
			goto IL_0067;
		}
	}
	{
		RuntimeObject* L_16 = __this->____comparer;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_17 = V_3;
		int32_t L_18 = V_5;
		NullCheck(L_17);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___value;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_20 = ___0_value;
		NullCheck(L_16);
		bool L_21;
		L_21 = InterfaceFuncInvoker2< bool, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_16, L_19, L_20);
		if (!L_21)
		{
			goto IL_0067;
		}
	}
	{
		return (bool)0;
	}

IL_0067:
	{
		int32_t L_22 = V_2;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_23 = V_3;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		if ((((int32_t)L_22) < ((int32_t)L_24)))
		{
			goto IL_0078;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_25 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_25, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_25, method);
	}

IL_0078:
	{
		int32_t L_26 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_27 = V_3;
		int32_t L_28 = V_5;
		NullCheck(L_27);
		int32_t L_29 = ((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_5 = L_29;
	}

IL_008b:
	{
		int32_t L_30 = V_5;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_31 = __this->____freeList;
		if ((((int32_t)L_31) < ((int32_t)0)))
		{
			goto IL_00b6;
		}
	}
	{
		int32_t L_32 = __this->____freeList;
		V_4 = L_32;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_33 = V_3;
		int32_t L_34 = V_4;
		NullCheck(L_33);
		int32_t L_35 = ((L_33)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_34)))->___next;
		__this->____freeList = L_35;
		goto IL_00ef;
	}

IL_00b6:
	{
		int32_t L_36 = __this->____lastIndex;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_37 = V_3;
		NullCheck(L_37);
		int32_t L_38 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_37)->max_length),NULL));
		if ((!(((uint32_t)L_36) == ((uint32_t)L_38))))
		{
			goto IL_00d9;
		}
	}
	{
		HashSet_1_IncreaseCapacity_mF06BBDACC9FB3F0629936C128349062594CD65E6(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_39 = __this->____slots;
		V_3 = L_39;
		int32_t L_40 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = __this->____buckets;
		NullCheck(L_41);
		int32_t L_42 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_41)->max_length),NULL));
		V_1 = ((int32_t)(L_40%L_42));
	}

IL_00d9:
	{
		int32_t L_43 = __this->____lastIndex;
		V_4 = L_43;
		int32_t L_44 = __this->____lastIndex;
		__this->____lastIndex = ((int32_t)il2cpp_codegen_add(L_44, 1));
	}

IL_00ef:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_45 = V_3;
		int32_t L_46 = V_4;
		NullCheck(L_45);
		int32_t L_47 = V_0;
		((L_45)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_46)))->___hashCode = L_47;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_48 = V_3;
		int32_t L_49 = V_4;
		NullCheck(L_48);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_50 = ___0_value;
		((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value = L_50;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_51 = V_3;
		int32_t L_52 = V_4;
		NullCheck(L_51);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_53 = __this->____buckets;
		int32_t L_54 = V_1;
		NullCheck(L_53);
		int32_t L_55 = L_54;
		int32_t L_56 = (L_53)->GetAt(static_cast<il2cpp_array_size_t>(L_55));
		((L_51)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_52)))->___next = ((int32_t)il2cpp_codegen_subtract(L_56, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = __this->____buckets;
		int32_t L_58 = V_1;
		int32_t L_59 = V_4;
		NullCheck(L_57);
		(L_57)->SetAt(static_cast<il2cpp_array_size_t>(L_58), (int32_t)((int32_t)il2cpp_codegen_add(L_59, 1)));
		int32_t L_60 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_60, 1));
		int32_t L_61 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_61, 1));
		return (bool)1;
	}
}
// Method Definition Index: 71593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mA51FE1D72D825FC764AA4ED6C347ACD2CAF61E4C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, int32_t ___0_index, int32_t ___1_hashCode, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_hashCode;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		V_0 = ((int32_t)(L_0%L_2));
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_3 = __this->____slots;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = ___1_hashCode;
		((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)))->___hashCode = L_5;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_6 = __this->____slots;
		int32_t L_7 = ___0_index;
		NullCheck(L_6);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_8 = ___2_value;
		((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value = L_8;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_9 = __this->____slots;
		int32_t L_10 = ___0_index;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___next = ((int32_t)il2cpp_codegen_subtract(L_14, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = __this->____buckets;
		int32_t L_16 = V_0;
		int32_t L_17 = ___0_index;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(L_16), (int32_t)((int32_t)il2cpp_codegen_add(L_17, 1)));
		return;
	}
}
// Method Definition Index: 71594
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_mB976C7D04D778F1FB1639F6E23FABA39C2EF175F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	{
		RuntimeObject* L_0 = ___0_other;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_0030;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_0030:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_5;
				L_5 = InterfaceFuncInvoker0< EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_4);
				V_1 = L_5;
				EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_6 = V_1;
				bool L_7;
				L_7 = HashSet_1_Contains_m4F9D37448BAEF8FE526453CB58B1EF11EB5D5C8C(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
				if (L_7)
				{
					goto IL_001d_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0033;
			}

IL_001d_1:
			{
				RuntimeObject* L_8 = V_0;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0031;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0031:
	{
		return (bool)1;
	}

IL_0033:
	{
		bool L_10 = V_2;
		return L_10;
	}
}
// Method Definition Index: 71595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_mCCA47E61CC24F37E672A305FA0614E2FD661A73C (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* V_2 = NULL;
	int32_t V_3 = 0;
	{
		V_0 = 0;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_0 = ___0_item;
		int32_t L_1;
		L_1 = HashSet_1_InternalGetHashCode_m38217C0101E1F461019404AAF3395993EB1CF941(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_1;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_2 = __this->____slots;
		V_2 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = __this->____buckets;
		int32_t L_4 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NullCheck(L_3);
		int32_t L_7 = ((int32_t)(L_4%L_6));
		int32_t L_8 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		goto IL_0074;
	}

IL_0027:
	{
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_9 = V_2;
		int32_t L_10 = V_3;
		NullCheck(L_9);
		int32_t L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___hashCode;
		int32_t L_12 = V_1;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_12))))
		{
			goto IL_0052;
		}
	}
	{
		RuntimeObject* L_13 = __this->____comparer;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_14 = V_2;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16 = ((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)))->___value;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_17 = ___0_item;
		NullCheck(L_13);
		bool L_18;
		L_18 = InterfaceFuncInvoker2< bool, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_13, L_16, L_17);
		if (!L_18)
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_19 = V_3;
		return L_19;
	}

IL_0052:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_0063;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_0063:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tFD52E53D3D49D5B46CDB157540D91BA6413FF4C4* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_0074:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_0027;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 71596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA HashSet_1_CheckUniqueAndUnfoundElements_mD12B1A14A687B718C5D814FA14C404D3F328BF0D (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	RuntimeObject* V_6 = NULL;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_7;
	memset((&V_7), 0, sizeof(V_7));
	int32_t V_8 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_004f;
		}
	}
	{
		V_5 = 0;
		RuntimeObject* L_1 = ___0_other;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_1);
		V_6 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_3 = V_6;
					if (!L_3)
					{
						goto IL_003b;
					}
				}
				{
					RuntimeObject* L_4 = V_6;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_003b:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0025_1;
			}

IL_0015_1:
			{
				RuntimeObject* L_5 = V_6;
				NullCheck(L_5);
				EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_6;
				L_6 = InterfaceFuncInvoker0< EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_5);
				int32_t L_7 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_7, 1));
				goto IL_003c;
			}

IL_0025_1:
			{
				RuntimeObject* L_8 = V_6;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0015_1;
				}
			}
			{
				goto IL_003c;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003c:
	{
		(&V_0)->___uniqueCount = 0;
		int32_t L_10 = V_5;
		(&V_0)->___unfoundCount = L_10;
		ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA L_11 = V_0;
		return L_11;
	}

IL_004f:
	{
		int32_t L_12 = __this->____lastIndex;
		int32_t L_13;
		L_13 = BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C(L_12, NULL);
		V_1 = L_13;
		int32_t L_14 = V_1;
		if ((((int32_t)L_14) > ((int32_t)((int32_t)100))))
		{
			goto IL_006f;
		}
	}
	{
		int32_t L_15 = V_1;
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		if ((uintptr_t)L_16 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_17 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_16, 4));
		int8_t* L_18;
		if (L_17 == 0)
		{
			L_18 = NULL;
		}
		else
		{
			L_18 = (int8_t*)alloca(L_17);
			memset(L_18, 0, L_17);
		}
		int32_t L_19 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_20 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3(L_20, (int32_t*)L_18, L_19, NULL);
		V_2 = L_20;
		goto IL_007c;
	}

IL_006f:
	{
		int32_t L_21 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_21);
		int32_t L_23 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_24 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19(L_24, L_22, L_23, NULL);
		V_2 = L_24;
	}

IL_007c:
	{
		V_3 = 0;
		V_4 = 0;
		RuntimeObject* L_25 = ___0_other;
		NullCheck(L_25);
		RuntimeObject* L_26;
		L_26 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_25);
		V_6 = L_26;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d1:
			{
				{
					RuntimeObject* L_27 = V_6;
					if (!L_27)
					{
						goto IL_00dc;
					}
				}
				{
					RuntimeObject* L_28 = V_6;
					NullCheck(L_28);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_28);
				}

IL_00dc:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00c6_1;
			}

IL_008b_1:
			{
				RuntimeObject* L_29 = V_6;
				NullCheck(L_29);
				EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_30;
				L_30 = InterfaceFuncInvoker0< EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_29);
				V_7 = L_30;
				EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_31 = V_7;
				int32_t L_32;
				L_32 = HashSet_1_InternalIndexOf_mCCA47E61CC24F37E672A305FA0614E2FD661A73C(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
				V_8 = L_32;
				int32_t L_33 = V_8;
				if ((((int32_t)L_33) < ((int32_t)0)))
				{
					goto IL_00bd_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_34 = V_2;
				int32_t L_35 = V_8;
				NullCheck(L_34);
				bool L_36;
				L_36 = BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2(L_34, L_35, NULL);
				if (L_36)
				{
					goto IL_00c6_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_37 = V_2;
				int32_t L_38 = V_8;
				NullCheck(L_37);
				BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86(L_37, L_38, NULL);
				int32_t L_39 = V_4;
				V_4 = ((int32_t)il2cpp_codegen_add(L_39, 1));
				goto IL_00c6_1;
			}

IL_00bd_1:
			{
				int32_t L_40 = V_3;
				V_3 = ((int32_t)il2cpp_codegen_add(L_40, 1));
				bool L_41 = ___1_returnIfUnfound;
				if (!L_41)
				{
					goto IL_00c6_1;
				}
			}
			{
				goto IL_00dd;
			}

IL_00c6_1:
			{
				RuntimeObject* L_42 = V_6;
				NullCheck(L_42);
				bool L_43;
				L_43 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_42);
				if (L_43)
				{
					goto IL_008b_1;
				}
			}
			{
				goto IL_00dd;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00dd:
	{
		int32_t L_44 = V_4;
		(&V_0)->___uniqueCount = L_44;
		int32_t L_45 = V_3;
		(&V_0)->___unfoundCount = L_45;
		ElementCount_tAED0D8766D4D61690A1111AC931ACA42DE8F13EA L_46 = V_0;
		return L_46;
	}
}
// Method Definition Index: 71597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m745C3AA0C82ABD3EACFE9AD11FB39B801138F98F (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___0_set1, HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* ___1_set2, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_0 = ___0_set1;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = HashSet_1_get_Comparer_m974F0A080C6E904F6E2EA9FDBFD34D3CAA616287_inline(L_0, NULL);
		HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* L_2 = ___1_set2;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = HashSet_1_get_Comparer_m974F0A080C6E904F6E2EA9FDBFD34D3CAA616287_inline(L_2, NULL);
		NullCheck(L_1);
		bool L_4;
		L_4 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, L_1, L_3);
		return L_4;
	}
}
// Method Definition Index: 71598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m38217C0101E1F461019404AAF3395993EB1CF941 (HashSet_1_t079A33BC313C233180D2B4A99D6B9DDC5AE4EBCB* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000a;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____comparer;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_2 = ___0_item;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_1, L_2);
		return ((int32_t)(L_3&((int32_t)2147483647LL)));
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
// Method Definition Index: 71561
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m5E8DC7C6B6881B5D2703AE7099227FC2B2AD7F72 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_0;
		L_0 = EqualityComparer_1_get_Default_m116EA0543E757039FC0248582114CD5078435378_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m81358023B845A4D3270030000BC6377A25AF109A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return;
	}
}
// Method Definition Index: 71562
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m81358023B845A4D3270030000BC6377A25AF109A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_comparer;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_1;
		L_1 = EqualityComparer_1_get_Default_m116EA0543E757039FC0248582114CD5078435378_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		___0_comparer = L_1;
	}

IL_0010:
	{
		RuntimeObject* L_2 = ___0_comparer;
		__this->____comparer = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_2);
		__this->____lastIndex = 0;
		__this->____count = 0;
		__this->____freeList = (-1);
		__this->____version = 0;
		return;
	}
}
// Method Definition Index: 71563
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mEF1EDD4A5336643519682DDF60BEEE848038F8EC (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_1;
		L_1 = EqualityComparer_1_get_Default_m116EA0543E757039FC0248582114CD5078435378_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m943B4F9475E84832B1690AE207920F0EB091C98C(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 71564
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m8B8F500D1CEAC0E17BD062103825131E2CE59250 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_collection;
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_1;
		L_1 = EqualityComparer_1_get_Default_m116EA0543E757039FC0248582114CD5078435378_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m2E7B8F4B50CB641ECAEA9DDCA03F85C59DBFCD0E(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
// Method Definition Index: 71565
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m2E7B8F4B50CB641ECAEA9DDCA03F85C59DBFCD0E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B8_0 = 0;
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_m81358023B845A4D3270030000BC6377A25AF109A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		RuntimeObject* L_1 = ___0_collection;
		if (L_1)
		{
			goto IL_0015;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral469F05BE9BB4C7903C353D0EB9F6384C84A48B25)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0015:
	{
		RuntimeObject* L_3 = ___0_collection;
		V_0 = ((HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_4 = V_0;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m4CE29AA365BD937A2E12C794E09E19D0CB20B8EE(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_7 = V_0;
		HashSet_1_CopyFrom_m9212C09A26DCBF451C4EDFDC285795EAF0EE5494(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return;
	}

IL_0030:
	{
		RuntimeObject* L_8 = ___0_collection;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_9 = V_1;
		if (!L_9)
		{
			goto IL_0042;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_10);
		G_B8_0 = L_11;
		goto IL_0043;
	}

IL_0042:
	{
		G_B8_0 = 0;
	}

IL_0043:
	{
		V_2 = G_B8_0;
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = HashSet_1_Initialize_m388FABC9629D7B7DBEE9104461A18D3A467ADE8A(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		RuntimeObject* L_14 = ___0_collection;
		HashSet_1_UnionWith_mCD4A87BDC9C79126CA4FA60ABC8116E47DE58F9C(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		int32_t L_15 = __this->____count;
		if ((((int32_t)L_15) <= ((int32_t)0)))
		{
			goto IL_0074;
		}
	}
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_16 = __this->____slots;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = __this->____count;
		if ((((int32_t)((int32_t)(L_17/L_18))) <= ((int32_t)3)))
		{
			goto IL_0074;
		}
	}
	{
		HashSet_1_TrimExcess_m09FAE505BEBF4191B480224176E6298AEAD543DD(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}

IL_0074:
	{
		return;
	}
}
// Method Definition Index: 71566
// Method Definition Index: 71567
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m9212C09A26DCBF451C4EDFDC285795EAF0EE5494 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_0 = ___0_source;
		NullCheck(L_0);
		int32_t L_1 = L_0->____count;
		V_0 = L_1;
		int32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_000b;
		}
	}
	{
		return;
	}

IL_000b:
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_3 = ___0_source;
		NullCheck(L_3);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = L_3->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = L_5;
		int32_t L_6 = V_0;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(((int32_t)il2cpp_codegen_add(L_6, 1)), NULL);
		int32_t L_8 = V_1;
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0065;
		}
	}
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_9 = ___0_source;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = L_9->____buckets;
		NullCheck((RuntimeArray*)L_10);
		RuntimeObject* L_11;
		L_11 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_10, NULL);
		__this->____buckets = ((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var)));
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_12 = ___0_source;
		NullCheck(L_12);
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_13 = L_12->____slots;
		NullCheck((RuntimeArray*)L_13);
		RuntimeObject* L_14;
		L_14 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_13, NULL);
		__this->____slots = ((SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)((SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))));
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_15 = ___0_source;
		NullCheck(L_15);
		int32_t L_16 = L_15->____lastIndex;
		__this->____lastIndex = L_16;
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_17 = ___0_source;
		NullCheck(L_17);
		int32_t L_18 = L_17->____freeList;
		__this->____freeList = L_18;
		goto IL_00c7;
	}

IL_0065:
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_19 = ___0_source;
		NullCheck(L_19);
		int32_t L_20 = L_19->____lastIndex;
		V_2 = L_20;
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_21 = ___0_source;
		NullCheck(L_21);
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_22 = L_21->____slots;
		V_3 = L_22;
		int32_t L_23 = V_0;
		int32_t L_24;
		L_24 = HashSet_1_Initialize_m388FABC9629D7B7DBEE9104461A18D3A467ADE8A(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		V_4 = 0;
		V_5 = 0;
		goto IL_00ba;
	}

IL_0083:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_25 = V_3;
		int32_t L_26 = V_5;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		V_6 = L_27;
		int32_t L_28 = V_6;
		if ((((int32_t)L_28) < ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		int32_t L_29 = V_4;
		int32_t L_30 = V_6;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_31 = V_3;
		int32_t L_32 = V_5;
		NullCheck(L_31);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_33 = ((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->___value;
		HashSet_1_AddValue_mE41A53D868E2ADA467E2C6304A0B806E7F5213BB(__this, L_29, L_30, L_33, NULL);
		int32_t L_34 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b4:
	{
		int32_t L_35 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_35, 1));
	}

IL_00ba:
	{
		int32_t L_36 = V_5;
		int32_t L_37 = V_2;
		if ((((int32_t)L_36) < ((int32_t)L_37)))
		{
			goto IL_0083;
		}
	}
	{
		int32_t L_38 = V_4;
		__this->____lastIndex = L_38;
	}

IL_00c7:
	{
		int32_t L_39 = V_0;
		__this->____count = L_39;
		return;
	}
}
// Method Definition Index: 71568
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m943B4F9475E84832B1690AE207920F0EB091C98C (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_m81358023B845A4D3270030000BC6377A25AF109A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0016;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0016:
	{
		int32_t L_3 = ___0_capacity;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = HashSet_1_Initialize_m388FABC9629D7B7DBEE9104461A18D3A467ADE8A(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0022:
	{
		return;
	}
}
// Method Definition Index: 71569
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_System_Collections_Generic_ICollectionU3CTU3E_Add_m41F4247A42DD0650507F359FE697EC492D830F03 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mC1CC3F3C8532776B1CBD8C19E8F245F33DCE066A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return;
	}
}
// Method Definition Index: 71570
// Method Definition Index: 71571
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m0B7B5FA01B6EAB629850CEDBD4C42CF166F3B07E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* V_2 = NULL;
	int32_t V_3 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0080;
		}
	}
	{
		V_0 = 0;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m077082839BDD06A5353FADE1CEDBE8FD44F9CFAD(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_2;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_3 = __this->____slots;
		V_2 = L_3;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		int32_t L_5 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->____buckets;
		NullCheck(L_6);
		int32_t L_7 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_6)->max_length),NULL));
		NullCheck(L_4);
		int32_t L_8 = ((int32_t)(L_5%L_7));
		int32_t L_9 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_9, 1));
		goto IL_007c;
	}

IL_002f:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_10 = V_2;
		int32_t L_11 = V_3;
		NullCheck(L_10);
		int32_t L_12 = ((L_10)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		int32_t L_13 = V_1;
		if ((!(((uint32_t)L_12) == ((uint32_t)L_13))))
		{
			goto IL_005a;
		}
	}
	{
		RuntimeObject* L_14 = __this->____comparer;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_15 = V_2;
		int32_t L_16 = V_3;
		NullCheck(L_15);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_17 = ((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)))->___value;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_18 = ___0_item;
		NullCheck(L_14);
		bool L_19;
		L_19 = InterfaceFuncInvoker2< bool, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_14, L_17, L_18);
		if (!L_19)
		{
			goto IL_005a;
		}
	}
	{
		return (bool)1;
	}

IL_005a:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_006b;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_006b:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_007c:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_002f;
		}
	}

IL_0080:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71572
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m6A86BCA601A1DF0D4223B3E80A7C724F1B161A4C (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_0 = ___0_array;
		int32_t L_1 = ___1_arrayIndex;
		int32_t L_2 = __this->____count;
		HashSet_1_CopyTo_m1D8319452756E92FD985CBEFBFDEBBB83C5D036E(__this, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71573
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_m05814B20238F59F43308AD5D54B3F0F877919CC1 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* V_4 = NULL;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0154;
		}
	}
	{
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m077082839BDD06A5353FADE1CEDBE8FD44F9CFAD(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_2;
		int32_t L_3 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = ((int32_t)(L_3%L_5));
		V_2 = (-1);
		V_3 = 0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_6 = __this->____slots;
		V_4 = L_6;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		int32_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
		goto IL_014c;
	}

IL_003b:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_11 = V_4;
		int32_t L_12 = V_5;
		NullCheck(L_11);
		int32_t L_13 = ((L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_12)))->___hashCode;
		int32_t L_14 = V_0;
		if ((!(((uint32_t)L_13) == ((uint32_t)L_14))))
		{
			goto IL_0123;
		}
	}
	{
		RuntimeObject* L_15 = __this->____comparer;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_16 = V_4;
		int32_t L_17 = V_5;
		NullCheck(L_16);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_18 = ((L_16)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_19 = ___0_item;
		NullCheck(L_15);
		bool L_20;
		L_20 = InterfaceFuncInvoker2< bool, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0123;
		}
	}
	{
		int32_t L_21 = V_2;
		if ((((int32_t)L_21) >= ((int32_t)0)))
		{
			goto IL_008c;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = __this->____buckets;
		int32_t L_23 = V_1;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_24 = V_4;
		int32_t L_25 = V_5;
		NullCheck(L_24);
		int32_t L_26 = ((L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_25)))->___next;
		NullCheck(L_22);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(L_23), (int32_t)((int32_t)il2cpp_codegen_add(L_26, 1)));
		goto IL_00a7;
	}

IL_008c:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_27 = V_4;
		int32_t L_28 = V_2;
		NullCheck(L_27);
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_29 = V_4;
		int32_t L_30 = V_5;
		NullCheck(L_29);
		int32_t L_31 = ((L_29)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_30)))->___next;
		((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next = L_31;
	}

IL_00a7:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_32 = V_4;
		int32_t L_33 = V_5;
		NullCheck(L_32);
		((L_32)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_33)))->___hashCode = (-1);
		goto IL_00d1;
	}

IL_00d1:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_34 = V_4;
		int32_t L_35 = V_5;
		NullCheck(L_34);
		int32_t L_36 = __this->____freeList;
		((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_35)))->___next = L_36;
		int32_t L_37 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_subtract(L_37, 1));
		int32_t L_38 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_38, 1));
		int32_t L_39 = __this->____count;
		if (L_39)
		{
			goto IL_0119;
		}
	}
	{
		__this->____lastIndex = 0;
		__this->____freeList = (-1);
		goto IL_0121;
	}

IL_0119:
	{
		int32_t L_40 = V_5;
		__this->____freeList = L_40;
	}

IL_0121:
	{
		return (bool)1;
	}

IL_0123:
	{
		int32_t L_41 = V_3;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_42 = V_4;
		NullCheck(L_42);
		int32_t L_43 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_42)->max_length),NULL));
		if ((((int32_t)L_41) < ((int32_t)L_43)))
		{
			goto IL_0135;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_44 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_0135:
	{
		int32_t L_45 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_45, 1));
		int32_t L_46 = V_5;
		V_2 = L_46;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_47 = V_4;
		int32_t L_48 = V_5;
		NullCheck(L_47);
		int32_t L_49 = ((L_47)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_48)))->___next;
		V_5 = L_49;
	}

IL_014c:
	{
		int32_t L_50 = V_5;
		if ((((int32_t)L_50) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0154:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F HashSet_1_GetEnumerator_mAC62F303E3E26D582BF19D2923E15B32EB4C681B (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m23E682237EE2BDF19D5BB21ABA68C2B0384B4CE0((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 71577
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mA9F15E10D3A7A0955D363E7E3230BDF49AFDCC93 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m23E682237EE2BDF19D5BB21ABA68C2B0384B4CE0((&L_0), __this, NULL);
		Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71578
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_IEnumerable_GetEnumerator_mF4178E3A916AA95FEC92B60B292B6E801552842E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m23E682237EE2BDF19D5BB21ABA68C2B0384B4CE0((&L_0), __this, NULL);
		Enumerator_tA432C8CD0DCF31B9262681956C57B4AF0F3AF22F L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_GetObjectData_mC1F8ACAD81A27299AD0E4A3697881F981089EE03 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* V_0 = NULL;
	String_t* G_B4_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_1 = NULL;
	String_t* G_B3_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_1 = NULL;
	int32_t G_B5_0 = 0;
	String_t* G_B5_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		int32_t L_3 = __this->____version;
		NullCheck(L_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_2, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_3, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeObject* L_5 = __this->____comparer;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 27)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		NullCheck(L_4);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_4, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, L_7, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_8 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = __this->____buckets;
		if (!L_9)
		{
			G_B4_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
			G_B4_1 = L_8;
			goto IL_0052;
		}
		G_B3_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
		G_B3_1 = L_8;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		NullCheck(L_10);
		int32_t L_11 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_10)->max_length),NULL));
		G_B5_0 = L_11;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0053;
	}

IL_0052:
	{
		G_B5_0 = 0;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0053:
	{
		NullCheck(G_B5_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B5_2, G_B5_1, G_B5_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = __this->____buckets;
		if (!L_12)
		{
			goto IL_0089;
		}
	}
	{
		int32_t L_13 = __this->____count;
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_14 = (EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25*)(EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29), (uint32_t)L_13);
		V_0 = L_14;
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_15 = V_0;
		HashSet_1_CopyTo_m78D58EDF20BAF924E06F4F0C973DE3C511293551(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_16 = ___0_info;
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_17 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		NullCheck(L_16);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_16, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, (RuntimeObject*)L_17, L_19, NULL);
	}

IL_0089:
	{
		return;
	}
}
// Method Definition Index: 71580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_OnDeserialization_m8FD27446E6EE45FC5D7D49AC53B72EF5B6924196 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* V_1 = NULL;
	int32_t V_2 = 0;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = __this->____siInfo;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		return;
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = __this->____siInfo;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_1, _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865, NULL);
		V_0 = L_2;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 32)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		NullCheck(L_3);
		RuntimeObject* L_6;
		L_6 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_3, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20))));
		__this->____freeList = (-1);
		int32_t L_7 = V_0;
		if (!L_7)
		{
			goto IL_00ad;
		}
	}
	{
		int32_t L_8 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_8);
		__this->____buckets = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_9);
		int32_t L_10 = V_0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_11 = (SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)(SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_10);
		__this->____slots = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_11);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_12 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_13 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_14;
		L_14 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_13, NULL);
		NullCheck(L_12);
		RuntimeObject* L_15;
		L_15 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_12, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, L_14, NULL);
		V_1 = ((EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25*)CastclassSealed((RuntimeObject*)L_15, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29)));
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_16 = V_1;
		if (L_16)
		{
			goto IL_008f;
		}
	}
	{
		SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7* L_17 = (SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_il2cpp_TypeInfo_var)));
		SerializationException__ctor_m0AAFE2ABD0A74F3E783AD5B5FE842DE460168DB0(L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC5ABE84F2ABF009EBC68D2A32EF8C171B074F922)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_008f:
	{
		V_2 = 0;
		goto IL_00a5;
	}

IL_0093:
	{
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_18 = V_1;
		int32_t L_19 = V_2;
		NullCheck(L_18);
		int32_t L_20 = L_19;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_21 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_20));
		bool L_22;
		L_22 = HashSet_1_AddIfNotPresent_mC1CC3F3C8532776B1CBD8C19E8F245F33DCE066A(__this, L_21, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_2;
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_25 = V_1;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((((int32_t)L_24) < ((int32_t)L_26)))
		{
			goto IL_0093;
		}
	}
	{
		goto IL_00b4;
	}

IL_00ad:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00b4:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_27 = __this->____siInfo;
		NullCheck(L_27);
		int32_t L_28;
		L_28 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_27, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		__this->____version = L_28;
		__this->____siInfo = (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____siInfo), (void*)(SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL);
		return;
	}
}
// Method Definition Index: 71581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Add_m8341C2BC10DE4FF1D307D56B19B9D50826BAF5D1 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mC1CC3F3C8532776B1CBD8C19E8F245F33DCE066A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_1;
	}
}
// Method Definition Index: 71582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mCD4A87BDC9C79126CA4FA60ABC8116E47DE58F9C (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_2);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_4 = V_0;
					if (!L_4)
					{
						goto IL_0039;
					}
				}
				{
					RuntimeObject* L_5 = V_0;
					NullCheck(L_5);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
				}

IL_0039:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_6 = V_0;
				NullCheck(L_6);
				EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_7;
				L_7 = InterfaceFuncInvoker0< EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_6);
				V_1 = L_7;
				EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_8 = V_1;
				bool L_9;
				L_9 = HashSet_1_AddIfNotPresent_mC1CC3F3C8532776B1CBD8C19E8F245F33DCE066A(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
			}

IL_0026_1:
			{
				RuntimeObject* L_10 = V_0;
				NullCheck(L_10);
				bool L_11;
				L_11 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_10);
				if (L_11)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_003a;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003a:
	{
		return;
	}
}
// Method Definition Index: 71583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_SetEquals_m73F5E16A53B835CF66C0DDCF961D88765DD4B54B (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		if ((!(((RuntimeObject*)(RuntimeObject*)L_2) == ((RuntimeObject*)(HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA*)__this))))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)1;
	}

IL_0014:
	{
		RuntimeObject* L_3 = ___0_other;
		V_0 = ((HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_4 = V_0;
		if (!L_4)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m4CE29AA365BD937A2E12C794E09E19D0CB20B8EE(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_003f;
		}
	}
	{
		int32_t L_7 = __this->____count;
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = HashSet_1_get_Count_m89A384E693796B3524241507B9CB798808BC9EC1_inline(L_8, NULL);
		if ((((int32_t)L_7) == ((int32_t)L_9)))
		{
			goto IL_0037;
		}
	}
	{
		return (bool)0;
	}

IL_0037:
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_10 = V_0;
		bool L_11;
		L_11 = HashSet_1_ContainsAllElements_mBFE3C57E264F8C227BEEBC200760FA83D1969B39(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return L_11;
	}

IL_003f:
	{
		RuntimeObject* L_12 = ___0_other;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_13 = V_1;
		if (!L_13)
		{
			goto IL_005c;
		}
	}
	{
		int32_t L_14 = __this->____count;
		if (L_14)
		{
			goto IL_005c;
		}
	}
	{
		RuntimeObject* L_15 = V_1;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_15);
		if ((((int32_t)L_16) <= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}
	{
		return (bool)0;
	}

IL_005c:
	{
		RuntimeObject* L_17 = ___0_other;
		ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D L_18;
		L_18 = HashSet_1_CheckUniqueAndUnfoundElements_m63C187EFD30928C462894D854942F13172A814AA(__this, L_17, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_2 = L_18;
		ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D L_19 = V_2;
		int32_t L_20 = L_19.___uniqueCount;
		int32_t L_21 = __this->____count;
		if ((!(((uint32_t)L_20) == ((uint32_t)L_21))))
		{
			goto IL_007d;
		}
	}
	{
		ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D L_22 = V_2;
		int32_t L_23 = L_22.___unfoundCount;
		return (bool)((((int32_t)L_23) == ((int32_t)0))? 1 : 0);
	}

IL_007d:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m78D58EDF20BAF924E06F4F0C973DE3C511293551 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_0 = ___0_array;
		int32_t L_1 = __this->____count;
		HashSet_1_CopyTo_m1D8319452756E92FD985CBEFBFDEBBB83C5D036E(__this, L_0, 0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71585
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m1D8319452756E92FD985CBEFBFDEBBB83C5D036E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_0 = ___0_array;
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
		int32_t L_2 = ___1_arrayIndex;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_3 = ___1_arrayIndex;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_6 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC00660333703C551EA80371B54D0ADCEB74C33B4)), L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0028:
	{
		int32_t L_7 = ___2_count;
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_0042;
		}
	}
	{
		int32_t L_8 = ___2_count;
		int32_t L_9 = L_8;
		RuntimeObject* L_10 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_9);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_11 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral07624473F417C06C74D59C64840A1532FCE2C626)), L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0042:
	{
		int32_t L_12 = ___1_arrayIndex;
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_13 = ___0_array;
		NullCheck(L_13);
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		if ((((int32_t)L_12) > ((int32_t)L_14)))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_15 = ___2_count;
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_16 = ___0_array;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = ___1_arrayIndex;
		if ((((int32_t)L_15) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18)))))
		{
			goto IL_005b;
		}
	}

IL_0050:
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_19 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_005b:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0097;
	}

IL_0061:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_20 = __this->____slots;
		int32_t L_21 = V_1;
		NullCheck(L_20);
		int32_t L_22 = ((L_20)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_21)))->___hashCode;
		if ((((int32_t)L_22) < ((int32_t)0)))
		{
			goto IL_0093;
		}
	}
	{
		EventIDU5BU5D_t2A11918391134B2F4B8BEB538E3D4A7FD245AD25* L_23 = ___0_array;
		int32_t L_24 = ___1_arrayIndex;
		int32_t L_25 = V_0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_26 = __this->____slots;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_28 = ((L_26)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_27)))->___value;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_24, L_25))), (EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF)L_28);
		int32_t L_29 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0093:
	{
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_0097:
	{
		int32_t L_31 = V_1;
		int32_t L_32 = __this->____lastIndex;
		if ((((int32_t)L_31) >= ((int32_t)L_32)))
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___2_count;
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0061;
		}
	}

IL_00a4:
	{
		return;
	}
}
// Method Definition Index: 71586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_RemoveWhere_m0269FC071D066797ED6B64E9FE700301C07E6EB5 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE2EEFB4BE0C9F57BA62E733F26387F8BA68AF67C)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0054;
	}

IL_0014:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_2 = __this->____slots;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = ((L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0050;
		}
	}
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_5 = __this->____slots;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_7 = ((L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		V_2 = L_7;
		Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3* L_8 = ___0_match;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_9 = V_2;
		NullCheck(L_8);
		bool L_10;
		L_10 = Predicate_1_Invoke_mBC57F9AAD95FE4E1D54D4F368A162D155516B547_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0050;
		}
	}
	{
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_11 = V_2;
		bool L_12;
		L_12 = HashSet_1_Remove_m05814B20238F59F43308AD5D54B3F0F877919CC1(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		if (!L_12)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0050:
	{
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0054:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = __this->____lastIndex;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_17 = V_0;
		return L_17;
	}
}
// Method Definition Index: 71587
// Method Definition Index: 71588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_m09FAE505BEBF4191B480224176E6298AEAD543DD (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_0025;
		}
	}
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
		__this->____slots = (SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)(SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)NULL);
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		return;
	}

IL_0025:
	{
		int32_t L_2 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_3;
		L_3 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_2, NULL);
		V_0 = L_3;
		int32_t L_4 = V_0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_5 = (SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)(SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		V_1 = L_5;
		int32_t L_6 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_2 = L_7;
		V_3 = 0;
		V_4 = 0;
		goto IL_00a2;
	}

IL_0046:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_8 = __this->____slots;
		int32_t L_9 = V_4;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_009c;
		}
	}
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_11 = V_1;
		int32_t L_12 = V_3;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_13 = __this->____slots;
		int32_t L_14 = V_4;
		NullCheck(L_13);
		int32_t L_15 = L_14;
		Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (Slot_t832EA400E5A48AA6DA60E79A23967F19D071665F)L_16);
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_17 = V_1;
		int32_t L_18 = V_3;
		NullCheck(L_17);
		int32_t L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_0;
		V_5 = ((int32_t)(L_19%L_20));
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_21 = V_1;
		int32_t L_22 = V_3;
		NullCheck(L_21);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_2;
		int32_t L_24 = V_5;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		int32_t L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		((L_21)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_22)))->___next = ((int32_t)il2cpp_codegen_subtract(L_26, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = V_2;
		int32_t L_28 = V_5;
		int32_t L_29 = V_3;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)il2cpp_codegen_add(L_29, 1)));
		int32_t L_30 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_009c:
	{
		int32_t L_31 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_00a2:
	{
		int32_t L_32 = V_4;
		int32_t L_33 = __this->____lastIndex;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_34 = V_3;
		__this->____lastIndex = L_34;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_35 = V_1;
		__this->____slots = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_35);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_2;
		__this->____buckets = L_36;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_36);
		__this->____freeList = (-1);
		return;
	}
}
// Method Definition Index: 71589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m388FABC9629D7B7DBEE9104461A18D3A467ADE8A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_5 = (SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)(SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		__this->____slots = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 71590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m2C7BDBAF64D2BA51F63BDB50FEE2FA43BA8C7B0E (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____count;
		if ((((int32_t)L_2) > ((int32_t)L_3)))
		{
			goto IL_0020;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral91930CCAB5CB8F6F327407F9A14CF42F57A0F27B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = V_0;
		HashSet_1_SetCapacity_m7AF79FED0EEF23B2F3FEEA789D4662599CA67EF0(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 71591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m7AF79FED0EEF23B2F3FEEA789D4662599CA67EF0 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_newSize, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* V_0 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		int32_t L_0 = ___0_newSize;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_1 = (SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)(SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_0);
		V_0 = L_1;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_2 = __this->____slots;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_3 = __this->____slots;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_4 = V_0;
		int32_t L_5 = __this->____lastIndex;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, L_5, NULL);
	}

IL_0023:
	{
		int32_t L_6 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_1 = L_7;
		V_2 = 0;
		goto IL_0058;
	}

IL_002e:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_8 = V_0;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		int32_t L_11 = ___0_newSize;
		V_3 = ((int32_t)(L_10%L_11));
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_12 = V_0;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = V_1;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = L_15;
		int32_t L_17 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___next = ((int32_t)il2cpp_codegen_subtract(L_17, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_1;
		int32_t L_19 = V_3;
		int32_t L_20 = V_2;
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(L_19), (int32_t)((int32_t)il2cpp_codegen_add(L_20, 1)));
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_0058:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = __this->____lastIndex;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_002e;
		}
	}
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_24 = V_0;
		__this->____slots = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_24);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_25 = V_1;
		__this->____buckets = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_25);
		return;
	}
}
// Method Definition Index: 71592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mC1CC3F3C8532776B1CBD8C19E8F245F33DCE066A (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1;
		L_1 = HashSet_1_Initialize_m388FABC9629D7B7DBEE9104461A18D3A467ADE8A(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0010:
	{
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_2 = ___0_value;
		int32_t L_3;
		L_3 = HashSet_1_InternalGetHashCode_m077082839BDD06A5353FADE1CEDBE8FD44F9CFAD(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_3;
		int32_t L_4 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		V_1 = ((int32_t)(L_4%L_6));
		V_2 = 0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_7 = __this->____slots;
		V_3 = L_7;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		int32_t L_11 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		goto IL_008b;
	}

IL_003a:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_12 = V_3;
		int32_t L_13 = V_5;
		NullCheck(L_12);
		int32_t L_14 = ((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		int32_t L_15 = V_0;
		if ((!(((uint32_t)L_14) == ((uint32_t)L_15))))
		{
			goto IL_0067;
		}
	}
	{
		RuntimeObject* L_16 = __this->____comparer;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_17 = V_3;
		int32_t L_18 = V_5;
		NullCheck(L_17);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___value;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_20 = ___0_value;
		NullCheck(L_16);
		bool L_21;
		L_21 = InterfaceFuncInvoker2< bool, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_16, L_19, L_20);
		if (!L_21)
		{
			goto IL_0067;
		}
	}
	{
		return (bool)0;
	}

IL_0067:
	{
		int32_t L_22 = V_2;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_23 = V_3;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		if ((((int32_t)L_22) < ((int32_t)L_24)))
		{
			goto IL_0078;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_25 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_25, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_25, method);
	}

IL_0078:
	{
		int32_t L_26 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_27 = V_3;
		int32_t L_28 = V_5;
		NullCheck(L_27);
		int32_t L_29 = ((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_5 = L_29;
	}

IL_008b:
	{
		int32_t L_30 = V_5;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_31 = __this->____freeList;
		if ((((int32_t)L_31) < ((int32_t)0)))
		{
			goto IL_00b6;
		}
	}
	{
		int32_t L_32 = __this->____freeList;
		V_4 = L_32;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_33 = V_3;
		int32_t L_34 = V_4;
		NullCheck(L_33);
		int32_t L_35 = ((L_33)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_34)))->___next;
		__this->____freeList = L_35;
		goto IL_00ef;
	}

IL_00b6:
	{
		int32_t L_36 = __this->____lastIndex;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_37 = V_3;
		NullCheck(L_37);
		int32_t L_38 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_37)->max_length),NULL));
		if ((!(((uint32_t)L_36) == ((uint32_t)L_38))))
		{
			goto IL_00d9;
		}
	}
	{
		HashSet_1_IncreaseCapacity_m2C7BDBAF64D2BA51F63BDB50FEE2FA43BA8C7B0E(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_39 = __this->____slots;
		V_3 = L_39;
		int32_t L_40 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = __this->____buckets;
		NullCheck(L_41);
		int32_t L_42 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_41)->max_length),NULL));
		V_1 = ((int32_t)(L_40%L_42));
	}

IL_00d9:
	{
		int32_t L_43 = __this->____lastIndex;
		V_4 = L_43;
		int32_t L_44 = __this->____lastIndex;
		__this->____lastIndex = ((int32_t)il2cpp_codegen_add(L_44, 1));
	}

IL_00ef:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_45 = V_3;
		int32_t L_46 = V_4;
		NullCheck(L_45);
		int32_t L_47 = V_0;
		((L_45)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_46)))->___hashCode = L_47;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_48 = V_3;
		int32_t L_49 = V_4;
		NullCheck(L_48);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_50 = ___0_value;
		((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value = L_50;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_51 = V_3;
		int32_t L_52 = V_4;
		NullCheck(L_51);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_53 = __this->____buckets;
		int32_t L_54 = V_1;
		NullCheck(L_53);
		int32_t L_55 = L_54;
		int32_t L_56 = (L_53)->GetAt(static_cast<il2cpp_array_size_t>(L_55));
		((L_51)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_52)))->___next = ((int32_t)il2cpp_codegen_subtract(L_56, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = __this->____buckets;
		int32_t L_58 = V_1;
		int32_t L_59 = V_4;
		NullCheck(L_57);
		(L_57)->SetAt(static_cast<il2cpp_array_size_t>(L_58), (int32_t)((int32_t)il2cpp_codegen_add(L_59, 1)));
		int32_t L_60 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_60, 1));
		int32_t L_61 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_61, 1));
		return (bool)1;
	}
}
// Method Definition Index: 71593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mE41A53D868E2ADA467E2C6304A0B806E7F5213BB (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, int32_t ___0_index, int32_t ___1_hashCode, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_hashCode;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		V_0 = ((int32_t)(L_0%L_2));
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_3 = __this->____slots;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = ___1_hashCode;
		((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)))->___hashCode = L_5;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_6 = __this->____slots;
		int32_t L_7 = ___0_index;
		NullCheck(L_6);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_8 = ___2_value;
		((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value = L_8;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_9 = __this->____slots;
		int32_t L_10 = ___0_index;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___next = ((int32_t)il2cpp_codegen_subtract(L_14, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = __this->____buckets;
		int32_t L_16 = V_0;
		int32_t L_17 = ___0_index;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(L_16), (int32_t)((int32_t)il2cpp_codegen_add(L_17, 1)));
		return;
	}
}
// Method Definition Index: 71594
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_mBFE3C57E264F8C227BEEBC200760FA83D1969B39 (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	{
		RuntimeObject* L_0 = ___0_other;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_0030;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_0030:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_5;
				L_5 = InterfaceFuncInvoker0< EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_4);
				V_1 = L_5;
				EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_6 = V_1;
				bool L_7;
				L_7 = HashSet_1_Contains_m0B7B5FA01B6EAB629850CEDBD4C42CF166F3B07E(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
				if (L_7)
				{
					goto IL_001d_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0033;
			}

IL_001d_1:
			{
				RuntimeObject* L_8 = V_0;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0031;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0031:
	{
		return (bool)1;
	}

IL_0033:
	{
		bool L_10 = V_2;
		return L_10;
	}
}
// Method Definition Index: 71595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m60DE8DED336AAAF63A6DC608722E57026FEBCD9F (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* V_2 = NULL;
	int32_t V_3 = 0;
	{
		V_0 = 0;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_0 = ___0_item;
		int32_t L_1;
		L_1 = HashSet_1_InternalGetHashCode_m077082839BDD06A5353FADE1CEDBE8FD44F9CFAD(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_1;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_2 = __this->____slots;
		V_2 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = __this->____buckets;
		int32_t L_4 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NullCheck(L_3);
		int32_t L_7 = ((int32_t)(L_4%L_6));
		int32_t L_8 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		goto IL_0074;
	}

IL_0027:
	{
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_9 = V_2;
		int32_t L_10 = V_3;
		NullCheck(L_9);
		int32_t L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___hashCode;
		int32_t L_12 = V_1;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_12))))
		{
			goto IL_0052;
		}
	}
	{
		RuntimeObject* L_13 = __this->____comparer;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_14 = V_2;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_16 = ((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)))->___value;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_17 = ___0_item;
		NullCheck(L_13);
		bool L_18;
		L_18 = InterfaceFuncInvoker2< bool, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_13, L_16, L_17);
		if (!L_18)
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_19 = V_3;
		return L_19;
	}

IL_0052:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_0063;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_0063:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tAD85978A82ACB7BE7F29D7A967D37BE653E32EBF* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_0074:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_0027;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 71596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D HashSet_1_CheckUniqueAndUnfoundElements_m63C187EFD30928C462894D854942F13172A814AA (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	RuntimeObject* V_6 = NULL;
	EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF V_7;
	memset((&V_7), 0, sizeof(V_7));
	int32_t V_8 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_004f;
		}
	}
	{
		V_5 = 0;
		RuntimeObject* L_1 = ___0_other;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_1);
		V_6 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_3 = V_6;
					if (!L_3)
					{
						goto IL_003b;
					}
				}
				{
					RuntimeObject* L_4 = V_6;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_003b:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0025_1;
			}

IL_0015_1:
			{
				RuntimeObject* L_5 = V_6;
				NullCheck(L_5);
				EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_6;
				L_6 = InterfaceFuncInvoker0< EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_5);
				int32_t L_7 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_7, 1));
				goto IL_003c;
			}

IL_0025_1:
			{
				RuntimeObject* L_8 = V_6;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0015_1;
				}
			}
			{
				goto IL_003c;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003c:
	{
		(&V_0)->___uniqueCount = 0;
		int32_t L_10 = V_5;
		(&V_0)->___unfoundCount = L_10;
		ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D L_11 = V_0;
		return L_11;
	}

IL_004f:
	{
		int32_t L_12 = __this->____lastIndex;
		int32_t L_13;
		L_13 = BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C(L_12, NULL);
		V_1 = L_13;
		int32_t L_14 = V_1;
		if ((((int32_t)L_14) > ((int32_t)((int32_t)100))))
		{
			goto IL_006f;
		}
	}
	{
		int32_t L_15 = V_1;
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		if ((uintptr_t)L_16 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_17 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_16, 4));
		int8_t* L_18;
		if (L_17 == 0)
		{
			L_18 = NULL;
		}
		else
		{
			L_18 = (int8_t*)alloca(L_17);
			memset(L_18, 0, L_17);
		}
		int32_t L_19 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_20 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3(L_20, (int32_t*)L_18, L_19, NULL);
		V_2 = L_20;
		goto IL_007c;
	}

IL_006f:
	{
		int32_t L_21 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_21);
		int32_t L_23 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_24 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19(L_24, L_22, L_23, NULL);
		V_2 = L_24;
	}

IL_007c:
	{
		V_3 = 0;
		V_4 = 0;
		RuntimeObject* L_25 = ___0_other;
		NullCheck(L_25);
		RuntimeObject* L_26;
		L_26 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_25);
		V_6 = L_26;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d1:
			{
				{
					RuntimeObject* L_27 = V_6;
					if (!L_27)
					{
						goto IL_00dc;
					}
				}
				{
					RuntimeObject* L_28 = V_6;
					NullCheck(L_28);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_28);
				}

IL_00dc:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00c6_1;
			}

IL_008b_1:
			{
				RuntimeObject* L_29 = V_6;
				NullCheck(L_29);
				EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_30;
				L_30 = InterfaceFuncInvoker0< EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_29);
				V_7 = L_30;
				EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_31 = V_7;
				int32_t L_32;
				L_32 = HashSet_1_InternalIndexOf_m60DE8DED336AAAF63A6DC608722E57026FEBCD9F(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
				V_8 = L_32;
				int32_t L_33 = V_8;
				if ((((int32_t)L_33) < ((int32_t)0)))
				{
					goto IL_00bd_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_34 = V_2;
				int32_t L_35 = V_8;
				NullCheck(L_34);
				bool L_36;
				L_36 = BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2(L_34, L_35, NULL);
				if (L_36)
				{
					goto IL_00c6_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_37 = V_2;
				int32_t L_38 = V_8;
				NullCheck(L_37);
				BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86(L_37, L_38, NULL);
				int32_t L_39 = V_4;
				V_4 = ((int32_t)il2cpp_codegen_add(L_39, 1));
				goto IL_00c6_1;
			}

IL_00bd_1:
			{
				int32_t L_40 = V_3;
				V_3 = ((int32_t)il2cpp_codegen_add(L_40, 1));
				bool L_41 = ___1_returnIfUnfound;
				if (!L_41)
				{
					goto IL_00c6_1;
				}
			}
			{
				goto IL_00dd;
			}

IL_00c6_1:
			{
				RuntimeObject* L_42 = V_6;
				NullCheck(L_42);
				bool L_43;
				L_43 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_42);
				if (L_43)
				{
					goto IL_008b_1;
				}
			}
			{
				goto IL_00dd;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00dd:
	{
		int32_t L_44 = V_4;
		(&V_0)->___uniqueCount = L_44;
		int32_t L_45 = V_3;
		(&V_0)->___unfoundCount = L_45;
		ElementCount_tB1747BE3B81DDFEE3A7C7DB07B07C8506916C49D L_46 = V_0;
		return L_46;
	}
}
// Method Definition Index: 71597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m4CE29AA365BD937A2E12C794E09E19D0CB20B8EE (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___0_set1, HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* ___1_set2, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_0 = ___0_set1;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = HashSet_1_get_Comparer_m0FDDAF4C5EBE9F2D935DA5791373DD5DFE439913_inline(L_0, NULL);
		HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* L_2 = ___1_set2;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = HashSet_1_get_Comparer_m0FDDAF4C5EBE9F2D935DA5791373DD5DFE439913_inline(L_2, NULL);
		NullCheck(L_1);
		bool L_4;
		L_4 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, L_1, L_3);
		return L_4;
	}
}
// Method Definition Index: 71598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m077082839BDD06A5353FADE1CEDBE8FD44F9CFAD (HashSet_1_tA48FADEA62F146C802EACB7CF02594C75B3B16FA* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000a;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____comparer;
		EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF L_2 = ___0_item;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_1, L_2);
		return ((int32_t)(L_3&((int32_t)2147483647LL)));
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
// Method Definition Index: 71561
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m90EA29D74B137C5317CDC485AA1D799F0B6726FF (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_0;
		L_0 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mD01A3150BFA527119EBAB7922A64F4BB94CC293D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return;
	}
}
// Method Definition Index: 71562
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mD01A3150BFA527119EBAB7922A64F4BB94CC293D (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_comparer;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_1;
		L_1 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		___0_comparer = L_1;
	}

IL_0010:
	{
		RuntimeObject* L_2 = ___0_comparer;
		__this->____comparer = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_2);
		__this->____lastIndex = 0;
		__this->____count = 0;
		__this->____freeList = (-1);
		__this->____version = 0;
		return;
	}
}
// Method Definition Index: 71563
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mB61A4173FD9D000867524949D5E105DE2C1B7D54 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_1;
		L_1 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mC8EB7E5E12FA6F38890EB2435FF06B81B3BBBB0A(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 71564
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m3F29A5426149F521CEE6900B9A4097810124ED8E (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_collection;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_1;
		L_1 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mA74E823F988E9515688F756D0DD9223AE0248596(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
// Method Definition Index: 71565
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA74E823F988E9515688F756D0DD9223AE0248596 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B8_0 = 0;
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_mD01A3150BFA527119EBAB7922A64F4BB94CC293D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		RuntimeObject* L_1 = ___0_collection;
		if (L_1)
		{
			goto IL_0015;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral469F05BE9BB4C7903C353D0EB9F6384C84A48B25)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0015:
	{
		RuntimeObject* L_3 = ___0_collection;
		V_0 = ((HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_4 = V_0;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m2D30A02470631B29664BF3981E958399DCD05E59(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_7 = V_0;
		HashSet_1_CopyFrom_m76A9036184E9E454D1A7553EF88A707525F27A8A(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return;
	}

IL_0030:
	{
		RuntimeObject* L_8 = ___0_collection;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_9 = V_1;
		if (!L_9)
		{
			goto IL_0042;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_10);
		G_B8_0 = L_11;
		goto IL_0043;
	}

IL_0042:
	{
		G_B8_0 = 0;
	}

IL_0043:
	{
		V_2 = G_B8_0;
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = HashSet_1_Initialize_m8DCCD8BD41DA4D933EB974678D99E0FFEAC5A21C(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		RuntimeObject* L_14 = ___0_collection;
		HashSet_1_UnionWith_m324C75B2D781E7BF38384F10C30AEC7668EB7CDA(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		int32_t L_15 = __this->____count;
		if ((((int32_t)L_15) <= ((int32_t)0)))
		{
			goto IL_0074;
		}
	}
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_16 = __this->____slots;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = __this->____count;
		if ((((int32_t)((int32_t)(L_17/L_18))) <= ((int32_t)3)))
		{
			goto IL_0074;
		}
	}
	{
		HashSet_1_TrimExcess_mFDA37D3F003EF52B5E93673AE3ED38E04D5DB500(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}

IL_0074:
	{
		return;
	}
}
// Method Definition Index: 71566
// Method Definition Index: 71567
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m76A9036184E9E454D1A7553EF88A707525F27A8A (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_0 = ___0_source;
		NullCheck(L_0);
		int32_t L_1 = L_0->____count;
		V_0 = L_1;
		int32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_000b;
		}
	}
	{
		return;
	}

IL_000b:
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_3 = ___0_source;
		NullCheck(L_3);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = L_3->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = L_5;
		int32_t L_6 = V_0;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(((int32_t)il2cpp_codegen_add(L_6, 1)), NULL);
		int32_t L_8 = V_1;
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0065;
		}
	}
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_9 = ___0_source;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = L_9->____buckets;
		NullCheck((RuntimeArray*)L_10);
		RuntimeObject* L_11;
		L_11 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_10, NULL);
		__this->____buckets = ((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var)));
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_12 = ___0_source;
		NullCheck(L_12);
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_13 = L_12->____slots;
		NullCheck((RuntimeArray*)L_13);
		RuntimeObject* L_14;
		L_14 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_13, NULL);
		__this->____slots = ((SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)((SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))));
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_15 = ___0_source;
		NullCheck(L_15);
		int32_t L_16 = L_15->____lastIndex;
		__this->____lastIndex = L_16;
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_17 = ___0_source;
		NullCheck(L_17);
		int32_t L_18 = L_17->____freeList;
		__this->____freeList = L_18;
		goto IL_00c7;
	}

IL_0065:
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_19 = ___0_source;
		NullCheck(L_19);
		int32_t L_20 = L_19->____lastIndex;
		V_2 = L_20;
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_21 = ___0_source;
		NullCheck(L_21);
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_22 = L_21->____slots;
		V_3 = L_22;
		int32_t L_23 = V_0;
		int32_t L_24;
		L_24 = HashSet_1_Initialize_m8DCCD8BD41DA4D933EB974678D99E0FFEAC5A21C(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		V_4 = 0;
		V_5 = 0;
		goto IL_00ba;
	}

IL_0083:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_25 = V_3;
		int32_t L_26 = V_5;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		V_6 = L_27;
		int32_t L_28 = V_6;
		if ((((int32_t)L_28) < ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		int32_t L_29 = V_4;
		int32_t L_30 = V_6;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_31 = V_3;
		int32_t L_32 = V_5;
		NullCheck(L_31);
		int32_t L_33 = ((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->___value;
		HashSet_1_AddValue_m6D3D24A6F1E5CB0ABD85841349382CE64EF2F690(__this, L_29, L_30, L_33, NULL);
		int32_t L_34 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b4:
	{
		int32_t L_35 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_35, 1));
	}

IL_00ba:
	{
		int32_t L_36 = V_5;
		int32_t L_37 = V_2;
		if ((((int32_t)L_36) < ((int32_t)L_37)))
		{
			goto IL_0083;
		}
	}
	{
		int32_t L_38 = V_4;
		__this->____lastIndex = L_38;
	}

IL_00c7:
	{
		int32_t L_39 = V_0;
		__this->____count = L_39;
		return;
	}
}
// Method Definition Index: 71568
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mC8EB7E5E12FA6F38890EB2435FF06B81B3BBBB0A (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_mD01A3150BFA527119EBAB7922A64F4BB94CC293D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0016;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0016:
	{
		int32_t L_3 = ___0_capacity;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = HashSet_1_Initialize_m8DCCD8BD41DA4D933EB974678D99E0FFEAC5A21C(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0022:
	{
		return;
	}
}
// Method Definition Index: 71569
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_System_Collections_Generic_ICollectionU3CTU3E_Add_m8DCCFBE982C11AAB3D29ED804447945A4FFC110B (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_m43D6B3CAAED91ED49E0194803AC6BA67ADF6439B(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return;
	}
}
// Method Definition Index: 71570
// Method Definition Index: 71571
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m98A9F88FF94538B5EECB0F87E1E3B3572E02ACA1 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* V_2 = NULL;
	int32_t V_3 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0080;
		}
	}
	{
		V_0 = 0;
		int32_t L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m8C50FFBACD63C1AA40F63C5C9CAA1811F5988F97(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_2;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_3 = __this->____slots;
		V_2 = L_3;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		int32_t L_5 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->____buckets;
		NullCheck(L_6);
		int32_t L_7 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_6)->max_length),NULL));
		NullCheck(L_4);
		int32_t L_8 = ((int32_t)(L_5%L_7));
		int32_t L_9 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_9, 1));
		goto IL_007c;
	}

IL_002f:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_10 = V_2;
		int32_t L_11 = V_3;
		NullCheck(L_10);
		int32_t L_12 = ((L_10)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		int32_t L_13 = V_1;
		if ((!(((uint32_t)L_12) == ((uint32_t)L_13))))
		{
			goto IL_005a;
		}
	}
	{
		RuntimeObject* L_14 = __this->____comparer;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_15 = V_2;
		int32_t L_16 = V_3;
		NullCheck(L_15);
		int32_t L_17 = ((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)))->___value;
		int32_t L_18 = ___0_item;
		NullCheck(L_14);
		bool L_19;
		L_19 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_14, L_17, L_18);
		if (!L_19)
		{
			goto IL_005a;
		}
	}
	{
		return (bool)1;
	}

IL_005a:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_006b;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_006b:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_007c:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_002f;
		}
	}

IL_0080:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71572
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mD398237C598AECB4793962F1E4DBA8BBA5DBE38B (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		int32_t L_1 = ___1_arrayIndex;
		int32_t L_2 = __this->____count;
		HashSet_1_CopyTo_m3C27BBD4EFB01EA7A8B2DE3F0E12CD9E449950DF(__this, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71573
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mF4C8539185EBCAAE0803DF227E006B701007DD65 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* V_4 = NULL;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0154;
		}
	}
	{
		int32_t L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m8C50FFBACD63C1AA40F63C5C9CAA1811F5988F97(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_2;
		int32_t L_3 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = ((int32_t)(L_3%L_5));
		V_2 = (-1);
		V_3 = 0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_6 = __this->____slots;
		V_4 = L_6;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		int32_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
		goto IL_014c;
	}

IL_003b:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_11 = V_4;
		int32_t L_12 = V_5;
		NullCheck(L_11);
		int32_t L_13 = ((L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_12)))->___hashCode;
		int32_t L_14 = V_0;
		if ((!(((uint32_t)L_13) == ((uint32_t)L_14))))
		{
			goto IL_0123;
		}
	}
	{
		RuntimeObject* L_15 = __this->____comparer;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_16 = V_4;
		int32_t L_17 = V_5;
		NullCheck(L_16);
		int32_t L_18 = ((L_16)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		int32_t L_19 = ___0_item;
		NullCheck(L_15);
		bool L_20;
		L_20 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0123;
		}
	}
	{
		int32_t L_21 = V_2;
		if ((((int32_t)L_21) >= ((int32_t)0)))
		{
			goto IL_008c;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = __this->____buckets;
		int32_t L_23 = V_1;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_24 = V_4;
		int32_t L_25 = V_5;
		NullCheck(L_24);
		int32_t L_26 = ((L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_25)))->___next;
		NullCheck(L_22);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(L_23), (int32_t)((int32_t)il2cpp_codegen_add(L_26, 1)));
		goto IL_00a7;
	}

IL_008c:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_27 = V_4;
		int32_t L_28 = V_2;
		NullCheck(L_27);
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_29 = V_4;
		int32_t L_30 = V_5;
		NullCheck(L_29);
		int32_t L_31 = ((L_29)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_30)))->___next;
		((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next = L_31;
	}

IL_00a7:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_32 = V_4;
		int32_t L_33 = V_5;
		NullCheck(L_32);
		((L_32)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_33)))->___hashCode = (-1);
		goto IL_00d1;
	}

IL_00d1:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_34 = V_4;
		int32_t L_35 = V_5;
		NullCheck(L_34);
		int32_t L_36 = __this->____freeList;
		((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_35)))->___next = L_36;
		int32_t L_37 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_subtract(L_37, 1));
		int32_t L_38 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_38, 1));
		int32_t L_39 = __this->____count;
		if (L_39)
		{
			goto IL_0119;
		}
	}
	{
		__this->____lastIndex = 0;
		__this->____freeList = (-1);
		goto IL_0121;
	}

IL_0119:
	{
		int32_t L_40 = V_5;
		__this->____freeList = L_40;
	}

IL_0121:
	{
		return (bool)1;
	}

IL_0123:
	{
		int32_t L_41 = V_3;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_42 = V_4;
		NullCheck(L_42);
		int32_t L_43 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_42)->max_length),NULL));
		if ((((int32_t)L_41) < ((int32_t)L_43)))
		{
			goto IL_0135;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_44 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_0135:
	{
		int32_t L_45 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_45, 1));
		int32_t L_46 = V_5;
		V_2 = L_46;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_47 = V_4;
		int32_t L_48 = V_5;
		NullCheck(L_47);
		int32_t L_49 = ((L_47)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_48)))->___next;
		V_5 = L_49;
	}

IL_014c:
	{
		int32_t L_50 = V_5;
		if ((((int32_t)L_50) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0154:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376 HashSet_1_GetEnumerator_m55BD13C9FD783AFB7B5B8F018E3008E05137A360 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mFE3FD5858B2622B0DB3A98E965A87270E087E292((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 71577
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mFB5AA335BD4906485CB12ED2FBFFAF51FA3F1EBB (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mFE3FD5858B2622B0DB3A98E965A87270E087E292((&L_0), __this, NULL);
		Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71578
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_IEnumerable_GetEnumerator_mE1616E3A1216DC33957C20680B934BC088CECEBA (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mFE3FD5858B2622B0DB3A98E965A87270E087E292((&L_0), __this, NULL);
		Enumerator_t28FAA6D38864A25718956AF2B8AFCB3B8CCF4376 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_GetObjectData_m225089E5EADAC464572D74B63933A7D9ACD63349 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	String_t* G_B4_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_1 = NULL;
	String_t* G_B3_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_1 = NULL;
	int32_t G_B5_0 = 0;
	String_t* G_B5_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		int32_t L_3 = __this->____version;
		NullCheck(L_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_2, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_3, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeObject* L_5 = __this->____comparer;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 27)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		NullCheck(L_4);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_4, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, L_7, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_8 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = __this->____buckets;
		if (!L_9)
		{
			G_B4_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
			G_B4_1 = L_8;
			goto IL_0052;
		}
		G_B3_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
		G_B3_1 = L_8;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		NullCheck(L_10);
		int32_t L_11 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_10)->max_length),NULL));
		G_B5_0 = L_11;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0053;
	}

IL_0052:
	{
		G_B5_0 = 0;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0053:
	{
		NullCheck(G_B5_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B5_2, G_B5_1, G_B5_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = __this->____buckets;
		if (!L_12)
		{
			goto IL_0089;
		}
	}
	{
		int32_t L_13 = __this->____count;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29), (uint32_t)L_13);
		V_0 = L_14;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = V_0;
		HashSet_1_CopyTo_mAFBFB4E9CC9508A1AE5E2FD2A63AEE373D77C409(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_16 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		NullCheck(L_16);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_16, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, (RuntimeObject*)L_17, L_19, NULL);
	}

IL_0089:
	{
		return;
	}
}
// Method Definition Index: 71580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_OnDeserialization_mE05F83949ED3974F2CB3209AA5925C2E0B62BF4B (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	int32_t V_2 = 0;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = __this->____siInfo;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		return;
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = __this->____siInfo;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_1, _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865, NULL);
		V_0 = L_2;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 32)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		NullCheck(L_3);
		RuntimeObject* L_6;
		L_6 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_3, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20))));
		__this->____freeList = (-1);
		int32_t L_7 = V_0;
		if (!L_7)
		{
			goto IL_00ad;
		}
	}
	{
		int32_t L_8 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_8);
		__this->____buckets = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_9);
		int32_t L_10 = V_0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_11 = (SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)(SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_10);
		__this->____slots = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_11);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_12 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_13 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_14;
		L_14 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_13, NULL);
		NullCheck(L_12);
		RuntimeObject* L_15;
		L_15 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_12, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, L_14, NULL);
		V_1 = ((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_15, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = V_1;
		if (L_16)
		{
			goto IL_008f;
		}
	}
	{
		SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7* L_17 = (SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_il2cpp_TypeInfo_var)));
		SerializationException__ctor_m0AAFE2ABD0A74F3E783AD5B5FE842DE460168DB0(L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC5ABE84F2ABF009EBC68D2A32EF8C171B074F922)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_008f:
	{
		V_2 = 0;
		goto IL_00a5;
	}

IL_0093:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_1;
		int32_t L_19 = V_2;
		NullCheck(L_18);
		int32_t L_20 = L_19;
		int32_t L_21 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_20));
		bool L_22;
		L_22 = HashSet_1_AddIfNotPresent_m43D6B3CAAED91ED49E0194803AC6BA67ADF6439B(__this, L_21, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_25 = V_1;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((((int32_t)L_24) < ((int32_t)L_26)))
		{
			goto IL_0093;
		}
	}
	{
		goto IL_00b4;
	}

IL_00ad:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00b4:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_27 = __this->____siInfo;
		NullCheck(L_27);
		int32_t L_28;
		L_28 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_27, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		__this->____version = L_28;
		__this->____siInfo = (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____siInfo), (void*)(SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL);
		return;
	}
}
// Method Definition Index: 71581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Add_m9B0DD9902395EE95D3DC522264BE1EBBBD3513EB (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_m43D6B3CAAED91ED49E0194803AC6BA67ADF6439B(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_1;
	}
}
// Method Definition Index: 71582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m324C75B2D781E7BF38384F10C30AEC7668EB7CDA (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_2);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_4 = V_0;
					if (!L_4)
					{
						goto IL_0039;
					}
				}
				{
					RuntimeObject* L_5 = V_0;
					NullCheck(L_5);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
				}

IL_0039:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_6 = V_0;
				NullCheck(L_6);
				int32_t L_7;
				L_7 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_6);
				V_1 = L_7;
				int32_t L_8 = V_1;
				bool L_9;
				L_9 = HashSet_1_AddIfNotPresent_m43D6B3CAAED91ED49E0194803AC6BA67ADF6439B(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
			}

IL_0026_1:
			{
				RuntimeObject* L_10 = V_0;
				NullCheck(L_10);
				bool L_11;
				L_11 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_10);
				if (L_11)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_003a;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003a:
	{
		return;
	}
}
// Method Definition Index: 71583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_SetEquals_m3824F4B9E5E10634DFA2AA9251671180FAAFEB9F (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		if ((!(((RuntimeObject*)(RuntimeObject*)L_2) == ((RuntimeObject*)(HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2*)__this))))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)1;
	}

IL_0014:
	{
		RuntimeObject* L_3 = ___0_other;
		V_0 = ((HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_4 = V_0;
		if (!L_4)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m2D30A02470631B29664BF3981E958399DCD05E59(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_003f;
		}
	}
	{
		int32_t L_7 = __this->____count;
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = HashSet_1_get_Count_mB717B519B4FBD92488427A6798B491B5FA5FB185_inline(L_8, NULL);
		if ((((int32_t)L_7) == ((int32_t)L_9)))
		{
			goto IL_0037;
		}
	}
	{
		return (bool)0;
	}

IL_0037:
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_10 = V_0;
		bool L_11;
		L_11 = HashSet_1_ContainsAllElements_m631F3C7D7E456054B308DEE064BF085F8EC99211(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return L_11;
	}

IL_003f:
	{
		RuntimeObject* L_12 = ___0_other;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_13 = V_1;
		if (!L_13)
		{
			goto IL_005c;
		}
	}
	{
		int32_t L_14 = __this->____count;
		if (L_14)
		{
			goto IL_005c;
		}
	}
	{
		RuntimeObject* L_15 = V_1;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_15);
		if ((((int32_t)L_16) <= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}
	{
		return (bool)0;
	}

IL_005c:
	{
		RuntimeObject* L_17 = ___0_other;
		ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA L_18;
		L_18 = HashSet_1_CheckUniqueAndUnfoundElements_m1FE7B070F6F535246DE7D39D368813B4CBE80B61(__this, L_17, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_2 = L_18;
		ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA L_19 = V_2;
		int32_t L_20 = L_19.___uniqueCount;
		int32_t L_21 = __this->____count;
		if ((!(((uint32_t)L_20) == ((uint32_t)L_21))))
		{
			goto IL_007d;
		}
	}
	{
		ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA L_22 = V_2;
		int32_t L_23 = L_22.___unfoundCount;
		return (bool)((((int32_t)L_23) == ((int32_t)0))? 1 : 0);
	}

IL_007d:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mAFBFB4E9CC9508A1AE5E2FD2A63AEE373D77C409 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		int32_t L_1 = __this->____count;
		HashSet_1_CopyTo_m3C27BBD4EFB01EA7A8B2DE3F0E12CD9E449950DF(__this, L_0, 0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71585
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m3C27BBD4EFB01EA7A8B2DE3F0E12CD9E449950DF (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
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
		int32_t L_2 = ___1_arrayIndex;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_3 = ___1_arrayIndex;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_6 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC00660333703C551EA80371B54D0ADCEB74C33B4)), L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0028:
	{
		int32_t L_7 = ___2_count;
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_0042;
		}
	}
	{
		int32_t L_8 = ___2_count;
		int32_t L_9 = L_8;
		RuntimeObject* L_10 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_9);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_11 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral07624473F417C06C74D59C64840A1532FCE2C626)), L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0042:
	{
		int32_t L_12 = ___1_arrayIndex;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = ___0_array;
		NullCheck(L_13);
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		if ((((int32_t)L_12) > ((int32_t)L_14)))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_15 = ___2_count;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = ___0_array;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = ___1_arrayIndex;
		if ((((int32_t)L_15) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18)))))
		{
			goto IL_005b;
		}
	}

IL_0050:
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_19 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_005b:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0097;
	}

IL_0061:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_20 = __this->____slots;
		int32_t L_21 = V_1;
		NullCheck(L_20);
		int32_t L_22 = ((L_20)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_21)))->___hashCode;
		if ((((int32_t)L_22) < ((int32_t)0)))
		{
			goto IL_0093;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = ___0_array;
		int32_t L_24 = ___1_arrayIndex;
		int32_t L_25 = V_0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_26 = __this->____slots;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		int32_t L_28 = ((L_26)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_27)))->___value;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_24, L_25))), (int32_t)L_28);
		int32_t L_29 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0093:
	{
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_0097:
	{
		int32_t L_31 = V_1;
		int32_t L_32 = __this->____lastIndex;
		if ((((int32_t)L_31) >= ((int32_t)L_32)))
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___2_count;
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0061;
		}
	}

IL_00a4:
	{
		return;
	}
}
// Method Definition Index: 71586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_RemoveWhere_m14A96615AA5F5F1497A6E01A5DF2BF13F022325E (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE2EEFB4BE0C9F57BA62E733F26387F8BA68AF67C)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0054;
	}

IL_0014:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_2 = __this->____slots;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = ((L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0050;
		}
	}
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_5 = __this->____slots;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = ((L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		V_2 = L_7;
		Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3* L_8 = ___0_match;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		bool L_10;
		L_10 = Predicate_1_Invoke_mD16C664FFE93598D1C12AC86190D12B0F90B5419_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_11 = V_2;
		bool L_12;
		L_12 = HashSet_1_Remove_mF4C8539185EBCAAE0803DF227E006B701007DD65(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		if (!L_12)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0050:
	{
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0054:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = __this->____lastIndex;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_17 = V_0;
		return L_17;
	}
}
// Method Definition Index: 71587
// Method Definition Index: 71588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mFDA37D3F003EF52B5E93673AE3ED38E04D5DB500 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_0025;
		}
	}
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
		__this->____slots = (SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)(SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)NULL);
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		return;
	}

IL_0025:
	{
		int32_t L_2 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_3;
		L_3 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_2, NULL);
		V_0 = L_3;
		int32_t L_4 = V_0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_5 = (SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)(SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		V_1 = L_5;
		int32_t L_6 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_2 = L_7;
		V_3 = 0;
		V_4 = 0;
		goto IL_00a2;
	}

IL_0046:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_8 = __this->____slots;
		int32_t L_9 = V_4;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_009c;
		}
	}
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_11 = V_1;
		int32_t L_12 = V_3;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_13 = __this->____slots;
		int32_t L_14 = V_4;
		NullCheck(L_13);
		int32_t L_15 = L_14;
		Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8)L_16);
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_17 = V_1;
		int32_t L_18 = V_3;
		NullCheck(L_17);
		int32_t L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_0;
		V_5 = ((int32_t)(L_19%L_20));
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_21 = V_1;
		int32_t L_22 = V_3;
		NullCheck(L_21);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_2;
		int32_t L_24 = V_5;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		int32_t L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		((L_21)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_22)))->___next = ((int32_t)il2cpp_codegen_subtract(L_26, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = V_2;
		int32_t L_28 = V_5;
		int32_t L_29 = V_3;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)il2cpp_codegen_add(L_29, 1)));
		int32_t L_30 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_009c:
	{
		int32_t L_31 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_00a2:
	{
		int32_t L_32 = V_4;
		int32_t L_33 = __this->____lastIndex;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_34 = V_3;
		__this->____lastIndex = L_34;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_35 = V_1;
		__this->____slots = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_35);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_2;
		__this->____buckets = L_36;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_36);
		__this->____freeList = (-1);
		return;
	}
}
// Method Definition Index: 71589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m8DCCD8BD41DA4D933EB974678D99E0FFEAC5A21C (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_5 = (SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)(SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		__this->____slots = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 71590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m7EE99125BBB78B18669A0B9760A5F6E4A01454FF (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____count;
		if ((((int32_t)L_2) > ((int32_t)L_3)))
		{
			goto IL_0020;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral91930CCAB5CB8F6F327407F9A14CF42F57A0F27B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = V_0;
		HashSet_1_SetCapacity_m6B2495F23F97908BC4EE3B987C1F16093E922C62(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 71591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m6B2495F23F97908BC4EE3B987C1F16093E922C62 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_newSize, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* V_0 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		int32_t L_0 = ___0_newSize;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_1 = (SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)(SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_0);
		V_0 = L_1;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_2 = __this->____slots;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_3 = __this->____slots;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_4 = V_0;
		int32_t L_5 = __this->____lastIndex;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, L_5, NULL);
	}

IL_0023:
	{
		int32_t L_6 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_1 = L_7;
		V_2 = 0;
		goto IL_0058;
	}

IL_002e:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_8 = V_0;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		int32_t L_11 = ___0_newSize;
		V_3 = ((int32_t)(L_10%L_11));
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_12 = V_0;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = V_1;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = L_15;
		int32_t L_17 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___next = ((int32_t)il2cpp_codegen_subtract(L_17, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_1;
		int32_t L_19 = V_3;
		int32_t L_20 = V_2;
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(L_19), (int32_t)((int32_t)il2cpp_codegen_add(L_20, 1)));
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_0058:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = __this->____lastIndex;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_002e;
		}
	}
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_24 = V_0;
		__this->____slots = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_24);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_25 = V_1;
		__this->____buckets = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_25);
		return;
	}
}
// Method Definition Index: 71592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_m43D6B3CAAED91ED49E0194803AC6BA67ADF6439B (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1;
		L_1 = HashSet_1_Initialize_m8DCCD8BD41DA4D933EB974678D99E0FFEAC5A21C(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0010:
	{
		int32_t L_2 = ___0_value;
		int32_t L_3;
		L_3 = HashSet_1_InternalGetHashCode_m8C50FFBACD63C1AA40F63C5C9CAA1811F5988F97(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_3;
		int32_t L_4 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		V_1 = ((int32_t)(L_4%L_6));
		V_2 = 0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_7 = __this->____slots;
		V_3 = L_7;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		int32_t L_11 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		goto IL_008b;
	}

IL_003a:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_12 = V_3;
		int32_t L_13 = V_5;
		NullCheck(L_12);
		int32_t L_14 = ((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		int32_t L_15 = V_0;
		if ((!(((uint32_t)L_14) == ((uint32_t)L_15))))
		{
			goto IL_0067;
		}
	}
	{
		RuntimeObject* L_16 = __this->____comparer;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_17 = V_3;
		int32_t L_18 = V_5;
		NullCheck(L_17);
		int32_t L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___value;
		int32_t L_20 = ___0_value;
		NullCheck(L_16);
		bool L_21;
		L_21 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_16, L_19, L_20);
		if (!L_21)
		{
			goto IL_0067;
		}
	}
	{
		return (bool)0;
	}

IL_0067:
	{
		int32_t L_22 = V_2;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_23 = V_3;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		if ((((int32_t)L_22) < ((int32_t)L_24)))
		{
			goto IL_0078;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_25 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_25, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_25, method);
	}

IL_0078:
	{
		int32_t L_26 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_27 = V_3;
		int32_t L_28 = V_5;
		NullCheck(L_27);
		int32_t L_29 = ((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_5 = L_29;
	}

IL_008b:
	{
		int32_t L_30 = V_5;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_31 = __this->____freeList;
		if ((((int32_t)L_31) < ((int32_t)0)))
		{
			goto IL_00b6;
		}
	}
	{
		int32_t L_32 = __this->____freeList;
		V_4 = L_32;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_33 = V_3;
		int32_t L_34 = V_4;
		NullCheck(L_33);
		int32_t L_35 = ((L_33)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_34)))->___next;
		__this->____freeList = L_35;
		goto IL_00ef;
	}

IL_00b6:
	{
		int32_t L_36 = __this->____lastIndex;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_37 = V_3;
		NullCheck(L_37);
		int32_t L_38 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_37)->max_length),NULL));
		if ((!(((uint32_t)L_36) == ((uint32_t)L_38))))
		{
			goto IL_00d9;
		}
	}
	{
		HashSet_1_IncreaseCapacity_m7EE99125BBB78B18669A0B9760A5F6E4A01454FF(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_39 = __this->____slots;
		V_3 = L_39;
		int32_t L_40 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = __this->____buckets;
		NullCheck(L_41);
		int32_t L_42 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_41)->max_length),NULL));
		V_1 = ((int32_t)(L_40%L_42));
	}

IL_00d9:
	{
		int32_t L_43 = __this->____lastIndex;
		V_4 = L_43;
		int32_t L_44 = __this->____lastIndex;
		__this->____lastIndex = ((int32_t)il2cpp_codegen_add(L_44, 1));
	}

IL_00ef:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_45 = V_3;
		int32_t L_46 = V_4;
		NullCheck(L_45);
		int32_t L_47 = V_0;
		((L_45)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_46)))->___hashCode = L_47;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_48 = V_3;
		int32_t L_49 = V_4;
		NullCheck(L_48);
		int32_t L_50 = ___0_value;
		((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value = L_50;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_51 = V_3;
		int32_t L_52 = V_4;
		NullCheck(L_51);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_53 = __this->____buckets;
		int32_t L_54 = V_1;
		NullCheck(L_53);
		int32_t L_55 = L_54;
		int32_t L_56 = (L_53)->GetAt(static_cast<il2cpp_array_size_t>(L_55));
		((L_51)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_52)))->___next = ((int32_t)il2cpp_codegen_subtract(L_56, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = __this->____buckets;
		int32_t L_58 = V_1;
		int32_t L_59 = V_4;
		NullCheck(L_57);
		(L_57)->SetAt(static_cast<il2cpp_array_size_t>(L_58), (int32_t)((int32_t)il2cpp_codegen_add(L_59, 1)));
		int32_t L_60 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_60, 1));
		int32_t L_61 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_61, 1));
		return (bool)1;
	}
}
// Method Definition Index: 71593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m6D3D24A6F1E5CB0ABD85841349382CE64EF2F690 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_index, int32_t ___1_hashCode, int32_t ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_hashCode;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		V_0 = ((int32_t)(L_0%L_2));
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_3 = __this->____slots;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = ___1_hashCode;
		((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)))->___hashCode = L_5;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_6 = __this->____slots;
		int32_t L_7 = ___0_index;
		NullCheck(L_6);
		int32_t L_8 = ___2_value;
		((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value = L_8;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_9 = __this->____slots;
		int32_t L_10 = ___0_index;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___next = ((int32_t)il2cpp_codegen_subtract(L_14, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = __this->____buckets;
		int32_t L_16 = V_0;
		int32_t L_17 = ___0_index;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(L_16), (int32_t)((int32_t)il2cpp_codegen_add(L_17, 1)));
		return;
	}
}
// Method Definition Index: 71594
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m631F3C7D7E456054B308DEE064BF085F8EC99211 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	bool V_2 = false;
	{
		RuntimeObject* L_0 = ___0_other;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_0030;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_0030:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				int32_t L_5;
				L_5 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_4);
				V_1 = L_5;
				int32_t L_6 = V_1;
				bool L_7;
				L_7 = HashSet_1_Contains_m98A9F88FF94538B5EECB0F87E1E3B3572E02ACA1(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
				if (L_7)
				{
					goto IL_001d_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0033;
			}

IL_001d_1:
			{
				RuntimeObject* L_8 = V_0;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0031;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0031:
	{
		return (bool)1;
	}

IL_0033:
	{
		bool L_10 = V_2;
		return L_10;
	}
}
// Method Definition Index: 71595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m25B685122812ED3363A4B27873DF75996E749592 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* V_2 = NULL;
	int32_t V_3 = 0;
	{
		V_0 = 0;
		int32_t L_0 = ___0_item;
		int32_t L_1;
		L_1 = HashSet_1_InternalGetHashCode_m8C50FFBACD63C1AA40F63C5C9CAA1811F5988F97(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_1;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_2 = __this->____slots;
		V_2 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = __this->____buckets;
		int32_t L_4 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NullCheck(L_3);
		int32_t L_7 = ((int32_t)(L_4%L_6));
		int32_t L_8 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		goto IL_0074;
	}

IL_0027:
	{
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_9 = V_2;
		int32_t L_10 = V_3;
		NullCheck(L_9);
		int32_t L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___hashCode;
		int32_t L_12 = V_1;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_12))))
		{
			goto IL_0052;
		}
	}
	{
		RuntimeObject* L_13 = __this->____comparer;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_14 = V_2;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = ((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)))->___value;
		int32_t L_17 = ___0_item;
		NullCheck(L_13);
		bool L_18;
		L_18 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_13, L_16, L_17);
		if (!L_18)
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_19 = V_3;
		return L_19;
	}

IL_0052:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_0063;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_0063:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tC4D7CD3E804DC835CCF2F990797BC1D9AE4330D7* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_0074:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_0027;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 71596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA HashSet_1_CheckUniqueAndUnfoundElements_m1FE7B070F6F535246DE7D39D368813B4CBE80B61 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	RuntimeObject* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_004f;
		}
	}
	{
		V_5 = 0;
		RuntimeObject* L_1 = ___0_other;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_1);
		V_6 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_3 = V_6;
					if (!L_3)
					{
						goto IL_003b;
					}
				}
				{
					RuntimeObject* L_4 = V_6;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_003b:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0025_1;
			}

IL_0015_1:
			{
				RuntimeObject* L_5 = V_6;
				NullCheck(L_5);
				int32_t L_6;
				L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_5);
				int32_t L_7 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_7, 1));
				goto IL_003c;
			}

IL_0025_1:
			{
				RuntimeObject* L_8 = V_6;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0015_1;
				}
			}
			{
				goto IL_003c;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003c:
	{
		(&V_0)->___uniqueCount = 0;
		int32_t L_10 = V_5;
		(&V_0)->___unfoundCount = L_10;
		ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA L_11 = V_0;
		return L_11;
	}

IL_004f:
	{
		int32_t L_12 = __this->____lastIndex;
		int32_t L_13;
		L_13 = BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C(L_12, NULL);
		V_1 = L_13;
		int32_t L_14 = V_1;
		if ((((int32_t)L_14) > ((int32_t)((int32_t)100))))
		{
			goto IL_006f;
		}
	}
	{
		int32_t L_15 = V_1;
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		if ((uintptr_t)L_16 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_17 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_16, 4));
		int8_t* L_18;
		if (L_17 == 0)
		{
			L_18 = NULL;
		}
		else
		{
			L_18 = (int8_t*)alloca(L_17);
			memset(L_18, 0, L_17);
		}
		int32_t L_19 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_20 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3(L_20, (int32_t*)L_18, L_19, NULL);
		V_2 = L_20;
		goto IL_007c;
	}

IL_006f:
	{
		int32_t L_21 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_21);
		int32_t L_23 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_24 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19(L_24, L_22, L_23, NULL);
		V_2 = L_24;
	}

IL_007c:
	{
		V_3 = 0;
		V_4 = 0;
		RuntimeObject* L_25 = ___0_other;
		NullCheck(L_25);
		RuntimeObject* L_26;
		L_26 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_25);
		V_6 = L_26;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d1:
			{
				{
					RuntimeObject* L_27 = V_6;
					if (!L_27)
					{
						goto IL_00dc;
					}
				}
				{
					RuntimeObject* L_28 = V_6;
					NullCheck(L_28);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_28);
				}

IL_00dc:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00c6_1;
			}

IL_008b_1:
			{
				RuntimeObject* L_29 = V_6;
				NullCheck(L_29);
				int32_t L_30;
				L_30 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_29);
				V_7 = L_30;
				int32_t L_31 = V_7;
				int32_t L_32;
				L_32 = HashSet_1_InternalIndexOf_m25B685122812ED3363A4B27873DF75996E749592(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
				V_8 = L_32;
				int32_t L_33 = V_8;
				if ((((int32_t)L_33) < ((int32_t)0)))
				{
					goto IL_00bd_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_34 = V_2;
				int32_t L_35 = V_8;
				NullCheck(L_34);
				bool L_36;
				L_36 = BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2(L_34, L_35, NULL);
				if (L_36)
				{
					goto IL_00c6_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_37 = V_2;
				int32_t L_38 = V_8;
				NullCheck(L_37);
				BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86(L_37, L_38, NULL);
				int32_t L_39 = V_4;
				V_4 = ((int32_t)il2cpp_codegen_add(L_39, 1));
				goto IL_00c6_1;
			}

IL_00bd_1:
			{
				int32_t L_40 = V_3;
				V_3 = ((int32_t)il2cpp_codegen_add(L_40, 1));
				bool L_41 = ___1_returnIfUnfound;
				if (!L_41)
				{
					goto IL_00c6_1;
				}
			}
			{
				goto IL_00dd;
			}

IL_00c6_1:
			{
				RuntimeObject* L_42 = V_6;
				NullCheck(L_42);
				bool L_43;
				L_43 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_42);
				if (L_43)
				{
					goto IL_008b_1;
				}
			}
			{
				goto IL_00dd;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00dd:
	{
		int32_t L_44 = V_4;
		(&V_0)->___uniqueCount = L_44;
		int32_t L_45 = V_3;
		(&V_0)->___unfoundCount = L_45;
		ElementCount_tB5ABF4ACED337501C26C43FFD9F6FBB0CE3483AA L_46 = V_0;
		return L_46;
	}
}
// Method Definition Index: 71597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m2D30A02470631B29664BF3981E958399DCD05E59 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___0_set1, HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___1_set2, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_0 = ___0_set1;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = HashSet_1_get_Comparer_m2DD3885BF267920FC8AD5DCD6EA6A6250ABFE3AD_inline(L_0, NULL);
		HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* L_2 = ___1_set2;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = HashSet_1_get_Comparer_m2DD3885BF267920FC8AD5DCD6EA6A6250ABFE3AD_inline(L_2, NULL);
		NullCheck(L_1);
		bool L_4;
		L_4 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, L_1, L_3);
		return L_4;
	}
}
// Method Definition Index: 71598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m8C50FFBACD63C1AA40F63C5C9CAA1811F5988F97 (HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000a;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____comparer;
		int32_t L_2 = ___0_item;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_1, L_2);
		return ((int32_t)(L_3&((int32_t)2147483647LL)));
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
// Method Definition Index: 71561
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mCCBBA7A7E1C76C56AA42BDB67DD077178C0A828F (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_0;
		L_0 = EqualityComparer_1_get_Default_m33839529811E5B677FAC3708C8617567B0D8A1AB_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mA593337684C1715F8F7DDDE4399536CB8767D9AE(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return;
	}
}
// Method Definition Index: 71562
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mA593337684C1715F8F7DDDE4399536CB8767D9AE (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_comparer;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_1;
		L_1 = EqualityComparer_1_get_Default_m33839529811E5B677FAC3708C8617567B0D8A1AB_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		___0_comparer = L_1;
	}

IL_0010:
	{
		RuntimeObject* L_2 = ___0_comparer;
		__this->____comparer = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_2);
		__this->____lastIndex = 0;
		__this->____count = 0;
		__this->____freeList = (-1);
		__this->____version = 0;
		return;
	}
}
// Method Definition Index: 71563
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m3CEFDA5A9AFB1AF5D55005C81FF129DB1F4529FA (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_1;
		L_1 = EqualityComparer_1_get_Default_m33839529811E5B677FAC3708C8617567B0D8A1AB_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m48DF5063EEA93A7753ECFC022584BC5879F67BB3(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 71564
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mB44CEE232ED8200AA578E856F0120001CD8959BF (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_collection;
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_1;
		L_1 = EqualityComparer_1_get_Default_m33839529811E5B677FAC3708C8617567B0D8A1AB_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mE79F5A3C8490054B23264CA3292ED4ECD6AE7A1E(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
// Method Definition Index: 71565
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mE79F5A3C8490054B23264CA3292ED4ECD6AE7A1E (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B8_0 = 0;
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_mA593337684C1715F8F7DDDE4399536CB8767D9AE(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		RuntimeObject* L_1 = ___0_collection;
		if (L_1)
		{
			goto IL_0015;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral469F05BE9BB4C7903C353D0EB9F6384C84A48B25)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0015:
	{
		RuntimeObject* L_3 = ___0_collection;
		V_0 = ((HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_4 = V_0;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_mEE3BE892E186C9374F85D41990FB9EC272705F9C(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_7 = V_0;
		HashSet_1_CopyFrom_m9D129AAD52690789DC1E875DA22208A523541411(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return;
	}

IL_0030:
	{
		RuntimeObject* L_8 = ___0_collection;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_9 = V_1;
		if (!L_9)
		{
			goto IL_0042;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_10);
		G_B8_0 = L_11;
		goto IL_0043;
	}

IL_0042:
	{
		G_B8_0 = 0;
	}

IL_0043:
	{
		V_2 = G_B8_0;
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = HashSet_1_Initialize_m12456C0B5F2BD37BD07B7CFDA9F116F25281B6D1(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		RuntimeObject* L_14 = ___0_collection;
		HashSet_1_UnionWith_mE7E76F7B64EAB9DB84193329E6DE509AA98D922A(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		int32_t L_15 = __this->____count;
		if ((((int32_t)L_15) <= ((int32_t)0)))
		{
			goto IL_0074;
		}
	}
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_16 = __this->____slots;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = __this->____count;
		if ((((int32_t)((int32_t)(L_17/L_18))) <= ((int32_t)3)))
		{
			goto IL_0074;
		}
	}
	{
		HashSet_1_TrimExcess_mF4BE03AACFEFADB2AF97B062CCBF788B4B45B8D3(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}

IL_0074:
	{
		return;
	}
}
// Method Definition Index: 71566
// Method Definition Index: 71567
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_m9D129AAD52690789DC1E875DA22208A523541411 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_0 = ___0_source;
		NullCheck(L_0);
		int32_t L_1 = L_0->____count;
		V_0 = L_1;
		int32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_000b;
		}
	}
	{
		return;
	}

IL_000b:
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_3 = ___0_source;
		NullCheck(L_3);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = L_3->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = L_5;
		int32_t L_6 = V_0;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(((int32_t)il2cpp_codegen_add(L_6, 1)), NULL);
		int32_t L_8 = V_1;
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0065;
		}
	}
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_9 = ___0_source;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = L_9->____buckets;
		NullCheck((RuntimeArray*)L_10);
		RuntimeObject* L_11;
		L_11 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_10, NULL);
		__this->____buckets = ((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var)));
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_12 = ___0_source;
		NullCheck(L_12);
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_13 = L_12->____slots;
		NullCheck((RuntimeArray*)L_13);
		RuntimeObject* L_14;
		L_14 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_13, NULL);
		__this->____slots = ((SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)((SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))));
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_15 = ___0_source;
		NullCheck(L_15);
		int32_t L_16 = L_15->____lastIndex;
		__this->____lastIndex = L_16;
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_17 = ___0_source;
		NullCheck(L_17);
		int32_t L_18 = L_17->____freeList;
		__this->____freeList = L_18;
		goto IL_00c7;
	}

IL_0065:
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_19 = ___0_source;
		NullCheck(L_19);
		int32_t L_20 = L_19->____lastIndex;
		V_2 = L_20;
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_21 = ___0_source;
		NullCheck(L_21);
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_22 = L_21->____slots;
		V_3 = L_22;
		int32_t L_23 = V_0;
		int32_t L_24;
		L_24 = HashSet_1_Initialize_m12456C0B5F2BD37BD07B7CFDA9F116F25281B6D1(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		V_4 = 0;
		V_5 = 0;
		goto IL_00ba;
	}

IL_0083:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_25 = V_3;
		int32_t L_26 = V_5;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		V_6 = L_27;
		int32_t L_28 = V_6;
		if ((((int32_t)L_28) < ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		int32_t L_29 = V_4;
		int32_t L_30 = V_6;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_31 = V_3;
		int32_t L_32 = V_5;
		NullCheck(L_31);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_33 = ((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->___value;
		HashSet_1_AddValue_mE3EB6B7254469CC1B786252C4CC9E221D59D5D70(__this, L_29, L_30, L_33, NULL);
		int32_t L_34 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b4:
	{
		int32_t L_35 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_35, 1));
	}

IL_00ba:
	{
		int32_t L_36 = V_5;
		int32_t L_37 = V_2;
		if ((((int32_t)L_36) < ((int32_t)L_37)))
		{
			goto IL_0083;
		}
	}
	{
		int32_t L_38 = V_4;
		__this->____lastIndex = L_38;
	}

IL_00c7:
	{
		int32_t L_39 = V_0;
		__this->____count = L_39;
		return;
	}
}
// Method Definition Index: 71568
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m48DF5063EEA93A7753ECFC022584BC5879F67BB3 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_mA593337684C1715F8F7DDDE4399536CB8767D9AE(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0016;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0016:
	{
		int32_t L_3 = ___0_capacity;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = HashSet_1_Initialize_m12456C0B5F2BD37BD07B7CFDA9F116F25281B6D1(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0022:
	{
		return;
	}
}
// Method Definition Index: 71569
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_System_Collections_Generic_ICollectionU3CTU3E_Add_mE54F826F3B1DE031E41B427D02252DFCFFD14965 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mA1B61994FAB542B6C40F2B1F6BDD417501CDA050(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return;
	}
}
// Method Definition Index: 71570
// Method Definition Index: 71571
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m208059B8D89BB100809C7CA51253201A3B504A0B (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* V_2 = NULL;
	int32_t V_3 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0080;
		}
	}
	{
		V_0 = 0;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_mA1CB8FE8A84C5D1386228D2ABBC9BCB047D163AB(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_2;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_3 = __this->____slots;
		V_2 = L_3;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		int32_t L_5 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->____buckets;
		NullCheck(L_6);
		int32_t L_7 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_6)->max_length),NULL));
		NullCheck(L_4);
		int32_t L_8 = ((int32_t)(L_5%L_7));
		int32_t L_9 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_9, 1));
		goto IL_007c;
	}

IL_002f:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_10 = V_2;
		int32_t L_11 = V_3;
		NullCheck(L_10);
		int32_t L_12 = ((L_10)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		int32_t L_13 = V_1;
		if ((!(((uint32_t)L_12) == ((uint32_t)L_13))))
		{
			goto IL_005a;
		}
	}
	{
		RuntimeObject* L_14 = __this->____comparer;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_15 = V_2;
		int32_t L_16 = V_3;
		NullCheck(L_15);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_17 = ((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)))->___value;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_18 = ___0_item;
		NullCheck(L_14);
		bool L_19;
		L_19 = InterfaceFuncInvoker2< bool, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_14, L_17, L_18);
		if (!L_19)
		{
			goto IL_005a;
		}
	}
	{
		return (bool)1;
	}

IL_005a:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_006b;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_006b:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_007c:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_002f;
		}
	}

IL_0080:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71572
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mC37F16C733A0C792834FE98C79BB2F0B5F7D64F9 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_0 = ___0_array;
		int32_t L_1 = ___1_arrayIndex;
		int32_t L_2 = __this->____count;
		HashSet_1_CopyTo_mCCACCE15A67A4C2F57BBCEE9FF8856544DC2CF2F(__this, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71573
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mDCCB1329C655014754502005D24A65823666CA5A (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* V_4 = NULL;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0154;
		}
	}
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_mA1CB8FE8A84C5D1386228D2ABBC9BCB047D163AB(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_2;
		int32_t L_3 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = ((int32_t)(L_3%L_5));
		V_2 = (-1);
		V_3 = 0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_6 = __this->____slots;
		V_4 = L_6;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		int32_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
		goto IL_014c;
	}

IL_003b:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_11 = V_4;
		int32_t L_12 = V_5;
		NullCheck(L_11);
		int32_t L_13 = ((L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_12)))->___hashCode;
		int32_t L_14 = V_0;
		if ((!(((uint32_t)L_13) == ((uint32_t)L_14))))
		{
			goto IL_0123;
		}
	}
	{
		RuntimeObject* L_15 = __this->____comparer;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_16 = V_4;
		int32_t L_17 = V_5;
		NullCheck(L_16);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_18 = ((L_16)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_19 = ___0_item;
		NullCheck(L_15);
		bool L_20;
		L_20 = InterfaceFuncInvoker2< bool, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0123;
		}
	}
	{
		int32_t L_21 = V_2;
		if ((((int32_t)L_21) >= ((int32_t)0)))
		{
			goto IL_008c;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = __this->____buckets;
		int32_t L_23 = V_1;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_24 = V_4;
		int32_t L_25 = V_5;
		NullCheck(L_24);
		int32_t L_26 = ((L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_25)))->___next;
		NullCheck(L_22);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(L_23), (int32_t)((int32_t)il2cpp_codegen_add(L_26, 1)));
		goto IL_00a7;
	}

IL_008c:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_27 = V_4;
		int32_t L_28 = V_2;
		NullCheck(L_27);
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_29 = V_4;
		int32_t L_30 = V_5;
		NullCheck(L_29);
		int32_t L_31 = ((L_29)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_30)))->___next;
		((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next = L_31;
	}

IL_00a7:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_32 = V_4;
		int32_t L_33 = V_5;
		NullCheck(L_32);
		((L_32)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_33)))->___hashCode = (-1);
	}
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_34 = V_4;
		int32_t L_35 = V_5;
		NullCheck(L_34);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* L_36 = (InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735*)(&((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_35)))->___value);
		il2cpp_codegen_initobj(L_36, sizeof(InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735));
	}

IL_00d1:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_37 = V_4;
		int32_t L_38 = V_5;
		NullCheck(L_37);
		int32_t L_39 = __this->____freeList;
		((L_37)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_38)))->___next = L_39;
		int32_t L_40 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_subtract(L_40, 1));
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = __this->____count;
		if (L_42)
		{
			goto IL_0119;
		}
	}
	{
		__this->____lastIndex = 0;
		__this->____freeList = (-1);
		goto IL_0121;
	}

IL_0119:
	{
		int32_t L_43 = V_5;
		__this->____freeList = L_43;
	}

IL_0121:
	{
		return (bool)1;
	}

IL_0123:
	{
		int32_t L_44 = V_3;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_45 = V_4;
		NullCheck(L_45);
		int32_t L_46 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_45)->max_length),NULL));
		if ((((int32_t)L_44) < ((int32_t)L_46)))
		{
			goto IL_0135;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_47 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_47, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_47, method);
	}

IL_0135:
	{
		int32_t L_48 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_48, 1));
		int32_t L_49 = V_5;
		V_2 = L_49;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_50 = V_4;
		int32_t L_51 = V_5;
		NullCheck(L_50);
		int32_t L_52 = ((L_50)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_51)))->___next;
		V_5 = L_52;
	}

IL_014c:
	{
		int32_t L_53 = V_5;
		if ((((int32_t)L_53) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0154:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2 HashSet_1_GetEnumerator_mBFD95C9855C3832DAEAEA8C73E0CA35B78E718E0 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m95D3F3FF905181D3CD46CD2426F4F37FD426B81C((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 71577
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m9B71E050942AF2DF503B91F095E91A0DE13C5AE1 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m95D3F3FF905181D3CD46CD2426F4F37FD426B81C((&L_0), __this, NULL);
		Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71578
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_IEnumerable_GetEnumerator_mEDCBDF387EB71BF2FC73D1DAF9A2605296BF4CD3 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m95D3F3FF905181D3CD46CD2426F4F37FD426B81C((&L_0), __this, NULL);
		Enumerator_tEB94B2558F92A47485AA174C64C70B81F71AD5D2 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_GetObjectData_m3EA07CB405178425AAE9EE459AFC9707178BCB08 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* V_0 = NULL;
	String_t* G_B4_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_1 = NULL;
	String_t* G_B3_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_1 = NULL;
	int32_t G_B5_0 = 0;
	String_t* G_B5_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		int32_t L_3 = __this->____version;
		NullCheck(L_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_2, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_3, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeObject* L_5 = __this->____comparer;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 27)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		NullCheck(L_4);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_4, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, L_7, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_8 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = __this->____buckets;
		if (!L_9)
		{
			G_B4_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
			G_B4_1 = L_8;
			goto IL_0052;
		}
		G_B3_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
		G_B3_1 = L_8;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		NullCheck(L_10);
		int32_t L_11 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_10)->max_length),NULL));
		G_B5_0 = L_11;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0053;
	}

IL_0052:
	{
		G_B5_0 = 0;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0053:
	{
		NullCheck(G_B5_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B5_2, G_B5_1, G_B5_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = __this->____buckets;
		if (!L_12)
		{
			goto IL_0089;
		}
	}
	{
		int32_t L_13 = __this->____count;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_14 = (InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5*)(InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29), (uint32_t)L_13);
		V_0 = L_14;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_15 = V_0;
		HashSet_1_CopyTo_mEE0682F788B7CB4A00C5FD93576ABF58350CF2FD(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_16 = ___0_info;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_17 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		NullCheck(L_16);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_16, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, (RuntimeObject*)L_17, L_19, NULL);
	}

IL_0089:
	{
		return;
	}
}
// Method Definition Index: 71580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_OnDeserialization_m082B963E72C36EC10B68BE5002612E307632931A (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* V_1 = NULL;
	int32_t V_2 = 0;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = __this->____siInfo;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		return;
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = __this->____siInfo;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_1, _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865, NULL);
		V_0 = L_2;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 32)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		NullCheck(L_3);
		RuntimeObject* L_6;
		L_6 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_3, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20))));
		__this->____freeList = (-1);
		int32_t L_7 = V_0;
		if (!L_7)
		{
			goto IL_00ad;
		}
	}
	{
		int32_t L_8 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_8);
		__this->____buckets = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_9);
		int32_t L_10 = V_0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_11 = (SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)(SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_10);
		__this->____slots = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_11);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_12 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_13 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_14;
		L_14 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_13, NULL);
		NullCheck(L_12);
		RuntimeObject* L_15;
		L_15 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_12, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, L_14, NULL);
		V_1 = ((InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5*)CastclassSealed((RuntimeObject*)L_15, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29)));
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_16 = V_1;
		if (L_16)
		{
			goto IL_008f;
		}
	}
	{
		SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7* L_17 = (SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_il2cpp_TypeInfo_var)));
		SerializationException__ctor_m0AAFE2ABD0A74F3E783AD5B5FE842DE460168DB0(L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC5ABE84F2ABF009EBC68D2A32EF8C171B074F922)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_008f:
	{
		V_2 = 0;
		goto IL_00a5;
	}

IL_0093:
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_18 = V_1;
		int32_t L_19 = V_2;
		NullCheck(L_18);
		int32_t L_20 = L_19;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_21 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_20));
		bool L_22;
		L_22 = HashSet_1_AddIfNotPresent_mA1B61994FAB542B6C40F2B1F6BDD417501CDA050(__this, L_21, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_2;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_25 = V_1;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((((int32_t)L_24) < ((int32_t)L_26)))
		{
			goto IL_0093;
		}
	}
	{
		goto IL_00b4;
	}

IL_00ad:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00b4:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_27 = __this->____siInfo;
		NullCheck(L_27);
		int32_t L_28;
		L_28 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_27, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		__this->____version = L_28;
		__this->____siInfo = (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____siInfo), (void*)(SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL);
		return;
	}
}
// Method Definition Index: 71581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Add_m2E138E1B572E38E2A758B658241F9AB54D84863E (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mA1B61994FAB542B6C40F2B1F6BDD417501CDA050(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_1;
	}
}
// Method Definition Index: 71582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_mE7E76F7B64EAB9DB84193329E6DE509AA98D922A (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_2);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_4 = V_0;
					if (!L_4)
					{
						goto IL_0039;
					}
				}
				{
					RuntimeObject* L_5 = V_0;
					NullCheck(L_5);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
				}

IL_0039:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_6 = V_0;
				NullCheck(L_6);
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_7;
				L_7 = InterfaceFuncInvoker0< InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_6);
				V_1 = L_7;
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_8 = V_1;
				bool L_9;
				L_9 = HashSet_1_AddIfNotPresent_mA1B61994FAB542B6C40F2B1F6BDD417501CDA050(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
			}

IL_0026_1:
			{
				RuntimeObject* L_10 = V_0;
				NullCheck(L_10);
				bool L_11;
				L_11 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_10);
				if (L_11)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_003a;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003a:
	{
		return;
	}
}
// Method Definition Index: 71583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_SetEquals_mB9E27666D1A51BE7E3B736FFA46278E936B7C8B4 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		if ((!(((RuntimeObject*)(RuntimeObject*)L_2) == ((RuntimeObject*)(HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B*)__this))))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)1;
	}

IL_0014:
	{
		RuntimeObject* L_3 = ___0_other;
		V_0 = ((HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_4 = V_0;
		if (!L_4)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_mEE3BE892E186C9374F85D41990FB9EC272705F9C(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_003f;
		}
	}
	{
		int32_t L_7 = __this->____count;
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = HashSet_1_get_Count_m857945CD468754937686144F8926EEDE2761F10F_inline(L_8, NULL);
		if ((((int32_t)L_7) == ((int32_t)L_9)))
		{
			goto IL_0037;
		}
	}
	{
		return (bool)0;
	}

IL_0037:
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_10 = V_0;
		bool L_11;
		L_11 = HashSet_1_ContainsAllElements_m12E8284DE8488A7F7F3CEAE63485C6EB5F76E8D2(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return L_11;
	}

IL_003f:
	{
		RuntimeObject* L_12 = ___0_other;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_13 = V_1;
		if (!L_13)
		{
			goto IL_005c;
		}
	}
	{
		int32_t L_14 = __this->____count;
		if (L_14)
		{
			goto IL_005c;
		}
	}
	{
		RuntimeObject* L_15 = V_1;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_15);
		if ((((int32_t)L_16) <= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}
	{
		return (bool)0;
	}

IL_005c:
	{
		RuntimeObject* L_17 = ___0_other;
		ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 L_18;
		L_18 = HashSet_1_CheckUniqueAndUnfoundElements_mFCC18A0BCB2346E051DD0AEA2F8405D0EC725C7C(__this, L_17, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_2 = L_18;
		ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 L_19 = V_2;
		int32_t L_20 = L_19.___uniqueCount;
		int32_t L_21 = __this->____count;
		if ((!(((uint32_t)L_20) == ((uint32_t)L_21))))
		{
			goto IL_007d;
		}
	}
	{
		ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 L_22 = V_2;
		int32_t L_23 = L_22.___unfoundCount;
		return (bool)((((int32_t)L_23) == ((int32_t)0))? 1 : 0);
	}

IL_007d:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mEE0682F788B7CB4A00C5FD93576ABF58350CF2FD (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_0 = ___0_array;
		int32_t L_1 = __this->____count;
		HashSet_1_CopyTo_mCCACCE15A67A4C2F57BBCEE9FF8856544DC2CF2F(__this, L_0, 0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71585
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mCCACCE15A67A4C2F57BBCEE9FF8856544DC2CF2F (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_0 = ___0_array;
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
		int32_t L_2 = ___1_arrayIndex;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_3 = ___1_arrayIndex;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_6 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC00660333703C551EA80371B54D0ADCEB74C33B4)), L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0028:
	{
		int32_t L_7 = ___2_count;
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_0042;
		}
	}
	{
		int32_t L_8 = ___2_count;
		int32_t L_9 = L_8;
		RuntimeObject* L_10 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_9);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_11 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral07624473F417C06C74D59C64840A1532FCE2C626)), L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0042:
	{
		int32_t L_12 = ___1_arrayIndex;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_13 = ___0_array;
		NullCheck(L_13);
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		if ((((int32_t)L_12) > ((int32_t)L_14)))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_15 = ___2_count;
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_16 = ___0_array;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = ___1_arrayIndex;
		if ((((int32_t)L_15) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18)))))
		{
			goto IL_005b;
		}
	}

IL_0050:
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_19 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_005b:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0097;
	}

IL_0061:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_20 = __this->____slots;
		int32_t L_21 = V_1;
		NullCheck(L_20);
		int32_t L_22 = ((L_20)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_21)))->___hashCode;
		if ((((int32_t)L_22) < ((int32_t)0)))
		{
			goto IL_0093;
		}
	}
	{
		InternedStringU5BU5D_t0B851758733FC0B118D84BE83AED10A0404C18D5* L_23 = ___0_array;
		int32_t L_24 = ___1_arrayIndex;
		int32_t L_25 = V_0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_26 = __this->____slots;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_28 = ((L_26)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_27)))->___value;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_24, L_25))), (InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735)L_28);
		int32_t L_29 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0093:
	{
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_0097:
	{
		int32_t L_31 = V_1;
		int32_t L_32 = __this->____lastIndex;
		if ((((int32_t)L_31) >= ((int32_t)L_32)))
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___2_count;
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0061;
		}
	}

IL_00a4:
	{
		return;
	}
}
// Method Definition Index: 71586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_RemoveWhere_m297747EB2D2F9496E70AFB2A5AF3AD551FB6240C (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE2EEFB4BE0C9F57BA62E733F26387F8BA68AF67C)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0054;
	}

IL_0014:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_2 = __this->____slots;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = ((L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0050;
		}
	}
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_5 = __this->____slots;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_7 = ((L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		V_2 = L_7;
		Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD* L_8 = ___0_match;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_9 = V_2;
		NullCheck(L_8);
		bool L_10;
		L_10 = Predicate_1_Invoke_m8B4BDF53D356DC2B6824AECCDFD936A57EBBA0FD_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0050;
		}
	}
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_11 = V_2;
		bool L_12;
		L_12 = HashSet_1_Remove_mDCCB1329C655014754502005D24A65823666CA5A(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		if (!L_12)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0050:
	{
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0054:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = __this->____lastIndex;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_17 = V_0;
		return L_17;
	}
}
// Method Definition Index: 71587
// Method Definition Index: 71588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mF4BE03AACFEFADB2AF97B062CCBF788B4B45B8D3 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_0025;
		}
	}
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
		__this->____slots = (SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)(SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)NULL);
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		return;
	}

IL_0025:
	{
		int32_t L_2 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_3;
		L_3 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_2, NULL);
		V_0 = L_3;
		int32_t L_4 = V_0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_5 = (SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)(SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		V_1 = L_5;
		int32_t L_6 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_2 = L_7;
		V_3 = 0;
		V_4 = 0;
		goto IL_00a2;
	}

IL_0046:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_8 = __this->____slots;
		int32_t L_9 = V_4;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_009c;
		}
	}
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_11 = V_1;
		int32_t L_12 = V_3;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_13 = __this->____slots;
		int32_t L_14 = V_4;
		NullCheck(L_13);
		int32_t L_15 = L_14;
		Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992 L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (Slot_t99E1DAD9EC10BC2CA3AD0951B37A54FB9B0C1992)L_16);
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_17 = V_1;
		int32_t L_18 = V_3;
		NullCheck(L_17);
		int32_t L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_0;
		V_5 = ((int32_t)(L_19%L_20));
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_21 = V_1;
		int32_t L_22 = V_3;
		NullCheck(L_21);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_2;
		int32_t L_24 = V_5;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		int32_t L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		((L_21)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_22)))->___next = ((int32_t)il2cpp_codegen_subtract(L_26, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = V_2;
		int32_t L_28 = V_5;
		int32_t L_29 = V_3;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)il2cpp_codegen_add(L_29, 1)));
		int32_t L_30 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_009c:
	{
		int32_t L_31 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_00a2:
	{
		int32_t L_32 = V_4;
		int32_t L_33 = __this->____lastIndex;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_34 = V_3;
		__this->____lastIndex = L_34;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_35 = V_1;
		__this->____slots = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_35);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_2;
		__this->____buckets = L_36;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_36);
		__this->____freeList = (-1);
		return;
	}
}
// Method Definition Index: 71589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m12456C0B5F2BD37BD07B7CFDA9F116F25281B6D1 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_5 = (SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)(SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		__this->____slots = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 71590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m75E93F1A8CC2B3C092B09C717B5F4B3612FC7DBB (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____count;
		if ((((int32_t)L_2) > ((int32_t)L_3)))
		{
			goto IL_0020;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral91930CCAB5CB8F6F327407F9A14CF42F57A0F27B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = V_0;
		HashSet_1_SetCapacity_m601FAA1088C6E2673429E100BD859DC44074A8B7(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 71591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m601FAA1088C6E2673429E100BD859DC44074A8B7 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_newSize, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* V_0 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		int32_t L_0 = ___0_newSize;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_1 = (SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)(SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_0);
		V_0 = L_1;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_2 = __this->____slots;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_3 = __this->____slots;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_4 = V_0;
		int32_t L_5 = __this->____lastIndex;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, L_5, NULL);
	}

IL_0023:
	{
		int32_t L_6 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_1 = L_7;
		V_2 = 0;
		goto IL_0058;
	}

IL_002e:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_8 = V_0;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		int32_t L_11 = ___0_newSize;
		V_3 = ((int32_t)(L_10%L_11));
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_12 = V_0;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = V_1;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = L_15;
		int32_t L_17 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___next = ((int32_t)il2cpp_codegen_subtract(L_17, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_1;
		int32_t L_19 = V_3;
		int32_t L_20 = V_2;
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(L_19), (int32_t)((int32_t)il2cpp_codegen_add(L_20, 1)));
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_0058:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = __this->____lastIndex;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_002e;
		}
	}
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_24 = V_0;
		__this->____slots = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_24);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_25 = V_1;
		__this->____buckets = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_25);
		return;
	}
}
// Method Definition Index: 71592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mA1B61994FAB542B6C40F2B1F6BDD417501CDA050 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1;
		L_1 = HashSet_1_Initialize_m12456C0B5F2BD37BD07B7CFDA9F116F25281B6D1(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0010:
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_2 = ___0_value;
		int32_t L_3;
		L_3 = HashSet_1_InternalGetHashCode_mA1CB8FE8A84C5D1386228D2ABBC9BCB047D163AB(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_3;
		int32_t L_4 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		V_1 = ((int32_t)(L_4%L_6));
		V_2 = 0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_7 = __this->____slots;
		V_3 = L_7;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		int32_t L_11 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		goto IL_008b;
	}

IL_003a:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_12 = V_3;
		int32_t L_13 = V_5;
		NullCheck(L_12);
		int32_t L_14 = ((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		int32_t L_15 = V_0;
		if ((!(((uint32_t)L_14) == ((uint32_t)L_15))))
		{
			goto IL_0067;
		}
	}
	{
		RuntimeObject* L_16 = __this->____comparer;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_17 = V_3;
		int32_t L_18 = V_5;
		NullCheck(L_17);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___value;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_20 = ___0_value;
		NullCheck(L_16);
		bool L_21;
		L_21 = InterfaceFuncInvoker2< bool, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_16, L_19, L_20);
		if (!L_21)
		{
			goto IL_0067;
		}
	}
	{
		return (bool)0;
	}

IL_0067:
	{
		int32_t L_22 = V_2;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_23 = V_3;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		if ((((int32_t)L_22) < ((int32_t)L_24)))
		{
			goto IL_0078;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_25 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_25, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_25, method);
	}

IL_0078:
	{
		int32_t L_26 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_27 = V_3;
		int32_t L_28 = V_5;
		NullCheck(L_27);
		int32_t L_29 = ((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_5 = L_29;
	}

IL_008b:
	{
		int32_t L_30 = V_5;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_31 = __this->____freeList;
		if ((((int32_t)L_31) < ((int32_t)0)))
		{
			goto IL_00b6;
		}
	}
	{
		int32_t L_32 = __this->____freeList;
		V_4 = L_32;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_33 = V_3;
		int32_t L_34 = V_4;
		NullCheck(L_33);
		int32_t L_35 = ((L_33)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_34)))->___next;
		__this->____freeList = L_35;
		goto IL_00ef;
	}

IL_00b6:
	{
		int32_t L_36 = __this->____lastIndex;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_37 = V_3;
		NullCheck(L_37);
		int32_t L_38 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_37)->max_length),NULL));
		if ((!(((uint32_t)L_36) == ((uint32_t)L_38))))
		{
			goto IL_00d9;
		}
	}
	{
		HashSet_1_IncreaseCapacity_m75E93F1A8CC2B3C092B09C717B5F4B3612FC7DBB(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_39 = __this->____slots;
		V_3 = L_39;
		int32_t L_40 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = __this->____buckets;
		NullCheck(L_41);
		int32_t L_42 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_41)->max_length),NULL));
		V_1 = ((int32_t)(L_40%L_42));
	}

IL_00d9:
	{
		int32_t L_43 = __this->____lastIndex;
		V_4 = L_43;
		int32_t L_44 = __this->____lastIndex;
		__this->____lastIndex = ((int32_t)il2cpp_codegen_add(L_44, 1));
	}

IL_00ef:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_45 = V_3;
		int32_t L_46 = V_4;
		NullCheck(L_45);
		int32_t L_47 = V_0;
		((L_45)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_46)))->___hashCode = L_47;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_48 = V_3;
		int32_t L_49 = V_4;
		NullCheck(L_48);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_50 = ___0_value;
		((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value = L_50;
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_StringLowerCase), (void*)NULL);
		#endif
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_51 = V_3;
		int32_t L_52 = V_4;
		NullCheck(L_51);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_53 = __this->____buckets;
		int32_t L_54 = V_1;
		NullCheck(L_53);
		int32_t L_55 = L_54;
		int32_t L_56 = (L_53)->GetAt(static_cast<il2cpp_array_size_t>(L_55));
		((L_51)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_52)))->___next = ((int32_t)il2cpp_codegen_subtract(L_56, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = __this->____buckets;
		int32_t L_58 = V_1;
		int32_t L_59 = V_4;
		NullCheck(L_57);
		(L_57)->SetAt(static_cast<il2cpp_array_size_t>(L_58), (int32_t)((int32_t)il2cpp_codegen_add(L_59, 1)));
		int32_t L_60 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_60, 1));
		int32_t L_61 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_61, 1));
		return (bool)1;
	}
}
// Method Definition Index: 71593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_mE3EB6B7254469CC1B786252C4CC9E221D59D5D70 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, int32_t ___0_index, int32_t ___1_hashCode, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_hashCode;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		V_0 = ((int32_t)(L_0%L_2));
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_3 = __this->____slots;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = ___1_hashCode;
		((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)))->___hashCode = L_5;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_6 = __this->____slots;
		int32_t L_7 = ___0_index;
		NullCheck(L_6);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_8 = ___2_value;
		((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value = L_8;
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_StringLowerCase), (void*)NULL);
		#endif
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_9 = __this->____slots;
		int32_t L_10 = ___0_index;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___next = ((int32_t)il2cpp_codegen_subtract(L_14, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = __this->____buckets;
		int32_t L_16 = V_0;
		int32_t L_17 = ___0_index;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(L_16), (int32_t)((int32_t)il2cpp_codegen_add(L_17, 1)));
		return;
	}
}
// Method Definition Index: 71594
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m12E8284DE8488A7F7F3CEAE63485C6EB5F76E8D2 (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	{
		RuntimeObject* L_0 = ___0_other;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_0030;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_0030:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_5;
				L_5 = InterfaceFuncInvoker0< InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_4);
				V_1 = L_5;
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6 = V_1;
				bool L_7;
				L_7 = HashSet_1_Contains_m208059B8D89BB100809C7CA51253201A3B504A0B(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
				if (L_7)
				{
					goto IL_001d_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0033;
			}

IL_001d_1:
			{
				RuntimeObject* L_8 = V_0;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0031;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0031:
	{
		return (bool)1;
	}

IL_0033:
	{
		bool L_10 = V_2;
		return L_10;
	}
}
// Method Definition Index: 71595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_m6D06F796CE11E1A2F42C845B3EAB89DF9EAC166D (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* V_2 = NULL;
	int32_t V_3 = 0;
	{
		V_0 = 0;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = ___0_item;
		int32_t L_1;
		L_1 = HashSet_1_InternalGetHashCode_mA1CB8FE8A84C5D1386228D2ABBC9BCB047D163AB(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_1;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_2 = __this->____slots;
		V_2 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = __this->____buckets;
		int32_t L_4 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NullCheck(L_3);
		int32_t L_7 = ((int32_t)(L_4%L_6));
		int32_t L_8 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		goto IL_0074;
	}

IL_0027:
	{
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_9 = V_2;
		int32_t L_10 = V_3;
		NullCheck(L_9);
		int32_t L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___hashCode;
		int32_t L_12 = V_1;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_12))))
		{
			goto IL_0052;
		}
	}
	{
		RuntimeObject* L_13 = __this->____comparer;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_14 = V_2;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_16 = ((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)))->___value;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_17 = ___0_item;
		NullCheck(L_13);
		bool L_18;
		L_18 = InterfaceFuncInvoker2< bool, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_13, L_16, L_17);
		if (!L_18)
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_19 = V_3;
		return L_19;
	}

IL_0052:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_0063;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_0063:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_t123558B2D530E4B5BD1DE3DEE7D54DDEEF5B44F0* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_0074:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_0027;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 71596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 HashSet_1_CheckUniqueAndUnfoundElements_mFCC18A0BCB2346E051DD0AEA2F8405D0EC725C7C (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	RuntimeObject* V_6 = NULL;
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_7;
	memset((&V_7), 0, sizeof(V_7));
	int32_t V_8 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_004f;
		}
	}
	{
		V_5 = 0;
		RuntimeObject* L_1 = ___0_other;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_1);
		V_6 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_3 = V_6;
					if (!L_3)
					{
						goto IL_003b;
					}
				}
				{
					RuntimeObject* L_4 = V_6;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_003b:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0025_1;
			}

IL_0015_1:
			{
				RuntimeObject* L_5 = V_6;
				NullCheck(L_5);
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6;
				L_6 = InterfaceFuncInvoker0< InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_5);
				int32_t L_7 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_7, 1));
				goto IL_003c;
			}

IL_0025_1:
			{
				RuntimeObject* L_8 = V_6;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0015_1;
				}
			}
			{
				goto IL_003c;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003c:
	{
		(&V_0)->___uniqueCount = 0;
		int32_t L_10 = V_5;
		(&V_0)->___unfoundCount = L_10;
		ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 L_11 = V_0;
		return L_11;
	}

IL_004f:
	{
		int32_t L_12 = __this->____lastIndex;
		int32_t L_13;
		L_13 = BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C(L_12, NULL);
		V_1 = L_13;
		int32_t L_14 = V_1;
		if ((((int32_t)L_14) > ((int32_t)((int32_t)100))))
		{
			goto IL_006f;
		}
	}
	{
		int32_t L_15 = V_1;
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		if ((uintptr_t)L_16 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_17 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_16, 4));
		int8_t* L_18;
		if (L_17 == 0)
		{
			L_18 = NULL;
		}
		else
		{
			L_18 = (int8_t*)alloca(L_17);
			memset(L_18, 0, L_17);
		}
		int32_t L_19 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_20 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3(L_20, (int32_t*)L_18, L_19, NULL);
		V_2 = L_20;
		goto IL_007c;
	}

IL_006f:
	{
		int32_t L_21 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_21);
		int32_t L_23 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_24 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19(L_24, L_22, L_23, NULL);
		V_2 = L_24;
	}

IL_007c:
	{
		V_3 = 0;
		V_4 = 0;
		RuntimeObject* L_25 = ___0_other;
		NullCheck(L_25);
		RuntimeObject* L_26;
		L_26 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_25);
		V_6 = L_26;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d1:
			{
				{
					RuntimeObject* L_27 = V_6;
					if (!L_27)
					{
						goto IL_00dc;
					}
				}
				{
					RuntimeObject* L_28 = V_6;
					NullCheck(L_28);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_28);
				}

IL_00dc:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00c6_1;
			}

IL_008b_1:
			{
				RuntimeObject* L_29 = V_6;
				NullCheck(L_29);
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_30;
				L_30 = InterfaceFuncInvoker0< InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_29);
				V_7 = L_30;
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_31 = V_7;
				int32_t L_32;
				L_32 = HashSet_1_InternalIndexOf_m6D06F796CE11E1A2F42C845B3EAB89DF9EAC166D(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
				V_8 = L_32;
				int32_t L_33 = V_8;
				if ((((int32_t)L_33) < ((int32_t)0)))
				{
					goto IL_00bd_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_34 = V_2;
				int32_t L_35 = V_8;
				NullCheck(L_34);
				bool L_36;
				L_36 = BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2(L_34, L_35, NULL);
				if (L_36)
				{
					goto IL_00c6_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_37 = V_2;
				int32_t L_38 = V_8;
				NullCheck(L_37);
				BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86(L_37, L_38, NULL);
				int32_t L_39 = V_4;
				V_4 = ((int32_t)il2cpp_codegen_add(L_39, 1));
				goto IL_00c6_1;
			}

IL_00bd_1:
			{
				int32_t L_40 = V_3;
				V_3 = ((int32_t)il2cpp_codegen_add(L_40, 1));
				bool L_41 = ___1_returnIfUnfound;
				if (!L_41)
				{
					goto IL_00c6_1;
				}
			}
			{
				goto IL_00dd;
			}

IL_00c6_1:
			{
				RuntimeObject* L_42 = V_6;
				NullCheck(L_42);
				bool L_43;
				L_43 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_42);
				if (L_43)
				{
					goto IL_008b_1;
				}
			}
			{
				goto IL_00dd;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00dd:
	{
		int32_t L_44 = V_4;
		(&V_0)->___uniqueCount = L_44;
		int32_t L_45 = V_3;
		(&V_0)->___unfoundCount = L_45;
		ElementCount_tDC1CC93BCADF2DE75BF9DC6BED0EB14E70C9BD95 L_46 = V_0;
		return L_46;
	}
}
// Method Definition Index: 71597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_mEE3BE892E186C9374F85D41990FB9EC272705F9C (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___0_set1, HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* ___1_set2, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_0 = ___0_set1;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = HashSet_1_get_Comparer_m3673F5CEB28586D9A02F64FD041905DB01F396C5_inline(L_0, NULL);
		HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* L_2 = ___1_set2;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = HashSet_1_get_Comparer_m3673F5CEB28586D9A02F64FD041905DB01F396C5_inline(L_2, NULL);
		NullCheck(L_1);
		bool L_4;
		L_4 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, L_1, L_3);
		return L_4;
	}
}
// Method Definition Index: 71598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_mA1CB8FE8A84C5D1386228D2ABBC9BCB047D163AB (HashSet_1_t87C47CF88B1B88398D4F9A1E51E92F834CF5160B* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000a;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____comparer;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_2 = ___0_item;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_1, L_2);
		return ((int32_t)(L_3&((int32_t)2147483647LL)));
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
// Method Definition Index: 71561
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m290C0FEA7D032B7A023297BA14ABDEEF3AAA388D (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_0;
		L_0 = EqualityComparer_1_get_Default_m4A0896866DFD0BFADEBA26A14A4072AC9D9917D8_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mFC3ABD9B392DE2F40985925ABC08BA1459B5F6E4(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return;
	}
}
// Method Definition Index: 71562
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mFC3ABD9B392DE2F40985925ABC08BA1459B5F6E4 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_comparer;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_1;
		L_1 = EqualityComparer_1_get_Default_m4A0896866DFD0BFADEBA26A14A4072AC9D9917D8_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		___0_comparer = L_1;
	}

IL_0010:
	{
		RuntimeObject* L_2 = ___0_comparer;
		__this->____comparer = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_2);
		__this->____lastIndex = 0;
		__this->____count = 0;
		__this->____freeList = (-1);
		__this->____version = 0;
		return;
	}
}
// Method Definition Index: 71563
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m53E4A58A263450147ABE80ACAEE774F4F06389F7 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_capacity;
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_1;
		L_1 = EqualityComparer_1_get_Default_m4A0896866DFD0BFADEBA26A14A4072AC9D9917D8_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_mD073B28596FF3A83B06D2C917FCF2D10F5D94372(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 71564
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m481BEE56FFED39D08B4E3420DF2B96F0EB50AC8F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_collection;
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_1;
		L_1 = EqualityComparer_1_get_Default_m4A0896866DFD0BFADEBA26A14A4072AC9D9917D8_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		HashSet_1__ctor_m6697C93FA4EE093921C5765C6F3484777246EE12(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
// Method Definition Index: 71565
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_m6697C93FA4EE093921C5765C6F3484777246EE12 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_collection, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B8_0 = 0;
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_mFC3ABD9B392DE2F40985925ABC08BA1459B5F6E4(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		RuntimeObject* L_1 = ___0_collection;
		if (L_1)
		{
			goto IL_0015;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral469F05BE9BB4C7903C353D0EB9F6384C84A48B25)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0015:
	{
		RuntimeObject* L_3 = ___0_collection;
		V_0 = ((HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_4 = V_0;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m3EB2FC760B463CDCE0838CAFB44F137DB6A77BFF(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_0030;
		}
	}
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_7 = V_0;
		HashSet_1_CopyFrom_mF6B7A9579D122B655180B1B56EB3DA87F3D46167(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return;
	}

IL_0030:
	{
		RuntimeObject* L_8 = ___0_collection;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_9 = V_1;
		if (!L_9)
		{
			goto IL_0042;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_10);
		G_B8_0 = L_11;
		goto IL_0043;
	}

IL_0042:
	{
		G_B8_0 = 0;
	}

IL_0043:
	{
		V_2 = G_B8_0;
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = HashSet_1_Initialize_m47155C7D260A5C12CC93E90A14D4554D17E37F1F(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		RuntimeObject* L_14 = ___0_collection;
		HashSet_1_UnionWith_m39B566378AD1EF02E6E6D135E8F5AA7216EFB45F(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		int32_t L_15 = __this->____count;
		if ((((int32_t)L_15) <= ((int32_t)0)))
		{
			goto IL_0074;
		}
	}
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_16 = __this->____slots;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = __this->____count;
		if ((((int32_t)((int32_t)(L_17/L_18))) <= ((int32_t)3)))
		{
			goto IL_0074;
		}
	}
	{
		HashSet_1_TrimExcess_mBEF82257C8F5AFE73305A602536496BE0E512E23(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
	}

IL_0074:
	{
		return;
	}
}
// Method Definition Index: 71566
// Method Definition Index: 71567
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyFrom_mF6B7A9579D122B655180B1B56EB3DA87F3D46167 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_0 = ___0_source;
		NullCheck(L_0);
		int32_t L_1 = L_0->____count;
		V_0 = L_1;
		int32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_000b;
		}
	}
	{
		return;
	}

IL_000b:
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_3 = ___0_source;
		NullCheck(L_3);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = L_3->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = L_5;
		int32_t L_6 = V_0;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(((int32_t)il2cpp_codegen_add(L_6, 1)), NULL);
		int32_t L_8 = V_1;
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0065;
		}
	}
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_9 = ___0_source;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = L_9->____buckets;
		NullCheck((RuntimeArray*)L_10);
		RuntimeObject* L_11;
		L_11 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_10, NULL);
		__this->____buckets = ((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)((Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)Castclass((RuntimeObject*)L_11, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var)));
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_12 = ___0_source;
		NullCheck(L_12);
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_13 = L_12->____slots;
		NullCheck((RuntimeArray*)L_13);
		RuntimeObject* L_14;
		L_14 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_13, NULL);
		__this->____slots = ((SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)((SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)CastclassSealed((RuntimeObject*)L_14, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))));
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_15 = ___0_source;
		NullCheck(L_15);
		int32_t L_16 = L_15->____lastIndex;
		__this->____lastIndex = L_16;
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_17 = ___0_source;
		NullCheck(L_17);
		int32_t L_18 = L_17->____freeList;
		__this->____freeList = L_18;
		goto IL_00c7;
	}

IL_0065:
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_19 = ___0_source;
		NullCheck(L_19);
		int32_t L_20 = L_19->____lastIndex;
		V_2 = L_20;
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_21 = ___0_source;
		NullCheck(L_21);
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_22 = L_21->____slots;
		V_3 = L_22;
		int32_t L_23 = V_0;
		int32_t L_24;
		L_24 = HashSet_1_Initialize_m47155C7D260A5C12CC93E90A14D4554D17E37F1F(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		V_4 = 0;
		V_5 = 0;
		goto IL_00ba;
	}

IL_0083:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_25 = V_3;
		int32_t L_26 = V_5;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		V_6 = L_27;
		int32_t L_28 = V_6;
		if ((((int32_t)L_28) < ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		int32_t L_29 = V_4;
		int32_t L_30 = V_6;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_31 = V_3;
		int32_t L_32 = V_5;
		NullCheck(L_31);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_33 = ((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->___value;
		HashSet_1_AddValue_m0594A940F2ADB614CAA703B0F1DFCD15A6CA6329(__this, L_29, L_30, L_33, NULL);
		int32_t L_34 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b4:
	{
		int32_t L_35 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_35, 1));
	}

IL_00ba:
	{
		int32_t L_36 = V_5;
		int32_t L_37 = V_2;
		if ((((int32_t)L_36) < ((int32_t)L_37)))
		{
			goto IL_0083;
		}
	}
	{
		int32_t L_38 = V_4;
		__this->____lastIndex = L_38;
	}

IL_00c7:
	{
		int32_t L_39 = V_0;
		__this->____count = L_39;
		return;
	}
}
// Method Definition Index: 71568
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1__ctor_mD073B28596FF3A83B06D2C917FCF2D10F5D94372 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___1_comparer;
		HashSet_1__ctor_mFC3ABD9B392DE2F40985925ABC08BA1459B5F6E4(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0016;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_2 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0016:
	{
		int32_t L_3 = ___0_capacity;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_4 = ___0_capacity;
		int32_t L_5;
		L_5 = HashSet_1_Initialize_m47155C7D260A5C12CC93E90A14D4554D17E37F1F(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0022:
	{
		return;
	}
}
// Method Definition Index: 71569
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_System_Collections_Generic_ICollectionU3CTU3E_Add_m00E2B97BE4074636C8EDDED51E5C1C0C27C7E241 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mE4C9D1F8BFD05EA7EDAD5D186153A5135AE293ED(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return;
	}
}
// Method Definition Index: 71570
// Method Definition Index: 71571
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_mBFF089381B4F9F83CAB4B68BF69351CDB316A5F0 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* V_2 = NULL;
	int32_t V_3 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0080;
		}
	}
	{
		V_0 = 0;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m54D386E54FD853D8B410D65049B7B5E9D96244BD(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_2;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_3 = __this->____slots;
		V_2 = L_3;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		int32_t L_5 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->____buckets;
		NullCheck(L_6);
		int32_t L_7 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_6)->max_length),NULL));
		NullCheck(L_4);
		int32_t L_8 = ((int32_t)(L_5%L_7));
		int32_t L_9 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_9, 1));
		goto IL_007c;
	}

IL_002f:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_10 = V_2;
		int32_t L_11 = V_3;
		NullCheck(L_10);
		int32_t L_12 = ((L_10)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		int32_t L_13 = V_1;
		if ((!(((uint32_t)L_12) == ((uint32_t)L_13))))
		{
			goto IL_005a;
		}
	}
	{
		RuntimeObject* L_14 = __this->____comparer;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_15 = V_2;
		int32_t L_16 = V_3;
		NullCheck(L_15);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_17 = ((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)))->___value;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_18 = ___0_item;
		NullCheck(L_14);
		bool L_19;
		L_19 = InterfaceFuncInvoker2< bool, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_14, L_17, L_18);
		if (!L_19)
		{
			goto IL_005a;
		}
	}
	{
		return (bool)1;
	}

IL_005a:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_006b;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_006b:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_007c:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_002f;
		}
	}

IL_0080:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71572
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m0B8229BF56B4620D100B23F4B02CABFCC1C02DD2 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_0 = ___0_array;
		int32_t L_1 = ___1_arrayIndex;
		int32_t L_2 = __this->____count;
		HashSet_1_CopyTo_m47AF3F67F0D00BF19747208D1B3A3233AEDBC95A(__this, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71573
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Remove_mDB799908FE78068E57CBAC14B4E85314BC5F7ABE (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* V_4 = NULL;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (!L_0)
		{
			goto IL_0154;
		}
	}
	{
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_1 = ___0_item;
		int32_t L_2;
		L_2 = HashSet_1_InternalGetHashCode_m54D386E54FD853D8B410D65049B7B5E9D96244BD(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_2;
		int32_t L_3 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = __this->____buckets;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		V_1 = ((int32_t)(L_3%L_5));
		V_2 = (-1);
		V_3 = 0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_6 = __this->____slots;
		V_4 = L_6;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		int32_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
		goto IL_014c;
	}

IL_003b:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_11 = V_4;
		int32_t L_12 = V_5;
		NullCheck(L_11);
		int32_t L_13 = ((L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_12)))->___hashCode;
		int32_t L_14 = V_0;
		if ((!(((uint32_t)L_13) == ((uint32_t)L_14))))
		{
			goto IL_0123;
		}
	}
	{
		RuntimeObject* L_15 = __this->____comparer;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_16 = V_4;
		int32_t L_17 = V_5;
		NullCheck(L_16);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_18 = ((L_16)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_19 = ___0_item;
		NullCheck(L_15);
		bool L_20;
		L_20 = InterfaceFuncInvoker2< bool, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0123;
		}
	}
	{
		int32_t L_21 = V_2;
		if ((((int32_t)L_21) >= ((int32_t)0)))
		{
			goto IL_008c;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = __this->____buckets;
		int32_t L_23 = V_1;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_24 = V_4;
		int32_t L_25 = V_5;
		NullCheck(L_24);
		int32_t L_26 = ((L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_25)))->___next;
		NullCheck(L_22);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(L_23), (int32_t)((int32_t)il2cpp_codegen_add(L_26, 1)));
		goto IL_00a7;
	}

IL_008c:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_27 = V_4;
		int32_t L_28 = V_2;
		NullCheck(L_27);
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_29 = V_4;
		int32_t L_30 = V_5;
		NullCheck(L_29);
		int32_t L_31 = ((L_29)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_30)))->___next;
		((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next = L_31;
	}

IL_00a7:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_32 = V_4;
		int32_t L_33 = V_5;
		NullCheck(L_32);
		((L_32)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_33)))->___hashCode = (-1);
	}
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_34 = V_4;
		int32_t L_35 = V_5;
		NullCheck(L_34);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79* L_36 = (PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79*)(&((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_35)))->___value);
		il2cpp_codegen_initobj(L_36, sizeof(PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79));
	}

IL_00d1:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_37 = V_4;
		int32_t L_38 = V_5;
		NullCheck(L_37);
		int32_t L_39 = __this->____freeList;
		((L_37)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_38)))->___next = L_39;
		int32_t L_40 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_subtract(L_40, 1));
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = __this->____count;
		if (L_42)
		{
			goto IL_0119;
		}
	}
	{
		__this->____lastIndex = 0;
		__this->____freeList = (-1);
		goto IL_0121;
	}

IL_0119:
	{
		int32_t L_43 = V_5;
		__this->____freeList = L_43;
	}

IL_0121:
	{
		return (bool)1;
	}

IL_0123:
	{
		int32_t L_44 = V_3;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_45 = V_4;
		NullCheck(L_45);
		int32_t L_46 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_45)->max_length),NULL));
		if ((((int32_t)L_44) < ((int32_t)L_46)))
		{
			goto IL_0135;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_47 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_47, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_47, method);
	}

IL_0135:
	{
		int32_t L_48 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_48, 1));
		int32_t L_49 = V_5;
		V_2 = L_49;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_50 = V_4;
		int32_t L_51 = V_5;
		NullCheck(L_50);
		int32_t L_52 = ((L_50)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_51)))->___next;
		V_5 = L_52;
	}

IL_014c:
	{
		int32_t L_53 = V_5;
		if ((((int32_t)L_53) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0154:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7 HashSet_1_GetEnumerator_m6489B1D751E73295030BB63B5D122640BA39856E (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m460D0268E0EAD8DDF942699DB292BA7FC04B31BD((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 71577
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m91AB566D3BAFCB27FB576F282F253F8B750C3124 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m460D0268E0EAD8DDF942699DB292BA7FC04B31BD((&L_0), __this, NULL);
		Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71578
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_System_Collections_IEnumerable_GetEnumerator_m208B25F21CADBCBC2002A42579290D5B214CA805 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m460D0268E0EAD8DDF942699DB292BA7FC04B31BD((&L_0), __this, NULL);
		Enumerator_tF8E69BF07F9F02F7353403E775CC0C7C9D5920A7 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 25), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 71579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_GetObjectData_m6535D216E50C34DF0363A1A3F31A2190E6C1E8E2 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* V_0 = NULL;
	String_t* G_B4_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_1 = NULL;
	String_t* G_B3_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_1 = NULL;
	int32_t G_B5_0 = 0;
	String_t* G_B5_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		int32_t L_3 = __this->____version;
		NullCheck(L_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_2, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_3, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeObject* L_5 = __this->____comparer;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 27)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		NullCheck(L_4);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_4, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, L_7, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_8 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = __this->____buckets;
		if (!L_9)
		{
			G_B4_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
			G_B4_1 = L_8;
			goto IL_0052;
		}
		G_B3_0 = _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865;
		G_B3_1 = L_8;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		NullCheck(L_10);
		int32_t L_11 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_10)->max_length),NULL));
		G_B5_0 = L_11;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0053;
	}

IL_0052:
	{
		G_B5_0 = 0;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0053:
	{
		NullCheck(G_B5_2);
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B5_2, G_B5_1, G_B5_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = __this->____buckets;
		if (!L_12)
		{
			goto IL_0089;
		}
	}
	{
		int32_t L_13 = __this->____count;
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_14 = (PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1*)(PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29), (uint32_t)L_13);
		V_0 = L_14;
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_15 = V_0;
		HashSet_1_CopyTo_mD7019504367CF88BF03BF13365DBA24FA58FAE84(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_16 = ___0_info;
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_17 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		NullCheck(L_16);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_16, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, (RuntimeObject*)L_17, L_19, NULL);
	}

IL_0089:
	{
		return;
	}
}
// Method Definition Index: 71580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_OnDeserialization_m3E64FA0DF2145EADA3574A8FD271B898F1F07E1A (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* V_1 = NULL;
	int32_t V_2 = 0;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = __this->____siInfo;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		return;
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = __this->____siInfo;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_1, _stringLiteralDD57D613EE89CAA812BA2441F086552F388D6865, NULL);
		V_0 = L_2;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 32)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		NullCheck(L_3);
		RuntimeObject* L_6;
		L_6 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_3, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_5, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_6, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 20))));
		__this->____freeList = (-1);
		int32_t L_7 = V_0;
		if (!L_7)
		{
			goto IL_00ad;
		}
	}
	{
		int32_t L_8 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_8);
		__this->____buckets = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_9);
		int32_t L_10 = V_0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_11 = (SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)(SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_10);
		__this->____slots = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_11);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_12 = __this->____siInfo;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_13 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 31)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_14;
		L_14 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_13, NULL);
		NullCheck(L_12);
		RuntimeObject* L_15;
		L_15 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_12, _stringLiteral7FD8990CE322087D5497AFE06F8F53AC9EBE47B0, L_14, NULL);
		V_1 = ((PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1*)CastclassSealed((RuntimeObject*)L_15, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 29)));
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_16 = V_1;
		if (L_16)
		{
			goto IL_008f;
		}
	}
	{
		SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7* L_17 = (SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SerializationException_t09D5CC39CEF9CC37AC9D2E0C6DBE050B4E3F8CA7_il2cpp_TypeInfo_var)));
		SerializationException__ctor_m0AAFE2ABD0A74F3E783AD5B5FE842DE460168DB0(L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC5ABE84F2ABF009EBC68D2A32EF8C171B074F922)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_008f:
	{
		V_2 = 0;
		goto IL_00a5;
	}

IL_0093:
	{
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_18 = V_1;
		int32_t L_19 = V_2;
		NullCheck(L_18);
		int32_t L_20 = L_19;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_21 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_20));
		bool L_22;
		L_22 = HashSet_1_AddIfNotPresent_mE4C9D1F8BFD05EA7EDAD5D186153A5135AE293ED(__this, L_21, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_2;
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_25 = V_1;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((((int32_t)L_24) < ((int32_t)L_26)))
		{
			goto IL_0093;
		}
	}
	{
		goto IL_00b4;
	}

IL_00ad:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00b4:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_27 = __this->____siInfo;
		NullCheck(L_27);
		int32_t L_28;
		L_28 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_27, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		__this->____version = L_28;
		__this->____siInfo = (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____siInfo), (void*)(SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37*)NULL);
		return;
	}
}
// Method Definition Index: 71581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Add_m05629EEF0DDCDC30A5AA99F66A11463F35DB3714 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_0 = ___0_item;
		bool L_1;
		L_1 = HashSet_1_AddIfNotPresent_mE4C9D1F8BFD05EA7EDAD5D186153A5135AE293ED(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_1;
	}
}
// Method Definition Index: 71582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_UnionWith_m39B566378AD1EF02E6E6D135E8F5AA7216EFB45F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_2);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_4 = V_0;
					if (!L_4)
					{
						goto IL_0039;
					}
				}
				{
					RuntimeObject* L_5 = V_0;
					NullCheck(L_5);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
				}

IL_0039:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_6 = V_0;
				NullCheck(L_6);
				PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_7;
				L_7 = InterfaceFuncInvoker0< PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_6);
				V_1 = L_7;
				PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_8 = V_1;
				bool L_9;
				L_9 = HashSet_1_AddIfNotPresent_mE4C9D1F8BFD05EA7EDAD5D186153A5135AE293ED(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
			}

IL_0026_1:
			{
				RuntimeObject* L_10 = V_0;
				NullCheck(L_10);
				bool L_11;
				L_11 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_10);
				if (L_11)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_003a;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003a:
	{
		return;
	}
}
// Method Definition Index: 71583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_SetEquals_m81F65245A9283D6AE1B5D34E57E97BA98DD67F63 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		RuntimeObject* L_0 = ___0_other;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF7933083B6BA56CBC6D7BCA0F30688A30D0368F6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_other;
		if ((!(((RuntimeObject*)(RuntimeObject*)L_2) == ((RuntimeObject*)(HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243*)__this))))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)1;
	}

IL_0014:
	{
		RuntimeObject* L_3 = ___0_other;
		V_0 = ((HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243*)IsInstClass((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)));
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_4 = V_0;
		if (!L_4)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_5 = V_0;
		bool L_6;
		L_6 = HashSet_1_AreEqualityComparersEqual_m3EB2FC760B463CDCE0838CAFB44F137DB6A77BFF(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_003f;
		}
	}
	{
		int32_t L_7 = __this->____count;
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = HashSet_1_get_Count_m471850B27F3237B4897DC9C958FAD020EA7185A3_inline(L_8, NULL);
		if ((((int32_t)L_7) == ((int32_t)L_9)))
		{
			goto IL_0037;
		}
	}
	{
		return (bool)0;
	}

IL_0037:
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_10 = V_0;
		bool L_11;
		L_11 = HashSet_1_ContainsAllElements_m040CA79E19A6BFFD5B55F6C138D8C9ED5861E21F(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return L_11;
	}

IL_003f:
	{
		RuntimeObject* L_12 = ___0_other;
		V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		RuntimeObject* L_13 = V_1;
		if (!L_13)
		{
			goto IL_005c;
		}
	}
	{
		int32_t L_14 = __this->____count;
		if (L_14)
		{
			goto IL_005c;
		}
	}
	{
		RuntimeObject* L_15 = V_1;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 7), L_15);
		if ((((int32_t)L_16) <= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}
	{
		return (bool)0;
	}

IL_005c:
	{
		RuntimeObject* L_17 = ___0_other;
		ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 L_18;
		L_18 = HashSet_1_CheckUniqueAndUnfoundElements_m621B1D60770E2C41C97F50A937FA2A145CC4C647(__this, L_17, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_2 = L_18;
		ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 L_19 = V_2;
		int32_t L_20 = L_19.___uniqueCount;
		int32_t L_21 = __this->____count;
		if ((!(((uint32_t)L_20) == ((uint32_t)L_21))))
		{
			goto IL_007d;
		}
	}
	{
		ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 L_22 = V_2;
		int32_t L_23 = L_22.___unfoundCount;
		return (bool)((((int32_t)L_23) == ((int32_t)0))? 1 : 0);
	}

IL_007d:
	{
		return (bool)0;
	}
}
// Method Definition Index: 71584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_mD7019504367CF88BF03BF13365DBA24FA58FAE84 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_0 = ___0_array;
		int32_t L_1 = __this->____count;
		HashSet_1_CopyTo_m47AF3F67F0D00BF19747208D1B3A3233AEDBC95A(__this, L_0, 0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return;
	}
}
// Method Definition Index: 71585
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_CopyTo_m47AF3F67F0D00BF19747208D1B3A3233AEDBC95A (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* ___0_array, int32_t ___1_arrayIndex, int32_t ___2_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_0 = ___0_array;
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
		int32_t L_2 = ___1_arrayIndex;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_3 = ___1_arrayIndex;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_6 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC00660333703C551EA80371B54D0ADCEB74C33B4)), L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, method);
	}

IL_0028:
	{
		int32_t L_7 = ___2_count;
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_0042;
		}
	}
	{
		int32_t L_8 = ___2_count;
		int32_t L_9 = L_8;
		RuntimeObject* L_10 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_9);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_11 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral07624473F417C06C74D59C64840A1532FCE2C626)), L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral181DEF79B2243F7C4801BB3A41C7077D5A07F414)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0042:
	{
		int32_t L_12 = ___1_arrayIndex;
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_13 = ___0_array;
		NullCheck(L_13);
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		if ((((int32_t)L_12) > ((int32_t)L_14)))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_15 = ___2_count;
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_16 = ___0_array;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		int32_t L_18 = ___1_arrayIndex;
		if ((((int32_t)L_15) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18)))))
		{
			goto IL_005b;
		}
	}

IL_0050:
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_19 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_005b:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0097;
	}

IL_0061:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_20 = __this->____slots;
		int32_t L_21 = V_1;
		NullCheck(L_20);
		int32_t L_22 = ((L_20)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_21)))->___hashCode;
		if ((((int32_t)L_22) < ((int32_t)0)))
		{
			goto IL_0093;
		}
	}
	{
		PropertyPathU5BU5D_t3242F5318E9FCD964C859C73D015DAC85179CEB1* L_23 = ___0_array;
		int32_t L_24 = ___1_arrayIndex;
		int32_t L_25 = V_0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_26 = __this->____slots;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_28 = ((L_26)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_27)))->___value;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_24, L_25))), (PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79)L_28);
		int32_t L_29 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0093:
	{
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_0097:
	{
		int32_t L_31 = V_1;
		int32_t L_32 = __this->____lastIndex;
		if ((((int32_t)L_31) >= ((int32_t)L_32)))
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___2_count;
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0061;
		}
	}

IL_00a4:
	{
		return;
	}
}
// Method Definition Index: 71586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_RemoveWhere_m31CA1A848885EF41EE3FD274ACB28F038E1B775F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE2EEFB4BE0C9F57BA62E733F26387F8BA68AF67C)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0054;
	}

IL_0014:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_2 = __this->____slots;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = ((L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0050;
		}
	}
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_5 = __this->____slots;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_7 = ((L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		V_2 = L_7;
		Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC* L_8 = ___0_match;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_9 = V_2;
		NullCheck(L_8);
		bool L_10;
		L_10 = Predicate_1_Invoke_mD00114316CACFD296E750222C808E712960B78FF_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0050;
		}
	}
	{
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_11 = V_2;
		bool L_12;
		L_12 = HashSet_1_Remove_mDB799908FE78068E57CBAC14B4E85314BC5F7ABE(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		if (!L_12)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0050:
	{
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0054:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = __this->____lastIndex;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_17 = V_0;
		return L_17;
	}
}
// Method Definition Index: 71587
// Method Definition Index: 71588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_TrimExcess_mBEF82257C8F5AFE73305A602536496BE0E512E23 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_0025;
		}
	}
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
		__this->____slots = (SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)(SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)NULL);
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		return;
	}

IL_0025:
	{
		int32_t L_2 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_3;
		L_3 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_2, NULL);
		V_0 = L_3;
		int32_t L_4 = V_0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_5 = (SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)(SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		V_1 = L_5;
		int32_t L_6 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_2 = L_7;
		V_3 = 0;
		V_4 = 0;
		goto IL_00a2;
	}

IL_0046:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_8 = __this->____slots;
		int32_t L_9 = V_4;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_009c;
		}
	}
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_11 = V_1;
		int32_t L_12 = V_3;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_13 = __this->____slots;
		int32_t L_14 = V_4;
		NullCheck(L_13);
		int32_t L_15 = L_14;
		Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1 L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (Slot_tEE444C62D9FC9B5D53D6541EEB01C136B0F395F1)L_16);
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_17 = V_1;
		int32_t L_18 = V_3;
		NullCheck(L_17);
		int32_t L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_0;
		V_5 = ((int32_t)(L_19%L_20));
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_21 = V_1;
		int32_t L_22 = V_3;
		NullCheck(L_21);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_2;
		int32_t L_24 = V_5;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		int32_t L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		((L_21)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_22)))->___next = ((int32_t)il2cpp_codegen_subtract(L_26, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = V_2;
		int32_t L_28 = V_5;
		int32_t L_29 = V_3;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)il2cpp_codegen_add(L_29, 1)));
		int32_t L_30 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_009c:
	{
		int32_t L_31 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_00a2:
	{
		int32_t L_32 = V_4;
		int32_t L_33 = __this->____lastIndex;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_34 = V_3;
		__this->____lastIndex = L_34;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_35 = V_1;
		__this->____slots = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_35);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_2;
		__this->____buckets = L_36;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_36);
		__this->____freeList = (-1);
		return;
	}
}
// Method Definition Index: 71589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_Initialize_m47155C7D260A5C12CC93E90A14D4554D17E37F1F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_5 = (SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)(SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_4);
		__this->____slots = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 71590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_IncreaseCapacity_m048FA262F10970373C3496B36D2BAC845C2F9B6E (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____count;
		if ((((int32_t)L_2) > ((int32_t)L_3)))
		{
			goto IL_0020;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral91930CCAB5CB8F6F327407F9A14CF42F57A0F27B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = V_0;
		HashSet_1_SetCapacity_m3CD22E798A2CE8BA8CA466AA43AC54CD8523C5EC(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 71591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_SetCapacity_m3CD22E798A2CE8BA8CA466AA43AC54CD8523C5EC (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_newSize, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* V_0 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		int32_t L_0 = ___0_newSize;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_1 = (SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)(SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), (uint32_t)L_0);
		V_0 = L_1;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_2 = __this->____slots;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_3 = __this->____slots;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_4 = V_0;
		int32_t L_5 = __this->____lastIndex;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, L_5, NULL);
	}

IL_0023:
	{
		int32_t L_6 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_6);
		V_1 = L_7;
		V_2 = 0;
		goto IL_0058;
	}

IL_002e:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_8 = V_0;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		int32_t L_10 = ((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)))->___hashCode;
		int32_t L_11 = ___0_newSize;
		V_3 = ((int32_t)(L_10%L_11));
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_12 = V_0;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = V_1;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = L_15;
		int32_t L_17 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___next = ((int32_t)il2cpp_codegen_subtract(L_17, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_1;
		int32_t L_19 = V_3;
		int32_t L_20 = V_2;
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(L_19), (int32_t)((int32_t)il2cpp_codegen_add(L_20, 1)));
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_0058:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = __this->____lastIndex;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_002e;
		}
	}
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_24 = V_0;
		__this->____slots = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____slots), (void*)L_24);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_25 = V_1;
		__this->____buckets = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_25);
		return;
	}
}
// Method Definition Index: 71592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AddIfNotPresent_mE4C9D1F8BFD05EA7EDAD5D186153A5135AE293ED (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____buckets;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1;
		L_1 = HashSet_1_Initialize_m47155C7D260A5C12CC93E90A14D4554D17E37F1F(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
	}

IL_0010:
	{
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_2 = ___0_value;
		int32_t L_3;
		L_3 = HashSet_1_InternalGetHashCode_m54D386E54FD853D8B410D65049B7B5E9D96244BD(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_3;
		int32_t L_4 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		V_1 = ((int32_t)(L_4%L_6));
		V_2 = 0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_7 = __this->____slots;
		V_3 = L_7;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		int32_t L_11 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		goto IL_008b;
	}

IL_003a:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_12 = V_3;
		int32_t L_13 = V_5;
		NullCheck(L_12);
		int32_t L_14 = ((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		int32_t L_15 = V_0;
		if ((!(((uint32_t)L_14) == ((uint32_t)L_15))))
		{
			goto IL_0067;
		}
	}
	{
		RuntimeObject* L_16 = __this->____comparer;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_17 = V_3;
		int32_t L_18 = V_5;
		NullCheck(L_17);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_19 = ((L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_18)))->___value;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_20 = ___0_value;
		NullCheck(L_16);
		bool L_21;
		L_21 = InterfaceFuncInvoker2< bool, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_16, L_19, L_20);
		if (!L_21)
		{
			goto IL_0067;
		}
	}
	{
		return (bool)0;
	}

IL_0067:
	{
		int32_t L_22 = V_2;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_23 = V_3;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		if ((((int32_t)L_22) < ((int32_t)L_24)))
		{
			goto IL_0078;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_25 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_25, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_25, method);
	}

IL_0078:
	{
		int32_t L_26 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_27 = V_3;
		int32_t L_28 = V_5;
		NullCheck(L_27);
		int32_t L_29 = ((L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_5 = L_29;
	}

IL_008b:
	{
		int32_t L_30 = V_5;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_31 = __this->____freeList;
		if ((((int32_t)L_31) < ((int32_t)0)))
		{
			goto IL_00b6;
		}
	}
	{
		int32_t L_32 = __this->____freeList;
		V_4 = L_32;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_33 = V_3;
		int32_t L_34 = V_4;
		NullCheck(L_33);
		int32_t L_35 = ((L_33)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_34)))->___next;
		__this->____freeList = L_35;
		goto IL_00ef;
	}

IL_00b6:
	{
		int32_t L_36 = __this->____lastIndex;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_37 = V_3;
		NullCheck(L_37);
		int32_t L_38 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_37)->max_length),NULL));
		if ((!(((uint32_t)L_36) == ((uint32_t)L_38))))
		{
			goto IL_00d9;
		}
	}
	{
		HashSet_1_IncreaseCapacity_m048FA262F10970373C3496B36D2BAC845C2F9B6E(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_39 = __this->____slots;
		V_3 = L_39;
		int32_t L_40 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = __this->____buckets;
		NullCheck(L_41);
		int32_t L_42 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_41)->max_length),NULL));
		V_1 = ((int32_t)(L_40%L_42));
	}

IL_00d9:
	{
		int32_t L_43 = __this->____lastIndex;
		V_4 = L_43;
		int32_t L_44 = __this->____lastIndex;
		__this->____lastIndex = ((int32_t)il2cpp_codegen_add(L_44, 1));
	}

IL_00ef:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_45 = V_3;
		int32_t L_46 = V_4;
		NullCheck(L_45);
		int32_t L_47 = V_0;
		((L_45)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_46)))->___hashCode = L_47;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_48 = V_3;
		int32_t L_49 = V_4;
		NullCheck(L_48);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_50 = ___0_value;
		((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value = L_50;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part0))->___m_Name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part0))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part1))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part1))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part2))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part2))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part3))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_Part3))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_48)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_49)))->___value))->___m_AdditionalParts), (void*)NULL);
		#endif
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_51 = V_3;
		int32_t L_52 = V_4;
		NullCheck(L_51);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_53 = __this->____buckets;
		int32_t L_54 = V_1;
		NullCheck(L_53);
		int32_t L_55 = L_54;
		int32_t L_56 = (L_53)->GetAt(static_cast<il2cpp_array_size_t>(L_55));
		((L_51)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_52)))->___next = ((int32_t)il2cpp_codegen_subtract(L_56, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = __this->____buckets;
		int32_t L_58 = V_1;
		int32_t L_59 = V_4;
		NullCheck(L_57);
		(L_57)->SetAt(static_cast<il2cpp_array_size_t>(L_58), (int32_t)((int32_t)il2cpp_codegen_add(L_59, 1)));
		int32_t L_60 = __this->____count;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_60, 1));
		int32_t L_61 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_61, 1));
		return (bool)1;
	}
}
// Method Definition Index: 71593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HashSet_1_AddValue_m0594A940F2ADB614CAA703B0F1DFCD15A6CA6329 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, int32_t ___0_index, int32_t ___1_hashCode, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_hashCode;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		V_0 = ((int32_t)(L_0%L_2));
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_3 = __this->____slots;
		int32_t L_4 = ___0_index;
		NullCheck(L_3);
		int32_t L_5 = ___1_hashCode;
		((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)))->___hashCode = L_5;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_6 = __this->____slots;
		int32_t L_7 = ___0_index;
		NullCheck(L_6);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_8 = ___2_value;
		((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value = L_8;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part0))->___m_Name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part0))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part1))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part1))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part2))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part2))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part3))->___m_Name), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_Part3))->___m_Key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)))->___value))->___m_AdditionalParts), (void*)NULL);
		#endif
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_9 = __this->____slots;
		int32_t L_10 = ___0_index;
		NullCheck(L_9);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___next = ((int32_t)il2cpp_codegen_subtract(L_14, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = __this->____buckets;
		int32_t L_16 = V_0;
		int32_t L_17 = ___0_index;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(L_16), (int32_t)((int32_t)il2cpp_codegen_add(L_17, 1)));
		return;
	}
}
// Method Definition Index: 71594
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_ContainsAllElements_m040CA79E19A6BFFD5B55F6C138D8C9ED5861E21F (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	{
		RuntimeObject* L_0 = ___0_other;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_0030;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_0030:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_5;
				L_5 = InterfaceFuncInvoker0< PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_4);
				V_1 = L_5;
				PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_6 = V_1;
				bool L_7;
				L_7 = HashSet_1_Contains_mBFF089381B4F9F83CAB4B68BF69351CDB316A5F0(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
				if (L_7)
				{
					goto IL_001d_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0033;
			}

IL_001d_1:
			{
				RuntimeObject* L_8 = V_0;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0031;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0031:
	{
		return (bool)1;
	}

IL_0033:
	{
		bool L_10 = V_2;
		return L_10;
	}
}
// Method Definition Index: 71595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalIndexOf_mF9A798624F165D0C90626783F1E8C5FF54524C56 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* V_2 = NULL;
	int32_t V_3 = 0;
	{
		V_0 = 0;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_0 = ___0_item;
		int32_t L_1;
		L_1 = HashSet_1_InternalGetHashCode_m54D386E54FD853D8B410D65049B7B5E9D96244BD(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_1 = L_1;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_2 = __this->____slots;
		V_2 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = __this->____buckets;
		int32_t L_4 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____buckets;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NullCheck(L_3);
		int32_t L_7 = ((int32_t)(L_4%L_6));
		int32_t L_8 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		goto IL_0074;
	}

IL_0027:
	{
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_9 = V_2;
		int32_t L_10 = V_3;
		NullCheck(L_9);
		int32_t L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_10)))->___hashCode;
		int32_t L_12 = V_1;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_12))))
		{
			goto IL_0052;
		}
	}
	{
		RuntimeObject* L_13 = __this->____comparer;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_14 = V_2;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_16 = ((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)))->___value;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_17 = ___0_item;
		NullCheck(L_13);
		bool L_18;
		L_18 = InterfaceFuncInvoker2< bool, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_13, L_16, L_17);
		if (!L_18)
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_19 = V_3;
		return L_19;
	}

IL_0052:
	{
		int32_t L_20 = V_0;
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_21 = V_2;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		if ((((int32_t)L_20) < ((int32_t)L_22)))
		{
			goto IL_0063;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_23 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_23, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC41E5684DECCF408AE6811BC4A564716D2F2AE9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, method);
	}

IL_0063:
	{
		int32_t L_24 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		SlotU5BU5D_tEE507B3AF89409A54A921CA9AF19EA95E275531C* L_25 = V_2;
		int32_t L_26 = V_3;
		NullCheck(L_25);
		int32_t L_27 = ((L_25)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)))->___next;
		V_3 = L_27;
	}

IL_0074:
	{
		int32_t L_28 = V_3;
		if ((((int32_t)L_28) >= ((int32_t)0)))
		{
			goto IL_0027;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 71596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 HashSet_1_CheckUniqueAndUnfoundElements_m621B1D60770E2C41C97F50A937FA2A145CC4C647 (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, RuntimeObject* ___0_other, bool ___1_returnIfUnfound, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	RuntimeObject* V_6 = NULL;
	PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 V_7;
	memset((&V_7), 0, sizeof(V_7));
	int32_t V_8 = 0;
	{
		int32_t L_0 = __this->____count;
		if (L_0)
		{
			goto IL_004f;
		}
	}
	{
		V_5 = 0;
		RuntimeObject* L_1 = ___0_other;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_1);
		V_6 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0030:
			{
				{
					RuntimeObject* L_3 = V_6;
					if (!L_3)
					{
						goto IL_003b;
					}
				}
				{
					RuntimeObject* L_4 = V_6;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_003b:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0025_1;
			}

IL_0015_1:
			{
				RuntimeObject* L_5 = V_6;
				NullCheck(L_5);
				PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_6;
				L_6 = InterfaceFuncInvoker0< PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_5);
				int32_t L_7 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_7, 1));
				goto IL_003c;
			}

IL_0025_1:
			{
				RuntimeObject* L_8 = V_6;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0015_1;
				}
			}
			{
				goto IL_003c;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003c:
	{
		(&V_0)->___uniqueCount = 0;
		int32_t L_10 = V_5;
		(&V_0)->___unfoundCount = L_10;
		ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 L_11 = V_0;
		return L_11;
	}

IL_004f:
	{
		int32_t L_12 = __this->____lastIndex;
		int32_t L_13;
		L_13 = BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C(L_12, NULL);
		V_1 = L_13;
		int32_t L_14 = V_1;
		if ((((int32_t)L_14) > ((int32_t)((int32_t)100))))
		{
			goto IL_006f;
		}
	}
	{
		int32_t L_15 = V_1;
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_15,NULL));
		if ((uintptr_t)L_16 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_17 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_16, 4));
		int8_t* L_18;
		if (L_17 == 0)
		{
			L_18 = NULL;
		}
		else
		{
			L_18 = (int8_t*)alloca(L_17);
			memset(L_18, 0, L_17);
		}
		int32_t L_19 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_20 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3(L_20, (int32_t*)L_18, L_19, NULL);
		V_2 = L_20;
		goto IL_007c;
	}

IL_006f:
	{
		int32_t L_21 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_22 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_21);
		int32_t L_23 = V_1;
		BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_24 = (BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1*)il2cpp_codegen_object_new(BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1_il2cpp_TypeInfo_var);
		BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19(L_24, L_22, L_23, NULL);
		V_2 = L_24;
	}

IL_007c:
	{
		V_3 = 0;
		V_4 = 0;
		RuntimeObject* L_25 = ___0_other;
		NullCheck(L_25);
		RuntimeObject* L_26;
		L_26 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 33), L_25);
		V_6 = L_26;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d1:
			{
				{
					RuntimeObject* L_27 = V_6;
					if (!L_27)
					{
						goto IL_00dc;
					}
				}
				{
					RuntimeObject* L_28 = V_6;
					NullCheck(L_28);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_28);
				}

IL_00dc:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00c6_1;
			}

IL_008b_1:
			{
				RuntimeObject* L_29 = V_6;
				NullCheck(L_29);
				PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_30;
				L_30 = InterfaceFuncInvoker0< PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_29);
				V_7 = L_30;
				PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_31 = V_7;
				int32_t L_32;
				L_32 = HashSet_1_InternalIndexOf_mF9A798624F165D0C90626783F1E8C5FF54524C56(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
				V_8 = L_32;
				int32_t L_33 = V_8;
				if ((((int32_t)L_33) < ((int32_t)0)))
				{
					goto IL_00bd_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_34 = V_2;
				int32_t L_35 = V_8;
				NullCheck(L_34);
				bool L_36;
				L_36 = BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2(L_34, L_35, NULL);
				if (L_36)
				{
					goto IL_00c6_1;
				}
			}
			{
				BitHelper_t2BEA51BB52EB1672DBF4163ED6757DCEEB3A4DF1* L_37 = V_2;
				int32_t L_38 = V_8;
				NullCheck(L_37);
				BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86(L_37, L_38, NULL);
				int32_t L_39 = V_4;
				V_4 = ((int32_t)il2cpp_codegen_add(L_39, 1));
				goto IL_00c6_1;
			}

IL_00bd_1:
			{
				int32_t L_40 = V_3;
				V_3 = ((int32_t)il2cpp_codegen_add(L_40, 1));
				bool L_41 = ___1_returnIfUnfound;
				if (!L_41)
				{
					goto IL_00c6_1;
				}
			}
			{
				goto IL_00dd;
			}

IL_00c6_1:
			{
				RuntimeObject* L_42 = V_6;
				NullCheck(L_42);
				bool L_43;
				L_43 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_42);
				if (L_43)
				{
					goto IL_008b_1;
				}
			}
			{
				goto IL_00dd;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00dd:
	{
		int32_t L_44 = V_4;
		(&V_0)->___uniqueCount = L_44;
		int32_t L_45 = V_3;
		(&V_0)->___unfoundCount = L_45;
		ElementCount_t0459DCE4620B57B4A9A0B5CBB4686676EF501FD9 L_46 = V_0;
		return L_46;
	}
}
// Method Definition Index: 71597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_AreEqualityComparersEqual_m3EB2FC760B463CDCE0838CAFB44F137DB6A77BFF (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___0_set1, HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* ___1_set2, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_0 = ___0_set1;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = HashSet_1_get_Comparer_m29781E9115A82E322DEE968C24FD049F711CE494_inline(L_0, NULL);
		HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* L_2 = ___1_set2;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = HashSet_1_get_Comparer_m29781E9115A82E322DEE968C24FD049F711CE494_inline(L_2, NULL);
		NullCheck(L_1);
		bool L_4;
		L_4 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, L_1, L_3);
		return L_4;
	}
}
// Method Definition Index: 71598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashSet_1_InternalGetHashCode_m54D386E54FD853D8B410D65049B7B5E9D96244BD (HashSet_1_t4FBFDDA1AD07FFD212AA59BAB18C9A86185C2243* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000a;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____comparer;
		PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 L_2 = ___0_item;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 20), L_1, L_2);
		return ((int32_t)(L_3&((int32_t)2147483647LL)));
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
// Method Definition Index: 71561
// Method Definition Index: 71562
// Method Definition Index: 71563
// Method Definition Index: 71564
// Method Definition Index: 71565
// Method Definition Index: 71566
// Method Definition Index: 71567
// Method Definition Index: 71568
// Method Definition Index: 71569
// Method Definition Index: 71570
// Method Definition Index: 71571
// Method Definition Index: 71572
// Method Definition Index: 71573
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
// Method Definition Index: 71577
// Method Definition Index: 71578
// Method Definition Index: 71579
// Method Definition Index: 71580
// Method Definition Index: 71581
// Method Definition Index: 71582
// Method Definition Index: 71583
// Method Definition Index: 71584
// Method Definition Index: 71585
// Method Definition Index: 71586
// Method Definition Index: 71587
// Method Definition Index: 71588
// Method Definition Index: 71589
// Method Definition Index: 71590
// Method Definition Index: 71591
// Method Definition Index: 71592
// Method Definition Index: 71593
// Method Definition Index: 71594
// Method Definition Index: 71595
// Method Definition Index: 71596
// Method Definition Index: 71597
// Method Definition Index: 71598
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 71561
// Method Definition Index: 71562
// Method Definition Index: 71563
// Method Definition Index: 71564
// Method Definition Index: 71565
// Method Definition Index: 71566
// Method Definition Index: 71567
// Method Definition Index: 71568
// Method Definition Index: 71569
// Method Definition Index: 71570
// Method Definition Index: 71571
// Method Definition Index: 71572
// Method Definition Index: 71573
// Method Definition Index: 71574
// Method Definition Index: 71575
// Method Definition Index: 71576
// Method Definition Index: 71577
// Method Definition Index: 71578
// Method Definition Index: 71579
// Method Definition Index: 71580
// Method Definition Index: 71581
// Method Definition Index: 71582
// Method Definition Index: 71583
// Method Definition Index: 71584
// Method Definition Index: 71585
// Method Definition Index: 71586
// Method Definition Index: 71587
// Method Definition Index: 71588
// Method Definition Index: 71589
// Method Definition Index: 71590
// Method Definition Index: 71591
// Method Definition Index: 71592
// Method Definition Index: 71593
// Method Definition Index: 71594
// Method Definition Index: 71595
// Method Definition Index: 71596
// Method Definition Index: 71597
// Method Definition Index: 71598
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 92228
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_x;
		int32_t L_1 = ___1_y;
		if ((((int32_t)L_0) > ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_y;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_x;
		return L_3;
	}
}
// Method Definition Index: 92307
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_lzcnt_m4BDBABBBAA2F9B553AE1155DFBDB552E23BB2F73_inline (int32_t ___0_x, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_x;
		int32_t L_1;
		L_1 = math_lzcnt_mCD77943688E8533316BC0238E5B9344B6433E3C0_inline(L_0, NULL);
		return L_1;
	}
}
// Method Definition Index: 92316
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_ceilpow2_m6873BD56787A2362EE6780DD54A9847561B11629_inline (int32_t ___0_x, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_x;
		___0_x = ((int32_t)il2cpp_codegen_subtract(L_0, 1));
		int32_t L_1 = ___0_x;
		int32_t L_2 = ___0_x;
		___0_x = ((int32_t)(L_1|((int32_t)(L_2>>1))));
		int32_t L_3 = ___0_x;
		int32_t L_4 = ___0_x;
		___0_x = ((int32_t)(L_3|((int32_t)(L_4>>2))));
		int32_t L_5 = ___0_x;
		int32_t L_6 = ___0_x;
		___0_x = ((int32_t)(L_5|((int32_t)(L_6>>4))));
		int32_t L_7 = ___0_x;
		int32_t L_8 = ___0_x;
		___0_x = ((int32_t)(L_7|((int32_t)(L_8>>8))));
		int32_t L_9 = ___0_x;
		int32_t L_10 = ___0_x;
		___0_x = ((int32_t)(L_9|((int32_t)(L_10>>((int32_t)16)))));
		int32_t L_11 = ___0_x;
		return ((int32_t)il2cpp_codegen_add(L_11, 1));
	}
}
// Method Definition Index: 92219
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_x;
		int32_t L_1 = ___1_y;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_y;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_x;
		return L_3;
	}
}
// Method Definition Index: 65478
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool HashMapHelper_1_get_IsCreated_mFD6A2975F04E9C84A9886543625D8E8BCA71E398_fshared_inline (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t* L_0 = __this->___Ptr;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 65476
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_CalcCapacityCeilPow2_m9E11DDA5C0E69FAD3BB1FB92BB81D4B3CFFBADC5_fshared_inline (HashMapHelper_1_t7364EEBCB4B3DE1B66766FEB2C1829C7F6CFE4BC* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___Count;
		int32_t L_1;
		L_1 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(1, L_0, NULL);
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(L_1, L_2, NULL);
		___0_capacity = L_3;
		int32_t L_4 = ___0_capacity;
		int32_t L_5 = __this->___Log2MinGrowth;
		int32_t L_6;
		L_6 = math_max_m5EE58D9462EC2A39BDE97B0C27BB14CF4A0DB651_inline(L_4, ((int32_t)(1<<((int32_t)(L_5&((int32_t)31))))), NULL);
		int32_t L_7;
		L_7 = math_ceilpow2_m6873BD56787A2362EE6780DD54A9847561B11629_inline(L_6, NULL);
		return L_7;
	}
}
// Method Definition Index: 41465
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m36ACB11EACD25CAC24617BB81FC5C3AA11976B6D_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41461
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC1C144C4AC4D9B3B2C30F06F88CB6E6AB475125E_inline (void* ___0_destination, int32_t ___1_index, uint64_t ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		uint64_t L_2 = ___2_value;
		UnsafeUtilityInternal_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC71868C665A692778D508E69E8AF1A631E0CD348_inline(L_0, L_1, L_2, NULL);
		return;
	}
}
// Method Definition Index: 65490
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashMapHelper_1_GetBucket_m3345CE3D37BC07CAFC78C5829BEBBFD3C15CC771_inline (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* __this, uint64_t* ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint64_t V_0 = 0;
	{
		uint64_t* L_0 = ___0_key;
		uint64_t L_1 = (*(uint64_t*)L_0);
		V_0 = L_1;
		int32_t L_2;
		L_2 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92((&V_0), NULL);
		uint64_t L_3 = (il2cpp_codegen_conv<uint64_t,int32_t,int32_t,false,false>(L_2,NULL));
		int32_t L_4 = __this->___BucketCapacity;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_subtract(L_4, 1)),NULL));
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)((int64_t)L_3&L_5)),NULL));
		return L_6;
	}
}
// Method Definition Index: 41459
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t UnsafeUtility_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8F5B829A65BCE22A8B2364D1C303A1E2876A3898_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		uint64_t L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mA5895D44428BCE7F38A3E30CA324F5E0E599364F_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11676
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* EqualityComparer_1_get_Default_mFF7A6E737199F092DA601ABC380996BD92336EEE_gshared_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* V_0 = NULL;
	{
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_0 = ((EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m2EA0FB1D5B051AA3C02FF460F77C79F729B43097(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t705CA5524453543A24D7C6D16B99F1AFB9F4FAC6* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 71574
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashSet_1_get_Count_mA764DCA3CB14CB2CBDF742A163492FF4DA515B63_fshared_inline (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____count;
		return L_0;
	}
}
// Method Definition Index: 923
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m94A03798DE3ED2CCEBF84727F779A9A09E2866D6_gshared_inline (Predicate_1_tCC749B46E50AF7F97D02EC114C8AA9623229FD08* __this, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, ValueTuple_2_t7375CFEC1EC69579A1347F5B8F27AAC1470A6D69, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 71587
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* HashSet_1_get_Comparer_m3025B6666A254AEDE933EDE04AD66D456C52AD00_fshared_inline (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->____comparer;
		return L_0;
	}
}
// Method Definition Index: 11676
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* EqualityComparer_1_get_Default_m16781A8E4EDB2114168E318B51C5081028E57F3D_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* V_0 = NULL;
	{
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_0 = ((EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m5C45453CBD8B5F1DD5C8F3C77D3B5F80BB1B4B70(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t63A37CBBA150A456A5494B585BAAD61AEC84FCC3* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 923
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m2F110E2073E6471BD12C32F8EA63B0673BEFB275_inline (Predicate_1_tBEF474A8961AB248CCCAB7A443893DDC7E47AD8B* __this, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11676
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* EqualityComparer_1_get_Default_m116EA0543E757039FC0248582114CD5078435378_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* V_0 = NULL;
	{
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_0 = ((EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m3E6DFD6F7D0BC2435CC38857D363A06C9F737722(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tDE5AC98ACBE0446ABE2D1FA30AA98C6DB8F61187* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 923
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mBC57F9AAD95FE4E1D54D4F368A162D155516B547_inline (Predicate_1_tAB3F82FE18F6A36DCAED4CD16CC224F635FBDED3* __this, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, EventID_tD4E92F0D1BA716CB26560DC79FBAE55C5BD2E7AF, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11676
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* V_0 = NULL;
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_0 = ((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 923
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mD16C664FFE93598D1C12AC86190D12B0F90B5419_inline (Predicate_1_t6CDE3111264F492F4F13277756366A07CA78A4C3* __this, int32_t ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11676
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* EqualityComparer_1_get_Default_m33839529811E5B677FAC3708C8617567B0D8A1AB_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* V_0 = NULL;
	{
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_0 = ((EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m5641C6C3F2BDF42B483859C7C1A734FB901C288B(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t2766463F2A6BE0C5D9D2243C503B3989C7C10668* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 923
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m8B4BDF53D356DC2B6824AECCDFD936A57EBBA0FD_inline (Predicate_1_t2EB8AC06BBCD4AE7BBA9CACDDC3C1B9F611618FD* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11676
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* EqualityComparer_1_get_Default_m4A0896866DFD0BFADEBA26A14A4072AC9D9917D8_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* V_0 = NULL;
	{
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_0 = ((EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m4E64AAE802462A678408F709D7B1A2E4F1FD603F(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tC97615634F3C29334C0D1ACC23E26BE1CDCEEF38* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 923
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mD00114316CACFD296E750222C808E712960B78FF_inline (Predicate_1_tB989E899E4E9154054171E9C43DE93B6E2AC6FCC* __this, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, PropertyPath_tA523CA2740853534DF6C009C588464B45A6D0A79, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 92308
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_lzcnt_mCD77943688E8533316BC0238E5B9344B6433E3C0_inline (uint32_t ___0_x, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	LongDoubleUnion_t17011746129284B81F310F56E20D549A6F6710D0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		uint32_t L_0 = ___0_x;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		return ((int32_t)32);
	}

IL_0006:
	{
		(&V_0)->___doubleValue = (0.0);
		uint32_t L_1 = ___0_x;
		uint64_t L_2 = (il2cpp_codegen_conv<uint64_t,uint32_t,int32_t,false,false>(L_1,NULL));
		(&V_0)->___longValue = ((int64_t)il2cpp_codegen_add(((int64_t)4841369599423283200LL), (int64_t)L_2));
		double* L_3 = (double*)(&(&V_0)->___doubleValue);
		double* L_4 = L_3;
		double L_5 = *(L_4);
		*(L_4) = ((double)il2cpp_codegen_subtract(L_5, (4503599627370496.0)));
		LongDoubleUnion_t17011746129284B81F310F56E20D549A6F6710D0 L_6 = V_0;
		int64_t L_7 = L_6.___longValue;
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)(L_7>>((int32_t)52))),NULL));
		return ((int32_t)il2cpp_codegen_subtract(((int32_t)1054), L_8));
	}
}
// Method Definition Index: 94616
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m36ACB11EACD25CAC24617BB81FC5C3AA11976B6D_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t10CEB3B5C979FADE1F3F9B38C6D77C6319AFF57C_mE4C1913654DEBAAC6B7EC085814397556183951E_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mF4BBC9CA9F485924727D26DA8F0ED7E229C1C2D1_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 94612
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC71868C665A692778D508E69E8AF1A631E0CD348_inline (void* ___0_destination, int32_t ___1_index, uint64_t ___2_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint64_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint64_t L_6 = ___2_value;
		*(uint64_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
// Method Definition Index: 94610
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t UnsafeUtilityInternal_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mA5895D44428BCE7F38A3E30CA324F5E0E599364F_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint64_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint64_t L_6 = (*(uint64_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 94615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t10CEB3B5C979FADE1F3F9B38C6D77C6319AFF57C_mE4C1913654DEBAAC6B7EC085814397556183951E_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t10CEB3B5C979FADE1F3F9B38C6D77C6319AFF57C);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 94615
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mF4BBC9CA9F485924727D26DA8F0ED7E229C1C2D1_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F);
		return (int32_t)L_0;
	}
}
