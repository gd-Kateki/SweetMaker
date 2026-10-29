#include "pch-cpp.hpp"





template <typename T1, typename T2>
struct VirtualActionInvoker2
{
	typedef void (*Action)(void*,T1,T2,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
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
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
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
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		R ret;
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F;
struct Comparison_1_t49BE56523BDD8BC22EF3396960546FE16DE7B11A;
struct Data_tBBAC62CD211FDD01BE331E13953455EC5AD3E38F;
struct Data_tD43A0A802BBF284FB327878A445148A56180D7DA;
struct Data_tD47C5E63F8D3918FF6FA9D00969FF044D6E745FD;
struct Data_t9C4189912B5BDF1A4B9AF0427C56C087D271149E;
struct Data_t6F131ABB2DC3608FBC19EEE1D985484C670DE41A;
struct Data_tB029B7B0990880F555E53ED820E0D81226AED0F5;
struct Func_2_t0F26B920A10A91BFA7B07637902B13D306D6ACB2;
struct Func_2_t9622A5472E3EB564FD9AA65F9666F983FA8CA079;
struct Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577;
struct Func_2_tAD3C25E447E01C5173D4EF30C14D5F69437441FD;
struct List_1_tD2FA3273746E404D72561E8324608D18B52B533E;
struct List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B;
struct List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7;
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73;
struct List_1_t491347B1404617671B39DA9325642B0DB8748CB3;
struct List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268;
struct List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF;
struct List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317;
struct List_1_tF9F2510E1F31EAAB4FF93BF5D2FD123A1BA401D8;
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E;
struct List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255;
struct ObjectPool_1_t064DFEE48E51D3616541C16CD778864418851DCD;
struct ObjectPool_1_t2F51A95950390AEFC54568149DC9139A7741D679;
struct ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47;
struct RefCounted_t6B975CD3D06E8D955346FC0D66E8F6E449D49A44;
struct RefCounted_t0E133AD36715877AE1CE72539A0199B4D3AA8CD1;
struct RefCounted_t81BCBAE57D930C934CF7A439452D65303AC6A8CD;
struct RefCounted_t78303B1CD3D08C664ABB15EBD7C882DA3E06CF7D;
struct RefCounted_tA9FB4D63A1064BD322AFDFCD70319CB384C057D9;
struct RefCounted_t812D790A2C787F18230F9234F6C9B84D4AC1A85A;
struct CameraU5BU5D_t1506EBA524A07AD1066D6DD4D7DFC6721F1AC26B;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct EasingFunctionU5BU5D_t3EEBBFFAD92EA74C3960D5F78D2A98BCEEA62E49;
struct FilterFunctionU5BU5D_t6E250F0FE79D15DC0BB74D665DDF2EAD1ABE07B7;
struct MaterialPropertyValueU5BU5D_t90351D00AFCBDFC3053382B69DA7BE5169D3DB9F;
struct StylePropertyNameU5BU5D_t531626CF806E3F3D348D1F38A9109767014C35F8;
struct TimeValueU5BU5D_t3EB79C5975D39A0E711250FD8A9547F5312746DE;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericStructTypeU5BU5D_tF3B929B6E80D0A8C109178E11CE8FF9957B014C1;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184;
struct CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B;
struct CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7;
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
struct ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233;
struct DebugDisplaySettingsUI_t35C42FEE551C9AF153EA6DCE9CE3A07C3554F1E2;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct FilterFunctionDefinition_tFE41DB19FFB74F4D2B54BF44D1D2051B57FC82F2;
struct GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB;
struct GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B;
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
struct GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct IntPtr_t;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct MotionVectorsPersistentData_t077A3BA28B75576C897E6C794FE0ABF9DB8EBBBB;
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
struct ProfilingSampler_t420D4672EDB44E0EF980B31ADFD9E5747200FECE;
struct RTHandleResourcePool_tB08B48917D5F811C85F6DDF0D751436D366CEF7A;
struct RenderGraph_t73ECE03B3CA3D0D17F1448D64AE020E81592AA1E;
struct RenderGraphPass_tEFB5BD685D417024760D82991EEEA4F4D0454A93;
struct RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27;
struct String_t;
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700;
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
struct Type_t;
struct UniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93;
struct UniversalCameraHistory_t15D275DAE9AD5B608CE533D0FCE0884F07BB1E80;
struct UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F;
struct UniversalRenderPipelineAsset_tE8A9AA6F030CC3B558CEA2EB54FFF4FC58CA6232;
struct UniversalRenderPipelineGlobalSettings_t895E975CCCA62A6DE4F820C0109953EF6D83B9F0;
struct UniversalRenderPipelineRuntimeTextures_tDA15F1E9BFCD85610D963AC723C03EB214D1EB86;
struct UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2;
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926;
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C;
struct VisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct VolumeStack_t5DE94743BDB63D97EF5587DBDAE46468233F36E8;
struct CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD;
struct Info_tDBEB127ABB26184014A541C0CAD1FC8D1B95DE84;
struct RequestLightsDelegate_t585505A75681754DA53BE119D8611B605F0243BB;
struct StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53;
struct SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24;
struct EqualityComparer_tF8FCE99C5DBB2F35D74728CB65346435381CFD5B;

IL2CPP_EXTERN_C RuntimeClass* Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ListPool_1_t97F6AE398781016115DBD2B6A4A443FD4FF438E6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tD2FA3273746E404D72561E8324608D18B52B533E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral48B5843525C3BEF16B7BE787788398005CFE4D6C;
IL2CPP_EXTERN_C String_t* _stringLiteral51A257776A6F5C5A85BB79B0C0B56E420A4C92B6;
IL2CPP_EXTERN_C String_t* _stringLiteral80F0368CFBC6552AC1C79FAE29101F4E1345BD2A;
IL2CPP_EXTERN_C String_t* _stringLiteralB8468D10D94786B5C421B4ACD80BF46EAAA054DD;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_TryGetComponent_TisUniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93_mBCAEF774AB0C0563A29C16F3A5305AE1A081C3BD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ListPool_1_Get_m7E32B4B150CCC0A396B9CFA7D60862F765DE7C15_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m9BE0CD6DB63BFCBCBD5619618748924143F1AFAD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m735F7A05528CC71E71E3019311F2E22CF9E2C681_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PooledObject_System_IDisposable_Dispose_m2C53DF93B31EF48C987A0FD22DEE119FDDD30E93_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_0_0_0_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct List_1_tD2FA3273746E404D72561E8324608D18B52B533E  : public RuntimeObject
{
	CameraU5BU5D_t1506EBA524A07AD1066D6DD4D7DFC6721F1AC26B* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B  : public RuntimeObject
{
	EasingFunctionU5BU5D_t3EEBBFFAD92EA74C3960D5F78D2A98BCEEA62E49* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7  : public RuntimeObject
{
	FilterFunctionU5BU5D_t6E250F0FE79D15DC0BB74D665DDF2EAD1ABE07B7* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t491347B1404617671B39DA9325642B0DB8748CB3  : public RuntimeObject
{
	MaterialPropertyValueU5BU5D_t90351D00AFCBDFC3053382B69DA7BE5169D3DB9F* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268  : public RuntimeObject
{
	StylePropertyNameU5BU5D_t531626CF806E3F3D348D1F38A9109767014C35F8* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF  : public RuntimeObject
{
	TimeValueU5BU5D_t3EB79C5975D39A0E711250FD8A9547F5312746DE* ____items;
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
struct List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4  : public RuntimeObject
{
	__Il2CppFullySharedGenericStructTypeU5BU5D_tF3B929B6E80D0A8C109178E11CE8FF9957B014C1* ____items;
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
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255  : public RuntimeObject
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06  : public RuntimeObject
{
	CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* ___m_WrappedCommandBuffer;
	RenderGraphPass_tEFB5BD685D417024760D82991EEEA4F4D0454A93* ___m_ExecutingPass;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct RenderPipeline_t3AF1E2046D27ABCEBA2279770AADA9F531073E69  : public RuntimeObject
{
	bool ___U3CdisposedU3Ek__BackingField;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct UnmanagedRefCountedListExtensions_tB999F9C3077EECD226CF96B133B380A21606C11C  : public RuntimeObject
{
};
struct Unsafe_t1B60DB2A3A2A631E537D045BDF121ECE5B06A3A0  : public RuntimeObject
{
};
struct Unsafe_t013486CBD5A88F5F394651AB34F2AC5AE97E71E4  : public RuntimeObject
{
};
struct UnsafeListExtensions_t9F27C0DDB39954D821115ACDC913DC77BCAC720A  : public RuntimeObject
{
};
struct UnsafePtrListExtensions_t26A84137ED878FA51C011CDA9A68E2B7FD40E6CA  : public RuntimeObject
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
struct AlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE 
{
	uint8_t ___dummy;
	int32_t ___data;
};
struct KeyValue_2_t6CF850BB70347624D35C74018B4BBBAE4CED68AB 
{
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___m_Buffer;
	int32_t ___m_Index;
	int32_t ___m_Next;
};
struct ParallelReader_tE9E5B90E22A4BC77DB4B327155E0A9F071FC4839 
{
	Il2CppFullySharedGenericStruct* ___Ptr;
	int32_t ___Length;
};
struct PooledObject_t6A17503D2E86923ADABDFFE03F1EA5163EAF076B 
{
	List_1_tD2FA3273746E404D72561E8324608D18B52B533E* ___m_ToReturn;
	ObjectPool_1_t064DFEE48E51D3616541C16CD778864418851DCD* ___m_Pool;
};
struct PooledObject_tAF29EF4F652282CE220188D9C8727C721E60336D 
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___m_ToReturn;
	ObjectPool_1_t2F51A95950390AEFC54568149DC9139A7741D679* ___m_Pool;
};
struct PooledObject_t42DFE6F40709CEDB91999103D5FA096C28E0A1DD 
{
	Il2CppSharedGenericObject* ___m_ToReturn;
	ObjectPool_1_tB01A360159214F30397EC893BAAA14B3205B7C47* ___m_Pool;
};
struct ReadOnly_t620C834D6C54D781225D753876F232E09821956C 
{
	Il2CppFullySharedGenericStruct* ___Ptr;
	int32_t ___Length;
};
struct StyleDataRef_1_tBB9987581539847AE5CCA2EA2349E05CDC9127FA 
{
	RefCounted_t6B975CD3D06E8D955346FC0D66E8F6E449D49A44* ___m_Ref;
};
struct StyleDataRef_1_t5330A6F4EAC0EAB88E3B9849D866AA23BB6BE5F4 
{
	RefCounted_t0E133AD36715877AE1CE72539A0199B4D3AA8CD1* ___m_Ref;
};
struct StyleDataRef_1_tF773E9CBC6DC0FEB38DF95A6F3F47AC49AE045B3 
{
	RefCounted_t81BCBAE57D930C934CF7A439452D65303AC6A8CD* ___m_Ref;
};
struct StyleDataRef_1_t1D59CCAB740BE6B330D5B5FDA9F67391800200B3 
{
	RefCounted_t78303B1CD3D08C664ABB15EBD7C882DA3E06CF7D* ___m_Ref;
};
struct StyleDataRef_1_t6A7B146DD79EDF7F42CD8CCF3E411B40AA729B8E 
{
	RefCounted_tA9FB4D63A1064BD322AFDFCD70319CB384C057D9* ___m_Ref;
};
struct StyleDataRef_1_t9CB834B90E638D92A3BE5123B0D3989697AA87FC 
{
	RefCounted_t812D790A2C787F18230F9234F6C9B84D4AC1A85A* ___m_Ref;
};
struct UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 
{
	union
	{
		struct
		{
			Data_tBBAC62CD211FDD01BE331E13953455EC5AD3E38F* ___m_Data;
		};
		uint8_t UnmanagedRefCountedList_1_t422A4815A59948FB5060BB10CB6D6DC9F24D2948__padding[8];
	};
};
struct UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE 
{
	union
	{
		struct
		{
			Data_tD43A0A802BBF284FB327878A445148A56180D7DA* ___m_Data;
		};
		uint8_t UnmanagedRefCountedList_1_t422A4815A59948FB5060BB10CB6D6DC9F24D2948__padding[8];
	};
};
struct UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 
{
	union
	{
		struct
		{
			Data_tD47C5E63F8D3918FF6FA9D00969FF044D6E745FD* ___m_Data;
		};
		uint8_t UnmanagedRefCountedList_1_t422A4815A59948FB5060BB10CB6D6DC9F24D2948__padding[8];
	};
};
struct UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 
{
	union
	{
		struct
		{
			Data_t9C4189912B5BDF1A4B9AF0427C56C087D271149E* ___m_Data;
		};
		uint8_t UnmanagedRefCountedList_1_t422A4815A59948FB5060BB10CB6D6DC9F24D2948__padding[8];
	};
};
struct UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC 
{
	union
	{
		struct
		{
			Data_t6F131ABB2DC3608FBC19EEE1D985484C670DE41A* ___m_Data;
		};
		uint8_t UnmanagedRefCountedList_1_t422A4815A59948FB5060BB10CB6D6DC9F24D2948__padding[8];
	};
};
struct UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC 
{
	union
	{
		struct
		{
			Data_tB029B7B0990880F555E53ED820E0D81226AED0F5* ___m_Data;
		};
		uint8_t UnmanagedRefCountedList_1_t422A4815A59948FB5060BB10CB6D6DC9F24D2948__padding[8];
	};
};
struct BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 
{
	uint32_t ___value;
};
struct BatchMaterialID_tF9E95833BB1C35A6D14D47CF4EC8A6EB7D15D65C 
{
	uint32_t ___value;
};
struct BatchMeshID_t34167B7C1D0503C43A01A7BD213DFC367525D2A0 
{
	uint32_t ___value;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	float ___r;
	float ___g;
	float ___b;
	float ___a;
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
#pragma pack(push, tp, 1)
struct FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					uint64_t ___byte0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					uint64_t ___byte0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0008_OffsetPadding[8];
					uint64_t ___byte0008;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0008_OffsetPadding_forAlignmentOnly[8];
					uint64_t ___byte0008_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4__padding[16];
	};
};
#pragma pack(pop, tp)
struct GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB 
{
	int16_t ___U3CindexU3Ek__BackingField;
};
struct GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 
{
	int16_t ___U3CindexU3Ek__BackingField;
};
struct GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB 
{
	uint64_t ___U3CcomponentsMaskU3Ek__BackingField;
};
struct GPUDrivenMaterialData_t1834AD299C8285768A90D366285F54ED98BE98B0 
{
	uint32_t ___data;
};
struct GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 
{
	int32_t ___U3CindexU3Ek__BackingField;
};
struct GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 
{
	int32_t ___index;
};
struct InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B 
{
	int32_t ___U3CindexU3Ek__BackingField;
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
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB 
{
	int32_t ___m_Mask;
};
struct LayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4 
{
	float ___PointScaleFactor;
	int32_t ___ManagedMeasureFunctionIndex;
	int32_t ___ManagedBaselineFunctionIndex;
	bool ___ShouldLog;
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
struct ShaderTagId_t453E2085B5EE9448FF75E550CAB111EFF690ECB0 
{
	int32_t ___m_Id;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct UIntPtr_t 
{
	void* ____pointer;
};
struct UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F  : public RenderPipeline_t3AF1E2046D27ABCEBA2279770AADA9F531073E69
{
	DebugDisplaySettingsUI_t35C42FEE551C9AF153EA6DCE9CE3A07C3554F1E2* ___m_DebugDisplaySettingsUI;
	UniversalRenderPipelineGlobalSettings_t895E975CCCA62A6DE4F820C0109953EF6D83B9F0* ___m_GlobalSettings;
	UniversalRenderPipelineRuntimeTextures_tDA15F1E9BFCD85610D963AC723C03EB214D1EB86* ___U3CruntimeTexturesU3Ek__BackingField;
	bool ___apvIsEnabled;
	UniversalRenderPipelineAsset_tE8A9AA6F030CC3B558CEA2EB54FFF4FC58CA6232* ___pipelineAsset;
	bool ___enableHDROutputOnce;
	bool ___warnedRuntimeSwitchHDROutputToSDROutput;
	Comparison_1_t49BE56523BDD8BC22EF3396960546FE16DE7B11A* ___cameraComparison;
};
struct UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 
{
	int32_t ___Size;
	int32_t ___Align;
};
struct UnmanagedDataHandle_t5295F32E122AF2E09BF729381A22BD86B72C1DD1 
{
	int32_t ___Index;
	int32_t ___Version;
};
struct UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2  : public BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06
{
};
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t* ___values;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t* ___values_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keys_OffsetPadding[8];
			uint8_t* ___keys;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keys_OffsetPadding_forAlignmentOnly[8];
			uint8_t* ___keys_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___next_OffsetPadding[16];
			uint8_t* ___next;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___next_OffsetPadding_forAlignmentOnly[16];
			uint8_t* ___next_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___buckets_OffsetPadding[24];
			uint8_t* ___buckets;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___buckets_OffsetPadding_forAlignmentOnly[24];
			uint8_t* ___buckets_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keyCapacity_OffsetPadding[32];
			int32_t ___keyCapacity;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keyCapacity_OffsetPadding_forAlignmentOnly[32];
			int32_t ___keyCapacity_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding[36];
			int32_t ___bucketCapacityMask;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding_forAlignmentOnly[36];
			int32_t ___bucketCapacityMask_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding[40];
			int32_t ___allocatedIndexLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding_forAlignmentOnly[40];
			int32_t ___allocatedIndexLength_forAlignmentOnly;
		};
	};
};
struct UnsafeParallelHashMapDataEnumerator_t8CD0B557DE7804D4ED6A5599D87CC889C2DDA4F5 
{
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___m_Buffer;
	int32_t ___m_Index;
	int32_t ___m_BucketIndex;
	int32_t ___m_NextIndex;
};
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C 
{
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___m_NextBlock;
	int32_t ___m_NumItems;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
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
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct U3CBorderU3Ee__FixedBuffer_t5A18296AB7D0BFC3131BDDE01656A53889147B34 
{
	union
	{
		struct
		{
			float ___FixedElementField;
		};
		uint8_t U3CBorderU3Ee__FixedBuffer_t5A18296AB7D0BFC3131BDDE01656A53889147B34__padding[24];
	};
};
struct U3CDimensionsU3Ee__FixedBuffer_tD2708ED4F2A6D227404834E91D6359AB4B954457 
{
	union
	{
		struct
		{
			float ___FixedElementField;
		};
		uint8_t U3CDimensionsU3Ee__FixedBuffer_tD2708ED4F2A6D227404834E91D6359AB4B954457__padding[8];
	};
};
struct U3CMarginU3Ee__FixedBuffer_tF5EF7606FDD9ACD4DDF18DC564195092A6A540FE 
{
	union
	{
		struct
		{
			float ___FixedElementField;
		};
		uint8_t U3CMarginU3Ee__FixedBuffer_tF5EF7606FDD9ACD4DDF18DC564195092A6A540FE__padding[24];
	};
};
struct U3CMeasuredDimensionsU3Ee__FixedBuffer_t3BF016D1583A3A9EABAD62B35368C369C06DCD87 
{
	union
	{
		struct
		{
			float ___FixedElementField;
		};
		uint8_t U3CMeasuredDimensionsU3Ee__FixedBuffer_t3BF016D1583A3A9EABAD62B35368C369C06DCD87__padding[8];
	};
};
struct U3CPaddingU3Ee__FixedBuffer_tE057FF067DA31EB3EC92DD01973C24BDC7E9E9F3 
{
	union
	{
		struct
		{
			float ___FixedElementField;
		};
		uint8_t U3CPaddingU3Ee__FixedBuffer_tE057FF067DA31EB3EC92DD01973C24BDC7E9E9F3__padding[24];
	};
};
struct U3CPositionU3Ee__FixedBuffer_t6F7472507E4B67C5CA936393DFFBA95309592810 
{
	union
	{
		struct
		{
			float ___FixedElementField;
		};
		uint8_t U3CPositionU3Ee__FixedBuffer_t6F7472507E4B67C5CA936393DFFBA95309592810__padding[16];
	};
};
struct LodSelectionCurve_t5E3F99BC782C22E828074538B8B43051FF859713 
{
	float ___m_LodSlope;
	float ___m_LodBias;
};
struct AlignOfHelper_1_t12EA8BB9031D0D42734685DAB3E0DC8CDE6F7844 
{
	uint8_t ___dummy;
	LayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4 ___data;
};
struct ByReference_1_tA7F58D709342B3D9D7560427019EB2E4432E1EDA 
{
	intptr_t ____value;
};
struct ByReference_1_t64E7DFCAC850E17580FFC701DCC09E55B59DFCED 
{
	intptr_t ____value;
};
struct ByReference_1_t2B449216F5B5D49DCF8CF206F54068606AE5D055 
{
	intptr_t ____value;
};
struct ByReference_1_t2A8E151FD116590E2F37794ACDBC2BFDC6B85C3B 
{
	intptr_t ____value;
};
struct ByReference_1_t2665E4A68FBF39DF6EE63D3D6950D90834502840 
{
	intptr_t ____value;
};
struct ByReference_1_t21C88CEA3607E6DA2435F0E317C10A776BCA6DCC 
{
	intptr_t ____value;
};
struct ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 
{
	intptr_t ____value;
};
struct ByReference_1_t3747EBE8AAD37F6624BB0D1E61ED7CB5FCD6655E 
{
	intptr_t ____value;
};
struct UnsafeList_1_t5C65DCA6782B7C9860C859C2F0C07A2C497E822D 
{
	uint8_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E 
{
	GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t5F75981CEC17C7EAE94180B0C9C63C260D6D1B3C 
{
	GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 
{
	intptr_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6 
{
	Il2CppFullySharedGenericStruct* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_tBB6961066733E78B8C22E5C4D4D5FF9A581981D1 
{
	Info_tDBEB127ABB26184014A541C0CAD1FC8D1B95DE84* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafePtrList_1_tA37C18AF110F20C6437047DBA50BF355602044E5 
{
	Il2CppFullySharedGenericStruct** ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct AntialiasingMode_tDF75AC7BDAF51FA550F528F7B798416ACB8D3487 
{
	int32_t ___value__;
};
struct AntialiasingQuality_t45B2A050F79EB8B705FED3F3F30A70942E71D605 
{
	int32_t ___value__;
};
struct AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 
{
	intptr_t ___m_Ptr;
	int32_t ___m_Version;
};
struct BatchDrawCommandFlags_tC502FA322382A3181F0800B1EA5A5654027FE034 
{
	int32_t ___value__;
};
struct CameraOverrideOption_tFE4F529A065C94484CFF2D27D4D7D2D8ADB145A9 
{
	int32_t ___value__;
};
struct CameraRenderType_tC686ABD18F67CA30E6DF217007744F509606A41D 
{
	int32_t ___value__;
};
struct CameraType_tCA1017DBE96964E1D967942FB98F152F14121FCD 
{
	int32_t ___value__;
};
struct CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7  : public RuntimeObject
{
	intptr_t ___m_Ptr;
};
struct ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233  : public RuntimeObject
{
	intptr_t ___m_Ptr;
};
struct CopyTextureSupport_t4EFE718FA2FC4A185D5011E063FAA1249550C644 
{
	int32_t ___value__;
};
struct CubemapFace_t300D6E2CD7DF60D44AA28338748B607677ED1D1B 
{
	int32_t ___value__;
};
struct CustomPropertyList_t48CD7F57B3FAE18133914CE45C38B1B6620A9B3A 
{
	intptr_t ___m_Data;
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
struct EasingMode_tEF87477B9B9EB2524525550AE5ABEBC00FC7B0DF 
{
	int32_t ___value__;
};
struct FilterFunctionType_tF29290365A61009BE6F2EF6C6C6218E72CB9F64A 
{
	int32_t ___value__;
};
struct FilterParameterType_t7250262A78079140235AAFF6F4FA3CCB2F99E390 
{
	int32_t ___value__;
};
#pragma pack(push, tp, 1)
struct FixedBytes64Align8_t84631A2A3E4A6CEF77C84D9B630BDF9720B945E1 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0016_OffsetPadding[16];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0016;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0016_OffsetPadding_forAlignmentOnly[16];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0016_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0032_OffsetPadding[32];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0032;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0032_OffsetPadding_forAlignmentOnly[32];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0032_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0048_OffsetPadding[48];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0048;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0048_OffsetPadding_forAlignmentOnly[48];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0048_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes64Align8_t84631A2A3E4A6CEF77C84D9B630BDF9720B945E1__padding[64];
	};
};
#pragma pack(pop, tp)
struct GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 
{
	BatchMaterialID_tF9E95833BB1C35A6D14D47CF4EC8A6EB7D15D65C ___materialID;
	GPUDrivenMaterialData_t1834AD299C8285768A90D366285F54ED98BE98B0 ___data;
};
struct GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1  : public RuntimeObject
{
	intptr_t ___m_Ptr;
};
struct GraphicsFormat_tC3D1898F3F3F1F57256C7F3FFD6BA9A37AE7E713 
{
	int32_t ___value__;
};
struct LODParameters_t54D2AA0FD8E53BCF51D7A42BC1A72FCA8C78A08A 
{
	int32_t ___m_IsOrthographic;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_CameraPosition;
	float ___m_FieldOfView;
	float ___m_OrthoSize;
	int32_t ___m_CameraPixelHeight;
};
struct LayoutDirection_t497B5D8A2EDA4BB4E634A27164FFE3DE67250D32 
{
	int32_t ___value__;
};
struct LayoutMeasureMode_tF611505DD74982A0B40646994C952A094E98FB30 
{
	int32_t ___value__;
};
struct LayoutUnit_tF18EC17FE8588A01C72784546410EA0D9B1D2F22 
{
	int32_t ___value__;
};
struct MaterialPropertyValueType_t3AE79BF4BF4F82EFA7E2ED2CB4EC5BAB096BC5A8 
{
	int32_t ___value__;
};
struct MotionVectorGenerationMode_tE87C61556749260EF5429A0F8FE55DAD30EEAFCB 
{
	int32_t ___value__;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct PanelTransformFlags_t433468719911123F7343DB3FA8BB22533A0C6E86 
{
	int32_t ___value__;
};
struct PseudoStates_tF4AB056E8743741BCE464A0983A060A53AAB7E4D 
{
	int32_t ___value__;
};
struct RenderTextureCreationFlags_t1C01993691E5BA956575134696509089FE852F50 
{
	int32_t ___value__;
};
struct RenderTextureFormat_tB6F1ED5040395B46880CE00312D2FDDBF9EEB40F 
{
	int32_t ___value__;
};
struct RenderTextureMemoryless_tE3B7F3AE353C3E9ACF86076376EB862131D19A69 
{
	int32_t ___value__;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 
{
	intptr_t ___m_Ptr;
};
struct ShadowCastingMode_tF30806698B37CF120A1A506BD7549EAF308E7C6D 
{
	int32_t ___value__;
};
struct ShadowSamplingMode_t8BE740C4258CFEDDBAC01FDC0438D8EE3F776BA8 
{
	int32_t ___value__;
};
struct StylePropertyId_tA3B8A5213F5BA43F9C5443B27B165D744713BE69 
{
	int32_t ___value__;
};
struct TemporalAAQuality_t03A8B3F777D54108A9CE21E79AB4C022968AD5F5 
{
	int32_t ___value__;
};
struct TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642 
{
	int32_t ___value__;
};
struct TextureFormat_t87A73E4A3850D3410DC211676FC14B94226C1C1D 
{
	int32_t ___value__;
};
struct TimeUnit_t56A79CDB672E98A4EE28002BD23B6D5E0BAA2649 
{
	int32_t ___value__;
};
struct UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500 
{
	uint8_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___Alignment;
};
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2 
{
	intptr_t ___m_FirstBlock;
	intptr_t ___m_LastBlock;
	int32_t ___m_MaxItems;
	int32_t ___m_CurrentRead;
	uint8_t* ___m_CurrentWriteBlockTLS;
};
struct VRTextureUsage_t57FAA0077810142A461D74EDC5E33FC3D78BD2E8 
{
	int32_t ___value__;
};
struct VisualElementTransformFlags_t47F836489394ED28F75EAD7C76A8F70FAB5E4A10 
{
	int32_t ___value__;
};
struct VolumeFrameworkUpdateMode_tCD9A8BEF3700F3AA490F1BB39EF8A88E94398627 
{
	int32_t ___value__;
};
struct AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___cameraID;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___jobHandle;
};
struct FlexStatus_tBEE27C88EDAE5A3F57C0AAFC4D1A650610B2CF5C 
{
	int32_t ___value__;
};
struct Version_t8FE0D25C0F2D4540648156EC04916E1EA8F1ACDC 
{
	int32_t ___value__;
};
struct FixedList64Bytes_1_tA8137DDBE902BF483FBBDB59365917992EA9F670 
{
	alignas(8) FixedBytes64Align8_t84631A2A3E4A6CEF77C84D9B630BDF9720B945E1 ___data;
};
struct NativeArray_1_t60C2883F9133642CF381234B3DD254605DD4F0A5 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t107C57D0357BCF9956A60495CD8FAADDF1D26AFB 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t2FF0F1BBD323229A2F9ABD52397EA6EF9B105E09 
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
struct NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tB58D1BE7997E66C484A0FCC487D9A3D3A7D31AEC 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tAA41AE8C464559D1987285B6F1D42333CD5EC15B 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t727E0B11B40EA7D6477F67D79DA7B7F7C383735E 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t703E60DA65EBF076EB4916D3B9D9987A5A09B9CC 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t8E042B4249B3126F27EE49887D2507798DC25F2C 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tFCAF9979C15E15C78F0F78DB34559D880F381CEE 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t8E236FFFE7B598011354300BFCED0A15647BBC5D 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184 
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
struct NativeArray_1_t497DD754C21E03BAC4C1F2BB7A3BB0025FF4EB88 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t251C0B6A4D277C92366F302523FD5C0031FA1B31 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct ReadOnlySpan_1_t56EB56BD24E849B1A28025A5D541442A2AB282E7 
{
	ByReference_1_tA7F58D709342B3D9D7560427019EB2E4432E1EDA ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tA7B55DDCFA4B3B474C0F1DCFCEADB2ABB0EC8F10 
{
	ByReference_1_t64E7DFCAC850E17580FFC701DCC09E55B59DFCED ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tA8945E8A02F969385193C34AFA893BCE779E5C80 
{
	ByReference_1_t2B449216F5B5D49DCF8CF206F54068606AE5D055 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tA7A09B5CBD9955114DF1BD8B2A082233FE91641C 
{
	ByReference_1_t2A8E151FD116590E2F37794ACDBC2BFDC6B85C3B ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t3CCF29C77768AF4EE7E6D7C30578D3084881DD85 
{
	ByReference_1_t2665E4A68FBF39DF6EE63D3D6950D90834502840 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 
{
	ByReference_1_t21C88CEA3607E6DA2435F0E317C10A776BCA6DCC ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC 
{
	ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tDFED1E92751A6EBC762EDE852E1ABE93EC8EFC7E 
{
	ByReference_1_t3747EBE8AAD37F6624BB0D1E61ED7CB5FCD6655E ____pointer;
	int32_t ____length;
};
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct ComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C 
{
	StyleDataRef_1_tBB9987581539847AE5CCA2EA2349E05CDC9127FA ___inheritedData;
	StyleDataRef_1_t5330A6F4EAC0EAB88E3B9849D866AA23BB6BE5F4 ___layoutData;
	StyleDataRef_1_tF773E9CBC6DC0FEB38DF95A6F3F47AC49AE045B3 ___rareData;
	StyleDataRef_1_t1D59CCAB740BE6B330D5B5FDA9F67391800200B3 ___transformData;
	StyleDataRef_1_t6A7B146DD79EDF7F42CD8CCF3E411B40AA729B8E ___transitionData;
	StyleDataRef_1_t9CB834B90E638D92A3BE5123B0D3989697AA87FC ___visualData;
	CustomPropertyList_t48CD7F57B3FAE18133914CE45C38B1B6620A9B3A ___m_CustomProperties;
	int64_t ___matchingRulesHash;
	float ___dpiScaling;
};
struct EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4 
{
	int32_t ___m_Mode;
};
struct FilterParameter_tC6BAE67835BA35634A769B28BF35314AF42BE060 
{
	int32_t ___m_Type;
	float ___m_FloatValue;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_ColorValue;
};
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct LayoutCachedMeasurement_tAEC7D318B47741D367D20EE2065A358062325CF0 
{
	float ___AvailableWidth;
	float ___AvailableHeight;
	float ___ParentWidth;
	float ___ParentHeight;
	int32_t ___WidthMeasureMode;
	int32_t ___HeightMeasureMode;
	float ___ComputedWidth;
	float ___ComputedHeight;
	void* ___m_NextMeasurementCachePtr;
};
struct LayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1 
{
	U3CPositionU3Ee__FixedBuffer_t6F7472507E4B67C5CA936393DFFBA95309592810 ___Position;
	U3CDimensionsU3Ee__FixedBuffer_tD2708ED4F2A6D227404834E91D6359AB4B954457 ___Dimensions;
	U3CMarginU3Ee__FixedBuffer_tF5EF7606FDD9ACD4DDF18DC564195092A6A540FE ___Margin;
	U3CBorderU3Ee__FixedBuffer_t5A18296AB7D0BFC3131BDDE01656A53889147B34 ___Border;
	U3CPaddingU3Ee__FixedBuffer_tE057FF067DA31EB3EC92DD01973C24BDC7E9E9F3 ___Padding;
	int32_t ___Direction;
	uint32_t ___ComputedFlexBasisGeneration;
	float ___ComputedFlexBasis;
	bool ___HadOverflow;
	uint32_t ___GenerationCount;
	int32_t ___LastParentDirection;
	float ___LastPointScaleFactor;
	U3CMeasuredDimensionsU3Ee__FixedBuffer_t3BF016D1583A3A9EABAD62B35368C369C06DCD87 ___MeasuredDimensions;
};
struct LayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_marshaled_pinvoke
{
	U3CPositionU3Ee__FixedBuffer_t6F7472507E4B67C5CA936393DFFBA95309592810 ___Position;
	U3CDimensionsU3Ee__FixedBuffer_tD2708ED4F2A6D227404834E91D6359AB4B954457 ___Dimensions;
	U3CMarginU3Ee__FixedBuffer_tF5EF7606FDD9ACD4DDF18DC564195092A6A540FE ___Margin;
	U3CBorderU3Ee__FixedBuffer_t5A18296AB7D0BFC3131BDDE01656A53889147B34 ___Border;
	U3CPaddingU3Ee__FixedBuffer_tE057FF067DA31EB3EC92DD01973C24BDC7E9E9F3 ___Padding;
	int32_t ___Direction;
	uint32_t ___ComputedFlexBasisGeneration;
	float ___ComputedFlexBasis;
	int32_t ___HadOverflow;
	uint32_t ___GenerationCount;
	int32_t ___LastParentDirection;
	float ___LastPointScaleFactor;
	U3CMeasuredDimensionsU3Ee__FixedBuffer_t3BF016D1583A3A9EABAD62B35368C369C06DCD87 ___MeasuredDimensions;
};
struct LayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_marshaled_com
{
	U3CPositionU3Ee__FixedBuffer_t6F7472507E4B67C5CA936393DFFBA95309592810 ___Position;
	U3CDimensionsU3Ee__FixedBuffer_tD2708ED4F2A6D227404834E91D6359AB4B954457 ___Dimensions;
	U3CMarginU3Ee__FixedBuffer_tF5EF7606FDD9ACD4DDF18DC564195092A6A540FE ___Margin;
	U3CBorderU3Ee__FixedBuffer_t5A18296AB7D0BFC3131BDDE01656A53889147B34 ___Border;
	U3CPaddingU3Ee__FixedBuffer_tE057FF067DA31EB3EC92DD01973C24BDC7E9E9F3 ___Padding;
	int32_t ___Direction;
	uint32_t ___ComputedFlexBasisGeneration;
	float ___ComputedFlexBasis;
	int32_t ___HadOverflow;
	uint32_t ___GenerationCount;
	int32_t ___LastParentDirection;
	float ___LastPointScaleFactor;
	U3CMeasuredDimensionsU3Ee__FixedBuffer_t3BF016D1583A3A9EABAD62B35368C369C06DCD87 ___MeasuredDimensions;
};
struct Length_t90BB06D47DD6DB461ED21BD3E3241FAB6C824256 
{
	float ___m_Value;
	int32_t ___m_Unit;
};
struct MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF 
{
	String_t* ___name;
	int32_t ___type;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___packedValue;
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___textureValue;
};
struct MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF_marshaled_pinvoke
{
	char* ___name;
	int32_t ___type;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___packedValue;
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___textureValue;
};
struct MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF_marshaled_com
{
	Il2CppChar* ___name;
	int32_t ___type;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___packedValue;
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___textureValue;
};
struct MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 
{
	union
	{
		struct
		{
			intptr_t ___pointer;
			int32_t ___allocator;
		};
		uint8_t MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2__padding[16];
	};
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
struct PanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED 
{
	int32_t ___Flags;
};
struct RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C 
{
	uint8_t ___layer;
	uint32_t ___renderingLayerMask;
	int32_t ___motionMode;
	int32_t ___shadowCastingMode;
	bool ___staticShadowCaster;
	int32_t ___rendererPriority;
	bool ___supportsIndirect;
};
struct RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_marshaled_pinvoke
{
	uint8_t ___layer;
	uint32_t ___renderingLayerMask;
	int32_t ___motionMode;
	int32_t ___shadowCastingMode;
	int32_t ___staticShadowCaster;
	int32_t ___rendererPriority;
	int32_t ___supportsIndirect;
};
struct RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_marshaled_com
{
	uint8_t ___layer;
	uint32_t ___renderingLayerMask;
	int32_t ___motionMode;
	int32_t ___shadowCastingMode;
	int32_t ___staticShadowCaster;
	int32_t ___rendererPriority;
	int32_t ___supportsIndirect;
};
struct RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 
{
	int32_t ___U3CwidthU3Ek__BackingField;
	int32_t ___U3CheightU3Ek__BackingField;
	int32_t ___U3CmsaaSamplesU3Ek__BackingField;
	int32_t ___U3CvolumeDepthU3Ek__BackingField;
	int32_t ___U3CmipCountU3Ek__BackingField;
	int32_t ____graphicsFormat;
	int32_t ___U3CstencilFormatU3Ek__BackingField;
	int32_t ___U3CdepthStencilFormatU3Ek__BackingField;
	int32_t ___U3CdimensionU3Ek__BackingField;
	int32_t ___U3CshadowSamplingModeU3Ek__BackingField;
	int32_t ___U3CvrUsageU3Ek__BackingField;
	int32_t ____flags;
	int32_t ___U3CmemorylessU3Ek__BackingField;
};
struct StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF 
{
	int32_t ___U3CidU3Ek__BackingField;
	String_t* ___U3CnameU3Ek__BackingField;
};
struct StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF_marshaled_pinvoke
{
	int32_t ___U3CidU3Ek__BackingField;
	char* ___U3CnameU3Ek__BackingField;
};
struct StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF_marshaled_com
{
	int32_t ___U3CidU3Ek__BackingField;
	Il2CppChar* ___U3CnameU3Ek__BackingField;
};
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E 
{
	float ___m_Value;
	int32_t ___m_Unit;
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75 
{
	int32_t ___name;
	int32_t ___type;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___packedValue;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___textureValue;
};
struct VisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0 
{
	int32_t ___typeNameId;
	int32_t ___nameId;
	int32_t ___pseudoStates;
	VisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0* ___logicalParent;
	int32_t* ___classIds;
	int32_t ___classCount;
	int32_t ___triggerPseudoMask;
	int32_t ___dependencyPseudoMask;
};
struct VisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3 
{
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___WorldTransform;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___WorldTransformInverse;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___BoundingBox;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___WorldBoundingBox;
	int32_t ___Flags;
};
struct Request_tAA55F47806E39B0E19B53273DCBFB5CF457F9187 
{
	UnsafeList_1_tBB6961066733E78B8C22E5C4D4D5FF9A581981D1 ___info;
	AsyncGPUReadbackRequest_t6A735D3E0F1DEF8F43EBD0E6FE550FAE564519C7 ___readback;
};
struct StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53  : public RuntimeObject
{
	RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* ___destination;
	int32_t ___mipLevel;
	int32_t ___face;
	int32_t ___slice;
	bool ___isPreview;
};
struct UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 
{
	UnsafeList_1_t5C65DCA6782B7C9860C859C2F0C07A2C497E822D ___meshLods;
	UnsafeList_1_t5C65DCA6782B7C9860C859C2F0C07A2C497E822D ___crossFades;
};
struct Settings_t3BEFDFF2C1A3D3A215DAF7B76E735B1BFB946C92 
{
	int32_t ___m_Quality;
	float ___m_FrameInfluence;
	float ___m_JitterScale;
	float ___m_MipBias;
	float ___m_VarianceClampScale;
	float ___m_ContrastAdaptiveSharpening;
	int32_t ___resetHistoryFrames;
	int32_t ___jitterFrameCountOffset;
};
struct CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86 
{
	ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___m_Context;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___m_Camera;
};
struct CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_marshaled_pinvoke
{
	ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___m_Context;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___m_Camera;
};
struct CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_marshaled_com
{
	ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___m_Context;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___m_Camera;
};
struct ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70 
{
	ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___m_Context;
	List_1_tD2FA3273746E404D72561E8324608D18B52B533E* ___m_Cameras;
};
struct ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_marshaled_pinvoke
{
	ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___m_Context;
	List_1_tD2FA3273746E404D72561E8324608D18B52B533E* ___m_Cameras;
};
struct ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_marshaled_com
{
	ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___m_Context;
	List_1_tD2FA3273746E404D72561E8324608D18B52B533E* ___m_Cameras;
};
struct SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24  : public RuntimeObject
{
	RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* ___destination;
	int32_t ___mipLevel;
	int32_t ___face;
	int32_t ___slice;
};
struct Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F  : public MulticastDelegate_t
{
};
struct AlignOfHelper_1_t2F30078087CCDB55F8D473591F4FDE09CBEB5D9C 
{
	uint8_t ___dummy;
	ComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C ___data;
};
struct AlignOfHelper_1_t938D5D39EB34C9404E00E05DA835AEAF195EED60 
{
	uint8_t ___dummy;
	LayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1 ___data;
};
struct AlignOfHelper_1_tA801A0280FB34492FDCB3CB6E3234C95DCA0A512 
{
	uint8_t ___dummy;
	PanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED ___data;
};
struct AlignOfHelper_1_t2E41B87D9D08BFCD38A18DAFF9D1503CD262A669 
{
	uint8_t ___dummy;
	VisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0 ___data;
};
struct AlignOfHelper_1_tFFFE7CB6FDF697D25267CACBE063159F38998B83 
{
	uint8_t ___dummy;
	VisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3 ___data;
};
struct EmbeddedArray64_1_t40B70A170260009F23E16506CE418B52748B8EE0 
{
	FixedList64Bytes_1_tA8137DDBE902BF483FBBDB59365917992EA9F670 ___m_FixedArray;
	UnsafeList_1_t5F75981CEC17C7EAE94180B0C9C63C260D6D1B3C ___m_List;
	int32_t ___m_Length;
	bool ___m_Created;
	bool ___m_IsEmbedded;
};
struct FixedBuffer2_1_t12861AD15AF3145969B4D81CB4DEE2C7C8C24B7C 
{
	Length_t90BB06D47DD6DB461ED21BD3E3241FAB6C824256 _____0;
	Length_t90BB06D47DD6DB461ED21BD3E3241FAB6C824256 _____1;
};
struct FixedBuffer4_1_tFD261E0E1A5ECEFC54C0B0B89FA6BFEE477E4D8C 
{
	FilterParameter_tC6BAE67835BA35634A769B28BF35314AF42BE060 _____0;
	FilterParameter_tC6BAE67835BA35634A769B28BF35314AF42BE060 _____1;
	FilterParameter_tC6BAE67835BA35634A769B28BF35314AF42BE060 _____2;
	FilterParameter_tC6BAE67835BA35634A769B28BF35314AF42BE060 _____3;
};
struct Func_2_t9622A5472E3EB564FD9AA65F9666F983FA8CA079  : public MulticastDelegate_t
{
};
struct Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577  : public MulticastDelegate_t
{
};
struct Func_2_tAD3C25E447E01C5173D4EF30C14D5F69437441FD  : public MulticastDelegate_t
{
};
struct NativeKeyValueArrays_2_t6F346645686D9ED3DF9980242A60F6343D9BD346 
{
	NativeArray_1_t2FF0F1BBD323229A2F9ABD52397EA6EF9B105E09 ___Keys;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___Values;
};
struct NativeKeyValueArrays_2_t5F8B14A1FC3085C8F576054B525A95D4898297D8 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___Keys;
	NativeArray_1_t107C57D0357BCF9956A60495CD8FAADDF1D26AFB ___Values;
};
struct NativeKeyValueArrays_2_t66B0B299E9562B5E22EF3BF01729F553EF5A1143 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___Keys;
	NativeArray_1_tAA41AE8C464559D1987285B6F1D42333CD5EC15B ___Values;
};
struct NativeKeyValueArrays_2_tA2DA312B446D1C4E01DFB5BABCD5FD907A6D98BB 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___Keys;
	NativeArray_1_t727E0B11B40EA7D6477F67D79DA7B7F7C383735E ___Values;
};
struct NativeKeyValueArrays_2_t69F48B55F7CB9E53D8DA8AC22D78A9FE2C4ACCBB 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___Keys;
	NativeArray_1_t8E042B4249B3126F27EE49887D2507798DC25F2C ___Values;
};
struct NativeKeyValueArrays_2_tCBCD37F108CC29AF7DD444E7DADEBD5DA915330C 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___Keys;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___Values;
};
struct NativeKeyValueArrays_2_t1DC3FE19F0B4A1DF25136B0397012CFE6BE2C193 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___Keys;
	NativeArray_1_tFCAF9979C15E15C78F0F78DB34559D880F381CEE ___Values;
};
struct NativeKeyValueArrays_2_t2DFE6540DA40D93DF34F283B6ED85D911565BD6D 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___Keys;
	NativeArray_1_t251C0B6A4D277C92366F302523FD5C0031FA1B31 ___Values;
};
struct NativeKeyValueArrays_2_t92055CB18DB710BBBCD3CC5107937B10BFDCEA2A 
{
	NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B ___Keys;
	NativeArray_1_t60C2883F9133642CF381234B3DD254605DD4F0A5 ___Values;
};
struct NativeKeyValueArrays_2_t637F773818E79D65A71945EFC311230CEF0730EC 
{
	NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B ___Keys;
	NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB ___Values;
};
struct NativeKeyValueArrays_2_tBB45ADF53F7E53E64A0AF63EF8702A771FDA1956 
{
	NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB ___Keys;
	NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B ___Values;
};
struct NativeKeyValueArrays_2_t93070D4261139B002601B084DE32FFA5AA5488CE 
{
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___Keys;
	NativeArray_1_tB58D1BE7997E66C484A0FCC487D9A3D3A7D31AEC ___Values;
};
struct NativeKeyValueArrays_2_t00C5D2C7AF9D9E3622CAB210E6E11E33C4881C8A 
{
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___Keys;
	NativeArray_1_t497DD754C21E03BAC4C1F2BB7A3BB0025FF4EB88 ___Values;
};
struct NativeKeyValueArrays_2_t5B99C2646C28A5C04DF011E6E993BDE26A27A953 
{
	NativeArray_1_t8E236FFFE7B598011354300BFCED0A15647BBC5D ___Keys;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___Values;
};
struct NativeKeyValueArrays_2_tD4417ED5E6C2DAC8437C9159D79F622F83C72D39 
{
	NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184 ___Keys;
	NativeArray_1_t703E60DA65EBF076EB4916D3B9D9987A5A09B9CC ___Values;
};
struct NativeKeyValueArrays_2_t4AA59D24D1616F48DCDB5CB6C4ABA336C51B1764 
{
	NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184 ___Keys;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___Values;
};
struct NativeKeyValueArrays_2_t97DEBC72840B73CFCEE6195C4C495C675E96FAF1 
{
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___Keys;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___Values;
};
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___transparentInstanceID;
	BatchMeshID_t34167B7C1D0503C43A01A7BD213DFC367525D2A0 ___meshID;
	int32_t ___submeshIndex;
	int32_t ___activeMeshLod;
	BatchMaterialID_tF9E95833BB1C35A6D14D47CF4EC8A6EB7D15D65C ___materialID;
	int32_t ___flags;
	GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___archetype;
	RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C ___range;
	int32_t ___lightmapIndex;
};
struct DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_marshaled_pinvoke
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___transparentInstanceID;
	BatchMeshID_t34167B7C1D0503C43A01A7BD213DFC367525D2A0 ___meshID;
	int32_t ___submeshIndex;
	int32_t ___activeMeshLod;
	BatchMaterialID_tF9E95833BB1C35A6D14D47CF4EC8A6EB7D15D65C ___materialID;
	int32_t ___flags;
	GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___archetype;
	RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_marshaled_pinvoke ___range;
	int32_t ___lightmapIndex;
};
struct DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_marshaled_com
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___transparentInstanceID;
	BatchMeshID_t34167B7C1D0503C43A01A7BD213DFC367525D2A0 ___meshID;
	int32_t ___submeshIndex;
	int32_t ___activeMeshLod;
	BatchMaterialID_tF9E95833BB1C35A6D14D47CF4EC8A6EB7D15D65C ___materialID;
	int32_t ___flags;
	GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___archetype;
	RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_marshaled_com ___range;
	int32_t ___lightmapIndex;
};
struct LayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92 
{
	LayoutCachedMeasurement_tAEC7D318B47741D367D20EE2065A358062325CF0 ___CachedLayout;
};
struct RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27  : public Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700
{
};
struct AlignOfHelper_1_t8866C28BEBC43BE45C777354FACE06E5D80D8AF1 
{
	uint8_t ___dummy;
	LayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92 ___data;
};
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
	uint32_t ___m_NonSerializedVersion;
};
struct FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF 
{
	int32_t ___m_Type;
	FixedBuffer4_1_tFD261E0E1A5ECEFC54C0B0B89FA6BFEE477E4D8C ___m_Parameters;
	int32_t ___m_ParameterCount;
	FilterFunctionDefinition_tFE41DB19FFB74F4D2B54BF44D1D2051B57FC82F2* ___m_CustomDefinition;
};
struct FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF_marshaled_pinvoke
{
	int32_t ___m_Type;
	FixedBuffer4_1_tFD261E0E1A5ECEFC54C0B0B89FA6BFEE477E4D8C ___m_Parameters;
	int32_t ___m_ParameterCount;
	FilterFunctionDefinition_tFE41DB19FFB74F4D2B54BF44D1D2051B57FC82F2* ___m_CustomDefinition;
};
struct FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF_marshaled_com
{
	int32_t ___m_Type;
	FixedBuffer4_1_tFD261E0E1A5ECEFC54C0B0B89FA6BFEE477E4D8C ___m_Parameters;
	int32_t ___m_ParameterCount;
	FilterFunctionDefinition_tFE41DB19FFB74F4D2B54BF44D1D2051B57FC82F2* ___m_CustomDefinition;
};
struct LayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858 
{
	FixedBuffer2_1_t12861AD15AF3145969B4D81CB4DEE2C7C8C24B7C ___ResolvedDimensions;
	UnmanagedDataHandle_t5295F32E122AF2E09BF729381A22BD86B72C1DD1 ___Config;
	UnmanagedDataHandle_t5295F32E122AF2E09BF729381A22BD86B72C1DD1 ___Parent;
	UnmanagedDataHandle_t5295F32E122AF2E09BF729381A22BD86B72C1DD1 ___FirstChild;
	UnmanagedDataHandle_t5295F32E122AF2E09BF729381A22BD86B72C1DD1 ___NextSibling;
	UnmanagedDataHandle_t5295F32E122AF2E09BF729381A22BD86B72C1DD1 ___PrevSiblingRing;
	UnmanagedDataHandle_t5295F32E122AF2E09BF729381A22BD86B72C1DD1 ___NextLayoutChild;
	int32_t ___Status;
	float ___TargetSize;
	int32_t ___LineIndex;
};
struct MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 
{
	BatchMeshID_t34167B7C1D0503C43A01A7BD213DFC367525D2A0 ___meshID;
	int32_t ___meshLodCount;
	LodSelectionCurve_t5E3F99BC782C22E828074538B8B43051FF859713 ___meshLodSelectionCurve;
	EmbeddedArray64_1_t40B70A170260009F23E16506CE418B52748B8EE0 ___subMeshes;
};
struct MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_marshaled_pinvoke
{
	BatchMeshID_t34167B7C1D0503C43A01A7BD213DFC367525D2A0 ___meshID;
	int32_t ___meshLodCount;
	LodSelectionCurve_t5E3F99BC782C22E828074538B8B43051FF859713 ___meshLodSelectionCurve;
	EmbeddedArray64_1_t40B70A170260009F23E16506CE418B52748B8EE0 ___subMeshes;
};
struct MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_marshaled_com
{
	BatchMeshID_t34167B7C1D0503C43A01A7BD213DFC367525D2A0 ___meshID;
	int32_t ___meshLodCount;
	LodSelectionCurve_t5E3F99BC782C22E828074538B8B43051FF859713 ___meshLodSelectionCurve;
	EmbeddedArray64_1_t40B70A170260009F23E16506CE418B52748B8EE0 ___subMeshes;
};
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
	CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B* ___m_CancellationTokenSource;
};
struct UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11 
{
	int32_t ___m_Type;
	FixedBuffer4_1_tFD261E0E1A5ECEFC54C0B0B89FA6BFEE477E4D8C ___m_Parameters;
	int32_t ___m_ParameterCount;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_CustomDefinition;
};
struct AlignOfHelper_1_tA1529F9F8B7FA790F2938A80AD16F77284A61D04 
{
	uint8_t ___dummy;
	LayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858 ___data;
};
struct Func_2_t0F26B920A10A91BFA7B07637902B13D306D6ACB2  : public MulticastDelegate_t
{
};
struct UniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	bool ___m_RenderShadows;
	int32_t ___m_RequiresDepthTextureOption;
	int32_t ___m_RequiresOpaqueTextureOption;
	int32_t ___m_CameraType;
	List_1_tD2FA3273746E404D72561E8324608D18B52B533E* ___m_Cameras;
	int32_t ___m_RendererIndex;
	LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB ___m_VolumeLayerMask;
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_VolumeTrigger;
	int32_t ___m_VolumeFrameworkUpdateModeOption;
	bool ___m_RenderPostProcessing;
	int32_t ___m_Antialiasing;
	int32_t ___m_AntialiasingQuality;
	bool ___m_StopNaN;
	bool ___m_Dithering;
	bool ___m_ClearDepth;
	bool ___m_AllowXRRendering;
	bool ___m_AllowHDROutput;
	bool ___m_UseScreenCoordOverride;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_ScreenSizeOverride;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_ScreenCoordScaleBias;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___m_Camera;
	bool ___m_RequiresDepthTexture;
	bool ___m_RequiresColorTexture;
	MotionVectorsPersistentData_t077A3BA28B75576C897E6C794FE0ABF9DB8EBBBB* ___m_MotionVectorsPersistentData;
	UniversalCameraHistory_t15D275DAE9AD5B608CE533D0FCE0884F07BB1E80* ___m_History;
	CameraU5BU5D_t1506EBA524A07AD1066D6DD4D7DFC6721F1AC26B* ___m_AllCamerasTemp;
	Settings_t3BEFDFF2C1A3D3A215DAF7B76E735B1BFB946C92 ___m_TaaSettings;
	VolumeStack_t5DE94743BDB63D97EF5587DBDAE46468233F36E8* ___m_VolumeStack;
	int32_t ___m_Version;
};
struct List_1_tD2FA3273746E404D72561E8324608D18B52B533E_StaticFields
{
	CameraU5BU5D_t1506EBA524A07AD1066D6DD4D7DFC6721F1AC26B* ___s_emptyArray;
};
struct List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B_StaticFields
{
	EasingFunctionU5BU5D_t3EEBBFFAD92EA74C3960D5F78D2A98BCEEA62E49* ___s_emptyArray;
};
struct List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7_StaticFields
{
	FilterFunctionU5BU5D_t6E250F0FE79D15DC0BB74D665DDF2EAD1ABE07B7* ___s_emptyArray;
};
struct List_1_t491347B1404617671B39DA9325642B0DB8748CB3_StaticFields
{
	MaterialPropertyValueU5BU5D_t90351D00AFCBDFC3053382B69DA7BE5169D3DB9F* ___s_emptyArray;
};
struct List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268_StaticFields
{
	StylePropertyNameU5BU5D_t531626CF806E3F3D348D1F38A9109767014C35F8* ___s_emptyArray;
};
struct List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF_StaticFields
{
	TimeValueU5BU5D_t3EB79C5975D39A0E711250FD8A9547F5312746DE* ___s_emptyArray;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___s_emptyArray;
};
struct List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4_StaticFields
{
	__Il2CppFullySharedGenericStructTypeU5BU5D_tF3B929B6E80D0A8C109178E11CE8FF9957B014C1* ___s_emptyArray;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___s_emptyArray;
};
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___s_emptyArray;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97_StaticFields
{
	MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___k_MemoryLabel;
	int32_t ___k_SizeOfData;
	int32_t ___k_SizeOfT;
};
struct UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE_StaticFields
{
	MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___k_MemoryLabel;
	int32_t ___k_SizeOfData;
	int32_t ___k_SizeOfT;
};
struct UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281_StaticFields
{
	MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___k_MemoryLabel;
	int32_t ___k_SizeOfData;
	int32_t ___k_SizeOfT;
};
struct UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5_StaticFields
{
	MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___k_MemoryLabel;
	int32_t ___k_SizeOfData;
	int32_t ___k_SizeOfT;
};
struct UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC_StaticFields
{
	MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___k_MemoryLabel;
	int32_t ___k_SizeOfData;
	int32_t ___k_SizeOfT;
};
struct UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC_StaticFields
{
	MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___k_MemoryLabel;
	int32_t ___k_SizeOfData;
	int32_t ___k_SizeOfT;
};
struct BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_StaticFields
{
	BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 ___Null;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_StaticFields
{
	GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___Invalid;
};
struct GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_StaticFields
{
	GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 ___Invalid;
};
struct GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_StaticFields
{
	GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 ___Invalid;
};
struct GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_StaticFields
{
	GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 ___Invalid;
};
struct InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_StaticFields
{
	InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B ___Invalid;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct UIntPtr_t_StaticFields
{
	uintptr_t ___Zero;
};
struct UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F_StaticFields
{
	int32_t ___k_UpscalerHash_Point;
	int32_t ___k_UpscalerHash_Linear;
	int32_t ___k_UpscalerHash_FSR1;
	int32_t ___k_UpscalerHash_STP;
	RenderGraph_t73ECE03B3CA3D0D17F1448D64AE020E81592AA1E* ___s_RenderGraph;
	RTHandleResourcePool_tB08B48917D5F811C85F6DDF0D751436D366CEF7A* ___s_RTHandlePool;
	bool ___requireOffscreenUICoverPrepass;
	bool ___offscreenUIRenderedInCurrentFrame;
	LODParameters_t54D2AA0FD8E53BCF51D7A42BC1A72FCA8C78A08A ___cachedLODParameters;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___k_DefaultLightPosition;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___k_DefaultLightColor;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___k_DefaultLightAttenuation;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___k_DefaultLightSpotDirection;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___k_DefaultLightsProbeChannel;
	List_1_tF42FEB6C3B18B7E7C8F2DE1FEBA00D2491736317* ___s_ShadowBiasData;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___s_ShadowResolutionData;
	RequestLightsDelegate_t585505A75681754DA53BE119D8611B605F0243BB* ___s_LightsDelegate;
};
struct CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7_StaticFields
{
	bool ___ThrowOnSetRenderTarget;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
struct ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36_StaticFields
{
	ShaderTagId_t453E2085B5EE9448FF75E550CAB111EFF690ECB0 ___kRenderTypeTag;
};
struct PanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_StaticFields
{
	PanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED ___Default;
};
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700_StaticFields
{
	int32_t ___GenerateAllMips;
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
struct VisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_StaticFields
{
	VisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0 ___Default;
};
struct VisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_StaticFields
{
	VisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3 ___Default;
};
struct CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_StaticFields
{
	ProfilingSampler_t420D4672EDB44E0EF980B31ADFD9E5747200FECE* ___beginCameraRenderingSampler;
	ProfilingSampler_t420D4672EDB44E0EF980B31ADFD9E5747200FECE* ___endCameraRenderingSampler;
};
struct ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_StaticFields
{
	ProfilingSampler_t420D4672EDB44E0EF980B31ADFD9E5747200FECE* ___beginContextRenderingSampler;
	ProfilingSampler_t420D4672EDB44E0EF980B31ADFD9E5747200FECE* ___endContextRenderingSampler;
};
struct LayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_StaticFields
{
	LayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92 ___Default;
};
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_StaticFields
{
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreCull;
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreRender;
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPostRender;
};
struct LayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_StaticFields
{
	LayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858 ___Default;
};
struct UniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93_StaticFields
{
	List_1_tF9F2510E1F31EAAB4FF93BF5D2FD123A1BA401D8* ___s_CachedVolumeStacks;
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


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7378BA5FBCA1E88080985FB810820B3F47DAD54C_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PooledObject_tAF29EF4F652282CE220188D9C8727C721E60336D ListPool_1_Get_m3DB5FF68692DF4554D8CA9BE30DCBB60B893C810_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E** ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PooledObject_System_IDisposable_Dispose_mD734AB7A8CE2AB14B06CEA5DB2B1269C92CA59CC_gshared (PooledObject_t42DFE6F40709CEDB91999103D5FA096C28E0A1DD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GameObject_TryGetComponent_TisIl2CppSharedGenericObject_m1B78688AF73D26F76CE465F57230D80C23B597C6_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, Il2CppSharedGenericObject** ___0_component, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mE09F2B19DAC75EB997515A1B25AB0AF59AA37EDA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m04DD2C89F805D820CAFA67B72D8261E1D52A75AA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m6AD907969ED820C7B597DBDE5A62251F0BAAEBB5_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m581D10C30FE27399A9EDCCBB6EE26A6D79E5477E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8E2B97AA6AB1779936EAA4893F7CE096024BCE54_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8291A5EAB6935532A5B3B16082E9709D3B425582_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m6BD3023222CB03E8462517B9F40193D9A085A1C2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m8D4E16E3691F9835E03B880A9BE1B0F7A25F955B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_mF86E7726D232D0C06A598629B29651A120967D95_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m38864F218C1121BECFC7EFB1DB548BD52F5E77D1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m257333772E743A0BFC11C2B733B8727A1379AC5D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_mA0454C21C3291C32B45B2566A9D88C11C570AAB7_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m7FE14B8744B411EBACDA2B154025806F5CAB4659_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m5586B4329861CC2D97E47E8ABBFB93BE29C41858_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m2C9EAB7C411248886CA8ADE580C3232DCE0942B8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_mCB89996F323B06C4C16FFD580A8744DCF6E0EAE0_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UnmanagedRefCountedList_1_get_IsEmpty_mB1BF30169E77B2C7AA4C2D05D91445827E62BE2D_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m8C60A954A286528BD0B6CF0D629BD42DF5692251 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC UnmanagedRefCountedList_1_get_Empty_mF30A4199DBFFC6A1CEE63EDC4667AD9C3F59A4D0_fshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m7ACD2CB9146F490C6C3E71CEB1A4C1DD97F7336A (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m3317B0BACC15E51025A554B4C52F73B2417EFCBD (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m019F92E6E6C2E3331D98817815F0D5E975A31BB6 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_mB86F120A00B23B11FE39DA54CB3BEBCEC8751B17_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m2C5C294367EEC020C3F2A9955689C9EF20C1DCFB (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4* UnmanagedRefCountedList_1_get_Item_m8ADEB8E0DB44D0F2ED01510725A6C7C5F5AB9EF4 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4 List_1_get_Item_m96D208AAEBB2370590FC90F7F803453D7AE9F116 (List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ReadOnlySpan_1_get_Length_m4430960CA0D0458B1A1106DD246CA9AB746B5DB2_fshared_inline (ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mC1A6A68B722E048D4FB2CF6CEA269887284C071F (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m6B20DE63D68C6950CC593A0E15E5175545AC06ED (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E* UnmanagedRefCountedList_1_get_Item_m25AD99321A43BCB3E10E0720C424B625B05F00D8 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E List_1_get_Item_m54313A208BF733F363077C5A2C48B534128B0889 (List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mB59A1EE1873B7EED39F101204D5F0E14A9DC1231 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_mE4C1F841F0D0FA8A08130B4761A3A0843B0D2F7B (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11* UnmanagedRefCountedList_1_get_Item_m4C2E9BDBA102B1DCD68E993BBAF130D87620131B (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_m58D3EA8F1F7DF64C8560E49D2BDB2631AA1A1970 (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m19BAE2388C9E2168BECA6291C243441CED5066CC (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75* UnmanagedRefCountedList_1_get_Item_m8BA86CC1FDC39C2CECA6193033CD0CC191DAA9AE (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mB9D68971E4FDE3D6C127D837D5E67DD52CF1899D (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m23C0348FE604FA9B337A9CB97A850D992E27D5C2_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_Item_m73AC4CB8D0814F69B7909BD7C5F6CD978F9D51FE_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mFED40840551BD2E9A867CEA2A8879454A05FB380_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF List_1_get_Item_mD8887B4702293F0057E0DD9DFCCDC9FE7F99F0E5 (List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11 Func_2_Invoke_mC82AB28A182689A25D4F657E20FC5A764642A915_inline (Func_2_t0F26B920A10A91BFA7B07637902B13D306D6ACB2* __this, FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF List_1_get_Item_mB0D64703F21141207CD84B9D6B5FB80410BB36F5 (List_1_t491347B1404617671B39DA9325642B0DB8748CB3* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75 Func_2_Invoke_m63E17BE9D669582B8D83B161B938EF4F5E866748_inline (Func_2_t9622A5472E3EB564FD9AA65F9666F983FA8CA079* __this, MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF List_1_get_Item_m2455DF403BC23EF806BBB35F26A197F1AA270CAC (List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m4C0458CE84ED9C58132692F135BB07908074DC06_gshared_inline (Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577* __this, StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m243F4E8CDDB9A9F83AA778B3F2A1DA639F65AFFE (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_m77408358E22109403619F8D5772C5BB0D90898E5 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_m346BA84F5DE67F951530A1FA79808C15A58E9BEE (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m4904C1101CBC6F7514E304F08A59D4D11FF21061 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_mDCB5C70225741FBD0A45FC7CF4AF86FFBE5F9082 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_mC42B46855B167085DF30F2EF8E5B972D224596E8 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_m305E33368392F6D1AD854746351A71687763E9AF (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_mD7415ADC961F9A1C7AA6A8E77C83534DCFC175AF (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_m85830C3F1A7DDFC22EDBAE2A99C08C617E793C58 (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m540F90AA5E678CB4111BAC286677FF58EAD5EF90 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_m4B39562DBE2738598CDBCE1DD4B2D04A52064F97 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_m3EF1747E3FE4FA9731252DDDDAAF355D28F0E66F (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_m1A1BC9ABD2A9D7B9C7434073D1F52063C8F92056_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m3D75E429C1104D73A7D1533FEDB84C8776D97DC6_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_m58403CFD1E60A2E9DF9DC8E7600CBC28F642089F_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_mC9425FE28356043DFC64EF65FC11F219FCA48380_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m934C9E3CBBFA04ABEF4528E565C300B5DCF8C2D1_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_Add_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m115C1E10CFF2E5179C099DDD59C5779D0863C1C1 (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeListExtensions_IndexOf_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mAAD5AAC095A0510309AEAA951828DAE9B8C783A2 (UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E ___0_container, GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tA7B55DDCFA4B3B474C0F1DCFCEADB2ABB0EC8F10 UnsafeList_1_AsReadOnlySpan_m0B9F520E68A4F8F1C7DE958A934E9AFB5D86B53A (UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeArrayExtensions_IndexOf_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m6F4F2F3FD9AEB9A0266F285F36171E22C3501B90 (ReadOnlySpan_1_tA7B55DDCFA4B3B474C0F1DCFCEADB2ABB0EC8F10 ___0_roSpan, GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEA2D219466CA70D0772888D0B2AA5BDF95B3D7B0 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m1889622A4F9D451311D704800071C27E203E30FD (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m53A432E510AFC1B5E17AC7D4CEA9BDC969EF4183 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mBBBCD7A3795516F652E2A209921D9F365FEF117D (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_mFCFCB281237C3FD181B82326F1CDC74ECDC26835 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m28DB190FC25AC6811E2F609C118B25148772E8ED (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m97E2EBA7DBA4EC678CB7F7D5A1E14B2687937D9B (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_mEE7449D53E0B0DF2588A7ABF7DE9C12E23AEC194 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m5EF0E0217EB20D03E739EF4F21BA8ED27454FBA1 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m11C03B89A0BC9969D9C5F48944DA915764AB7653 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m1039B6A2212089AF73B18D7545E9DC3D3DF22E44 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m4AC175F5FE1C77C9A2E7602A09E229A5CF617FAF (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m7CF1071B4128F92A069498179CE85F80CB5AEBE1 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m47E7EA1FA34E44C4B7E215FA109EFC5813E93948 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m84BBCADD738D8E17724D100724F1173F24CC9D46 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m92740FC50E0692378ABED6D572FE0AA5FFF18DFB (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 UnsafeUtility_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_mFD7DBC1199616005466125347027F6201459B40D_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C UnsafeUtility_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mFDF2C4591B5F4C0AF4424ED681225F9CF100C5BB_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m4BCBCB4D1AC60559B41D33E7097084B82F700097 (NativeKeyValueArrays_2_t6F346645686D9ED3DF9980242A60F6343D9BD346* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_mBEBDFF6E64411CCDC46D8A00FF46DD9D99082631 (NativeKeyValueArrays_2_t5F8B14A1FC3085C8F576054B525A95D4898297D8* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UnsafeUtility_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_mF765CB2E5FD631DFB79C25DE656F3C1BB359B995_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m4F24A3063C8E3F28E85784A8E086E8ABCEF80123 (NativeKeyValueArrays_2_t66B0B299E9562B5E22EF3BF01729F553EF5A1143* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 UnsafeUtility_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m2E442046FFC024C177FCA6130678FA0B97F3C445_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m686910AE937E76C8D8BAC2FA971F98F55668D1A1 (NativeKeyValueArrays_2_tA2DA312B446D1C4E01DFB5BABCD5FD907A6D98BB* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 UnsafeUtility_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mF42F014B5AA9C633D3FCAB3FFF26646E54395BD8_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_mFCC843E8A6076977EDC711B85D5A812409F96A92 (NativeKeyValueArrays_2_t69F48B55F7CB9E53D8DA8AC22D78A9FE2C4ACCBB* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B UnsafeUtility_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m86FC76E325E9D3B56133BB7A193BAF12B47FBCC1_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m8AD3EFA2ADD479EB790D599C9BF297BBFE6A6E22 (NativeKeyValueArrays_2_tCBCD37F108CC29AF7DD444E7DADEBD5DA915330C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m70A3BFBC8F88E9B0C7044FD84799B8FD2D4CF586 (NativeKeyValueArrays_2_t1DC3FE19F0B4A1DF25136B0397012CFE6BE2C193* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 UnsafeUtility_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_mAEB04091BED5994494AB1521F1CA283C9A55DA84_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m8AA40536A05046C7F2594BBDB7694F1C91CA23CF (NativeKeyValueArrays_2_t2DFE6540DA40D93DF34F283B6ED85D911565BD6D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 UnsafeUtility_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m6C484995D5C95208A4EB1F0C7664EC42A74DE670_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m2DE1DE05F01D53EE056876CE742559C9DA71D08E (NativeKeyValueArrays_2_t92055CB18DB710BBBCD3CC5107937B10BFDCEA2A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 UnsafeUtility_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m80C61348EC8F9D4F73F0AAA4A69A028E6D599DCD_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m24BCC1A996AF2B999A11BAC7FF1B589574131C68 (NativeKeyValueArrays_2_t637F773818E79D65A71945EFC311230CEF0730EC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m95CF0086C8462E4956EA2941717F496F9E9157A2 (NativeKeyValueArrays_2_tBB45ADF53F7E53E64A0AF63EF8702A771FDA1956* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_mED5744BD99EE505BA094FB2E2D3E1460FBF35AD9 (NativeKeyValueArrays_2_t93070D4261139B002601B084DE32FFA5AA5488CE* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 UnsafeUtility_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m361058B0E058D8D5D3AC6C6C015700E6018A671C_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m02951443FBCF5B78507CC0C916DA7B406A6E2FFC (NativeKeyValueArrays_2_t00C5D2C7AF9D9E3622CAB210E6E11E33C4881C8A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 UnsafeUtility_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m8460969BD9998B0DFF865186874B2414FEED12C8_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m354A6BD5F31BC54C9F3D2B8A51EF1C71C9005648 (NativeKeyValueArrays_2_t5B99C2646C28A5C04DF011E6E993BDE26A27A953* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m0DD220DB30C031B6200A4119D0DCF56B565846E6 (NativeKeyValueArrays_2_tD4417ED5E6C2DAC8437C9159D79F622F83C72D39* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 UnsafeUtility_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m2A66DBE83F9498AC60B42C9A0B1C7E4401B4CDCC_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m8C99316414D47C54EF1AFF05D069266C1FE65840 (NativeKeyValueArrays_2_t4AA59D24D1616F48DCDB5CB6C4ABA336C51B1764* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271 (uint8_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m312FD1D94C51FFE92899836D9F020617D431BBF5_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mDEDCEBAF0C62FDCD22EA85CBDDBAFADD5CCB7915_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m2B47DA4F1DF05E028EEA414B4BC8C82E8FCF4481_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_mA5EE4C645904072BD057D41FC7D1AABAB3B4E398_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m77A7D05474DF60C828E063E75D6A6C52B0BB8A0A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m61E51176F8D18A3C2FC21CECC8908B35B9DB5F3D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mFF371C2E5F2018BDF838A2BBC5AC30EA7C74230E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mF8CB5ED1AEDA173F1F15E75017828AA38AE9E6EA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m851FFDFB05C6D16BC27B3BAD2B486229B48796FB_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m67C30665BD5F032BA4790CB4F198C5128D65FA1B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m952393E8A8C420CA0DEAB80F495FF991803AE4CD_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m86AC2282B14EEB2988DF554898FE8D12B6968652_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m501662FEF1C371DA264F4A8F86497DD85C6576C8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m36CB3A618AC04CD0E869A5C34BAE8DBFDEA34119_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m3BF032FF33CB8E4BAD8B53BCB58362D59F473562_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m7936CCEA1FD37B0D005189C07C3FAAC4E016B792_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6C6F7ABC33BDF25A69E8A2E8DE137DB2ACB77FDC_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 UnsafeUtilityInternal_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_m108E077C32AC45BC5336988B727DADDF1711407A_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeUtilityInternal_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mDC8A7125EE74C940B9F940440D412BA4B3A42575_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB UnsafeUtilityInternal_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m0C048047EB886D78B484166DCB014DF594B085BD_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m4E657D67A0253D6AA48A0AF0834D8B8B4D986C48_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C UnsafeUtilityInternal_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mC6AFEEF7260AB50C6AC741C83424DB3F59ECA569_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t UnsafeUtilityInternal_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mAA4A4AC11C7C0784A0566FAE86EFBAD08CF4126D_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UnsafeUtilityInternal_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m504EAEDFA7F1C3551FBC5F11CFB40360033F8B84_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 UnsafeUtilityInternal_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_mB00BADAC0C27D3EBF922C4D9514DBAFFE7570306_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 UnsafeUtilityInternal_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_m03D847364989884CB1A8D031CFBB7BAACDF29EB2_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B UnsafeUtilityInternal_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m6FD81C4AA7D25C02FAA41E4FDDA346959381646F_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 UnsafeUtilityInternal_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m11FC059EDD11872BC9AA0E4A69DE23575103FCB9_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 UnsafeUtilityInternal_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m25474EB27C8162D7A4BDF444168565682AC81612_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 UnsafeUtilityInternal_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m986ED2902CE4A51ABE99D9309F33BEE50D219A80_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m0863D7A09467FAC3CAE8A852D088E9E980F02756_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 UnsafeUtilityInternal_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_mFD8E968B6D42F987231C2D4D4433BC15E231FB83_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 UnsafeUtilityInternal_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m3358302574C84901BFC17BF5A4E83AD5C5475245_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2F30078087CCDB55F8D473591F4FDE09CBEB5D9C_m55C940043B5A1852EB5C37BA424A6AC9A7B4260D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t8866C28BEBC43BE45C777354FACE06E5D80D8AF1_m98779B037E081B8050E0B38AEAF0844112F9EBCA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t938D5D39EB34C9404E00E05DA835AEAF195EED60_mEAD7EEB63B4DF320E2B845B35B5279D7DE3A79D1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t12EA8BB9031D0D42734685DAB3E0DC8CDE6F7844_mF7669FB4FDB08DEECFB97E2BE96E4ABE06854B8A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA1529F9F8B7FA790F2938A80AD16F77284A61D04_mA13156A8148DE6FA510A7CC74B7B821794A925C7_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA801A0280FB34492FDCB3CB6E3234C95DCA0A512_mC956A5504B875A9255F4031549F4DA7B47AEE47B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2E41B87D9D08BFCD38A18DAFF9D1503CD262A669_m95A0D6A4B8D13CC09EF01FF9975C8AB46CDD7086_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFFFE7CB6FDF697D25267CACBE063159F38998B83_m5EF673BA7CA5471B065B0509F1A5949AADC5747A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Camera_get_cameraType_m85434C4C986D2EAC04FBFA44B284840AFC497851 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* Camera_get_targetTexture_mC856D7FF8351476068D04E245E4F08F5C56A55BD (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 RenderTexture_get_descriptor_m2FABD5CF6CCF410D1311FCBC7C9D9ECDEE9C7CC2 (RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RenderTexture_get_format_m58556ABB91A1FADA8044BEEA2E8C55280768CF35 (RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_colorFormat_m61B0FA4FCDE8A0F8A843DD6BF74097C21021C4FE (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_volumeDepth_mEF9610D1C14182417A01B7243DEE6B559A13B34D_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RenderTextureDescriptor_get_msaaSamples_mFCC33643AFF2265C8305DCFD79ED8774A1A8FA22_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_msaaSamples_m6910E09489372746391B14FBAF59A7237539D6C4_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_dimension_mCE9A4A08454BB2D9DFE3E505EC336FD480078F39_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Math_Pow_mEAE651F0858203FBE12B72B6A53951BBD0FB5265 (double ___0_x, double ___1_y, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_width_m3B2494007BFE3AD4D14403407C9B24F5045E7E10_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_height_m1FE41111472DAA9B5E80FFAF3445004D72A3CFA5_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RenderTextureDescriptor_get_width_mB159E4EB08B23B19CCCFADB465864361FB840BFF_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Mathf_Max_m7FA442918DE37E3A00106D1F2E789D65829792B8_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RenderTextureDescriptor_get_height_m1006F9AA45029715C552C8A8C2F102F63D3A91EC_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* RenderTexture_GetTemporary_mA8C827B80D3C07D0B8CDF7F5270FB5D3E53DD235 (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 ___0_desc, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Camera_set_cameraType_m20ECE54572F8B7CAF5D32193B65F3D7812E20F17 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_exists, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Camera_set_targetTexture_mE6C740F21A72DA47FB5B1D31D208710738A836C4 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* ___0_value, const RuntimeMethod* method) ;
inline void List_1__ctor_m735F7A05528CC71E71E3019311F2E22CF9E2C681 (List_1_tD2FA3273746E404D72561E8324608D18B52B533E* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tD2FA3273746E404D72561E8324608D18B52B533E*, const RuntimeMethod*))List_1__ctor_m7378BA5FBCA1E88080985FB810820B3F47DAD54C_gshared)(__this, method);
}
inline void List_1_Add_m9BE0CD6DB63BFCBCBD5619618748924143F1AFAD_inline (List_1_tD2FA3273746E404D72561E8324608D18B52B533E* __this, Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tD2FA3273746E404D72561E8324608D18B52B533E*, Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184*, const RuntimeMethod*))List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline)(__this, ___0_item, method);
}
inline PooledObject_t6A17503D2E86923ADABDFFE03F1EA5163EAF076B ListPool_1_Get_m7E32B4B150CCC0A396B9CFA7D60862F765DE7C15 (List_1_tD2FA3273746E404D72561E8324608D18B52B533E** ___0_value, const RuntimeMethod* method)
{
	return ((  PooledObject_t6A17503D2E86923ADABDFFE03F1EA5163EAF076B (*) (List_1_tD2FA3273746E404D72561E8324608D18B52B533E**, const RuntimeMethod*))ListPool_1_Get_m3DB5FF68692DF4554D8CA9BE30DCBB60B893C810_gshared)(___0_value, method);
}
inline void PooledObject_System_IDisposable_Dispose_m2C53DF93B31EF48C987A0FD22DEE119FDDD30E93 (PooledObject_t6A17503D2E86923ADABDFFE03F1EA5163EAF076B* __this, const RuntimeMethod* method)
{
	((  void (*) (PooledObject_t6A17503D2E86923ADABDFFE03F1EA5163EAF076B*, const RuntimeMethod*))PooledObject_System_IDisposable_Dispose_mD734AB7A8CE2AB14B06CEA5DB2B1269C92CA59CC_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ContextRenderingScope__ctor_m59F5F0D796371C51FC2BD08A9E2DBC0EA6C32003 (ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70* __this, ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___0_context, List_1_tD2FA3273746E404D72561E8324608D18B52B533E* ___1_cameras, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ContextRenderingScope_Dispose_mB51673C299E1DAA325206945F442709AF153868D (ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CameraRenderingScope__ctor_mB6900429BFF6B78AF2325B36B44C96101329BD2C (CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86* __this, ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___0_context, Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___1_camera, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CameraRenderingScope_Dispose_m7E450211F8C22CDF76970E0BC4FA3832ECE0E3C5 (CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
inline bool GameObject_TryGetComponent_TisUniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93_mBCAEF774AB0C0563A29C16F3A5305AE1A081C3BD (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, UniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93** ___0_component, const RuntimeMethod* method)
{
	return ((  bool (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, UniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93**, const RuntimeMethod*))GameObject_TryGetComponent_TisIl2CppSharedGenericObject_m1B78688AF73D26F76CE465F57230D80C23B597C6_gshared)(__this, ___0_component, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UniversalRenderPipeline_RenderSingleCameraInternal_mF40EDE5547E0DDE493AE06455C9928313D54E1AB (ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___0_context, Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___1_camera, UniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93** ___2_additionalCameraData, bool ___3_isLastBaseCamera, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SystemInfo_get_copyTextureSupport_m35C5E2D749B53757DD6F05492B5D79F364F466C2 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Graphics_CopyTexture_m306EE635C15C8118A93D947A5183E5134B4EE718 (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___0_src, int32_t ___1_srcElement, int32_t ___2_srcMip, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___3_dst, int32_t ___4_dstElement, int32_t ___5_dstMip, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Enum_GetName_m05FE85181853F756BA6BB2C033DD3590E6114D29 (Type_t* ___0_enumType, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Graphics_SetRenderTarget_m995C0F14B97C5BF46CCF2E7EF410C1CC05C46409 (RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* ___0_rt, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RenderTexture_ReleaseTemporary_mEEF2C1990196FF06FDD0DC190928AD3A023EBDD2 (RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* ___0_temp, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mE09F2B19DAC75EB997515A1B25AB0AF59AA37EDA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m04DD2C89F805D820CAFA67B72D8261E1D52A75AA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m6AD907969ED820C7B597DBDE5A62251F0BAAEBB5_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m581D10C30FE27399A9EDCCBB6EE26A6D79E5477E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8E2B97AA6AB1779936EAA4893F7CE096024BCE54_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8291A5EAB6935532A5B3B16082E9709D3B425582_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m6BD3023222CB03E8462517B9F40193D9A085A1C2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m8D4E16E3691F9835E03B880A9BE1B0F7A25F955B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_mF86E7726D232D0C06A598629B29651A120967D95_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m38864F218C1121BECFC7EFB1DB548BD52F5E77D1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m257333772E743A0BFC11C2B733B8727A1379AC5D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_mA0454C21C3291C32B45B2566A9D88C11C570AAB7_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m7FE14B8744B411EBACDA2B154025806F5CAB4659_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m5586B4329861CC2D97E47E8ABBFB93BE29C41858_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m2C9EAB7C411248886CA8ADE580C3232DCE0942B8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_mCB89996F323B06C4C16FFD580A8744DCF6E0EAE0_inline (const RuntimeMethod* method) ;
inline bool UnmanagedRefCountedList_1_get_IsEmpty_m2E14B74870630D7E8FED2C9B0B1ACE4BA16F0B1D (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97*, const RuntimeMethod*))UnmanagedRefCountedList_1_get_IsEmpty_mB1BF30169E77B2C7AA4C2D05D91445827E62BE2D_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m8C60A954A286528BD0B6CF0D629BD42DF5692251 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, const RuntimeMethod* method) ;
inline UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 UnmanagedRefCountedList_1_get_Empty_m27704059A53CF33AEF1259D47A403CD942B9731C (const RuntimeMethod* method)
{
	return ((  UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 (*) (const RuntimeMethod*))UnmanagedRefCountedList_1_get_Empty_mF30A4199DBFFC6A1CEE63EDC4667AD9C3F59A4D0_fshared)(method);
}
inline bool UnmanagedRefCountedList_1_get_IsEmpty_mFFEB115C88447058B106153933C2815CA0DB6030 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE*, const RuntimeMethod*))UnmanagedRefCountedList_1_get_IsEmpty_mB1BF30169E77B2C7AA4C2D05D91445827E62BE2D_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m7ACD2CB9146F490C6C3E71CEB1A4C1DD97F7336A (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, const RuntimeMethod* method) ;
inline UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE UnmanagedRefCountedList_1_get_Empty_mFC8CC3717E6C8ACF52A1A11863A2EC1B3C61B25A (const RuntimeMethod* method)
{
	return ((  UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE (*) (const RuntimeMethod*))UnmanagedRefCountedList_1_get_Empty_mF30A4199DBFFC6A1CEE63EDC4667AD9C3F59A4D0_fshared)(method);
}
inline bool UnmanagedRefCountedList_1_get_IsEmpty_m7F763A556B56D166DA9B84E3820FB94835F5533F (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281*, const RuntimeMethod*))UnmanagedRefCountedList_1_get_IsEmpty_mB1BF30169E77B2C7AA4C2D05D91445827E62BE2D_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m3317B0BACC15E51025A554B4C52F73B2417EFCBD (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, const RuntimeMethod* method) ;
inline UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 UnmanagedRefCountedList_1_get_Empty_m0EAA4D4244E7C3386545230900F0481C312D5169 (const RuntimeMethod* method)
{
	return ((  UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 (*) (const RuntimeMethod*))UnmanagedRefCountedList_1_get_Empty_mF30A4199DBFFC6A1CEE63EDC4667AD9C3F59A4D0_fshared)(method);
}
inline bool UnmanagedRefCountedList_1_get_IsEmpty_m4A937075322F5292F9840A84932C8015F894DA96 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5*, const RuntimeMethod*))UnmanagedRefCountedList_1_get_IsEmpty_mB1BF30169E77B2C7AA4C2D05D91445827E62BE2D_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1_UnsafeRelease_m019F92E6E6C2E3331D98817815F0D5E975A31BB6 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, const RuntimeMethod* method) ;
inline UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 UnmanagedRefCountedList_1_get_Empty_mAC8C90BA6702C35E53D2DDC7CD7477E718384457 (const RuntimeMethod* method)
{
	return ((  UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 (*) (const RuntimeMethod*))UnmanagedRefCountedList_1_get_Empty_mF30A4199DBFFC6A1CEE63EDC4667AD9C3F59A4D0_fshared)(method);
}
inline bool UnmanagedRefCountedList_1_get_IsEmpty_m521500F43BEA84B121D1ACDF22D20631BCDE3DFB (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, const RuntimeMethod*))UnmanagedRefCountedList_1_get_IsEmpty_mB1BF30169E77B2C7AA4C2D05D91445827E62BE2D_fshared)(__this, method);
}
inline void UnmanagedRefCountedList_1_UnsafeRelease_mB86F120A00B23B11FE39DA54CB3BEBCEC8751B17 (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, const RuntimeMethod* method)
{
	((  void (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, const RuntimeMethod*))UnmanagedRefCountedList_1_UnsafeRelease_mB86F120A00B23B11FE39DA54CB3BEBCEC8751B17_gshared)(__this, method);
}
inline UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC UnmanagedRefCountedList_1_get_Empty_m20DF05F068FA42AE6EADC38351DED3E2006DCC16 (const RuntimeMethod* method)
{
	return ((  UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC (*) (const RuntimeMethod*))UnmanagedRefCountedList_1_get_Empty_mF30A4199DBFFC6A1CEE63EDC4667AD9C3F59A4D0_fshared)(method);
}
inline int32_t List_1_get_Count_m714CDE1380C64F24D3FFA0C3A05220010855A1A3_inline (List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m2C5C294367EEC020C3F2A9955689C9EF20C1DCFB (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4* UnmanagedRefCountedList_1_get_Item_m8ADEB8E0DB44D0F2ED01510725A6C7C5F5AB9EF4 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4 List_1_get_Item_m96D208AAEBB2370590FC90F7F803453D7AE9F116 (List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B* __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline int32_t ReadOnlySpan_1_get_Length_mD966C06BF9402B65B5D1CB6E939CAD9FD1A56B6C_inline (ReadOnlySpan_1_t56EB56BD24E849B1A28025A5D541442A2AB282E7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_t56EB56BD24E849B1A28025A5D541442A2AB282E7*, const RuntimeMethod*))ReadOnlySpan_1_get_Length_m4430960CA0D0458B1A1106DD246CA9AB746B5DB2_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mC1A6A68B722E048D4FB2CF6CEA269887284C071F (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m780E93121AF45C1AE9F963A3E27BD6D79647BD6E_inline (List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m6B20DE63D68C6950CC593A0E15E5175545AC06ED (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E* UnmanagedRefCountedList_1_get_Item_m25AD99321A43BCB3E10E0720C424B625B05F00D8 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E List_1_get_Item_m54313A208BF733F363077C5A2C48B534128B0889 (List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF* __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline int32_t ReadOnlySpan_1_get_Length_mB739611300D60B4BEB14C21136E8462A04116674_inline (ReadOnlySpan_1_tA8945E8A02F969385193C34AFA893BCE779E5C80* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_tA8945E8A02F969385193C34AFA893BCE779E5C80*, const RuntimeMethod*))ReadOnlySpan_1_get_Length_m4430960CA0D0458B1A1106DD246CA9AB746B5DB2_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mB59A1EE1873B7EED39F101204D5F0E14A9DC1231 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, const RuntimeMethod* method) ;
inline int32_t ReadOnlySpan_1_get_Length_m0DDED3E4F3B413070D5A21ECABCEB0FC6A3A9D52_inline (ReadOnlySpan_1_tA7A09B5CBD9955114DF1BD8B2A082233FE91641C* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_tA7A09B5CBD9955114DF1BD8B2A082233FE91641C*, const RuntimeMethod*))ReadOnlySpan_1_get_Length_m4430960CA0D0458B1A1106DD246CA9AB746B5DB2_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_mE4C1F841F0D0FA8A08130B4761A3A0843B0D2F7B (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11* UnmanagedRefCountedList_1_get_Item_m4C2E9BDBA102B1DCD68E993BBAF130D87620131B (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_m58D3EA8F1F7DF64C8560E49D2BDB2631AA1A1970 (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, const RuntimeMethod* method) ;
inline int32_t ReadOnlySpan_1_get_Length_m3FF6D8FEC6FB6A437E4FD618AD20DE188AD2E373_inline (ReadOnlySpan_1_t3CCF29C77768AF4EE7E6D7C30578D3084881DD85* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_t3CCF29C77768AF4EE7E6D7C30578D3084881DD85*, const RuntimeMethod*))ReadOnlySpan_1_get_Length_m4430960CA0D0458B1A1106DD246CA9AB746B5DB2_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m19BAE2388C9E2168BECA6291C243441CED5066CC (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75* UnmanagedRefCountedList_1_get_Item_m8BA86CC1FDC39C2CECA6193033CD0CC191DAA9AE (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mB9D68971E4FDE3D6C127D837D5E67DD52CF1899D (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m8719A0E4E1F227424476DE81DF6DF6B58CA1CD71_inline (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
inline void UnmanagedRefCountedListExtensions_PrepareWrite_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m23C0348FE604FA9B337A9CB97A850D992E27D5C2 (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, int32_t ___1_count, const RuntimeMethod* method)
{
	((  void (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, int32_t, const RuntimeMethod*))UnmanagedRefCountedListExtensions_PrepareWrite_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m23C0348FE604FA9B337A9CB97A850D992E27D5C2_gshared)(___0_self, ___1_count, method);
}
inline int32_t* UnmanagedRefCountedList_1_get_Item_m73AC4CB8D0814F69B7909BD7C5F6CD978F9D51FE (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  int32_t* (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, int32_t, const RuntimeMethod*))UnmanagedRefCountedList_1_get_Item_m73AC4CB8D0814F69B7909BD7C5F6CD978F9D51FE_gshared)(__this, ___0_index, method);
}
inline int32_t List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75_gshared)(__this, ___0_index, method);
}
inline int32_t ReadOnlySpan_1_get_Length_m5D2D9C9D84B6B351227F38867909DFAC0CC9693D_inline (ReadOnlySpan_1_tDFED1E92751A6EBC762EDE852E1ABE93EC8EFC7E* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_tDFED1E92751A6EBC762EDE852E1ABE93EC8EFC7E*, const RuntimeMethod*))ReadOnlySpan_1_get_Length_m4430960CA0D0458B1A1106DD246CA9AB746B5DB2_fshared_inline)(__this, method);
}
inline int32_t* UnmanagedRefCountedList_1_get_UnsafeRefCount_mFED40840551BD2E9A867CEA2A8879454A05FB380 (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, const RuntimeMethod* method)
{
	return ((  int32_t* (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, const RuntimeMethod*))UnmanagedRefCountedList_1_get_UnsafeRefCount_mFED40840551BD2E9A867CEA2A8879454A05FB380_gshared)(__this, method);
}
inline int32_t List_1_get_Count_m1D6FD73298DDB395877D930AE657C2CD73B72E04_inline (List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF List_1_get_Item_mD8887B4702293F0057E0DD9DFCCDC9FE7F99F0E5 (List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11 Func_2_Invoke_mC82AB28A182689A25D4F657E20FC5A764642A915_inline (Func_2_t0F26B920A10A91BFA7B07637902B13D306D6ACB2* __this, FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF ___0_arg, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_mD1945480F1375B8F210F93C9AF5A14CB66DB12E2_inline (List_1_t491347B1404617671B39DA9325642B0DB8748CB3* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t491347B1404617671B39DA9325642B0DB8748CB3*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF List_1_get_Item_mB0D64703F21141207CD84B9D6B5FB80410BB36F5 (List_1_t491347B1404617671B39DA9325642B0DB8748CB3* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75 Func_2_Invoke_m63E17BE9D669582B8D83B161B938EF4F5E866748_inline (Func_2_t9622A5472E3EB564FD9AA65F9666F983FA8CA079* __this, MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF ___0_arg, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m828EB26F6BCE9B7DC682DF2DB6500C146BF74ED9_inline (List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF List_1_get_Item_m2455DF403BC23EF806BBB35F26A197F1AA270CAC (List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268* __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline int32_t Func_2_Invoke_m4C0458CE84ED9C58132692F135BB07908074DC06_inline (Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577* __this, StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF ___0_arg, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577*, StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF, const RuntimeMethod*))Func_2_Invoke_m4C0458CE84ED9C58132692F135BB07908074DC06_gshared_inline)(__this, ___0_arg, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m243F4E8CDDB9A9F83AA778B3F2A1DA639F65AFFE (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_m77408358E22109403619F8D5772C5BB0D90898E5 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_m346BA84F5DE67F951530A1FA79808C15A58E9BEE (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m4904C1101CBC6F7514E304F08A59D4D11FF21061 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_mDCB5C70225741FBD0A45FC7CF4AF86FFBE5F9082 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_mC42B46855B167085DF30F2EF8E5B972D224596E8 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_m305E33368392F6D1AD854746351A71687763E9AF (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_mD7415ADC961F9A1C7AA6A8E77C83534DCFC175AF (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_m85830C3F1A7DDFC22EDBAE2A99C08C617E793C58 (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m540F90AA5E678CB4111BAC286677FF58EAD5EF90 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedList_1__ctor_m4B39562DBE2738598CDBCE1DD4B2D04A52064F97 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnmanagedRefCountedList_1_get_UnsafeCount_m3EF1747E3FE4FA9731252DDDDAAF355D28F0E66F (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* __this, const RuntimeMethod* method) ;
inline void UnmanagedRefCountedList_1__ctor_m1A1BC9ABD2A9D7B9C7434073D1F52063C8F92056 (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, int32_t, const RuntimeMethod*))UnmanagedRefCountedList_1__ctor_m1A1BC9ABD2A9D7B9C7434073D1F52063C8F92056_fshared)(__this, ___0_size, method);
}
inline void UnmanagedRefCountedListExtensions_Clear_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m3D75E429C1104D73A7D1533FEDB84C8776D97DC6 (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, const RuntimeMethod* method)
{
	((  void (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, const RuntimeMethod*))UnmanagedRefCountedListExtensions_Clear_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m3D75E429C1104D73A7D1533FEDB84C8776D97DC6_gshared)(___0_self, method);
}
inline void UnmanagedRefCountedList_1__ctor_m58403CFD1E60A2E9DF9DC8E7600CBC28F642089F (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	((  void (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, int32_t, const RuntimeMethod*))UnmanagedRefCountedList_1__ctor_m58403CFD1E60A2E9DF9DC8E7600CBC28F642089F_gshared)(__this, ___0_size, method);
}
inline int32_t UnmanagedRefCountedList_1_get_UnsafeCount_mC9425FE28356043DFC64EF65FC11F219FCA48380 (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*, const RuntimeMethod*))UnmanagedRefCountedList_1_get_UnsafeCount_mC9425FE28356043DFC64EF65FC11F219FCA48380_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t IntPtr_op_Explicit_mE2CEC14C61FD5E2159A03EA2AD97F5CDC5BB9F4D (void* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_SetCapacity_mF80BF3DD388E819E52586A458C10606333611269 (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9 (uint64_t ___0_offset, int32_t ___1_alignmentPowerOfTwo, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m934C9E3CBBFA04ABEF4528E565C300B5DCF8C2D1_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177 (void* ___0_destination, void* ___1_source, int64_t ___2_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_Add_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m115C1E10CFF2E5179C099DDD59C5779D0863C1C1 (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_Add_m1CE98EFF1C7CAFEDCDE896B21530D3B2A3311D25 (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, void* ___0_ptr, int32_t ___1_structSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeListExtensions_IndexOf_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mAAD5AAC095A0510309AEAA951828DAE9B8C783A2 (UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E ___0_container, GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tA7B55DDCFA4B3B474C0F1DCFCEADB2ABB0EC8F10 UnsafeList_1_AsReadOnlySpan_m0B9F520E68A4F8F1C7DE958A934E9AFB5D86B53A (UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeArrayExtensions_IndexOf_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m6F4F2F3FD9AEB9A0266F285F36171E22C3501B90 (ReadOnlySpan_1_tA7B55DDCFA4B3B474C0F1DCFCEADB2ABB0EC8F10 ___0_roSpan, GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663 (bool ___0_condition, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5 (int64_t ___0_size, int32_t ___1_align, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_allocator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline (int64_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEA2D219466CA70D0772888D0B2AA5BDF95B3D7B0 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m1889622A4F9D451311D704800071C27E203E30FD (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m53A432E510AFC1B5E17AC7D4CEA9BDC969EF4183 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mBBBCD7A3795516F652E2A209921D9F365FEF117D (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_mFCFCB281237C3FD181B82326F1CDC74ECDC26835 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m28DB190FC25AC6811E2F609C118B25148772E8ED (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m97E2EBA7DBA4EC678CB7F7D5A1E14B2687937D9B (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_mEE7449D53E0B0DF2588A7ABF7DE9C12E23AEC194 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m5EF0E0217EB20D03E739EF4F21BA8ED27454FBA1 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m11C03B89A0BC9969D9C5F48944DA915764AB7653 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m1039B6A2212089AF73B18D7545E9DC3D3DF22E44 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m4AC175F5FE1C77C9A2E7602A09E229A5CF617FAF (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m7CF1071B4128F92A069498179CE85F80CB5AEBE1 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m47E7EA1FA34E44C4B7E215FA109EFC5813E93948 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m84BBCADD738D8E17724D100724F1173F24CC9D46 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m92740FC50E0692378ABED6D572FE0AA5FFF18DFB (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82 (int64_t ___0_size, int32_t ___1_alignmentPowerOfTwo, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 UnsafeUtility_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_mFD7DBC1199616005466125347027F6201459B40D_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C UnsafeUtility_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mFDF2C4591B5F4C0AF4424ED681225F9CF100C5BB_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m4BCBCB4D1AC60559B41D33E7097084B82F700097 (NativeKeyValueArrays_2_t6F346645686D9ED3DF9980242A60F6343D9BD346* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_mBEBDFF6E64411CCDC46D8A00FF46DD9D99082631 (NativeKeyValueArrays_2_t5F8B14A1FC3085C8F576054B525A95D4898297D8* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UnsafeUtility_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_mF765CB2E5FD631DFB79C25DE656F3C1BB359B995_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m4F24A3063C8E3F28E85784A8E086E8ABCEF80123 (NativeKeyValueArrays_2_t66B0B299E9562B5E22EF3BF01729F553EF5A1143* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 UnsafeUtility_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m2E442046FFC024C177FCA6130678FA0B97F3C445_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m686910AE937E76C8D8BAC2FA971F98F55668D1A1 (NativeKeyValueArrays_2_tA2DA312B446D1C4E01DFB5BABCD5FD907A6D98BB* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 UnsafeUtility_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mF42F014B5AA9C633D3FCAB3FFF26646E54395BD8_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_mFCC843E8A6076977EDC711B85D5A812409F96A92 (NativeKeyValueArrays_2_t69F48B55F7CB9E53D8DA8AC22D78A9FE2C4ACCBB* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B UnsafeUtility_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m86FC76E325E9D3B56133BB7A193BAF12B47FBCC1_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m8AD3EFA2ADD479EB790D599C9BF297BBFE6A6E22 (NativeKeyValueArrays_2_tCBCD37F108CC29AF7DD444E7DADEBD5DA915330C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m70A3BFBC8F88E9B0C7044FD84799B8FD2D4CF586 (NativeKeyValueArrays_2_t1DC3FE19F0B4A1DF25136B0397012CFE6BE2C193* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 UnsafeUtility_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_mAEB04091BED5994494AB1521F1CA283C9A55DA84_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m8AA40536A05046C7F2594BBDB7694F1C91CA23CF (NativeKeyValueArrays_2_t2DFE6540DA40D93DF34F283B6ED85D911565BD6D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 UnsafeUtility_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m6C484995D5C95208A4EB1F0C7664EC42A74DE670_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m2DE1DE05F01D53EE056876CE742559C9DA71D08E (NativeKeyValueArrays_2_t92055CB18DB710BBBCD3CC5107937B10BFDCEA2A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 UnsafeUtility_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m80C61348EC8F9D4F73F0AAA4A69A028E6D599DCD_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m24BCC1A996AF2B999A11BAC7FF1B589574131C68 (NativeKeyValueArrays_2_t637F773818E79D65A71945EFC311230CEF0730EC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m95CF0086C8462E4956EA2941717F496F9E9157A2 (NativeKeyValueArrays_2_tBB45ADF53F7E53E64A0AF63EF8702A771FDA1956* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_mED5744BD99EE505BA094FB2E2D3E1460FBF35AD9 (NativeKeyValueArrays_2_t93070D4261139B002601B084DE32FFA5AA5488CE* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 UnsafeUtility_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m361058B0E058D8D5D3AC6C6C015700E6018A671C_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m02951443FBCF5B78507CC0C916DA7B406A6E2FFC (NativeKeyValueArrays_2_t00C5D2C7AF9D9E3622CAB210E6E11E33C4881C8A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 UnsafeUtility_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m8460969BD9998B0DFF865186874B2414FEED12C8_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m354A6BD5F31BC54C9F3D2B8A51EF1C71C9005648 (NativeKeyValueArrays_2_t5B99C2646C28A5C04DF011E6E993BDE26A27A953* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m0DD220DB30C031B6200A4119D0DCF56B565846E6 (NativeKeyValueArrays_2_tD4417ED5E6C2DAC8437C9159D79F622F83C72D39* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 UnsafeUtility_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m2A66DBE83F9498AC60B42C9A0B1C7E4401B4CDCC_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeKeyValueArrays_2_get_Length_m8C99316414D47C54EF1AFF05D069266C1FE65840 (NativeKeyValueArrays_2_t4AA59D24D1616F48DCDB5CB6C4ABA336C51B1764* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t DrawKey_GetHashCode_m6E3C5F3D42D02D8035AA7E7B5501FDBC1551F4E5 (DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271 (uint8_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410 (EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GPUArchetypeHandle_GetHashCode_mF816A596DEE9C2CA813E280D5DB3FE046085480C (GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GPUComponentSet_GetHashCode_mD21ED0964434E73545827D58153D059227B51B21 (GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RangeKey_GetHashCode_mC38845B6A1CC657D6F6B1149E7448AA6A3EF3257 (RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC (uint32_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CollectionHelper_Align_m0F9A1D60694634D775C811136208ED02D7665F2F (int32_t ___0_size, int32_t ___1_alignmentPowerOfTwo, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeQueueData_SetCurrentWriteBlockTLS_mE8BF637642E13044DFF8A34A55B8AE0B33A5F727_inline (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* __this, int32_t ___0_threadIndex, UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___1_currentWriteBlock, const RuntimeMethod* method) ;
inline void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared)(__this, ___0_item, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m312FD1D94C51FFE92899836D9F020617D431BBF5_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mDEDCEBAF0C62FDCD22EA85CBDDBAFADD5CCB7915_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m2B47DA4F1DF05E028EEA414B4BC8C82E8FCF4481_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_mA5EE4C645904072BD057D41FC7D1AABAB3B4E398_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m77A7D05474DF60C828E063E75D6A6C52B0BB8A0A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m61E51176F8D18A3C2FC21CECC8908B35B9DB5F3D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mFF371C2E5F2018BDF838A2BBC5AC30EA7C74230E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mF8CB5ED1AEDA173F1F15E75017828AA38AE9E6EA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m851FFDFB05C6D16BC27B3BAD2B486229B48796FB_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m67C30665BD5F032BA4790CB4F198C5128D65FA1B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m952393E8A8C420CA0DEAB80F495FF991803AE4CD_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m86AC2282B14EEB2988DF554898FE8D12B6968652_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m501662FEF1C371DA264F4A8F86497DD85C6576C8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m36CB3A618AC04CD0E869A5C34BAE8DBFDEA34119_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m3BF032FF33CB8E4BAD8B53BCB58362D59F473562_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m7936CCEA1FD37B0D005189C07C3FAAC4E016B792_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6C6F7ABC33BDF25A69E8A2E8DE137DB2ACB77FDC_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 UnsafeUtilityInternal_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_m108E077C32AC45BC5336988B727DADDF1711407A_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeUtilityInternal_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mDC8A7125EE74C940B9F940440D412BA4B3A42575_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB UnsafeUtilityInternal_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m0C048047EB886D78B484166DCB014DF594B085BD_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m4E657D67A0253D6AA48A0AF0834D8B8B4D986C48_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C UnsafeUtilityInternal_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mC6AFEEF7260AB50C6AC741C83424DB3F59ECA569_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t UnsafeUtilityInternal_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mAA4A4AC11C7C0784A0566FAE86EFBAD08CF4126D_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UnsafeUtilityInternal_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m504EAEDFA7F1C3551FBC5F11CFB40360033F8B84_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 UnsafeUtilityInternal_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_mB00BADAC0C27D3EBF922C4D9514DBAFFE7570306_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 UnsafeUtilityInternal_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_m03D847364989884CB1A8D031CFBB7BAACDF29EB2_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B UnsafeUtilityInternal_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m6FD81C4AA7D25C02FAA41E4FDDA346959381646F_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 UnsafeUtilityInternal_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m11FC059EDD11872BC9AA0E4A69DE23575103FCB9_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 UnsafeUtilityInternal_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m25474EB27C8162D7A4BDF444168565682AC81612_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 UnsafeUtilityInternal_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m986ED2902CE4A51ABE99D9309F33BEE50D219A80_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m0863D7A09467FAC3CAE8A852D088E9E980F02756_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 UnsafeUtilityInternal_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_mFD8E968B6D42F987231C2D4D4433BC15E231FB83_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 UnsafeUtilityInternal_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m3358302574C84901BFC17BF5A4E83AD5C5475245_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2F30078087CCDB55F8D473591F4FDE09CBEB5D9C_m55C940043B5A1852EB5C37BA424A6AC9A7B4260D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t8866C28BEBC43BE45C777354FACE06E5D80D8AF1_m98779B037E081B8050E0B38AEAF0844112F9EBCA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t938D5D39EB34C9404E00E05DA835AEAF195EED60_mEAD7EEB63B4DF320E2B845B35B5279D7DE3A79D1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t12EA8BB9031D0D42734685DAB3E0DC8CDE6F7844_mF7669FB4FDB08DEECFB97E2BE96E4ABE06854B8A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA1529F9F8B7FA790F2938A80AD16F77284A61D04_mA13156A8148DE6FA510A7CC74B7B821794A925C7_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA801A0280FB34492FDCB3CB6E3234C95DCA0A512_mC956A5504B875A9255F4031549F4DA7B47AEE47B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2E41B87D9D08BFCD38A18DAFF9D1503CD262A669_m95A0D6A4B8D13CC09EF01FF9975C8AB46CDD7086_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFFFE7CB6FDF697D25267CACBE063159F38998B83_m5EF673BA7CA5471B065B0509F1A5949AADC5747A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;
// Method Definition Index: 54619
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UniversalRenderPipeline_ProcessRenderRequests_TisIl2CppFullySharedGenericAny_mDA545F6D05108DA4899629AEE6B8356279506772_fshared (UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F* __this, ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___0_context, Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___1_camera, Il2CppFullySharedGenericAny ___2_renderRequest, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_TryGetComponent_TisUniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93_mBCAEF774AB0C0563A29C16F3A5305AE1A081C3BD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ListPool_1_Get_m7E32B4B150CCC0A396B9CFA7D60862F765DE7C15_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ListPool_1_t97F6AE398781016115DBD2B6A4A443FD4FF438E6_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m9BE0CD6DB63BFCBCBD5619618748924143F1AFAD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m735F7A05528CC71E71E3019311F2E22CF9E2C681_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tD2FA3273746E404D72561E8324608D18B52B533E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PooledObject_System_IDisposable_Dispose_m2C53DF93B31EF48C987A0FD22DEE119FDDD30E93_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral48B5843525C3BEF16B7BE787788398005CFE4D6C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral51A257776A6F5C5A85BB79B0C0B56E420A4C92B6);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral80F0368CFBC6552AC1C79FAE29101F4E1345BD2A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB8468D10D94786B5C421B4ACD80BF46EAAA054DD);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_RequestData_t23AF8AF1732E49524440830F612EE084B6253A37 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	CHECKED_LOCAL(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticInit);
	CHECKED_LOCAL(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_StaticInit);
	CHECKED_LOCAL(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_StaticInit);
	CHECKED_LOCAL(ListPool_1_t97F6AE398781016115DBD2B6A4A443FD4FF438E6_StaticInit);
	CHECKED_LOCAL(ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_StaticInit);
	CHECKED_LOCAL(CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_StaticInit);
	CHECKED_LOCAL(UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F_StaticInit);
	CHECKED_LOCAL(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticInit);
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_RequestData_t23AF8AF1732E49524440830F612EE084B6253A37);
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_RequestData_t23AF8AF1732E49524440830F612EE084B6253A37);
	//<source_info:<no-source>:1>
	StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* V_0 = NULL;
	SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24* V_1 = NULL;
	RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* V_7 = NULL;
	RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* V_8 = NULL;
	RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 V_9;
	memset((&V_9), 0, sizeof(V_9));
	RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 V_10;
	memset((&V_10), 0, sizeof(V_10));
	List_1_tD2FA3273746E404D72561E8324608D18B52B533E* V_11 = NULL;
	PooledObject_t6A17503D2E86923ADABDFFE03F1EA5163EAF076B V_12;
	memset((&V_12), 0, sizeof(V_12));
	ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70 V_13;
	memset((&V_13), 0, sizeof(V_13));
	CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86 V_14;
	memset((&V_14), 0, sizeof(V_14));
	UniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93* V_15 = NULL;
	bool V_16 = false;
	int32_t V_17 = 0;
	RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* G_B5_0 = NULL;
	int32_t G_B10_0 = 0;
	int32_t G_B13_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B19_0 = 0;
	int32_t G_B21_0 = 0;
	int32_t G_B20_0 = 0;
	int32_t G_B23_0 = 0;
	int32_t G_B22_0 = 0;
	int32_t G_B24_0 = 0;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* G_B28_0 = NULL;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* G_B27_0 = NULL;
	RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* G_B29_0 = NULL;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* G_B29_1 = NULL;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___2_renderRequest : &___2_renderRequest), SizeOf_RequestData_t23AF8AF1732E49524440830F612EE084B6253A37);
		RuntimeObject* L_1 = il2cpp_codegen_isinst_runtime_class(il2cpp_rgctx_data(method->rgctx_data, 0), StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53_il2cpp_TypeInfo_var, L_0);;
		V_0 = (StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53*)L_1;
		il2cpp_codegen_memcpy(L_2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___2_renderRequest : &___2_renderRequest), SizeOf_RequestData_t23AF8AF1732E49524440830F612EE084B6253A37);
		RuntimeObject* L_3 = il2cpp_codegen_isinst_runtime_class(il2cpp_rgctx_data(method->rgctx_data, 0), SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24_il2cpp_TypeInfo_var, L_2);;
		V_1 = (SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24*)L_3;
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_4 = V_0;
		if (L_4)
		{
			goto IL_0021;
		}
	}
	{
		SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24* L_5 = V_1;
		if (!L_5)
		{
			goto IL_0313;
		}
	}

IL_0021:
	{
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_6 = V_0;
		if (L_6)
		{
			goto IL_002c;
		}
	}
	{
		SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24* L_7 = V_1;
		NullCheck(L_7);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_8 = L_7->___destination;
		G_B5_0 = L_8;
		goto IL_0032;
	}

IL_002c:
	{
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_9 = V_0;
		NullCheck(L_9);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_10 = L_9->___destination;
		G_B5_0 = L_10;
	}

IL_0032:
	{
		V_2 = G_B5_0;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_11 = V_2;
		CHECKED_LOCAL_INIT(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticInit,(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		bool L_12;
		L_12 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_11, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_12)
		{
			goto IL_0047;
		}
	}
	{
		CHECKED_LOCAL_INIT(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_StaticInit,(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteralB8468D10D94786B5C421B4ACD80BF46EAAA054DD, NULL);
		return;
	}

IL_0047:
	{
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_13 = V_0;
		if (L_13)
		{
			goto IL_0052;
		}
	}
	{
		SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24* L_14 = V_1;
		NullCheck(L_14);
		int32_t L_15 = L_14->___mipLevel;
		G_B10_0 = L_15;
		goto IL_0058;
	}

IL_0052:
	{
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_16 = V_0;
		NullCheck(L_16);
		int32_t L_17 = L_16->___mipLevel;
		G_B10_0 = L_17;
	}

IL_0058:
	{
		V_3 = G_B10_0;
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_18 = V_0;
		if (L_18)
		{
			goto IL_0064;
		}
	}
	{
		SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24* L_19 = V_1;
		NullCheck(L_19);
		int32_t L_20 = L_19->___slice;
		G_B13_0 = L_20;
		goto IL_006a;
	}

IL_0064:
	{
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_21 = V_0;
		NullCheck(L_21);
		int32_t L_22 = L_21->___slice;
		G_B13_0 = L_22;
	}

IL_006a:
	{
		V_4 = G_B13_0;
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_23 = V_0;
		if (L_23)
		{
			goto IL_0077;
		}
	}
	{
		SingleCameraRequest_tF902D3B3D32643E8D9E7D3E4D87741C01B983A24* L_24 = V_1;
		NullCheck(L_24);
		int32_t L_25 = L_24->___face;
		G_B16_0 = L_25;
		goto IL_007d;
	}

IL_0077:
	{
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_26 = V_0;
		NullCheck(L_26);
		int32_t L_27 = L_26->___face;
		G_B16_0 = L_27;
	}

IL_007d:
	{
		V_5 = G_B16_0;
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_28 = V_0;
		if (L_28)
		{
			goto IL_0085;
		}
	}
	{
		G_B19_0 = 0;
		goto IL_008b;
	}

IL_0085:
	{
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_29 = V_0;
		NullCheck(L_29);
		bool L_30 = L_29->___isPreview;
		G_B19_0 = ((int32_t)(L_30));
	}

IL_008b:
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_31 = ___1_camera;
		NullCheck(L_31);
		int32_t L_32;
		L_32 = Camera_get_cameraType_m85434C4C986D2EAC04FBFA44B284840AFC497851(L_31, NULL);
		V_6 = L_32;
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_33 = ___1_camera;
		NullCheck(L_33);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_34;
		L_34 = Camera_get_targetTexture_mC856D7FF8351476068D04E245E4F08F5C56A55BD(L_33, NULL);
		V_7 = L_34;
		V_8 = (RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27*)NULL;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_35 = V_2;
		NullCheck(L_35);
		RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 L_36;
		L_36 = RenderTexture_get_descriptor_m2FABD5CF6CCF410D1311FCBC7C9D9ECDEE9C7CC2(L_35, NULL);
		V_9 = L_36;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_37 = V_2;
		NullCheck(L_37);
		int32_t L_38;
		L_38 = VirtualFuncInvoker0< int32_t >::Invoke(9, L_37);
		if ((!(((uint32_t)L_38) == ((uint32_t)4))))
		{
			G_B21_0 = G_B19_0;
			goto IL_00b7;
		}
		G_B20_0 = G_B19_0;
	}
	{
		il2cpp_codegen_initobj((&V_9), sizeof(RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46));
		G_B21_0 = G_B20_0;
	}

IL_00b7:
	{
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_39 = V_2;
		NullCheck(L_39);
		int32_t L_40;
		L_40 = RenderTexture_get_format_m58556ABB91A1FADA8044BEEA2E8C55280768CF35(L_39, NULL);
		RenderTextureDescriptor_set_colorFormat_m61B0FA4FCDE8A0F8A843DD6BF74097C21021C4FE((&V_9), L_40, NULL);
		RenderTextureDescriptor_set_volumeDepth_mEF9610D1C14182417A01B7243DEE6B559A13B34D_inline((&V_9), 1, NULL);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_41 = V_2;
		NullCheck(L_41);
		RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 L_42;
		L_42 = RenderTexture_get_descriptor_m2FABD5CF6CCF410D1311FCBC7C9D9ECDEE9C7CC2(L_41, NULL);
		V_10 = L_42;
		int32_t L_43;
		L_43 = RenderTextureDescriptor_get_msaaSamples_mFCC33643AFF2265C8305DCFD79ED8774A1A8FA22_inline((&V_10), NULL);
		RenderTextureDescriptor_set_msaaSamples_m6910E09489372746391B14FBAF59A7237539D6C4_inline((&V_9), L_43, NULL);
		RenderTextureDescriptor_set_dimension_mCE9A4A08454BB2D9DFE3E505EC336FD480078F39_inline((&V_9), 2, NULL);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_44 = V_2;
		NullCheck(L_44);
		int32_t L_45;
		L_45 = VirtualFuncInvoker0< int32_t >::Invoke(5, L_44);
		int32_t L_46 = V_3;
		double L_47 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_46,NULL));
		CHECKED_LOCAL_INIT(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_StaticInit,(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		double L_48;
		L_48 = Math_Pow_mEAE651F0858203FBE12B72B6A53951BBD0FB5265((2.0), L_47, NULL);
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(L_48,NULL));
		RenderTextureDescriptor_set_width_m3B2494007BFE3AD4D14403407C9B24F5045E7E10_inline((&V_9), ((int32_t)(L_45/L_49)), NULL);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_50 = V_2;
		NullCheck(L_50);
		int32_t L_51;
		L_51 = VirtualFuncInvoker0< int32_t >::Invoke(7, L_50);
		int32_t L_52 = V_3;
		double L_53 = (il2cpp_codegen_conv<double,int32_t,int32_t,false,false>(L_52,NULL));
		double L_54;
		L_54 = Math_Pow_mEAE651F0858203FBE12B72B6A53951BBD0FB5265((2.0), L_53, NULL);
		int32_t L_55 = (il2cpp_codegen_conv<int32_t,double,double,false,false>(L_54,NULL));
		RenderTextureDescriptor_set_height_m1FE41111472DAA9B5E80FFAF3445004D72A3CFA5_inline((&V_9), ((int32_t)(L_51/L_55)), NULL);
		int32_t L_56;
		L_56 = RenderTextureDescriptor_get_width_mB159E4EB08B23B19CCCFADB465864361FB840BFF_inline((&V_9), NULL);
		int32_t L_57;
		L_57 = Mathf_Max_m7FA442918DE37E3A00106D1F2E789D65829792B8_inline(1, L_56, NULL);
		RenderTextureDescriptor_set_width_m3B2494007BFE3AD4D14403407C9B24F5045E7E10_inline((&V_9), L_57, NULL);
		int32_t L_58;
		L_58 = RenderTextureDescriptor_get_height_m1006F9AA45029715C552C8A8C2F102F63D3A91EC_inline((&V_9), NULL);
		int32_t L_59;
		L_59 = Mathf_Max_m7FA442918DE37E3A00106D1F2E789D65829792B8_inline(1, L_58, NULL);
		RenderTextureDescriptor_set_height_m1FE41111472DAA9B5E80FFAF3445004D72A3CFA5_inline((&V_9), L_59, NULL);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_60 = V_2;
		NullCheck(L_60);
		int32_t L_61;
		L_61 = VirtualFuncInvoker0< int32_t >::Invoke(9, L_60);
		if ((!(((uint32_t)L_61) == ((uint32_t)2))))
		{
			G_B23_0 = G_B21_0;
			goto IL_015c;
		}
		G_B22_0 = G_B21_0;
	}
	{
		int32_t L_62 = V_3;
		if (!L_62)
		{
			G_B24_0 = G_B22_0;
			goto IL_0165;
		}
		G_B23_0 = G_B22_0;
	}

IL_015c:
	{
		RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46 L_63 = V_9;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_64;
		L_64 = RenderTexture_GetTemporary_mA8C827B80D3C07D0B8CDF7F5270FB5D3E53DD235(L_63, NULL);
		V_8 = L_64;
		G_B24_0 = G_B23_0;
	}

IL_0165:
	{
		if (!G_B24_0)
		{
			goto IL_016e;
		}
	}
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_65 = ___1_camera;
		NullCheck(L_65);
		Camera_set_cameraType_m20ECE54572F8B7CAF5D32193B65F3D7812E20F17(L_65, 4, NULL);
	}

IL_016e:
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_66 = ___1_camera;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_67 = V_8;
		CHECKED_LOCAL_INIT(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticInit,(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		bool L_68;
		L_68 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_67, NULL);
		if (L_68)
		{
			G_B28_0 = L_66;
			goto IL_017b;
		}
		G_B27_0 = L_66;
	}
	{
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_69 = V_2;
		G_B29_0 = L_69;
		G_B29_1 = G_B27_0;
		goto IL_017d;
	}

IL_017b:
	{
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_70 = V_8;
		G_B29_0 = L_70;
		G_B29_1 = G_B28_0;
	}

IL_017d:
	{
		NullCheck(G_B29_1);
		Camera_set_targetTexture_mE6C740F21A72DA47FB5B1D31D208710738A836C4(G_B29_1, G_B29_0, NULL);
		StandardRequest_t74A964925918EB8C1578B4A825EFE91A0C7D8B53* L_71 = V_0;
		if (!L_71)
		{
			goto IL_019a;
		}
	}
	{
		ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 L_72 = ___0_context;
		List_1_tD2FA3273746E404D72561E8324608D18B52B533E* L_73 = (List_1_tD2FA3273746E404D72561E8324608D18B52B533E*)il2cpp_codegen_object_new(List_1_tD2FA3273746E404D72561E8324608D18B52B533E_il2cpp_TypeInfo_var);
		List_1__ctor_m735F7A05528CC71E71E3019311F2E22CF9E2C681(L_73, List_1__ctor_m735F7A05528CC71E71E3019311F2E22CF9E2C681_RuntimeMethod_var);
		List_1_tD2FA3273746E404D72561E8324608D18B52B533E* L_74 = L_73;
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_75 = ___1_camera;
		NullCheck(L_74);
		List_1_Add_m9BE0CD6DB63BFCBCBD5619618748924143F1AFAD_inline(L_74, L_75, List_1_Add_m9BE0CD6DB63BFCBCBD5619618748924143F1AFAD_RuntimeMethod_var);
		VirtualActionInvoker2< ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36, List_1_tD2FA3273746E404D72561E8324608D18B52B533E* >::Invoke(7, __this, L_72, L_74);
		goto IL_0202;
	}

IL_019a:
	{
		CHECKED_LOCAL_INIT(ListPool_1_t97F6AE398781016115DBD2B6A4A443FD4FF438E6_StaticInit,(ListPool_1_t97F6AE398781016115DBD2B6A4A443FD4FF438E6_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		PooledObject_t6A17503D2E86923ADABDFFE03F1EA5163EAF076B L_76;
		L_76 = ListPool_1_Get_m7E32B4B150CCC0A396B9CFA7D60862F765DE7C15((&V_11), ListPool_1_Get_m7E32B4B150CCC0A396B9CFA7D60862F765DE7C15_RuntimeMethod_var);
		V_12 = L_76;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_01f4:
			{
				PooledObject_System_IDisposable_Dispose_m2C53DF93B31EF48C987A0FD22DEE119FDDD30E93((&V_12), PooledObject_System_IDisposable_Dispose_m2C53DF93B31EF48C987A0FD22DEE119FDDD30E93_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				List_1_tD2FA3273746E404D72561E8324608D18B52B533E* L_77 = V_11;
				Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_78 = ___1_camera;
				NullCheck(L_77);
				List_1_Add_m9BE0CD6DB63BFCBCBD5619618748924143F1AFAD_inline(L_77, L_78, List_1_Add_m9BE0CD6DB63BFCBCBD5619618748924143F1AFAD_RuntimeMethod_var);
				ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 L_79 = ___0_context;
				List_1_tD2FA3273746E404D72561E8324608D18B52B533E* L_80 = V_11;
				ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70 L_81;
				memset((&L_81), 0, sizeof(L_81));
				ContextRenderingScope__ctor_m59F5F0D796371C51FC2BD08A9E2DBC0EA6C32003((&L_81), L_79, L_80, NULL);
				V_13 = L_81;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_01e6_1:
					{
						CHECKED_LOCAL_INIT(ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_StaticInit,(ContextRenderingScope_t41F3C30482A93F2E0777958D2D1DAB7357F2DA70_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
						ContextRenderingScope_Dispose_mB51673C299E1DAA325206945F442709AF153868D((&V_13), NULL);
						return;
					}
				});
				try
				{
					{
						ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 L_82 = ___0_context;
						Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_83 = ___1_camera;
						CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86 L_84;
						memset((&L_84), 0, sizeof(L_84));
						CameraRenderingScope__ctor_mB6900429BFF6B78AF2325B36B44C96101329BD2C((&L_84), L_82, L_83, NULL);
						V_14 = L_84;
					}
					{
						auto __finallyBlock = il2cpp::utils::Finally([&]
						{

FINALLY_01d8_2:
							{
								CHECKED_LOCAL_INIT(CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_StaticInit,(CameraRenderingScope_t22DC9DD80675F9F4798118075227E437E22B0D86_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
								CameraRenderingScope_Dispose_m7E450211F8C22CDF76970E0BC4FA3832ECE0E3C5((&V_14), NULL);
								return;
							}
						});
						try
						{
							Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_85 = ___1_camera;
							NullCheck(L_85);
							GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_86;
							L_86 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_85, NULL);
							NullCheck(L_86);
							bool L_87;
							L_87 = GameObject_TryGetComponent_TisUniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93_mBCAEF774AB0C0563A29C16F3A5305AE1A081C3BD(L_86, (&V_15), GameObject_TryGetComponent_TisUniversalAdditionalCameraData_t57B5D0F93C2D506E618E23187302C0FADE813B93_mBCAEF774AB0C0563A29C16F3A5305AE1A081C3BD_RuntimeMethod_var);
							ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 L_88 = ___0_context;
							Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_89 = ___1_camera;
							CHECKED_LOCAL_INIT(UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F_StaticInit,(UniversalRenderPipeline_t54B4737DC500C08628C5BE283D8C583C14DED98F_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
							UniversalRenderPipeline_RenderSingleCameraInternal_mF40EDE5547E0DDE493AE06455C9928313D54E1AB(L_88, L_89, (&V_15), (bool)1, NULL);
							goto IL_0202;
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

IL_0202:
	{
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_90 = V_8;
		CHECKED_LOCAL_INIT(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticInit,(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		bool L_91;
		L_91 = Object_op_Implicit_m93896EF7D68FA113C42D3FE2BC6F661FC7EF514A(L_90, NULL);
		if (!L_91)
		{
			goto IL_02f4;
		}
	}
	{
		V_16 = (bool)0;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_92 = V_2;
		NullCheck(L_92);
		int32_t L_93;
		L_93 = VirtualFuncInvoker0< int32_t >::Invoke(9, L_92);
		V_17 = L_93;
		int32_t L_94 = V_17;
		switch (((int32_t)il2cpp_codegen_subtract((int32_t)L_94, 2)))
		{
			case 0:
			{
				goto IL_023b;
			}
			case 1:
			{
				goto IL_0273;
			}
			case 2:
			{
				goto IL_028e;
			}
			case 3:
			{
				goto IL_0258;
			}
			case 4:
			{
				goto IL_02a9;
			}
		}
	}
	{
		goto IL_02c7;
	}

IL_023b:
	{
		int32_t L_95;
		L_95 = SystemInfo_get_copyTextureSupport_m35C5E2D749B53757DD6F05492B5D79F364F466C2(NULL);
		if (!((int32_t)((int32_t)L_95&1)))
		{
			goto IL_02c7;
		}
	}
	{
		V_16 = (bool)1;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_96 = V_8;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_97 = V_2;
		int32_t L_98 = V_3;
		CHECKED_LOCAL_INIT(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_StaticInit,(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Graphics_CopyTexture_m306EE635C15C8118A93D947A5183E5134B4EE718(L_96, 0, 0, L_97, 0, L_98, NULL);
		goto IL_02c7;
	}

IL_0258:
	{
		int32_t L_99;
		L_99 = SystemInfo_get_copyTextureSupport_m35C5E2D749B53757DD6F05492B5D79F364F466C2(NULL);
		if (!((int32_t)((int32_t)L_99&4)))
		{
			goto IL_02c7;
		}
	}
	{
		V_16 = (bool)1;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_100 = V_8;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_101 = V_2;
		int32_t L_102 = V_4;
		int32_t L_103 = V_3;
		CHECKED_LOCAL_INIT(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_StaticInit,(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Graphics_CopyTexture_m306EE635C15C8118A93D947A5183E5134B4EE718(L_100, 0, 0, L_101, L_102, L_103, NULL);
		goto IL_02c7;
	}

IL_0273:
	{
		int32_t L_104;
		L_104 = SystemInfo_get_copyTextureSupport_m35C5E2D749B53757DD6F05492B5D79F364F466C2(NULL);
		if (!((int32_t)((int32_t)L_104&4)))
		{
			goto IL_02c7;
		}
	}
	{
		V_16 = (bool)1;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_105 = V_8;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_106 = V_2;
		int32_t L_107 = V_4;
		int32_t L_108 = V_3;
		CHECKED_LOCAL_INIT(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_StaticInit,(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Graphics_CopyTexture_m306EE635C15C8118A93D947A5183E5134B4EE718(L_105, 0, 0, L_106, L_107, L_108, NULL);
		goto IL_02c7;
	}

IL_028e:
	{
		int32_t L_109;
		L_109 = SystemInfo_get_copyTextureSupport_m35C5E2D749B53757DD6F05492B5D79F364F466C2(NULL);
		if (!((int32_t)((int32_t)L_109&4)))
		{
			goto IL_02c7;
		}
	}
	{
		V_16 = (bool)1;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_110 = V_8;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_111 = V_2;
		int32_t L_112 = V_5;
		int32_t L_113 = V_3;
		CHECKED_LOCAL_INIT(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_StaticInit,(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Graphics_CopyTexture_m306EE635C15C8118A93D947A5183E5134B4EE718(L_110, 0, 0, L_111, L_112, L_113, NULL);
		goto IL_02c7;
	}

IL_02a9:
	{
		int32_t L_114;
		L_114 = SystemInfo_get_copyTextureSupport_m35C5E2D749B53757DD6F05492B5D79F364F466C2(NULL);
		if (!((int32_t)((int32_t)L_114&4)))
		{
			goto IL_02c7;
		}
	}
	{
		V_16 = (bool)1;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_115 = V_8;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_116 = V_2;
		int32_t L_117 = V_5;
		int32_t L_118 = V_4;
		int32_t L_119 = V_3;
		CHECKED_LOCAL_INIT(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_StaticInit,(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Graphics_CopyTexture_m306EE635C15C8118A93D947A5183E5134B4EE718(L_115, 0, 0, L_116, ((int32_t)il2cpp_codegen_add(L_117, ((int32_t)il2cpp_codegen_multiply(L_118, 6)))), L_119, NULL);
	}

IL_02c7:
	{
		bool L_120 = V_16;
		if (L_120)
		{
			goto IL_02f4;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_121 = { reinterpret_cast<intptr_t> (TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_0_0_0_var) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_122;
		L_122 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_121, NULL);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_123 = V_2;
		NullCheck(L_123);
		int32_t L_124;
		L_124 = VirtualFuncInvoker0< int32_t >::Invoke(9, L_123);
		int32_t L_125 = L_124;
		RuntimeObject* L_126 = Box(TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_il2cpp_TypeInfo_var, &L_125);
		CHECKED_LOCAL_INIT(Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticInit,(Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		String_t* L_127;
		L_127 = Enum_GetName_m05FE85181853F756BA6BB2C033DD3590E6114D29(L_122, L_126, NULL);
		String_t* L_128;
		L_128 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral80F0368CFBC6552AC1C79FAE29101F4E1345BD2A, L_127, NULL);
		CHECKED_LOCAL_INIT(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_StaticInit,(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_128, NULL);
	}

IL_02f4:
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_129 = ___1_camera;
		int32_t L_130 = V_6;
		NullCheck(L_129);
		Camera_set_cameraType_m20ECE54572F8B7CAF5D32193B65F3D7812E20F17(L_129, L_130, NULL);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_131 = ___1_camera;
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_132 = V_7;
		NullCheck(L_131);
		Camera_set_targetTexture_mE6C740F21A72DA47FB5B1D31D208710738A836C4(L_131, L_132, NULL);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_133 = V_7;
		CHECKED_LOCAL_INIT(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_StaticInit,(Graphics_t99CD970FFEA58171C70F54DF0C06D315BD452F2C_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Graphics_SetRenderTarget_m995C0F14B97C5BF46CCF2E7EF410C1CC05C46409(L_133, NULL);
		RenderTexture_tBA90C4C3AD9EECCFDDCC632D97C29FAB80D60D27* L_134 = V_8;
		RenderTexture_ReleaseTemporary_mEEF2C1990196FF06FDD0DC190928AD3A023EBDD2(L_134, NULL);
		return;
	}

IL_0313:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_135 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 1)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_136;
		L_136 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_135, NULL);
		NullCheck(L_136);
		String_t* L_137;
		L_137 = VirtualFuncInvoker0< String_t* >::Invoke(28, L_136);
		String_t* L_138;
		L_138 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteral51A257776A6F5C5A85BB79B0C0B56E420A4C92B6, L_137, _stringLiteral48B5843525C3BEF16B7BE787788398005CFE4D6C, NULL);
		CHECKED_LOCAL_INIT(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_StaticInit,(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_138, NULL);
		return;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m0CF277E9039770CEC4022AFB1D6EB8187A3B8D56 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mE09F2B19DAC75EB997515A1B25AB0AF59AA37EDA_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m04DD2C89F805D820CAFA67B72D8261E1D52A75AA_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_mDC64A84FADB36AC678664DEB0E2ED51320D24CFD (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m6AD907969ED820C7B597DBDE5A62251F0BAAEBB5_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m581D10C30FE27399A9EDCCBB6EE26A6D79E5477E_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_mE93AD242A7232965E28EABAACB2AD8A7E3CF817B (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8E2B97AA6AB1779936EAA4893F7CE096024BCE54_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8291A5EAB6935532A5B3B16082E9709D3B425582_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m23FF3B4AB80847F0607DE7C906ADE023F45A7814 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m6BD3023222CB03E8462517B9F40193D9A085A1C2_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m8D4E16E3691F9835E03B880A9BE1B0F7A25F955B_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m2FE58388710FA5C5C336DBA2808E72DFF0DB2838 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_mF86E7726D232D0C06A598629B29651A120967D95_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m38864F218C1121BECFC7EFB1DB548BD52F5E77D1_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m7CBCF64BAF88AA5F19E6366F1D2DAE5BF4604469 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m257333772E743A0BFC11C2B733B8727A1379AC5D_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_mA0454C21C3291C32B45B2566A9D88C11C570AAB7_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m4A081AA1D9013D37593C1E63DE9FAA5D6DA253ED (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m7FE14B8744B411EBACDA2B154025806F5CAB4659_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m5586B4329861CC2D97E47E8ABBFB93BE29C41858_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_mEF2787E13090D4485875D00588A507CAFD8E2645 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m2C9EAB7C411248886CA8ADE580C3232DCE0942B8_inline(NULL);
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_mCB89996F323B06C4C16FFD580A8744DCF6E0EAE0_inline(NULL);
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 UnmanagedComponentType_Create_TisIl2CppFullySharedGenericStruct_m7584DBDC44C26F4D107EC1BF37B79CCEDF149A25_fshared (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87));
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___Size = L_0;
		int32_t L_1;
		L_1 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___Align = L_1;
		UnmanagedComponentType_tE2EB2660135166C7DE40CA311E36A7E884E78A87 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 21797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m243F4E8CDDB9A9F83AA778B3F2A1DA639F65AFFE (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit);
	//<source_info:<no-source>:1>
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_0 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = UnmanagedRefCountedList_1_get_IsEmpty_m2E14B74870630D7E8FED2C9B0B1ACE4BA16F0B1D(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m8C60A954A286528BD0B6CF0D629BD42DF5692251(L_2, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_000e:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_3 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 L_4;
		L_4 = UnmanagedRefCountedList_1_get_Empty_m27704059A53CF33AEF1259D47A403CD942B9731C(NULL);
		*(UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97*)L_3 = L_4;
		return;
	}
}
// Method Definition Index: 21797
// Method Definition Index: 21797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m4904C1101CBC6F7514E304F08A59D4D11FF21061 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit);
	//<source_info:<no-source>:1>
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_0 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = UnmanagedRefCountedList_1_get_IsEmpty_mFFEB115C88447058B106153933C2815CA0DB6030(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m7ACD2CB9146F490C6C3E71CEB1A4C1DD97F7336A(L_2, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_000e:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_3 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE L_4;
		L_4 = UnmanagedRefCountedList_1_get_Empty_mFC8CC3717E6C8ACF52A1A11863A2EC1B3C61B25A(NULL);
		*(UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE*)L_3 = L_4;
		return;
	}
}
// Method Definition Index: 21797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_m305E33368392F6D1AD854746351A71687763E9AF (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit);
	//<source_info:<no-source>:1>
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_0 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = UnmanagedRefCountedList_1_get_IsEmpty_m7F763A556B56D166DA9B84E3820FB94835F5533F(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m3317B0BACC15E51025A554B4C52F73B2417EFCBD(L_2, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_000e:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_3 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 L_4;
		L_4 = UnmanagedRefCountedList_1_get_Empty_m0EAA4D4244E7C3386545230900F0481C312D5169(NULL);
		*(UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281*)L_3 = L_4;
		return;
	}
}
// Method Definition Index: 21797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m540F90AA5E678CB4111BAC286677FF58EAD5EF90 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit);
	//<source_info:<no-source>:1>
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_0 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = UnmanagedRefCountedList_1_get_IsEmpty_m4A937075322F5292F9840A84932C8015F894DA96(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m019F92E6E6C2E3331D98817815F0D5E975A31BB6(L_2, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_000e:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_3 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 L_4;
		L_4 = UnmanagedRefCountedList_1_get_Empty_mAC8C90BA6702C35E53D2DDC7CD7477E718384457(NULL);
		*(UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5*)L_3 = L_4;
		return;
	}
}
// Method Definition Index: 21797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_TisIl2CppFullySharedGenericStruct_m6EFE521D8B6AA05E101FE1E54873BBCD9C8FF002_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* ___0_self, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit);
	//<source_info:<no-source>:1>
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_0 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_2, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_000e:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_3 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC L_4;
		L_4 = ((  UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(NULL);
		*(UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*)L_3 = L_4;
		return;
	}
}
// Method Definition Index: 21797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_Clear_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m3D75E429C1104D73A7D1533FEDB84C8776D97DC6_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit);
	//<source_info:<no-source>:1>
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_0 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = UnmanagedRefCountedList_1_get_IsEmpty_m521500F43BEA84B121D1ACDF22D20631BCDE3DFB(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_mB86F120A00B23B11FE39DA54CB3BEBCEC8751B17(L_2, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_000e:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_3 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t87CD4AEC707818F525F892B2778E5EEED8B2BCF0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC L_4;
		L_4 = UnmanagedRefCountedList_1_get_Empty_m20DF05F068FA42AE6EADC38351DED3E2006DCC16(NULL);
		*(UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*)L_3 = L_4;
		return;
	}
}
// Method Definition Index: 21799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_mB098E749A57B649583083B14E8D24BB8EB4778E3 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B* ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = List_1_get_Count_m714CDE1380C64F24D3FFA0C3A05220010855A1A3_inline(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_3 = ___0_self;
		int32_t L_4 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m2C5C294367EEC020C3F2A9955689C9EF20C1DCFB(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_002f;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4* L_7;
		L_7 = UnmanagedRefCountedList_1_get_Item_m8ADEB8E0DB44D0F2ED01510725A6C7C5F5AB9EF4(L_5, L_6, NULL);
		List_1_tE7FB077B3CEA6371A27F72CC60962491AB71490B* L_8 = ___1_other;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4 L_10;
		L_10 = List_1_get_Item_m96D208AAEBB2370590FC90F7F803453D7AE9F116(L_8, L_9, NULL);
		*(EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4*)L_7 = L_10;
		int32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_002f:
	{
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m27B7F3DB4ACBB7DA17C90DF92774440664F74BC5 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, ReadOnlySpan_1_t56EB56BD24E849B1A28025A5D541442A2AB282E7 ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0;
		L_0 = ReadOnlySpan_1_get_Length_mD966C06BF9402B65B5D1CB6E939CAD9FD1A56B6C_inline((&___1_other), NULL);
		V_0 = L_0;
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_1 = ___0_self;
		int32_t L_2 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m2C5C294367EEC020C3F2A9955689C9EF20C1DCFB(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0030;
	}

IL_0013:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_3 = ___0_self;
		int32_t L_4 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4* L_5;
		L_5 = UnmanagedRefCountedList_1_get_Item_m8ADEB8E0DB44D0F2ED01510725A6C7C5F5AB9EF4(L_3, L_4, NULL);
		int32_t L_6 = V_1;
		EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4* L_7;
		L_7 = il2cpp_span_get_item((EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4*)((Il2CppByReference*)&(((&___1_other))->____pointer))->value, (L_6), ((&___1_other))->____length);
		EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4 L_8 = (*(EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4*)L_7);
		*(EasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4*)L_5 = L_8;
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0030:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0013;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m52989E0F4A01D918A1357C61CDA1BCDB79DF0EC4 (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_0;
		L_0 = UnmanagedRefCountedList_1_get_IsEmpty_m2E14B74870630D7E8FED2C9B0B1ACE4BA16F0B1D((&___1_other), NULL);
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_1;
		L_1 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mC1A6A68B722E048D4FB2CF6CEA269887284C071F((&___1_other), NULL);
		int32_t* L_2 = L_1;
		int32_t L_3 = *(L_2);
		*(L_2) = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_0015:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_4 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_5;
		L_5 = UnmanagedRefCountedList_1_get_IsEmpty_m2E14B74870630D7E8FED2C9B0B1ACE4BA16F0B1D(L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_6 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m8C60A954A286528BD0B6CF0D629BD42DF5692251(L_6, il2cpp_rgctx_method(method->rgctx_data, 3));
	}

IL_0023:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_7 = ___0_self;
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 L_8 = ___1_other;
		*(UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97*)L_7 = L_8;
		return;
	}
}
// Method Definition Index: 21799
// Method Definition Index: 21801
// Method Definition Index: 21798
// Method Definition Index: 21799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m2D32A70C642BC1508FDFBF4E72385C9FFB63EAB9 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF* ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = List_1_get_Count_m780E93121AF45C1AE9F963A3E27BD6D79647BD6E_inline(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_3 = ___0_self;
		int32_t L_4 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m6B20DE63D68C6950CC593A0E15E5175545AC06ED(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_002f;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E* L_7;
		L_7 = UnmanagedRefCountedList_1_get_Item_m25AD99321A43BCB3E10E0720C424B625B05F00D8(L_5, L_6, NULL);
		List_1_t437B6C3879E969156A381BDC3C459CF809D39DDF* L_8 = ___1_other;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E L_10;
		L_10 = List_1_get_Item_m54313A208BF733F363077C5A2C48B534128B0889(L_8, L_9, NULL);
		*(TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E*)L_7 = L_10;
		int32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_002f:
	{
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m59D9F0B787D1FAE078A02C2E7B3522A6CC2C81E3 (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, ReadOnlySpan_1_tA8945E8A02F969385193C34AFA893BCE779E5C80 ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0;
		L_0 = ReadOnlySpan_1_get_Length_mB739611300D60B4BEB14C21136E8462A04116674_inline((&___1_other), NULL);
		V_0 = L_0;
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_1 = ___0_self;
		int32_t L_2 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m6B20DE63D68C6950CC593A0E15E5175545AC06ED(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0030;
	}

IL_0013:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_3 = ___0_self;
		int32_t L_4 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E* L_5;
		L_5 = UnmanagedRefCountedList_1_get_Item_m25AD99321A43BCB3E10E0720C424B625B05F00D8(L_3, L_4, NULL);
		int32_t L_6 = V_1;
		TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E* L_7;
		L_7 = il2cpp_span_get_item((TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E*)((Il2CppByReference*)&(((&___1_other))->____pointer))->value, (L_6), ((&___1_other))->____length);
		TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E L_8 = (*(TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E*)L_7);
		*(TimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E*)L_5 = L_8;
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0030:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0013;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m08CA3F6A6DAC40640DDCD04E48466CF93BD3AE9D (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_0;
		L_0 = UnmanagedRefCountedList_1_get_IsEmpty_mFFEB115C88447058B106153933C2815CA0DB6030((&___1_other), NULL);
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_1;
		L_1 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mB59A1EE1873B7EED39F101204D5F0E14A9DC1231((&___1_other), NULL);
		int32_t* L_2 = L_1;
		int32_t L_3 = *(L_2);
		*(L_2) = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_0015:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_4 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_5;
		L_5 = UnmanagedRefCountedList_1_get_IsEmpty_mFFEB115C88447058B106153933C2815CA0DB6030(L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_6 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m7ACD2CB9146F490C6C3E71CEB1A4C1DD97F7336A(L_6, il2cpp_rgctx_method(method->rgctx_data, 3));
	}

IL_0023:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_7 = ___0_self;
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE L_8 = ___1_other;
		*(UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE*)L_7 = L_8;
		return;
	}
}
// Method Definition Index: 21801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_m17834963CC7A6D69A464CEE17F73D0932B85D170 (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, ReadOnlySpan_1_tA7A09B5CBD9955114DF1BD8B2A082233FE91641C ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0;
		L_0 = ReadOnlySpan_1_get_Length_m0DDED3E4F3B413070D5A21ECABCEB0FC6A3A9D52_inline((&___1_other), NULL);
		V_0 = L_0;
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_1 = ___0_self;
		int32_t L_2 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_mE4C1F841F0D0FA8A08130B4761A3A0843B0D2F7B(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0030;
	}

IL_0013:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_3 = ___0_self;
		int32_t L_4 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11* L_5;
		L_5 = UnmanagedRefCountedList_1_get_Item_m4C2E9BDBA102B1DCD68E993BBAF130D87620131B(L_3, L_4, NULL);
		int32_t L_6 = V_1;
		UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11* L_7;
		L_7 = il2cpp_span_get_item((UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11*)((Il2CppByReference*)&(((&___1_other))->____pointer))->value, (L_6), ((&___1_other))->____length);
		UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11 L_8 = (*(UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11*)L_7);
		*(UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11*)L_5 = L_8;
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0030:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0013;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_mB2974533503E017554A88F7DF7C7580A810455C9 (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_0;
		L_0 = UnmanagedRefCountedList_1_get_IsEmpty_m7F763A556B56D166DA9B84E3820FB94835F5533F((&___1_other), NULL);
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_1;
		L_1 = UnmanagedRefCountedList_1_get_UnsafeRefCount_m58D3EA8F1F7DF64C8560E49D2BDB2631AA1A1970((&___1_other), NULL);
		int32_t* L_2 = L_1;
		int32_t L_3 = *(L_2);
		*(L_2) = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_0015:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_4 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_5;
		L_5 = UnmanagedRefCountedList_1_get_IsEmpty_m7F763A556B56D166DA9B84E3820FB94835F5533F(L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_6 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m3317B0BACC15E51025A554B4C52F73B2417EFCBD(L_6, il2cpp_rgctx_method(method->rgctx_data, 3));
	}

IL_0023:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_7 = ___0_self;
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 L_8 = ___1_other;
		*(UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281*)L_7 = L_8;
		return;
	}
}
// Method Definition Index: 21801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m3BB855E3D32F4D7DD9BC4E1864DB8308071BA35C (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, ReadOnlySpan_1_t3CCF29C77768AF4EE7E6D7C30578D3084881DD85 ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0;
		L_0 = ReadOnlySpan_1_get_Length_m3FF6D8FEC6FB6A437E4FD618AD20DE188AD2E373_inline((&___1_other), NULL);
		V_0 = L_0;
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_1 = ___0_self;
		int32_t L_2 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m19BAE2388C9E2168BECA6291C243441CED5066CC(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0030;
	}

IL_0013:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_3 = ___0_self;
		int32_t L_4 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75* L_5;
		L_5 = UnmanagedRefCountedList_1_get_Item_m8BA86CC1FDC39C2CECA6193033CD0CC191DAA9AE(L_3, L_4, NULL);
		int32_t L_6 = V_1;
		UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75* L_7;
		L_7 = il2cpp_span_get_item((UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75*)((Il2CppByReference*)&(((&___1_other))->____pointer))->value, (L_6), ((&___1_other))->____length);
		UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75 L_8 = (*(UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75*)L_7);
		*(UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75*)L_5 = L_8;
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0030:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0013;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m9A6FE78203423780C1D4DC543A23A7C098023901 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_0;
		L_0 = UnmanagedRefCountedList_1_get_IsEmpty_m4A937075322F5292F9840A84932C8015F894DA96((&___1_other), NULL);
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_1;
		L_1 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mB9D68971E4FDE3D6C127D837D5E67DD52CF1899D((&___1_other), NULL);
		int32_t* L_2 = L_1;
		int32_t L_3 = *(L_2);
		*(L_2) = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_0015:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_4 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_5;
		L_5 = UnmanagedRefCountedList_1_get_IsEmpty_m4A937075322F5292F9840A84932C8015F894DA96(L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_6 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m019F92E6E6C2E3331D98817815F0D5E975A31BB6(L_6, il2cpp_rgctx_method(method->rgctx_data, 3));
	}

IL_0023:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_7 = ___0_self;
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 L_8 = ___1_other;
		*(UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5*)L_7 = L_8;
		return;
	}
}
// Method Definition Index: 21799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisIl2CppFullySharedGenericStruct_m807D2BDC95BCD2A3EB39CEAC5305608E60214D44_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* ___0_self, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit);
	const uint32_t SizeOf_T_t5A03A4044624B019A9C455E9601C16981EAC3C03 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 5));
	const Il2CppFullySharedGenericStruct L_10 = alloca(SizeOf_T_t5A03A4044624B019A9C455E9601C16981EAC3C03);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = ((  int32_t (*) (List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_3 = ___0_self;
		int32_t L_4 = V_0;
		((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_002f;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		Il2CppFullySharedGenericStruct* L_7;
		L_7 = ((  Il2CppFullySharedGenericStruct* (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 2));
		List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* L_8 = ___1_other;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)), il2cpp_rgctx_method(method->rgctx_data, 4), L_8, L_9, (Il2CppFullySharedGenericStruct*)L_10);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_7, L_10, SizeOf_T_t5A03A4044624B019A9C455E9601C16981EAC3C03);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 5), (void**)(Il2CppFullySharedGenericStruct*)L_7, (void*)L_10);
		int32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_002f:
	{
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisIl2CppFullySharedGenericStruct_m0B7C4A5CBBE45A84BF547449C60BEB7FEC8DD6AD_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* ___0_self, ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit);
	const uint32_t SizeOf_T_t5CB4DD11F2D2956CDED05AA2B5B372283687298D = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 5));
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t5CB4DD11F2D2956CDED05AA2B5B372283687298D);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___1_other), NULL);
		V_0 = L_0;
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_1 = ___0_self;
		int32_t L_2 = V_0;
		((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0030;
	}

IL_0013:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_3 = ___0_self;
		int32_t L_4 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		Il2CppFullySharedGenericStruct* L_5;
		L_5 = ((  Il2CppFullySharedGenericStruct* (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_6 = V_1;
		Il2CppFullySharedGenericStruct* L_7;
		L_7 = ((  Il2CppFullySharedGenericStruct* (*) (ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))((&___1_other), L_6, il2cpp_rgctx_method(method->rgctx_data, 4));
		il2cpp_codegen_memcpy(L_8, L_7, SizeOf_T_t5CB4DD11F2D2956CDED05AA2B5B372283687298D);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_5, L_8, SizeOf_T_t5CB4DD11F2D2956CDED05AA2B5B372283687298D);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 5), (void**)(Il2CppFullySharedGenericStruct*)L_5, (void*)L_8);
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0030:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0013;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisIl2CppFullySharedGenericStruct_m1157114BC0716A5AEFDBC5EA71812C0BF0D80FB4_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* ___0_self, UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_0;
		L_0 = ((  bool (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___1_other), NULL);
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_1;
		L_1 = ((  int32_t* (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))((&___1_other), il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t* L_2 = L_1;
		int32_t L_3 = *(L_2);
		*(L_2) = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_0015:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_4 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_5;
		L_5 = ((  bool (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_6 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_6, il2cpp_rgctx_method(method->rgctx_data, 3));
	}

IL_0023:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_7 = ___0_self;
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC L_8 = ___1_other;
		*(UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*)L_7 = L_8;
		return;
	}
}
// Method Definition Index: 21799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mC45B9E76F322847EE815CFE2C7F46B4C8CFBEA70_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = List_1_get_Count_m8719A0E4E1F227424476DE81DF6DF6B58CA1CD71_inline(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_3 = ___0_self;
		int32_t L_4 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m23C0348FE604FA9B337A9CB97A850D992E27D5C2(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_002f;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9679F3A0296226D624CAB754A7A9401D5FF78F47_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_7;
		L_7 = UnmanagedRefCountedList_1_get_Item_m73AC4CB8D0814F69B7909BD7C5F6CD978F9D51FE(L_5, L_6, NULL);
		List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* L_8 = ___1_other;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		int32_t L_10;
		L_10 = List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75(L_8, L_9, NULL);
		*(int32_t*)L_7 = L_10;
		int32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_002f:
	{
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m3AC6D3EA4E0350FBBA79935CCA878E6109697709_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, ReadOnlySpan_1_tDFED1E92751A6EBC762EDE852E1ABE93EC8EFC7E ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0;
		L_0 = ReadOnlySpan_1_get_Length_m5D2D9C9D84B6B351227F38867909DFAC0CC9693D_inline((&___1_other), NULL);
		V_0 = L_0;
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_1 = ___0_self;
		int32_t L_2 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m23C0348FE604FA9B337A9CB97A850D992E27D5C2(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0030;
	}

IL_0013:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_3 = ___0_self;
		int32_t L_4 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t9E4D92EE7CE4C509DCB536F52631C675D620E7DC_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_5;
		L_5 = UnmanagedRefCountedList_1_get_Item_m73AC4CB8D0814F69B7909BD7C5F6CD978F9D51FE(L_3, L_4, NULL);
		int32_t L_6 = V_1;
		int32_t* L_7;
		L_7 = il2cpp_span_get_item((int32_t*)((Il2CppByReference*)&(((&___1_other))->____pointer))->value, (L_6), ((&___1_other))->____length);
		int32_t L_8 = (*(int32_t*)L_7);
		*(int32_t*)L_5 = L_8;
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0030:
	{
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0013;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m2B900993D5B64CD28305A46B63CBF8FBF6142EEC_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_0;
		L_0 = UnmanagedRefCountedList_1_get_IsEmpty_m521500F43BEA84B121D1ACDF22D20631BCDE3DFB((&___1_other), NULL);
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_1;
		L_1 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mFED40840551BD2E9A867CEA2A8879454A05FB380((&___1_other), NULL);
		int32_t* L_2 = L_1;
		int32_t L_3 = *(L_2);
		*(L_2) = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_0015:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_4 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		bool L_5;
		L_5 = UnmanagedRefCountedList_1_get_IsEmpty_m521500F43BEA84B121D1ACDF22D20631BCDE3DFB(L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_6 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t116A19AF0AB3521459333DCEF6A4A5D70C5D32B0_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_mB86F120A00B23B11FE39DA54CB3BEBCEC8751B17(L_6, il2cpp_rgctx_method(method->rgctx_data, 3));
	}

IL_0023:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_7 = ___0_self;
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC L_8 = ___1_other;
		*(UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*)L_7 = L_8;
		return;
	}
}
// Method Definition Index: 21800
// Method Definition Index: 21800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_TisFilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF_mFE710D3F840B9A9A396D508DC86B27886F595662 (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7* ___1_other, Func_2_t0F26B920A10A91BFA7B07637902B13D306D6ACB2* ___2_convert, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = List_1_get_Count_m1D6FD73298DDB395877D930AE657C2CD73B72E04_inline(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_3 = ___0_self;
		int32_t L_4 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_mE4C1F841F0D0FA8A08130B4761A3A0843B0D2F7B(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0035;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11* L_7;
		L_7 = UnmanagedRefCountedList_1_get_Item_m4C2E9BDBA102B1DCD68E993BBAF130D87620131B(L_5, L_6, NULL);
		Func_2_t0F26B920A10A91BFA7B07637902B13D306D6ACB2* L_8 = ___2_convert;
		List_1_tBD2E4781BB0BD1FCD30E6D3586CA13AFD0ABE6F7* L_9 = ___1_other;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF L_11;
		L_11 = List_1_get_Item_mD8887B4702293F0057E0DD9DFCCDC9FE7F99F0E5(L_9, L_10, NULL);
		NullCheck(L_8);
		UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11 L_12;
		L_12 = Func_2_Invoke_mC82AB28A182689A25D4F657E20FC5A764642A915_inline(L_8, L_11, NULL);
		*(UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11*)L_7 = L_12;
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0035:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_0;
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_TisMaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF_m8FA80E57DBD6E403E2044ED7E56B958846CF3D60 (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, List_1_t491347B1404617671B39DA9325642B0DB8748CB3* ___1_other, Func_2_t9622A5472E3EB564FD9AA65F9666F983FA8CA079* ___2_convert, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_t491347B1404617671B39DA9325642B0DB8748CB3* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_t491347B1404617671B39DA9325642B0DB8748CB3* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = List_1_get_Count_mD1945480F1375B8F210F93C9AF5A14CB66DB12E2_inline(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_3 = ___0_self;
		int32_t L_4 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m19BAE2388C9E2168BECA6291C243441CED5066CC(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0035;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75* L_7;
		L_7 = UnmanagedRefCountedList_1_get_Item_m8BA86CC1FDC39C2CECA6193033CD0CC191DAA9AE(L_5, L_6, NULL);
		Func_2_t9622A5472E3EB564FD9AA65F9666F983FA8CA079* L_8 = ___2_convert;
		List_1_t491347B1404617671B39DA9325642B0DB8748CB3* L_9 = ___1_other;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF L_11;
		L_11 = List_1_get_Item_mB0D64703F21141207CD84B9D6B5FB80410BB36F5(L_9, L_10, NULL);
		NullCheck(L_8);
		UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75 L_12;
		L_12 = Func_2_Invoke_m63E17BE9D669582B8D83B161B938EF4F5E866748_inline(L_8, L_11, NULL);
		*(UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75*)L_7 = L_12;
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0035:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_0;
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericAny_m27C7816899EFA0C6ED703C50EC5AA09B5A34B3D8_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* ___0_self, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___1_other, Func_2_tAD3C25E447E01C5173D4EF30C14D5F69437441FD* ___2_convert, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit);
	const uint32_t SizeOf_T_tF82C44D47BED67C05E55882DE04760E127EDA661 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 7));
	const Il2CppFullySharedGenericStruct L_12 = alloca(SizeOf_T_tF82C44D47BED67C05E55882DE04760E127EDA661);
	const uint32_t SizeOf_TOther_t67A20CFA829EAF62E40EA9796F0A3B4718051875 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 5));
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_TOther_t67A20CFA829EAF62E40EA9796F0A3B4718051875);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_3 = ___0_self;
		int32_t L_4 = V_0;
		((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0035;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		Il2CppFullySharedGenericStruct* L_7;
		L_7 = ((  Il2CppFullySharedGenericStruct* (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 2));
		Func_2_tAD3C25E447E01C5173D4EF30C14D5F69437441FD* L_8 = ___2_convert;
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_9 = ___1_other;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)), il2cpp_rgctx_method(method->rgctx_data, 4), L_9, L_10, (Il2CppFullySharedGenericAny*)L_11);
		NullCheck(L_8);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)), il2cpp_rgctx_method(method->rgctx_data, 6), L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 5)) ? L_11: *(void**)L_11), (Il2CppFullySharedGenericStruct*)L_12);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_7, L_12, SizeOf_T_tF82C44D47BED67C05E55882DE04760E127EDA661);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 7), (void**)(Il2CppFullySharedGenericStruct*)L_7, (void*)L_12);
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0035:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_0;
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_CopyFrom_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_TisStylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF_mFA3C84AEBB8C5D3964440DEACC17940E42D0BA50_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268* ___1_other, Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577* ___2_convert, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268* L_0 = ___1_other;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_000c;
	}

IL_0006:
	{
		List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268* L_1 = ___1_other;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = List_1_get_Count_m828EB26F6BCE9B7DC682DF2DB6500C146BF74ED9_inline(L_1, NULL);
		G_B3_0 = L_2;
	}

IL_000c:
	{
		V_0 = G_B3_0;
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_3 = ___0_self;
		int32_t L_4 = V_0;
		UnmanagedRefCountedListExtensions_PrepareWrite_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m23C0348FE604FA9B337A9CB97A850D992E27D5C2(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = 0;
		goto IL_0035;
	}

IL_0018:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_5 = ___0_self;
		int32_t L_6 = V_1;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_t78BE89586B4F84171AF55770EB9B0E6D6FED7BE6_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 3)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_7;
		L_7 = UnmanagedRefCountedList_1_get_Item_m73AC4CB8D0814F69B7909BD7C5F6CD978F9D51FE(L_5, L_6, NULL);
		Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577* L_8 = ___2_convert;
		List_1_tD6F1685FEE5A196B3002ACC649A1DF5C65162268* L_9 = ___1_other;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF L_11;
		L_11 = List_1_get_Item_m2455DF403BC23EF806BBB35F26A197F1AA270CAC(L_9, L_10, NULL);
		NullCheck(L_8);
		int32_t L_12;
		L_12 = Func_2_Invoke_m4C0458CE84ED9C58132692F135BB07908074DC06_inline(L_8, L_11, NULL);
		*(int32_t*)L_7 = L_12;
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0035:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_0;
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_0018;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 21796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m2C5C294367EEC020C3F2A9955689C9EF20C1DCFB (UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* ___0_self, int32_t ___1_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___1_count;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_1 = ___0_self;
		UnmanagedRefCountedListExtensions_Clear_TisEasingFunction_t5197D3B06056326A8B5C96032CDEBD5D3BDCA7A4_m243F4E8CDDB9A9F83AA778B3F2A1DA639F65AFFE(L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}

IL_000a:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		bool L_3;
		L_3 = UnmanagedRefCountedList_1_get_IsEmpty_m2E14B74870630D7E8FED2C9B0B1ACE4BA16F0B1D(L_2, NULL);
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_4 = ___0_self;
		int32_t L_5 = ___1_count;
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 L_6;
		memset((&L_6), 0, sizeof(L_6));
		UnmanagedRefCountedList_1__ctor_m77408358E22109403619F8D5772C5BB0D90898E5((&L_6), L_5, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97*)L_4 = L_6;
		return;
	}

IL_001f:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_7 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = UnmanagedRefCountedList_1_get_UnsafeCount_m346BA84F5DE67F951530A1FA79808C15A58E9BEE(L_7, NULL);
		int32_t L_9 = ___1_count;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_0033;
		}
	}
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_10 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_11;
		L_11 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mC1A6A68B722E048D4FB2CF6CEA269887284C071F(L_10, NULL);
		int32_t L_12 = *(L_11);
		if ((!(((uint32_t)L_12) == ((uint32_t)1))))
		{
			goto IL_0033;
		}
	}
	{
		return;
	}

IL_0033:
	{
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_13 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m8C60A954A286528BD0B6CF0D629BD42DF5692251(L_13, il2cpp_rgctx_method(method->rgctx_data, 6));
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97* L_14 = ___0_self;
		int32_t L_15 = ___1_count;
		UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97 L_16;
		memset((&L_16), 0, sizeof(L_16));
		UnmanagedRefCountedList_1__ctor_m77408358E22109403619F8D5772C5BB0D90898E5((&L_16), L_15, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t87F605E6E2A53C987FAD9F7FE66842141F83ED97*)L_14 = L_16;
		return;
	}
}
// Method Definition Index: 21796
// Method Definition Index: 21796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m6B20DE63D68C6950CC593A0E15E5175545AC06ED (UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* ___0_self, int32_t ___1_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___1_count;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_1 = ___0_self;
		UnmanagedRefCountedListExtensions_Clear_TisTimeValue_t45AE43B219493F9459363F32C79E8986B5F82E0E_m4904C1101CBC6F7514E304F08A59D4D11FF21061(L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}

IL_000a:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		bool L_3;
		L_3 = UnmanagedRefCountedList_1_get_IsEmpty_mFFEB115C88447058B106153933C2815CA0DB6030(L_2, NULL);
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_4 = ___0_self;
		int32_t L_5 = ___1_count;
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE L_6;
		memset((&L_6), 0, sizeof(L_6));
		UnmanagedRefCountedList_1__ctor_mDCB5C70225741FBD0A45FC7CF4AF86FFBE5F9082((&L_6), L_5, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE*)L_4 = L_6;
		return;
	}

IL_001f:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_7 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = UnmanagedRefCountedList_1_get_UnsafeCount_mC42B46855B167085DF30F2EF8E5B972D224596E8(L_7, NULL);
		int32_t L_9 = ___1_count;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_0033;
		}
	}
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_10 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_11;
		L_11 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mB59A1EE1873B7EED39F101204D5F0E14A9DC1231(L_10, NULL);
		int32_t L_12 = *(L_11);
		if ((!(((uint32_t)L_12) == ((uint32_t)1))))
		{
			goto IL_0033;
		}
	}
	{
		return;
	}

IL_0033:
	{
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_13 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m7ACD2CB9146F490C6C3E71CEB1A4C1DD97F7336A(L_13, il2cpp_rgctx_method(method->rgctx_data, 6));
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE* L_14 = ___0_self;
		int32_t L_15 = ___1_count;
		UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE L_16;
		memset((&L_16), 0, sizeof(L_16));
		UnmanagedRefCountedList_1__ctor_mDCB5C70225741FBD0A45FC7CF4AF86FFBE5F9082((&L_16), L_15, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t99A5F9010AF1EFC3F764B1EA44D4AEF7EC93E8EE*)L_14 = L_16;
		return;
	}
}
// Method Definition Index: 21796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_mE4C1F841F0D0FA8A08130B4761A3A0843B0D2F7B (UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* ___0_self, int32_t ___1_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___1_count;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_1 = ___0_self;
		UnmanagedRefCountedListExtensions_Clear_TisUnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11_m305E33368392F6D1AD854746351A71687763E9AF(L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}

IL_000a:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		bool L_3;
		L_3 = UnmanagedRefCountedList_1_get_IsEmpty_m7F763A556B56D166DA9B84E3820FB94835F5533F(L_2, NULL);
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_4 = ___0_self;
		int32_t L_5 = ___1_count;
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 L_6;
		memset((&L_6), 0, sizeof(L_6));
		UnmanagedRefCountedList_1__ctor_mD7415ADC961F9A1C7AA6A8E77C83534DCFC175AF((&L_6), L_5, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281*)L_4 = L_6;
		return;
	}

IL_001f:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_7 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = UnmanagedRefCountedList_1_get_UnsafeCount_m85830C3F1A7DDFC22EDBAE2A99C08C617E793C58(L_7, NULL);
		int32_t L_9 = ___1_count;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_0033;
		}
	}
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_10 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_11;
		L_11 = UnmanagedRefCountedList_1_get_UnsafeRefCount_m58D3EA8F1F7DF64C8560E49D2BDB2631AA1A1970(L_10, NULL);
		int32_t L_12 = *(L_11);
		if ((!(((uint32_t)L_12) == ((uint32_t)1))))
		{
			goto IL_0033;
		}
	}
	{
		return;
	}

IL_0033:
	{
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_13 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m3317B0BACC15E51025A554B4C52F73B2417EFCBD(L_13, il2cpp_rgctx_method(method->rgctx_data, 6));
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281* L_14 = ___0_self;
		int32_t L_15 = ___1_count;
		UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281 L_16;
		memset((&L_16), 0, sizeof(L_16));
		UnmanagedRefCountedList_1__ctor_mD7415ADC961F9A1C7AA6A8E77C83534DCFC175AF((&L_16), L_15, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_tEAD96F00DAE426BB352AEF0444CE64D11061F281*)L_14 = L_16;
		return;
	}
}
// Method Definition Index: 21796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m19BAE2388C9E2168BECA6291C243441CED5066CC (UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* ___0_self, int32_t ___1_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___1_count;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_1 = ___0_self;
		UnmanagedRefCountedListExtensions_Clear_TisUnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75_m540F90AA5E678CB4111BAC286677FF58EAD5EF90(L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}

IL_000a:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		bool L_3;
		L_3 = UnmanagedRefCountedList_1_get_IsEmpty_m4A937075322F5292F9840A84932C8015F894DA96(L_2, NULL);
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_4 = ___0_self;
		int32_t L_5 = ___1_count;
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 L_6;
		memset((&L_6), 0, sizeof(L_6));
		UnmanagedRefCountedList_1__ctor_m4B39562DBE2738598CDBCE1DD4B2D04A52064F97((&L_6), L_5, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5*)L_4 = L_6;
		return;
	}

IL_001f:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_7 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = UnmanagedRefCountedList_1_get_UnsafeCount_m3EF1747E3FE4FA9731252DDDDAAF355D28F0E66F(L_7, NULL);
		int32_t L_9 = ___1_count;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_0033;
		}
	}
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_10 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_11;
		L_11 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mB9D68971E4FDE3D6C127D837D5E67DD52CF1899D(L_10, NULL);
		int32_t L_12 = *(L_11);
		if ((!(((uint32_t)L_12) == ((uint32_t)1))))
		{
			goto IL_0033;
		}
	}
	{
		return;
	}

IL_0033:
	{
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_13 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_m019F92E6E6C2E3331D98817815F0D5E975A31BB6(L_13, il2cpp_rgctx_method(method->rgctx_data, 6));
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5* L_14 = ___0_self;
		int32_t L_15 = ___1_count;
		UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5 L_16;
		memset((&L_16), 0, sizeof(L_16));
		UnmanagedRefCountedList_1__ctor_m4B39562DBE2738598CDBCE1DD4B2D04A52064F97((&L_16), L_15, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t0988C4F7F135DFD05367A2D439B27EE9F49444A5*)L_14 = L_16;
		return;
	}
}
// Method Definition Index: 21796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_TisIl2CppFullySharedGenericStruct_mE0BCB9507B8C736AC77C699536E4C4FC7454A283_fshared (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* ___0_self, int32_t ___1_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___1_count;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_1 = ___0_self;
		((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}

IL_000a:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		bool L_3;
		L_3 = ((  bool (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_2, NULL);
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_4 = ___0_self;
		int32_t L_5 = ___1_count;
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC L_6;
		memset((&L_6), 0, sizeof(L_6));
		UnmanagedRefCountedList_1__ctor_m1A1BC9ABD2A9D7B9C7434073D1F52063C8F92056((&L_6), L_5, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*)L_4 = L_6;
		return;
	}

IL_001f:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_7 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = ((  int32_t (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(L_7, il2cpp_rgctx_method(method->rgctx_data, 4));
		int32_t L_9 = ___1_count;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_0033;
		}
	}
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_10 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_11;
		L_11 = ((  int32_t* (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(L_10, il2cpp_rgctx_method(method->rgctx_data, 5));
		int32_t L_12 = *(L_11);
		if ((!(((uint32_t)L_12) == ((uint32_t)1))))
		{
			goto IL_0033;
		}
	}
	{
		return;
	}

IL_0033:
	{
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_13 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		((  void (*) (UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(L_13, il2cpp_rgctx_method(method->rgctx_data, 6));
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC* L_14 = ___0_self;
		int32_t L_15 = ___1_count;
		UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC L_16;
		memset((&L_16), 0, sizeof(L_16));
		UnmanagedRefCountedList_1__ctor_m1A1BC9ABD2A9D7B9C7434073D1F52063C8F92056((&L_16), L_15, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t8B02F7EA0267E2F24A9C139864512B7B0BBE81BC*)L_14 = L_16;
		return;
	}
}
// Method Definition Index: 21796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnmanagedRefCountedListExtensions_PrepareWrite_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m23C0348FE604FA9B337A9CB97A850D992E27D5C2_gshared (UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* ___0_self, int32_t ___1_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___1_count;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_1 = ___0_self;
		UnmanagedRefCountedListExtensions_Clear_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m3D75E429C1104D73A7D1533FEDB84C8776D97DC6(L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}

IL_000a:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_2 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		bool L_3;
		L_3 = UnmanagedRefCountedList_1_get_IsEmpty_m521500F43BEA84B121D1ACDF22D20631BCDE3DFB(L_2, NULL);
		if (!L_3)
		{
			goto IL_001f;
		}
	}
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_4 = ___0_self;
		int32_t L_5 = ___1_count;
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC L_6;
		memset((&L_6), 0, sizeof(L_6));
		UnmanagedRefCountedList_1__ctor_m58403CFD1E60A2E9DF9DC8E7600CBC28F642089F((&L_6), L_5, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*)L_4 = L_6;
		return;
	}

IL_001f:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_7 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = UnmanagedRefCountedList_1_get_UnsafeCount_mC9425FE28356043DFC64EF65FC11F219FCA48380(L_7, NULL);
		int32_t L_9 = ___1_count;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_0033;
		}
	}
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_10 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		int32_t* L_11;
		L_11 = UnmanagedRefCountedList_1_get_UnsafeRefCount_mFED40840551BD2E9A867CEA2A8879454A05FB380(L_10, NULL);
		int32_t L_12 = *(L_11);
		if ((!(((uint32_t)L_12) == ((uint32_t)1))))
		{
			goto IL_0033;
		}
	}
	{
		return;
	}

IL_0033:
	{
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_13 = ___0_self;
		CHECKED_LOCAL_INIT(UnmanagedRefCountedList_1_tBE228B378C04195CEBC51848BA70C37959809841_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 2)),il2cpp_codegen_runtime_class_init_inline);
		UnmanagedRefCountedList_1_UnsafeRelease_mB86F120A00B23B11FE39DA54CB3BEBCEC8751B17(L_13, il2cpp_rgctx_method(method->rgctx_data, 6));
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC* L_14 = ___0_self;
		int32_t L_15 = ___1_count;
		UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC L_16;
		memset((&L_16), 0, sizeof(L_16));
		UnmanagedRefCountedList_1__ctor_m58403CFD1E60A2E9DF9DC8E7600CBC28F642089F((&L_16), L_15, il2cpp_rgctx_method(method->rgctx_data, 3));
		*(UnmanagedRefCountedList_1_t6BEDFED7B99FA7F62FCD287B12C626ACD076CBAC*)L_14 = L_16;
		return;
	}
}
// Method Definition Index: 98059
// Method Definition Index: 98058
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_AddByteOffset_TisIl2CppFullySharedGenericAny_mA6877EB6A5CE3EEE6671E72022081A718D8CBEC8_fshared (Il2CppFullySharedGenericAny* ___0_source, intptr_t ___1_byteOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		intptr_t L_1 = ___1_byteOffset;
		return ((Il2CppFullySharedGenericAny*)il2cpp_codegen_add((intptr_t)L_0, L_1));
	}
}
// Method Definition Index: 98059
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_AddByteOffset_TisIl2CppFullySharedGenericAny_mFEF319F8CEF9CA5FD56DB2E46B519799801465DC_fshared (Il2CppFullySharedGenericAny* ___0_source, uintptr_t ___1_byteOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		uintptr_t L_1 = ___1_byteOffset;
		return ((Il2CppFullySharedGenericAny*)il2cpp_codegen_add((intptr_t)L_0, (intptr_t)L_1));
	}
}
// Method Definition Index: 98055
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Unsafe_As_TisIl2CppSharedGenericObject_mF43B42CDF61533403D004E09920FB9F3F7CFD768_gshared (RuntimeObject* ___0_o, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_o;
		return (Il2CppSharedGenericObject*)L_0;
	}
}
// Method Definition Index: 98057
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_As_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m6A2B605DB158987669F45298C591DC5876B5128C_fshared (Il2CppFullySharedGenericAny* ___0_source, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		return (Il2CppFullySharedGenericAny*)(L_0);
	}
}
// Method Definition Index: 98052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Unsafe_AsPointer_TisIl2CppFullySharedGenericAny_mB3F08848197461508634619D2125BFB713699361_fshared (Il2CppFullySharedGenericAny* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_value;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,Il2CppFullySharedGenericAny*,intptr_t,false,false>(L_0,NULL));
		return (void*)(L_1);
	}
}
// Method Definition Index: 98056
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_AsRef_TisIl2CppFullySharedGenericAny_mF06D34D5150ECDA41C2E3902F90C988F2CF868CB_fshared (void* ___0_source, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	{
		void* L_0 = ___0_source;
		V_0 = (int32_t*)L_0;
		int32_t* L_1 = V_0;
		return (Il2CppFullySharedGenericAny*)(L_1);
	}
}
// Method Definition Index: 98060
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Unsafe_ByteOffset_TisIl2CppFullySharedGenericAny_mFD0E1A923BABD9757AA645DF6F879C4AA2F00E34_fshared (Il2CppFullySharedGenericAny* ___0_origin, Il2CppFullySharedGenericAny* ___1_target, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___1_target;
		Il2CppFullySharedGenericAny* L_1 = ___0_origin;
		return (intptr_t)((Il2CppFullySharedGenericAny*)il2cpp_codegen_subtract((intptr_t)L_0, (intptr_t)L_1));
	}
}
// Method Definition Index: 98049
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_ReadUnaligned_TisIl2CppFullySharedGenericAny_m14D483BC40001F823BDC3F9AFAA26C86027B655A_fshared (uint8_t* ___0_source, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t0BE9A499D7700B8625DF3E0AAF1EB1345188F8EE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t0BE9A499D7700B8625DF3E0AAF1EB1345188F8EE);
	//<source_info:<no-source>:1>
	{
		uint8_t* L_0 = ___0_source;
		il2cpp_codegen_memcpy(L_1, L_0, SizeOf_T_t0BE9A499D7700B8625DF3E0AAF1EB1345188F8EE);
		il2cpp_codegen_memcpy(il2cppRetVal, L_1, SizeOf_T_t0BE9A499D7700B8625DF3E0AAF1EB1345188F8EE);
		return;
	}
}
// Method Definition Index: 98048
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_ReadUnaligned_TisIl2CppFullySharedGenericAny_m535CEEECB2FC10C90C764D5AD3CC65EA97DEBD00_fshared (void* ___0_source, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t15D3C2F20CB4F9D5A08E7998BE25B9AB3C131769 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t15D3C2F20CB4F9D5A08E7998BE25B9AB3C131769);
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		il2cpp_codegen_memcpy(L_1, L_0, SizeOf_T_t15D3C2F20CB4F9D5A08E7998BE25B9AB3C131769);
		il2cpp_codegen_memcpy(il2cppRetVal, L_1, SizeOf_T_t15D3C2F20CB4F9D5A08E7998BE25B9AB3C131769);
		return;
	}
}
// Method Definition Index: 98053
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Unsafe_SizeOf_TisIl2CppFullySharedGenericAny_m9333BB4BE96C96F379EBC63E590625F638A12AB2_fshared (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tEBAD0940DB52DC5349543CC3BDE62C848B32B00D = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = SizeOf_T_tEBAD0940DB52DC5349543CC3BDE62C848B32B00D;
		return (int32_t)L_0;
	}
}
// Method Definition Index: 98051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_WriteUnaligned_TisIl2CppFullySharedGenericAny_m4A21AE425C18E39310C29B4F493602AA6E56A6D9_fshared (uint8_t* ___0_destination, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tFDE785E318899B2ADBC90EFA1364A3B76599F750 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tFDE785E318899B2ADBC90EFA1364A3B76599F750);
	//<source_info:<no-source>:1>
	{
		uint8_t* L_0 = ___0_destination;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___1_value : &___1_value), SizeOf_T_tFDE785E318899B2ADBC90EFA1364A3B76599F750);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericAny*)L_0, L_1, SizeOf_T_tFDE785E318899B2ADBC90EFA1364A3B76599F750);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericAny*)L_0, (void*)L_1);
		return;
	}
}
// Method Definition Index: 98050
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_WriteUnaligned_TisIl2CppFullySharedGenericAny_m8E4966BB8B73735827F57FFA14E1947FA84C9394_fshared (void* ___0_destination, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t7D75490B2823EDFE685A24645133F767DDEE1DCB = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t7D75490B2823EDFE685A24645133F767DDEE1DCB);
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_destination;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___1_value : &___1_value), SizeOf_T_t7D75490B2823EDFE685A24645133F767DDEE1DCB);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericAny*)L_0, L_1, SizeOf_T_t7D75490B2823EDFE685A24645133F767DDEE1DCB);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericAny*)L_0, (void*)L_1);
		return;
	}
}
// Method Definition Index: 8547
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_Add_TisIl2CppFullySharedGenericAny_mDA4722F94AF13693FCE1583B641A792D2EA47924_fshared (Il2CppFullySharedGenericAny* ___0_source, int32_t ___1_elementOffset, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tBE6850158665A8E196430E1D80AEFF9AC121F5F9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		int32_t L_1 = ___1_elementOffset;
		uint32_t L_2 = SizeOf_T_tBE6850158665A8E196430E1D80AEFF9AC121F5F9;
		intptr_t L_3 = (il2cpp_codegen_conv<intptr_t,uint32_t,int32_t,false,false>(L_2,NULL));
		return ((Il2CppFullySharedGenericAny*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(L_1, L_3))));
	}
}
// Method Definition Index: 8548
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_Add_TisIl2CppFullySharedGenericAny_mC89D70E498F759E971238CF82E99E44CC68197DA_fshared (Il2CppFullySharedGenericAny* ___0_source, intptr_t ___1_elementOffset, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tEE9E2B0A67EF7877E2DDB454C5066EBB8C09D0DA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		intptr_t L_1 = ___1_elementOffset;
		uint32_t L_2 = SizeOf_T_tEE9E2B0A67EF7877E2DDB454C5066EBB8C09D0DA;
		return ((Il2CppFullySharedGenericAny*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(L_1, (int32_t)L_2))));
	}
}
// Method Definition Index: 8549
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Unsafe_Add_TisIl2CppFullySharedGenericAny_m25356A475C0867B15741BD80812E4EBA4394F3C5_fshared (void* ___0_source, int32_t ___1_elementOffset, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t3ED59D9C3AB22383C6F506D05E4A04928B7130D6 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_elementOffset;
		uint32_t L_2 = SizeOf_T_t3ED59D9C3AB22383C6F506D05E4A04928B7130D6;
		intptr_t L_3 = (il2cpp_codegen_conv<intptr_t,uint32_t,int32_t,false,false>(L_2,NULL));
		return ((void*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(L_1, L_3))));
	}
}
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8550
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_AddByteOffset_TisIl2CppFullySharedGenericAny_m023762698D869AA8F4D477B66833C0BCFC1EA25C_fshared (Il2CppFullySharedGenericAny* ___0_source, intptr_t ___1_byteOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		intptr_t L_1 = ___1_byteOffset;
		return ((Il2CppFullySharedGenericAny*)il2cpp_codegen_add((intptr_t)L_0, L_1));
	}
}
// Method Definition Index: 8563
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_AddByteOffset_TisIl2CppFullySharedGenericAny_m77EFAC6DAA578E6C65CAC97578F1800F25019689_fshared (Il2CppFullySharedGenericAny* ___0_source, uint64_t ___1_byteOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		uint64_t L_1 = ___1_byteOffset;
		uintptr_t L_2 = (il2cpp_codegen_conv<uintptr_t,uint64_t,int64_t,false,false>(L_1,NULL));
		intptr_t L_3;
		L_3 = IntPtr_op_Explicit_mE2CEC14C61FD5E2159A03EA2AD97F5CDC5BB9F4D((void*)L_2, NULL);
		Il2CppFullySharedGenericAny* L_4;
		L_4 = il2cpp_unsafe_add_byte_offset<Il2CppFullySharedGenericAny,intptr_t>(L_0, L_3);
		return L_4;
	}
}
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8563
// Method Definition Index: 8551
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Unsafe_AreSame_TisIl2CppFullySharedGenericAny_mEFCD9F27093DEB04CA603DC1C6F306CE6DCCDC3C_fshared (Il2CppFullySharedGenericAny* ___0_left, Il2CppFullySharedGenericAny* ___1_right, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_left;
		Il2CppFullySharedGenericAny* L_1 = ___1_right;
		return (bool)((((RuntimeObject*)(intptr_t)L_0) == ((RuntimeObject*)(intptr_t)L_1))? 1 : 0);
	}
}
// Method Definition Index: 8552
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Unsafe_As_TisIl2CppSharedGenericObject_mEA282A8D403A0B743C8FF21F53E3421FFE98BCCC_gshared (RuntimeObject* ___0_o, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_o;
		return (Il2CppSharedGenericObject*)L_0;
	}
}
// Method Definition Index: 8553
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_As_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mAF06A659941D15118FC1E4800E3A7A0F262628A4_fshared (Il2CppFullySharedGenericAny* ___0_source, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		return (Il2CppFullySharedGenericAny*)(L_0);
	}
}
// Method Definition Index: 8554
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Unsafe_AsPointer_TisIl2CppFullySharedGenericAny_mE85961ECFFC7310EBEF309E6E67AD0FED2F9030B_fshared (Il2CppFullySharedGenericAny* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_value;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,Il2CppFullySharedGenericAny*,intptr_t,false,false>(L_0,NULL));
		return (void*)(L_1);
	}
}
// Method Definition Index: 8556
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_AsRef_TisIl2CppFullySharedGenericAny_m088920550101BD3FA6B40E99A5F107C35BE752FA_fshared (Il2CppFullySharedGenericAny* ___0_source, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_source;
		return L_0;
	}
}
// Method Definition Index: 8555
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* Unsafe_AsRef_TisIl2CppFullySharedGenericAny_mD269D4D95DA51D3CF4E4025805638814158802A3_fshared (void* ___0_source, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		return (Il2CppFullySharedGenericAny*)(L_0);
	}
}
// Method Definition Index: 8562
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Unsafe_IsAddressLessThan_TisIl2CppFullySharedGenericAny_m731B9B0C5A4B349E4545E7AAAB44731B9ADB6597_fshared (Il2CppFullySharedGenericAny* ___0_left, Il2CppFullySharedGenericAny* ___1_right, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_left;
		Il2CppFullySharedGenericAny* L_1 = ___1_right;
		return (bool)((!(((RuntimeObject*)(uintptr_t)L_0) >= ((RuntimeObject*)(uintptr_t)L_1)))? 1 : 0);
	}
}
// Method Definition Index: 8558
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_Read_TisIl2CppFullySharedGenericAny_mF6B28073E683AAE891ED373C5F5F29DA2A0708A2_fshared (void* ___0_source, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tB42CCB1CEED288E2BEBBDFE4BE22B8CB6F084B54 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tB42CCB1CEED288E2BEBBDFE4BE22B8CB6F084B54);
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		il2cpp_codegen_memcpy(L_1, L_0, SizeOf_T_tB42CCB1CEED288E2BEBBDFE4BE22B8CB6F084B54);
		il2cpp_codegen_memcpy(il2cppRetVal, L_1, SizeOf_T_tB42CCB1CEED288E2BEBBDFE4BE22B8CB6F084B54);
		return;
	}
}
// Method Definition Index: 8559
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_ReadUnaligned_TisIl2CppFullySharedGenericAny_m42C276800437B81F51F1F38619B499B6AAFB0021_fshared (uint8_t* ___0_source, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tE109D24A290E1158759C26079ED706B46290FAE5 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tE109D24A290E1158759C26079ED706B46290FAE5);
	//<source_info:<no-source>:1>
	{
		uint8_t* L_0 = ___0_source;
		il2cpp_codegen_memcpy(L_1, L_0, SizeOf_T_tE109D24A290E1158759C26079ED706B46290FAE5);
		il2cpp_codegen_memcpy(il2cppRetVal, L_1, SizeOf_T_tE109D24A290E1158759C26079ED706B46290FAE5);
		return;
	}
}
// Method Definition Index: 8560
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Unsafe_SizeOf_TisIl2CppFullySharedGenericAny_mD5748385042811E049C06FFD865AFD213C5FA9EB_fshared (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t77C4AF644C0D2AE4F0E9399E7AED3FED3426FBD7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = SizeOf_T_t77C4AF644C0D2AE4F0E9399E7AED3FED3426FBD7;
		return (int32_t)L_0;
	}
}
// Method Definition Index: 8561
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_WriteUnaligned_TisIl2CppFullySharedGenericAny_mF9DAA41D685A65A581864DBF65CE23C6F7E72BDF_fshared (uint8_t* ___0_destination, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tBBA6F3D6E1BC76807F91C471253B4033DB66D6E8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tBBA6F3D6E1BC76807F91C471253B4033DB66D6E8);
	//<source_info:<no-source>:1>
	{
		uint8_t* L_0 = ___0_destination;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___1_value : &___1_value), SizeOf_T_tBBA6F3D6E1BC76807F91C471253B4033DB66D6E8);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericAny*)L_0, L_1, SizeOf_T_tBBA6F3D6E1BC76807F91C471253B4033DB66D6E8);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericAny*)L_0, (void*)L_1);
		return;
	}
}
// Method Definition Index: 65686
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_Add_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m115C1E10CFF2E5179C099DDD59C5779D0863C1C1 (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	void* V_1 = NULL;
	{
		uint32_t L_0 = sizeof(int32_t);
		V_0 = (int32_t)L_0;
		int32_t L_1 = __this->___Length;
		int32_t L_2 = V_0;
		UnsafeAppendBuffer_SetCapacity_mF80BF3DD388E819E52586A458C10606333611269(__this, ((int32_t)il2cpp_codegen_add(L_1, L_2)), NULL);
		uint8_t* L_3 = __this->___Ptr;
		int32_t L_4 = __this->___Length;
		V_1 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_3, L_4));
		void* L_5 = V_1;
		uint64_t L_6 = (il2cpp_codegen_conv<uint64_t,void*,intptr_t,false,false>(L_5,NULL));
		int32_t L_7;
		L_7 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline(NULL);
		bool L_8;
		L_8 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9(L_6, L_7, NULL);
		if (!L_8)
		{
			goto IL_003b;
		}
	}
	{
		void* L_9 = V_1;
		UnsafeUtility_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m934C9E3CBBFA04ABEF4528E565C300B5DCF8C2D1_inline((&___0_value), L_9, NULL);
		goto IL_0046;
	}

IL_003b:
	{
		void* L_10 = V_1;
		uintptr_t L_11 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>((&___0_value),NULL));
		int32_t L_12 = V_0;
		int64_t L_13 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_12,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_10, (void*)L_11, L_13, NULL);
	}

IL_0046:
	{
		int32_t L_14 = __this->___Length;
		int32_t L_15 = V_0;
		__this->___Length = ((int32_t)il2cpp_codegen_add(L_14, L_15));
		return;
	}
}
// Method Definition Index: 65686
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_Add_TisIl2CppFullySharedGenericStruct_mDDC9C1D1487BB5B9B776AD9F9B6581F838DA5C09_fshared (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t968E150614965331C7DD07EE4B335800AC5FBC8D = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	void* V_1 = NULL;
	{
		uint32_t L_0 = SizeOf_T_t968E150614965331C7DD07EE4B335800AC5FBC8D;
		V_0 = (int32_t)L_0;
		int32_t L_1 = __this->___Length;
		int32_t L_2 = V_0;
		UnsafeAppendBuffer_SetCapacity_mF80BF3DD388E819E52586A458C10606333611269(__this, ((int32_t)il2cpp_codegen_add(L_1, L_2)), NULL);
		uint8_t* L_3 = __this->___Ptr;
		int32_t L_4 = __this->___Length;
		V_1 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_3, L_4));
		void* L_5 = V_1;
		uint64_t L_6 = (il2cpp_codegen_conv<uint64_t,void*,intptr_t,false,false>(L_5,NULL));
		int32_t L_7;
		L_7 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		bool L_8;
		L_8 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9(L_6, L_7, NULL);
		if (!L_8)
		{
			goto IL_003b;
		}
	}
	{
		void* L_9 = V_1;
		((  void (*) (Il2CppFullySharedGenericStruct*, void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))((Il2CppFullySharedGenericStruct*)___0_value, L_9, il2cpp_rgctx_method(method->rgctx_data, 2));
		goto IL_0046;
	}

IL_003b:
	{
		void* L_10 = V_1;
		uintptr_t L_11 = (il2cpp_codegen_conv<uintptr_t,Il2CppFullySharedGenericStruct*,intptr_t,false,false>((Il2CppFullySharedGenericStruct*)___0_value,NULL));
		int32_t L_12 = V_0;
		int64_t L_13 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_12,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_10, (void*)L_11, L_13, NULL);
	}

IL_0046:
	{
		int32_t L_14 = __this->___Length;
		int32_t L_15 = V_0;
		__this->___Length = ((int32_t)il2cpp_codegen_add(L_14, L_15));
		return;
	}
}
// Method Definition Index: 65689
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_Add_TisIl2CppFullySharedGenericStruct_mBC28FDDA775CF46EBFF35FACA19AB97DA55D7C5C_fshared (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tE3F6B05D1E5A45A817DFAAD5B883AEAC587DD659 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 2));
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_value), NULL);
		UnsafeAppendBuffer_Add_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m115C1E10CFF2E5179C099DDD59C5779D0863C1C1(__this, L_0, NULL);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_1 = ___0_value;
		void* L_2;
		L_2 = ((  void* (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_1, NULL);
		uint32_t L_3 = SizeOf_T_tE3F6B05D1E5A45A817DFAAD5B883AEAC587DD659;
		int32_t L_4;
		L_4 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_value), NULL);
		UnsafeAppendBuffer_Add_m1CE98EFF1C7CAFEDCDE896B21530D3B2A3311D25(__this, L_2, ((int32_t)il2cpp_codegen_multiply((int32_t)L_3, L_4)), NULL);
		return;
	}
}
// Method Definition Index: 65688
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_AddArray_TisIl2CppFullySharedGenericStruct_m5627B5F2DCE95940F3F9DFF77A97789E2CCD5E57_fshared (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, void* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tCB7BCEF928A0AD313FE193E3B540DF5281DE8184 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___1_length;
		UnsafeAppendBuffer_Add_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m115C1E10CFF2E5179C099DDD59C5779D0863C1C1(__this, L_0, NULL);
		int32_t L_1 = ___1_length;
		if (!L_1)
		{
			goto IL_0019;
		}
	}
	{
		void* L_2 = ___0_ptr;
		int32_t L_3 = ___1_length;
		uint32_t L_4 = SizeOf_T_tCB7BCEF928A0AD313FE193E3B540DF5281DE8184;
		UnsafeAppendBuffer_Add_m1CE98EFF1C7CAFEDCDE896B21530D3B2A3311D25(__this, L_2, ((int32_t)il2cpp_codegen_multiply(L_3, (int32_t)L_4)), NULL);
	}

IL_0019:
	{
		return;
	}
}
// Method Definition Index: 65690
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeAppendBuffer_Pop_TisIl2CppFullySharedGenericStruct_m504B53F43031CB15FF39BBBA94BE052B3E33D1A9_fshared (UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500* __this, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericStruct L_13 = alloca(SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E);
	const Il2CppFullySharedGenericStruct L_21 = L_13;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	Il2CppFullySharedGenericStruct V_3 = alloca(SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E);
	memset(V_3, 0, SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E);
	{
		uint32_t L_0 = SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E;
		V_0 = (int32_t)L_0;
		uint8_t* L_1 = __this->___Ptr;
		uint64_t L_2 = (il2cpp_codegen_conv<uint64_t,uint8_t*,intptr_t,false,false>(L_1,NULL));
		int32_t L_3 = __this->___Length;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		V_1 = L_4;
		int64_t L_5 = V_1;
		int32_t L_6 = V_0;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_6,NULL));
		V_2 = ((int64_t)il2cpp_codegen_subtract(((int64_t)il2cpp_codegen_add((int64_t)L_2, L_5)), L_7));
		int64_t L_8 = V_2;
		int32_t L_9;
		L_9 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		bool L_10;
		L_10 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0034;
		}
	}
	{
		int64_t L_11 = V_2;
		uintptr_t L_12 = (il2cpp_codegen_conv<uintptr_t,int64_t,int64_t,false,false>(L_11,NULL));
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), NULL, (void*)L_12, 0, (Il2CppFullySharedGenericStruct*)L_13);
		il2cpp_codegen_memcpy(V_3, L_13, SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E);
		goto IL_0040;
	}

IL_0034:
	{
		uintptr_t L_14 = (il2cpp_codegen_conv<uintptr_t,Il2CppFullySharedGenericStruct*,intptr_t,false,false>((Il2CppFullySharedGenericStruct*)V_3,NULL));
		int64_t L_15 = V_2;
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		int32_t L_17 = V_0;
		int64_t L_18 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_17,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_14, (void*)L_16, L_18, NULL);
	}

IL_0040:
	{
		int32_t L_19 = __this->___Length;
		int32_t L_20 = V_0;
		__this->___Length = ((int32_t)il2cpp_codegen_subtract(L_19, L_20));
		il2cpp_codegen_memcpy(L_21, V_3, SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E);
		il2cpp_codegen_memcpy(il2cppRetVal, L_21, SizeOf_T_t46B54E1394E86F4EC59651D45B3DFBD912AF848E);
		return;
	}
}
// Method Definition Index: 30147
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_m4590CF7239319F64DD1DE7F1E5CF341CD5A88678_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* ___1_src, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___2_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* L_2 = ___1_src;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_3 = ___2_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233*, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30149
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_m20D6C46671CDF2A0117036841F76C9EA2E89765B_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* ___1_src, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___2_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* L_2 = ___1_src;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_3 = ___2_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1*, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30151
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_mBB3BE09088AA14350A4E99D0FA9ACE372092D649_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___1_src, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___2_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* L_2 = ___1_src;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_3 = ___2_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30147
// Method Definition Index: 30149
// Method Definition Index: 30151
// Method Definition Index: 30152
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_mDFF41C29FE9637F59BA78CB79E38512A3CF09AC7_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___1_src, int32_t ___2_mipIndex, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___3_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* L_2 = ___1_src;
		int32_t L_3 = ___2_mipIndex;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_4 = ___3_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30152
// Method Definition Index: 30148
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_mFC4D980DAF673130B0757D1BF0C74ECC72AA8C0E_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* ___1_src, int32_t ___2_size, int32_t ___3_offset, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___4_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* L_2 = ___1_src;
		int32_t L_3 = ___2_size;
		int32_t L_4 = ___3_offset;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_5 = ___4_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233*, int32_t, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30150
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_m1797A693E3B4DD59699F15D1703EA6B1A3490A57_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* ___1_src, int32_t ___2_size, int32_t ___3_offset, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___4_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* L_2 = ___1_src;
		int32_t L_3 = ___2_size;
		int32_t L_4 = ___3_offset;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_5 = ___4_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1*, int32_t, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_mA413BB50721484FE5C2F38E17C1C1E3F3B3D4CB3_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___1_src, int32_t ___2_mipIndex, int32_t ___3_dstFormat, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___4_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* L_2 = ___1_src;
		int32_t L_3 = ___2_mipIndex;
		int32_t L_4 = ___3_dstFormat;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_5 = ___4_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*, int32_t, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_mC224093E7F4B147F2A1F86C804DDBBE19384AECB_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___1_src, int32_t ___2_mipIndex, int32_t ___3_dstFormat, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___4_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* L_2 = ___1_src;
		int32_t L_3 = ___2_mipIndex;
		int32_t L_4 = ___3_dstFormat;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_5 = ___4_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*, int32_t, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30148
// Method Definition Index: 30150
// Method Definition Index: 30154
// Method Definition Index: 30153
// Method Definition Index: 30155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_m3DB621F402102565ADA22FE7821F8684ACED6C87_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___1_src, int32_t ___2_mipIndex, int32_t ___3_x, int32_t ___4_width, int32_t ___5_y, int32_t ___6_height, int32_t ___7_z, int32_t ___8_depth, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___9_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* L_2 = ___1_src;
		int32_t L_3 = ___2_mipIndex;
		int32_t L_4 = ___3_x;
		int32_t L_5 = ___4_width;
		int32_t L_6 = ___5_y;
		int32_t L_7 = ___6_height;
		int32_t L_8 = ___7_z;
		int32_t L_9 = ___8_depth;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_10 = ___9_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, L_6, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30155
// Method Definition Index: 30157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_m076CC5B64DE819DBAF372FE886BA2B90CBD3BC31_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___1_src, int32_t ___2_mipIndex, int32_t ___3_x, int32_t ___4_width, int32_t ___5_y, int32_t ___6_height, int32_t ___7_z, int32_t ___8_depth, int32_t ___9_dstFormat, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___10_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* L_2 = ___1_src;
		int32_t L_3 = ___2_mipIndex;
		int32_t L_4 = ___3_x;
		int32_t L_5 = ___4_width;
		int32_t L_6 = ___5_y;
		int32_t L_7 = ___6_height;
		int32_t L_8 = ___7_z;
		int32_t L_9 = ___8_depth;
		int32_t L_10 = ___9_dstFormat;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_11 = ___10_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, L_6, L_7, L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_RequestAsyncReadbackIntoNativeArray_TisIl2CppFullySharedGenericStruct_m6CE123F7CF5137595A8A743B5AF17BD8D2C3F66B_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_output, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___1_src, int32_t ___2_mipIndex, int32_t ___3_x, int32_t ___4_width, int32_t ___5_y, int32_t ___6_height, int32_t ___7_z, int32_t ___8_depth, int32_t ___9_dstFormat, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* ___10_callback, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_output;
		Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* L_2 = ___1_src;
		int32_t L_3 = ___2_mipIndex;
		int32_t L_4 = ___3_x;
		int32_t L_5 = ___4_width;
		int32_t L_6 = ___5_y;
		int32_t L_7 = ___6_height;
		int32_t L_8 = ___7_z;
		int32_t L_9 = ___8_depth;
		int32_t L_10 = ___9_dstFormat;
		Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F* L_11 = ___10_callback;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, Action_1_t6AC29B34E68BC53AA807670D868CBB59CD5D995F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, L_6, L_7, L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30157
// Method Definition Index: 30156
// Method Definition Index: 30228
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_m4612A502BC75360BA91CFDF3E61DBCB1D75E90CB_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* ___0_buffer, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* ___1_data, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* L_1 = ___0_buffer;
		List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* L_2 = ___1_data;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233*, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30229
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_m27C6E5B0D3DF6CFB5CB1474C6AE92BD28D641399_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* ___0_buffer, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___1_data, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* L_1 = ___0_buffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_2 = ___1_data;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30235
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_m9DF8E236C9AD375EAB748CC5715F23ABBEE6BA75_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* ___0_buffer, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* ___1_data, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* L_1 = ___0_buffer;
		List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* L_2 = ___1_data;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1*, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30236
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_m3F9A4F561905D138501C3EF53CAF41EBF524A8E2_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* ___0_buffer, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___1_data, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* L_1 = ___0_buffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_2 = ___1_data;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30228
// Method Definition Index: 30229
// Method Definition Index: 30235
// Method Definition Index: 30236
// Method Definition Index: 30231
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_mE27938896498F85F95486585EB3BB8F54DBEF3D9_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* ___0_buffer, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* ___1_data, int32_t ___2_managedBufferStartIndex, int32_t ___3_graphicsBufferStartIndex, int32_t ___4_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* L_1 = ___0_buffer;
		List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* L_2 = ___1_data;
		int32_t L_3 = ___2_managedBufferStartIndex;
		int32_t L_4 = ___3_graphicsBufferStartIndex;
		int32_t L_5 = ___4_count;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233*, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30232
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_mD59E7951302BED8F22E9A1C0D3E3EE37ADEFA4AC_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* ___0_buffer, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___1_data, int32_t ___2_nativeBufferStartIndex, int32_t ___3_graphicsBufferStartIndex, int32_t ___4_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233* L_1 = ___0_buffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_2 = ___1_data;
		int32_t L_3 = ___2_nativeBufferStartIndex;
		int32_t L_4 = ___3_graphicsBufferStartIndex;
		int32_t L_5 = ___4_count;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, ComputeBuffer_t51EADA9015EBCC1B982C5584E9AB2734415A8233*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30238
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_m146FB8A0C1686793072BF6F4C14A4F38E29FD925_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* ___0_buffer, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* ___1_data, int32_t ___2_managedBufferStartIndex, int32_t ___3_graphicsBufferStartIndex, int32_t ___4_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* L_1 = ___0_buffer;
		List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4* L_2 = ___1_data;
		int32_t L_3 = ___2_managedBufferStartIndex;
		int32_t L_4 = ___3_graphicsBufferStartIndex;
		int32_t L_5 = ___4_count;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1*, List_1_tE5211AFE92BF26309D7C5814A29544E9EF496FE4*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30239
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeCommandBuffer_SetBufferData_TisIl2CppFullySharedGenericStruct_m605037FF731BED168BA65C7E3A07F6B48A2F76C5_fshared (UnsafeCommandBuffer_tDE6BB2FE234DC7453CA682AB275888E9E35F22F2* __this, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* ___0_buffer, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___1_data, int32_t ___2_nativeBufferStartIndex, int32_t ___3_graphicsBufferStartIndex, int32_t ___4_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* L_0 = ((BaseCommandBuffer_tD67BB9B3F740537BD3F3A96FA17D06E6C3BFDC06*)__this)->___m_WrappedCommandBuffer;
		GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1* L_1 = ___0_buffer;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_2 = ___1_data;
		int32_t L_3 = ___2_nativeBufferStartIndex;
		int32_t L_4 = ___3_graphicsBufferStartIndex;
		int32_t L_5 = ___4_count;
		NullCheck(L_0);
		((  void (*) (CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7*, GraphicsBuffer_t91FACD3CD78588C25C361C453D1A2FE055EC4AF1*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
// Method Definition Index: 30231
// Method Definition Index: 30232
// Method Definition Index: 30238
// Method Definition Index: 30239
// Method Definition Index: 65972
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UnsafeListExtensions_ArraysEqual_TisIl2CppFullySharedGenericStruct_m26517D1B620B6BB143F8CDBCBC9299D6C9AA512F_fshared (UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6 ___0_container, UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6* ___1_other, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t36936CBBA76E77B94AE3777BAF4D0FDDB161EC12 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 2));
	void* L_9 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 2)));
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t36936CBBA76E77B94AE3777BAF4D0FDDB161EC12);
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t36936CBBA76E77B94AE3777BAF4D0FDDB161EC12);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppFullySharedGenericStruct V_1 = alloca(SizeOf_T_t36936CBBA76E77B94AE3777BAF4D0FDDB161EC12);
	memset(V_1, 0, SizeOf_T_t36936CBBA76E77B94AE3777BAF4D0FDDB161EC12);
	UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_container), NULL);
		UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6* L_1 = ___1_other;
		int32_t L_2;
		L_2 = ((  int32_t (*) (UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_1, NULL);
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0011;
		}
	}
	{
		return (bool)0;
	}

IL_0011:
	{
		V_0 = 0;
		goto IL_0042;
	}

IL_0015:
	{
		int32_t L_3 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), (&___0_container), L_3, (Il2CppFullySharedGenericStruct*)L_4);
		il2cpp_codegen_memcpy(V_1, L_4, SizeOf_T_t36936CBBA76E77B94AE3777BAF4D0FDDB161EC12);
		UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6* L_5 = ___1_other;
		UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6 L_6 = (*(UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6*)L_5);
		V_2 = L_6;
		int32_t L_7 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), (&V_2), L_7, (Il2CppFullySharedGenericStruct*)L_8);
		Il2CppConstrainedCallData L_10;
		Il2CppMethodPointer L_11 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(method->rgctx_data, 2), il2cpp_rgctx_method(method->rgctx_data, 3), (void*)(Il2CppFullySharedGenericStruct*)V_1, &L_10, L_9);
		bool L_12 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericStruct >::Invoke(L_11, L_10.method,L_10.thisPtr, L_8);
		if (L_12)
		{
			goto IL_003e;
		}
	}
	{
		return (bool)0;
	}

IL_003e:
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0042:
	{
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = ((  int32_t (*) (UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_container), NULL);
		if ((!(((uint32_t)L_14) == ((uint32_t)L_15))))
		{
			goto IL_0015;
		}
	}
	{
		return (bool)1;
	}
}
// Method Definition Index: 65967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UnsafeListExtensions_Contains_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m1375620C18228462A2BF75D07835F90AD70516B8 (UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E ___0_container, GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E L_0 = ___0_container;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_1 = ___1_value;
		int32_t L_2;
		L_2 = UnsafeListExtensions_IndexOf_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mAAD5AAC095A0510309AEAA951828DAE9B8C783A2(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 1));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 65971
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UnsafeListExtensions_Contains_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericAny_m849EF25437A5D844E398509A94A164CA1BD07D7A_fshared (ParallelReader_tE9E5B90E22A4BC77DB4B327155E0A9F071FC4839 ___0_container, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_t71E8B5E5C2FEAD5E433A30BDC27D9E9F6C907692 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_U_t71E8B5E5C2FEAD5E433A30BDC27D9E9F6C907692);
	//<source_info:<no-source>:1>
	{
		ParallelReader_tE9E5B90E22A4BC77DB4B327155E0A9F071FC4839 L_0 = ___0_container;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___1_value : &___1_value), SizeOf_U_t71E8B5E5C2FEAD5E433A30BDC27D9E9F6C907692);
		int32_t L_2;
		L_2 = InvokerFuncInvoker2< int32_t, ParallelReader_tE9E5B90E22A4BC77DB4B327155E0A9F071FC4839, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? L_1: *(void**)L_1));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 65969
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UnsafeListExtensions_Contains_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericAny_m9A04B9F17C4745874BFCBA06B0CA62B3C1BD8618_fshared (ReadOnly_t620C834D6C54D781225D753876F232E09821956C ___0_container, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_tDC75599B528D5C6C23F210DE1975466A48F27F8C = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_U_tDC75599B528D5C6C23F210DE1975466A48F27F8C);
	//<source_info:<no-source>:1>
	{
		ReadOnly_t620C834D6C54D781225D753876F232E09821956C L_0 = ___0_container;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___1_value : &___1_value), SizeOf_U_tDC75599B528D5C6C23F210DE1975466A48F27F8C);
		int32_t L_2;
		L_2 = InvokerFuncInvoker2< int32_t, ReadOnly_t620C834D6C54D781225D753876F232E09821956C, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? L_1: *(void**)L_1));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 65967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UnsafeListExtensions_Contains_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericAny_mEA66444086816FFF6C02FDEDF064DC92D43ABB07_fshared (UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6 ___0_container, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_t79ED4F2F667B96B1F466267D4E93F6567EE08001 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_U_t79ED4F2F667B96B1F466267D4E93F6567EE08001);
	//<source_info:<no-source>:1>
	{
		UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6 L_0 = ___0_container;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___1_value : &___1_value), SizeOf_U_t79ED4F2F667B96B1F466267D4E93F6567EE08001);
		int32_t L_2;
		L_2 = InvokerFuncInvoker2< int32_t, UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? L_1: *(void**)L_1));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 65966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeListExtensions_IndexOf_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mAAD5AAC095A0510309AEAA951828DAE9B8C783A2 (UnsafeList_1_t08F6AE31B94E9EFB7804E94FC5A06EE32A6A326E ___0_container, GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		ReadOnlySpan_1_tA7B55DDCFA4B3B474C0F1DCFCEADB2ABB0EC8F10 L_0;
		L_0 = UnsafeList_1_AsReadOnlySpan_m0B9F520E68A4F8F1C7DE958A934E9AFB5D86B53A((&___0_container), NULL);
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_1 = ___1_value;
		int32_t L_2;
		L_2 = NativeArrayExtensions_IndexOf_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m6F4F2F3FD9AEB9A0266F285F36171E22C3501B90(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 2));
		return L_2;
	}
}
// Method Definition Index: 65970
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeListExtensions_IndexOf_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericAny_m4C0405202053EC610D5814D16972342C44B04015_fshared (ParallelReader_tE9E5B90E22A4BC77DB4B327155E0A9F071FC4839 ___0_container, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_t527490260DD61FB68E8B24509583B4E5B8004E85 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_U_t527490260DD61FB68E8B24509583B4E5B8004E85);
	//<source_info:<no-source>:1>
	{
		ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 L_0;
		L_0 = ((  ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 (*) (ParallelReader_tE9E5B90E22A4BC77DB4B327155E0A9F071FC4839*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_container), il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 1)) ? ___1_value : &___1_value), SizeOf_U_t527490260DD61FB68E8B24509583B4E5B8004E85);
		int32_t L_2;
		L_2 = InvokerFuncInvoker2< int32_t, ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 1)) ? L_1: *(void**)L_1));
		return L_2;
	}
}
// Method Definition Index: 65968
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeListExtensions_IndexOf_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericAny_m666B6958EA2FFC68FF7ED5C8350CE4F72D717323_fshared (ReadOnly_t620C834D6C54D781225D753876F232E09821956C ___0_container, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_t8A2813E5F32C60A802660497A33599DED0C1E01F = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_U_t8A2813E5F32C60A802660497A33599DED0C1E01F);
	//<source_info:<no-source>:1>
	{
		ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 L_0;
		L_0 = ((  ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 (*) (ReadOnly_t620C834D6C54D781225D753876F232E09821956C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_container), il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 1)) ? ___1_value : &___1_value), SizeOf_U_t8A2813E5F32C60A802660497A33599DED0C1E01F);
		int32_t L_2;
		L_2 = InvokerFuncInvoker2< int32_t, ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 1)) ? L_1: *(void**)L_1));
		return L_2;
	}
}
// Method Definition Index: 65966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeListExtensions_IndexOf_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericAny_m57EF2104D6B01A3B93003ABF811294D496610604_fshared (UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6 ___0_container, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_t54CFCA7844B58AFDB181E954D6BBD75E1E48ACF7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_U_t54CFCA7844B58AFDB181E954D6BBD75E1E48ACF7);
	//<source_info:<no-source>:1>
	{
		ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 L_0;
		L_0 = ((  ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25 (*) (UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_container), il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 1)) ? ___1_value : &___1_value), SizeOf_U_t54CFCA7844B58AFDB181E954D6BBD75E1E48ACF7);
		int32_t L_2;
		L_2 = InvokerFuncInvoker2< int32_t, ReadOnlySpan_1_tE8C37D9A05FCAB953169AFFE8A0ABCA809781E25, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 1)) ? L_1: *(void**)L_1));
		return L_2;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mCCBA9B456E509039F0C37BA72EFD6D0CDAF16BB6 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEA2D219466CA70D0772888D0B2AA5BDF95B3D7B0(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_mC33D66B36C84BB3713D03F117D2FC7BA97B6F1B3 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m1889622A4F9D451311D704800071C27E203E30FD(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m9DB5174B630BFCDD07377E084AC0454D96CAC220 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m53A432E510AFC1B5E17AC7D4CEA9BDC969EF4183(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mC5DB96096F58345413CB2300A12310634E7D4AB1 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mBBBCD7A3795516F652E2A209921D9F365FEF117D(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_mB3FAEAB9C60EB3A7B2966293CED32A184224B5C2 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_mFCFCB281237C3FD181B82326F1CDC74ECDC26835(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFC6AE4DAC01DFDFF29C1E53E06F14FB0B0D66206 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m28DB190FC25AC6811E2F609C118B25148772E8ED(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m369A63CE018827DD5E6BE176CFF6F8AEC91B6808 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m97E2EBA7DBA4EC678CB7F7D5A1E14B2687937D9B(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m8D3687B5D1BA985486262D8B54210C4FBCE092DD (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_mEE7449D53E0B0DF2588A7ABF7DE9C12E23AEC194(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m10477D640DA472DA625A765ED5827A671C732748 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m5EF0E0217EB20D03E739EF4F21BA8ED27454FBA1(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m4703FC665098F0086135518707826A9643725C05 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m11C03B89A0BC9969D9C5F48944DA915764AB7653(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m3DF039E5AB6577F727530E71E36C46240A76B643 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m1039B6A2212089AF73B18D7545E9DC3D3DF22E44(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m0F983D34E0DCB835F9351EB64BB37B3BBD53D345 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m4AC175F5FE1C77C9A2E7602A09E229A5CF617FAF(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m62629C19185CA06E83F04EC7AE00FDFCACF04587 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m7CF1071B4128F92A069498179CE85F80CB5AEBE1(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mDD38B740F2986420537A4FABB757116266FE03B9 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m47E7EA1FA34E44C4B7E215FA109EFC5813E93948(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m8802747A63F08F7229D7AD998621B29674AC1392 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m84BBCADD738D8E17724D100724F1173F24CC9D46(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBAA6B72D2B45297384CE311773557353F2E031B8 (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m92740FC50E0692378ABED6D572FE0AA5FFF18DFB(L_14, L_15, (&V_2), (&V_3), (&V_4), NULL);
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_AllocateHashMap_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_mD7F5F49BFAB2AEE159CED53DACA62E9374B0B063_fshared (int32_t ___0_length, int64_t ___1_bucketLength, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_label, UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** ___3_outBuf, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	CHECKED_LOCAL(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_1 = NULL;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		uint32_t L_1 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		CHECKED_LOCAL_INIT(Assert_tDC16963451AC4364803739B73A4477ADCB365863_StaticInit,(Assert_tDC16963451AC4364803739B73A4477ADCB365863_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Assert_IsTrue_mE42C53B7220324D1FBAFB7AE48A7D8DD7796A663((bool)((((int32_t)((((int32_t)L_1) > ((int32_t)((int32_t)64)))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(((int32_t)64), ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_2)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_label;
		void* L_5;
		L_5 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_3, ((int32_t)64), L_4, NULL);
		V_1 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_5;
		int64_t L_6 = ___1_bucketLength;
		int64_t L_7;
		L_7 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_6, NULL);
		___1_bucketLength = L_7;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_8 = V_1;
		int32_t L_9 = ___0_length;
		NullCheck(L_8);
		L_8->___keyCapacity = L_9;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_10 = V_1;
		int64_t L_11 = ___1_bucketLength;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_11, L_12)),NULL));
		NullCheck(L_10);
		L_10->___bucketCapacityMask = L_13;
		int32_t L_14 = ___0_length;
		int64_t L_15 = ___1_bucketLength;
		int64_t L_16;
		L_16 = ((  int64_t (*) (int32_t, int64_t, int64_t*, int64_t*, int64_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_14, L_15, (&V_2), (&V_3), (&V_4), il2cpp_rgctx_method(method->rgctx_data, 0));
		V_5 = L_16;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_17 = V_1;
		int64_t L_18 = V_5;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_19 = ___2_label;
		void* L_20;
		L_20 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_18, ((int32_t)64), L_19, NULL);
		NullCheck(L_17);
		L_17->___values = (uint8_t*)L_20;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_21 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = V_1;
		NullCheck(L_22);
		uint8_t* L_23 = L_22->___values;
		int64_t L_24 = V_2;
		intptr_t L_25 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_24,NULL));
		NullCheck(L_21);
		L_21->___keys = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_23, L_25));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_27 = V_1;
		NullCheck(L_27);
		uint8_t* L_28 = L_27->___values;
		int64_t L_29 = V_3;
		intptr_t L_30 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_29,NULL));
		NullCheck(L_26);
		L_26->___next = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_28, L_30));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_31 = V_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = V_1;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___values;
		int64_t L_34 = V_4;
		intptr_t L_35 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_34,NULL));
		NullCheck(L_31);
		L_31->___buckets = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_33, L_35));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926** L_36 = ___3_outBuf;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_37 = V_1;
		*(((intptr_t*)L_36)) = ((intptr_t)L_37);
		return;
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEA2D219466CA70D0772888D0B2AA5BDF95B3D7B0 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(int32_t);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m1889622A4F9D451311D704800071C27E203E30FD (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(bool);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m53A432E510AFC1B5E17AC7D4CEA9BDC969EF4183 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mBBBCD7A3795516F652E2A209921D9F365FEF117D (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_mFCFCB281237C3FD181B82326F1CDC74ECDC26835 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m28DB190FC25AC6811E2F609C118B25148772E8ED (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(int32_t);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m97E2EBA7DBA4EC678CB7F7D5A1E14B2687937D9B (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_mEE7449D53E0B0DF2588A7ABF7DE9C12E23AEC194 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m5EF0E0217EB20D03E739EF4F21BA8ED27454FBA1 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m11C03B89A0BC9969D9C5F48944DA915764AB7653 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m1039B6A2212089AF73B18D7545E9DC3D3DF22E44 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m4AC175F5FE1C77C9A2E7602A09E229A5CF617FAF (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(int32_t);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m7CF1071B4128F92A069498179CE85F80CB5AEBE1 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(int32_t);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m47E7EA1FA34E44C4B7E215FA109EFC5813E93948 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(int32_t);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m84BBCADD738D8E17724D100724F1173F24CC9D46 (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(uint32_t);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m92740FC50E0692378ABED6D572FE0AA5FFF18DFB (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = sizeof(int32_t);
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = sizeof(uint32_t);
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnsafeParallelHashMapData_CalculateDataSize_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_m86C560D40D8AAEF07631BFB8D1698688602BFD91_fshared (int32_t ___0_length, int64_t ___1_bucketLength, int64_t* ___2_keyOffset, int64_t* ___3_nextOffset, int64_t* ___4_bucketOffset, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_TValue_tB73822E5C10E34F3A9A9B541102F7CAD7D84853E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const uint32_t SizeOf_TKey_tDBC8C46C28C29C419CF2B4A775A1045FCC9C9F3D = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t V_4 = 0;
	int64_t V_5 = 0;
	{
		uint32_t L_0 = SizeOf_TValue_tB73822E5C10E34F3A9A9B541102F7CAD7D84853E;
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_0,NULL));
		uint32_t L_2 = SizeOf_TKey_tDBC8C46C28C29C419CF2B4A775A1045FCC9C9F3D;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		V_0 = L_3;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		V_1 = L_4;
		int32_t L_5 = ___0_length;
		int64_t L_6 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_5,NULL));
		int64_t L_7;
		L_7 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_1, L_6)), ((int32_t)64), NULL);
		V_2 = L_7;
		int64_t L_8 = V_0;
		int32_t L_9 = ___0_length;
		int64_t L_10 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_9,NULL));
		int64_t L_11;
		L_11 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_8, L_10)), ((int32_t)64), NULL);
		V_3 = L_11;
		int64_t L_12 = V_1;
		int32_t L_13 = ___0_length;
		int64_t L_14 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_13,NULL));
		int64_t L_15;
		L_15 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_12, L_14)), ((int32_t)64), NULL);
		V_4 = L_15;
		int64_t L_16 = V_1;
		int64_t L_17 = ___1_bucketLength;
		int64_t L_18;
		L_18 = CollectionHelper_Align_mC40859378CEE3C9844C39FAC725566EBA5E7BD82(((int64_t)il2cpp_codegen_multiply(L_16, L_17)), ((int32_t)64), NULL);
		V_5 = L_18;
		int64_t L_19 = V_2;
		int64_t L_20 = V_3;
		int64_t L_21 = V_4;
		int64_t L_22 = V_5;
		int64_t* L_23 = ___2_keyOffset;
		int64_t L_24 = V_2;
		*(L_23) = L_24;
		int64_t* L_25 = ___3_nextOffset;
		int64_t* L_26 = ___2_keyOffset;
		int64_t L_27 = *(L_26);
		int64_t L_28 = V_3;
		*(L_25) = ((int64_t)il2cpp_codegen_add(L_27, L_28));
		int64_t* L_29 = ___4_bucketOffset;
		int64_t* L_30 = ___3_nextOffset;
		int64_t L_31 = *(L_30);
		int64_t L_32 = V_4;
		*(L_29) = ((int64_t)il2cpp_codegen_add(L_31, L_32));
		return ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(L_19, L_20)), L_21)), L_22));
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_m49E855A91D083A54CFF44DEB13335123AD3C4001 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t2FF0F1BBD323229A2F9ABD52397EA6EF9B105E09 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 L_14;
		L_14 = UnsafeUtility_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_mFD7DBC1199616005466125347027F6201459B40D_inline((void*)L_12, L_13, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94, ((&___1_result))->___m_Buffer, L_10, (L_14));
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mAB07175AB7AA23FBCB3571D1F770E945969E8567 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_14;
		L_14 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_12, L_13, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, ((&___1_result))->___m_Buffer, L_10, (L_14));
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mA5240CB06C397E4086D1016D90B80350DFC04ADC (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_14;
		L_14 = UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline((void*)L_12, L_13, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB, ((&___1_result))->___m_Buffer, L_10, (L_14));
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m555B8BDEC7D510E8BBA54684D119E26098F369C6 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB L_14;
		L_14 = UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline((void*)L_12, L_13, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB, ((&___1_result))->___m_Buffer, L_10, (L_14));
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m7038B50B7446591159A4FD4B5C96EC436C073DEC (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		int32_t L_14;
		L_14 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_12, L_13, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, ((&___1_result))->___m_Buffer, L_10, (L_14));
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mBC5FD6BA6693913CD1A82461A39609D9F97AC4FC (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t8E236FFFE7B598011354300BFCED0A15647BBC5D ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C L_14;
		L_14 = UnsafeUtility_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mFDF2C4591B5F4C0AF4424ED681225F9CF100C5BB_inline((void*)L_12, L_13, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C, ((&___1_result))->___m_Buffer, L_10, (L_14));
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mAAD7AAAE80C57C80CC140F956DA6FAEF8360F6B7 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		uint32_t L_14;
		L_14 = UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline((void*)L_12, L_13, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(uint32_t, ((&___1_result))->___m_Buffer, L_10, (L_14));
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyArray_TisIl2CppFullySharedGenericStruct_m7137096325EC50712B1665E2B5937352A1B004F2_fshared (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___1_result, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_TKey_tA421440C75A581A02A933BEA4E233521D2CE2584 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 2));
	const Il2CppFullySharedGenericStruct L_14 = alloca(SizeOf_TKey_tA421440C75A581A02A933BEA4E233521D2CE2584);
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___1_result), NULL);
		V_4 = L_4;
		goto IL_0054;
	}

