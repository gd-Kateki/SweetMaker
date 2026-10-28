#include "pch-cpp.hpp"





struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1Invoker;
template <typename T1>
struct InterfaceActionInvoker1Invoker<T1*>
{
	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1* p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		void* params[1] = { p1 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, params[0]);
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
struct InvokerFuncInvoker4<R, T1, T2, T3*, T4*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2 p2, T3* p3, T4* p4)
	{
		R ret;
		void* params[4] = { &p1, &p2, p3, p4 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
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
template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
struct InvokerFuncInvoker5;
template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
struct InvokerFuncInvoker5<R, T1*, T2, T3, T4*, T5*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3 p3, T4* p4, T5* p5)
	{
		R ret;
		void* params[5] = { p1, &p2, &p3, p4, p5 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF;
struct Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C;
struct Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7;
struct Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023;
struct Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7;
struct Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440;
struct Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505;
struct Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4;
struct Action_1_t923A20D1D4F6B55B2ED5AE21B90F1A0CE0450D99;
struct Comparison_1_t481A1DF2F78166A7F0827FA0A9A8E26233D3973E;
struct Comparison_1_t6447E02D95C4C995AE37F197D13D355CC1E9AE10;
struct Comparison_1_t035E1D57F8E92650AD1DCAAFF9632D0F026CA046;
struct Comparison_1_t89BA6BA726C49026677C45BEDBD41952739E06A2;
struct Comparison_1_t55FCE173570442A2D451AE8BFC15B22D41D55DC9;
struct Comparison_1_tCC0DD2EF5FD4D03E423A3C172F5D948A944669DA;
struct Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5;
struct Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E;
struct Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49;
struct ICollection_1_tD2502FFE0EF5514D4A736ACD8FE04B57D7394DA3;
struct ICollection_1_tD6E7A0BE4457456D8D68E05E3B70A884C92C269B;
struct ICollection_1_t55F4FEF52A396FAC3E4F5016AA390047F80DF782;
struct ICollection_1_t0EB5E6AF628EDA8C574A6E62694F35A101C5EDE9;
struct ICollection_1_t191C893BDB2C098042ED421B3FEB9C45162A4D0B;
struct ICollection_1_tB4FB43265EAB02449E3C07131B2F1375CF1E5FEC;
struct ICollection_1_t58D5B5A564BF08CD3C8EE106100AC0D7B8C4508B;
struct ICollection_1_t8BB9FA45EE380E6FBD45BA62F6175AAB6C1D7B09;
struct ICollection_1_tB388ED908E2D241F56264CA971F25D9ADC1ADEC3;
struct IComparer_1_t56F8CE7C6F56BB755322EC41EEF4092C027F5E1E;
struct IComparer_1_t6BC180E73C92A7A8633AA035BC770DB8CA760239;
struct IComparer_1_tF45F94B89D1B0B3CC7E66C1DA205DBF44ED116AF;
struct IComparer_1_t69CA28CD3CA60CD4686A0CBCCB2755CF5E55061B;
struct IComparer_1_t12FDD9882EC7ECD970F65BAE66029647C62E55C5;
struct IComparer_1_t0A49E09E645CEE9B60B8B6989545CE01D6497156;
struct IComparer_1_t3B0F39D062C0830CA6D3DD5C771FEF9D2E6F5DEF;
struct IComparer_1_tCA6EADC3ABE46D05BB75C1D455892FDF1DB7C20A;
struct IComparer_1_tCA720E7837F12C38065A4AB632B5FAAD19EC30AA;
struct IEnumerable_1_tD5C0FD17E45BB16A64310D831E29C350A184590F;
struct IEnumerable_1_t6F76C3DE352DC9A88E75D84DAEAEEE43FD07A76F;
struct IEnumerable_1_t7077BBA3C7C066A2C0A5A8CE392424FDFCDE0EE3;
struct IEnumerable_1_t904FA51796BAFAFF18394056D302B106606019DC;
struct IEnumerable_1_tDDB768CC2EC358D9530029011A515F5583CA0015;
struct IEnumerable_1_tCDAD4B3857407CDC6FE32CF5B7CBC3F07A4D2DA5;
struct IEnumerable_1_t6D5FFB1B4A97F30426C5D394135AD0D2FAEAE680;
struct IEnumerable_1_tE450BCE97960A576892BD3F4C84B89C53DCFF504;
struct IEnumerable_1_t29E7244AE33B71FA0981E50D5BC73B7938F35C66;
struct IEnumerator_1_t1DC9BF0C441509977AE52846CAE10D10A21C5FE0;
struct IEnumerator_1_t06541250E744F82918C560E3AF79DA72DFABEC49;
struct IEnumerator_1_t50290435BC8E629C0A84C7D52F99AEBE0B90CFB4;
struct IEnumerator_1_t2390E479B6DB7DEA6DE39BB6212EBB88FD6163B4;
struct IEnumerator_1_tFD92D349677E89FA94B8AEC66F76C0041590FEDB;
struct IEnumerator_1_tB00265C848CC8131C088CF2E0C06FA0AA8C3E66F;
struct IEnumerator_1_tB41B292FAFD525FC5C54D7E469F0BA1A193CA8B1;
struct IEnumerator_1_t9D5AD8C382C310ECCB5FF06F8FE44118996EE79D;
struct IEnumerator_1_t75CB2681E18F7F2791528FA2CA60361FDB5DA08D;
struct IList_1_t42FF818BEA4BF4853E17DE64566576B4020C72EF;
struct IList_1_t057158FE233DC0721BC83986546CB11DD55EFDAD;
struct IList_1_t5369B140039A15A341DDD4D472C88280E058DE6A;
struct IList_1_t394566ACD92198848950B83D3260ADE4FEF94687;
struct IList_1_t82892C93D8E03E68BB11DCD20470A61C1188C7B5;
struct IList_1_tD4524336A640CBA52D02C55E127F36B55880C425;
struct IList_1_t7DC7A22F42EEFA1E8D796516A9F22282DF4EB5FA;
struct IList_1_tE00655F1AC041AB3B785699F9C5A6EA951470879;
struct IList_1_t8AC59FFD0F90EC2DAD4C3FA39B2A5851F9D2987A;
struct List_1_t41896DF347A129D13205BBFADE03DFB21E05E459;
struct List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317;
struct List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A;
struct List_1_tE320DA6F66936619F210A03F77F93803DCAB9355;
struct List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33;
struct List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB;
struct List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7;
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E;
struct List_1_t92E81A9A2159538A8E6169454F51D454A6093C75;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D;
struct Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433;
struct Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67;
struct Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B;
struct Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5;
struct Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0;
struct Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88;
struct Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626;
struct Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107;
struct ReadOnlyCollection_1_tC097ADAD4728DA15D13F639EC263BD398D57B04F;
struct ReadOnlyCollection_1_tA87EA4F23BAC952A78BDE9A5B94F3091DB5C7861;
struct ReadOnlyCollection_1_tC4584ACB2E63F593E2DEF37DDA8EA9A18DD97F5D;
struct ReadOnlyCollection_1_tB6FD6BA75C6F479B6860FCBA235488206BF20E52;
struct ReadOnlyCollection_1_t803A81BE343B15275BCD30A219ACAC97F0B9A1C8;
struct ReadOnlyCollection_1_t95C4CE7A3281F650247DAD055168AC75CA2E0D94;
struct ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263;
struct ReadOnlyCollection_1_tD86E076A19D3DF6CFD1AC3FEE937BD0FB0B39AF7;
struct ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD;
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2;
struct WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D;
struct X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299;
struct XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7;
struct XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
struct MethodInfo_t;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RuntimeObject_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD;
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2;
struct WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D;
struct X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299;
struct XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7;
struct XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317  : public RuntimeObject
{
	Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A  : public RuntimeObject
{
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tE320DA6F66936619F210A03F77F93803DCAB9355  : public RuntimeObject
{
	WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33  : public RuntimeObject
{
	X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB  : public RuntimeObject
{
	XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7  : public RuntimeObject
{
	XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E  : public RuntimeObject
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t92E81A9A2159538A8E6169454F51D454A6093C75  : public RuntimeObject
{
	__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A  : public RuntimeObject
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tC097ADAD4728DA15D13F639EC263BD398D57B04F  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tA87EA4F23BAC952A78BDE9A5B94F3091DB5C7861  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tC4584ACB2E63F593E2DEF37DDA8EA9A18DD97F5D  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB6FD6BA75C6F479B6860FCBA235488206BF20E52  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t803A81BE343B15275BCD30A219ACAC97F0B9A1C8  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t95C4CE7A3281F650247DAD055168AC75CA2E0D94  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tD86E076A19D3DF6CFD1AC3FEE937BD0FB0B39AF7  : public RuntimeObject
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
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ____list;
	int32_t ____index;
	int32_t ____version;
	Il2CppSharedGenericObject* ____current;
};
struct Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0 
{
	List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* ____list;
	int32_t ____index;
	int32_t ____version;
	uint8_t ____current;
};
typedef Il2CppFullySharedGenericStruct Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF;
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
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
struct Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 
{
	float ___m00;
	float ___m10;
	float ___m20;
	float ___m30;
	float ___m01;
	float ___m11;
	float ___m21;
	float ___m31;
	float ___m02;
	float ___m12;
	float ___m22;
	float ___m32;
	float ___m03;
	float ___m13;
	float ___m23;
	float ___m33;
};
struct Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D 
{
	float ___m_XMin;
	float ___m_YMin;
	float ___m_Width;
	float ___m_Height;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	float ___x;
	float ___y;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
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
struct Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A 
{
	List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* ____list;
	int32_t ____index;
	int32_t ____version;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ____current;
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
struct ExceptionArgument_t60E7F8D9DE5362CBE9365893983C30302D83B778 
{
	int32_t ___value__;
};
struct ExceptionResource_t609A85E253A4E615583553D91D839E2E79FDFBD9 
{
	int32_t ___value__;
};
struct FeatureType_t794EFAD24C687FA0CDC5A313581A39F5CB61CC41 
{
	int32_t ___value__;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct VertexAttribute_tF34C1B76F20CA4AEC9D606BCD37A8A0C4A24C9A6 
{
	int32_t ___value__;
};
struct VertexAttributeFormat_tD714C51E671502B116ACE5E23F042BA80649D32F 
{
	int32_t ___value__;
};
struct WebshopExternalTokenType_tE6687CE2F4F1570455D3DE2453F526488B38A76F 
{
	int32_t ___value__;
};
struct X509ChainStatusFlags_t57C80D7C1F4C319F6D6B9FBDEA402E3023E6C769 
{
	int32_t ___value__;
};
struct XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 
{
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___projMatrix;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___viewMatrix;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___prevViewMatrix;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___viewport;
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___occlusionMesh;
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___visibleMesh;
	int32_t ___textureArraySlice;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___eyeCenterUV;
	bool ___isPrevViewMatrixValid;
};
struct XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_marshaled_pinvoke
{
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___projMatrix;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___viewMatrix;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___prevViewMatrix;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___viewport;
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___occlusionMesh;
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___visibleMesh;
	int32_t ___textureArraySlice;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___eyeCenterUV;
	int32_t ___isPrevViewMatrixValid;
};
struct XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_marshaled_com
{
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___projMatrix;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___viewMatrix;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___prevViewMatrix;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___viewport;
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___occlusionMesh;
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___visibleMesh;
	int32_t ___textureArraySlice;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___eyeCenterUV;
	int32_t ___isPrevViewMatrixValid;
};
struct Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1 
{
	List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* ____list;
	int32_t ____index;
	int32_t ____version;
	XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ____current;
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
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 
{
	int32_t ___U3CattributeU3Ek__BackingField;
	int32_t ___U3CformatU3Ek__BackingField;
	int32_t ___U3CdimensionU3Ek__BackingField;
	int32_t ___U3CstreamU3Ek__BackingField;
};
struct WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 
{
	int32_t ___U3CTypeU3Ek__BackingField;
	String_t* ___U3CTokenU3Ek__BackingField;
};
struct WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_marshaled_pinvoke
{
	int32_t ___U3CTypeU3Ek__BackingField;
	char* ___U3CTokenU3Ek__BackingField;
};
struct WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_marshaled_com
{
	int32_t ___U3CTypeU3Ek__BackingField;
	Il2CppChar* ___U3CTokenU3Ek__BackingField;
};
struct X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D 
{
	int32_t ___status;
	String_t* ___info;
};
struct X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_marshaled_pinvoke
{
	int32_t ___status;
	char* ___info;
};
struct X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_marshaled_com
{
	int32_t ___status;
	Il2CppChar* ___info;
};
struct XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 
{
	String_t* ___name;
	List_1_t41896DF347A129D13205BBFADE03DFB21E05E459* ___usageHints;
	int32_t ___featureType;
	uint32_t ___customSize;
};
struct XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_marshaled_pinvoke
{
	char* ___name;
	List_1_t41896DF347A129D13205BBFADE03DFB21E05E459* ___usageHints;
	int32_t ___featureType;
	uint32_t ___customSize;
};
struct XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_marshaled_com
{
	Il2CppChar* ___name;
	List_1_t41896DF347A129D13205BBFADE03DFB21E05E459* ___usageHints;
	int32_t ___featureType;
	uint32_t ___customSize;
};
struct Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF  : public MulticastDelegate_t
{
};
struct Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C  : public MulticastDelegate_t
{
};
struct Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7  : public MulticastDelegate_t
{
};
struct Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023  : public MulticastDelegate_t
{
};
struct Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7  : public MulticastDelegate_t
{
};
struct Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440  : public MulticastDelegate_t
{
};
struct Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505  : public MulticastDelegate_t
{
};
struct Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4  : public MulticastDelegate_t
{
};
struct Action_1_t923A20D1D4F6B55B2ED5AE21B90F1A0CE0450D99  : public MulticastDelegate_t
{
};
struct Comparison_1_t481A1DF2F78166A7F0827FA0A9A8E26233D3973E  : public MulticastDelegate_t
{
};
struct Comparison_1_t6447E02D95C4C995AE37F197D13D355CC1E9AE10  : public MulticastDelegate_t
{
};
struct Comparison_1_t035E1D57F8E92650AD1DCAAFF9632D0F026CA046  : public MulticastDelegate_t
{
};
struct Comparison_1_t89BA6BA726C49026677C45BEDBD41952739E06A2  : public MulticastDelegate_t
{
};
struct Comparison_1_t55FCE173570442A2D451AE8BFC15B22D41D55DC9  : public MulticastDelegate_t
{
};
struct Comparison_1_tCC0DD2EF5FD4D03E423A3C172F5D948A944669DA  : public MulticastDelegate_t
{
};
struct Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5  : public MulticastDelegate_t
{
};
struct Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E  : public MulticastDelegate_t
{
};
struct Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49  : public MulticastDelegate_t
{
};
struct Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC 
{
	List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* ____list;
	int32_t ____index;
	int32_t ____version;
	VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ____current;
};
struct Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD 
{
	List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* ____list;
	int32_t ____index;
	int32_t ____version;
	WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ____current;
};
struct Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588 
{
	List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* ____list;
	int32_t ____index;
	int32_t ____version;
	X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ____current;
};
struct Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0 
{
	List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* ____list;
	int32_t ____index;
	int32_t ____version;
	XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ____current;
};
struct Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D  : public MulticastDelegate_t
{
};
struct Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433  : public MulticastDelegate_t
{
};
struct Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67  : public MulticastDelegate_t
{
};
struct Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B  : public MulticastDelegate_t
{
};
struct Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5  : public MulticastDelegate_t
{
};
struct Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0  : public MulticastDelegate_t
{
};
struct Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88  : public MulticastDelegate_t
{
};
struct Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626  : public MulticastDelegate_t
{
};
struct Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107  : public MulticastDelegate_t
{
};
struct ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields
{
	Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___s_emptyArray;
};
struct List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields
{
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___s_emptyArray;
};
struct List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields
{
	WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___s_emptyArray;
};
struct List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields
{
	X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___s_emptyArray;
};
struct List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields
{
	XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___s_emptyArray;
};
struct List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields
{
	XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___s_emptyArray;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___s_emptyArray;
};
struct List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields
{
	__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___s_emptyArray;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___s_emptyArray;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_StaticFields
{
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___zeroVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___oneVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___positiveInfinityVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___negativeInfinityVector;
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
struct Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD  : public RuntimeArray
{
	ALIGN_FIELD (8) Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 m_Items[1];

	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 value)
	{
		m_Items[index] = value;
	}
};
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2  : public RuntimeArray
{
	ALIGN_FIELD (8) VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 m_Items[1];

	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 value)
	{
		m_Items[index] = value;
	}
};
struct WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D  : public RuntimeArray
{
	ALIGN_FIELD (8) WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 m_Items[1];

	inline WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CTokenU3Ek__BackingField), (void*)NULL);
	}
	inline WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CTokenU3Ek__BackingField), (void*)NULL);
	}
};
struct X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299  : public RuntimeArray
{
	ALIGN_FIELD (8) X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D m_Items[1];

	inline X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___info), (void*)NULL);
	}
	inline X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___info), (void*)NULL);
	}
};
struct XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7  : public RuntimeArray
{
	ALIGN_FIELD (8) XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 m_Items[1];

	inline XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___usageHints), (void*)NULL);
		#endif
	}
	inline XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___usageHints), (void*)NULL);
		#endif
	}
};
struct XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D  : public RuntimeArray
{
	ALIGN_FIELD (8) XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 m_Items[1];