IL_001d:
	{
		int32_t* L_5 = V_0;
		int32_t L_6 = V_2;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 4)))));
		V_5 = L_8;
		goto IL_004b;
	}

IL_0028:
	{
		int32_t L_9 = V_3;
		int32_t L_10 = L_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_10, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_11 = ___0_data;
		NullCheck(L_11);
		uint8_t* L_12 = L_11->___keys;
		int32_t L_13 = V_5;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), NULL, (void*)L_12, L_13, (Il2CppFullySharedGenericStruct*)L_14);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), (&___1_result), L_10, L_14);
		int32_t* L_15 = V_1;
		int32_t L_16 = V_5;
		intptr_t L_17 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_16,NULL));
		int32_t L_18 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(L_17, 4)))));
		V_5 = L_18;
	}

IL_004b:
	{
		int32_t L_19 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0054:
	{
		int32_t L_21 = V_2;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_22 = ___0_data;
		NullCheck(L_22);
		int32_t L_23 = L_22->___bucketCapacityMask;
		if ((((int32_t)L_21) > ((int32_t)L_23)))
		{
			goto IL_0062;
		}
	}
	{
		int32_t L_24 = V_3;
		int32_t L_25 = V_4;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_001d;
		}
	}

IL_0062:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mC3C2330139E264EC4EB952292BE242F6511CA8E6 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t6F346645686D9ED3DF9980242A60F6343D9BD346 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m4BCBCB4D1AC60559B41D33E7097084B82F700097((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t2FF0F1BBD323229A2F9ABD52397EA6EF9B105E09* L_11 = (NativeArray_1_t2FF0F1BBD323229A2F9ABD52397EA6EF9B105E09*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_mFD7DBC1199616005466125347027F6201459B40D_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_17 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		int32_t L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m21239CE036F4F5471F4055037C59ACA18A4724CA (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t5F8B14A1FC3085C8F576054B525A95D4898297D8 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_mBEBDFF6E64411CCDC46D8A00FF46DD9D99082631((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_11 = (NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t107C57D0357BCF9956A60495CD8FAADDF1D26AFB* L_17 = (NativeArray_1_t107C57D0357BCF9956A60495CD8FAADDF1D26AFB*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		bool L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_mF765CB2E5FD631DFB79C25DE656F3C1BB359B995_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(bool, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m6D0BEC921137959E6A66721B1B26247236FDC5D4 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t66B0B299E9562B5E22EF3BF01729F553EF5A1143 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m4F24A3063C8E3F28E85784A8E086E8ABCEF80123((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_11 = (NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_tAA41AE8C464559D1987285B6F1D42333CD5EC15B* L_17 = (NativeArray_1_tAA41AE8C464559D1987285B6F1D42333CD5EC15B*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m2E442046FFC024C177FCA6130678FA0B97F3C445_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mA03F53939352AD52E121E78DAABC5895D0CFF08D (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_tA2DA312B446D1C4E01DFB5BABCD5FD907A6D98BB ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m686910AE937E76C8D8BAC2FA971F98F55668D1A1((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_11 = (NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t727E0B11B40EA7D6477F67D79DA7B7F7C383735E* L_17 = (NativeArray_1_t727E0B11B40EA7D6477F67D79DA7B7F7C383735E*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mF42F014B5AA9C633D3FCAB3FFF26646E54395BD8_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m25B1FF2DD44BBEC084000393CE299617A0AC1E75 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t69F48B55F7CB9E53D8DA8AC22D78A9FE2C4ACCBB ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_mFCC843E8A6076977EDC711B85D5A812409F96A92((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_11 = (NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t8E042B4249B3126F27EE49887D2507798DC25F2C* L_17 = (NativeArray_1_t8E042B4249B3126F27EE49887D2507798DC25F2C*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m86FC76E325E9D3B56133BB7A193BAF12B47FBCC1_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3DB176E612D3F9E0446BCC0B1803F073E38F8254 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_tCBCD37F108CC29AF7DD444E7DADEBD5DA915330C ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m8AD3EFA2ADD479EB790D599C9BF297BBFE6A6E22((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_11 = (NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_17 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		int32_t L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m93F6531A2902F3B33BB5570F9F32D9F1D8370947 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t1DC3FE19F0B4A1DF25136B0397012CFE6BE2C193 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m70A3BFBC8F88E9B0C7044FD84799B8FD2D4CF586((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_11 = (NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_tFCAF9979C15E15C78F0F78DB34559D880F381CEE* L_17 = (NativeArray_1_tFCAF9979C15E15C78F0F78DB34559D880F381CEE*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_mAEB04091BED5994494AB1521F1CA283C9A55DA84_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m03E6303F2DD4D5789C5D98C45857139E13C6231F (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t2DFE6540DA40D93DF34F283B6ED85D911565BD6D ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m8AA40536A05046C7F2594BBDB7694F1C91CA23CF((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_11 = (NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t251C0B6A4D277C92366F302523FD5C0031FA1B31* L_17 = (NativeArray_1_t251C0B6A4D277C92366F302523FD5C0031FA1B31*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m6C484995D5C95208A4EB1F0C7664EC42A74DE670_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_mA7105AB4A47434D54EB4334EB60CE6C223EBD882 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t92055CB18DB710BBBCD3CC5107937B10BFDCEA2A ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m2DE1DE05F01D53EE056876CE742559C9DA71D08E((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B* L_11 = (NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t60C2883F9133642CF381234B3DD254605DD4F0A5* L_17 = (NativeArray_1_t60C2883F9133642CF381234B3DD254605DD4F0A5*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m80C61348EC8F9D4F73F0AAA4A69A028E6D599DCD_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_mA0CD942DD01F49ABE86547F584AFFA15502352F7 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t637F773818E79D65A71945EFC311230CEF0730EC ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m24BCC1A996AF2B999A11BAC7FF1B589574131C68((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B* L_11 = (NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB* L_17 = (NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mA6A2DDAF3EA1AF28C0E2A4E7905E5F7C38D40975 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_tBB45ADF53F7E53E64A0AF63EF8702A771FDA1956 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m95CF0086C8462E4956EA2941717F496F9E9157A2((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB* L_11 = (NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B* L_17 = (NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_mC38FFFC4587BA74EF030826B828CC2DF81D6F84B (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t93070D4261139B002601B084DE32FFA5AA5488CE ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_mED5744BD99EE505BA094FB2E2D3E1460FBF35AD9((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_11 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		int32_t L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_tB58D1BE7997E66C484A0FCC487D9A3D3A7D31AEC* L_17 = (NativeArray_1_tB58D1BE7997E66C484A0FCC487D9A3D3A7D31AEC*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m361058B0E058D8D5D3AC6C6C015700E6018A671C_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m1E750A8A323FD50BB2502C9516B48DFD6E8EA959 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t00C5D2C7AF9D9E3622CAB210E6E11E33C4881C8A ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m02951443FBCF5B78507CC0C916DA7B406A6E2FFC((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_11 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		int32_t L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t497DD754C21E03BAC4C1F2BB7A3BB0025FF4EB88* L_17 = (NativeArray_1_t497DD754C21E03BAC4C1F2BB7A3BB0025FF4EB88*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m8460969BD9998B0DFF865186874B2414FEED12C8_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4E1351262AA9FAA749ADAC271C6A88355D3D4D85 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t5B99C2646C28A5C04DF011E6E993BDE26A27A953 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m354A6BD5F31BC54C9F3D2B8A51EF1C71C9005648((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t8E236FFFE7B598011354300BFCED0A15647BBC5D* L_11 = (NativeArray_1_t8E236FFFE7B598011354300BFCED0A15647BBC5D*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mFDF2C4591B5F4C0AF4424ED681225F9CF100C5BB_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_17 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		int32_t L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m07B41A0BA900140C60A8DA63F2CFA357FC3FFA83 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_tD4417ED5E6C2DAC8437C9159D79F622F83C72D39 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m0DD220DB30C031B6200A4119D0DCF56B565846E6((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184* L_11 = (NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		uint32_t L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(uint32_t, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_t703E60DA65EBF076EB4916D3B9D9987A5A09B9CC* L_17 = (NativeArray_1_t703E60DA65EBF076EB4916D3B9D9987A5A09B9CC*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m2A66DBE83F9498AC60B42C9A0B1C7E4401B4CDCC_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m07F57872193FA2EAB888B9D0FAECEC7F5C78B997 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t4AA59D24D1616F48DCDB5CB6C4ABA336C51B1764 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = NativeKeyValueArrays_2_get_Length_m8C99316414D47C54EF1AFF05D069266C1FE65840((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184* L_11 = (NativeArray_1_t453E3DEA4CC9F1056F24E417C3308C35174BC184*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		uint32_t L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(uint32_t, (L_11)->___m_Buffer, L_12, (L_16));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_17 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		int32_t L_22;
		L_22 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_17)->___m_Buffer, L_18, (L_22));
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetKeyValueArrays_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_mE7B20EAFC97698B67540C38AF16BB6595C8B786D_fshared (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeKeyValueArrays_2_t97DEBC72840B73CFCEE6195C4C495C675E96FAF1 ___1_result, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_TKey_t144C42ACB2DDADF052103F43EA00E1E62D94C90F = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 2));
	const Il2CppFullySharedGenericStruct L_16 = alloca(SizeOf_TKey_t144C42ACB2DDADF052103F43EA00E1E62D94C90F);
	const uint32_t SizeOf_TValue_t4FEA332ED977D95FEBFE603FCE1F5250E543CBBF = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 5));
	const Il2CppFullySharedGenericStruct L_22 = alloca(SizeOf_TValue_t4FEA332ED977D95FEBFE603FCE1F5250E543CBBF);
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = ((  int32_t (*) (NativeKeyValueArrays_2_t97DEBC72840B73CFCEE6195C4C495C675E96FAF1*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___1_result), il2cpp_rgctx_method(method->rgctx_data, 0));
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_007b;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0072;
	}

IL_0030:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_11 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&(&___1_result)->___Keys);
		int32_t L_12 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___keys;
		int32_t L_15 = V_6;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), NULL, (void*)L_14, L_15, (Il2CppFullySharedGenericStruct*)L_16);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), L_11, L_12, L_16);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_17 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&(&___1_result)->___Values);
		int32_t L_18 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_19 = ___0_data;
		NullCheck(L_19);
		uint8_t* L_20 = L_19->___values;
		int32_t L_21 = V_6;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)), il2cpp_rgctx_method(method->rgctx_data, 4), NULL, (void*)L_20, L_21, (Il2CppFullySharedGenericStruct*)L_22);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)), il2cpp_rgctx_method(method->rgctx_data, 6), L_17, L_18, L_22);
		int32_t L_23 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t* L_24 = V_1;
		int32_t L_25 = V_6;
		intptr_t L_26 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_25,NULL));
		int32_t L_27 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_24, ((intptr_t)il2cpp_codegen_multiply(L_26, 4)))));
		V_6 = L_27;
	}

IL_0072:
	{
		int32_t L_28 = V_6;
		if ((!(((uint32_t)L_28) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_007b:
	{
		int32_t L_30 = V_2;
		int32_t L_31 = V_5;
		if ((((int32_t)L_30) > ((int32_t)L_31)))
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_32 = V_3;
		int32_t L_33 = V_4;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0025;
		}
	}

IL_0085:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_mAFA081C9B2AD7C9734C843DA3296E66A06F64258 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t60C2883F9133642CF381234B3DD254605DD4F0A5 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m80C61348EC8F9D4F73F0AAA4A69A028E6D599DCD_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_mC207F978B303B5F48108C11804D921E6F240342D (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t107C57D0357BCF9956A60495CD8FAADDF1D26AFB ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		bool L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_mF765CB2E5FD631DFB79C25DE656F3C1BB359B995_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(bool, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mA1DA3B28AE02653539C97673A6326C270E84E919 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t20401E81C3977721C4821E208D326838C60AB66B ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m1AAF49523204B0A3114C17796C71ACB8802FD73A (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_tB58D1BE7997E66C484A0FCC487D9A3D3A7D31AEC ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m361058B0E058D8D5D3AC6C6C015700E6018A671C_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m10334CA50169EDC7D8190F1459D6E18A6EF2030A (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t3F1CB4E86EF77335C3D96B3C1EFA12F8E52314EB ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_mEC7179C6FD7FEFFC5E8D1BE999A7CF349AD8B8ED (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_tAA41AE8C464559D1987285B6F1D42333CD5EC15B ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m2E442046FFC024C177FCA6130678FA0B97F3C445_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_m0E8CE5C728489D98BC6F0B92382E2326A0E0769D (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t727E0B11B40EA7D6477F67D79DA7B7F7C383735E ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mF42F014B5AA9C633D3FCAB3FFF26646E54395BD8_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m200DA9B2BC8B0CEB99FD9F46ED953E12251AC2B4 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t703E60DA65EBF076EB4916D3B9D9987A5A09B9CC ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m2A66DBE83F9498AC60B42C9A0B1C7E4401B4CDCC_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m9E1C36193953F8B34B0DAA5D4C5EE5B57D78B5AD (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t8E042B4249B3126F27EE49887D2507798DC25F2C ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m86FC76E325E9D3B56133BB7A193BAF12B47FBCC1_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4769F528CC3AB04D768F83B2A2A016AE29C5F87E (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		int32_t L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_mD27DE5474C726F013A990E7CCE11642CDE28708D (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_tFCAF9979C15E15C78F0F78DB34559D880F381CEE ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_mAEB04091BED5994494AB1521F1CA283C9A55DA84_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisIl2CppFullySharedGenericStruct_m127A626CD960E02AEBF7B88B7A8F3A9401445A69_fshared (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___1_result, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_TValue_t0232C4E00D4E39FC209358F87310CF1B96E0619E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 2));
	const Il2CppFullySharedGenericStruct L_16 = alloca(SizeOf_TValue_t0232C4E00D4E39FC209358F87310CF1B96E0619E);
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___1_result), NULL);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), NULL, (void*)L_14, L_15, (Il2CppFullySharedGenericStruct*)L_16);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), (&___1_result), L_12, L_16);
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_mF1597D81CF060DA43380933C7653AEE5D655FE2F (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t497DD754C21E03BAC4C1F2BB7A3BB0025FF4EB88 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m8460969BD9998B0DFF865186874B2414FEED12C8_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_GetValueArray_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_mBC08096B208A0BEB933ADEFBECE4F028F2D94483 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, NativeArray_1_t251C0B6A4D277C92366F302523FD5C0031FA1B31 ___1_result, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t* V_0 = NULL;
	int32_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_data;
		NullCheck(L_0);
		uint8_t* L_1 = L_0->___buckets;
		V_0 = (int32_t*)L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		uint8_t* L_3 = L_2->___next;
		V_1 = (int32_t*)L_3;
		V_2 = 0;
		V_3 = 0;
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&___1_result))->___m_Length);
		V_4 = L_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		V_5 = L_6;
		goto IL_005c;
	}

IL_0025:
	{
		int32_t* L_7 = V_0;
		int32_t L_8 = V_2;
		intptr_t L_9 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_8,NULL));
		int32_t L_10 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(L_9, 4)))));
		V_6 = L_10;
		goto IL_0053;
	}

IL_0030:
	{
		int32_t L_11 = V_3;
		int32_t L_12 = L_11;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_13 = ___0_data;
		NullCheck(L_13);
		uint8_t* L_14 = L_13->___values;
		int32_t L_15 = V_6;
		UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 L_16;
		L_16 = UnsafeUtility_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m6C484995D5C95208A4EB1F0C7664EC42A74DE670_inline((void*)L_14, L_15, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750, ((&___1_result))->___m_Buffer, L_12, (L_16));
		int32_t* L_17 = V_1;
		int32_t L_18 = V_6;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_18,NULL));
		int32_t L_20 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_17, ((intptr_t)il2cpp_codegen_multiply(L_19, 4)))));
		V_6 = L_20;
	}

IL_0053:
	{
		int32_t L_21 = V_6;
		if ((!(((uint32_t)L_21) == ((uint32_t)(-1)))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_22 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_22, 1));
	}

IL_005c:
	{
		int32_t L_23 = V_2;
		int32_t L_24 = V_5;
		if ((((int32_t)L_23) > ((int32_t)L_24)))
		{
			goto IL_0066;
		}
	}
	{
		int32_t L_25 = V_3;
		int32_t L_26 = V_4;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0025;
		}
	}

IL_0066:
	{
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3998D4C65643516D842CF6D61C4513767A18FA63 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEA2D219466CA70D0772888D0B2AA5BDF95B3D7B0(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(int32_t);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_mFD7DBC1199616005466125347027F6201459B40D_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = DrawKey_GetHashCode_m6E3C5F3D42D02D8035AA7E7B5501FDBC1551F4E5((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m74E8AA99C7F975CBC9B07E2EE5507D607611E849 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m1889622A4F9D451311D704800071C27E203E30FD(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(bool);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m48E5FF5F41637E261FFDB6EF3154FC85F0211D58 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m53A432E510AFC1B5E17AC7D4CEA9BDC969EF4183(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mF394020DE5FEF55FD41D472FCFEDFB94EC21E18C (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mBBBCD7A3795516F652E2A209921D9F365FEF117D(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m60D8A6A4D2FC5E25CD0C3229AD6E6B568C384C32 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_mFCFCB281237C3FD181B82326F1CDC74ECDC26835(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m8CA3249E613156F5440F57EDC2841CC44B9CF479 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m28DB190FC25AC6811E2F609C118B25148772E8ED(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(int32_t);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m42E7D99D8EBAEBF3BAD092684E6EEAB4AD41B10D (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m97E2EBA7DBA4EC678CB7F7D5A1E14B2687937D9B(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m8CBF4C11500731B2BA768362607ED8B5FCE9B520 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_mEE7449D53E0B0DF2588A7ABF7DE9C12E23AEC194(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = EntityId_GetHashCode_m7B7BE3CC221C5EEAB3D2E64BD632F057E7931410((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m53F008BF155FA3071AA803295CD52B877FA97301 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_StaticInit);
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m5EF0E0217EB20D03E739EF4F21BA8ED27454FBA1(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		CHECKED_LOCAL_INIT(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_StaticInit,(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_82;
		L_82 = GPUArchetypeHandle_GetHashCode_mF816A596DEE9C2CA813E280D5DB3FE046085480C((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m7D4B76EEA56BC2D0A4E69040ECAC2BFF29F6239B (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_StaticInit);
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m11C03B89A0BC9969D9C5F48944DA915764AB7653(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		CHECKED_LOCAL_INIT(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_StaticInit,(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_82;
		L_82 = GPUArchetypeHandle_GetHashCode_mF816A596DEE9C2CA813E280D5DB3FE046085480C((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_mB62CB55609C38163B91BEF995A2D6AAE252DB5D0 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_StaticInit);
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m1039B6A2212089AF73B18D7545E9DC3D3DF22E44(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		CHECKED_LOCAL_INIT(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_StaticInit,(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_82;
		L_82 = GPUComponentSet_GetHashCode_mD21ED0964434E73545827D58153D059227B51B21((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m91576454D66AE28099F50FBEE92EBBB84FC659AF (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m4AC175F5FE1C77C9A2E7602A09E229A5CF617FAF(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(int32_t);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		int32_t L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_mED51823316D888F4C0BBD35347050157D421DF94 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m7CF1071B4128F92A069498179CE85F80CB5AEBE1(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(int32_t);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		int32_t L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m3DEC8FE0C45757F13739FD01205D6A4138E8E9CD (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C V_15;
	memset((&V_15), 0, sizeof(V_15));
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m47E7EA1FA34E44C4B7E215FA109EFC5813E93948(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(int32_t);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mFDF2C4591B5F4C0AF4424ED681225F9CF100C5BB_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = RangeKey_GetHashCode_mC38845B6A1CC657D6F6B1149E7448AA6A3EF3257((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_mBD7A8412C7ED558BD4891BE34D5D811409097B84 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	uint32_t V_15 = 0;
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m84BBCADD738D8E17724D100724F1173F24CC9D46(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(uint32_t);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		uint32_t L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED337C060A7869E7A836D5F3C6671B9500396F53 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	uint32_t V_15 = 0;
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = UnsafeParallelHashMapData_CalculateDataSize_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m92740FC50E0692378ABED6D572FE0AA5FFF18DFB(L_9, L_10, (&V_0), (&V_1), (&V_2), NULL);
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = sizeof(int32_t);
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = sizeof(uint32_t);
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		uint32_t L_81;
		L_81 = UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline((void*)L_79, L_80, NULL);
		V_15 = L_81;
		int32_t L_82;
		L_82 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC((&V_15), NULL);
		int32_t L_83 = V_7;
		V_14 = ((int32_t)(L_82&L_83));
		int32_t* L_84 = V_12;
		int32_t L_85 = V_13;
		intptr_t L_86 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_85,NULL));
		uint8_t* L_87 = V_6;
		int32_t L_88 = V_14;
		intptr_t L_89 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_88,NULL));
		int32_t L_90 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_87, ((intptr_t)il2cpp_codegen_multiply(L_89, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_84, ((intptr_t)il2cpp_codegen_multiply(L_86, 4))))) = L_90;
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4)))))) = L_94;
	}

IL_0143:
	{
		int32_t* L_95 = V_11;
		int32_t L_96 = V_10;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))));
		if ((((int32_t)L_98) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_99 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_99, 1));
	}

IL_0155:
	{
		int32_t L_100 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_101 = ___0_data;
		NullCheck(L_101);
		int32_t L_102 = L_101->___bucketCapacityMask;
		if ((((int32_t)L_100) <= ((int32_t)L_102)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_103 = ___0_data;
		NullCheck(L_103);
		uint8_t* L_104 = L_103->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_105 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_104, L_105, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_106 = ___0_data;
		NullCheck(L_106);
		int32_t L_107 = L_106->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_108 = ___0_data;
		NullCheck(L_108);
		int32_t L_109 = L_108->___keyCapacity;
		if ((((int32_t)L_107) <= ((int32_t)L_109)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_111 = ___0_data;
		NullCheck(L_111);
		int32_t L_112 = L_111->___keyCapacity;
		NullCheck(L_110);
		L_110->___allocatedIndexLength = L_112;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_113 = ___0_data;
		uint8_t* L_114 = V_3;
		NullCheck(L_113);
		L_113->___values = L_114;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		uint8_t* L_116 = V_4;
		NullCheck(L_115);
		L_115->___keys = L_116;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_5;
		NullCheck(L_117);
		L_117->___next = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_6;
		NullCheck(L_119);
		L_119->___buckets = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		int32_t L_122 = ___1_newCapacity;
		NullCheck(L_121);
		L_121->___keyCapacity = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		int32_t L_124 = V_7;
		NullCheck(L_123);
		L_123->___bucketCapacityMask = L_124;
		return;
	}
}
// Method Definition Index: 66035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapData_ReallocateHashMap_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_mD75A84E690BE573D5B2F40EF59DFD1AC4703BFED_fshared (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_data, int32_t ___1_newCapacity, int64_t ___2_newBucketCapacity, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_label, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_TKey_t5C6CF5C92FA36F580A298FBAD5C0C26409B948E2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 2));
	const uint32_t SizeOf_TValue_tC69328621FD17954468B8EF13B10C5DE9B45FA92 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	void* L_82 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 2)));
	const Il2CppFullySharedGenericStruct L_81 = alloca(SizeOf_TKey_t5C6CF5C92FA36F580A298FBAD5C0C26409B948E2);
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	int64_t V_2 = 0;
	uint8_t* V_3 = NULL;
	uint8_t* V_4 = NULL;
	uint8_t* V_5 = NULL;
	uint8_t* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t* V_11 = NULL;
	int32_t* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	Il2CppFullySharedGenericStruct V_15 = alloca(SizeOf_TKey_t5C6CF5C92FA36F580A298FBAD5C0C26409B948E2);
	memset(V_15, 0, SizeOf_TKey_t5C6CF5C92FA36F580A298FBAD5C0C26409B948E2);
	{
		int64_t L_0 = ___2_newBucketCapacity;
		int64_t L_1;
		L_1 = math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline(L_0, NULL);
		___2_newBucketCapacity = L_1;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_data;
		NullCheck(L_2);
		int32_t L_3 = L_2->___keyCapacity;
		int32_t L_4 = ___1_newCapacity;
		if ((!(((uint32_t)L_3) == ((uint32_t)L_4))))
		{
			goto IL_001e;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_5 = ___0_data;
		NullCheck(L_5);
		int32_t L_6 = L_5->___bucketCapacityMask;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_6, 1)),NULL));
		int64_t L_8 = ___2_newBucketCapacity;
		if ((!(((uint64_t)L_7) == ((uint64_t)L_8))))
		{
			goto IL_001e;
		}
	}
	{
		return;
	}

IL_001e:
	{
		int32_t L_9 = ___1_newCapacity;
		int64_t L_10 = ___2_newBucketCapacity;
		int64_t L_11;
		L_11 = ((  int64_t (*) (int32_t, int64_t, int64_t*, int64_t*, int64_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_9, L_10, (&V_0), (&V_1), (&V_2), il2cpp_rgctx_method(method->rgctx_data, 0));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_12 = ___3_label;
		void* L_13;
		L_13 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_11, ((int32_t)64), L_12, NULL);
		V_3 = (uint8_t*)L_13;
		uint8_t* L_14 = V_3;
		int64_t L_15 = V_0;
		intptr_t L_16 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_15,NULL));
		V_4 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_14, L_16));
		uint8_t* L_17 = V_3;
		int64_t L_18 = V_1;
		intptr_t L_19 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_18,NULL));
		V_5 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_17, L_19));
		uint8_t* L_20 = V_3;
		int64_t L_21 = V_2;
		intptr_t L_22 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(L_21,NULL));
		V_6 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_20, L_22));
		uint8_t* L_23 = V_3;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_24 = ___0_data;
		NullCheck(L_24);
		uint8_t* L_25 = L_24->___values;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_26 = ___0_data;
		NullCheck(L_26);
		int32_t L_27 = L_26->___keyCapacity;
		int64_t L_28 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_27,NULL));
		uint32_t L_29 = SizeOf_TValue_tC69328621FD17954468B8EF13B10C5DE9B45FA92;
		int64_t L_30 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_29,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_23, (void*)L_25, ((int64_t)il2cpp_codegen_multiply(L_28, L_30)), NULL);
		uint8_t* L_31 = V_4;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_32 = ___0_data;
		NullCheck(L_32);
		uint8_t* L_33 = L_32->___keys;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_34 = ___0_data;
		NullCheck(L_34);
		int32_t L_35 = L_34->___keyCapacity;
		int64_t L_36 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_35,NULL));
		uint32_t L_37 = SizeOf_TKey_t5C6CF5C92FA36F580A298FBAD5C0C26409B948E2;
		int64_t L_38 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_37,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_31, (void*)L_33, ((int64_t)il2cpp_codegen_multiply(L_36, L_38)), NULL);
		uint8_t* L_39 = V_5;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_40 = ___0_data;
		NullCheck(L_40);
		uint8_t* L_41 = L_40->___next;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_42 = ___0_data;
		NullCheck(L_42);
		int32_t L_43 = L_42->___keyCapacity;
		int64_t L_44 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_43,NULL));
		int64_t L_45 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(4,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_39, (void*)L_41, ((int64_t)il2cpp_codegen_multiply(L_44, L_45)), NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_46 = ___0_data;
		NullCheck(L_46);
		int32_t L_47 = L_46->___keyCapacity;
		V_8 = L_47;
		goto IL_00ae;
	}

IL_009e:
	{
		uint8_t* L_48 = V_5;
		int32_t L_49 = V_8;
		intptr_t L_50 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_49,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_48, ((intptr_t)il2cpp_codegen_multiply(L_50, 4)))))) = (-1);
		int32_t L_51 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_00ae:
	{
		int32_t L_52 = V_8;
		int32_t L_53 = ___1_newCapacity;
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_009e;
		}
	}
	{
		V_9 = 0;
		goto IL_00c8;
	}

IL_00b8:
	{
		uint8_t* L_54 = V_6;
		int32_t L_55 = V_9;
		intptr_t L_56 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_55,NULL));
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_54, ((intptr_t)il2cpp_codegen_multiply(L_56, 4)))))) = (-1);
		int32_t L_57 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00c8:
	{
		int32_t L_58 = V_9;
		int64_t L_59 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_58,NULL));
		int64_t L_60 = ___2_newBucketCapacity;
		if ((((int64_t)L_59) < ((int64_t)L_60)))
		{
			goto IL_00b8;
		}
	}
	{
		int64_t L_61 = ___2_newBucketCapacity;
		int64_t L_62 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int32_t L_63 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_subtract(L_61, L_62)),NULL));
		V_7 = L_63;
		V_10 = 0;
		goto IL_0155;
	}

IL_00da:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_64 = ___0_data;
		NullCheck(L_64);
		uint8_t* L_65 = L_64->___buckets;
		V_11 = (int32_t*)L_65;
		uint8_t* L_66 = V_5;
		V_12 = (int32_t*)L_66;
		goto IL_0143;
	}

IL_00e8:
	{
		int32_t* L_67 = V_11;
		int32_t L_68 = V_10;
		intptr_t L_69 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_68,NULL));
		int32_t L_70 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_67, ((intptr_t)il2cpp_codegen_multiply(L_69, 4)))));
		V_13 = L_70;
		int32_t* L_71 = V_11;
		int32_t L_72 = V_10;
		intptr_t L_73 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_72,NULL));
		int32_t* L_74 = V_12;
		int32_t L_75 = V_13;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		int32_t L_77 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_71, ((intptr_t)il2cpp_codegen_multiply(L_73, 4))))) = L_77;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_78 = ___0_data;
		NullCheck(L_78);
		uint8_t* L_79 = L_78->___keys;
		int32_t L_80 = V_13;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), NULL, (void*)L_79, L_80, (Il2CppFullySharedGenericStruct*)L_81);
		il2cpp_codegen_memcpy(V_15, L_81, SizeOf_TKey_t5C6CF5C92FA36F580A298FBAD5C0C26409B948E2);
		Il2CppConstrainedCallData L_83;
		Il2CppMethodPointer L_84 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(method->rgctx_data, 2), il2cpp_rgctx_method(method->rgctx_data, 4), (void*)(Il2CppFullySharedGenericStruct*)V_15, &L_83, L_82);
		typedef int32_t ( *func_L_85)(void*,const RuntimeMethod*);
		int32_t L_86 = ((func_L_85)L_84)(L_83.thisPtr,L_83.method);
		int32_t L_87 = V_7;
		V_14 = ((int32_t)(L_86&L_87));
		int32_t* L_88 = V_12;
		int32_t L_89 = V_13;
		intptr_t L_90 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_89,NULL));
		uint8_t* L_91 = V_6;
		int32_t L_92 = V_14;
		intptr_t L_93 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_92,NULL));
		int32_t L_94 = *(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_91, ((intptr_t)il2cpp_codegen_multiply(L_93, 4))))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_88, ((intptr_t)il2cpp_codegen_multiply(L_90, 4))))) = L_94;
		uint8_t* L_95 = V_6;
		int32_t L_96 = V_14;
		intptr_t L_97 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_96,NULL));
		int32_t L_98 = V_13;
		*(((int32_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_95, ((intptr_t)il2cpp_codegen_multiply(L_97, 4)))))) = L_98;
	}

IL_0143:
	{
		int32_t* L_99 = V_11;
		int32_t L_100 = V_10;
		intptr_t L_101 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_100,NULL));
		int32_t L_102 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_99, ((intptr_t)il2cpp_codegen_multiply(L_101, 4)))));
		if ((((int32_t)L_102) >= ((int32_t)0)))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_103 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_103, 1));
	}

IL_0155:
	{
		int32_t L_104 = V_10;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_105 = ___0_data;
		NullCheck(L_105);
		int32_t L_106 = L_105->___bucketCapacityMask;
		if ((((int32_t)L_104) <= ((int32_t)L_106)))
		{
			goto IL_00da;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_107 = ___0_data;
		NullCheck(L_107);
		uint8_t* L_108 = L_107->___values;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_109 = ___3_label;
		Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271(L_108, L_109, NULL);
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_110 = ___0_data;
		NullCheck(L_110);
		int32_t L_111 = L_110->___allocatedIndexLength;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_112 = ___0_data;
		NullCheck(L_112);
		int32_t L_113 = L_112->___keyCapacity;
		if ((((int32_t)L_111) <= ((int32_t)L_113)))
		{
			goto IL_0188;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_114 = ___0_data;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_115 = ___0_data;
		NullCheck(L_115);
		int32_t L_116 = L_115->___keyCapacity;
		NullCheck(L_114);
		L_114->___allocatedIndexLength = L_116;
	}

IL_0188:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_117 = ___0_data;
		uint8_t* L_118 = V_3;
		NullCheck(L_117);
		L_117->___values = L_118;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_119 = ___0_data;
		uint8_t* L_120 = V_4;
		NullCheck(L_119);
		L_119->___keys = L_120;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_121 = ___0_data;
		uint8_t* L_122 = V_5;
		NullCheck(L_121);
		L_121->___next = L_122;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_123 = ___0_data;
		uint8_t* L_124 = V_6;
		NullCheck(L_123);
		L_123->___buckets = L_124;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_125 = ___0_data;
		int32_t L_126 = ___1_newCapacity;
		NullCheck(L_125);
		L_125->___keyCapacity = L_126;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_127 = ___0_data;
		int32_t L_128 = V_7;
		NullCheck(L_127);
		L_127->___bucketCapacityMask = L_128;
		return;
	}
}
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
// Method Definition Index: 66073
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyValue_2_t6CF850BB70347624D35C74018B4BBBAE4CED68AB UnsafeParallelHashMapDataEnumerator_GetCurrent_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_mF329629AC81460B256D980C6CB8DD9E758F034A3_fshared (UnsafeParallelHashMapDataEnumerator_t8CD0B557DE7804D4ED6A5599D87CC889C2DDA4F5* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	KeyValue_2_t6CF850BB70347624D35C74018B4BBBAE4CED68AB V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(KeyValue_2_t6CF850BB70347624D35C74018B4BBBAE4CED68AB));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = __this->___m_Buffer;
		(&V_0)->___m_Buffer = L_0;
		int32_t L_1 = __this->___m_Index;
		(&V_0)->___m_Index = L_1;
		KeyValue_2_t6CF850BB70347624D35C74018B4BBBAE4CED68AB L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 66074
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeParallelHashMapDataEnumerator_GetCurrentKey_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCEB8FADDFFDFCED9D937E3C7AA23AD82227AC10C (UnsafeParallelHashMapDataEnumerator_t8CD0B557DE7804D4ED6A5599D87CC889C2DDA4F5* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->___m_Index;
		if ((((int32_t)L_0) == ((int32_t)(-1))))
		{
			goto IL_0020;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_1 = __this->___m_Buffer;
		NullCheck(L_1);
		uint8_t* L_2 = L_1->___keys;
		int32_t L_3 = __this->___m_Index;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_4;
		L_4 = UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline((void*)L_2, L_3, NULL);
		return L_4;
	}

IL_0020:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8));
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_5 = V_0;
		return L_5;
	}
}
// Method Definition Index: 66074
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeParallelHashMapDataEnumerator_GetCurrentKey_TisIl2CppFullySharedGenericStruct_mCFE6E3FA9A491B1CB54FF3EA51EF2A853ABB2533_fshared (UnsafeParallelHashMapDataEnumerator_t8CD0B557DE7804D4ED6A5599D87CC889C2DDA4F5* __this, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF);
	const Il2CppFullySharedGenericStruct L_5 = L_4;
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericStruct V_0 = alloca(SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF);
	memset(V_0, 0, SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF);
	{
		int32_t L_0 = __this->___m_Index;
		if ((((int32_t)L_0) == ((int32_t)(-1))))
		{
			goto IL_0020;
		}
	}
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_1 = __this->___m_Buffer;
		NullCheck(L_1);
		uint8_t* L_2 = L_1->___keys;
		int32_t L_3 = __this->___m_Index;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)), il2cpp_rgctx_method(method->rgctx_data, 0), NULL, (void*)L_2, L_3, (Il2CppFullySharedGenericStruct*)L_4);
		il2cpp_codegen_memcpy(il2cppRetVal, L_4, SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF);
		return;
	}