	inline XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___occlusionMesh), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___visibleMesh), (void*)NULL);
		#endif
	}
	inline XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___occlusionMesh), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___visibleMesh), (void*)NULL);
		#endif
	}
};
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
struct __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
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


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m26993F578F05F8D920AF3C8F683CF9945DF89654 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 List_1_get_Item_mF5D504FB09F98DB07ABEF3D064237C0BCBD8EDC4 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mEC1C52B874AD5BD406704205ABB2229EC53C8587 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9CE045A3C18BAFF826CE4686A0F2D3D00930416F (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m3E361A77D2986AAB36EB748E177978BF014B3E20 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mBA43C64613DB8DC278E2794C1899386CE9A8E9E5 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m65F0731FF2C839C25530522F74BE029D34851222_inline (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mFF2B0BD7EF36E3CFCDC13D697EF56BA8B408AB24 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared (ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8* __this, RuntimeObject* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mCF69FB022FF37FC83FCCA53C1D648929F23D783C (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, int32_t ___1_index, int32_t ___2_length, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m6DB615C6555A7223C82FE5B3143C2CBCE6DB56A3 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mA0FC83E94A2B5036280B7D8E33D97B171C7A3C4A (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mEA00D4F19254CE6BDA86092ADB4FEC44F26BCABC (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m2B0853629C0AB51AFB8D5D4F1BE146816A1BC05A (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m4349F707AFD29359D197EE27DD358DF37C12E2F8 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m04DC58E48FEAD029F01D3F3C89897D792153E65E (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline (Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m95C311035E2177D40ACD62E9D08BA9112E64502F (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m66BC05CFB9CEB99D7E604E23D99B80D00D5878AA (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m9293612C0DEA13BB9B5CADE956F799DE325BBD4B_inline (Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m719A771160FA0C4E0A4B3873553711844C534C5E (Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A* __this, List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m6DE881973FEDB21534398B48EC603235384D7543 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mE87C571495149031291F9689A1B42F9602497CC1 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mB7456174239E3B8D43A5010D5C2FCCAD202771DE (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mA6D665F94D3F7826F488DF40C349E9C597B2954D (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mFD67A83E6D563627CF3CE27A150D98204CD10E13 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m465E995BBA92B01A5E941A06EB6601F358514F29 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mCD238B8516B142585C6FD2359049E89B42B5D061 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA826BF7BB567765985BDF8FA09B5BE4E023EAEFE (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m9727818F9220BFB7086FB70AECF191C6359707D8 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m13C3861259F6EFC91390A9A35480FD1839085598 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t481A1DF2F78166A7F0827FA0A9A8E26233D3973E* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m7DB9498F929F4CFDF5C0CF824A46680C398F06CD (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 List_1_get_Item_m9570D3859A5938946A3F72E8BE5836F938D73893 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m37CF179DA2A4DC544E181AB6152F610E55CF79E0 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mB3E57754B24B9C5E644B92B770B84D0F1D536028 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mC00103AF93A8667AEDB218D04F80F511F8194C9F (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mD09A0A4D5F4FC01ACDD6A7BC8975F4955A7E1CF6 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m8671BB7A955C16011966B029D9912C97256E551D_inline (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mD8B4739BC8DB91F6B5DFBAA474808F87DFAEB365 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m8E43D5DB47A684DE0EB2082A70E0371D355EC399 (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, int32_t ___1_index, int32_t ___2_length, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m8B1F2694EA45CC157FAE79AD1366C7C7C6567371 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mE0C5BD3D2B8D54D1F623027DD5F7278F438ABBEA (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m48FB0001AE7658BB8710D2834A5744F892AC7647 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mE62BDAE8E56D02D25F553CFFD73521AFE4D83279 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m896CE24A195E32A1363C4F47EC5A86A603400B18 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m1CAB513D06B1472A368559829C8E089AF07FF851 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline (Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m6E15F63947B41B703AC0A083850BC3DF9B4CE4DF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mE799B12F5A68426E6DD83B2C20848D06AF5E1F7C (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m74BA9791568FC6CEE9D33F5F6135FB35B40FF1FA_inline (Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m59A9B193503149669F9A1CDB976DE9A92E7C2BF4 (Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC* __this, List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m928B6B1FDFC0416B78DBDF07575A46F41CF80B13 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_mD66A99635C0749F6DCABDAF67917A44E48B647FF (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m7054F9A6D9ED69BFBF644B2498E93E5AA1BCD5DC (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m9923D8311DC83F4A2AE170B02A72A75F5974DE02 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mC12DEE4882625EB0E815AB856F0A4D86A85E52EF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m606AE91C5E089F1854C7D93CEB9A076DE041F6FB (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_mCAB85548741CC2290CD5711D7BDD1D605F3DDD06 (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m7045BFA1D7EA8DBA05CA0CD348D61D0EA85B8682 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m209AFB649D59EAEF75AD3C1696A43FDF81C7ADFE (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m791404477F2D37E776687167796922908A64BCA4 (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t6447E02D95C4C995AE37F197D13D355CC1E9AE10* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m2651B082BDD0B240BC0A569B1407DCFC2E64652E (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 List_1_get_Item_m2924E7746F6C53EDFEA3CCF16EF3B218E419DC3D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mA1DAD0FF706B1F126927FFDD38749A7A54FA292E (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m005D2CC35F5E7CBC3CA9B247C9A6F53C82079AB3 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m0CFF45D3EDB67B4F93F72B28293EACF735E2D915 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mEB188A6DEB187615EA3F109C3D6FA101549AAE49 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m8733206CE9C292CC7AE372250D705ECD9BC11353_inline (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mF79B155E875CD01C203BD61F17DFEF51D3AE620D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m0995AD1F41D4F87F3A61CFE7C33B65A8459A95E2 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, int32_t ___1_index, int32_t ___2_length, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m66C94A2B368326DFDC153672733D937188CD7F2B (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m87D9B1778F33B1D47D8B10D757427E7EB94591BE (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m258CDE81FD7826B5BC9394598147752BC8856F41 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mF21748A6EAFA84C0E8D2CF169CEB7CAD353BDE33 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m365573DAEE0CC09ED7C9EF91DA5F363256AA4F9F (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mD98A4B0A65890CA3D82C9D19CAA86DCD6A5ADC9B (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline (Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mCA968DFD73D48BDB875296E6A8814E215093022D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m195A090FF38080873B8C05C6DE14FFDECE48E591 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m77C7D2ACEEF9DF21BE26F4303BCFBEFEF8F7C764_inline (Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m44CA5DD6AF03BEEEA951E58A67514FFE9FC30048 (Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD* __this, List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m8F1145270D67E0B3CEBC6254CA273ACFCAEDC702 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mCAA516810A5A4E54E12136DD70E915064768AF24 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mEC7B7774A45AC794B51AD1DADB2E680D0F85791C (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m7797CB3726E2D8D8F08F35B4D0853DBF469FB501 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m5440E53F4F7D13F14EC26C51EE4865A298C0F217 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m3520CDF5BC09508EF2280BB34D85F62338B365E4 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m0B0C8AC7BD3093D4B3350A89EA537D4654583A0A (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA8B491BB3C19694F857CE4DF4901D1606950C26F (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m52E580379FC406094751B182A878AE05CAD72D19 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m4C5B394849E5E1EBD694444DCD64F30ACD6BD648 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t035E1D57F8E92650AD1DCAAFF9632D0F026CA046* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m933BBC3774C46C94DE1BF5CA6AC39EC4E5D37D30 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D List_1_get_Item_m0B7EFA3EB9BD3A50B8BDEB2463B28E86EF6BA0F1 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA17F2B115A27352849BFF45AE179346E639C2B76 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m0726156C6DF11D5675F28EC4CACF2EC179D86E55 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m57CCC347F7A2D40306F42BE2E7822E13C0516E91 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m53C9A0D593A54DE616005FC0C75DF1DE1FC0EB25 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m1794A41080E7D990FC91C41044F40666784FAF5F_inline (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m806B1F613ACD9C02EB149299D718A1B51DC8779D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mC50E157F7E181EDEA92E51C9F2673CDAE84B5E51 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, int32_t ___1_index, int32_t ___2_length, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m2B49FAD4F587A9C4CA5CBE6AB74CF60105435E16 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mA598DCD7147BAA1775E07E60CC8F2BCBC052B9E6 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m8FA678F87A5F9E701EF1E74D1DC390973929CC9D (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mED6A7530571DED9EC65DE47BF2DC8B37D3BABE0D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5C29B9150B8CD4C2BA48966294BFDABF3A119C10 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA0A82440E4B1821AF295DCEFACEDE6414F672C9B (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline (Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mEF23AA633A6618208A8864BB4A59260DFF6E0AF4 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mE37DB2FA21A091A57F38BB3727C2D4F1586DC38F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m4298A6EF344901142C650584A3B102A0582873A6_inline (Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m0F297AA4D5E9DCCA5B022568286E587CFFA548B9 (Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588* __this, List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mBD3EEB3E27E27898E6E051D4D657BA527DF06D31 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA53DD5C386D2BC150E7AF665AD973861A0325966 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mA52D0749531BA9E39D056DEC246376A16DFA768D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m663ADE2FC3D8F054681C0FF19E9996185AB5BDD7 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAEDA4677C2ADEDBDA2DF0F8F9E9F0748C01E553F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m90285F94EF464888EDC820B62826C0482EAA1883 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_m12119C509581F764BD40D4271062FAA078B90764 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m32893B90CE4E1370C3F82B6EBE941635F7C62A96 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mE15993628BBDD272038B8BB6E5847DD6ECFED252 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m54388C4AC33B08A6F59DA0D043DE35C6F7CE74CD (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t89BA6BA726C49026677C45BEDBD41952739E06A2* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m6C3A37912654122DD8AE143EFEB1C2A4C1015C29 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 List_1_get_Item_m4C81AE785745E7C9A726104CD2F588258FBE5E8F (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mADBF15F169E5DF2762161FB96F64C99569429300 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m6C903F3CAAD0D6DA54369D2224E52DFADB242F60 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m55AFD45DC0ADD64C8749E1B59252B0BF0793CE49 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB16BDFA4B73F390167601AF70BC65637BF9AE433 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m50157FAAF8FE0562A862140A17AD2B1097B078E7_inline (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m2555E93F7C903532A49529BCC327427FC3B1C6EE (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_m469FFB0730A2E7136D62A2AE6D197A1858EC6CFE (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, int32_t ___1_index, int32_t ___2_length, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m603A1422A5D4C6AC20CFDB1897BD527164CFE059 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m54DA0380F7731F2146DEDD98FC646038D9FC3923 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m72B9D7AAB1A1E284232CC6C4CF613FEA6A227584 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mA297C73B52DACB79EAF9BABC705E6D7DB8EB7978 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5593B7194363BCB1B716A4ECA594F6E2CC03F94C (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m14D5EB230C22B6C4A649235CC3E08C5F6561E15B (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline (Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m3A09BF3BCAAF3C61D9A2EEF2C3090311C21A62EB (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m94DC2E52655A61CACBDD8FFD47097AAE3E618198 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m14B5F0EFFF227D076151E00CACE917B6512254B8_inline (Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m5CBA8C17D9A8E5F5E385A4876B9B1745FA3CB8C0 (Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0* __this, List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m1742E82D5AF5200DFAC69B895C4A24E80D760C4D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mECE416DA9044547B55FF326280E3AFAB15850B37 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mBECAB59CCD69670908799776F1D6507EF7EA7D87 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m53875FA8AA50D0F755EE525314DB9818741B6E2F (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m15AEA673A2E9F2A482D49F374814A49D0734CEC6 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m3CE641659C3CD3760E5EE96E88FA7006B7D9995D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_m6953DC1CD28104B40EF7B6C79E12EDA04CCC52F3 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m52E4077FCE9FF6DF21E5DCE7A99DACB700AB2E0D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mACACE6CA017DAF3419A4C86E329FA9CFE4018C03 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m479DAA4C8994B2FBFA82BCC2220725F25C35DCD9 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t55FCE173570442A2D451AE8BFC15B22D41D55DC9* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m9B49892AA65CC96277D2D79218DB14788068DA41 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 List_1_get_Item_mFFCB4E0F2978CE787223C6D1734D41306942EB30 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m8ADD7E3A387FB67C59B3A2FB00548D05874F417B (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m7A495455B6674DB278F9185B18C72E8BEF911BA7 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m940FD70455448D1B8E960B93BE1194188D09F786 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m479A86683CEE12F0C214CB5F3A05549381DC660E (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m26A98FFE1090E98CCB9AA0278EC4017152C89F85_inline (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m992A9116BAD4C2EC04F0F9C88B89A1B52C17EB80 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m5D4301D56E29378AE3D729C7AB2EACA0F911398F (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, int32_t ___1_index, int32_t ___2_length, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m0280BDACD6B1BE7BD4B43BF0E243AAA3240204CF (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mFDE66951AEA8FFF75C995BEF3AA99D47C3AA8B21 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m70B0273AB943F33BC49BE752D55720E5A6B45863 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4EEC6DE78174B1A7C89D5DA9D0B9923881561328 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mD7F92B17978CCAD780D5027AB9ED84DC79B44DFD (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mB4E76D35717A9DB62561714DAF4292E2B4404D58 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline (Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m182300006C2F508433064C65566BFE6D4210BF3D (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m2932FC34CFE0B8373CC0E031216528C99A0F008B (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m1E148200B150317478F1EAF858AE3F230EB8D4AA_inline (Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m9649445EB055BFD3F58AC786F4A50C5843ACBEE5 (Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1* __this, List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mF13A6D0FE4169F106512A28BA7B29E68E7D4E1FA (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_mF9B09B9F1A4B269FF6D212596871AA5569E5D8B2 (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m4C4C068BB28606E5DE98FB7616757884C4CCD698 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m0A038738F0C2834BE11C14491130246276431B20 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mBA2ED23FD37868DBBC644AD7E3A9935F0DE57CB3 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m39920E0E4B4089FD8E4C0A5CA145911B31FA1D15 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m9E4B79FAA123091EDADB1E0EDBD296F9AECCBCD9 (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m81FCD89C0A108E16223AF643893B87B1BF43002D (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m4595EBB46D67A07754F8987A2B382C13811C8D88 (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m5935F327EBF640B1FEB63092149D6B0D5ADD8C4D (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tCC0DD2EF5FD4D03E423A3C172F5D948A944669DA* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054_gshared (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisIl2CppSharedGenericObject_m6D8A1F3C8EDCAAF226FE8B32CBB649F099D8C16B_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, Il2CppSharedGenericObject* ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mB2BE3DF9182ED9C862AA44566C878D046534474E_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, Il2CppSharedGenericObject* ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mD56F0607D7DAD9622F7DE2C6C8957D9C7847EEC5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_gshared_inline (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m75AB13CBCA95A0E0722F6CDE89F0CBDAB27322DA_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_gshared_inline (Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9_gshared (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m54D719307910A9DC9CD4DEFA8AE2626F49EB7516_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, Il2CppSharedGenericObject* ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m426F79399C24D92B89DBA07ABF04AD125278169D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t List_1_get_Item_mAA1579D28843BE101AF5735731E5F6C74CADBC25_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m1BCCAEF15531A89027A8C21D496867A6744E119A_gshared (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m8178833364A7D14F2AC3ACE6FC8DE95D5FF9B7BB_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, uint8_t ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m76095CD55E33211D69331C6DBF9A12AE1E1F544C_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m4950BFDE5379FB1EE9E82C2AA9E4631881DED88D_gshared_inline (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m169B03E44FA6B59F43486EEEA8E98C44F7B5751E_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mCC8652BE0AE4082A8DEA7D0B05CF46DE9C38F9D1_gshared (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, int32_t ___1_index, int32_t ___2_length, uint8_t ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mE7F3B1638176AF8F4CC0E83A5D06258B839D9F6F_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, uint8_t ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m0AFABF6F1B3F0240ED564A30B2610DABA9881872_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mF6062BD01FB16E2976FE77274D3B42294B156F8D_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mF83AE21E82590B5270938D4389B13BD6007F3C21_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mA829BA58B34F17EE008D7D66468B478647866621_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m90942CB72E241DC275A09D90F31B0CAAA2301F15_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_gshared_inline (Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* __this, uint8_t ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m98B9B243A5F21F0F6F288BC5D562F9D215769C08_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m2943A682B3924333EEBA9CAA0CDC4FA2FCA17ADC_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m3F52CF20C1CBEFC2E57A2FBAD08312B7C5EA6ECF_gshared_inline (Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4* __this, uint8_t ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m146B47AAA47492A68DCB08165A6CBCD0A1E33AFF_gshared (Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0* __this, List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m6584A1C860271ACE4B035721F88B0ED8F5C1FE56_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m8A7370BF306BED894DB61B836F0F21E9C835925C_gshared (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, uint8_t ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mCEA3676018EDF23B82BC33A722F2E704326D72C3_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, uint8_t ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mAAF9759F6A50882987B1159F163F34505DCD5ECF_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m67007AD85DF53B4D7B867E20F7E6119867473640_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m414E45C4A570B0CF6B4EAB3C057756A91F6C16EB_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mBDC688B8984B71C25FF4A90AC54B59F47088C58A_gshared (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m92428DD612222174207D8E28F3A6D26B3E033F5D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m7B400433E1797FA18AB1874F99F69E1009435A03_gshared (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_mD18D2E61AE0EE6FF9F52E820F4F829BB062466CB_gshared (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50_fshared (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_list, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F (int32_t ___0_argument, int32_t ___1_resource, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC (int32_t ___0_argument, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m26993F578F05F8D920AF3C8F683CF9945DF89654 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41 (RuntimeArray* ___0_sourceArray, int32_t ___1_sourceIndex, RuntimeArray* ___2_destinationArray, int32_t ___3_destinationIndex, int32_t ___4_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 List_1_get_Item_mF5D504FB09F98DB07ABEF3D064237C0BCBD8EDC4 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mEC1C52B874AD5BD406704205ABB2229EC53C8587 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9CE045A3C18BAFF826CE4686A0F2D3D00930416F (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910 (RuntimeObject* ___0_value, Type_t* ___1_targetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m3E361A77D2986AAB36EB748E177978BF014B3E20 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mBA43C64613DB8DC278E2794C1899386CE9A8E9E5 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m65F0731FF2C839C25530522F74BE029D34851222_inline (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m970BE5CCB1F05BAF033736206A0C3142930127B0_inline (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mFF2B0BD7EF36E3CFCDC13D697EF56BA8B408AB24 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m2DC6024BDE63E97DDA876E4E7FEDA4F7E63C6B05 (ReadOnlyCollection_1_tC097ADAD4728DA15D13F639EC263BD398D57B04F* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tC097ADAD4728DA15D13F639EC263BD398D57B04F*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA (int32_t ___0_resource, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mCF69FB022FF37FC83FCCA53C1D648929F23D783C (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, int32_t ___1_index, int32_t ___2_length, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m6DB615C6555A7223C82FE5B3143C2CBCE6DB56A3 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mA0FC83E94A2B5036280B7D8E33D97B171C7A3C4A (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mEA00D4F19254CE6BDA86092ADB4FEC44F26BCABC (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m2B0853629C0AB51AFB8D5D4F1BE146816A1BC05A (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m314B8CB7B41FD2599F59BC44DF117BDD267F47A5 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317*, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m4349F707AFD29359D197EE27DD358DF37C12E2F8 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m04DC58E48FEAD029F01D3F3C89897D792153E65E (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline (Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m95C311035E2177D40ACD62E9D08BA9112E64502F (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m66BC05CFB9CEB99D7E604E23D99B80D00D5878AA (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m9293612C0DEA13BB9B5CADE956F799DE325BBD4B_inline (Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m719A771160FA0C4E0A4B3873553711844C534C5E (Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A* __this, List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m6DE881973FEDB21534398B48EC603235384D7543 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mE87C571495149031291F9689A1B42F9602497CC1 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mB7456174239E3B8D43A5010D5C2FCCAD202771DE (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mA6D665F94D3F7826F488DF40C349E9C597B2954D (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mFD67A83E6D563627CF3CE27A150D98204CD10E13 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m465E995BBA92B01A5E941A06EB6601F358514F29 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mCD238B8516B142585C6FD2359049E89B42B5D061 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA826BF7BB567765985BDF8FA09B5BE4E023EAEFE (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m9727818F9220BFB7086FB70AECF191C6359707D8 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m13C3861259F6EFC91390A9A35480FD1839085598 (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t481A1DF2F78166A7F0827FA0A9A8E26233D3973E* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m7DB9498F929F4CFDF5C0CF824A46680C398F06CD (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 List_1_get_Item_m9570D3859A5938946A3F72E8BE5836F938D73893 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m37CF179DA2A4DC544E181AB6152F610E55CF79E0 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mB3E57754B24B9C5E644B92B770B84D0F1D536028 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mC00103AF93A8667AEDB218D04F80F511F8194C9F (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mD09A0A4D5F4FC01ACDD6A7BC8975F4955A7E1CF6 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m8671BB7A955C16011966B029D9912C97256E551D_inline (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_mDD272882E7942B991C9A1EA5E0D2159CACC3E8A1_inline (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mD8B4739BC8DB91F6B5DFBAA474808F87DFAEB365 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m6D29517721D8F7433380C05B5140B4A1CE9B2084 (ReadOnlyCollection_1_tA87EA4F23BAC952A78BDE9A5B94F3091DB5C7861* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tA87EA4F23BAC952A78BDE9A5B94F3091DB5C7861*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m8E43D5DB47A684DE0EB2082A70E0371D355EC399 (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, int32_t ___1_index, int32_t ___2_length, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m8B1F2694EA45CC157FAE79AD1366C7C7C6567371 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mE0C5BD3D2B8D54D1F623027DD5F7278F438ABBEA (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m48FB0001AE7658BB8710D2834A5744F892AC7647 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mE62BDAE8E56D02D25F553CFFD73521AFE4D83279 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_mBA70B343697D13EFB11FA95A6336CC6936D6D7AC (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A*, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m896CE24A195E32A1363C4F47EC5A86A603400B18 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m1CAB513D06B1472A368559829C8E089AF07FF851 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline (Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m6E15F63947B41B703AC0A083850BC3DF9B4CE4DF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mE799B12F5A68426E6DD83B2C20848D06AF5E1F7C (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m74BA9791568FC6CEE9D33F5F6135FB35B40FF1FA_inline (Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m59A9B193503149669F9A1CDB976DE9A92E7C2BF4 (Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC* __this, List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m928B6B1FDFC0416B78DBDF07575A46F41CF80B13 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_mD66A99635C0749F6DCABDAF67917A44E48B647FF (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m7054F9A6D9ED69BFBF644B2498E93E5AA1BCD5DC (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m9923D8311DC83F4A2AE170B02A72A75F5974DE02 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mC12DEE4882625EB0E815AB856F0A4D86A85E52EF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m606AE91C5E089F1854C7D93CEB9A076DE041F6FB (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_mCAB85548741CC2290CD5711D7BDD1D605F3DDD06 (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m7045BFA1D7EA8DBA05CA0CD348D61D0EA85B8682 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m209AFB649D59EAEF75AD3C1696A43FDF81C7ADFE (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m791404477F2D37E776687167796922908A64BCA4 (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t6447E02D95C4C995AE37F197D13D355CC1E9AE10* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m2651B082BDD0B240BC0A569B1407DCFC2E64652E (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 List_1_get_Item_m2924E7746F6C53EDFEA3CCF16EF3B218E419DC3D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mA1DAD0FF706B1F126927FFDD38749A7A54FA292E (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m005D2CC35F5E7CBC3CA9B247C9A6F53C82079AB3 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m0CFF45D3EDB67B4F93F72B28293EACF735E2D915 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mEB188A6DEB187615EA3F109C3D6FA101549AAE49 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m8733206CE9C292CC7AE372250D705ECD9BC11353_inline (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m4F68AE5CD41D50629D6288599566638EA4DBCFBE_inline (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mF79B155E875CD01C203BD61F17DFEF51D3AE620D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m21AAD542DC641C1CC6201A83A58815D43F49726D (ReadOnlyCollection_1_tC4584ACB2E63F593E2DEF37DDA8EA9A18DD97F5D* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tC4584ACB2E63F593E2DEF37DDA8EA9A18DD97F5D*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m0995AD1F41D4F87F3A61CFE7C33B65A8459A95E2 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, int32_t ___1_index, int32_t ___2_length, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m66C94A2B368326DFDC153672733D937188CD7F2B (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m87D9B1778F33B1D47D8B10D757427E7EB94591BE (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m258CDE81FD7826B5BC9394598147752BC8856F41 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mF21748A6EAFA84C0E8D2CF169CEB7CAD353BDE33 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m46EEB7B6D977E644C0B5D333F81FEAC6C355472D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355*, WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m365573DAEE0CC09ED7C9EF91DA5F363256AA4F9F (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mD98A4B0A65890CA3D82C9D19CAA86DCD6A5ADC9B (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline (Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mCA968DFD73D48BDB875296E6A8814E215093022D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m195A090FF38080873B8C05C6DE14FFDECE48E591 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m77C7D2ACEEF9DF21BE26F4303BCFBEFEF8F7C764_inline (Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m44CA5DD6AF03BEEEA951E58A67514FFE9FC30048 (Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD* __this, List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m8F1145270D67E0B3CEBC6254CA273ACFCAEDC702 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mCAA516810A5A4E54E12136DD70E915064768AF24 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mEC7B7774A45AC794B51AD1DADB2E680D0F85791C (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m7797CB3726E2D8D8F08F35B4D0853DBF469FB501 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m5440E53F4F7D13F14EC26C51EE4865A298C0F217 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m3520CDF5BC09508EF2280BB34D85F62338B365E4 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m0B0C8AC7BD3093D4B3350A89EA537D4654583A0A (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA8B491BB3C19694F857CE4DF4901D1606950C26F (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m52E580379FC406094751B182A878AE05CAD72D19 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m4C5B394849E5E1EBD694444DCD64F30ACD6BD648 (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t035E1D57F8E92650AD1DCAAFF9632D0F026CA046* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m933BBC3774C46C94DE1BF5CA6AC39EC4E5D37D30 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D List_1_get_Item_m0B7EFA3EB9BD3A50B8BDEB2463B28E86EF6BA0F1 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA17F2B115A27352849BFF45AE179346E639C2B76 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m0726156C6DF11D5675F28EC4CACF2EC179D86E55 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m57CCC347F7A2D40306F42BE2E7822E13C0516E91 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m53C9A0D593A54DE616005FC0C75DF1DE1FC0EB25 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m1794A41080E7D990FC91C41044F40666784FAF5F_inline (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m0EB2669CA7A6261B73D759A35CF46BA8F2EAA9F0_inline (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m806B1F613ACD9C02EB149299D718A1B51DC8779D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_mAE442BCA7BE7654008D38947D61ACB626CCE4031 (ReadOnlyCollection_1_tB6FD6BA75C6F479B6860FCBA235488206BF20E52* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tB6FD6BA75C6F479B6860FCBA235488206BF20E52*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mC50E157F7E181EDEA92E51C9F2673CDAE84B5E51 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, int32_t ___1_index, int32_t ___2_length, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m2B49FAD4F587A9C4CA5CBE6AB74CF60105435E16 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mA598DCD7147BAA1775E07E60CC8F2BCBC052B9E6 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m8FA678F87A5F9E701EF1E74D1DC390973929CC9D (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mED6A7530571DED9EC65DE47BF2DC8B37D3BABE0D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m334B1330AE8565DC583C274533F172510BB5C839 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33*, X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5C29B9150B8CD4C2BA48966294BFDABF3A119C10 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA0A82440E4B1821AF295DCEFACEDE6414F672C9B (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline (Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mEF23AA633A6618208A8864BB4A59260DFF6E0AF4 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mE37DB2FA21A091A57F38BB3727C2D4F1586DC38F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m4298A6EF344901142C650584A3B102A0582873A6_inline (Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m0F297AA4D5E9DCCA5B022568286E587CFFA548B9 (Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588* __this, List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mBD3EEB3E27E27898E6E051D4D657BA527DF06D31 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA53DD5C386D2BC150E7AF665AD973861A0325966 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mA52D0749531BA9E39D056DEC246376A16DFA768D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m663ADE2FC3D8F054681C0FF19E9996185AB5BDD7 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAEDA4677C2ADEDBDA2DF0F8F9E9F0748C01E553F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m90285F94EF464888EDC820B62826C0482EAA1883 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_m12119C509581F764BD40D4271062FAA078B90764 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m32893B90CE4E1370C3F82B6EBE941635F7C62A96 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mE15993628BBDD272038B8BB6E5847DD6ECFED252 (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m54388C4AC33B08A6F59DA0D043DE35C6F7CE74CD (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t89BA6BA726C49026677C45BEDBD41952739E06A2* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m6C3A37912654122DD8AE143EFEB1C2A4C1015C29 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 List_1_get_Item_m4C81AE785745E7C9A726104CD2F588258FBE5E8F (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mADBF15F169E5DF2762161FB96F64C99569429300 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m6C903F3CAAD0D6DA54369D2224E52DFADB242F60 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m55AFD45DC0ADD64C8749E1B59252B0BF0793CE49 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB16BDFA4B73F390167601AF70BC65637BF9AE433 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m50157FAAF8FE0562A862140A17AD2B1097B078E7_inline (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m67096A69BCCCB33B2146561E2259883F084F5B95_inline (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m2555E93F7C903532A49529BCC327427FC3B1C6EE (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_mCAD4E9DC796CAE1655D1F09987BFC987E8FD72F1 (ReadOnlyCollection_1_t803A81BE343B15275BCD30A219ACAC97F0B9A1C8* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t803A81BE343B15275BCD30A219ACAC97F0B9A1C8*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_m469FFB0730A2E7136D62A2AE6D197A1858EC6CFE (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, int32_t ___1_index, int32_t ___2_length, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m603A1422A5D4C6AC20CFDB1897BD527164CFE059 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m54DA0380F7731F2146DEDD98FC646038D9FC3923 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m72B9D7AAB1A1E284232CC6C4CF613FEA6A227584 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mA297C73B52DACB79EAF9BABC705E6D7DB8EB7978 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m0E4DE3BC195FF67210FE47068EE58A77C5074C85 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB*, XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5593B7194363BCB1B716A4ECA594F6E2CC03F94C (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m14D5EB230C22B6C4A649235CC3E08C5F6561E15B (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline (Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m3A09BF3BCAAF3C61D9A2EEF2C3090311C21A62EB (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m94DC2E52655A61CACBDD8FFD47097AAE3E618198 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m14B5F0EFFF227D076151E00CACE917B6512254B8_inline (Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m5CBA8C17D9A8E5F5E385A4876B9B1745FA3CB8C0 (Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0* __this, List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m1742E82D5AF5200DFAC69B895C4A24E80D760C4D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mECE416DA9044547B55FF326280E3AFAB15850B37 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mBECAB59CCD69670908799776F1D6507EF7EA7D87 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m53875FA8AA50D0F755EE525314DB9818741B6E2F (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m15AEA673A2E9F2A482D49F374814A49D0734CEC6 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m3CE641659C3CD3760E5EE96E88FA7006B7D9995D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_m6953DC1CD28104B40EF7B6C79E12EDA04CCC52F3 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m52E4077FCE9FF6DF21E5DCE7A99DACB700AB2E0D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mACACE6CA017DAF3419A4C86E329FA9CFE4018C03 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m479DAA4C8994B2FBFA82BCC2220725F25C35DCD9 (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t55FCE173570442A2D451AE8BFC15B22D41D55DC9* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m9B49892AA65CC96277D2D79218DB14788068DA41 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 List_1_get_Item_mFFCB4E0F2978CE787223C6D1734D41306942EB30 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m8ADD7E3A387FB67C59B3A2FB00548D05874F417B (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m7A495455B6674DB278F9185B18C72E8BEF911BA7 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m940FD70455448D1B8E960B93BE1194188D09F786 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m479A86683CEE12F0C214CB5F3A05549381DC660E (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m26A98FFE1090E98CCB9AA0278EC4017152C89F85_inline (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m38785A4676BA4266C779A1DCB1DA31522E554864_inline (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m992A9116BAD4C2EC04F0F9C88B89A1B52C17EB80 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m0F14248B4CC1878CDFEC416C9213E81135B04750 (ReadOnlyCollection_1_t95C4CE7A3281F650247DAD055168AC75CA2E0D94* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t95C4CE7A3281F650247DAD055168AC75CA2E0D94*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_BinarySearch_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m5D4301D56E29378AE3D729C7AB2EACA0F911398F (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, int32_t ___1_index, int32_t ___2_length, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m0280BDACD6B1BE7BD4B43BF0E243AAA3240204CF (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mFDE66951AEA8FFF75C995BEF3AA99D47C3AA8B21 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m70B0273AB943F33BC49BE752D55720E5A6B45863 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4EEC6DE78174B1A7C89D5DA9D0B9923881561328 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_mDB8EBD9ED943554A5C6FAD9384AB4B42567E5C7B (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7*, XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mD7F92B17978CCAD780D5027AB9ED84DC79B44DFD (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mB4E76D35717A9DB62561714DAF4292E2B4404D58 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___0_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline (Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m182300006C2F508433064C65566BFE6D4210BF3D (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m2932FC34CFE0B8373CC0E031216528C99A0F008B (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m1E148200B150317478F1EAF858AE3F230EB8D4AA_inline (Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m9649445EB055BFD3F58AC786F4A50C5843ACBEE5 (Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1* __this, List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mF13A6D0FE4169F106512A28BA7B29E68E7D4E1FA (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_mF9B09B9F1A4B269FF6D212596871AA5569E5D8B2 (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m4C4C068BB28606E5DE98FB7616757884C4CCD698 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m0A038738F0C2834BE11C14491130246276431B20 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mBA2ED23FD37868DBBC644AD7E3A9935F0DE57CB3 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m39920E0E4B4089FD8E4C0A5CA145911B31FA1D15 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m9E4B79FAA123091EDADB1E0EDBD296F9AECCBCD9 (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m81FCD89C0A108E16223AF643893B87B1BF43002D (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m4595EBB46D67A07754F8987A2B382C13811C8D88 (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m5935F327EBF640B1FEB63092149D6B0D5ADD8C4D (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tCC0DD2EF5FD4D03E423A3C172F5D948A944669DA* ___3_comparer, const RuntimeMethod* method) ;
inline void List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, RuntimeObject*, const RuntimeMethod*))List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79_gshared)(__this, ___0_enumerable, method);
}
inline Il2CppSharedGenericObject* List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515_gshared)(__this, ___0_index, method);
}
inline void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054_gshared)(___0_value, ___1_argName, method);
}
inline void List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF_gshared)(__this, ___0_index, ___1_value, method);
}
inline void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared)(__this, ___0_item, method);
}
inline void List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_min, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5_gshared)(__this, ___0_min, method);
}
inline void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline)(__this, ___0_item, method);
}
inline int32_t List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
inline void List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804_gshared)(__this, ___0_index, ___1_collection, method);
}
inline void ReadOnlyCollection_1__ctor_mC1890FAC00703F47A655C35CBCB613C74A811580 (ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
inline int32_t Array_BinarySearch_TisIl2CppSharedGenericObject_m6D8A1F3C8EDCAAF226FE8B32CBB649F099D8C16B (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, Il2CppSharedGenericObject* ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method)
{
	return ((  int32_t (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, int32_t, Il2CppSharedGenericObject*, RuntimeObject*, const RuntimeMethod*))Array_BinarySearch_TisIl2CppSharedGenericObject_m6D8A1F3C8EDCAAF226FE8B32CBB649F099D8C16B_gshared)(___0_array, ___1_index, ___2_length, ___3_value, ___4_comparer, method);
}
inline int32_t List_1_BinarySearch_mB2BE3DF9182ED9C862AA44566C878D046534474E (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, Il2CppSharedGenericObject* ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, Il2CppSharedGenericObject*, RuntimeObject*, const RuntimeMethod*))List_1_BinarySearch_mB2BE3DF9182ED9C862AA44566C878D046534474E_gshared)(__this, ___0_index, ___1_count, ___2_item, ___3_comparer, method);
}
inline int32_t List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9_gshared)(__this, ___0_item, method);
}
inline bool List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26_gshared)(___0_value, method);
}
inline bool List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE_gshared)(__this, ___0_item, method);
}
inline void List_1_CopyTo_m75919E1737F4EC8D7DD329629C11CACA64EF5BE3 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
inline void List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6_gshared)(__this, ___0_value, method);
}
inline int32_t List_1_FindIndex_mD56F0607D7DAD9622F7DE2C6C8957D9C7847EEC5 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88*, const RuntimeMethod*))List_1_FindIndex_mD56F0607D7DAD9622F7DE2C6C8957D9C7847EEC5_gshared)(__this, ___0_match, method);
}
inline bool Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method)
{
	return ((  bool (*) (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88*, Il2CppSharedGenericObject*, const RuntimeMethod*))Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_gshared_inline)(__this, ___0_obj, method);
}
inline int32_t List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88*, const RuntimeMethod*))List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D_gshared)(__this, ___0_startIndex, ___1_count, ___2_match, method);
}
inline int32_t List_1_FindLastIndex_m75AB13CBCA95A0E0722F6CDE89F0CBDAB27322DA (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88*, const RuntimeMethod*))List_1_FindLastIndex_m75AB13CBCA95A0E0722F6CDE89F0CBDAB27322DA_gshared)(__this, ___0_startIndex, ___1_count, ___2_match, method);
}
inline void Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_inline (Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method)
{
	((  void (*) (Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505*, Il2CppSharedGenericObject*, const RuntimeMethod*))Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_gshared_inline)(__this, ___0_obj, method);
}
inline void Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9 (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, const RuntimeMethod*))Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9_gshared)(__this, ___0_list, method);
}
inline void List_1__ctor_m54D719307910A9DC9CD4DEFA8AE2626F49EB7516 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1__ctor_m54D719307910A9DC9CD4DEFA8AE2626F49EB7516_gshared)(__this, ___0_capacity, method);
}
inline int32_t Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, Il2CppSharedGenericObject* ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Il2CppSharedGenericObject*, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline void List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E_gshared)(__this, ___0_index, ___1_item, method);
}
inline void List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C_gshared)(__this, ___0_index, method);
}
inline bool List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796_gshared)(__this, ___0_item, method);
}
inline void List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, const RuntimeMethod*))List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99_gshared)(__this, ___0_index, ___1_count, method);
}
inline void Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method)
{
	((  void (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, int32_t, const RuntimeMethod*))Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541_gshared)(___0_array, ___1_index, ___2_length, method);
}
inline void List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A_gshared)(__this, ___0_index, ___1_count, ___2_comparer, method);
}
inline void Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61_gshared)(___0_array, ___1_index, ___2_length, ___3_comparer, method);
}
inline void ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, int32_t, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5*, const RuntimeMethod*))ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970_gshared)(___0_keys, ___1_index, ___2_length, ___3_comparer, method);
}
inline void List_1_AddEnumerable_m426F79399C24D92B89DBA07ABF04AD125278169D (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, RuntimeObject*, const RuntimeMethod*))List_1_AddEnumerable_m426F79399C24D92B89DBA07ABF04AD125278169D_gshared)(__this, ___0_enumerable, method);
}
inline uint8_t List_1_get_Item_mAA1579D28843BE101AF5735731E5F6C74CADBC25 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  uint8_t (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, const RuntimeMethod*))List_1_get_Item_mAA1579D28843BE101AF5735731E5F6C74CADBC25_gshared)(__this, ___0_index, method);
}
inline void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m1BCCAEF15531A89027A8C21D496867A6744E119A (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m1BCCAEF15531A89027A8C21D496867A6744E119A_gshared)(___0_value, ___1_argName, method);
}
inline void List_1_set_Item_m8178833364A7D14F2AC3ACE6FC8DE95D5FF9B7BB (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, uint8_t ___1_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, uint8_t, const RuntimeMethod*))List_1_set_Item_m8178833364A7D14F2AC3ACE6FC8DE95D5FF9B7BB_gshared)(__this, ___0_index, ___1_value, method);
}
inline void List_1_AddWithResize_m76095CD55E33211D69331C6DBF9A12AE1E1F544C (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, uint8_t, const RuntimeMethod*))List_1_AddWithResize_m76095CD55E33211D69331C6DBF9A12AE1E1F544C_gshared)(__this, ___0_item, method);
}
inline void List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_min, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, const RuntimeMethod*))List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D_gshared)(__this, ___0_min, method);
}
inline void List_1_Add_m4950BFDE5379FB1EE9E82C2AA9E4631881DED88D_inline (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, uint8_t, const RuntimeMethod*))List_1_Add_m4950BFDE5379FB1EE9E82C2AA9E4631881DED88D_gshared_inline)(__this, ___0_item, method);
}
inline int32_t List_1_get_Count_mE2A014D40D80B0243F6B9B41149E7D086E96900D_inline (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
inline void List_1_InsertRange_m169B03E44FA6B59F43486EEEA8E98C44F7B5751E (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_InsertRange_m169B03E44FA6B59F43486EEEA8E98C44F7B5751E_gshared)(__this, ___0_index, ___1_collection, method);
}
inline void ReadOnlyCollection_1__ctor_m691F18FF07E708D77863DB26C8FD7C99240CBBDE (ReadOnlyCollection_1_tD86E076A19D3DF6CFD1AC3FEE937BD0FB0B39AF7* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tD86E076A19D3DF6CFD1AC3FEE937BD0FB0B39AF7*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
inline int32_t Array_BinarySearch_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mCC8652BE0AE4082A8DEA7D0B05CF46DE9C38F9D1 (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, int32_t ___1_index, int32_t ___2_length, uint8_t ___3_value, RuntimeObject* ___4_comparer, const RuntimeMethod* method)
{
	return ((  int32_t (*) (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, int32_t, int32_t, uint8_t, RuntimeObject*, const RuntimeMethod*))Array_BinarySearch_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mCC8652BE0AE4082A8DEA7D0B05CF46DE9C38F9D1_gshared)(___0_array, ___1_index, ___2_length, ___3_value, ___4_comparer, method);
}
inline int32_t List_1_BinarySearch_mE7F3B1638176AF8F4CC0E83A5D06258B839D9F6F (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, uint8_t ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, int32_t, uint8_t, RuntimeObject*, const RuntimeMethod*))List_1_BinarySearch_mE7F3B1638176AF8F4CC0E83A5D06258B839D9F6F_gshared)(__this, ___0_index, ___1_count, ___2_item, ___3_comparer, method);
}
inline int32_t List_1_IndexOf_m0AFABF6F1B3F0240ED564A30B2610DABA9881872 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, uint8_t, const RuntimeMethod*))List_1_IndexOf_m0AFABF6F1B3F0240ED564A30B2610DABA9881872_gshared)(__this, ___0_item, method);
}
inline bool List_1_IsCompatibleObject_mF6062BD01FB16E2976FE77274D3B42294B156F8D (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))List_1_IsCompatibleObject_mF6062BD01FB16E2976FE77274D3B42294B156F8D_gshared)(___0_value, method);
}
inline bool List_1_Contains_mF83AE21E82590B5270938D4389B13BD6007F3C21 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, uint8_t, const RuntimeMethod*))List_1_Contains_mF83AE21E82590B5270938D4389B13BD6007F3C21_gshared)(__this, ___0_item, method);
}
inline void List_1_CopyTo_mC3638F2FCF0162384166CDAD58E83F978A4781BD (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
inline void List_1_set_Capacity_mA829BA58B34F17EE008D7D66468B478647866621 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mA829BA58B34F17EE008D7D66468B478647866621_gshared)(__this, ___0_value, method);
}
inline int32_t List_1_FindIndex_m90942CB72E241DC275A09D90F31B0CAAA2301F15 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___0_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626*, const RuntimeMethod*))List_1_FindIndex_m90942CB72E241DC275A09D90F31B0CAAA2301F15_gshared)(__this, ___0_match, method);
}
inline bool Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_inline (Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* __this, uint8_t ___0_obj, const RuntimeMethod* method)
{
	return ((  bool (*) (Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626*, uint8_t, const RuntimeMethod*))Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_gshared_inline)(__this, ___0_obj, method);
}
inline int32_t List_1_FindIndex_m98B9B243A5F21F0F6F288BC5D562F9D215769C08 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___2_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, int32_t, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626*, const RuntimeMethod*))List_1_FindIndex_m98B9B243A5F21F0F6F288BC5D562F9D215769C08_gshared)(__this, ___0_startIndex, ___1_count, ___2_match, method);
}
inline int32_t List_1_FindLastIndex_m2943A682B3924333EEBA9CAA0CDC4FA2FCA17ADC (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___2_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, int32_t, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626*, const RuntimeMethod*))List_1_FindLastIndex_m2943A682B3924333EEBA9CAA0CDC4FA2FCA17ADC_gshared)(__this, ___0_startIndex, ___1_count, ___2_match, method);
}
inline void Action_1_Invoke_m3F52CF20C1CBEFC2E57A2FBAD08312B7C5EA6ECF_inline (Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4* __this, uint8_t ___0_obj, const RuntimeMethod* method)
{
	((  void (*) (Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4*, uint8_t, const RuntimeMethod*))Action_1_Invoke_m3F52CF20C1CBEFC2E57A2FBAD08312B7C5EA6ECF_gshared_inline)(__this, ___0_obj, method);
}
inline void Enumerator__ctor_m146B47AAA47492A68DCB08165A6CBCD0A1E33AFF (Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0* __this, List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0*, List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, const RuntimeMethod*))Enumerator__ctor_m146B47AAA47492A68DCB08165A6CBCD0A1E33AFF_gshared)(__this, ___0_list, method);
}
inline void List_1__ctor_m6584A1C860271ACE4B035721F88B0ED8F5C1FE56 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, const RuntimeMethod*))List_1__ctor_m6584A1C860271ACE4B035721F88B0ED8F5C1FE56_gshared)(__this, ___0_capacity, method);
}
inline int32_t Array_IndexOf_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m8A7370BF306BED894DB61B836F0F21E9C835925C (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, uint8_t ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, uint8_t, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m8A7370BF306BED894DB61B836F0F21E9C835925C_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline void List_1_Insert_mCEA3676018EDF23B82BC33A722F2E704326D72C3 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, uint8_t ___1_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, uint8_t, const RuntimeMethod*))List_1_Insert_mCEA3676018EDF23B82BC33A722F2E704326D72C3_gshared)(__this, ___0_index, ___1_item, method);
}
inline void List_1_RemoveAt_mAAF9759F6A50882987B1159F163F34505DCD5ECF (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, const RuntimeMethod*))List_1_RemoveAt_mAAF9759F6A50882987B1159F163F34505DCD5ECF_gshared)(__this, ___0_index, method);
}
inline bool List_1_Remove_m67007AD85DF53B4D7B867E20F7E6119867473640 (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, uint8_t, const RuntimeMethod*))List_1_Remove_m67007AD85DF53B4D7B867E20F7E6119867473640_gshared)(__this, ___0_item, method);
}
inline void List_1_Reverse_m414E45C4A570B0CF6B4EAB3C057756A91F6C16EB (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, int32_t, const RuntimeMethod*))List_1_Reverse_m414E45C4A570B0CF6B4EAB3C057756A91F6C16EB_gshared)(__this, ___0_index, ___1_count, method);
}
inline void Array_Reverse_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mBDC688B8984B71C25FF4A90AC54B59F47088C58A (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method)
{
	((  void (*) (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, int32_t, int32_t, const RuntimeMethod*))Array_Reverse_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mBDC688B8984B71C25FF4A90AC54B59F47088C58A_gshared)(___0_array, ___1_index, ___2_length, method);
}
inline void List_1_Sort_m92428DD612222174207D8E28F3A6D26B3E033F5D (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method)
{
	((  void (*) (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_Sort_m92428DD612222174207D8E28F3A6D26B3E033F5D_gshared)(__this, ___0_index, ___1_count, ___2_comparer, method);
}
inline void Array_Sort_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m7B400433E1797FA18AB1874F99F69E1009435A03 (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))Array_Sort_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m7B400433E1797FA18AB1874F99F69E1009435A03_gshared)(___0_array, ___1_index, ___2_length, ___3_comparer, method);
}
inline void ArraySortHelper_1_Sort_mD18D2E61AE0EE6FF9F52E820F4F829BB062466CB (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, int32_t, int32_t, Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E*, const RuntimeMethod*))ArraySortHelper_1_Sort_mD18D2E61AE0EE6FF9F52E820F4F829BB062466CB_gshared)(___0_keys, ___1_index, ___2_length, ___3_comparer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58 (const RuntimeMethod* method) ;
inline void Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50 (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50_fshared)(__this, ___0_list, method);
}
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7A5FFB71CC0B9A11A8FF0FC535B7D700EF76ED20 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = ((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m6DE881973FEDB21534398B48EC603235384D7543 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_2 = ((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_4 = (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)(Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mD9791AC84BFDD1E95ED483EF04752D321D7B3D5C (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_6 = ((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_8 = (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)(Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_12 = ((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m26993F578F05F8D920AF3C8F683CF9945DF89654(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m4349F707AFD29359D197EE27DD358DF37C12E2F8 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)(Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_9 = __this->____items;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_13 = ((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 List_1_get_Item_mF5D504FB09F98DB07ABEF3D064237C0BCBD8EDC4 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9CE045A3C18BAFF826CE4686A0F2D3D00930416F (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mEA00D4F19254CE6BDA86092ADB4FEC44F26BCABC (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((&V_0), sizeof(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3));
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_2 = V_0;
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m93E30EF6A6F91CEDE2588B0E39C9A0402C86A9CC (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_1;
		L_1 = List_1_get_Item_mF5D504FB09F98DB07ABEF3D064237C0BCBD8EDC4(__this, L_0, NULL);
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m810868BCAD92EAF83AECE3996664ED969F1DC930 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mEC1C52B874AD5BD406704205ABB2229EC53C8587(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m9CE045A3C18BAFF826CE4686A0F2D3D00930416F(__this, L_1, ((*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m65F0731FF2C839C25530522F74BE029D34851222 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = V_0;
		int32_t L_8 = V_1;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_9);
		return;
	}

IL_0034:
	{
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_10 = ___0_item;
		List_1_AddWithResize_m3E361A77D2986AAB36EB748E177978BF014B3E20(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m3E361A77D2986AAB36EB748E177978BF014B3E20 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mBA43C64613DB8DC278E2794C1899386CE9A8E9E5(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mF8B95EF55DD2BF8722BB1D5D01B9C0D402A72A56 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mEC1C52B874AD5BD406704205ABB2229EC53C8587(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m65F0731FF2C839C25530522F74BE029D34851222_inline(__this, ((*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m970BE5CCB1F05BAF033736206A0C3142930127B0_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m26E962CD4DEE4E16A1EAF5A2FEA95DFD7C32AB75 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_mFF2B0BD7EF36E3CFCDC13D697EF56BA8B408AB24(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tC097ADAD4728DA15D13F639EC263BD398D57B04F* List_1_AsReadOnly_m702A668245ECE15EC5421EE441B844A9918B4C97 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_tC097ADAD4728DA15D13F639EC263BD398D57B04F* L_0 = (ReadOnlyCollection_1_tC097ADAD4728DA15D13F639EC263BD398D57B04F*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m2DC6024BDE63E97DDA876E4E7FEDA4F7E63C6B05(L_0, __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m6DB615C6555A7223C82FE5B3143C2CBCE6DB56A3 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mCF69FB022FF37FC83FCCA53C1D648929F23D783C(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mCB56B8C2694706D6A91E00EF5E6E407AB9626434 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m970BE5CCB1F05BAF033736206A0C3142930127B0_inline(__this, NULL);
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_m6DB615C6555A7223C82FE5B3143C2CBCE6DB56A3(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mE972FDAAC284BE7847451A4EE7E6ADD23F8D9DF8 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m970BE5CCB1F05BAF033736206A0C3142930127B0_inline(__this, NULL);
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_m6DB615C6555A7223C82FE5B3143C2CBCE6DB56A3(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m6C27D2DB91485CF3C5992CD0234BA828E8C53275 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m2B0853629C0AB51AFB8D5D4F1BE146816A1BC05A (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mA0FC83E94A2B5036280B7D8E33D97B171C7A3C4A(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m25F8CFEB8E2479AB108EDC84728416DE9798B18A (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mEA00D4F19254CE6BDA86092ADB4FEC44F26BCABC(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m2B0853629C0AB51AFB8D5D4F1BE146816A1BC05A(__this, ((*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m2C7B297F95832BB6750455FDE3FC7AAAD89EF920 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = ___0_array;
		List_1_CopyTo_m314B8CB7B41FD2599F59BC44DF117BDD267F47A5(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mBA43C64613DB8DC278E2794C1899386CE9A8E9E5 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m4349F707AFD29359D197EE27DD358DF37C12E2F8(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_m91E605A52B7EF7A9F18A32DF80CB2E9A1CC1EAD7 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_m04DC58E48FEAD029F01D3F3C89897D792153E65E(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 List_1_Find_mDB13DDB1B5AA2CF88F6BC7ADBDAD0808E046FC10 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_1 = ___0_match;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3));
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m04DC58E48FEAD029F01D3F3C89897D792153E65E (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m95C311035E2177D40ACD62E9D08BA9112E64502F(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m36F8EE82E5CA850F378A7736BB90634F37C0E8F9 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_startIndex, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_m95C311035E2177D40ACD62E9D08BA9112E64502F(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m95C311035E2177D40ACD62E9D08BA9112E64502F (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_10 = ___2_match;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m8E63161B5DB3AF6F8FFC637E9BDE3A2DDEC17C16 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_m66BC05CFB9CEB99D7E604E23D99B80D00D5878AA(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m66BC05CFB9CEB99D7E604E23D99B80D00D5878AA (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_11 = ___2_match;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_mA8357B3861CCC61670D57824928188720E863C4B (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF* L_4 = ___0_action;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_m9293612C0DEA13BB9B5CADE956F799DE325BBD4B_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A List_1_GetEnumerator_m44A7CA6B3C20DCF5DDF5405F9C3D9A56EF6802EA (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m719A771160FA0C4E0A4B3873553711844C534C5E((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mB703607F773938B6BA10E903FEE168483506E938 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m719A771160FA0C4E0A4B3873553711844C534C5E((&L_0), __this, NULL);
		Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m8BB0C45F83708B6516D9FBF7EB813179768F18BD (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m719A771160FA0C4E0A4B3873553711844C534C5E((&L_0), __this, NULL);
		Enumerator_tE713E07F5A4EA08805E6D4160E39F98057E43F9A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* List_1_GetRange_m7F1BA56A2E3202A019887928A6570C5544978557 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* L_6 = (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_m6DE881973FEDB21534398B48EC603235384D7543(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* L_9 = V_0;
		NullCheck(L_9);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mA0FC83E94A2B5036280B7D8E33D97B171C7A3C4A (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = __this->____items;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mE87C571495149031291F9689A1B42F9602497CC1(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m52B70CBAF1B411F3B1FEB9EE45B22983BD41EE23 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mEA00D4F19254CE6BDA86092ADB4FEC44F26BCABC(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mA0FC83E94A2B5036280B7D8E33D97B171C7A3C4A(__this, ((*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mB7456174239E3B8D43A5010D5C2FCCAD202771DE (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mBA43C64613DB8DC278E2794C1899386CE9A8E9E5(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m1F52F7F192D0B2E0D695C6C5EDBC0C7AF0F82DDD (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mEC1C52B874AD5BD406704205ABB2229EC53C8587(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mB7456174239E3B8D43A5010D5C2FCCAD202771DE(__this, L_1, ((*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mFF2B0BD7EF36E3CFCDC13D697EF56BA8B408AB24 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mBA43C64613DB8DC278E2794C1899386CE9A8E9E5(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_20 = __this->____items;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck(L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_45;
				L_45 = InterfaceFuncInvoker0< Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_mB7456174239E3B8D43A5010D5C2FCCAD202771DE(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck(L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m26993F578F05F8D920AF3C8F683CF9945DF89654(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mFD67A83E6D563627CF3CE27A150D98204CD10E13 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mA0FC83E94A2B5036280B7D8E33D97B171C7A3C4A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_mA6D665F94D3F7826F488DF40C349E9C597B2954D(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_mE8A74EBBCAF076DB24821E4BBD1CCB6530B2E8B2 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mEA00D4F19254CE6BDA86092ADB4FEC44F26BCABC(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mFD67A83E6D563627CF3CE27A150D98204CD10E13(__this, ((*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m33A680A478F764351E96EFCFFB49D2ABCD870E58 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_4 = ___0_match;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* L_16 = ___0_match;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		goto IL_00ad;
	}

IL_00ad:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_0;
		int32_t L_36 = V_0;
		__this->____size = L_36;
		int32_t L_37 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_37, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mA6D665F94D3F7826F488DF40C349E9C597B2954D (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		goto IL_0063;
	}

IL_0063:
	{
		int32_t L_11 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_11, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m128D19D86F081739D899891EF22D020A939CAB83 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		goto IL_008d;
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m4A865143CEC4C0736CC843235893AE03E82B0004 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m970BE5CCB1F05BAF033736206A0C3142930127B0_inline(__this, NULL);
		List_1_Reverse_m465E995BBA92B01A5E941A06EB6601F358514F29(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m465E995BBA92B01A5E941A06EB6601F358514F29 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mCD238B8516B142585C6FD2359049E89B42B5D061(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m1F6F240E13F132DCE980A30B6B26373276DD9C03 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m970BE5CCB1F05BAF033736206A0C3142930127B0_inline(__this, NULL);
		List_1_Sort_mA826BF7BB567765985BDF8FA09B5BE4E023EAEFE(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m040B49D624BB3A9951D324543CC6DCD7C4E4B207 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m970BE5CCB1F05BAF033736206A0C3142930127B0_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_mA826BF7BB567765985BDF8FA09B5BE4E023EAEFE(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA826BF7BB567765985BDF8FA09B5BE4E023EAEFE (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m9727818F9220BFB7086FB70AECF191C6359707D8(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mE154D5FE149C695A30964DE1F3B1659D4F4F47C1 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Comparison_1_t481A1DF2F78166A7F0827FA0A9A8E26233D3973E* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_t481A1DF2F78166A7F0827FA0A9A8E26233D3973E* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t481A1DF2F78166A7F0827FA0A9A8E26233D3973E* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m13C3861259F6EFC91390A9A35480FD1839085598(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* List_1_ToArray_m65092E284FCFF79BD500F713ED24D6530A9B3CC5 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_1 = ((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_3 = (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)(Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_4 = __this->____items;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_mDDDD59DBA090EE2280949D0BFDFCD1B17543DDD3 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_m4349F707AFD29359D197EE27DD358DF37C12E2F8(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m26993F578F05F8D920AF3C8F683CF9945DF89654 (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_6;
				L_6 = InterfaceFuncInvoker0< Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mBA43C64613DB8DC278E2794C1899386CE9A8E9E5(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck(L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mE2E4D4A95A34CB288396B4EB18DF1DDC7F1C9920 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_0 = (Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)(Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m9D221BAADD9EB33ADECFA2923E1A443628244BD2 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m928B6B1FDFC0416B78DBDF07575A46F41CF80B13 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_2 = ((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mDC800C93352274C2D4197FEC1B0A504259B4E7C3 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_6 = ((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_8 = (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_12 = ((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m7DB9498F929F4CFDF5C0CF824A46680C398F06CD(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m896CE24A195E32A1363C4F47EC5A86A603400B18 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_7 = (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_9 = __this->____items;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_13 = ((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 List_1_get_Item_m9570D3859A5938946A3F72E8BE5836F938D73893 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mB3E57754B24B9C5E644B92B770B84D0F1D536028 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m48FB0001AE7658BB8710D2834A5744F892AC7647 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((&V_0), sizeof(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76));
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_2 = V_0;
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m720E6F2DA5D5DF367CF73FB45AEAA94B62CD92D5 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_1;
		L_1 = List_1_get_Item_m9570D3859A5938946A3F72E8BE5836F938D73893(__this, L_0, NULL);
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m551DE1659F004F28E4B82BDEC68FFF922BE239E8 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m37CF179DA2A4DC544E181AB6152F610E55CF79E0(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_mB3E57754B24B9C5E644B92B770B84D0F1D536028(__this, L_1, ((*(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m8671BB7A955C16011966B029D9912C97256E551D (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_7 = V_0;
		int32_t L_8 = V_1;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_9);
		return;
	}

IL_0034:
	{
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_10 = ___0_item;
		List_1_AddWithResize_mC00103AF93A8667AEDB218D04F80F511F8194C9F(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mC00103AF93A8667AEDB218D04F80F511F8194C9F (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mD09A0A4D5F4FC01ACDD6A7BC8975F4955A7E1CF6(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_3 = __this->____items;
		int32_t L_4 = V_0;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m7CA4522EED1A457D4300433920955C9748ED9192 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m37CF179DA2A4DC544E181AB6152F610E55CF79E0(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m8671BB7A955C16011966B029D9912C97256E551D_inline(__this, ((*(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_mDD272882E7942B991C9A1EA5E0D2159CACC3E8A1_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m27AB1BC3FDDC51EC5767563F5A6B935FB2058EE6 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_mD8B4739BC8DB91F6B5DFBAA474808F87DFAEB365(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tA87EA4F23BAC952A78BDE9A5B94F3091DB5C7861* List_1_AsReadOnly_m62897FC4696F7357EED598F9CE9BEC8471E1B12F (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_tA87EA4F23BAC952A78BDE9A5B94F3091DB5C7861* L_0 = (ReadOnlyCollection_1_tA87EA4F23BAC952A78BDE9A5B94F3091DB5C7861*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m6D29517721D8F7433380C05B5140B4A1CE9B2084(L_0, __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m8B1F2694EA45CC157FAE79AD1366C7C7C6567371 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m8E43D5DB47A684DE0EB2082A70E0371D355EC399(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m9FF34AF8E04F6691B8963AFF35B18AB34A83082D (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mDD272882E7942B991C9A1EA5E0D2159CACC3E8A1_inline(__this, NULL);
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_m8B1F2694EA45CC157FAE79AD1366C7C7C6567371(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m6605C924A94AEF8F3A9A0375A4F9D5F250C9DAA2 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mDD272882E7942B991C9A1EA5E0D2159CACC3E8A1_inline(__this, NULL);
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_m8B1F2694EA45CC157FAE79AD1366C7C7C6567371(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m166E08577EB1EE78EB8AF27E72BC551DE3597DD2 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mE62BDAE8E56D02D25F553CFFD73521AFE4D83279 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mE0C5BD3D2B8D54D1F623027DD5F7278F438ABBEA(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m378205FBB5FB8A4683E7284530962AACC3BA4FD1 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m48FB0001AE7658BB8710D2834A5744F892AC7647(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mE62BDAE8E56D02D25F553CFFD73521AFE4D83279(__this, ((*(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m75EC226DFC4B608B77C1888B7A565975172B4193 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ___0_array;
		List_1_CopyTo_mBA70B343697D13EFB11FA95A6336CC6936D6D7AC(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mD09A0A4D5F4FC01ACDD6A7BC8975F4955A7E1CF6 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m896CE24A195E32A1363C4F47EC5A86A603400B18(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_m4D3E5D6DC80B673C1F9FE7E9CEFAB010D3587D1D (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_m1CAB513D06B1472A368559829C8E089AF07FF851(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 List_1_Find_m722F7A6765E7BCBB80B6E5DB43AF298C0BD5E6B9 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_1 = ___0_match;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76));
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m1CAB513D06B1472A368559829C8E089AF07FF851 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m6E15F63947B41B703AC0A083850BC3DF9B4CE4DF(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mFBBE53B77423DBCE95D348395534D942729D0C08 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_startIndex, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_m6E15F63947B41B703AC0A083850BC3DF9B4CE4DF(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m6E15F63947B41B703AC0A083850BC3DF9B4CE4DF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_10 = ___2_match;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mA179B31FC4F7AF9469EF39CCB9876C7D8C048B01 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_mE799B12F5A68426E6DD83B2C20848D06AF5E1F7C(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mE799B12F5A68426E6DD83B2C20848D06AF5E1F7C (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_11 = ___2_match;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_m28D556DDFCFA46EEF1CA751993D051D853F200CF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C* L_4 = ___0_action;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_m74BA9791568FC6CEE9D33F5F6135FB35B40FF1FA_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC List_1_GetEnumerator_m8C2B68F3EA63A79557BD752343BB817C31728181 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m59A9B193503149669F9A1CDB976DE9A92E7C2BF4((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m038E4BFB8729CF991650ED790B1C1444F8BF1D5F (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m59A9B193503149669F9A1CDB976DE9A92E7C2BF4((&L_0), __this, NULL);
		Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_mEB692D025EA4178F8966F7DEF566AA47EDA76F55 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m59A9B193503149669F9A1CDB976DE9A92E7C2BF4((&L_0), __this, NULL);
		Enumerator_t63330B4094998948CC09317F806BD56E90FFF8EC L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* List_1_GetRange_m1B29B235350E995B595C5A06BD9E4438C346DD4C (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* L_6 = (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_m928B6B1FDFC0416B78DBDF07575A46F41CF80B13(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* L_9 = V_0;
		NullCheck(L_9);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mE0C5BD3D2B8D54D1F623027DD5F7278F438ABBEA (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = __this->____items;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_mD66A99635C0749F6DCABDAF67917A44E48B647FF(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m39B5AD68EF69B2DFF8E6F92BDDB6B3EDDFD1D2DD (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m48FB0001AE7658BB8710D2834A5744F892AC7647(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mE0C5BD3D2B8D54D1F623027DD5F7278F438ABBEA(__this, ((*(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m7054F9A6D9ED69BFBF644B2498E93E5AA1BCD5DC (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mD09A0A4D5F4FC01ACDD6A7BC8975F4955A7E1CF6(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m5D473EFFD2A147A0B61DA3E4ACEE836FCC08E883 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m37CF179DA2A4DC544E181AB6152F610E55CF79E0(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_m7054F9A6D9ED69BFBF644B2498E93E5AA1BCD5DC(__this, L_1, ((*(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mD8B4739BC8DB91F6B5DFBAA474808F87DFAEB365 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mD09A0A4D5F4FC01ACDD6A7BC8975F4955A7E1CF6(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_20 = __this->____items;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck(L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_45;
				L_45 = InterfaceFuncInvoker0< VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_m7054F9A6D9ED69BFBF644B2498E93E5AA1BCD5DC(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck(L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m7DB9498F929F4CFDF5C0CF824A46680C398F06CD(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mC12DEE4882625EB0E815AB856F0A4D86A85E52EF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mE0C5BD3D2B8D54D1F623027DD5F7278F438ABBEA(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m9923D8311DC83F4A2AE170B02A72A75F5974DE02(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m26600AD8D142FF609B1C7D73934857140A067AB9 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m48FB0001AE7658BB8710D2834A5744F892AC7647(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mC12DEE4882625EB0E815AB856F0A4D86A85E52EF(__this, ((*(VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m836D0D5E590ADD32A7530BB903FA27C279117F7F (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_4 = ___0_match;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* L_16 = ___0_match;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		goto IL_00ad;
	}

IL_00ad:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_0;
		int32_t L_36 = V_0;
		__this->____size = L_36;
		int32_t L_37 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_37, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m9923D8311DC83F4A2AE170B02A72A75F5974DE02 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		goto IL_0063;
	}

IL_0063:
	{
		int32_t L_11 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_11, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mDE8DA7A49D426456B155E8C540D027C4F48831FB (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		goto IL_008d;
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m96409655F06101024808EFB92CC5FE34298F157B (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mDD272882E7942B991C9A1EA5E0D2159CACC3E8A1_inline(__this, NULL);
		List_1_Reverse_m606AE91C5E089F1854C7D93CEB9A076DE041F6FB(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m606AE91C5E089F1854C7D93CEB9A076DE041F6FB (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_mCAB85548741CC2290CD5711D7BDD1D605F3DDD06(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m308FB2CAEAF199171C8A82B14E701BC54B8B4B97 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mDD272882E7942B991C9A1EA5E0D2159CACC3E8A1_inline(__this, NULL);
		List_1_Sort_m7045BFA1D7EA8DBA05CA0CD348D61D0EA85B8682(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m45F7BC16639AE824D25455C7F7C8B85095C5CDE1 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mDD272882E7942B991C9A1EA5E0D2159CACC3E8A1_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m7045BFA1D7EA8DBA05CA0CD348D61D0EA85B8682(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m7045BFA1D7EA8DBA05CA0CD348D61D0EA85B8682 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisVertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76_m209AFB649D59EAEF75AD3C1696A43FDF81C7ADFE(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m9E0EC1185B4933441C7FAEA4D849BFA9D1DE75B4 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, Comparison_1_t6447E02D95C4C995AE37F197D13D355CC1E9AE10* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_t6447E02D95C4C995AE37F197D13D355CC1E9AE10* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t6447E02D95C4C995AE37F197D13D355CC1E9AE10* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m791404477F2D37E776687167796922908A64BCA4(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* List_1_ToArray_mAF6B310F60BD0206826A1E92B4627FFA151048BF (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_1 = ((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_3 = (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = __this->____items;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_m86437E7492F902E147692F7FBFFB486BBB051674 (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_m896CE24A195E32A1363C4F47EC5A86A603400B18(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m7DB9498F929F4CFDF5C0CF824A46680C398F06CD (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_6;
				L_6 = InterfaceFuncInvoker0< VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mD09A0A4D5F4FC01ACDD6A7BC8975F4955A7E1CF6(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck(L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mEAF51DC080029812D35619633B10264F73972214 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m4A11F1A9E1E64780D2B470808F77BC3DF4FA8F44 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_0 = ((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m8F1145270D67E0B3CEBC6254CA273ACFCAEDC702 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_2 = ((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_4 = (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)(WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mC5ED23F7FC2B76408E58C1C8885174145ED99BDD (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_6 = ((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_8 = (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)(WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_12 = ((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m2651B082BDD0B240BC0A569B1407DCFC2E64652E(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m365573DAEE0CC09ED7C9EF91DA5F363256AA4F9F (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_7 = (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)(WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_9 = __this->____items;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_13 = ((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 List_1_get_Item_m2924E7746F6C53EDFEA3CCF16EF3B218E419DC3D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m005D2CC35F5E7CBC3CA9B247C9A6F53C82079AB3 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m258CDE81FD7826B5BC9394598147752BC8856F41 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((&V_0), sizeof(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286));
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_2 = V_0;
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_mCAFF118FAD3E46D5AC4BAD05CD70A91B91F6A707 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_1;
		L_1 = List_1_get_Item_m2924E7746F6C53EDFEA3CCF16EF3B218E419DC3D(__this, L_0, NULL);
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mFCD75572B51943CE99D982A478A07C2C4A8DED59 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mA1DAD0FF706B1F126927FFDD38749A7A54FA292E(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m005D2CC35F5E7CBC3CA9B247C9A6F53C82079AB3(__this, L_1, ((*(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m8733206CE9C292CC7AE372250D705ECD9BC11353 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_7 = V_0;
		int32_t L_8 = V_1;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_9);
		return;
	}

IL_0034:
	{
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_10 = ___0_item;
		List_1_AddWithResize_m0CFF45D3EDB67B4F93F72B28293EACF735E2D915(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m0CFF45D3EDB67B4F93F72B28293EACF735E2D915 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mEB188A6DEB187615EA3F109C3D6FA101549AAE49(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_3 = __this->____items;
		int32_t L_4 = V_0;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m3FF7E0F82AEFB7926ADC1D531520A86B43CDF10E (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mA1DAD0FF706B1F126927FFDD38749A7A54FA292E(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m8733206CE9C292CC7AE372250D705ECD9BC11353_inline(__this, ((*(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m4F68AE5CD41D50629D6288599566638EA4DBCFBE_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_mF33DB428A565353266260776A2BB5C476A5794C0 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_mF79B155E875CD01C203BD61F17DFEF51D3AE620D(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tC4584ACB2E63F593E2DEF37DDA8EA9A18DD97F5D* List_1_AsReadOnly_m33DB0DDA6EB52E7FEA5E76515D94684CAA9493D3 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_tC4584ACB2E63F593E2DEF37DDA8EA9A18DD97F5D* L_0 = (ReadOnlyCollection_1_tC4584ACB2E63F593E2DEF37DDA8EA9A18DD97F5D*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m21AAD542DC641C1CC6201A83A58815D43F49726D(L_0, __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m66C94A2B368326DFDC153672733D937188CD7F2B (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m0995AD1F41D4F87F3A61CFE7C33B65A8459A95E2(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m553891F5D767DDC8FFF25A1A350B75C33DF9530D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4F68AE5CD41D50629D6288599566638EA4DBCFBE_inline(__this, NULL);
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_m66C94A2B368326DFDC153672733D937188CD7F2B(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mBA4892F7A2F21204C1D327B27EEB58EC2F383FA9 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4F68AE5CD41D50629D6288599566638EA4DBCFBE_inline(__this, NULL);
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_m66C94A2B368326DFDC153672733D937188CD7F2B(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m1098E72D9253B8B7EAC7F81412033DC01C077CC4 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mF21748A6EAFA84C0E8D2CF169CEB7CAD353BDE33 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m87D9B1778F33B1D47D8B10D757427E7EB94591BE(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m375BD0F09A2E9964D1E186803F3DF21BE6A62B38 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m258CDE81FD7826B5BC9394598147752BC8856F41(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mF21748A6EAFA84C0E8D2CF169CEB7CAD353BDE33(__this, ((*(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_mEE5C3517BC892D1A7DB31355455CD8002F0DE0DF (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_0 = ___0_array;
		List_1_CopyTo_m46EEB7B6D977E644C0B5D333F81FEAC6C355472D(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mEB188A6DEB187615EA3F109C3D6FA101549AAE49 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m365573DAEE0CC09ED7C9EF91DA5F363256AA4F9F(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_mC1E7D213000E04C28CAF5F74C673358C04098AB5 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_mD98A4B0A65890CA3D82C9D19CAA86DCD6A5ADC9B(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 List_1_Find_mECA3B044B045234DDF9458A71CAB58D10C190C2A (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_1 = ___0_match;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286));
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mD98A4B0A65890CA3D82C9D19CAA86DCD6A5ADC9B (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_mCA968DFD73D48BDB875296E6A8814E215093022D(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mE9F527991D2BD1C7C427249A42225091B7023FDD (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_startIndex, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_mCA968DFD73D48BDB875296E6A8814E215093022D(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mCA968DFD73D48BDB875296E6A8814E215093022D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_10 = ___2_match;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m1010D181F1FD20FEEF6C61A701C9BA9EC6D43C18 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_m195A090FF38080873B8C05C6DE14FFDECE48E591(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m195A090FF38080873B8C05C6DE14FFDECE48E591 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_11 = ___2_match;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_m1A968EF18DCB40E239CDBB9F7E6D5198FA225289 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7* L_4 = ___0_action;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_m77C7D2ACEEF9DF21BE26F4303BCFBEFEF8F7C764_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD List_1_GetEnumerator_m8AC1782C0E411623C05784212245987CA74B7FFF (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m44CA5DD6AF03BEEEA951E58A67514FFE9FC30048((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m725108BE3EF9488F4E00BEED5E2559291A927063 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m44CA5DD6AF03BEEEA951E58A67514FFE9FC30048((&L_0), __this, NULL);
		Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m65CFA9901EE1CE6E9D12EA0751BA71164C49B0C2 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m44CA5DD6AF03BEEEA951E58A67514FFE9FC30048((&L_0), __this, NULL);
		Enumerator_tA3A56830314B0A88EC7912BD320A2D64648019FD L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* List_1_GetRange_m5CEAE3022E418358D72323FBAA1FD6428C2FA51F (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* L_6 = (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_m8F1145270D67E0B3CEBC6254CA273ACFCAEDC702(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* L_9 = V_0;
		NullCheck(L_9);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m87D9B1778F33B1D47D8B10D757427E7EB94591BE (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_0 = __this->____items;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mCAA516810A5A4E54E12136DD70E915064768AF24(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_mA47DF154EFD5068A316A67579BF9E063D2B57335 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m258CDE81FD7826B5BC9394598147752BC8856F41(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m87D9B1778F33B1D47D8B10D757427E7EB94591BE(__this, ((*(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mEC7B7774A45AC794B51AD1DADB2E680D0F85791C (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mEB188A6DEB187615EA3F109C3D6FA101549AAE49(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m8832FC08A5EF5A87E6B2B4C18122600A1F20BC48 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_mA1DAD0FF706B1F126927FFDD38749A7A54FA292E(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mEC7B7774A45AC794B51AD1DADB2E680D0F85791C(__this, L_1, ((*(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_mF79B155E875CD01C203BD61F17DFEF51D3AE620D (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mEB188A6DEB187615EA3F109C3D6FA101549AAE49(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tE320DA6F66936619F210A03F77F93803DCAB9355*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_20 = __this->____items;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck(L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_45;
				L_45 = InterfaceFuncInvoker0< WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_mEC7B7774A45AC794B51AD1DADB2E680D0F85791C(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck(L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m2651B082BDD0B240BC0A569B1407DCFC2E64652E(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m5440E53F4F7D13F14EC26C51EE4865A298C0F217 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m87D9B1778F33B1D47D8B10D757427E7EB94591BE(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m7797CB3726E2D8D8F08F35B4D0853DBF469FB501(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m6064815135F0203C89734BD6C8AD714A1BE302B7 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m258CDE81FD7826B5BC9394598147752BC8856F41(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_m5440E53F4F7D13F14EC26C51EE4865A298C0F217(__this, ((*(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m4740EE3CE7F79802222BBCDCF9914F7CCAF1F7FB (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_4 = ___0_match;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* L_16 = ___0_match;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m7797CB3726E2D8D8F08F35B4D0853DBF469FB501 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286));
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_13 = V_0;
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mCC43F1246F54D250FC88B202794F824FFEE00573 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m107819CC9BEC800B382381A3A4DAC7DAFAD49367 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4F68AE5CD41D50629D6288599566638EA4DBCFBE_inline(__this, NULL);
		List_1_Reverse_m3520CDF5BC09508EF2280BB34D85F62338B365E4(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m3520CDF5BC09508EF2280BB34D85F62338B365E4 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m0B0C8AC7BD3093D4B3350A89EA537D4654583A0A(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mB40FF46F5F9033DD8F16EC31FBF83F46405D18B2 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4F68AE5CD41D50629D6288599566638EA4DBCFBE_inline(__this, NULL);
		List_1_Sort_mA8B491BB3C19694F857CE4DF4901D1606950C26F(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mFA624A97970800D69511B87D048B1D2B88B1E04B (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4F68AE5CD41D50629D6288599566638EA4DBCFBE_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_mA8B491BB3C19694F857CE4DF4901D1606950C26F(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA8B491BB3C19694F857CE4DF4901D1606950C26F (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisWebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286_m52E580379FC406094751B182A878AE05CAD72D19(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m11FD8028F805465432BF7C04AA6731B18314F8C2 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, Comparison_1_t035E1D57F8E92650AD1DCAAFF9632D0F026CA046* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_t035E1D57F8E92650AD1DCAAFF9632D0F026CA046* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t035E1D57F8E92650AD1DCAAFF9632D0F026CA046* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m4C5B394849E5E1EBD694444DCD64F30ACD6BD648(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* List_1_ToArray_mD673366C75396DD42577D673BB6AB022CCB05C13 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_1 = ((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_3 = (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)(WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_4 = __this->____items;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_m4C473195B3BE5A387F461E13B53CE4171FA166A0 (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_m365573DAEE0CC09ED7C9EF91DA5F363256AA4F9F(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m2651B082BDD0B240BC0A569B1407DCFC2E64652E (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_6;
				L_6 = InterfaceFuncInvoker0< WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mEB188A6DEB187615EA3F109C3D6FA101549AAE49(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck(L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_m6C9890541D5A592B036AFD26CA93ABFAD612EE5C (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_0 = (WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)(WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tE320DA6F66936619F210A03F77F93803DCAB9355_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mF30FEE3E944E17EC5FB08148FF63FE253821092D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_0 = ((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mBD3EEB3E27E27898E6E051D4D657BA527DF06D31 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_2 = ((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_4 = (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)(X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m771AB78045A936137E3E8FD89387A08EF15A85F9 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_6 = ((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_8 = (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)(X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_12 = ((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m933BBC3774C46C94DE1BF5CA6AC39EC4E5D37D30(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5C29B9150B8CD4C2BA48966294BFDABF3A119C10 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_7 = (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)(X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_9 = __this->____items;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_13 = ((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D List_1_get_Item_m0B7EFA3EB9BD3A50B8BDEB2463B28E86EF6BA0F1 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m0726156C6DF11D5675F28EC4CACF2EC179D86E55 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m8FA678F87A5F9E701EF1E74D1DC390973929CC9D (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((&V_0), sizeof(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D));
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_2 = V_0;
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m8B4E571EFD9F222044F7414951411A380B426E57 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_1;
		L_1 = List_1_get_Item_m0B7EFA3EB9BD3A50B8BDEB2463B28E86EF6BA0F1(__this, L_0, NULL);
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m27802DF89AC29CFE74CC3A858ADD0AE2603D5E2B (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA17F2B115A27352849BFF45AE179346E639C2B76(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m0726156C6DF11D5675F28EC4CACF2EC179D86E55(__this, L_1, ((*(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m1794A41080E7D990FC91C41044F40666784FAF5F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_7 = V_0;
		int32_t L_8 = V_1;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_9);
		return;
	}

IL_0034:
	{
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_10 = ___0_item;
		List_1_AddWithResize_m57CCC347F7A2D40306F42BE2E7822E13C0516E91(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m57CCC347F7A2D40306F42BE2E7822E13C0516E91 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m53C9A0D593A54DE616005FC0C75DF1DE1FC0EB25(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_3 = __this->____items;
		int32_t L_4 = V_0;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m871031C5F7C253BB5D360838A3FF2690BABF2136 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA17F2B115A27352849BFF45AE179346E639C2B76(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m1794A41080E7D990FC91C41044F40666784FAF5F_inline(__this, ((*(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m0EB2669CA7A6261B73D759A35CF46BA8F2EAA9F0_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m978D9EA63503E752FBD236AE20E1F6B77E7D5F8A (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m806B1F613ACD9C02EB149299D718A1B51DC8779D(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tB6FD6BA75C6F479B6860FCBA235488206BF20E52* List_1_AsReadOnly_m7E1F0AF8C17169D3BBA1ACE4558A33536527DCC1 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_tB6FD6BA75C6F479B6860FCBA235488206BF20E52* L_0 = (ReadOnlyCollection_1_tB6FD6BA75C6F479B6860FCBA235488206BF20E52*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_mAE442BCA7BE7654008D38947D61ACB626CCE4031(L_0, __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m2B49FAD4F587A9C4CA5CBE6AB74CF60105435E16 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mC50E157F7E181EDEA92E51C9F2673CDAE84B5E51(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m4254253BBBE769EB03382BDD18C1314F5D0D2B4A (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m0EB2669CA7A6261B73D759A35CF46BA8F2EAA9F0_inline(__this, NULL);
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_m2B49FAD4F587A9C4CA5CBE6AB74CF60105435E16(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m6B4DFD78CF24B61DA52141451A19CC1BB2F3D0C5 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m0EB2669CA7A6261B73D759A35CF46BA8F2EAA9F0_inline(__this, NULL);
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_m2B49FAD4F587A9C4CA5CBE6AB74CF60105435E16(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m9B5D907F3FB532869173E6ECDAB66CEE173B8143 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mED6A7530571DED9EC65DE47BF2DC8B37D3BABE0D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mA598DCD7147BAA1775E07E60CC8F2BCBC052B9E6(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_mDF60819EA56E2085EFFABEF2DBA9BF5B3E1F440A (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m8FA678F87A5F9E701EF1E74D1DC390973929CC9D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mED6A7530571DED9EC65DE47BF2DC8B37D3BABE0D(__this, ((*(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_mB473AA1B803199222BEE09AFC20AFAF4E8D83B84 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_0 = ___0_array;
		List_1_CopyTo_m334B1330AE8565DC583C274533F172510BB5C839(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m53C9A0D593A54DE616005FC0C75DF1DE1FC0EB25 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m5C29B9150B8CD4C2BA48966294BFDABF3A119C10(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_mA32FD1F546A2B00CBE19E29A755962CFB537E282 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_mA0A82440E4B1821AF295DCEFACEDE6414F672C9B(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D List_1_Find_m29E38C6098819A354BCEA0F6D162A424D5146900 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_1 = ___0_match;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D));
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA0A82440E4B1821AF295DCEFACEDE6414F672C9B (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_mEF23AA633A6618208A8864BB4A59260DFF6E0AF4(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA96FDF80DCB8E29E6D783099944464DBAF56E155 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_startIndex, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_mEF23AA633A6618208A8864BB4A59260DFF6E0AF4(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mEF23AA633A6618208A8864BB4A59260DFF6E0AF4 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_10 = ___2_match;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m799DE8A10DF19296FCB793262EEE4B1A3F783F2D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_mE37DB2FA21A091A57F38BB3727C2D4F1586DC38F(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mE37DB2FA21A091A57F38BB3727C2D4F1586DC38F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_11 = ___2_match;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_m9C3C746DC1EC0F3D82E8DFCAA80BD38D2BE07CF5 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023* L_4 = ___0_action;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_m4298A6EF344901142C650584A3B102A0582873A6_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588 List_1_GetEnumerator_m802161253C2558466C620AB571E214D6842B000E (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0F297AA4D5E9DCCA5B022568286E587CFFA548B9((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m3BC068757C3F0882B70B51ABC88E013CF83C08BA (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0F297AA4D5E9DCCA5B022568286E587CFFA548B9((&L_0), __this, NULL);
		Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_mDCBE73484955531E53A36B1F7220BA02B53D213A (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0F297AA4D5E9DCCA5B022568286E587CFFA548B9((&L_0), __this, NULL);
		Enumerator_t04BE6117C1CB74CBDA5B3D45C357B11E5F40B588 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* List_1_GetRange_mF28ABC0904F9A6BD8DC77704B4B8E980ED1F4C1E (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* L_6 = (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_mBD3EEB3E27E27898E6E051D4D657BA527DF06D31(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* L_9 = V_0;
		NullCheck(L_9);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mA598DCD7147BAA1775E07E60CC8F2BCBC052B9E6 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_0 = __this->____items;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA53DD5C386D2BC150E7AF665AD973861A0325966(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m14D7890EBAD6E071F64D77CEF3CBF0EC6DE73BFE (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m8FA678F87A5F9E701EF1E74D1DC390973929CC9D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mA598DCD7147BAA1775E07E60CC8F2BCBC052B9E6(__this, ((*(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mA52D0749531BA9E39D056DEC246376A16DFA768D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m53C9A0D593A54DE616005FC0C75DF1DE1FC0EB25(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_mEE70CD456A1C6F2C24C1E806D8DF5DECD65E7D79 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mA17F2B115A27352849BFF45AE179346E639C2B76(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mA52D0749531BA9E39D056DEC246376A16DFA768D(__this, L_1, ((*(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m806B1F613ACD9C02EB149299D718A1B51DC8779D (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m53C9A0D593A54DE616005FC0C75DF1DE1FC0EB25(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_20 = __this->____items;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck(L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_45;
				L_45 = InterfaceFuncInvoker0< X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_mA52D0749531BA9E39D056DEC246376A16DFA768D(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck(L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m933BBC3774C46C94DE1BF5CA6AC39EC4E5D37D30(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAEDA4677C2ADEDBDA2DF0F8F9E9F0748C01E553F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mA598DCD7147BAA1775E07E60CC8F2BCBC052B9E6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m663ADE2FC3D8F054681C0FF19E9996185AB5BDD7(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m6442ACCABF65925C668669A2061DFFA41D340D87 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m8FA678F87A5F9E701EF1E74D1DC390973929CC9D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mAEDA4677C2ADEDBDA2DF0F8F9E9F0748C01E553F(__this, ((*(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m34DC59B059E6462CB25BCBE323402D032C2FABE9 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_4 = ___0_match;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* L_16 = ___0_match;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m663ADE2FC3D8F054681C0FF19E9996185AB5BDD7 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D));
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_13 = V_0;
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m3D57FAE9B72CEB7C56F9529947A9708306F7E296 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m449B6F95516DFCD6851383FCF46A0ED03CFD7CF7 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m0EB2669CA7A6261B73D759A35CF46BA8F2EAA9F0_inline(__this, NULL);
		List_1_Reverse_m90285F94EF464888EDC820B62826C0482EAA1883(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m90285F94EF464888EDC820B62826C0482EAA1883 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_m12119C509581F764BD40D4271062FAA078B90764(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m14751434DFA58F7861D202257D820A478030F08F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m0EB2669CA7A6261B73D759A35CF46BA8F2EAA9F0_inline(__this, NULL);
		List_1_Sort_m32893B90CE4E1370C3F82B6EBE941635F7C62A96(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m21F5E645534A1C7D2BDB2EA5FEE5EFDF6CB442B4 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m0EB2669CA7A6261B73D759A35CF46BA8F2EAA9F0_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m32893B90CE4E1370C3F82B6EBE941635F7C62A96(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m32893B90CE4E1370C3F82B6EBE941635F7C62A96 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisX509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D_mE15993628BBDD272038B8BB6E5847DD6ECFED252(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mF408D112DB002AE0B294C2695B50B07C5CD44E0F (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, Comparison_1_t89BA6BA726C49026677C45BEDBD41952739E06A2* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_t89BA6BA726C49026677C45BEDBD41952739E06A2* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t89BA6BA726C49026677C45BEDBD41952739E06A2* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m54388C4AC33B08A6F59DA0D043DE35C6F7CE74CD(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* List_1_ToArray_m4F1BB2A6D076B50BF97BCE92550F3CA5FE5B1322 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_1 = ((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_3 = (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)(X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_4 = __this->____items;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_mFC33632E23AB4C97755A6F05B35712878F875545 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_m5C29B9150B8CD4C2BA48966294BFDABF3A119C10(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m933BBC3774C46C94DE1BF5CA6AC39EC4E5D37D30 (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_6;
				L_6 = InterfaceFuncInvoker0< X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m53C9A0D593A54DE616005FC0C75DF1DE1FC0EB25(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck(L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_m1A34C024DA9DAF0ADB9F25E5A74CF29F43B39C14 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_0 = (X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)(X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mB5A115525F03F979B28964F23108C8C5312FC460 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_0 = ((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m1742E82D5AF5200DFAC69B895C4A24E80D760C4D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_2 = ((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_4 = (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)(XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m9313D754412425CDD96F4AB6AF2BE94CFC547467 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_6 = ((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_8 = (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)(XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_12 = ((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m6C3A37912654122DD8AE143EFEB1C2A4C1015C29(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5593B7194363BCB1B716A4ECA594F6E2CC03F94C (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_7 = (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)(XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_9 = __this->____items;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_13 = ((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 List_1_get_Item_m4C81AE785745E7C9A726104CD2F588258FBE5E8F (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m6C903F3CAAD0D6DA54369D2224E52DFADB242F60 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m72B9D7AAB1A1E284232CC6C4CF613FEA6A227584 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((&V_0), sizeof(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2));
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_2 = V_0;
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m43477563FF796F46E62630752F9BE96E325D1539 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_1;
		L_1 = List_1_get_Item_m4C81AE785745E7C9A726104CD2F588258FBE5E8F(__this, L_0, NULL);
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mF605D424A31F1FBA0A3372FFDB96685809FE65F2 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mADBF15F169E5DF2762161FB96F64C99569429300(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m6C903F3CAAD0D6DA54369D2224E52DFADB242F60(__this, L_1, ((*(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m50157FAAF8FE0562A862140A17AD2B1097B078E7 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_7 = V_0;
		int32_t L_8 = V_1;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_9);
		return;
	}

IL_0034:
	{
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_10 = ___0_item;
		List_1_AddWithResize_m55AFD45DC0ADD64C8749E1B59252B0BF0793CE49(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m55AFD45DC0ADD64C8749E1B59252B0BF0793CE49 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mB16BDFA4B73F390167601AF70BC65637BF9AE433(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_3 = __this->____items;
		int32_t L_4 = V_0;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mC6B19D56B8AE9140033F1D945B32C63D7787F1E7 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mADBF15F169E5DF2762161FB96F64C99569429300(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m50157FAAF8FE0562A862140A17AD2B1097B078E7_inline(__this, ((*(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m67096A69BCCCB33B2146561E2259883F084F5B95_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m11FEE6342C344D8B7EC9B4149CC6481D71B8131C (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m2555E93F7C903532A49529BCC327427FC3B1C6EE(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t803A81BE343B15275BCD30A219ACAC97F0B9A1C8* List_1_AsReadOnly_mACE06FAFE83E7F8666C85F2B1221320C9317229A (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_t803A81BE343B15275BCD30A219ACAC97F0B9A1C8* L_0 = (ReadOnlyCollection_1_t803A81BE343B15275BCD30A219ACAC97F0B9A1C8*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_mCAD4E9DC796CAE1655D1F09987BFC987E8FD72F1(L_0, __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m603A1422A5D4C6AC20CFDB1897BD527164CFE059 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_m469FFB0730A2E7136D62A2AE6D197A1858EC6CFE(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m801D312379BE0AE1182D84AD92CA7B2E586F4C94 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m67096A69BCCCB33B2146561E2259883F084F5B95_inline(__this, NULL);
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_m603A1422A5D4C6AC20CFDB1897BD527164CFE059(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m626ED321DA6F622943A33FF1D261635171AFF7EC (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m67096A69BCCCB33B2146561E2259883F084F5B95_inline(__this, NULL);
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_m603A1422A5D4C6AC20CFDB1897BD527164CFE059(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_mEE78EC937E81E2FDA5335F33388A6E97E29F8F31 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mA297C73B52DACB79EAF9BABC705E6D7DB8EB7978 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m54DA0380F7731F2146DEDD98FC646038D9FC3923(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m0CDE85DB8C5DC9B72599D70A788A493AC0B8A208 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m72B9D7AAB1A1E284232CC6C4CF613FEA6A227584(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mA297C73B52DACB79EAF9BABC705E6D7DB8EB7978(__this, ((*(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_mF8F83E4B8C9C108EF18A8DD2013F6B28D7973601 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_0 = ___0_array;
		List_1_CopyTo_m0E4DE3BC195FF67210FE47068EE58A77C5074C85(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB16BDFA4B73F390167601AF70BC65637BF9AE433 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m5593B7194363BCB1B716A4ECA594F6E2CC03F94C(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_mB669AD0B558524366CCCE12802080E2B6C8E29F7 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_m14D5EB230C22B6C4A649235CC3E08C5F6561E15B(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 List_1_Find_mEA5FFD8AE168068A5E1A7C3F2EE50951DE0D95C4 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_1 = ___0_match;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2));
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m14D5EB230C22B6C4A649235CC3E08C5F6561E15B (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m3A09BF3BCAAF3C61D9A2EEF2C3090311C21A62EB(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m51E998267867F8D97298015D769AFDCC7EE81CC5 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_startIndex, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_m3A09BF3BCAAF3C61D9A2EEF2C3090311C21A62EB(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m3A09BF3BCAAF3C61D9A2EEF2C3090311C21A62EB (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_10 = ___2_match;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m6D3AC86C71F42816D3E21F44F07E449BA78CFD8D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_m94DC2E52655A61CACBDD8FFD47097AAE3E618198(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m94DC2E52655A61CACBDD8FFD47097AAE3E618198 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_11 = ___2_match;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_mA5C50F2E961CBF3FD566EC636E04E15E5878DC49 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7* L_4 = ___0_action;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_m14B5F0EFFF227D076151E00CACE917B6512254B8_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0 List_1_GetEnumerator_mB89A30406EEF5FDCEE5AF1043B26322952301CC5 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m5CBA8C17D9A8E5F5E385A4876B9B1745FA3CB8C0((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF0B7F334A99DCAF4683DC567B17D41A6533693AF (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m5CBA8C17D9A8E5F5E385A4876B9B1745FA3CB8C0((&L_0), __this, NULL);
		Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m28BAB8390754C90274D3D56A124833D0EEC11046 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m5CBA8C17D9A8E5F5E385A4876B9B1745FA3CB8C0((&L_0), __this, NULL);
		Enumerator_tB41744EFD7274B3F0B75074E72D0EB8C658D06A0 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* List_1_GetRange_mB9031AD631C5CE205CA8A609E7609BE73F7EC115 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* L_6 = (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_m1742E82D5AF5200DFAC69B895C4A24E80D760C4D(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* L_9 = V_0;
		NullCheck(L_9);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m54DA0380F7731F2146DEDD98FC646038D9FC3923 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_0 = __this->____items;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mECE416DA9044547B55FF326280E3AFAB15850B37(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m092D30E460F94CBB0CA767F55E7FA83513870516 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m72B9D7AAB1A1E284232CC6C4CF613FEA6A227584(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m54DA0380F7731F2146DEDD98FC646038D9FC3923(__this, ((*(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mBECAB59CCD69670908799776F1D6507EF7EA7D87 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mB16BDFA4B73F390167601AF70BC65637BF9AE433(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m9D19205B336741A33577DAA89A2E89EE6877607A (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mADBF15F169E5DF2762161FB96F64C99569429300(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mBECAB59CCD69670908799776F1D6507EF7EA7D87(__this, L_1, ((*(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m2555E93F7C903532A49529BCC327427FC3B1C6EE (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mB16BDFA4B73F390167601AF70BC65637BF9AE433(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_20 = __this->____items;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck(L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_45;
				L_45 = InterfaceFuncInvoker0< XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_mBECAB59CCD69670908799776F1D6507EF7EA7D87(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck(L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m6C3A37912654122DD8AE143EFEB1C2A4C1015C29(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m15AEA673A2E9F2A482D49F374814A49D0734CEC6 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m54DA0380F7731F2146DEDD98FC646038D9FC3923(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m53875FA8AA50D0F755EE525314DB9818741B6E2F(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m3FECF0FF7CFC70F9CAFD6638404006EDD1958497 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m72B9D7AAB1A1E284232CC6C4CF613FEA6A227584(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_m15AEA673A2E9F2A482D49F374814A49D0734CEC6(__this, ((*(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_mA70F72C868278E8BFADAF3B4360A368940DD3C6E (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_4 = ___0_match;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* L_16 = ___0_match;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m53875FA8AA50D0F755EE525314DB9818741B6E2F (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2));
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_13 = V_0;
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mC1B1AB6D62C187164FAC266ABA9E2CCF9A82E319 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m30B202196815C19AE8B0490CBAAB3BD9BFE7708D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m67096A69BCCCB33B2146561E2259883F084F5B95_inline(__this, NULL);
		List_1_Reverse_m3CE641659C3CD3760E5EE96E88FA7006B7D9995D(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m3CE641659C3CD3760E5EE96E88FA7006B7D9995D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_m6953DC1CD28104B40EF7B6C79E12EDA04CCC52F3(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mBE8198663CB0C59B33595171E2AEB7AC234A928B (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m67096A69BCCCB33B2146561E2259883F084F5B95_inline(__this, NULL);
		List_1_Sort_m52E4077FCE9FF6DF21E5DCE7A99DACB700AB2E0D(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mDF03A517DD0404D794600FB10DB2E1C96B05CDDB (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m67096A69BCCCB33B2146561E2259883F084F5B95_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m52E4077FCE9FF6DF21E5DCE7A99DACB700AB2E0D(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m52E4077FCE9FF6DF21E5DCE7A99DACB700AB2E0D (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisXRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2_mACACE6CA017DAF3419A4C86E329FA9CFE4018C03(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m4516B76B51AD343F66ACF3B5A7F9759588DACAB1 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, Comparison_1_t55FCE173570442A2D451AE8BFC15B22D41D55DC9* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_t55FCE173570442A2D451AE8BFC15B22D41D55DC9* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t55FCE173570442A2D451AE8BFC15B22D41D55DC9* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m479DAA4C8994B2FBFA82BCC2220725F25C35DCD9(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* List_1_ToArray_m677619684B3EF4C720C66F624ADAB575895E7157 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_1 = ((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_3 = (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)(XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_4 = __this->____items;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_m6ED6F38E8DE4AB9707C793DAA411AEC7E220BD79 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_m5593B7194363BCB1B716A4ECA594F6E2CC03F94C(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m6C3A37912654122DD8AE143EFEB1C2A4C1015C29 (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_6;
				L_6 = InterfaceFuncInvoker0< XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mB16BDFA4B73F390167601AF70BC65637BF9AE433(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck(L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_m567B01372F1083CB9736FFF9FAA3FA8B86FA3FB2 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_0 = (XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)(XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mD44B58ABA4B42AA58A297AFEF2E682261FA3182F (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_0 = ((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mF13A6D0FE4169F106512A28BA7B29E68E7D4E1FA (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_2 = ((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_4 = (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)(XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mC79F163BBB95AB963F82201C1DB10215415788F5 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_6 = ((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_8 = (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)(XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_12 = ((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m9B49892AA65CC96277D2D79218DB14788068DA41(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mD7F92B17978CCAD780D5027AB9ED84DC79B44DFD (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_7 = (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)(XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_9 = __this->____items;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_13 = ((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 List_1_get_Item_mFFCB4E0F2978CE787223C6D1734D41306942EB30 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m7A495455B6674DB278F9185B18C72E8BEF911BA7 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m70B0273AB943F33BC49BE752D55720E5A6B45863 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((&V_0), sizeof(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5));
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_2 = V_0;
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m2B89DC21E9112FD507C9A5C9DDEC308181CD18BC (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_1;
		L_1 = List_1_get_Item_mFFCB4E0F2978CE787223C6D1734D41306942EB30(__this, L_0, NULL);
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m6B91DFE7E5863903C76EEAB0E841E2FC4EC02726 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m8ADD7E3A387FB67C59B3A2FB00548D05874F417B(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m7A495455B6674DB278F9185B18C72E8BEF911BA7(__this, L_1, ((*(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m26A98FFE1090E98CCB9AA0278EC4017152C89F85 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_7 = V_0;
		int32_t L_8 = V_1;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_9);
		return;
	}

IL_0034:
	{
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_10 = ___0_item;
		List_1_AddWithResize_m940FD70455448D1B8E960B93BE1194188D09F786(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m940FD70455448D1B8E960B93BE1194188D09F786 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m479A86683CEE12F0C214CB5F3A05549381DC660E(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_3 = __this->____items;
		int32_t L_4 = V_0;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m67A1605BA621AA48A861A6919D1E708F92F5AE4F (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m8ADD7E3A387FB67C59B3A2FB00548D05874F417B(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m26A98FFE1090E98CCB9AA0278EC4017152C89F85_inline(__this, ((*(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m38785A4676BA4266C779A1DCB1DA31522E554864_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m8CEAB9895EBA109532CE1E4BEBD8B8EA504C42CF (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m992A9116BAD4C2EC04F0F9C88B89A1B52C17EB80(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t95C4CE7A3281F650247DAD055168AC75CA2E0D94* List_1_AsReadOnly_m163C41C3E7072D96162C056BE4E0DE33C7ACC255 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_t95C4CE7A3281F650247DAD055168AC75CA2E0D94* L_0 = (ReadOnlyCollection_1_t95C4CE7A3281F650247DAD055168AC75CA2E0D94*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m0F14248B4CC1878CDFEC416C9213E81135B04750(L_0, __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m0280BDACD6B1BE7BD4B43BF0E243AAA3240204CF (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m5D4301D56E29378AE3D729C7AB2EACA0F911398F(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m38A0F93D6596DC6D35726CBFF8A93B53AD731AB4 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m38785A4676BA4266C779A1DCB1DA31522E554864_inline(__this, NULL);
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_m0280BDACD6B1BE7BD4B43BF0E243AAA3240204CF(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mCCF7403AFEFD8CB55D75882742BC00E35723026B (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m38785A4676BA4266C779A1DCB1DA31522E554864_inline(__this, NULL);
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_m0280BDACD6B1BE7BD4B43BF0E243AAA3240204CF(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m4EC103D42EA8C9452F05D8A41A258EDCFCD19E90 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4EEC6DE78174B1A7C89D5DA9D0B9923881561328 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mFDE66951AEA8FFF75C995BEF3AA99D47C3AA8B21(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m8F263B2B28A0D146D5DE869A1B74FE007009B6EA (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m70B0273AB943F33BC49BE752D55720E5A6B45863(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m4EEC6DE78174B1A7C89D5DA9D0B9923881561328(__this, ((*(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m6C1513CE35993155222333FC3593665170A710D2 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_0 = ___0_array;
		List_1_CopyTo_mDB8EBD9ED943554A5C6FAD9384AB4B42567E5C7B(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m479A86683CEE12F0C214CB5F3A05549381DC660E (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_mD7F92B17978CCAD780D5027AB9ED84DC79B44DFD(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_mEA7D709186C31195ABA25F12D1697A580A770ACB (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_mB4E76D35717A9DB62561714DAF4292E2B4404D58(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 List_1_Find_m2D48EAA874F6F97D616671C9BB4D4AAA18D87079 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_1 = ___0_match;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5));
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mB4E76D35717A9DB62561714DAF4292E2B4404D58 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m182300006C2F508433064C65566BFE6D4210BF3D(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mEC69724DFF88DF5955F06802E481286453F2315E (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_startIndex, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_m182300006C2F508433064C65566BFE6D4210BF3D(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m182300006C2F508433064C65566BFE6D4210BF3D (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_10 = ___2_match;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m46429DBF08639BB3B193EE86CEE9F1FD4B194C59 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_m2932FC34CFE0B8373CC0E031216528C99A0F008B(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m2932FC34CFE0B8373CC0E031216528C99A0F008B (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_11 = ___2_match;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_m9F5AE2BAF57DC6A75B13D5DB8B4127A71B5035D7 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440* L_4 = ___0_action;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_m1E148200B150317478F1EAF858AE3F230EB8D4AA_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1 List_1_GetEnumerator_mD69BC60CDB6D4766B7D2F9D15C55F20E357F9989 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m9649445EB055BFD3F58AC786F4A50C5843ACBEE5((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mB0582F5E4B7C2DCADC9C2A4F0D79A85E443295F1 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m9649445EB055BFD3F58AC786F4A50C5843ACBEE5((&L_0), __this, NULL);
		Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m3A1E24B9688C724EE19E866F583C0E9B0EF96CE2 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m9649445EB055BFD3F58AC786F4A50C5843ACBEE5((&L_0), __this, NULL);
		Enumerator_tA2DAF234D0BEBCCA6944A6E989C24F6A56AF9EE1 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* List_1_GetRange_m7D82D0439F9235772F4905AAA58EABB23E202EDB (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* L_6 = (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_mF13A6D0FE4169F106512A28BA7B29E68E7D4E1FA(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* L_9 = V_0;
		NullCheck(L_9);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mFDE66951AEA8FFF75C995BEF3AA99D47C3AA8B21 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_0 = __this->____items;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_mF9B09B9F1A4B269FF6D212596871AA5569E5D8B2(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m395663174D314121EE63B30F2986F9625E1AF726 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m70B0273AB943F33BC49BE752D55720E5A6B45863(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mFDE66951AEA8FFF75C995BEF3AA99D47C3AA8B21(__this, ((*(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m4C4C068BB28606E5DE98FB7616757884C4CCD698 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m479A86683CEE12F0C214CB5F3A05549381DC660E(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m8E6D2211307B0D2DD1245B318918A06D3298FE69 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m8ADD7E3A387FB67C59B3A2FB00548D05874F417B(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_m4C4C068BB28606E5DE98FB7616757884C4CCD698(__this, L_1, ((*(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m992A9116BAD4C2EC04F0F9C88B89A1B52C17EB80 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m479A86683CEE12F0C214CB5F3A05549381DC660E(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_20 = __this->____items;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck(L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_45;
				L_45 = InterfaceFuncInvoker0< XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_m4C4C068BB28606E5DE98FB7616757884C4CCD698(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck(L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m9B49892AA65CC96277D2D79218DB14788068DA41(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mBA2ED23FD37868DBBC644AD7E3A9935F0DE57CB3 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mFDE66951AEA8FFF75C995BEF3AA99D47C3AA8B21(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m0A038738F0C2834BE11C14491130246276431B20(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_mD9AEEFB0A07AAF24E3626F414A049BBBF6D7054A (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m70B0273AB943F33BC49BE752D55720E5A6B45863(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mBA2ED23FD37868DBBC644AD7E3A9935F0DE57CB3(__this, ((*(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_mF10A319E7A0AA8782F3133A3D0DC05616DC173D7 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_4 = ___0_match;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* L_16 = ___0_match;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m0A038738F0C2834BE11C14491130246276431B20 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5));
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_13 = V_0;
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m24B183FCC3FA94AC600E1948B46283B5FCBC2869 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_mAE8C02A14FC1C0828D2BD5535EA0D26EF4C42259 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m38785A4676BA4266C779A1DCB1DA31522E554864_inline(__this, NULL);
		List_1_Reverse_m39920E0E4B4089FD8E4C0A5CA145911B31FA1D15(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m39920E0E4B4089FD8E4C0A5CA145911B31FA1D15 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m9E4B79FAA123091EDADB1E0EDBD296F9AECCBCD9(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m90EA5F86F09D7EA61D3F18E143DBBC4D15118F43 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m38785A4676BA4266C779A1DCB1DA31522E554864_inline(__this, NULL);
		List_1_Sort_m81FCD89C0A108E16223AF643893B87B1BF43002D(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mF18BB7238E510EE28D2775FCF596129CC1940002 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m38785A4676BA4266C779A1DCB1DA31522E554864_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m81FCD89C0A108E16223AF643893B87B1BF43002D(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m81FCD89C0A108E16223AF643893B87B1BF43002D (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisXRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5_m4595EBB46D67A07754F8987A2B382C13811C8D88(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m397091D63432807EBFB7D37176FD5D96071CFAC5 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, Comparison_1_tCC0DD2EF5FD4D03E423A3C172F5D948A944669DA* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_tCC0DD2EF5FD4D03E423A3C172F5D948A944669DA* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tCC0DD2EF5FD4D03E423A3C172F5D948A944669DA* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m5935F327EBF640B1FEB63092149D6B0D5ADD8C4D(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* List_1_ToArray_m995A76FB6E2713586892C03382AA7EEC26F5AAAB (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_1 = ((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_3 = (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)(XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_4 = __this->____items;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_m3D367E107FE47980581B65096070EB462A7F16E1 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_mD7F92B17978CCAD780D5027AB9ED84DC79B44DFD(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m9B49892AA65CC96277D2D79218DB14788068DA41 (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_6;
				L_6 = InterfaceFuncInvoker0< XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m479A86683CEE12F0C214CB5F3A05549381DC660E(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck(L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mF6AA7A79EF86B3CB9627ED67BDBD2BC1EBB7E93C (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_0 = (XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)(XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7378BA5FBCA1E88080985FB810820B3F47DAD54C_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m54D719307910A9DC9CD4DEFA8AE2626F49EB7516_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m4D165FBE2796C395527CD5404B0C5D0F2828736A_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_6 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_8 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_9 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_13 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		Il2CppSharedGenericObject* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		Il2CppSharedGenericObject* L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (Il2CppSharedGenericObject*)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		RuntimeObject* L_0 = ___0_value;
		if (((Il2CppSharedGenericObject*)IsInst((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m78BCF727FD3CF47C4FE97D00AFAD2781B6A7F004_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		Il2CppSharedGenericObject* L_1;
		L_1 = List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515(__this, L_0, NULL);
		return (RuntimeObject*)L_1;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m5E8C43852B62BD7E2A9582754B44057F224BD12D_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF(__this, L_1, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = V_0;
		int32_t L_8 = V_1;
		Il2CppSharedGenericObject* L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (Il2CppSharedGenericObject*)L_9);
		return;
	}

IL_0034:
	{
		Il2CppSharedGenericObject* L_10 = ___0_item;
		List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (Il2CppSharedGenericObject*)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mC916FB88482D2EF5E43527D9840C8E67FAC4D4CB_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_inline(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m655A34E010FCB41069350D2D616558180A0C0AFF_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263* List_1_AsReadOnly_m55F73F8553E9885F803507A3650967BE90AA81C9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263* L_0 = (ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_mC1890FAC00703F47A655C35CBCB613C74A811580(L_0, (RuntimeObject*)__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mB2BE3DF9182ED9C862AA44566C878D046534474E_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, Il2CppSharedGenericObject* ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		Il2CppSharedGenericObject* L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_TisIl2CppSharedGenericObject_m6D8A1F3C8EDCAAF226FE8B32CBB649F099D8C16B(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m541581D188E2E7A2C2FF99CDE1FA62559C4E22F7_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		Il2CppSharedGenericObject* L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_mB2BE3DF9182ED9C862AA44566C878D046534474E(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m1AE074244BC7C4672E92D4E5B8F2E1A5015F8C8F_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		Il2CppSharedGenericObject* L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_mB2BE3DF9182ED9C862AA44566C878D046534474E(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_mCCC05B98943E8F4E0F6FBF47063A269048AE71E5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		Il2CppSharedGenericObject* L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m7E4E8EA0E50007EC7F90752FBB913B35DBD8C00B_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m04A1E702FBAB126758881A6A6D42052295136DCD_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_array;
		List_1_CopyTo_m75919E1737F4EC8D7DD329629C11CACA64EF5BE3(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_mEF102A40848CF9A0986FF9992D666F99F3DC79BB_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_mD56F0607D7DAD9622F7DE2C6C8957D9C7847EEC5(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* List_1_Find_m6620F179C7B4BFD1BB040EA342AEBDEC8B2C5B44_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_1 = ___0_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		Il2CppSharedGenericObject* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		Il2CppSharedGenericObject* L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mD56F0607D7DAD9622F7DE2C6C8957D9C7847EEC5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m7045E26E5CE9E0449BF70DC55234C9B9E5265F41_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_10 = ___2_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		Il2CppSharedGenericObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m8F234B6692487E3D9AE864FB759FF51E5C35EEE5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_m75AB13CBCA95A0E0722F6CDE89F0CBDAB27322DA(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m75AB13CBCA95A0E0722F6CDE89F0CBDAB27322DA_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_11 = ___2_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		Il2CppSharedGenericObject* L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_m8ADDD90CD18FA47D7C9010951EE34AA49513AC50_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* L_4 = ___0_action;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		Il2CppSharedGenericObject* L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mBF03CBE09BFBA1E25B3E040FC761F6674F19D793_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9((&L_0), __this, NULL);
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m2B6B507A19EBC0BBE5E87F276DB25C8B3388EC75_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9((&L_0), __this, NULL);
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* List_1_GetRange_m2C6E6EDDC70F1D5E30EF591172FA5590D17035FB_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_6 = (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_m54D719307910A9DC9CD4DEFA8AE2626F49EB7516(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_9 = V_0;
		NullCheck(L_9);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->____items;
		Il2CppSharedGenericObject* L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m1C5FA1B6E2917EF7F5DDC5BF65147FE6EF7F8517_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		Il2CppSharedGenericObject* L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (Il2CppSharedGenericObject*)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m09D3F4F2042326635CFB5369AC8F9760A7F81CE2_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E(__this, L_1, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_20 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck((RuntimeObject*)L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				Il2CppSharedGenericObject* L_45;
				L_45 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck((RuntimeObject*)L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		Il2CppSharedGenericObject* L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_mCBBBF61C9D398AB54A3B84E64145D65DF44BA716_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m4EE2013145E54D7A4FC8DC18C59D96E7DB7766FC_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_4 = ___0_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		Il2CppSharedGenericObject* L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_16 = ___0_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		Il2CppSharedGenericObject* L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		Il2CppSharedGenericObject* L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (Il2CppSharedGenericObject*)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_13 = V_0;
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_12), (Il2CppSharedGenericObject*)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m62CC0A9594355982BB7665FB6F070950D3B89C30_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m5D2819AF5937BFF72667A9AC1F0D657F4AFF58BC_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m07AFC087F5B3C54E8E292639DA39D7CBBBF047B2_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA11C7B54C894C91320394703D2B0BB90E5FBF21B_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m5DC9EDD762287204259B029E98F1409BC3A63A81_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* List_1_ToArray_m90E6D9E57256EC0FB6B36FDC40F65B0F59D7B671_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_m3837DE03BEA738B4FB4A586787ABAB0638DFCD7F_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	Il2CppSharedGenericObject* V_1 = NULL;
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck((RuntimeObject*)L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				Il2CppSharedGenericObject* L_6;
				L_6 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				Il2CppSharedGenericObject* L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (Il2CppSharedGenericObject*)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck((RuntimeObject*)L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mF9EC44C2DCE6FA8CA8EFEC794130234F42A1D6DB_gshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mD53DE65329B412F767B58BB545422AA94C761581_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_0 = ((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m6584A1C860271ACE4B035721F88B0ED8F5C1FE56_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_2 = ((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_4 = (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)(__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m1DBAC5A05DBBA4EA084B16664220012DDD12FEDD_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_6 = ((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_8 = (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)(__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_12 = ((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m426F79399C24D92B89DBA07ABF04AD125278169D(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mA829BA58B34F17EE008D7D66468B478647866621_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_7 = (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)(__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_9 = __this->____items;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_13 = ((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
// Method Definition Index: 11284
// Method Definition Index: 11285
// Method Definition Index: 11286
// Method Definition Index: 11287
// Method Definition Index: 11288
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t List_1_get_Item_mAA1579D28843BE101AF5735731E5F6C74CADBC25_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		uint8_t L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m8178833364A7D14F2AC3ACE6FC8DE95D5FF9B7BB_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, uint8_t ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		uint8_t L_4 = ___1_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (uint8_t)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mF6062BD01FB16E2976FE77274D3B42294B156F8D_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	uint8_t V_0 = 0;
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((&V_0), sizeof(uint8_t));
		uint8_t L_2 = V_0;
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_mDE1597858CCE60D711445E51141A09545897B620_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		uint8_t L_1;
		L_1 = List_1_get_Item_mAA1579D28843BE101AF5735731E5F6C74CADBC25(__this, L_0, NULL);
		uint8_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mBAC2F3DA3ECEDB6EB063CE06A9A33C910D594759_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m1BCCAEF15531A89027A8C21D496867A6744E119A(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m8178833364A7D14F2AC3ACE6FC8DE95D5FF9B7BB(__this, L_1, ((*(uint8_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m4950BFDE5379FB1EE9E82C2AA9E4631881DED88D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_7 = V_0;
		int32_t L_8 = V_1;
		uint8_t L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (uint8_t)L_9);
		return;
	}

IL_0034:
	{
		uint8_t L_10 = ___0_item;
		List_1_AddWithResize_m76095CD55E33211D69331C6DBF9A12AE1E1F544C(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m76095CD55E33211D69331C6DBF9A12AE1E1F544C_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_3 = __this->____items;
		int32_t L_4 = V_0;
		uint8_t L_5 = ___0_item;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(L_4), (uint8_t)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m6054DDBA0CC43689644F8F2ABB33B3F0AB4A1244_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m1BCCAEF15531A89027A8C21D496867A6744E119A(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m4950BFDE5379FB1EE9E82C2AA9E4631881DED88D_inline(__this, ((*(uint8_t*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_mE2A014D40D80B0243F6B9B41149E7D086E96900D_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_mE023419E6F0A822454D9133DFECFB6C2788C7A5D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m169B03E44FA6B59F43486EEEA8E98C44F7B5751E(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tD86E076A19D3DF6CFD1AC3FEE937BD0FB0B39AF7* List_1_AsReadOnly_m1096F306589451BBC51A75DB57A060F0B0C6A620_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_tD86E076A19D3DF6CFD1AC3FEE937BD0FB0B39AF7* L_0 = (ReadOnlyCollection_1_tD86E076A19D3DF6CFD1AC3FEE937BD0FB0B39AF7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m691F18FF07E708D77863DB26C8FD7C99240CBBDE(L_0, (RuntimeObject*)__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mE7F3B1638176AF8F4CC0E83A5D06258B839D9F6F_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, uint8_t ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		uint8_t L_8 = ___2_item;
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = Array_BinarySearch_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mCC8652BE0AE4082A8DEA7D0B05CF46DE9C38F9D1(L_5, L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mF470C003062D2BF15E575325436FEB1598B4C176_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mE2A014D40D80B0243F6B9B41149E7D086E96900D_inline(__this, NULL);
		uint8_t L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_BinarySearch_mE7F3B1638176AF8F4CC0E83A5D06258B839D9F6F(__this, 0, L_0, L_1, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_mB9BC4EF55D86FC2A8625A79A308F960FFDF71849_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mE2A014D40D80B0243F6B9B41149E7D086E96900D_inline(__this, NULL);
		uint8_t L_1 = ___0_item;
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = List_1_BinarySearch_mE7F3B1638176AF8F4CC0E83A5D06258B839D9F6F(__this, 0, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m61409D61652D42F5CF74FC5AAADA633296B77386_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mF83AE21E82590B5270938D4389B13BD6007F3C21_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		uint8_t L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m0AFABF6F1B3F0240ED564A30B2610DABA9881872(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m33CA38C7FB829721D3F92D6861FC7C64F9D06359_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mF6062BD01FB16E2976FE77274D3B42294B156F8D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mF83AE21E82590B5270938D4389B13BD6007F3C21(__this, ((*(uint8_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_mC729BF5765446BAF515DF85C53290E79FB004542_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_0 = ___0_array;
		List_1_CopyTo_mC3638F2FCF0162384166CDAD58E83F978A4781BD(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
// Method Definition Index: 11307
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_mA829BA58B34F17EE008D7D66468B478647866621(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_mEC84F6F0CB21DAC6F375246337DFC3AC1BE46173_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_0 = ___0_match;
		int32_t L_1;
		L_1 = List_1_FindIndex_m90942CB72E241DC275A09D90F31B0CAAA2301F15(__this, L_0, NULL);
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t List_1_Find_mB8FE9A3B0CE9D068BA318D91D79F17D1AD959C1E_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	uint8_t V_1 = 0;
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_1 = ___0_match;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		uint8_t L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		NullCheck(L_1);
		bool L_6;
		L_6 = Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_inline(L_1, L_5, NULL);
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		uint8_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		return L_10;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(uint8_t));
		uint8_t L_14 = V_1;
		return L_14;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m90942CB72E241DC275A09D90F31B0CAAA2301F15_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m98B9B243A5F21F0F6F288BC5D562F9D215769C08(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mB8A6CE6F383EBBD17A4A598B34214F751B516F29_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_startIndex, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_3 = ___1_match;
		int32_t L_4;
		L_4 = List_1_FindIndex_m98B9B243A5F21F0F6F288BC5D562F9D215769C08(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m98B9B243A5F21F0F6F288BC5D562F9D215769C08_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_10 = ___2_match;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		uint8_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_10);
		bool L_15;
		L_15 = Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mF565B9C8A6AC37D7D271406EBC1ABB384F6F5C4D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_2 = ___0_match;
		int32_t L_3;
		L_3 = List_1_FindLastIndex_m2943A682B3924333EEBA9CAA0CDC4FA2FCA17ADC(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_m2943A682B3924333EEBA9CAA0CDC4FA2FCA17ADC_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___2_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_11 = ___2_match;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		uint8_t L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_11);
		bool L_16;
		L_16 = Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_inline(L_11, L_15, NULL);
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_m0F32E17120D8BBE7D5D6C2932DEE4E8927A9089A_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4* ___0_action, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4* L_4 = ___0_action;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		uint8_t L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		Action_1_Invoke_m3F52CF20C1CBEFC2E57A2FBAD08312B7C5EA6ECF_inline(L_4, L_8, NULL);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0 List_1_GetEnumerator_m4CBEA4EB7D88F46A4ABCD7875C8F4F8E7FEC4A9B_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m146B47AAA47492A68DCB08165A6CBCD0A1E33AFF((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m96952353D27981F9BC2AA8ED773543EDF0A7B7C3_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m146B47AAA47492A68DCB08165A6CBCD0A1E33AFF((&L_0), __this, NULL);
		Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m17F60ABA796257F4E525FB0380AA833317D5585C_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m146B47AAA47492A68DCB08165A6CBCD0A1E33AFF((&L_0), __this, NULL);
		Enumerator_t00462E5D1FB821F6ADF1B6DE0F6FACA01D9A74F0 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* List_1_GetRange_mCC75E6EF704205E782A9F67051AEE7B2656D328F_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* L_6 = (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		List_1__ctor_m6584A1C860271ACE4B035721F88B0ED8F5C1FE56(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* L_9 = V_0;
		NullCheck(L_9);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m0AFABF6F1B3F0240ED564A30B2610DABA9881872_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_0 = __this->____items;
		uint8_t L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m8A7370BF306BED894DB61B836F0F21E9C835925C(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m3A251F7245CE90E14A0C856A177F783A779095AF_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mF6062BD01FB16E2976FE77274D3B42294B156F8D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m0AFABF6F1B3F0240ED564A30B2610DABA9881872(__this, ((*(uint8_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mCEA3676018EDF23B82BC33A722F2E704326D72C3_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, uint8_t ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		uint8_t L_16 = ___1_item;
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (uint8_t)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m896197065C5FD47E13C17B887843513513F9258C_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m1BCCAEF15531A89027A8C21D496867A6744E119A(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mCEA3676018EDF23B82BC33A722F2E704326D72C3(__this, L_1, ((*(uint8_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m169B03E44FA6B59F43486EEEA8E98C44F7B5751E_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
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
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t92E81A9A2159538A8E6169454F51D454A6093C75*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_20 = __this->____items;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck((RuntimeObject*)L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				uint8_t L_45;
				L_45 = InterfaceFuncInvoker0< uint8_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44);
				List_1_Insert_mCEA3676018EDF23B82BC33A722F2E704326D72C3(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck((RuntimeObject*)L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m426F79399C24D92B89DBA07ABF04AD125278169D(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m67007AD85DF53B4D7B867E20F7E6119867473640_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		uint8_t L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m0AFABF6F1B3F0240ED564A30B2610DABA9881872(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_mAAF9759F6A50882987B1159F163F34505DCD5ECF(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m64C62510649DAC17F8A2E6BAFAF341ED47A44B93_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mF6062BD01FB16E2976FE77274D3B42294B156F8D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_m67007AD85DF53B4D7B867E20F7E6119867473640(__this, ((*(uint8_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m3E9B3BA88BA433CD91640188C7C8D993A650EAEC_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_4 = ___0_match;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		uint8_t L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_4);
		bool L_9;
		L_9 = Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* L_16 = ___0_match;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		uint8_t L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_16);
		bool L_21;
		L_21 = Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		uint8_t L_31 = (L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_26), (uint8_t)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		goto IL_00ad;
	}

IL_00ad:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_0;
		int32_t L_36 = V_0;
		__this->____size = L_36;
		int32_t L_37 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_37, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mAAF9759F6A50882987B1159F163F34505DCD5ECF_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint8_t V_0 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		goto IL_0063;
	}

IL_0063:
	{
		int32_t L_11 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_11, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m7E4008D22F0A587981DB1FEBE440BF91A3DF2095_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		goto IL_008d;
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m84B62BC694E581F6516193E05CA860DCB2E58B31_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mE2A014D40D80B0243F6B9B41149E7D086E96900D_inline(__this, NULL);
		List_1_Reverse_m414E45C4A570B0CF6B4EAB3C057756A91F6C16EB(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m414E45C4A570B0CF6B4EAB3C057756A91F6C16EB_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_mBDC688B8984B71C25FF4A90AC54B59F47088C58A(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mF702CF4BCF65857D851EF79D55831DE217D8A763_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mE2A014D40D80B0243F6B9B41149E7D086E96900D_inline(__this, NULL);
		List_1_Sort_m92428DD612222174207D8E28F3A6D26B3E033F5D(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m6EA24CEC8DAAB0D2EB348CED045FA17C75E8187F_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mE2A014D40D80B0243F6B9B41149E7D086E96900D_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m92428DD612222174207D8E28F3A6D26B3E033F5D(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m92428DD612222174207D8E28F3A6D26B3E033F5D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_Tis__Il2CppByteEnum_t68E018163828EBAE5DA154A7FDE684D7ADCFA809_m7B400433E1797FA18AB1874F99F69E1009435A03(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m45E7FFC95A317E20A7444F00C6C4C7087858D2AB_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t11A2056E954E9BA6F20890493F7D416ED542258E* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_mD18D2E61AE0EE6FF9F52E820F4F829BB062466CB(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* List_1_ToArray_m165921B8C0A8BAFCA818C357389660F83E74E18F_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_1 = ((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_3 = (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)(__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_4 = __this->____items;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_m779C9A4DB3D9C24D5E404881A1754FC64F458A52_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		List_1_set_Capacity_mA829BA58B34F17EE008D7D66468B478647866621(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m426F79399C24D92B89DBA07ABF04AD125278169D_gshared (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
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
	uint8_t V_1 = 0;
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck((RuntimeObject*)L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				uint8_t L_6;
				L_6 = InterfaceFuncInvoker0< uint8_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m4743F262A7865788EFAABA31BBB5AB6E6656D41D(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				uint8_t L_15 = V_1;
				NullCheck(L_11);
				(L_11)->SetAt(static_cast<il2cpp_array_size_t>(L_14), (uint8_t)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck((RuntimeObject*)L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_m543471C413E9355B0241BDCC444054B5F03DDC99_gshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_0 = (__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)(__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t92E81A9A2159538A8E6169454F51D454A6093C75_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
// Method Definition Index: 11278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m0AFBAEA7EC427E32CC9CA267B1930DC5DF67A374_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m3069CACB5775E013107F559C825422266A09F9E8_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
// Method Definition Index: 11280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mACCB7726C2E9728AE336F99C68B334459F9F30FB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_6 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_8 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = __this->____items;
		NullCheck(L_9);
		InterfaceActionInvoker2< __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
// Method Definition Index: 11281
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Capacity_m5BE6D733C76E1AB093FB6D2783220A5B96EF61DF_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		return L_1;
	}
}
// Method Definition Index: 11282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mD365C22FA3D32D70A2088AB13116E7BA5FBF0BFB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_9 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_13 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
// Method Definition Index: 11283
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11284
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_get_IsFixedSize_m9BB85C4C7B3D227CAA4B56F531CCA9112C5FE801_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 11285
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_Generic_ICollectionU3CTU3E_get_IsReadOnly_m3F886C476FAC47C7E0B22BBEFA863E6E28CB6967_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 11286
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_get_IsReadOnly_m14CBA0E79745928530A7F91F920E3B29BF5977C2_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 11287
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_ICollection_get_IsSynchronized_m3F155097881E03657F32A11414B0E214B9356584_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 11288
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_ICollection_get_SyncRoot_m81521F85F116B00354BB0F726158451F3F1543F8_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = il2cpp_intrinsic_interlocked_compare_exchange(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11289
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_get_Item_m6E4BA37C1FB558E4A62AE4324212E45D09C5C937_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		il2cpp_codegen_memcpy(L_5, (L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(il2cppRetVal, L_5, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		return;
	}
}
// Method Definition Index: 11290
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9A958091885CC5363CCFE9F0BC472EAFCB56C813_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		il2cpp_codegen_memcpy(L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___1_value : &___1_value), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_2);
		il2cpp_codegen_memcpy((L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)), L_4, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)), (void*)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11291
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mF063A5AC0A6B869965B78A300A210C77D7D85A9E_fshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	memset(V_0, 0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInst((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
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
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(L_2, V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		bool L_3 = !il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), L_2);
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
// Method Definition Index: 11292
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m9468A95C180AB56C22EF37B808E722B82FA5DA1D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7), __this, L_0, (Il2CppFullySharedGenericAny*)L_1);
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_1);
		return L_2;
	}
}
// Method Definition Index: 11293
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m0F05BC227468EA87CF5E5E2D0707EFEDD6DB1D48_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(L_0, ((int32_t)15), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9), __this, L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_6 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11294
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mD4F3498FBD3BDD3F03CBCFB38041CBAC9C28CAFC_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_9 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	const Il2CppFullySharedGenericAny L_10 = L_9;
	//<source_info:<no-source>:1>
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = V_0;
		int32_t L_8 = V_1;
		il2cpp_codegen_memcpy(L_9, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_7);
		il2cpp_codegen_memcpy((L_7)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_8)), L_9, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_7)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_8)), (void*)L_9);
		return;
	}

IL_0034:
	{
		il2cpp_codegen_memcpy(L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_10: *(void**)L_10));
		return;
	}
}
// Method Definition Index: 11295
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mA6DFDBC2B22D6318212C6989A34784BD8303AF33_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		int32_t L_4 = V_0;
		il2cpp_codegen_memcpy(L_5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_3);
		il2cpp_codegen_memcpy((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)), L_5, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)), (void*)L_5);
		return;
	}
}
// Method Definition Index: 11296
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m16AFA75CCE3355CE51D428B0931951485666BF3D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(L_0, ((int32_t)20), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		void* L_3 = UnBox_Any(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_2);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_3)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_3))));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_4 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_5 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_5, L_7, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_8;
		L_8 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_8, 1));
	}
}
// Method Definition Index: 11297
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m44DED39FFEBC8F2ACF6162DB065B649E888B9C57_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
// Method Definition Index: 11298
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8* List_1_AsReadOnly_m7815E4F80542F2F7532AD847F4AA17739E5A7158_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8* L_0 = (ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		((  void (*) (ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 17)))(L_0, (RuntimeObject*)__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 11299
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m432056F077882449B26AE6759DEB4EECB8BB743E_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, Il2CppFullySharedGenericAny ___2_item, RuntimeObject* ___3_comparer, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		int32_t L_7 = ___1_count;
		il2cpp_codegen_memcpy(L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___2_item : &___2_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		RuntimeObject* L_9 = ___3_comparer;
		int32_t L_10;
		L_10 = InvokerFuncInvoker5< int32_t, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, Il2CppFullySharedGenericAny, RuntimeObject* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18), NULL, L_5, L_6, L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_8: *(void**)L_8), L_9);
		return L_10;
	}
}
// Method Definition Index: 11300
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m1A34A59B839C5FC7331DAA3F10BFCC8230174B15_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		int32_t L_2;
		L_2 = InvokerFuncInvoker4< int32_t, int32_t, int32_t, Il2CppFullySharedGenericAny, RuntimeObject* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19), __this, 0, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_1: *(void**)L_1), (RuntimeObject*)NULL);
		return L_2;
	}
}
// Method Definition Index: 11301
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_BinarySearch_m816AA1BC17CB3E2169E7E8E2DC777EE13B1CF439_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		RuntimeObject* L_2 = ___1_comparer;
		int32_t L_3;
		L_3 = InvokerFuncInvoker4< int32_t, int32_t, int32_t, Il2CppFullySharedGenericAny, RuntimeObject* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19), __this, 0, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_1: *(void**)L_1), L_2);
		return L_3;
	}
}
// Method Definition Index: 11302
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_mD615D1BCB2C9DD91DAD86A2F9E5CF1DFFCBF7925_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		bool L_1;
		L_1 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_2 = __this->____size;
		V_0 = L_2;
		__this->____size = 0;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		int32_t L_5 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_4, 0, L_5, NULL);
		return;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11303
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m8DA550B703DFB328B69C4712064C667D7CA33DF1_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		int32_t L_2;
		L_2 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_1: *(void**)L_1));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11304
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m20FD9B23AB202EAE6A3EBD3271A64B10BB21C5D9_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		bool L_5;
		L_5 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		return L_5;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11305
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m9632CAFAB9E06DBDE71886CC36E6C910F8350F9C_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_array;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_0, 0, NULL);
		return;
	}
}
// Method Definition Index: 11306
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_ICollection_CopyTo_mAAA2256D3B50B6A712DFB270B01B470759AB4FE9_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeArray* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (!L_0)
		{
			goto IL_0012;
		}
	}
	{
		RuntimeArray* L_1 = ___0_array;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0012:
	{
	}
	try
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		RuntimeArray* L_4 = ___0_array;
		int32_t L_5 = ___1_arrayIndex;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, L_4, L_5, L_6, NULL);
		goto IL_0031;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0029;
		}
		throw e;
	}

CATCH_0029:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_7 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0031;
	}

IL_0031:
	{
		return;
	}
}
// Method Definition Index: 11307
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
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
// Method Definition Index: 11308
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m0116C3A6AF6FB7DCF2E909AD859A0ADC86A60C66_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		NullCheck(L_3);
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_003d:
	{
		return;
	}
}
// Method Definition Index: 11309
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Exists_m4D844228EBB80F1DFE1D49094731494B09C2B4E8_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_0 = ___0_match;
		int32_t L_1;
		L_1 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 11310
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Find_m25CD37B5BB59793EBDF3A50F8B982947F7D84B11_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___0_match, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	const Il2CppFullySharedGenericAny L_10 = L_5;
	const Il2CppFullySharedGenericAny L_14 = L_5;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	memset(V_1, 0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_000d:
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_1 = ___0_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = V_0;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		il2cpp_codegen_memcpy(L_5, (L_2)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_4)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_1);
		bool L_6;
		L_6 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27), L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_5: *(void**)L_5));
		if (!L_6)
		{
			goto IL_002e;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = __this->____items;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		il2cpp_codegen_memcpy(L_10, (L_7)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_9)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(il2cppRetVal, L_10, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		return;
	}

IL_002e:
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0032:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____size;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}
	{
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_1, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(L_14, V_1, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(il2cppRetVal, L_14, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		return;
	}
}
// Method Definition Index: 11311
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mE810B96CFE4683761086D777FD5947FA66EA9255_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_1 = ___0_match;
		int32_t L_2;
		L_2 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_2;
	}
}
// Method Definition Index: 11312
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mC65D4C55FBE418F22B2356ECE4C0C5DD57D814A7_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_startIndex, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___1_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		int32_t L_2 = ___0_startIndex;
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_3 = ___1_match;
		int32_t L_4;
		L_4 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_0, ((int32_t)il2cpp_codegen_subtract(L_1, L_2)), L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_4;
	}
}
// Method Definition Index: 11313
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m63AAB8CE007CDF25CF1952FBF0F1FF7234695BD0_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___2_match, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_10 = ___2_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = __this->____items;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		il2cpp_codegen_memcpy(L_14, (L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_10);
		bool L_15;
		L_15 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_14: *(void**)L_14));
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11314
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mFD4CF7EBF3B162CECB31EC07527A12BE8835189B_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___0_match, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		int32_t L_1 = __this->____size;
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_2 = ___0_match;
		int32_t L_3;
		L_3 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)))(__this, ((int32_t)il2cpp_codegen_subtract(L_0, 1)), L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return L_3;
	}
}
// Method Definition Index: 11315
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindLastIndex_mF6E379672297CF3C1B401461A2AB681686AC50A0_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___2_match, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_0 = ___2_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		int32_t L_1 = __this->____size;
		if (L_1)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2 = ___0_startIndex;
		if ((((int32_t)L_2) == ((int32_t)(-1))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
		goto IL_002a;
	}

IL_001c:
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		if ((!(((uint32_t)L_3) >= ((uint32_t)L_4))))
		{
			goto IL_002a;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_002a:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_6 = ___0_startIndex;
		int32_t L_7 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_6, L_7)), 1))) >= ((int32_t)0)))
		{
			goto IL_003b;
		}
	}

IL_0036:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_003b:
	{
		int32_t L_8 = ___0_startIndex;
		int32_t L_9 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_8, L_9));
		int32_t L_10 = ___0_startIndex;
		V_1 = L_10;
		goto IL_005d;
	}

IL_0043:
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_11 = ___2_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = __this->____items;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		il2cpp_codegen_memcpy(L_15, (L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_14)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_11);
		bool L_16;
		L_16 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27), L_11, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_15: *(void**)L_15));
		if (!L_16)
		{
			goto IL_0059;
		}
	}
	{
		int32_t L_17 = V_1;
		return L_17;
	}

IL_0059:
	{
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
	}

IL_005d:
	{
		int32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) > ((int32_t)L_20)))
		{
			goto IL_0043;
		}
	}
	{
		return (-1);
	}
}
// Method Definition Index: 11316
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_ForEach_mA959944628050F666BD4CD147F51232EAC2E1B64_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Action_1_t923A20D1D4F6B55B2ED5AE21B90F1A0CE0450D99* ___0_action, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Action_1_t923A20D1D4F6B55B2ED5AE21B90F1A0CE0450D99* L_0 = ___0_action;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)33), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____version;
		V_0 = L_1;
		V_1 = 0;
		goto IL_0034;
	}

IL_0015:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____version;
		if ((!(((uint32_t)L_2) == ((uint32_t)L_3))))
		{
			goto IL_003d;
		}
	}
	{
		Action_1_t923A20D1D4F6B55B2ED5AE21B90F1A0CE0450D99* L_4 = ___0_action;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = __this->____items;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		il2cpp_codegen_memcpy(L_8, (L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_4);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_8: *(void**)L_8));
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0034:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0015;
		}
	}

IL_003d:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->____version;
		if ((((int32_t)L_12) == ((int32_t)L_13)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion_m5331E2E0EC0E36843D53F439C2529530595ACE9F(NULL);
	}

IL_004b:
	{
		return;
	}
}
// Method Definition Index: 11317
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_GetEnumerator_m8B2A92ACD4FBA5FBDC3F6F4F5C23A0DDF491DA61_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31));
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_0 = alloca(SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
	//<source_info:<no-source>:1>
	{
		memset(L_0, 0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		return;
	}
}
// Method Definition Index: 11318
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF8AB18BC6656CC469BFB6E837C001C2DE0833859_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31));
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_0 = alloca(SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
	//<source_info:<no-source>:1>
	{
		memset(L_0, 0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), L_0);
		return (RuntimeObject*)L_1;
	}
}
// Method Definition Index: 11319
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m83A6D1115899BF6BA842C33FE41FAD8D6EB43ED9_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31));
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_0 = alloca(SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
	//<source_info:<no-source>:1>
	{
		memset(L_0, 0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 31), L_0);
		return (RuntimeObject*)L_1;
	}
}
// Method Definition Index: 11320
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* List_1_GetRange_mBB92D8804DB148ED81D02A0CCA79968FFD71CAD4_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_6 = (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(L_6, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		V_0 = L_6;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_9 = V_0;
		NullCheck(L_9);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = L_9->____items;
		int32_t L_11 = ___1_count;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_7, L_8, (RuntimeArray*)L_10, 0, L_11, NULL);
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_12 = V_0;
		int32_t L_13 = ___1_count;
		NullCheck(L_12);
		L_12->____size = L_13;
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 11321
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m1FFA888B47CE3256B0AC301302FAD79AAAFC0818_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = InvokerFuncInvoker4< int32_t, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Il2CppFullySharedGenericAny, int32_t, int32_t >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_1: *(void**)L_1), 0, L_2);
		return L_3;
	}
}
// Method Definition Index: 11322
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_mF0601617A54C360278652B7AEE34E69F21B5ADDA_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		int32_t L_5;
		L_5 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		return L_5;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11323
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mB8862677E04375531A30F3EC07AC2372FCE61F55_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		il2cpp_codegen_memcpy(L_16, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___1_item : &___1_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_14);
		il2cpp_codegen_memcpy((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)), L_16, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15)), (void*)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
// Method Definition Index: 11324
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m3A5BCE3337DF64C89354C0CDF5DB4EE39A30BCA7_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(L_0, ((int32_t)20), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35), __this, L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_6 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11325
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m729639E2C8D1AA7579AC78D259085921E7DC72F2_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_45 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_20 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		NullCheck(L_31);
		InterfaceActionInvoker2< __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		NullCheck(L_38);
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					NullCheck((RuntimeObject*)L_41);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				NullCheck(L_44);
				InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_44, (Il2CppFullySharedGenericAny*)L_45);
				InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35), __this, L_43, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_45: *(void**)L_45));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				NullCheck((RuntimeObject*)L_46);
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
// Method Definition Index: 11326
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m9BCE8CEF94E6F2BF8624D65214FF4F3CA686D60C_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		int32_t L_1;
		L_1 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11327
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m69B0EB46209420A0DF794AE7598F8C3E02515509_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		bool L_5;
		L_5 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
	}

IL_0015:
	{
		return;
	}
}
// Method Definition Index: 11328
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m64ACE8FD442E00A79160BB070C0133B43A8C4075_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___0_match, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	const Il2CppFullySharedGenericAny L_20 = L_8;
	const Il2CppFullySharedGenericAny L_31 = L_8;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_4 = ___0_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = __this->____items;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		il2cpp_codegen_memcpy(L_8, (L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_4);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27), L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_16 = ___0_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_17 = __this->____items;
		int32_t L_18 = V_1;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		il2cpp_codegen_memcpy(L_20, (L_17)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_19)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_16);
		bool L_21;
		L_21 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27), L_16, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_20: *(void**)L_20));
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		NullCheck(L_27);
		int32_t L_30 = L_29;
		il2cpp_codegen_memcpy(L_31, (L_27)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_30)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_24);
		il2cpp_codegen_memcpy((L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)), L_31, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_24)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_26)), (void*)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		bool L_34;
		L_34 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_34)
		{
			goto IL_00ad;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_35 = __this->____items;
		int32_t L_36 = V_0;
		int32_t L_37 = __this->____size;
		int32_t L_38 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_35, L_36, ((int32_t)il2cpp_codegen_subtract(L_37, L_38)), NULL);
	}

IL_00ad:
	{
		int32_t L_39 = __this->____size;
		int32_t L_40 = V_0;
		int32_t L_41 = V_0;
		__this->____size = L_41;
		int32_t L_42 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_42, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_39, L_40));
	}
}
// Method Definition Index: 11329
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mF6C23E9072D8CBE2872705E7E4D08BDB78770F5C_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	memset(V_0, 0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		bool L_11;
		L_11 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_11)
		{
			goto IL_0063;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = __this->____items;
		int32_t L_13 = __this->____size;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(L_14, V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		NullCheck(L_12);
		il2cpp_codegen_memcpy((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)), L_14, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_13)), (void*)L_14);
	}

IL_0063:
	{
		int32_t L_15 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_15, 1));
		return;
	}
}
// Method Definition Index: 11330
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mCD6121D4FDE143767E6F0EC89183A9A349884DFF_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		bool L_19;
		L_19 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_19)
		{
			goto IL_008d;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_20 = __this->____items;
		int32_t L_21 = __this->____size;
		int32_t L_22 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_20, L_21, L_22, NULL);
	}

IL_008d:
	{
		return;
	}
}
// Method Definition Index: 11331
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m31924FC6445F9A1633DA40A8930F89E271B477F2_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42)))(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		return;
	}
}
// Method Definition Index: 11332
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m4F224F8A44C29751CCF7ED914FC00BFE7F27CD01_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		((  void (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43)))(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
// Method Definition Index: 11333
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m3B418BED64218204CAA69CD89BAA05CC12EB5EE6_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44)))(__this, 0, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11334
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mCBEFEE4479438557E591F7AEF3BFDE2297DA269D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44)))(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		return;
	}
}
// Method Definition Index: 11335
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m851B4290E563560C0037434A52D469666ABDE79D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		((  void (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45)))(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
// Method Definition Index: 11336
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mF939EF9300267AF108323ABAECB490A27894309B_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	//<source_info:<no-source>:1>
	{
		Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 47)),il2cpp_codegen_runtime_class_init_inline);
		((  void (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46)))(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
// Method Definition Index: 11337
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* List_1_ToArray_m5160526E5983BD8ED24DFFE47C33B141C1B3187A_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	//<source_info:<no-source>:1>
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 11338
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_TrimExcess_m915005BC7D68487C2006E5A31D87D1CAED751407_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		double L_2 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(((double)il2cpp_codegen_multiply(L_2, (0.90000000000000002))),NULL));
		V_0 = L_3;
		int32_t L_4 = __this->____size;
		int32_t L_5 = V_0;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_002a;
		}
	}
	{
		int32_t L_6 = __this->____size;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
	}

IL_002a:
	{
		return;
	}
}
// Method Definition Index: 11339
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mFD4E2919839A27C7CEACADF62222C63701302D02_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	const Il2CppFullySharedGenericAny L_15 = L_6;
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	memset(V_1, 0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 36), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					NullCheck((RuntimeObject*)L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 38), L_5, (Il2CppFullySharedGenericAny*)L_6);
				il2cpp_codegen_memcpy(V_1, L_6, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
				int32_t L_7 = __this->____size;
				__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_8 = __this->____items;
				NullCheck(L_8);
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				il2cpp_codegen_memcpy(L_15, V_1, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
				NullCheck(L_11);
				il2cpp_codegen_memcpy((L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_14)), L_15, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
				Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_11)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_14)), (void*)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				NullCheck((RuntimeObject*)L_16);
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
// Method Definition Index: 11340
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mFBD61154F711CE4EF252AA0B8B504EFC3E7E5B37_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m65F0731FF2C839C25530522F74BE029D34851222_inline (List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		Vector4U5BU5D_tC0F3A7115F85007510F6D173968200CD31BCF7AD* L_7 = V_0;
		int32_t L_8 = V_1;
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3)L_9);
		return;
	}

IL_0034:
	{
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_10 = ___0_item;
		List_1_AddWithResize_m3E361A77D2986AAB36EB748E177978BF014B3E20(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 11283
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m4AAEAD038F0A5CD547E8693E6E3BDD5F8F57CBD1_inline (Predicate_1_t5D3885F0B10D3F6345B19C0FFF8C67C14C7ECE1D* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m9293612C0DEA13BB9B5CADE956F799DE325BBD4B_inline (Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m8671BB7A955C16011966B029D9912C97256E551D_inline (List_1_tA7CAD0AC45F81CB3151C43DB534729898937504A* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_7 = V_0;
		int32_t L_8 = V_1;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_9);
		return;
	}

IL_0034:
	{
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_10 = ___0_item;
		List_1_AddWithResize_mC00103AF93A8667AEDB218D04F80F511F8194C9F(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m13DCD227FD7D0D810FEAA407EED268FA6657B152_inline (Predicate_1_t34FC9FE4137EF0639ABE9C1FEA3E718F546B3433* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m74BA9791568FC6CEE9D33F5F6135FB35B40FF1FA_inline (Action_1_t9EF2AA5703CAFAEF9B4B038F2B20639ACC29162C* __this, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m8733206CE9C292CC7AE372250D705ECD9BC11353_inline (List_1_tE320DA6F66936619F210A03F77F93803DCAB9355* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		WebshopExternalTokenU5BU5D_t79F14E066A7171FB15B0CEF937B3A2D4DD07B34D* L_7 = V_0;
		int32_t L_8 = V_1;
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286)L_9);
		return;
	}

IL_0034:
	{
		WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 L_10 = ___0_item;
		List_1_AddWithResize_m0CFF45D3EDB67B4F93F72B28293EACF735E2D915(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m5D0CF80E59CA9639A2D57953C15FCBEC3FF54188_inline (Predicate_1_tCF39765B0B8B783A79C31BDDF53961373C29CC67* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m77C7D2ACEEF9DF21BE26F4303BCFBEFEF8F7C764_inline (Action_1_t0E7E84C7E09437C22DF7D395E2C142BFCF062BC7* __this, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, WebshopExternalToken_t49418CE1A25E36B2F77D321FD4D098CE16A69286, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m1794A41080E7D990FC91C41044F40666784FAF5F_inline (List_1_t14F08D1F5A2E0F276F976F81CC13B7CB7EDABE33* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		X509ChainStatusU5BU5D_tA4CB502E13E6D62B9C824B15F3193FE7EC889299* L_7 = V_0;
		int32_t L_8 = V_1;
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D)L_9);
		return;
	}

IL_0034:
	{
		X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D L_10 = ___0_item;
		List_1_AddWithResize_m57CCC347F7A2D40306F42BE2E7822E13C0516E91(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m4A38FFF3029D79C03361DDE66EE04F9B75B961BD_inline (Predicate_1_tB2B4613BB6B50416AC05F114BE23CAB79DB2105B* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m4298A6EF344901142C650584A3B102A0582873A6_inline (Action_1_t8211FDBB28EEB761B566A466344EDAFA85BC3023* __this, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, X509ChainStatus_t5A57DDA24AA1FCA9F2B8D70B767CDDF388E4A80D, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m50157FAAF8FE0562A862140A17AD2B1097B078E7_inline (List_1_tB5E6131382BD8F3FB4090AD7EA52B72231DBDDCB* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		XRFeatureDescriptorU5BU5D_tBB735747E74DA05050B124BFE3525E40EC4114A7* L_7 = V_0;
		int32_t L_8 = V_1;
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2)L_9);
		return;
	}

IL_0034:
	{
		XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 L_10 = ___0_item;
		List_1_AddWithResize_m55AFD45DC0ADD64C8749E1B59252B0BF0793CE49(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m91BF5E52B5443EC259EE465ECFE80677DA340F98_inline (Predicate_1_tB9999C9C9C42FA89BBE6865404B6372BA3E8F5F5* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m14B5F0EFFF227D076151E00CACE917B6512254B8_inline (Action_1_tC8CC18F6848AAE74469E78A12EC004873F4332A7* __this, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, XRFeatureDescriptor_t690E672A6BBBEFBB8AF221485C1884507EAFB5B2, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m26A98FFE1090E98CCB9AA0278EC4017152C89F85_inline (List_1_t7B0B015A57215073C45C813320AF5F3ECF8149F7* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		XRViewU5BU5D_t46B2B3C0D45A670846E736AFB362448972CB513D* L_7 = V_0;
		int32_t L_8 = V_1;
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5)L_9);
		return;
	}

IL_0034:
	{
		XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 L_10 = ___0_item;
		List_1_AddWithResize_m940FD70455448D1B8E960B93BE1194188D09F786(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m2F90BCF2FEC7854C0CC6BBE2C4F57F9B48AE0385_inline (Predicate_1_tAC2079F7E6995DA080B0BA133041858D4D7709D0* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m1E148200B150317478F1EAF858AE3F230EB8D4AA_inline (Action_1_t10CDFD5B5E8466CFBE78033790678473EA484440* __this, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5 ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, XRView_t70E23918C68E24DB22A8614AA8717B3BA213FAB5, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = V_0;
		int32_t L_8 = V_1;
		Il2CppSharedGenericObject* L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (Il2CppSharedGenericObject*)L_9);
		return;
	}

IL_0034:
	{
		Il2CppSharedGenericObject* L_10 = ___0_item;
		List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_gshared_inline (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_gshared_inline (Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 11294
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m4950BFDE5379FB1EE9E82C2AA9E4631881DED88D_gshared_inline (List_1_t92E81A9A2159538A8E6169454F51D454A6093C75* __this, uint8_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__Il2CppByteEnumU5BU5D_t4D02DF3357DB0BD78CB7064114CAFFD248D6999A* L_7 = V_0;
		int32_t L_8 = V_1;
		uint8_t L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (uint8_t)L_9);
		return;
	}

IL_0034:
	{
		uint8_t L_10 = ___0_item;
		List_1_AddWithResize_m76095CD55E33211D69331C6DBF9A12AE1E1F544C(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 922
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m9EDCC4FC0BEE68AEE7B4161403FAB037CFE62743_gshared_inline (Predicate_1_t558D305E246D5642A24163DFCC957F53014AE626* __this, uint8_t ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef bool (*FunctionPointerType) (RuntimeObject*, uint8_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 884
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_m3F52CF20C1CBEFC2E57A2FBAD08312B7C5EA6ECF_gshared_inline (Action_1_tDBBAE587922AB83B3094F1CB9DB190A7C07324E4* __this, uint8_t ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, uint8_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