IL_0020:
	{
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_0, SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF);
		il2cpp_codegen_memcpy(L_5, V_0, SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF);
		il2cpp_codegen_memcpy(il2cppRetVal, L_5, SizeOf_TKey_tDBBD3695D659ACD8F0553908105525ACBBC2CAFF);
		return;
	}
}
// Method Definition Index: 66026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613* UnsafePtrListExtensions_ListData_TisIl2CppFullySharedGenericStruct_mFF9507AE135715955F3CF4DD075A2CDFC5BC6B0C_fshared (UnsafePtrList_1_tA37C18AF110F20C6437047DBA50BF355602044E5* ___0_from, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		UnsafePtrList_1_tA37C18AF110F20C6437047DBA50BF355602044E5* L_0 = ___0_from;
		UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613* L_1;
		L_1 = ((  UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613* (*) (UnsafePtrList_1_tA37C18AF110F20C6437047DBA50BF355602044E5*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_1;
	}
}
// Method Definition Index: 66027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 UnsafePtrListExtensions_ListDataRO_TisIl2CppFullySharedGenericStruct_mFF9DAC69E1BEF0AFC23A8917EC38C644F4873B88_fshared (UnsafePtrList_1_tA37C18AF110F20C6437047DBA50BF355602044E5 ___0_from, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	//<source_info:<no-source>:1>
	{
		UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613* L_0;
		L_0 = ((  UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613* (*) (UnsafePtrList_1_tA37C18AF110F20C6437047DBA50BF355602044E5*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&___0_from), il2cpp_rgctx_method(method->rgctx_data, 0));
		UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 L_1 = (*(UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613*)L_0);
		return L_1;
	}
}
// Method Definition Index: 65534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeQueueData_AllocateQueue_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m06786DD20006041E83D7A1F52C68944684D0CFDF (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** ___1_outBuf, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* V_2 = NULL;
	int32_t V_3 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline(NULL);
		int32_t L_2;
		L_2 = CollectionHelper_Align_m0F9A1D60694634D775C811136208ED02D7665F2F(L_1, ((int32_t)64), NULL);
		V_1 = L_2;
		int32_t L_3 = V_1;
		int32_t L_4 = V_0;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_3, ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_4)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_6 = ___0_allocator;
		void* L_7;
		L_7 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_5, ((int32_t)64), L_6, NULL);
		V_2 = (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_7;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_8 = V_2;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_9 = V_2;
		int32_t L_10 = V_1;
		NullCheck(L_8);
		L_8->___m_CurrentWriteBlockTLS = (uint8_t*)((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)il2cpp_codegen_add((intptr_t)L_9, L_10));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_11 = V_2;
		NullCheck(L_11);
		L_11->___m_FirstBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_12 = V_2;
		NullCheck(L_12);
		L_12->___m_LastBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_13 = V_2;
		int32_t L_14;
		L_14 = UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline(NULL);
		uint32_t L_15 = sizeof(int32_t);
		NullCheck(L_13);
		L_13->___m_MaxItems = ((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)16384), L_14))/(int32_t)L_15));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_16 = V_2;
		NullCheck(L_16);
		L_16->___m_CurrentRead = 0;
		V_3 = 0;
		goto IL_0072;
	}

IL_0065:
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_17 = V_2;
		int32_t L_18 = V_3;
		uintptr_t L_19 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		UnsafeQueueData_SetCurrentWriteBlockTLS_mE8BF637642E13044DFF8A34A55B8AE0B33A5F727_inline((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_17, L_18, (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)L_19, NULL);
		int32_t L_20 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0072:
	{
		int32_t L_21 = V_3;
		int32_t L_22 = V_0;
		if ((((int32_t)L_21) < ((int32_t)L_22)))
		{
			goto IL_0065;
		}
	}
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** L_23 = ___1_outBuf;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_24 = V_2;
		*(((intptr_t*)L_23)) = ((intptr_t)L_24);
		return;
	}
}
// Method Definition Index: 65534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeQueueData_AllocateQueue_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mB0416B43674E7A2FC704E79BFAEB1E53E5E3A492 (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** ___1_outBuf, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* V_2 = NULL;
	int32_t V_3 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline(NULL);
		int32_t L_2;
		L_2 = CollectionHelper_Align_m0F9A1D60694634D775C811136208ED02D7665F2F(L_1, ((int32_t)64), NULL);
		V_1 = L_2;
		int32_t L_3 = V_1;
		int32_t L_4 = V_0;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_3, ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_4)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_6 = ___0_allocator;
		void* L_7;
		L_7 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_5, ((int32_t)64), L_6, NULL);
		V_2 = (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_7;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_8 = V_2;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_9 = V_2;
		int32_t L_10 = V_1;
		NullCheck(L_8);
		L_8->___m_CurrentWriteBlockTLS = (uint8_t*)((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)il2cpp_codegen_add((intptr_t)L_9, L_10));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_11 = V_2;
		NullCheck(L_11);
		L_11->___m_FirstBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_12 = V_2;
		NullCheck(L_12);
		L_12->___m_LastBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_13 = V_2;
		int32_t L_14;
		L_14 = UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline(NULL);
		uint32_t L_15 = sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08);
		NullCheck(L_13);
		L_13->___m_MaxItems = ((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)16384), L_14))/(int32_t)L_15));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_16 = V_2;
		NullCheck(L_16);
		L_16->___m_CurrentRead = 0;
		V_3 = 0;
		goto IL_0072;
	}

IL_0065:
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_17 = V_2;
		int32_t L_18 = V_3;
		uintptr_t L_19 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		UnsafeQueueData_SetCurrentWriteBlockTLS_mE8BF637642E13044DFF8A34A55B8AE0B33A5F727_inline((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_17, L_18, (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)L_19, NULL);
		int32_t L_20 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0072:
	{
		int32_t L_21 = V_3;
		int32_t L_22 = V_0;
		if ((((int32_t)L_21) < ((int32_t)L_22)))
		{
			goto IL_0065;
		}
	}
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** L_23 = ___1_outBuf;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_24 = V_2;
		*(((intptr_t*)L_23)) = ((intptr_t)L_24);
		return;
	}
}
// Method Definition Index: 65534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeQueueData_AllocateQueue_TisIl2CppFullySharedGenericStruct_mF5F2F17F56ED0720581E604C4A49821E2BB67353_fshared (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** ___1_outBuf, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t1DBA8EB390B8E400F799289005C416BE1ABCE55B = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* V_2 = NULL;
	int32_t V_3 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline(NULL);
		int32_t L_2;
		L_2 = CollectionHelper_Align_m0F9A1D60694634D775C811136208ED02D7665F2F(L_1, ((int32_t)64), NULL);
		V_1 = L_2;
		int32_t L_3 = V_1;
		int32_t L_4 = V_0;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_3, ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_4)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_6 = ___0_allocator;
		void* L_7;
		L_7 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_5, ((int32_t)64), L_6, NULL);
		V_2 = (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_7;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_8 = V_2;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_9 = V_2;
		int32_t L_10 = V_1;
		NullCheck(L_8);
		L_8->___m_CurrentWriteBlockTLS = (uint8_t*)((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)il2cpp_codegen_add((intptr_t)L_9, L_10));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_11 = V_2;
		NullCheck(L_11);
		L_11->___m_FirstBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_12 = V_2;
		NullCheck(L_12);
		L_12->___m_LastBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_13 = V_2;
		int32_t L_14;
		L_14 = UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline(NULL);
		uint32_t L_15 = SizeOf_T_t1DBA8EB390B8E400F799289005C416BE1ABCE55B;
		NullCheck(L_13);
		L_13->___m_MaxItems = ((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)16384), L_14))/(int32_t)L_15));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_16 = V_2;
		NullCheck(L_16);
		L_16->___m_CurrentRead = 0;
		V_3 = 0;
		goto IL_0072;
	}

IL_0065:
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_17 = V_2;
		int32_t L_18 = V_3;
		uintptr_t L_19 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		UnsafeQueueData_SetCurrentWriteBlockTLS_mE8BF637642E13044DFF8A34A55B8AE0B33A5F727_inline((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_17, L_18, (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)L_19, NULL);
		int32_t L_20 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0072:
	{
		int32_t L_21 = V_3;
		int32_t L_22 = V_0;
		if ((((int32_t)L_21) < ((int32_t)L_22)))
		{
			goto IL_0065;
		}
	}
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** L_23 = ___1_outBuf;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_24 = V_2;
		*(((intptr_t*)L_23)) = ((intptr_t)L_24);
		return;
	}
}
// Method Definition Index: 65534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeQueueData_AllocateQueue_TisRequest_tAA55F47806E39B0E19B53273DCBFB5CF457F9187_mABB266FBB4A19CA28EB80D50DA7FC13E97D63585 (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** ___1_outBuf, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* V_2 = NULL;
	int32_t V_3 = 0;
	{
		int32_t L_0;
		L_0 = JobsUtility_get_ThreadIndexCount_m88A954344398143540618B35943F863B92465676(NULL);
		V_0 = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline(NULL);
		int32_t L_2;
		L_2 = CollectionHelper_Align_m0F9A1D60694634D775C811136208ED02D7665F2F(L_1, ((int32_t)64), NULL);
		V_1 = L_2;
		int32_t L_3 = V_1;
		int32_t L_4 = V_0;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(((int32_t)il2cpp_codegen_add(L_3, ((int32_t)il2cpp_codegen_multiply(((int32_t)64), L_4)))),NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_6 = ___0_allocator;
		void* L_7;
		L_7 = Unmanaged_Allocate_m7310B1FE896DEFFA18303D961C9859C8FF3D21E5(L_5, ((int32_t)64), L_6, NULL);
		V_2 = (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_7;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_8 = V_2;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_9 = V_2;
		int32_t L_10 = V_1;
		NullCheck(L_8);
		L_8->___m_CurrentWriteBlockTLS = (uint8_t*)((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)il2cpp_codegen_add((intptr_t)L_9, L_10));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_11 = V_2;
		NullCheck(L_11);
		L_11->___m_FirstBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_12 = V_2;
		NullCheck(L_12);
		L_12->___m_LastBlock = 0;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_13 = V_2;
		int32_t L_14;
		L_14 = UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline(NULL);
		uint32_t L_15 = sizeof(Request_tAA55F47806E39B0E19B53273DCBFB5CF457F9187);
		NullCheck(L_13);
		L_13->___m_MaxItems = ((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)16384), L_14))/(int32_t)L_15));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_16 = V_2;
		NullCheck(L_16);
		L_16->___m_CurrentRead = 0;
		V_3 = 0;
		goto IL_0072;
	}

IL_0065:
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_17 = V_2;
		int32_t L_18 = V_3;
		uintptr_t L_19 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		UnsafeQueueData_SetCurrentWriteBlockTLS_mE8BF637642E13044DFF8A34A55B8AE0B33A5F727_inline((UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_17, L_18, (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)L_19, NULL);
		int32_t L_20 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0072:
	{
		int32_t L_21 = V_3;
		int32_t L_22 = V_0;
		if ((((int32_t)L_21) < ((int32_t)L_22)))
		{
			goto IL_0065;
		}
	}
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2** L_23 = ___1_outBuf;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_24 = V_2;
		*(((intptr_t*)L_23)) = ((intptr_t)L_24);
		return;
	}
}
// Method Definition Index: 65533
// Method Definition Index: 65533
// Method Definition Index: 43302
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_volumeDepth_mEF9610D1C14182417A01B7243DEE6B559A13B34D_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->___U3CvolumeDepthU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 43299
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RenderTextureDescriptor_get_msaaSamples_mFCC33643AFF2265C8305DCFD79ED8774A1A8FA22_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___U3CmsaaSamplesU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 43300
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_msaaSamples_m6910E09489372746391B14FBAF59A7237539D6C4_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->___U3CmsaaSamplesU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 43317
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_dimension_mCE9A4A08454BB2D9DFE3E505EC336FD480078F39_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->___U3CdimensionU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 43296
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_width_m3B2494007BFE3AD4D14403407C9B24F5045E7E10_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->___U3CwidthU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 43298
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RenderTextureDescriptor_set_height_m1FE41111472DAA9B5E80FFAF3445004D72A3CFA5_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->___U3CheightU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 43295
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RenderTextureDescriptor_get_width_mB159E4EB08B23B19CCCFADB465864361FB840BFF_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___U3CwidthU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 43685
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Mathf_Max_m7FA442918DE37E3A00106D1F2E789D65829792B8_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) > ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_b;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_a;
		return L_3;
	}
}
// Method Definition Index: 43297
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RenderTextureDescriptor_get_height_m1006F9AA45029715C552C8A8C2F102F63D3A91EC_inline (RenderTextureDescriptor_t69845881CE6437E4E61F92074F2F84079F23FA46* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___U3CheightU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 93864
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t math_ceilpow2_m8691C3C194B41660E1FB2E694F7D209BE60DDCC7_inline (int64_t ___0_x, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int64_t L_0 = ___0_x;
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		___0_x = ((int64_t)il2cpp_codegen_subtract(L_0, L_1));
		int64_t L_2 = ___0_x;
		int64_t L_3 = ___0_x;
		___0_x = ((int64_t)(L_2|((int64_t)(L_3>>1))));
		int64_t L_4 = ___0_x;
		int64_t L_5 = ___0_x;
		___0_x = ((int64_t)(L_4|((int64_t)(L_5>>2))));
		int64_t L_6 = ___0_x;
		int64_t L_7 = ___0_x;
		___0_x = ((int64_t)(L_6|((int64_t)(L_7>>4))));
		int64_t L_8 = ___0_x;
		int64_t L_9 = ___0_x;
		___0_x = ((int64_t)(L_8|((int64_t)(L_9>>8))));
		int64_t L_10 = ___0_x;
		int64_t L_11 = ___0_x;
		___0_x = ((int64_t)(L_10|((int64_t)(L_11>>((int32_t)16)))));
		int64_t L_12 = ___0_x;
		int64_t L_13 = ___0_x;
		___0_x = ((int64_t)(L_12|((int64_t)(L_13>>((int32_t)32)))));
		int64_t L_14 = ___0_x;
		int64_t L_15 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		return ((int64_t)il2cpp_codegen_add(L_14, L_15));
	}
}
// Method Definition Index: 65532
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeQueueData_SetCurrentWriteBlockTLS_mE8BF637642E13044DFF8A34A55B8AE0B33A5F727_inline (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* __this, int32_t ___0_threadIndex, UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___1_currentWriteBlock, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C** V_0 = NULL;
	{
		uint8_t* L_0 = __this->___m_CurrentWriteBlockTLS;
		int32_t L_1 = ___0_threadIndex;
		uintptr_t L_2 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(((uint8_t*)il2cpp_codegen_add((intptr_t)L_0, ((int32_t)il2cpp_codegen_multiply(L_1, ((int32_t)64))))),NULL));
		V_0 = (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C**)L_2;
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C** L_3 = V_0;
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_4 = ___1_currentWriteBlock;
		*(((intptr_t*)L_3)) = ((intptr_t)L_4);
		return;
	}
}
// Method Definition Index: 11444
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
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mE09F2B19DAC75EB997515A1B25AB0AF59AA37EDA_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m312FD1D94C51FFE92899836D9F020617D431BBF5_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m04DD2C89F805D820CAFA67B72D8261E1D52A75AA_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mDEDCEBAF0C62FDCD22EA85CBDDBAFADD5CCB7915_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m6AD907969ED820C7B597DBDE5A62251F0BAAEBB5_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m2B47DA4F1DF05E028EEA414B4BC8C82E8FCF4481_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m581D10C30FE27399A9EDCCBB6EE26A6D79E5477E_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_mA5EE4C645904072BD057D41FC7D1AABAB3B4E398_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8E2B97AA6AB1779936EAA4893F7CE096024BCE54_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m77A7D05474DF60C828E063E75D6A6C52B0BB8A0A_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m8291A5EAB6935532A5B3B16082E9709D3B425582_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m61E51176F8D18A3C2FC21CECC8908B35B9DB5F3D_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m6BD3023222CB03E8462517B9F40193D9A085A1C2_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mFF371C2E5F2018BDF838A2BBC5AC30EA7C74230E_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_m8D4E16E3691F9835E03B880A9BE1B0F7A25F955B_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mF8CB5ED1AEDA173F1F15E75017828AA38AE9E6EA_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_mF86E7726D232D0C06A598629B29651A120967D95_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m851FFDFB05C6D16BC27B3BAD2B486229B48796FB_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m38864F218C1121BECFC7EFB1DB548BD52F5E77D1_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m67C30665BD5F032BA4790CB4F198C5128D65FA1B_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m257333772E743A0BFC11C2B733B8727A1379AC5D_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m952393E8A8C420CA0DEAB80F495FF991803AE4CD_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_mA0454C21C3291C32B45B2566A9D88C11C570AAB7_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m86AC2282B14EEB2988DF554898FE8D12B6968652_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m7FE14B8744B411EBACDA2B154025806F5CAB4659_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m501662FEF1C371DA264F4A8F86497DD85C6576C8_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m5586B4329861CC2D97E47E8ABBFB93BE29C41858_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m36CB3A618AC04CD0E869A5C34BAE8DBFDEA34119_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m2C9EAB7C411248886CA8ADE580C3232DCE0942B8_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m3BF032FF33CB8E4BAD8B53BCB58362D59F473562_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_mCB89996F323B06C4C16FFD580A8744DCF6E0EAE0_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m7936CCEA1FD37B0D005189C07C3FAAC4E016B792_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 11433
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 2419
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ReadOnlySpan_1_get_Length_m4430960CA0D0458B1A1106DD246CA9AB746B5DB2_fshared_inline (ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
// Method Definition Index: 903
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11 Func_2_Invoke_mC82AB28A182689A25D4F657E20FC5A764642A915_inline (Func_2_t0F26B920A10A91BFA7B07637902B13D306D6ACB2* __this, FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef UnmanagedFilterFunction_t46D1C73262CD8245474DBC2CA5878C80E08A1B11 (*FunctionPointerType) (RuntimeObject*, FilterFunction_t32E0707BD9D9F770A2A7578985A5C163FC1AAEFF, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 903
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75 Func_2_Invoke_m63E17BE9D669582B8D83B161B938EF4F5E866748_inline (Func_2_t9622A5472E3EB564FD9AA65F9666F983FA8CA079* __this, MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef UnmanagedMaterialPropertyValue_t32418EF3A65B66312EE3D81C88513C1116711B75 (*FunctionPointerType) (RuntimeObject*, MaterialPropertyValue_t7E5F9CBA239436E9F59788183F2C33E9826F8ADF, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 903
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m4C0458CE84ED9C58132692F135BB07908074DC06_gshared_inline (Func_2_tBF61C27F5D4B1164E65ED3A5E547C0318EF97577* __this, StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF ___0_arg, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, StylePropertyName_tCBE2B561C690538C8514BF56426AC486DC35B6FF, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 41474
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41467
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m934C9E3CBBFA04ABEF4528E565C300B5DCF8C2D1_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___0_input;
		void* L_1 = ___1_ptr;
		UnsafeUtilityInternal_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6C6F7ABC33BDF25A69E8A2E8DE137DB2ACB77FDC_inline(L_0, L_1, NULL);
		return;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 UnsafeUtility_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_mFD7DBC1199616005466125347027F6201459B40D_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_m108E077C32AC45BC5336988B727DADDF1711407A_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeUtility_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mCA80AB19D82B40C3B0B1BC9A4BE2F87BAFD9BE64_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mDC8A7125EE74C940B9F940440D412BA4B3A42575_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB UnsafeUtility_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m7AA25F6024B181108CC3A96104D0E5ABCED519C6_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m0C048047EB886D78B484166DCB014DF594B085BD_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB UnsafeUtility_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m77A0F5FAAAA9E070343AB7A018FCB34FD1698A06_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m4E657D67A0253D6AA48A0AF0834D8B8B4D986C48_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int32_t L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C UnsafeUtility_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mFDF2C4591B5F4C0AF4424ED681225F9CF100C5BB_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mC6AFEEF7260AB50C6AC741C83424DB3F59ECA569_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t UnsafeUtility_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mDA80BAFF55EA77496672B3B5B3804B55274B7E95_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		uint32_t L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mAA4A4AC11C7C0784A0566FAE86EFBAD08CF4126D_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UnsafeUtility_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_mF765CB2E5FD631DFB79C25DE656F3C1BB359B995_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		bool L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m504EAEDFA7F1C3551FBC5F11CFB40360033F8B84_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 UnsafeUtility_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_m2E442046FFC024C177FCA6130678FA0B97F3C445_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_mB00BADAC0C27D3EBF922C4D9514DBAFFE7570306_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 UnsafeUtility_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_mF42F014B5AA9C633D3FCAB3FFF26646E54395BD8_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_m03D847364989884CB1A8D031CFBB7BAACDF29EB2_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B UnsafeUtility_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m86FC76E325E9D3B56133BB7A193BAF12B47FBCC1_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m6FD81C4AA7D25C02FAA41E4FDDA346959381646F_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 UnsafeUtility_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_mAEB04091BED5994494AB1521F1CA283C9A55DA84_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m11FC059EDD11872BC9AA0E4A69DE23575103FCB9_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 UnsafeUtility_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m6C484995D5C95208A4EB1F0C7664EC42A74DE670_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m25474EB27C8162D7A4BDF444168565682AC81612_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 UnsafeUtility_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m80C61348EC8F9D4F73F0AAA4A69A028E6D599DCD_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m986ED2902CE4A51ABE99D9309F33BEE50D219A80_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 UnsafeUtility_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m361058B0E058D8D5D3AC6C6C015700E6018A671C_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m0863D7A09467FAC3CAE8A852D088E9E980F02756_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 UnsafeUtility_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_m8460969BD9998B0DFF865186874B2414FEED12C8_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_mFD8E968B6D42F987231C2D4D4433BC15E231FB83_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41468
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 UnsafeUtility_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m2A66DBE83F9498AC60B42C9A0B1C7E4401B4CDCC_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m3358302574C84901BFC17BF5A4E83AD5C5475245_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 41473
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m312FD1D94C51FFE92899836D9F020617D431BBF5_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(ComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_mDEDCEBAF0C62FDCD22EA85CBDDBAFADD5CCB7915_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2F30078087CCDB55F8D473591F4FDE09CBEB5D9C_m55C940043B5A1852EB5C37BA424A6AC9A7B4260D_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisComputedStyle_t8B08CCCEE20525528B3FFDAC6D3F58F101AAF54C_m312FD1D94C51FFE92899836D9F020617D431BBF5_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m2B47DA4F1DF05E028EEA414B4BC8C82E8FCF4481_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(LayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_mA5EE4C645904072BD057D41FC7D1AABAB3B4E398_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t8866C28BEBC43BE45C777354FACE06E5D80D8AF1_m98779B037E081B8050E0B38AEAF0844112F9EBCA_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisLayoutCacheData_t1C9D16AB3B4EF0EC7A51422286D2E84ABBDEEA92_m2B47DA4F1DF05E028EEA414B4BC8C82E8FCF4481_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m77A7D05474DF60C828E063E75D6A6C52B0BB8A0A_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(LayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m61E51176F8D18A3C2FC21CECC8908B35B9DB5F3D_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t938D5D39EB34C9404E00E05DA835AEAF195EED60_mEAD7EEB63B4DF320E2B845B35B5279D7DE3A79D1_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisLayoutComputedData_t37CD62B9A6B59283679F1126AD9C4BB9FD15B9C1_m77A7D05474DF60C828E063E75D6A6C52B0BB8A0A_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mFF371C2E5F2018BDF838A2BBC5AC30EA7C74230E_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(LayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mF8CB5ED1AEDA173F1F15E75017828AA38AE9E6EA_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t12EA8BB9031D0D42734685DAB3E0DC8CDE6F7844_mF7669FB4FDB08DEECFB97E2BE96E4ABE06854B8A_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisLayoutConfigData_t6B1D36F00422E7EB7C51CF9103FC9D522B5481F4_mFF371C2E5F2018BDF838A2BBC5AC30EA7C74230E_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m851FFDFB05C6D16BC27B3BAD2B486229B48796FB_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(LayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m67C30665BD5F032BA4790CB4F198C5128D65FA1B_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA1529F9F8B7FA790F2938A80AD16F77284A61D04_mA13156A8148DE6FA510A7CC74B7B821794A925C7_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisLayoutNodeData_t1D56A4D5BFA0B262C0B70873ADB2B38C6A677858_m851FFDFB05C6D16BC27B3BAD2B486229B48796FB_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m952393E8A8C420CA0DEAB80F495FF991803AE4CD_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(PanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m86AC2282B14EEB2988DF554898FE8D12B6968652_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA801A0280FB34492FDCB3CB6E3234C95DCA0A512_mC956A5504B875A9255F4031549F4DA7B47AEE47B_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisPanelTransformData_t9DAFA01800D7063A32AF86020376173A567999ED_m952393E8A8C420CA0DEAB80F495FF991803AE4CD_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m501662FEF1C371DA264F4A8F86497DD85C6576C8_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(VisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m36CB3A618AC04CD0E869A5C34BAE8DBFDEA34119_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2E41B87D9D08BFCD38A18DAFF9D1503CD262A669_m95A0D6A4B8D13CC09EF01FF9975C8AB46CDD7086_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVisualElementSelectorData_t4C4043092A19A653CE8637C7659E36E0D3CC23A0_m501662FEF1C371DA264F4A8F86497DD85C6576C8_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m3BF032FF33CB8E4BAD8B53BCB58362D59F473562_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(VisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m7936CCEA1FD37B0D005189C07C3FAAC4E016B792_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFFFE7CB6FDF697D25267CACBE063159F38998B83_m5EF673BA7CA5471B065B0509F1A5949AADC5747A_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVisualElementTransformData_t3DD575B5990B68FF956673EFF036171C86A38DF3_m3BF032FF33CB8E4BAD8B53BCB58362D59F473562_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95900
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// Method Definition Index: 95892
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6C6F7ABC33BDF25A69E8A2E8DE137DB2ACB77FDC_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___0_input;
		void* L_1 = ___1_ptr;
		UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline(L_0, L_1, NULL);
		return;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 UnsafeUtilityInternal_ReadArrayElement_TisDrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94_m108E077C32AC45BC5336988B727DADDF1711407A_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94 L_6 = (*(DrawKey_t3B4EE6E2AE19E9DD7C1731E60C6A7B39FEEA1C94*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeUtilityInternal_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mDC8A7125EE74C940B9F940440D412BA4B3A42575_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_6 = (*(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB UnsafeUtilityInternal_ReadArrayElement_TisGPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB_m0C048047EB886D78B484166DCB014DF594B085BD_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB L_6 = (*(GPUArchetypeHandle_t4B8DB32EBCD8FFA94BCD4FD28FEC39E4A42054EB*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB_m4E657D67A0253D6AA48A0AF0834D8B8B4D986C48_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB L_6 = (*(GPUComponentSet_tD679169DC8F46CC38BDB81FA45D750A6DECA92FB*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int32_t L_6 = (*(int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C UnsafeUtilityInternal_ReadArrayElement_TisRangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C_mC6AFEEF7260AB50C6AC741C83424DB3F59ECA569_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C L_6 = (*(RangeKey_t6D4869B364ADC52DCAE541898513EF33CEE8878C*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t UnsafeUtilityInternal_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mAA4A4AC11C7C0784A0566FAE86EFBAD08CF4126D_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint32_t L_6 = (*(uint32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UnsafeUtilityInternal_ReadArrayElement_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m504EAEDFA7F1C3551FBC5F11CFB40360033F8B84_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(bool);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		bool L_6 = (*(bool*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 UnsafeUtilityInternal_ReadArrayElement_TisGPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6_mB00BADAC0C27D3EBF922C4D9514DBAFFE7570306_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6 L_6 = (*(GPUDrivenMaterial_tA7930996F9C2C0DF7FD8865402EB452E8EACCFB6*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 UnsafeUtilityInternal_ReadArrayElement_TisGPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78_m03D847364989884CB1A8D031CFBB7BAACDF29EB2_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78 L_6 = (*(GPUInstanceIndex_t1B73FC29B273B0470A8E186E3C2F19CA6D8FBA78*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B UnsafeUtilityInternal_ReadArrayElement_TisInstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B_m6FD81C4AA7D25C02FAA41E4FDDA346959381646F_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B L_6 = (*(InstanceHandle_tE8D892B001AFFDB8FA53EB19F2B356436AC36C3B*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 UnsafeUtilityInternal_ReadArrayElement_TisMeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254_m11FC059EDD11872BC9AA0E4A69DE23575103FCB9_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254 L_6 = (*(MeshInfo_tCFDEE32B5DCE649CF99B2376DAAC45BBB9C34254*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 UnsafeUtilityInternal_ReadArrayElement_TisUnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750_m25474EB27C8162D7A4BDF444168565682AC81612_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750 L_6 = (*(UnsafePerCameraInstanceData_tFE00A87578E2CC5C4A5CD6F93975B35DE6D78750*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 UnsafeUtilityInternal_ReadArrayElement_TisBatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770_m986ED2902CE4A51ABE99D9309F33BEE50D219A80_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770 L_6 = (*(BatchID_t884E3C204D1F4C18FFD2361FC14A1E64CFBD8770*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 UnsafeUtilityInternal_ReadArrayElement_TisGPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669_m0863D7A09467FAC3CAE8A852D088E9E980F02756_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669 L_6 = (*(GPUComponentHandle_t619739F7572042FBAC8209B8B39DE768B62D7669*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 UnsafeUtilityInternal_ReadArrayElement_TisAnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46_mFD8E968B6D42F987231C2D4D4433BC15E231FB83_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46 L_6 = (*(AnimatedFadeData_t965D6428A80522AB9EDFDF2671880282159C5E46*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95894
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 UnsafeUtilityInternal_ReadArrayElement_TisGeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271_m3358302574C84901BFC17BF5A4E83AD5C5475245_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271 L_6 = (*(GeometryPoolHandle_t7EF37F11E23B05A26C1F72855D269B7A772B2271*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2F30078087CCDB55F8D473591F4FDE09CBEB5D9C_m55C940043B5A1852EB5C37BA424A6AC9A7B4260D_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t2F30078087CCDB55F8D473591F4FDE09CBEB5D9C);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t8866C28BEBC43BE45C777354FACE06E5D80D8AF1_m98779B037E081B8050E0B38AEAF0844112F9EBCA_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t8866C28BEBC43BE45C777354FACE06E5D80D8AF1);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t938D5D39EB34C9404E00E05DA835AEAF195EED60_mEAD7EEB63B4DF320E2B845B35B5279D7DE3A79D1_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t938D5D39EB34C9404E00E05DA835AEAF195EED60);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t12EA8BB9031D0D42734685DAB3E0DC8CDE6F7844_mF7669FB4FDB08DEECFB97E2BE96E4ABE06854B8A_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t12EA8BB9031D0D42734685DAB3E0DC8CDE6F7844);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA1529F9F8B7FA790F2938A80AD16F77284A61D04_mA13156A8148DE6FA510A7CC74B7B821794A925C7_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tA1529F9F8B7FA790F2938A80AD16F77284A61D04);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA801A0280FB34492FDCB3CB6E3234C95DCA0A512_mC956A5504B875A9255F4031549F4DA7B47AEE47B_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tA801A0280FB34492FDCB3CB6E3234C95DCA0A512);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2E41B87D9D08BFCD38A18DAFF9D1503CD262A669_m95A0D6A4B8D13CC09EF01FF9975C8AB46CDD7086_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t2E41B87D9D08BFCD38A18DAFF9D1503CD262A669);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFFFE7CB6FDF697D25267CACBE063159F38998B83_m5EF673BA7CA5471B065B0509F1A5949AADC5747A_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tFFFE7CB6FDF697D25267CACBE063159F38998B83);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95899
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = sizeof(int32_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 95893
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___1_ptr;
		int32_t* L_1 = ___0_input;
		int32_t L_2 = (*(int32_t*)L_1);
		*(int32_t*)L_0 = L_2;
		return;
	}
}
