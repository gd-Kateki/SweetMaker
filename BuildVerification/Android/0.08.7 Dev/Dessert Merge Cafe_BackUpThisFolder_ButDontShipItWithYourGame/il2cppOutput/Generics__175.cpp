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
template <typename T1, typename T2>
struct InterfaceActionInvoker2Invoker;
template <typename T1, typename T2>
struct InterfaceActionInvoker2Invoker<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1* p1, T2* p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		void* params[2] = { p1, p2 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, params[1]);
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
template <typename R, typename T1>
struct InterfaceFuncInvoker1Invoker;
template <typename R, typename T1>
struct InterfaceFuncInvoker1Invoker<R, T1*>
{
	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1* p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		R ret;
		void* params[1] = { p1 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2>
struct InterfaceFuncInvoker2Invoker;
template <typename R, typename T1, typename T2>
struct InterfaceFuncInvoker2Invoker<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1* p1, T2* p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		R ret;
		void* params[2] = { p1, p2 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, &ret);
		return ret;
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
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
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

struct ICollection_1_tB388ED908E2D241F56264CA971F25D9ADC1ADEC3;
struct IComparer_1_tFAD3AE9FE3CE1FB3CBB781C55DC57C986D71521E;
struct IDictionary_2_t4D3B65115D85F2C21975A2BBF4A23860F8BCD02F;
struct IEnumerable_1_t29E7244AE33B71FA0981E50D5BC73B7938F35C66;
struct IEnumerator_1_tFABD3B897F1296469E9A2DB9BCF6C89439049208;
struct IEnumerator_1_tC5EFC4DBB62C34A72D754565B91BA1F031A699FC;
struct IEnumerator_1_t1CFA6C99C764C9BBCD65BAF549FE08D1B84115DC;
struct IEnumerator_1_tC5858E440C3359E6457615D148BFD48EEB44B936;
struct IEnumerator_1_tB6110C5E4A18204546255EEF953F864D42DD5628;
struct IEnumerator_1_tF27F732B80D68354FB25E1B973770485E116E661;
struct IEnumerator_1_t1DE1A6D62A866B680CA05436970C66219F072F3F;
struct IEnumerator_1_tF422B2F697FFF4CEE00980A3F34C5EBCFF513AF8;
struct IEnumerator_1_tAD7115F3C599B3BBBB9FE1BAF43B40430B72787B;
struct IEnumerator_1_tB51F2BDB78AE50C18CD1FF9228F79A4F3E42E0F7;
struct IEnumerator_1_t9C4BEE74A726ABB541B6A2B81ABEBF11CEA37C93;
struct IEnumerator_1_tD4C45DA5A0EA402F52194AEF4BC5CEE33E9C42E7;
struct IEnumerator_1_t7F214D72DFE165B967A6488A351FD951AC943ECA;
struct IEnumerator_1_t50392EAD9ADF106BC46B4B284A411A16A3ECAAF0;
struct IEnumerator_1_tFE6E2BC242ED315B202D7AAFB5C2F283E0ACF41C;
struct IEnumerator_1_t9357DF13155A41022B9D2DAFB156C0520B699468;
struct IEnumerator_1_t3213D02848B6FA0AFF56BE2845A373C10004DCEC;
struct IEnumerator_1_t0283A591C147070A93FFA0F6C159D608B6155514;
struct IEnumerator_1_t8786CDA48E7686ED7408ABC3D0107028D2ECF147;
struct IEnumerator_1_tBDF7E057F62DB2860C2B14C0D800AACDDFFD0D09;
struct IEnumerator_1_t856F6838DCBDCCBBBC1BCE5D2A2CA3FB73C9E5C9;
struct IEnumerator_1_t599F3C486FA9A5C478FFFD6420C59A6BBB7876CB;
struct IEnumerator_1_t79B912CBA712D5F76599837CD1604BEED0829411;
struct IEnumerator_1_tB22FCD08D591B657979BC015772EF132DF8E4A74;
struct IEnumerator_1_t000A232CAF2DD4044B9AFBD8982ECD3FB93809DC;
struct IEnumerator_1_tE972D340F536B04FCEE79D5799CA3F036A83451E;
struct IEnumerator_1_t90BCA6A7B2801D6A60BF1AFFCCA677FFF22E4CDA;
struct IEnumerator_1_t2AE5E199CB93D17B1E27686CC16B6667521C4040;
struct IEnumerator_1_tBF6C47FD132BC760EB3FDF790E0FE91FD3053E9B;
struct IEnumerator_1_t837F12EEBD47871CA329AE5636F57529BD8510A5;
struct IEnumerator_1_t9BAC5B5F88A0B1402733E2E2AA7CDE94AAFFA628;
struct IEnumerator_1_tDA7EC6DD9C7B117D360F4F267DE1AF00D78E8A69;
struct IEnumerator_1_t795CE62572C33D602EE9162EFF1F8EB4430DAD53;
struct IEnumerator_1_tA50BA3A8477F7D3879301E45E86A18629E2CBF24;
struct IEnumerator_1_t3EEE9F125377475C3703132A819F02052CF21AFE;
struct IEnumerator_1_t7BCCF276AC30D3D187A762A3D4C55F4DA5CF0A12;
struct IEnumerator_1_t039FD1F79231873CA31A318A129D0F6366AE3729;
struct IEnumerator_1_tA64CB30F779A737F032BA0D0CA682AC54394FFA9;
struct IList_1_t16C1DE656F539216C2848197DD082F031C99F0C9;
struct IList_1_t54E7CEBB4F294BA7B9763262BEAD86BC7B3168C4;
struct IList_1_t7377FF68EE69B2987F8ACA5DEAE761851EA76BE4;
struct IList_1_tDCAF0049399DB8F22357E3CB72C84AE9A9702622;
struct IList_1_t5B9EDB63B2FC90F1EE5DF135C6FE8980047D8256;
struct IList_1_t94487033F99C5F7721C5C01BF007997207619130;
struct IList_1_t7563D82E2F8FABF600EEAB60A1585E401B6956D8;
struct IList_1_t7ECC6E2121DC015DF0532362ADD66FD411AE1D15;
struct IList_1_t6DC167BA63FEF5BD4CEDB6EB280344C5BA1AD4F4;
struct IList_1_tD27D8B7ADCEC5D64ADFBFA86505E4FE8D79AE399;
struct IList_1_tE36A63031E9C51E9B9F93EA9B09C4F9E5D8D9DC6;
struct IList_1_tFC0A38BF4A5A9374A84D2EB9837B4BB339BBC0DE;
struct IList_1_tBD4540D0A736923D06693CEDD5D0A7A89A53F040;
struct IList_1_t609D22177EE2C239AD3FF73279ECE88BBA4F0BFD;
struct IList_1_tAA1BA8212B537BD1CD622C60BC1660EC40FC5A55;
struct IList_1_tEB2AED36070E2E4FB9F2FEEC1E6A428E7AF0F27C;
struct IList_1_t3639BAE2393179717490A044F0250855FC246BA0;
struct IList_1_t4A9A4A4522238CC06724A58FE97BCC6029EA9F08;
struct IList_1_tF9176C866FFDE150BF57180C6B228C8CDA338F9F;
struct IList_1_t8532AAEB5D11551EBC2277A07A759536F58EA1A4;
struct IList_1_t143D8FB6289D26A7B7AD4238902B17029E83C017;
struct IList_1_t311EFF3B321589A14DAE708AD51B9BF47F025EB8;
struct IList_1_t9D41323B910C0BD2D04A6EF5DB4357FECB8F8BA3;
struct IList_1_t6D08EA7FA01BDF3C06E5BAAE0BFA0F62C86BD338;
struct IList_1_tB81C98CCFC4C70060D8C4A7773A2E018B7705389;
struct IList_1_tEBC9CEC655A21BEAC057F73381FE6A0F3284AB01;
struct IList_1_tCC943A0042E6BB5B3A81CD3BE47F5757992D48D0;
struct IList_1_t508D5DFA2AB2A294AE3394E462C1CAD77F2661CB;
struct IList_1_t3EE866489B03C7FF7DEF9C7563B742E75B5689A2;
struct IList_1_t36B65C5A0703C973E0430B86757444E48EB4FB33;
struct IList_1_t003E5AFD433AB8547CCEE560E2BED50D6AD222BD;
struct IList_1_tDE5A2CD28934CB598C6F11B9F1968099A5148F4C;
struct IList_1_tFE2112C69F0B9C04D713EA1C40EFA14A01A0F401;
struct IList_1_tE3897FF146787D9898848BA6072D0A5ACF74AF62;
struct IList_1_tC43AD077B5DBEFD836CDC2D1D0F3257315EB484F;
struct IList_1_t45147F5693AC2CD8E1FC02E6C69D23EC082D597B;
struct IList_1_t9603583555C8EAF0519028F467C9AD34BFEE4011;
struct KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221;
struct KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC;
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73;
struct ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B;
struct ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD;
struct ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6;
struct ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A;
struct ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A;
struct ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D;
struct ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC;
struct ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216;
struct ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4;
struct ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF;
struct ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5;
struct ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214;
struct ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D;
struct ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5;
struct ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631;
struct ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318;
struct ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32;
struct ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501;
struct ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73;
struct ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E;
struct ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6;
struct ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07;
struct ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69;
struct ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7;
struct ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135;
struct ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4;
struct ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65;
struct ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF;
struct ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568;
struct ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227;
struct ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC;
struct ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247;
struct ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466;
struct ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D;
struct ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4;
struct ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235;
struct ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434;
struct ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734;
struct ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849;
struct KeyValuePair_2U5BU5D_tF8154B2302178CCE00D745DBF55F703880469DFC;
struct KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE;
struct TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE;
struct AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F;
struct AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C;
struct Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44;
struct BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE;
struct SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F;
struct ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3;
struct StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7;
struct SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6;
struct ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB;
struct MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3;
struct TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322;
struct PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4;
struct AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8;
struct UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A;
struct FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118;
struct BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA;
struct FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25;
struct TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83;
struct RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279;
struct WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577;
struct AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F;
struct SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299;
struct SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A;
struct UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811;
struct VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64;
struct PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA;
struct XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27;
struct VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F;
struct ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279;
struct LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E;
struct InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3;
struct PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC;
struct ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B;
struct EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B;
struct PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317;
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Entry_t475ED76E31923970E7F7A6522E570E7577C487B9;
struct Font_tC95270EA3198038970422D78B74A7F2E218A96B6;
struct FontAsset_t61A6446D934E582651044E33D250EA8D306AB958;
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931;
struct ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IDictionaryEnumerator_tE129D608FCDB7207E0F0ECE33473CC950A83AD16;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct IPinnable_tA3989EA495C0118966BAAF8848C0009947BB49C0;
struct Instruction_t7ED95EF62BBC5003D30C1CE0FF8B1D79105A8998;
struct ManualResetEvent_t63959486AA41A113A4353D0BF4A68E77EBA0A158;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MeshHandle_tC1E9A7ECCFDAEFDE064B8D58B35B9CEE5A70A22E;
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
struct Page_tB4EA8095DF85BAF22AB8FCA71400121E721B57C9;
struct RenderData_t1ABE116B2B5E0409AC699E195922516606531DC2;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SendOrPostCallback_t5C292A12062F24027A98492F52ECFE9802AA6F0E;
struct String_t;
struct TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69;
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700;
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
struct Type_t;
struct UxmlSerializedData_t5BDDB665835158F6BC2975E086891B337C3BB706;
struct VisualElement_t2667F9D19E62C7A315927506C06F223AB9234115;
struct VisualTreeAsset_tFB5BF81F0780A412AE5A7C2C552B3EEA64EA2EEB;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct Volume_t7CAAEA22D7F13A50FAE114DE7A6986FEAC837377;
struct VolumeComponent_t8121D1F6054A9DFB3A596EE451FD65A2BFE2D7E1;
struct VolumeProfile_t9B5F2005F575A710F38A124EF81A6228CCACACE1;
struct XmlQualifiedName_t2794880B373257E4108CC3F36D7373A343ACC5B9;
struct XmlSchemaObject_t82CCD87AADB4BEF4E9DFE4C501F09EDA372AA19D;
struct BufferResourceData_t0B823212ADCC9AA80412877B802DD43236781D57;
struct TextureResourceData_t0714EB0BFE2BFB2FC4E0CCFFBFE5CAA6C4B53BE3;
struct NRPInfo_tFAE346DBF564B1FDA1EBC1D2F0C3EDC93143D04F;
struct ResourceIdLists_tD6328DF3B43DB6A2B045464122D4DD5AC1629D99;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RuntimeObject_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* String_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1;
IL2CPP_EXTERN_C String_t* _stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE;
IL2CPP_EXTERN_C String_t* _stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B;
IL2CPP_EXTERN_C String_t* _stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70;
IL2CPP_EXTERN_C String_t* _stringLiteral958BF5561D89C9A90653416FCB65BBE72DADDE1E;
IL2CPP_EXTERN_C String_t* _stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5;
IL2CPP_EXTERN_C String_t* _stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED;
IL2CPP_EXTERN_C String_t* _stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8;
IL2CPP_EXTERN_C String_t* _stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB;
IL2CPP_EXTERN_C String_t* _stringLiteralE7D028CCE3B6E7B61AE2C752D7AE970DA04AB7C6;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE;
struct TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE;
struct AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F;
struct AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C;
struct Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44;
struct BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE;
struct SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F;
struct ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3;
struct StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7;
struct SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6;
struct ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB;
struct MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3;
struct TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322;
struct PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4;
struct AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8;
struct UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A;
struct FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118;
struct BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA;
struct FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25;
struct TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83;
struct RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279;
struct WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577;
struct AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F;
struct SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299;
struct SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A;
struct UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811;
struct VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64;
struct PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA;
struct XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27;
struct VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F;
struct ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279;
struct LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E;
struct InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3;
struct PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC;
struct ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B;
struct EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B;
struct PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221  : public RuntimeObject
{
	RuntimeObject* ____collection;
	RuntimeObject* ____syncRoot;
};
struct MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E  : public RuntimeObject
{
};
struct MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583  : public RuntimeObject
{
};
struct ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734  : public RuntimeObject
{
	RuntimeObject* ___m_dictionary;
	RuntimeObject* ____syncRoot;
	KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* ____keys;
	ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* ____values;
};
struct ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849  : public RuntimeObject
{
	RuntimeObject* ____collection;
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
struct ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____array;
	int32_t ____offset;
	int32_t ____count;
};
struct ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3 
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ____array;
	int32_t ____offset;
	int32_t ____count;
};
struct ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178 
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ____array;
	int32_t ____offset;
	int32_t ____count;
};
struct DictionaryEnumerator_tA07B53C91CCF243B3DDF48825CD4F71A6835CD77 
{
	RuntimeObject* ____dictionary;
	RuntimeObject* ____enumerator;
};
typedef Il2CppFullySharedGenericStruct KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669;
struct Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036 
{
	RuntimeObject* ____object;
	int32_t ____index;
	int32_t ____length;
};
#ifndef Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke_define
#define Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke_define
struct Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
#ifndef Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com_define
#define Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com_define
struct Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
struct Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E 
{
	RuntimeObject* ____object;
	int32_t ____index;
	int32_t ____length;
};
#ifndef Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke_define
#define Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke_define
struct Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
#ifndef Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com_define
#define Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com_define
struct Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
struct Memory_1_t762D61B435521D1706EEDC25CA8C8EA1AE19AFEA 
{
	RuntimeObject* ____object;
	int32_t ____index;
	int32_t ____length;
};
#ifndef Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke_define
#define Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke_define
struct Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
#ifndef Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com_define
#define Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com_define
struct Memory_1_t56F63672B8E752B13E0BBBBD034BA3C1F6CFDC17_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
struct ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 
{
	RuntimeObject* ____object;
	int32_t ____index;
	int32_t ____length;
};
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
struct ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 
{
	RuntimeObject* ____object;
	int32_t ____index;
	int32_t ____length;
};
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
struct ReadOnlyMemory_1_t192441E248CAB66088AAEDBD64DFEE110ADBEED4 
{
	RuntimeObject* ____object;
	int32_t ____index;
	int32_t ____length;
};
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
struct Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE 
{
	uint32_t ___start;
	uint32_t ___size;
	RuntimeObject* ___handle;
	bool ___shortLived;
};
struct Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_pinvoke
{
	uint32_t ___start;
	uint32_t ___size;
	Il2CppIUnknown* ___handle;
	int32_t ___shortLived;
};
struct Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_com
{
	uint32_t ___start;
	uint32_t ___size;
	Il2CppIUnknown* ___handle;
	int32_t ___shortLived;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	float ___r;
	float ___g;
	float ___b;
	float ___a;
};
struct ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B 
{
	bool ___isValid;
	uint16_t ___id;
};
struct ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_pinvoke
{
	int32_t ___isValid;
	uint16_t ___id;
};
struct ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_com
{
	int32_t ___isValid;
	uint16_t ___id;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB 
{
	RuntimeObject* ____key;
	RuntimeObject* ____value;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_marshaled_pinvoke
{
	Il2CppIUnknown* ____key;
	Il2CppIUnknown* ____value;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_marshaled_com
{
	Il2CppIUnknown* ____key;
	Il2CppIUnknown* ____value;
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
struct InputDeviceMatcher_tF9BA551C8BB4AE41672366A7EBEA951543E0C555 
{
	KeyValuePair_2U5BU5D_tF8154B2302178CCE00D745DBF55F703880469DFC* ___m_Patterns;
};
struct InputDeviceMatcher_tF9BA551C8BB4AE41672366A7EBEA951543E0C555_marshaled_pinvoke
{
	KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC* ___m_Patterns;
};
struct InputDeviceMatcher_tF9BA551C8BB4AE41672366A7EBEA951543E0C555_marshaled_com
{
	KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC* ___m_Patterns;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
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
struct Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D 
{
	float ___m_XMin;
	float ___m_YMin;
	float ___m_Width;
	float ___m_Height;
};
struct RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 
{
	int32_t ___m_XMin;
	int32_t ___m_YMin;
	int32_t ___m_Width;
	int32_t ___m_Height;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	float ___x;
	float ___y;
};
struct Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A 
{
	int32_t ___m_X;
	int32_t ___m_Y;
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
struct NativeColorId_tC2A21D165C258872CC3EEB668F4CF4D08C37237A 
{
	int32_t ___isValid;
	uint16_t ___id;
	uint16_t ____pad;
};
struct BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B 
{
	int32_t ___x;
	int32_t ___y;
	int32_t ___z;
};
struct SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 
{
	String_t* ___sceneGUID;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___cellList;
};
struct SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591_marshaled_pinvoke
{
	char* ___sceneGUID;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___cellList;
};
struct SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591_marshaled_com
{
	Il2CppChar* ___sceneGUID;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___cellList;
};
struct ObsoletePerScenarioData_tB1EFC0C7B7EA6D0DD0CACC22888799725FC6787C 
{
	int32_t ___sceneHash;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* ___cellDataAsset;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* ___cellOptionalDataAsset;
};
struct ObsoletePerScenarioData_tB1EFC0C7B7EA6D0DD0CACC22888799725FC6787C_marshaled_pinvoke
{
	int32_t ___sceneHash;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* ___cellDataAsset;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* ___cellOptionalDataAsset;
};
struct ObsoletePerScenarioData_tB1EFC0C7B7EA6D0DD0CACC22888799725FC6787C_marshaled_com
{
	int32_t ___sceneHash;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* ___cellDataAsset;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* ___cellOptionalDataAsset;
};
struct StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A 
{
	int32_t ___offset;
	int32_t ___elementCount;
};
struct SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC 
{
	Il2CppChar ___First;
	Il2CppChar ___Last;
};
struct SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_marshaled_pinvoke
{
	uint8_t ___First;
	uint8_t ___Last;
};
struct SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_marshaled_com
{
	uint8_t ___First;
	uint8_t ___Last;
};
struct ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 
{
	VisualElement_t2667F9D19E62C7A315927506C06F223AB9234115* ___element;
	bool ___canceled;
};
struct ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959_marshaled_pinvoke
{
	VisualElement_t2667F9D19E62C7A315927506C06F223AB9234115* ___element;
	int32_t ___canceled;
};
struct ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959_marshaled_com
{
	VisualElement_t2667F9D19E62C7A315927506C06F223AB9234115* ___element;
	int32_t ___canceled;
};
struct TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 
{
	String_t* ___fullName;
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___transform;
};
struct TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646_marshaled_pinvoke
{
	char* ___fullName;
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___transform;
};
struct TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646_marshaled_com
{
	Il2CppChar* ___fullName;
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___transform;
};
struct AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF 
{
	String_t* ___m_ElementName;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___m_NamesPath;
	String_t* ___m_AttributeName;
	String_t* ___m_Value;
};
struct AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF_marshaled_pinvoke
{
	char* ___m_ElementName;
	char** ___m_NamesPath;
	char* ___m_AttributeName;
	char* ___m_Value;
};
struct AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF_marshaled_com
{
	Il2CppChar* ___m_ElementName;
	Il2CppChar** ___m_NamesPath;
	Il2CppChar* ___m_AttributeName;
	Il2CppChar* ___m_Value;
};
struct UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 
{
	int32_t ___m_ElementId;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___m_ElementIdsPath;
	UxmlSerializedData_t5BDDB665835158F6BC2975E086891B337C3BB706* ___m_SerializedData;
};
struct UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67_marshaled_pinvoke
{
	int32_t ___m_ElementId;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___m_ElementIdsPath;
	UxmlSerializedData_t5BDDB665835158F6BC2975E086891B337C3BB706* ___m_SerializedData;
};
struct UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67_marshaled_com
{
	int32_t ___m_ElementId;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___m_ElementIdsPath;
	UxmlSerializedData_t5BDDB665835158F6BC2975E086891B337C3BB706* ___m_SerializedData;
};
struct FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 
{
	Font_tC95270EA3198038970422D78B74A7F2E218A96B6* ___font;
	FontAsset_t61A6446D934E582651044E33D250EA8D306AB958* ___fontAsset;
};
struct FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831_marshaled_pinvoke
{
	Font_tC95270EA3198038970422D78B74A7F2E218A96B6* ___font;
	FontAsset_t61A6446D934E582651044E33D250EA8D306AB958* ___fontAsset;
};
struct FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831_marshaled_com
{
	Font_tC95270EA3198038970422D78B74A7F2E218A96B6* ___font;
	FontAsset_t61A6446D934E582651044E33D250EA8D306AB958* ___fontAsset;
};
struct SpriteFrame_t0AD908328349FA1B90D428FEBAAD7B480B6D59F4 
{
	float ___x;
	float ___y;
	float ___w;
	float ___h;
};
struct SpriteSize_tF99BB7603AE2E6587E6184ACAB6CD209FE6569B3 
{
	float ___w;
	float ___h;
};
struct TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B 
{
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___texture;
	bool ___dynamic;
	int32_t ___refCount;
};
struct TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B_marshaled_pinvoke
{
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___texture;
	int32_t ___dynamic;
	int32_t ___refCount;
};
struct TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B_marshaled_com
{
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___texture;
	int32_t ___dynamic;
	int32_t ___refCount;
};
struct WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 
{
	SendOrPostCallback_t5C292A12062F24027A98492F52ECFE9802AA6F0E* ___m_DelagateCallback;
	RuntimeObject* ___m_DelagateState;
	ManualResetEvent_t63959486AA41A113A4353D0BF4A68E77EBA0A158* ___m_WaitHandle;
};
struct WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44_marshaled_pinvoke
{
	Il2CppMethodPointer ___m_DelagateCallback;
	Il2CppIUnknown* ___m_DelagateState;
	ManualResetEvent_t63959486AA41A113A4353D0BF4A68E77EBA0A158* ___m_WaitHandle;
};
struct WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44_marshaled_com
{
	Il2CppMethodPointer ___m_DelagateCallback;
	Il2CppIUnknown* ___m_DelagateState;
	ManualResetEvent_t63959486AA41A113A4353D0BF4A68E77EBA0A158* ___m_WaitHandle;
};
struct SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 
{
	String_t* ___name;
	int32_t ___insertionPointId;
};
struct SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8_marshaled_pinvoke
{
	char* ___name;
	int32_t ___insertionPointId;
};
struct SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8_marshaled_com
{
	Il2CppChar* ___name;
	int32_t ___insertionPointId;
};
struct SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 
{
	String_t* ___slotName;
	int32_t ___assetId;
};
struct SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76_marshaled_pinvoke
{
	char* ___slotName;
	int32_t ___assetId;
};
struct SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76_marshaled_com
{
	Il2CppChar* ___slotName;
	int32_t ___assetId;
};
struct UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 
{
	String_t* ___alias;
	String_t* ___path;
	VisualTreeAsset_tFB5BF81F0780A412AE5A7C2C552B3EEA64EA2EEB* ___asset;
};
struct UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484_marshaled_pinvoke
{
	char* ___alias;
	char* ___path;
	VisualTreeAsset_tFB5BF81F0780A412AE5A7C2C552B3EEA64EA2EEB* ___asset;
};
struct UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484_marshaled_com
{
	Il2CppChar* ___alias;
	Il2CppChar* ___path;
	VisualTreeAsset_tFB5BF81F0780A412AE5A7C2C552B3EEA64EA2EEB* ___asset;
};
struct VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 
{
	RuntimeObject* ___source;
	int64_t ___version;
};
struct VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8_marshaled_pinvoke
{
	Il2CppIUnknown* ___source;
	int64_t ___version;
};
struct VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8_marshaled_com
{
	Il2CppIUnknown* ___source;
	int64_t ___version;
};
struct XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD 
{
	XmlQualifiedName_t2794880B373257E4108CC3F36D7373A343ACC5B9* ___qname;
	XmlSchemaObject_t82CCD87AADB4BEF4E9DFE4C501F09EDA372AA19D* ___xso;
};
struct XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD_marshaled_pinvoke
{
	XmlQualifiedName_t2794880B373257E4108CC3F36D7373A343ACC5B9* ___qname;
	XmlSchemaObject_t82CCD87AADB4BEF4E9DFE4C501F09EDA372AA19D* ___xso;
};
struct XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD_marshaled_com
{
	XmlQualifiedName_t2794880B373257E4108CC3F36D7373A343ACC5B9* ___qname;
	XmlSchemaObject_t82CCD87AADB4BEF4E9DFE4C501F09EDA372AA19D* ___xso;
};
struct ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 
{
	String_t* ___displayName;
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___action;
};
struct ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9_marshaled_pinvoke
{
	char* ___displayName;
	Il2CppMethodPointer ___action;
};
struct ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9_marshaled_com
{
	Il2CppChar* ___displayName;
	Il2CppMethodPointer ___action;
};
struct NameAndTooltip_tA6656221A6E70C8409CFCBAF6CCEC9C718E344D4 
{
	String_t* ___name;
	String_t* ___tooltip;
};
struct NameAndTooltip_tA6656221A6E70C8409CFCBAF6CCEC9C718E344D4_marshaled_pinvoke
{
	char* ___name;
	char* ___tooltip;
};
struct NameAndTooltip_tA6656221A6E70C8409CFCBAF6CCEC9C718E344D4_marshaled_com
{
	Il2CppChar* ___name;
	Il2CppChar* ___tooltip;
};
struct InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D 
{
	int32_t ____index;
	int32_t ____stackDepth;
	int32_t ____continuationsDepth;
	String_t* ____name;
	Instruction_t7ED95EF62BBC5003D30C1CE0FF8B1D79105A8998* ____instruction;
};
struct InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D_marshaled_pinvoke
{
	int32_t ____index;
	int32_t ____stackDepth;
	int32_t ____continuationsDepth;
	char* ____name;
	Instruction_t7ED95EF62BBC5003D30C1CE0FF8B1D79105A8998* ____instruction;
};
struct InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D_marshaled_com
{
	int32_t ____index;
	int32_t ____stackDepth;
	int32_t ____continuationsDepth;
	Il2CppChar* ____name;
	Instruction_t7ED95EF62BBC5003D30C1CE0FF8B1D79105A8998* ____instruction;
};
struct PassScriptInfo_t8619301849E12A8422C5C4BF3D19F5D7410A0A31 
{
	String_t* ___filePath;
	int32_t ___line;
};
struct PassScriptInfo_t8619301849E12A8422C5C4BF3D19F5D7410A0A31_marshaled_pinvoke
{
	char* ___filePath;
	int32_t ___line;
};
struct PassScriptInfo_t8619301849E12A8422C5C4BF3D19F5D7410A0A31_marshaled_com
{
	Il2CppChar* ___filePath;
	int32_t ___line;
};
struct ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 
{
	String_t* ___name;
	bool ___imported;
	int32_t ___creationPassIndex;
	int32_t ___releasePassIndex;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___consumerList;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___producerList;
	bool ___memoryless;
	TextureResourceData_t0714EB0BFE2BFB2FC4E0CCFFBFE5CAA6C4B53BE3* ___textureData;
	BufferResourceData_t0B823212ADCC9AA80412877B802DD43236781D57* ___bufferData;
};
struct ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3_marshaled_pinvoke
{
	char* ___name;
	int32_t ___imported;
	int32_t ___creationPassIndex;
	int32_t ___releasePassIndex;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___consumerList;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___producerList;
	int32_t ___memoryless;
	TextureResourceData_t0714EB0BFE2BFB2FC4E0CCFFBFE5CAA6C4B53BE3* ___textureData;
	BufferResourceData_t0B823212ADCC9AA80412877B802DD43236781D57* ___bufferData;
};
struct ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3_marshaled_com
{
	Il2CppChar* ___name;
	int32_t ___imported;
	int32_t ___creationPassIndex;
	int32_t ___releasePassIndex;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___consumerList;
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___producerList;
	int32_t ___memoryless;
	TextureResourceData_t0714EB0BFE2BFB2FC4E0CCFFBFE5CAA6C4B53BE3* ___textureData;
	BufferResourceData_t0B823212ADCC9AA80412877B802DD43236781D57* ___bufferData;
};
struct PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 
{
	String_t* ___message;
	bool ___isCompatible;
};
struct PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3_marshaled_pinvoke
{
	char* ___message;
	int32_t ___isCompatible;
};
struct PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3_marshaled_com
{
	Il2CppChar* ___message;
	int32_t ___isCompatible;
};
struct ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC 
{
	intptr_t ____value;
};
struct ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 
{
	intptr_t ____value;
};
struct ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 
{
	intptr_t ____value;
};
struct LazyLoadReference_1_tD57A582D5A28F3AE34FBB810985EF171325FAF1B 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_EntityId;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct DrawPhase_t486494E09E3D14AEF7D5544440BD869D73BB7DA7 
{
	uint8_t ___value__;
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
struct GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC 
{
	intptr_t ___handle;
};
struct GCHandleType_t4CD45A3495E593D093AB0CE36EF9EC1A1572F82A 
{
	int32_t ___value__;
};
struct RenderGraphPassType_tD00EC2DAA135C660EE7E71652291A4672104EA2D 
{
	int32_t ___value__;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct ScaleMode_t16AD656758EE54C56B3DA34FE4F2033C9C2EE13D 
{
	int32_t ___value__;
};
struct RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0  : public RuntimeObject
{
	intptr_t ___Bounds;
	intptr_t ___Count;
	uint8_t ___Data;
};
struct RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0_marshaled_pinvoke
{
	intptr_t ___Bounds;
	intptr_t ___Count;
	uint8_t ___Data;
};
struct RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0_marshaled_com
{
	intptr_t ___Bounds;
	intptr_t ___Count;
	uint8_t ___Data;
};
struct BorderParams_tA3F0684BE19E681B68F40A773737978EB3FD1509 
{
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___rect;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___playmodeTintColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___leftColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___topColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___rightColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___bottomColor;
	float ___leftWidth;
	float ___topWidth;
	float ___rightWidth;
	float ___bottomWidth;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topLeftRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomLeftRadius;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B ___leftColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B ___topColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B ___rightColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B ___bottomColorId;
};
struct BorderParams_tA3F0684BE19E681B68F40A773737978EB3FD1509_marshaled_pinvoke
{
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___rect;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___playmodeTintColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___leftColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___topColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___rightColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___bottomColor;
	float ___leftWidth;
	float ___topWidth;
	float ___rightWidth;
	float ___bottomWidth;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topLeftRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomLeftRadius;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_pinvoke ___leftColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_pinvoke ___topColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_pinvoke ___rightColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_pinvoke ___bottomColorId;
};
struct BorderParams_tA3F0684BE19E681B68F40A773737978EB3FD1509_marshaled_com
{
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___rect;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___playmodeTintColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___leftColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___topColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___rightColor;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___bottomColor;
	float ___leftWidth;
	float ___topWidth;
	float ___rightWidth;
	float ___bottomWidth;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topLeftRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomLeftRadius;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_com ___leftColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_com ___topColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_com ___rightColorId;
	ColorId_t6B928BC1978476896DCF48B8577984FD37D89F9B_marshaled_com ___bottomColorId;
};
struct RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C 
{
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___rect;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___uv;
};
struct AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB 
{
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE ___alloc;
	Page_tB4EA8095DF85BAF22AB8FCA71400121E721B57C9* ___page;
	bool ___vertices;
};
struct AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB_marshaled_pinvoke
{
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_pinvoke ___alloc;
	Page_tB4EA8095DF85BAF22AB8FCA71400121E721B57C9* ___page;
	int32_t ___vertices;
};
struct AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB_marshaled_com
{
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_com ___alloc;
	Page_tB4EA8095DF85BAF22AB8FCA71400121E721B57C9* ___page;
	int32_t ___vertices;
};
struct AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 
{
	uint32_t ___id;
	uint32_t ___allocTime;
	MeshHandle_tC1E9A7ECCFDAEFDE064B8D58B35B9CEE5A70A22E* ___meshHandle;
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE ___permAllocVerts;
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE ___permAllocIndices;
	Page_tB4EA8095DF85BAF22AB8FCA71400121E721B57C9* ___permPage;
	bool ___copyBackIndices;
};
struct AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3_marshaled_pinvoke
{
	uint32_t ___id;
	uint32_t ___allocTime;
	MeshHandle_tC1E9A7ECCFDAEFDE064B8D58B35B9CEE5A70A22E* ___meshHandle;
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_pinvoke ___permAllocVerts;
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_pinvoke ___permAllocIndices;
	Page_tB4EA8095DF85BAF22AB8FCA71400121E721B57C9* ___permPage;
	int32_t ___copyBackIndices;
};
struct AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3_marshaled_com
{
	uint32_t ___id;
	uint32_t ___allocTime;
	MeshHandle_tC1E9A7ECCFDAEFDE064B8D58B35B9CEE5A70A22E* ___meshHandle;
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_com ___permAllocVerts;
	Alloc_t78312CFE58F38082281E80E297AE6176BD2BD8AE_marshaled_com ___permAllocIndices;
	Page_tB4EA8095DF85BAF22AB8FCA71400121E721B57C9* ___permPage;
	int32_t ___copyBackIndices;
};
struct ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 
{
	String_t* ___scenario;
	ObsoletePerScenarioData_tB1EFC0C7B7EA6D0DD0CACC22888799725FC6787C ___data;
};
struct ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7_marshaled_pinvoke
{
	char* ___scenario;
	ObsoletePerScenarioData_tB1EFC0C7B7EA6D0DD0CACC22888799725FC6787C_marshaled_pinvoke ___data;
};
struct ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7_marshaled_com
{
	Il2CppChar* ___scenario;
	ObsoletePerScenarioData_tB1EFC0C7B7EA6D0DD0CACC22888799725FC6787C_marshaled_com ___data;
};
struct MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___min;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___max;
};
struct BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 
{
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___src;
	RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 ___srcRect;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___dstPos;
	int32_t ___border;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___tint;
};
struct BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357_marshaled_pinvoke
{
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___src;
	RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 ___srcRect;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___dstPos;
	int32_t ___border;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___tint;
};
struct BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357_marshaled_com
{
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___src;
	RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 ___srcRect;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___dstPos;
	int32_t ___border;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___tint;
};
struct Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD 
{
	String_t* ___filename;
	SpriteFrame_t0AD908328349FA1B90D428FEBAAD7B480B6D59F4 ___frame;
	bool ___rotated;
	bool ___trimmed;
	SpriteFrame_t0AD908328349FA1B90D428FEBAAD7B480B6D59F4 ___spriteSourceSize;
	SpriteSize_tF99BB7603AE2E6587E6184ACAB6CD209FE6569B3 ___sourceSize;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___pivot;
};
struct Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD_marshaled_pinvoke
{
	char* ___filename;
	SpriteFrame_t0AD908328349FA1B90D428FEBAAD7B480B6D59F4 ___frame;
	int32_t ___rotated;
	int32_t ___trimmed;
	SpriteFrame_t0AD908328349FA1B90D428FEBAAD7B480B6D59F4 ___spriteSourceSize;
	SpriteSize_tF99BB7603AE2E6587E6184ACAB6CD209FE6569B3 ___sourceSize;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___pivot;
};
struct Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD_marshaled_com
{
	Il2CppChar* ___filename;
	SpriteFrame_t0AD908328349FA1B90D428FEBAAD7B480B6D59F4 ___frame;
	int32_t ___rotated;
	int32_t ___trimmed;
	SpriteFrame_t0AD908328349FA1B90D428FEBAAD7B480B6D59F4 ___spriteSourceSize;
	SpriteSize_tF99BB7603AE2E6587E6184ACAB6CD209FE6569B3 ___sourceSize;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___pivot;
};
struct RaycastHitData_t5EAB266730389AB27715962670C2512800451841 
{
	Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931* ___U3CgraphicU3Ek__BackingField;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CworldHitPositionU3Ek__BackingField;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CscreenPositionU3Ek__BackingField;
	float ___U3CdistanceU3Ek__BackingField;
};
struct RaycastHitData_t5EAB266730389AB27715962670C2512800451841_marshaled_pinvoke
{
	Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931* ___U3CgraphicU3Ek__BackingField;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CworldHitPositionU3Ek__BackingField;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CscreenPositionU3Ek__BackingField;
	float ___U3CdistanceU3Ek__BackingField;
};
struct RaycastHitData_t5EAB266730389AB27715962670C2512800451841_marshaled_com
{
	Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931* ___U3CgraphicU3Ek__BackingField;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CworldHitPositionU3Ek__BackingField;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CscreenPositionU3Ek__BackingField;
	float ___U3CdistanceU3Ek__BackingField;
};
struct PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___position;
	int32_t ___type;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___intensity;
	int32_t ___castShadows;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forward;
	int32_t ___contributesToDirectLighting;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___attenuation;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___up;
	float ___width;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___right;
	float ___height;
	uint32_t ___layerMask;
	float ___indirectScale;
	float ___spotAngle;
	float ___innerSpotAngle;
	float ___range;
	int32_t ___shadowMaskChannel;
	int32_t ___falloffIndex;
	float ___shadowRadius;
	int32_t ___cookieIndex;
};
struct VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E 
{
	NameAndTooltip_tA6656221A6E70C8409CFCBAF6CCEC9C718E344D4 ___nameAndTooltip;
	VolumeProfile_t9B5F2005F575A710F38A124EF81A6228CCACACE1* ___volumeProfile;
	VolumeComponent_t8121D1F6054A9DFB3A596EE451FD65A2BFE2D7E1* ___volumeComponent;
	Volume_t7CAAEA22D7F13A50FAE114DE7A6986FEAC837377* ___volume;
};
struct VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E_marshaled_pinvoke
{
	NameAndTooltip_tA6656221A6E70C8409CFCBAF6CCEC9C718E344D4_marshaled_pinvoke ___nameAndTooltip;
	VolumeProfile_t9B5F2005F575A710F38A124EF81A6228CCACACE1* ___volumeProfile;
	VolumeComponent_t8121D1F6054A9DFB3A596EE451FD65A2BFE2D7E1* ___volumeComponent;
	Volume_t7CAAEA22D7F13A50FAE114DE7A6986FEAC837377* ___volume;
};
struct VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E_marshaled_com
{
	NameAndTooltip_tA6656221A6E70C8409CFCBAF6CCEC9C718E344D4_marshaled_com ___nameAndTooltip;
	VolumeProfile_t9B5F2005F575A710F38A124EF81A6228CCACACE1* ___volumeProfile;
	VolumeComponent_t8121D1F6054A9DFB3A596EE451FD65A2BFE2D7E1* ___volumeComponent;
	Volume_t7CAAEA22D7F13A50FAE114DE7A6986FEAC837377* ___volume;
};
struct LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 
{
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___layoutName;
	InputDeviceMatcher_tF9BA551C8BB4AE41672366A7EBEA951543E0C555 ___deviceMatcher;
};
struct LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6_marshaled_pinvoke
{
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_pinvoke ___layoutName;
	InputDeviceMatcher_tF9BA551C8BB4AE41672366A7EBEA951543E0C555_marshaled_pinvoke ___deviceMatcher;
};
struct LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6_marshaled_com
{
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_com ___layoutName;
	InputDeviceMatcher_tF9BA551C8BB4AE41672366A7EBEA951543E0C555_marshaled_com ___deviceMatcher;
};
struct VisualsProcessingType_t19983E0076886C15ED2761057B9992989A710ECC 
{
	int32_t ___value__;
};
struct NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC 
{
	ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 ____pointer;
	int32_t ____length;
};
struct Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 ____pointer;
	int32_t ____length;
};
struct Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 
{
	ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 ____pointer;
	int32_t ____length;
};
struct MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD 
{
	void* ____pointer;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ____handle;
	RuntimeObject* ____pinnable;
};
struct MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD_marshaled_pinvoke
{
	void* ____pointer;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ____handle;
	RuntimeObject* ____pinnable;
};
struct MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD_marshaled_com
{
	void* ____pointer;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ____handle;
	RuntimeObject* ____pinnable;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct UnsafeMeshGenerationNode_t1FF7D38D9B39DC59A2F8E2DFC92BFAB2481E88A2 
{
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ___m_Handle;
};
struct NativeRectParams_t18E2E456D50F027D08BF8B4BCBD83DF7FDB1C02F 
{
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___rect;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___subRect;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___uv;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___color;
	intptr_t ___backgroundRepeatInstanceList;
	int32_t ___backgroundRepeatInstanceListStartIndex;
	int32_t ___backgroundRepeatInstanceListEndIndex;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topLeftRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___topRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomRightRadius;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___bottomLeftRadius;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___backgroundRepeatRect;
	intptr_t ___texture;
	intptr_t ___sprite;
	intptr_t ___vectorImage;
	intptr_t ___spriteTexture;
	intptr_t ___spriteVertices;
	intptr_t ___spriteUVs;
	intptr_t ___spriteTriangles;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___spriteGeomRect;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___contentSize;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___textureSize;
	float ___texturePixelsPerPoint;
	int32_t ___leftSlice;
	int32_t ___topSlice;
	int32_t ___rightSlice;
	int32_t ___bottomSlice;
	float ___sliceScale;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___rectInset;
	NativeColorId_tC2A21D165C258872CC3EEB668F4CF4D08C37237A ___colorId;
	int32_t ___meshFlags;
	int32_t ___scaleMode;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___uvTopLeft;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___uvTopRight;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___uvBottomRight;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___uvBottomLeft;
	int32_t ___uvCornersValid;
};
struct AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D 
{
	String_t* ___m_Path;
	String_t* ___m_TypeFullName;
	LazyLoadReference_1_tD57A582D5A28F3AE34FBB810985EF171325FAF1B ___m_AssetReference;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_EntityId;
	Type_t* ___m_CachedType;
};
struct AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D_marshaled_pinvoke
{
	char* ___m_Path;
	char* ___m_TypeFullName;
	LazyLoadReference_1_tD57A582D5A28F3AE34FBB810985EF171325FAF1B ___m_AssetReference;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_EntityId;
	Type_t* ___m_CachedType;
};
struct AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D_marshaled_com
{
	Il2CppChar* ___m_Path;
	Il2CppChar* ___m_TypeFullName;
	LazyLoadReference_1_tD57A582D5A28F3AE34FBB810985EF171325FAF1B ___m_AssetReference;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_EntityId;
	Type_t* ___m_CachedType;
};
struct PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F 
{
	String_t* ___name;
	int32_t ___type;
	ResourceIdLists_tD6328DF3B43DB6A2B045464122D4DD5AC1629D99* ___resourceReadLists;
	ResourceIdLists_tD6328DF3B43DB6A2B045464122D4DD5AC1629D99* ___resourceWriteLists;
	bool ___culled;
	bool ___async;
	int32_t ___nativeSubPassIndex;
	int32_t ___syncToPassIndex;
	int32_t ___syncFromPassIndex;
	bool ___generateDebugData;
	NRPInfo_tFAE346DBF564B1FDA1EBC1D2F0C3EDC93143D04F* ___nrpInfo;
	PassScriptInfo_t8619301849E12A8422C5C4BF3D19F5D7410A0A31 ___scriptInfo;
};
struct PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F_marshaled_pinvoke
{
	char* ___name;
	int32_t ___type;
	ResourceIdLists_tD6328DF3B43DB6A2B045464122D4DD5AC1629D99* ___resourceReadLists;
	ResourceIdLists_tD6328DF3B43DB6A2B045464122D4DD5AC1629D99* ___resourceWriteLists;
	int32_t ___culled;
	int32_t ___async;
	int32_t ___nativeSubPassIndex;
	int32_t ___syncToPassIndex;
	int32_t ___syncFromPassIndex;
	int32_t ___generateDebugData;
	NRPInfo_tFAE346DBF564B1FDA1EBC1D2F0C3EDC93143D04F* ___nrpInfo;
	PassScriptInfo_t8619301849E12A8422C5C4BF3D19F5D7410A0A31_marshaled_pinvoke ___scriptInfo;
};
struct PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F_marshaled_com
{
	Il2CppChar* ___name;
	int32_t ___type;
	ResourceIdLists_tD6328DF3B43DB6A2B045464122D4DD5AC1629D99* ___resourceReadLists;
	ResourceIdLists_tD6328DF3B43DB6A2B045464122D4DD5AC1629D99* ___resourceWriteLists;
	int32_t ___culled;
	int32_t ___async;
	int32_t ___nativeSubPassIndex;
	int32_t ___syncToPassIndex;
	int32_t ___syncFromPassIndex;
	int32_t ___generateDebugData;
	NRPInfo_tFAE346DBF564B1FDA1EBC1D2F0C3EDC93143D04F* ___nrpInfo;
	PassScriptInfo_t8619301849E12A8422C5C4BF3D19F5D7410A0A31_marshaled_com ___scriptInfo;
};
struct EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 
{
	RenderData_t1ABE116B2B5E0409AC699E195922516606531DC2* ___renderData;
	int32_t ___type;
	Entry_t475ED76E31923970E7F7A6522E570E7577C487B9* ___rootEntry;
};
struct EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289_marshaled_pinvoke
{
	RenderData_t1ABE116B2B5E0409AC699E195922516606531DC2* ___renderData;
	int32_t ___type;
	Entry_t475ED76E31923970E7F7A6522E570E7577C487B9* ___rootEntry;
};
struct EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289_marshaled_com
{
	RenderData_t1ABE116B2B5E0409AC699E195922516606531DC2* ___renderData;
	int32_t ___type;
	Entry_t475ED76E31923970E7F7A6522E570E7577C487B9* ___rootEntry;
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 
{
	bool ___isBorderJob;
	uint8_t ___phase;
	NativeRectParams_t18E2E456D50F027D08BF8B4BCBD83DF7FDB1C02F ___rectParams;
	BorderParams_tA3F0684BE19E681B68F40A773737978EB3FD1509 ___borderParams;
	UnsafeMeshGenerationNode_t1FF7D38D9B39DC59A2F8E2DFC92BFAB2481E88A2 ___node;
};
struct TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2_marshaled_pinvoke
{
	int32_t ___isBorderJob;
	uint8_t ___phase;
	NativeRectParams_t18E2E456D50F027D08BF8B4BCBD83DF7FDB1C02F ___rectParams;
	BorderParams_tA3F0684BE19E681B68F40A773737978EB3FD1509_marshaled_pinvoke ___borderParams;
	UnsafeMeshGenerationNode_t1FF7D38D9B39DC59A2F8E2DFC92BFAB2481E88A2 ___node;
};
struct TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2_marshaled_com
{
	int32_t ___isBorderJob;
	uint8_t ___phase;
	NativeRectParams_t18E2E456D50F027D08BF8B4BCBD83DF7FDB1C02F ___rectParams;
	BorderParams_tA3F0684BE19E681B68F40A773737978EB3FD1509_marshaled_com ___borderParams;
	UnsafeMeshGenerationNode_t1FF7D38D9B39DC59A2F8E2DFC92BFAB2481E88A2 ___node;
};
struct Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF 
{
	UnsafeMeshGenerationNode_t1FF7D38D9B39DC59A2F8E2DFC92BFAB2481E88A2 ___node;
	int32_t ___snapshotIndex;
	intptr_t ___vectorImagePtr;
	intptr_t ___texturePtr;
	int32_t ___userData;
};
struct Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 
{
	NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF ___array;
	int32_t ___used;
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
	RuntimeObject* ____actualValue;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093_StaticFields
{
	ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093 ___U3CEmptyU3Ek__BackingField;
};
struct ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3_StaticFields
{
	ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3 ___U3CEmptyU3Ek__BackingField;
};
struct ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178_StaticFields
{
	ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178 ___U3CEmptyU3Ek__BackingField;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
struct UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484_StaticFields
{
	RuntimeObject* ___comparer;
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
struct RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE  : public RuntimeArray
{
	ALIGN_FIELD (8) RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C m_Items[1];

	inline RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C value)
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
struct TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE  : public RuntimeArray
{
	ALIGN_FIELD (8) TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 m_Items[1];

	inline TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 value)
	{
		m_Items[index] = value;
	}
};
struct AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F  : public RuntimeArray
{
	ALIGN_FIELD (8) AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB m_Items[1];

	inline AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___alloc))->___handle), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___page), (void*)NULL);
		#endif
	}
	inline AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___alloc))->___handle), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___page), (void*)NULL);
		#endif
	}
};
struct AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C  : public RuntimeArray
{
	ALIGN_FIELD (8) AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 m_Items[1];

	inline AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___meshHandle), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___permAllocVerts))->___handle), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___permAllocIndices))->___handle), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___permPage), (void*)NULL);
		#endif
	}
	inline AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___meshHandle), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___permAllocVerts))->___handle), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___permAllocIndices))->___handle), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___permPage), (void*)NULL);
		#endif
	}
};
struct Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44  : public RuntimeArray
{
	ALIGN_FIELD (8) Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF m_Items[1];

	inline Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF value)
	{
		m_Items[index] = value;
	}
};
struct BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE  : public RuntimeArray
{
	ALIGN_FIELD (8) BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B m_Items[1];

	inline BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B value)
	{
		m_Items[index] = value;
	}
};
struct SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F  : public RuntimeArray
{
	ALIGN_FIELD (8) SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 m_Items[1];

	inline SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___sceneGUID), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___cellList), (void*)NULL);
		#endif
	}
	inline SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___sceneGUID), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___cellList), (void*)NULL);
		#endif
	}
};
struct ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3  : public RuntimeArray
{
	ALIGN_FIELD (8) ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 m_Items[1];

	inline ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___scenario), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___data))->___cellDataAsset), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___data))->___cellOptionalDataAsset), (void*)NULL);
		#endif
	}
	inline ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___scenario), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___data))->___cellDataAsset), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___data))->___cellOptionalDataAsset), (void*)NULL);
		#endif
	}
};
struct StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7  : public RuntimeArray
{
	ALIGN_FIELD (8) StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A m_Items[1];

	inline StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A value)
	{
		m_Items[index] = value;
	}
};
struct SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6  : public RuntimeArray
{
	ALIGN_FIELD (8) SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC m_Items[1];

	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC value)
	{
		m_Items[index] = value;
	}
};
struct ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB  : public RuntimeArray
{
	ALIGN_FIELD (8) ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 m_Items[1];

	inline ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___element), (void*)NULL);
	}
	inline ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___element), (void*)NULL);
	}
};
struct MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3  : public RuntimeArray
{
	ALIGN_FIELD (8) MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 m_Items[1];

	inline MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 value)
	{
		m_Items[index] = value;
	}
};
struct TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322  : public RuntimeArray
{
	ALIGN_FIELD (8) TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 m_Items[1];

	inline TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___fullName), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___transform), (void*)NULL);
		#endif
	}
	inline TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___fullName), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___transform), (void*)NULL);
		#endif
	}
};
struct PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4  : public RuntimeArray
{
	ALIGN_FIELD (8) Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 m_Items[1];

	inline Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 value)
	{
		m_Items[index] = value;
	}
};
struct AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8  : public RuntimeArray
{
	ALIGN_FIELD (8) AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF m_Items[1];

	inline AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ElementName), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_NamesPath), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_AttributeName), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Value), (void*)NULL);
		#endif
	}
	inline AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ElementName), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_NamesPath), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_AttributeName), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Value), (void*)NULL);
		#endif
	}
};
struct UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A  : public RuntimeArray
{
	ALIGN_FIELD (8) UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 m_Items[1];

	inline UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ElementIdsPath), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_SerializedData), (void*)NULL);
		#endif
	}
	inline UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ElementIdsPath), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_SerializedData), (void*)NULL);
		#endif
	}
};
struct FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118  : public RuntimeArray
{
	ALIGN_FIELD (8) FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 m_Items[1];

	inline FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___font), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___fontAsset), (void*)NULL);
		#endif
	}
	inline FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___font), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___fontAsset), (void*)NULL);
		#endif
	}
};
struct BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA  : public RuntimeArray
{
	ALIGN_FIELD (8) BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 m_Items[1];

	inline BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___src), (void*)NULL);
	}
	inline BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___src), (void*)NULL);
	}
};
struct FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25  : public RuntimeArray
{
	ALIGN_FIELD (8) Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD m_Items[1];

	inline Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___filename), (void*)NULL);
	}
	inline Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___filename), (void*)NULL);
	}
};
struct TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83  : public RuntimeArray
{
	ALIGN_FIELD (8) TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B m_Items[1];

	inline TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___texture), (void*)NULL);
	}
	inline TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___texture), (void*)NULL);
	}
};
struct RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279  : public RuntimeArray
{
	ALIGN_FIELD (8) RaycastHitData_t5EAB266730389AB27715962670C2512800451841 m_Items[1];

	inline RaycastHitData_t5EAB266730389AB27715962670C2512800451841 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RaycastHitData_t5EAB266730389AB27715962670C2512800451841* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CgraphicU3Ek__BackingField), (void*)NULL);
	}
	inline RaycastHitData_t5EAB266730389AB27715962670C2512800451841 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RaycastHitData_t5EAB266730389AB27715962670C2512800451841* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CgraphicU3Ek__BackingField), (void*)NULL);
	}
};
struct WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577  : public RuntimeArray
{
	ALIGN_FIELD (8) WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 m_Items[1];

	inline WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_DelagateCallback), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_DelagateState), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_WaitHandle), (void*)NULL);
		#endif
	}
	inline WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_DelagateCallback), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_DelagateState), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_WaitHandle), (void*)NULL);
		#endif
	}
};
struct AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F  : public RuntimeArray
{
	ALIGN_FIELD (8) AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D m_Items[1];

	inline AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Path), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_TypeFullName), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_CachedType), (void*)NULL);
		#endif
	}
	inline AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Path), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_TypeFullName), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_CachedType), (void*)NULL);
		#endif
	}
};
struct SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299  : public RuntimeArray
{
	ALIGN_FIELD (8) SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 m_Items[1];

	inline SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
	}
	inline SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
	}
};
struct SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A  : public RuntimeArray
{
	ALIGN_FIELD (8) SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 m_Items[1];

	inline SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___slotName), (void*)NULL);
	}
	inline SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___slotName), (void*)NULL);
	}
};
struct UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811  : public RuntimeArray
{
	ALIGN_FIELD (8) UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 m_Items[1];

	inline UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___alias), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___path), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___asset), (void*)NULL);
		#endif
	}
	inline UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___alias), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___path), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___asset), (void*)NULL);
		#endif
	}
};
struct VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64  : public RuntimeArray
{
	ALIGN_FIELD (8) VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 m_Items[1];

	inline VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___source), (void*)NULL);
	}
	inline VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___source), (void*)NULL);
	}
};
struct PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA  : public RuntimeArray
{
	ALIGN_FIELD (8) PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 m_Items[1];

	inline PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 value)
	{
		m_Items[index] = value;
	}
};
struct XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27  : public RuntimeArray
{
	ALIGN_FIELD (8) XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD m_Items[1];

	inline XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___qname), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___xso), (void*)NULL);
		#endif
	}
	inline XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___qname), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___xso), (void*)NULL);
		#endif
	}
};
struct VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F  : public RuntimeArray
{
	ALIGN_FIELD (8) VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E m_Items[1];

	inline VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___nameAndTooltip))->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___nameAndTooltip))->___tooltip), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___volumeProfile), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___volumeComponent), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___volume), (void*)NULL);
		#endif
	}
	inline VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___nameAndTooltip))->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___nameAndTooltip))->___tooltip), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___volumeProfile), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___volumeComponent), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___volume), (void*)NULL);
		#endif
	}
};
struct ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279  : public RuntimeArray
{
	ALIGN_FIELD (8) ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 m_Items[1];

	inline ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___displayName), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___action), (void*)NULL);
		#endif
	}
	inline ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___displayName), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___action), (void*)NULL);
		#endif
	}
};
struct LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E  : public RuntimeArray
{
	ALIGN_FIELD (8) LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 m_Items[1];

	inline LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___layoutName))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___layoutName))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___deviceMatcher))->___m_Patterns), (void*)NULL);
		#endif
	}
	inline LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___layoutName))->___m_StringOriginalCase), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___layoutName))->___m_StringLowerCase), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___deviceMatcher))->___m_Patterns), (void*)NULL);
		#endif
	}
};
struct InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3  : public RuntimeArray
{
	ALIGN_FIELD (8) InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D m_Items[1];

	inline InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____instruction), (void*)NULL);
		#endif
	}
	inline InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____instruction), (void*)NULL);
		#endif
	}
};
struct PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC  : public RuntimeArray
{
	ALIGN_FIELD (8) PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F m_Items[1];

	inline PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___resourceReadLists), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___resourceWriteLists), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___nrpInfo), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___scriptInfo))->___filePath), (void*)NULL);
		#endif
	}
	inline PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___resourceReadLists), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___resourceWriteLists), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___nrpInfo), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___scriptInfo))->___filePath), (void*)NULL);
		#endif
	}
};
struct ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B  : public RuntimeArray
{
	ALIGN_FIELD (8) ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 m_Items[1];

	inline ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___consumerList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___producerList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___textureData), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___bufferData), (void*)NULL);
		#endif
	}
	inline ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___name), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___consumerList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___producerList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___textureData), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___bufferData), (void*)NULL);
		#endif
	}
};
struct EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B  : public RuntimeArray
{
	ALIGN_FIELD (8) EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 m_Items[1];

	inline EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___renderData), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___rootEntry), (void*)NULL);
		#endif
	}
	inline EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___renderData), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___rootEntry), (void*)NULL);
		#endif
	}
};
struct PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317  : public RuntimeArray
{
	ALIGN_FIELD (8) PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 m_Items[1];

	inline PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___message), (void*)NULL);
	}
	inline PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___message), (void*)NULL);
	}
};
struct KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57  : public RuntimeArray
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
struct DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533  : public RuntimeArray
{
	ALIGN_FIELD (8) DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB m_Items[1];

	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____value), (void*)NULL);
		#endif
	}
	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____value), (void*)NULL);
		#endif
	}
};
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
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
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppChar m_Items[1];

	inline Il2CppChar GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppChar value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Il2CppChar GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppChar value)
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


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8E1E04E7BBAF15EB7C047EB1D2C195918CA0881A (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m79537AB29BC45B039EC2EC8C4D1676D1E99050EE (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m0AB43B74EC42C2031FB99692031B34C176E6DC2E (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m7AC9BA5BEB59068FAA7EFADA5EBB80B85D400A74 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mFF8DC212CA14B1BAD190433D8A39325EB8F8692A (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m162020E379E108D3B9A4607E90AC6CB7999E2906 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6AFC7D4D548E6DEF9AF986FB86F1AE3805653785 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2A11348B3EFD6DF36D28D99228DBB7447B2ED8C2 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mB3B7A3A0C879250FA0A51533B5FAFAEC745B059A (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m25436CDFD278C3404F78E12A10F35D98681429B6 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC42D7F66712159450A3E1581D1C447DA781D6ABB (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m05E6B9F938D84C399B9B3B0D32121EADFE6060D1 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m66D6D55666245CDEE1E9897829324A1F2755D07F (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mCEEBE7AC91128582C3C0FB0DE3F98528829728C9 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m50631914758AD83F933C8C58C9C56181167206EF (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC2583A3BBC34282E2E0D92456C65DAC815328002 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mA923C6AA7115FB17D5F43D8F5EFAB906CD573191 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m17EE888747F53315F45BD98410940E0BC662DFB9 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91259BF5D56B9D4993F7E2209D58F860DC46FD2A (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4959B727178367FB71DDF85183AE6B42896A6968 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE31E6450162F6E9B618AAC3AC422BA73138F2DF2 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m1584B4A5D71D0BD68DC0B608E63CE74E81094A13 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3E387EA2DD8EE68F91476C1CFC4FB56DB16FE901 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB2EE20AD2CF899F6D963C508EB10B05E9DBAAFD1 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m2278DB015831D3852A1ECDC9C8E44CA52E94A010 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m6679EEE84E9BBDBE8761CF44B8294155AB69A45E (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB732A9E350D9E3CD2C7840CC90E0CD38529A5C1C (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m002E2463EC869D6B730B00CF9A1A973007B41B35 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m98DEFEBAE637436EEDC27C55AE2C19B076DE090F (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2762EABC097FB2A997370146E5E61C2A197552CE (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6453D07CDC6264E9F4FEBF425DFA817487EE9723 (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB98D3656FF7E5F1A67C4FB181C9A4A3D309087FA (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m2CC3246BF9378F698D206586E815F940BDFF3A4F (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAD7E8A171AFE7CD86454D7E8BFDE0CD9D216060C (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m47AEA24C0ACE4F3899592E7466AEEAEC7C8677AB (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2C11317DDF1B10C32280199980586FF267E163F6 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mD9D82410CB95D4FE5C14BACB7022BFC0B090CB23 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mA31AC1D905D65EE27428ABA47C90CFA51CA93BA8 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m913E4228E930667ED05C69E275781B4D65AD6377 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m05146C24F41FA016ABE609031F1CCDF60E768619 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m95E8E1F55501F640B52A5AD4E73DE9CB674CA074 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAB1EFE8A5D353B131BBE9EB34B74A6BAE06F9599 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m983620D9F4A7313CEB1B1AEFFEDC8DB2DF1600F3 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mAB5A5EADC7E5E50497A3B7584352D42B28CE3C69 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0EEB9CC7A903E35B3737942EFF99016D288DDED6 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0DDEE58D13E8FB5B2766AC7DA0C55DAC13584B77 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC67C7EF96296B0DE1C19FDEEDBABA0FFBD67CB03 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m716BA7D21054B1D77515F421EE50AD75DB3EACBE (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8DB78ECCD7FE15165D37E8B1BEE1E0CE961646B8 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0E3D36FD434C8509FA5456EC472A90892333EBB3 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m41DE6354C6777FCC2A9A07D4EEBA1EDED633DF95 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB3BC65B35BADE231093A41C12901EA81455B7C7A (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mF8F286601D8EED13DACAB99C02259324E49C6DA1 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m95712CD049C6EEB0E90DB244AC3171FA85166DB6 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m947A3FA40F7BF31EEE550BB315172BE53B38F22F (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m0A4F50958D471DC760F266D8D2A1EE200DF52C2E (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mBB2B7BF08D287E2667F29836FCF9E439551DBE8F (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m11348500F34A92ED3E4F57AA0233784078379771 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m638A809E5C72AB15EDA998647FE19E464E709DEF (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC3926319976609BD7A37B3FD87A61906A26C54B6 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE24114E67C1515ED8C4F81DBE65B00B6B917A279 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m5F2B05B1740F553E40DFC6DED6A468B45B9316FF (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m23A5C68995E101E0D2EB2F9483D609514BBDBD2E (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE9844C779BE6775172325AFACCE26458ABB4B8C0 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m294CA4038F05C8500E78F059A44B5C74556DBBF8 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFCD2A54038776E3951F71F390645766807267DE5 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m07FD564014E69D4B40CE0B12AFAA93929EC83137 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB2559896BC5F11800B0108BEBA9EAB2A6C95EE0F (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m9759E4E426E53E8DD9400478BA7D6F81C7045498 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m77E7B5A08971CD505FF41765E78B811AAB31B492 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF080F0FA34F8F5E175F6E4DEDD178B75394CF519 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2B98BD0E648DADFDD364421B9F9FC9936A394B91 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m9755643A08D11F86D78C24879A20FA6B7A92EF03 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8408613E90585C543FF86E0D19765A06036A7DB1 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3950355F5CE2667D4D6E45F1236436E1D59D65BA (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE665276036AA8B4551F37184CDA5DB0F5FB3E144 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mA3718CBDAD334D0C3B3B3D9C2FBFFC64CB9C1280 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD22DEE1877768FD46CF1D7BE9E64A9BBF4762858 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m226D99000078C09F61A5D23C9D572EEFD2C1F3AB (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m38FC28A8D172A809848EBBE17B7593C9A4AC5309 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0AFB680989F7183252C477DD7EB9EF59D9C88ECC (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m052B85911C70FD4FE70D220FF791FAF6C6479F83 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m37A8647602E0715AC27FDFF43DABCCEF7701AEAB (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE1ABD3A991704C640186283F3DD505E3B9A77BB6 (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m409F5776BEB430BE72273C433CC1850CD93700A7 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m297F49BCB3FD33C8DE274BA917FFF7B708758DB7 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mDF174A6917D3D93C8D7910C91080D253891A1AC5 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC7204EA734A903659BFE12EFC2FD358391419441 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m31B5E7F8E3D51CB370BE05608F7B2C3C11EE0C55 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m496DFF37E9CC6DE59F0E2B4E2A5DBEAA32DEAD94 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6057F27D1ACAA9CBF4A9FFC87FDAA2ACC117A809 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD865206564138ED88C746288B0A9A6EB96555FC2 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m15D679310A0AC97586C8124180F5EB3E1D40A2BC (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m948DB26D5A8A2DF64E9700A6DEB6F836B10749A3 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9ADA09E692C504A400AF0D8E4BF59A7C3C2C8F93 (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m942BE9C1C9D8A0392F495981442E058E887308CF (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m299B4E260E97612F6BFD1965863F5EDB0D80889F (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mBF48FC95A670E75A65647A9F7520AEB9AE4A0FE6 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m705B2717517A6E1493976E0F972CEC791692FF97 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mBE061D69DECDF68D566C15E465E25ECFCE11FCD3 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m05F05C64F32981A1BF2CEC3E7589604A188B612B (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mBA2972FFD773AA00EC4BAD22D43C97C5FFFD31EA (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD887308D8602D0A6C687F8B588F772CB0D0911A2 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mCC0B8F0541328E20D9E516ACE2AF53B44AA502ED (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCB408C9C0EF8BB4EAF3BD9D74210EA1BF645DF9F (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mCB5B8ABED8FAA81E9313462E91E846577DBF79E7 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mA07C916646443F7E600B771BA5B6E3276CF6F38D (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m24635AF1EE0DBE26C00D1E919C331F3EC3514442 (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m95888730659343F372198CD5B3EE35B001150127 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE94C5A9A40442783E8EE309CDBA6395F4842EEB3 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m25DB18C9E908096B821F4C692B9190E3B812A1FA (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4D6C6D23DE1E2EE6057F94BDBD946631CC5B2EBC (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCB4FF2AFAA94D01923F9242ACB66F817F7CF18C7 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC5B4A17FCA21C2DF1F66767E828535AD34B90513 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m116AE421F0EB30927F6725D62792FFA5A6065627 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mF523F5C22B1C3DFB9577177B1C50F9DC3B9704C2 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8458978F11950358DAF515D9793F94E96E164867 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0F15E0EC055DA3F521E73184206A61A28D6E1C0F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mE296E176CF781CFBEDEA890CD7B7438707C5CBC2 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m25AC6AFADC9DA3C7616FB3DF2538489069FE82FF (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCFEB25EF1344B976A050CB6937362A3F5DF0199A (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m3A0010FDAC2908AF80DDEB4BA4458869F0FE9F8F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3CAC4C8BA133B39A5BA9FA0A1E0E711E09BD7694 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE8080B23EA1AD670E7D7D77D172A6973A222ED2C (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m88DC99D667337D16893CDF63694D22FEAF331E05 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m9E692C71C0193F22ACD65EEFBA4ECA75E5C53AAD (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9FE5CCC2B059229D4C97248D4F5E82C20ECB5FBE (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m093DAAF13F65B6DE09B24D00F36FCC13F61E6E15 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m283266AC4D77DC2424BDBD9CB125A1A61AB55E1C (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD7979063F69DBCBBA075F88868B40DE92ED347FC (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m7535255C244884FCE69E71A597A10D82C38A21AB (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m07CEF5EB192EFDA22EC079165EEE0F82A03E5FD7 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m818A3E47FE33091DD1275D2DFDF70695E715E185 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m9E090EF8DAC5EB1362F55C11AC2FD29FE307A954 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3006B42AEF364FAED734490926CA034ED5348569 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4D42E127F9A2F6A6D223785F8CA656A4930B87C2 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0730B9BAC8092A41B1C48042F79C306FD18E553F (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m718A868545EA0ABD0015911A27C3815E8A95752D (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD6916963F70388076B4D8A005C8C1AC7DB630642 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mEAC3EE66A5CB94BE471210EA64A682C55D8463D0 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8B2AEA509E07E389B797D3576C0DDF9A5551E3A4 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC9A90AF46B6E7EC8BC710283B87EB110801FAB1B (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD750C5DD43B49E3369FF1CC3778B43D83F58636E (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mDA0A610D1FE508DC17DABD5A4D5D861295857416 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m5BD62585103C935CC4B20021B610D1D480BE6F19 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC38E543F0BA4C1931B8FDCDA225802CE37FBD971 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC061A8BAB0855DF9F3365468CFE7C6897B27DB66 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m91DD8D51560F4B4A6690B2B4DCF114816973A693 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DictionaryEnumerator__ctor_mA1A62AF5ED8AB1B514BBAAAEA9BB3D081C3AA4ED_fshared (DictionaryEnumerator_tA07B53C91CCF243B3DDF48825CD4F71A6835CD77* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_mD82E516936D2BDE6D46C8C45270250647986231E_fshared (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* __this, Il2CppFullySharedGenericAny ___0_key, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ArraySegment_1_get_Array_mE4A35DFD81ABF447350B9A05C0F4BF0248A3CFF2_fshared_inline (ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ArraySegment_1_get_Offset_m4FAFF061AB36BF278BA8DC37B6D13718A06301E6_fshared_inline (ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ArraySegment_1_get_Count_mEF96248898C14F3687A5C72B920F841701E4E13C_fshared_inline (ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlyMemory_1__ctor_m1FD19CA8A2CB8A92DC095EE34D414ADE2FD39A12_fshared_inline (ReadOnlyMemory_1_t192441E248CAB66088AAEDBD64DFEE110ADBEED4* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlyMemory_1_ToString_m0C4DF727B39C613F84AC56D6FDAF7ACFF9E39720 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m9D8BA8245B8DC9BFB4A4164759CBAAEAD1318CD6_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC Span_1_op_Implicit_m704A5B9FD25EEA23756181A8EB40B875387A6C01_fshared (Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 ___0_span, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m7B5C2765879EA5E8D1617D834CC465A39540A913_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ReadOnlyMemory_1_get_Span_mA087C8160638E6581A03C1BDAF2803AC88834762_inline (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Memory_1_get_Span_mA0CAB13956D6FA3BBF9F9176CB647933F88E034E_inline (Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlySpan_1_CopyTo_m8144AA3941DF7B7C2C665680221977E1D15D1462 (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_destination, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlySpan_1_TryCopyTo_m2C902AB57D2363B06C42BDDE761F3E0DFD5541B3 (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_destination, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ReadOnlySpan_1_ToArray_mF805FAE3816BCFA5C63592CA173237F9B1E4566E (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_Equals_mF7DA75997B4FFDFB2D6F953E8DC580EC3C941A61_fshared (ReadOnlyMemory_1_t192441E248CAB66088AAEDBD64DFEE110ADBEED4* __this, ReadOnlyMemory_1_t192441E248CAB66088AAEDBD64DFEE110ADBEED4 ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyMemory_1_t192441E248CAB66088AAEDBD64DFEE110ADBEED4 Memory_1_op_Implicit_m7216145178505C2CB2BA0E21CB95773BE1E6A7AF_fshared (Memory_1_t762D61B435521D1706EEDC25CA8C8EA1AE19AFEA ___0_memory, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_Equals_mD0C4947B91FD3864C476B6CA8BA929A6F5B01175 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_CombineHashCodes_mC20EA69C2706DE824529A0506BD45837E26C6980 (int32_t ___0_h1, int32_t ___1_h2, int32_t ___2_h3, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_GetHashCode_mE47597BBDBFFBC9185DE65261A7388207854ADE6 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_CombineHashCodes_m74D5DE9AF0CCB1FF7B88058328C835DBD981C568_fshared (int32_t ___0_left, int32_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA_inline (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlySpan_1_ToString_mB13A913EF211B14B719EE62133C15C298642E34D (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlyMemory_1_ToString_m4676D3AFBC120B54C2B53171F9C7DE3B4E753F68 (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mFA6EE52BCF39100AE30C79E73F0F972182D0CA2A_fshared_inline (ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC* __this, Il2CppFullySharedGenericAny* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 ReadOnlySpan_1_Slice_mDEEA4C304B13C8F7A63BC3D60B62FF17BBEE282B_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mDADE08E6B4594775C6675B389078E5FE98C745D5_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Memory_1_get_Span_m926BDF0BE2BAC67BB057415AE70537AFCB4FE3B8_inline (Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlySpan_1_CopyTo_m42F1668DECE40277D97A37705EA6BE27CF7D5030 (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_destination, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlySpan_1_TryCopyTo_m22E885FE905F1306DDE8000F155109F7F4987666 (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_destination, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ReadOnlySpan_1_ToArray_m3CC38C41E9FB235D0C9D24033DE4D561B1017488 (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_Equals_mE4EA5DC4ACF51E07F85C4A55A3281E580903506F (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_CombineHashCodes_m90089D22A29124B5DFB7253B5795FBBBA2E17BC1 (int32_t ___0_h1, int32_t ___1_h2, int32_t ___2_h3, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_GetHashCode_m7D885665B2C6E9B5B157129A6CCAFC4938400D0D (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mBA868F06359701D9950DEB1B10F52F848E9FF6DA_fshared_inline (Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54* __this, Il2CppFullySharedGenericAny* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m698EC79E2E44AFF16BA096D0861CFB129FBF8218_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m5BFF79141064122141ED34283347A634B9DF577D_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC (int32_t ___0_argument, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA (int32_t ___0_resource, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC (RuntimeArray* __this, int32_t ___0_dimension, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8E1E04E7BBAF15EB7C047EB1D2C195918CA0881A (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m79537AB29BC45B039EC2EC8C4D1676D1E99050EE (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m0AB43B74EC42C2031FB99692031B34C176E6DC2E (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m7AC9BA5BEB59068FAA7EFADA5EBB80B85D400A74 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mFF8DC212CA14B1BAD190433D8A39325EB8F8692A (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m162020E379E108D3B9A4607E90AC6CB7999E2906 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6AFC7D4D548E6DEF9AF986FB86F1AE3805653785 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2A11348B3EFD6DF36D28D99228DBB7447B2ED8C2 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mB3B7A3A0C879250FA0A51533B5FAFAEC745B059A (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m25436CDFD278C3404F78E12A10F35D98681429B6 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC42D7F66712159450A3E1581D1C447DA781D6ABB (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m05E6B9F938D84C399B9B3B0D32121EADFE6060D1 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m66D6D55666245CDEE1E9897829324A1F2755D07F (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mCEEBE7AC91128582C3C0FB0DE3F98528829728C9 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m50631914758AD83F933C8C58C9C56181167206EF (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC2583A3BBC34282E2E0D92456C65DAC815328002 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mA923C6AA7115FB17D5F43D8F5EFAB906CD573191 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m17EE888747F53315F45BD98410940E0BC662DFB9 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91259BF5D56B9D4993F7E2209D58F860DC46FD2A (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4959B727178367FB71DDF85183AE6B42896A6968 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE31E6450162F6E9B618AAC3AC422BA73138F2DF2 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m1584B4A5D71D0BD68DC0B608E63CE74E81094A13 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3E387EA2DD8EE68F91476C1CFC4FB56DB16FE901 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB2EE20AD2CF899F6D963C508EB10B05E9DBAAFD1 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m2278DB015831D3852A1ECDC9C8E44CA52E94A010 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m6679EEE84E9BBDBE8761CF44B8294155AB69A45E (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB732A9E350D9E3CD2C7840CC90E0CD38529A5C1C (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m002E2463EC869D6B730B00CF9A1A973007B41B35 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m98DEFEBAE637436EEDC27C55AE2C19B076DE090F (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2762EABC097FB2A997370146E5E61C2A197552CE (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6453D07CDC6264E9F4FEBF425DFA817487EE9723 (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB98D3656FF7E5F1A67C4FB181C9A4A3D309087FA (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m2CC3246BF9378F698D206586E815F940BDFF3A4F (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAD7E8A171AFE7CD86454D7E8BFDE0CD9D216060C (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m47AEA24C0ACE4F3899592E7466AEEAEC7C8677AB (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2C11317DDF1B10C32280199980586FF267E163F6 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mD9D82410CB95D4FE5C14BACB7022BFC0B090CB23 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mA31AC1D905D65EE27428ABA47C90CFA51CA93BA8 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m913E4228E930667ED05C69E275781B4D65AD6377 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m05146C24F41FA016ABE609031F1CCDF60E768619 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m95E8E1F55501F640B52A5AD4E73DE9CB674CA074 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAB1EFE8A5D353B131BBE9EB34B74A6BAE06F9599 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m983620D9F4A7313CEB1B1AEFFEDC8DB2DF1600F3 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mAB5A5EADC7E5E50497A3B7584352D42B28CE3C69 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0EEB9CC7A903E35B3737942EFF99016D288DDED6 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0DDEE58D13E8FB5B2766AC7DA0C55DAC13584B77 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC67C7EF96296B0DE1C19FDEEDBABA0FFBD67CB03 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m716BA7D21054B1D77515F421EE50AD75DB3EACBE (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8DB78ECCD7FE15165D37E8B1BEE1E0CE961646B8 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0E3D36FD434C8509FA5456EC472A90892333EBB3 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m41DE6354C6777FCC2A9A07D4EEBA1EDED633DF95 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB3BC65B35BADE231093A41C12901EA81455B7C7A (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mF8F286601D8EED13DACAB99C02259324E49C6DA1 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m95712CD049C6EEB0E90DB244AC3171FA85166DB6 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m947A3FA40F7BF31EEE550BB315172BE53B38F22F (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m0A4F50958D471DC760F266D8D2A1EE200DF52C2E (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mBB2B7BF08D287E2667F29836FCF9E439551DBE8F (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m11348500F34A92ED3E4F57AA0233784078379771 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m638A809E5C72AB15EDA998647FE19E464E709DEF (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC3926319976609BD7A37B3FD87A61906A26C54B6 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE24114E67C1515ED8C4F81DBE65B00B6B917A279 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m5F2B05B1740F553E40DFC6DED6A468B45B9316FF (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m23A5C68995E101E0D2EB2F9483D609514BBDBD2E (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE9844C779BE6775172325AFACCE26458ABB4B8C0 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m294CA4038F05C8500E78F059A44B5C74556DBBF8 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFCD2A54038776E3951F71F390645766807267DE5 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m07FD564014E69D4B40CE0B12AFAA93929EC83137 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB2559896BC5F11800B0108BEBA9EAB2A6C95EE0F (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m9759E4E426E53E8DD9400478BA7D6F81C7045498 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m77E7B5A08971CD505FF41765E78B811AAB31B492 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF080F0FA34F8F5E175F6E4DEDD178B75394CF519 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2B98BD0E648DADFDD364421B9F9FC9936A394B91 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m9755643A08D11F86D78C24879A20FA6B7A92EF03 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8408613E90585C543FF86E0D19765A06036A7DB1 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3950355F5CE2667D4D6E45F1236436E1D59D65BA (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE665276036AA8B4551F37184CDA5DB0F5FB3E144 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mA3718CBDAD334D0C3B3B3D9C2FBFFC64CB9C1280 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD22DEE1877768FD46CF1D7BE9E64A9BBF4762858 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m226D99000078C09F61A5D23C9D572EEFD2C1F3AB (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m38FC28A8D172A809848EBBE17B7593C9A4AC5309 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0AFB680989F7183252C477DD7EB9EF59D9C88ECC (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m052B85911C70FD4FE70D220FF791FAF6C6479F83 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m37A8647602E0715AC27FDFF43DABCCEF7701AEAB (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE1ABD3A991704C640186283F3DD505E3B9A77BB6 (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m409F5776BEB430BE72273C433CC1850CD93700A7 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m297F49BCB3FD33C8DE274BA917FFF7B708758DB7 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mDF174A6917D3D93C8D7910C91080D253891A1AC5 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC7204EA734A903659BFE12EFC2FD358391419441 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m31B5E7F8E3D51CB370BE05608F7B2C3C11EE0C55 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m496DFF37E9CC6DE59F0E2B4E2A5DBEAA32DEAD94 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6057F27D1ACAA9CBF4A9FFC87FDAA2ACC117A809 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD865206564138ED88C746288B0A9A6EB96555FC2 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m15D679310A0AC97586C8124180F5EB3E1D40A2BC (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m948DB26D5A8A2DF64E9700A6DEB6F836B10749A3 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9ADA09E692C504A400AF0D8E4BF59A7C3C2C8F93 (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m942BE9C1C9D8A0392F495981442E058E887308CF (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m299B4E260E97612F6BFD1965863F5EDB0D80889F (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mBF48FC95A670E75A65647A9F7520AEB9AE4A0FE6 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m705B2717517A6E1493976E0F972CEC791692FF97 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mBE061D69DECDF68D566C15E465E25ECFCE11FCD3 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m05F05C64F32981A1BF2CEC3E7589604A188B612B (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mBA2972FFD773AA00EC4BAD22D43C97C5FFFD31EA (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD887308D8602D0A6C687F8B588F772CB0D0911A2 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mCC0B8F0541328E20D9E516ACE2AF53B44AA502ED (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCB408C9C0EF8BB4EAF3BD9D74210EA1BF645DF9F (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mCB5B8ABED8FAA81E9313462E91E846577DBF79E7 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mA07C916646443F7E600B771BA5B6E3276CF6F38D (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m24635AF1EE0DBE26C00D1E919C331F3EC3514442 (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m95888730659343F372198CD5B3EE35B001150127 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE94C5A9A40442783E8EE309CDBA6395F4842EEB3 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m25DB18C9E908096B821F4C692B9190E3B812A1FA (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4D6C6D23DE1E2EE6057F94BDBD946631CC5B2EBC (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCB4FF2AFAA94D01923F9242ACB66F817F7CF18C7 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC5B4A17FCA21C2DF1F66767E828535AD34B90513 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m116AE421F0EB30927F6725D62792FFA5A6065627 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mF523F5C22B1C3DFB9577177B1C50F9DC3B9704C2 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8458978F11950358DAF515D9793F94E96E164867 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0F15E0EC055DA3F521E73184206A61A28D6E1C0F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mE296E176CF781CFBEDEA890CD7B7438707C5CBC2 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m25AC6AFADC9DA3C7616FB3DF2538489069FE82FF (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCFEB25EF1344B976A050CB6937362A3F5DF0199A (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m3A0010FDAC2908AF80DDEB4BA4458869F0FE9F8F (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3CAC4C8BA133B39A5BA9FA0A1E0E711E09BD7694 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE8080B23EA1AD670E7D7D77D172A6973A222ED2C (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m88DC99D667337D16893CDF63694D22FEAF331E05 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m9E692C71C0193F22ACD65EEFBA4ECA75E5C53AAD (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9FE5CCC2B059229D4C97248D4F5E82C20ECB5FBE (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m093DAAF13F65B6DE09B24D00F36FCC13F61E6E15 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m283266AC4D77DC2424BDBD9CB125A1A61AB55E1C (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD7979063F69DBCBBA075F88868B40DE92ED347FC (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m7535255C244884FCE69E71A597A10D82C38A21AB (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m07CEF5EB192EFDA22EC079165EEE0F82A03E5FD7 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m818A3E47FE33091DD1275D2DFDF70695E715E185 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m9E090EF8DAC5EB1362F55C11AC2FD29FE307A954 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3006B42AEF364FAED734490926CA034ED5348569 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4D42E127F9A2F6A6D223785F8CA656A4930B87C2 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0730B9BAC8092A41B1C48042F79C306FD18E553F (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m718A868545EA0ABD0015911A27C3815E8A95752D (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD6916963F70388076B4D8A005C8C1AC7DB630642 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mEAC3EE66A5CB94BE471210EA64A682C55D8463D0 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8B2AEA509E07E389B797D3576C0DDF9A5551E3A4 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC9A90AF46B6E7EC8BC710283B87EB110801FAB1B (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD750C5DD43B49E3369FF1CC3778B43D83F58636E (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mDA0A610D1FE508DC17DABD5A4D5D861295857416 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m5BD62585103C935CC4B20021B610D1D480BE6F19 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC38E543F0BA4C1931B8FDCDA225802CE37FBD971 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC061A8BAB0855DF9F3365468CFE7C6897B27DB66 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m91DD8D51560F4B4A6690B2B4DCF114816973A693 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
inline void DictionaryEnumerator__ctor_mA1A62AF5ED8AB1B514BBAAAEA9BB3D081C3AA4ED (DictionaryEnumerator_tA07B53C91CCF243B3DDF48825CD4F71A6835CD77* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (DictionaryEnumerator_tA07B53C91CCF243B3DDF48825CD4F71A6835CD77*, RuntimeObject*, const RuntimeMethod*))DictionaryEnumerator__ctor_mA1A62AF5ED8AB1B514BBAAAEA9BB3D081C3AA4ED_fshared)(__this, ___0_dictionary, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_mE5B2755F0BEA043CACF915D5CE140859EE58FA66 (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, String_t* ___1_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
inline void KeyValuePair_2__ctor_mD82E516936D2BDE6D46C8C45270250647986231E (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* __this, Il2CppFullySharedGenericAny ___0_key, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method)
{
	((  void (*) (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, const RuntimeMethod*))KeyValuePair_2__ctor_mD82E516936D2BDE6D46C8C45270250647986231E_fshared)((KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)__this, ___0_key, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ArraySegment_1_get_Array_m85F374406C1E34FDEFA7F160336A247891AF8105_inline (ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093* __this, const RuntimeMethod* method)
{
	return ((  ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* (*) (ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093*, const RuntimeMethod*))ArraySegment_1_get_Array_mE4A35DFD81ABF447350B9A05C0F4BF0248A3CFF2_fshared_inline)(__this, method);
}
inline int32_t ArraySegment_1_get_Offset_m28FEFF65E8FA9A92DF84966071346BFD426CC3AA_inline (ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093*, const RuntimeMethod*))ArraySegment_1_get_Offset_m4FAFF061AB36BF278BA8DC37B6D13718A06301E6_fshared_inline)(__this, method);
}
inline int32_t ArraySegment_1_get_Count_m7B026228B16D905890B805EA70E9114D1517B053_inline (ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093*, const RuntimeMethod*))ArraySegment_1_get_Count_mEF96248898C14F3687A5C72B920F841701E4E13C_fshared_inline)(__this, method);
}
inline void ReadOnlyMemory_1__ctor_m3727B8B598D6E2BDC484D8B20FE81585C449AD30_inline (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399*, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, int32_t, int32_t, const RuntimeMethod*))ReadOnlyMemory_1__ctor_m1FD19CA8A2CB8A92DC095EE34D414ADE2FD39A12_fshared_inline)(__this, ___0_array, ___1_start, ___2_length, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlyMemory_1_ToString_m0C4DF727B39C613F84AC56D6FDAF7ACFF9E39720 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m9D8BA8245B8DC9BFB4A4164759CBAAEAD1318CD6_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
inline ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D Span_1_op_Implicit_mD249188242C0C9D3192A31E9F7FA74C683F05B84 (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_span, const RuntimeMethod* method)
{
	return ((  ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305, const RuntimeMethod*))Span_1_op_Implicit_m704A5B9FD25EEA23756181A8EB40B875387A6C01_fshared)(___0_span, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m7B5C2765879EA5E8D1617D834CC465A39540A913_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ReadOnlyMemory_1_get_Span_mA087C8160638E6581A03C1BDAF2803AC88834762_inline (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Memory_1_get_Span_mA0CAB13956D6FA3BBF9F9176CB647933F88E034E_inline (Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlySpan_1_CopyTo_m8144AA3941DF7B7C2C665680221977E1D15D1462 (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_destination, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlySpan_1_TryCopyTo_m2C902AB57D2363B06C42BDDE761F3E0DFD5541B3 (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_destination, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t* Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline (RuntimeArray* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MemoryHandle__ctor_mBC4C2B7E7F10F5F93EFCF6A3A24D41CE79916C91 (MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD* __this, void* ___0_pointer, GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ___1_handle, RuntimeObject* ___2_pinnable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC (RuntimeObject* ___0_value, int32_t ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ReadOnlySpan_1_ToArray_mF805FAE3816BCFA5C63592CA173237F9B1E4566E (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, const RuntimeMethod* method) ;
inline bool ReadOnlyMemory_1_Equals_mC3969DE0744A246E0576FEDE51191A0D3F5F69A9 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 ___0_other, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399*, ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399, const RuntimeMethod*))ReadOnlyMemory_1_Equals_mF7DA75997B4FFDFB2D6F953E8DC580EC3C941A61_fshared)(__this, ___0_other, method);
}
inline ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 Memory_1_op_Implicit_m7B80A71310A3EA9F99CB1774CAFED254811599CD (Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036 ___0_memory, const RuntimeMethod* method)
{
	return ((  ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 (*) (Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036, const RuntimeMethod*))Memory_1_op_Implicit_m7216145178505C2CB2BA0E21CB95773BE1E6A7AF_fshared)(___0_memory, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_Equals_mD0C4947B91FD3864C476B6CA8BA929A6F5B01175 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_CombineHashCodes_mC20EA69C2706DE824529A0506BD45837E26C6980 (int32_t ___0_h1, int32_t ___1_h2, int32_t ___2_h3, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_GetHashCode_mE47597BBDBFFBC9185DE65261A7388207854ADE6 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) ;
inline int32_t ReadOnlyMemory_1_CombineHashCodes_mAD75C6BDDB231C42D8A846F50E2B081E244108DA (int32_t ___0_left, int32_t ___1_right, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int32_t, int32_t, const RuntimeMethod*))ReadOnlyMemory_1_CombineHashCodes_m74D5DE9AF0CCB1FF7B88058328C835DBD981C568_fshared)(___0_left, ___1_right, method);
}
inline CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ArraySegment_1_get_Array_mAB134498A82AD590967BDB7C71136238AA980AD8_inline (ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3* __this, const RuntimeMethod* method)
{
	return ((  CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* (*) (ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3*, const RuntimeMethod*))ArraySegment_1_get_Array_mE4A35DFD81ABF447350B9A05C0F4BF0248A3CFF2_fshared_inline)(__this, method);
}
inline int32_t ArraySegment_1_get_Offset_m0C181BD19C4ED1F046320674D18CAEA6C3445EFB_inline (ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3*, const RuntimeMethod*))ArraySegment_1_get_Offset_m4FAFF061AB36BF278BA8DC37B6D13718A06301E6_fshared_inline)(__this, method);
}
inline int32_t ArraySegment_1_get_Count_m41C56DC7483456EE6281ACF18BD801F6C23F16B8_inline (ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3*, const RuntimeMethod*))ArraySegment_1_get_Count_mEF96248898C14F3687A5C72B920F841701E4E13C_fshared_inline)(__this, method);
}
inline void ReadOnlyMemory_1__ctor_m01C92ACEFF41B2945760FBBE73C5761736F117C8_inline (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6*, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*, int32_t, int32_t, const RuntimeMethod*))ReadOnlyMemory_1__ctor_m1FD19CA8A2CB8A92DC095EE34D414ADE2FD39A12_fshared_inline)(__this, ___0_array, ___1_start, ___2_length, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA_inline (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlySpan_1_ToString_mB13A913EF211B14B719EE62133C15C298642E34D (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE (String_t* __this, int32_t ___0_startIndex, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlyMemory_1_ToString_m4676D3AFBC120B54C2B53171F9C7DE3B4E753F68 (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
inline ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 Span_1_op_Implicit_m03D0CEDC1BC95844236105D1DE24A702B956BFE4 (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, const RuntimeMethod* method)
{
	return ((  ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 (*) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, const RuntimeMethod*))Span_1_op_Implicit_m704A5B9FD25EEA23756181A8EB40B875387A6C01_fshared)(___0_span, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar* String_GetRawStringData_m87BC50B7B314C055E27A28032D1003D42FDE411D (String_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
inline void ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1*, Il2CppChar*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mFA6EE52BCF39100AE30C79E73F0F972182D0CA2A_fshared_inline)(__this, ___0_ptr, ___1_length, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 ReadOnlySpan_1_Slice_mDEEA4C304B13C8F7A63BC3D60B62FF17BBEE282B_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mDADE08E6B4594775C6675B389078E5FE98C745D5_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Memory_1_get_Span_m926BDF0BE2BAC67BB057415AE70537AFCB4FE3B8_inline (Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlySpan_1_CopyTo_m42F1668DECE40277D97A37705EA6BE27CF7D5030 (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_destination, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlySpan_1_TryCopyTo_m22E885FE905F1306DDE8000F155109F7F4987666 (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_destination, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ReadOnlySpan_1_ToArray_m3CC38C41E9FB235D0C9D24033DE4D561B1017488 (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, const RuntimeMethod* method) ;
inline bool ReadOnlyMemory_1_Equals_mC4A7615E6A8C3467783EB6D9FBDA06A1B9745117 (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 ___0_other, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6*, ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6, const RuntimeMethod*))ReadOnlyMemory_1_Equals_mF7DA75997B4FFDFB2D6F953E8DC580EC3C941A61_fshared)(__this, ___0_other, method);
}
inline ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 Memory_1_op_Implicit_m2A354E866CDB4F77671ADADD234CFF9A31DAB8FB (Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E ___0_memory, const RuntimeMethod* method)
{
	return ((  ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 (*) (Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E, const RuntimeMethod*))Memory_1_op_Implicit_m7216145178505C2CB2BA0E21CB95773BE1E6A7AF_fshared)(___0_memory, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_Equals_mE4EA5DC4ACF51E07F85C4A55A3281E580903506F (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_CombineHashCodes_m90089D22A29124B5DFB7253B5795FBBBA2E17BC1 (int32_t ___0_h1, int32_t ___1_h2, int32_t ___2_h3, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_GetHashCode_m7D885665B2C6E9B5B157129A6CCAFC4938400D0D (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) ;
inline int32_t ReadOnlyMemory_1_CombineHashCodes_mE36B3B07DCBC22779CDDB94D35E0D00AD8568028 (int32_t ___0_left, int32_t ___1_right, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int32_t, int32_t, const RuntimeMethod*))ReadOnlyMemory_1_CombineHashCodes_m74D5DE9AF0CCB1FF7B88058328C835DBD981C568_fshared)(___0_left, ___1_right, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56 (const RuntimeMethod* method) ;
inline void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305*, uint8_t*, int32_t, const RuntimeMethod*))Span_1__ctor_mBA868F06359701D9950DEB1B10F52F848E9FF6DA_fshared_inline)(__this, ___0_ptr, ___1_length, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m698EC79E2E44AFF16BA096D0861CFB129FBF8218_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
inline void Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D*, Il2CppChar*, int32_t, const RuntimeMethod*))Span_1__ctor_mBA868F06359701D9950DEB1B10F52F848E9FF6DA_fshared_inline)(__this, ___0_ptr, ___1_length, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m5BFF79141064122141ED34283347A634B9DF577D_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8E1E04E7BBAF15EB7C047EB1D2C195918CA0881A (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ReadOnlyCollection_1_get_Item_m372A5C8638E7939A221EDE1F745CD5B0CB90D635 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_2;
		L_2 = InterfaceFuncInvoker1< RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m0AB43B74EC42C2031FB99692031B34C176E6DC2E (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m282961D38BF8519BCBECD4B6DCB99C430034BE72 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mA605C8D5366092D2AD633814015998F29C0EB05E (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m7AC9BA5BEB59068FAA7EFADA5EBB80B85D400A74 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m2DCD7F19253D830C363663D516916D6E53FAA7D8 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_2;
		L_2 = InterfaceFuncInvoker1< RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mFB4E25D06A8148E3D31EE6FE9D60DCA4CFF589DD (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m8E1E04E7BBAF15EB7C047EB1D2C195918CA0881A(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< RepeatRectUVU5BU5D_t134899E528136F583F5E5CB953E09A42EAFF52FE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_35;
			L_35 = InterfaceFuncInvoker1< RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m8B23413A1F0CA8F27B202E55860299242B538C34 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_2;
		L_2 = InterfaceFuncInvoker1< RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m79537AB29BC45B039EC2EC8C4D1676D1E99050EE (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C));
		RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mB020417058F51BFEB154FDC1E64CB2ACF650C227 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m79537AB29BC45B039EC2EC8C4D1676D1E99050EE(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m0AB43B74EC42C2031FB99692031B34C176E6DC2E(__this, ((*(RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m3286EC2AABA78CE1A10CC423D72E9E14D2E194E1 (ReadOnlyCollection_1_t5E383B2619260F758DF464DCF892BAC98420089B* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m79537AB29BC45B039EC2EC8C4D1676D1E99050EE(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m7AC9BA5BEB59068FAA7EFADA5EBB80B85D400A74(__this, ((*(RepeatRectUV_tD14FA437CD80FC82B2ED78B34A201F3C91416A7C*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mFF8DC212CA14B1BAD190433D8A39325EB8F8692A (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ReadOnlyCollection_1_get_Item_m056726550AB23007B44EAE860053D4F3E2C9CFF4 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_2;
		L_2 = InterfaceFuncInvoker1< TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6AFC7D4D548E6DEF9AF986FB86F1AE3805653785 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m5635CA4D3094567C2DF328936F817FB7709030FA (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m7291430244EF4F974A202E456EA947A4B8A7F24B (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2A11348B3EFD6DF36D28D99228DBB7447B2ED8C2 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m7D320F07F83A6BB5C60CBE8440C784A1D4D8408A (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_2;
		L_2 = InterfaceFuncInvoker1< TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m265422C912208679F512944C68C951BE58F32290 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mFF8DC212CA14B1BAD190433D8A39325EB8F8692A(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< TessellationJobParametersU5BU5D_tFDC79BFC52A9ED8B50D955BAB909B22B626749EE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_35;
			L_35 = InterfaceFuncInvoker1< TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mE5B76EFC8552217CB71A237FFECBB12F6CE8B795 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_2;
		L_2 = InterfaceFuncInvoker1< TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m162020E379E108D3B9A4607E90AC6CB7999E2906 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2));
		TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m37B6807D801669CDEE221767DBA4DCB0F17AC0F8 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m162020E379E108D3B9A4607E90AC6CB7999E2906(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m6AFC7D4D548E6DEF9AF986FB86F1AE3805653785(__this, ((*(TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mF0361F568683A284F5FA22FDC91B948CABE0E0B3 (ReadOnlyCollection_1_t1982DAD9473AAD7F47804C72E2A0177F7D3987FD* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m162020E379E108D3B9A4607E90AC6CB7999E2906(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m2A11348B3EFD6DF36D28D99228DBB7447B2ED8C2(__this, ((*(TessellationJobParameters_tA2407D5C15761590BDD217DDE4861964544E8CE2*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mB3B7A3A0C879250FA0A51533B5FAFAEC745B059A (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ReadOnlyCollection_1_get_Item_m9290C496836CAE117EFEC29153ACD0D0016E0FFF (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_2;
		L_2 = InterfaceFuncInvoker1< AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC42D7F66712159450A3E1581D1C447DA781D6ABB (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m23344AE093CCE169D170A9EB87734B2C4BFE9CAF (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m26C544D88E31DA5ECB5D1BD888955BF107AEF60A (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m05E6B9F938D84C399B9B3B0D32121EADFE6060D1 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m2DE980F2736284D35758DE5C9F5EBDE13926DBA4 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_2;
		L_2 = InterfaceFuncInvoker1< AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mD3EC784BB6E74143B51C20A297806D871BFA2086 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mB3B7A3A0C879250FA0A51533B5FAFAEC745B059A(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< AllocToFreeU5BU5D_t6F402B32E75165739A05F4BFF291C353ED0C1A7F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_35;
			L_35 = InterfaceFuncInvoker1< AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m8F4EBDD68C55EAF72AEB9F2FE5811A9FCB5F64D9 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_2;
		L_2 = InterfaceFuncInvoker1< AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m25436CDFD278C3404F78E12A10F35D98681429B6 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB));
		AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m3051B9E4831A8EAEF9ABA1F5D1F2A6A4F8973641 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m25436CDFD278C3404F78E12A10F35D98681429B6(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mC42D7F66712159450A3E1581D1C447DA781D6ABB(__this, ((*(AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m586DE00F98D61DFEC141C5233DE3F1D44F96C787 (ReadOnlyCollection_1_t48C40E4B0693FF45334D70226463AA59BD9DCAB6* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m25436CDFD278C3404F78E12A10F35D98681429B6(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m05E6B9F938D84C399B9B3B0D32121EADFE6060D1(__this, ((*(AllocToFree_tE4DBFDF44B21D35677B13570BA217FDAE35476CB*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m66D6D55666245CDEE1E9897829324A1F2755D07F (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ReadOnlyCollection_1_get_Item_mDA830BE6355AD2E205EA07B21C21E69688BF6CC0 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_2;
		L_2 = InterfaceFuncInvoker1< AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m50631914758AD83F933C8C58C9C56181167206EF (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m9858B37CFFC2797D6229F49DB38A0205C7BF2407 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m82021A3C529D108F5449A907A12C584CA0C81A94 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC2583A3BBC34282E2E0D92456C65DAC815328002 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m2CA3EC897C3474078ADE051AA822315F14749526 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_2;
		L_2 = InterfaceFuncInvoker1< AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mBF5C9C0D9096632B63557AA85578913CF072DE21 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m66D6D55666245CDEE1E9897829324A1F2755D07F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< AllocToUpdateU5BU5D_t648208B48A57FABF5543F60FF312E79D8B6FF49C*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_35;
			L_35 = InterfaceFuncInvoker1< AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mFE11E68E1D7E0C8238798E76020E1AC2FCC6C2C6 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_2;
		L_2 = InterfaceFuncInvoker1< AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mCEEBE7AC91128582C3C0FB0DE3F98528829728C9 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3));
		AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m78B1B3BACCC7BCAE45B204B5A8344C7878D81268 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mCEEBE7AC91128582C3C0FB0DE3F98528829728C9(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m50631914758AD83F933C8C58C9C56181167206EF(__this, ((*(AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mDCCB23D18F93D59AC4077EE712866253F40B50F6 (ReadOnlyCollection_1_t7CA4D7A31C4147338F414D044F33027644917E2A* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mCEEBE7AC91128582C3C0FB0DE3F98528829728C9(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mC2583A3BBC34282E2E0D92456C65DAC815328002(__this, ((*(AllocToUpdate_t7E5493AF0DAEBF6C8D1E005C93179042069A46A3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mA923C6AA7115FB17D5F43D8F5EFAB906CD573191 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ReadOnlyCollection_1_get_Item_mA4AFDE4C6099110CA7988416522BD423F7842FCC (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_2;
		L_2 = InterfaceFuncInvoker1< Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m91259BF5D56B9D4993F7E2209D58F860DC46FD2A (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mB2DDF38206C78B5653DB7446CC9A4E65B27D764B (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m1E526D38E6A602BD663FBDF0E31DCEA98F414C5E (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4959B727178367FB71DDF85183AE6B42896A6968 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m461DE56E5CF49E83BF5FAE98BC7AE38CABA3D8C2 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_2;
		L_2 = InterfaceFuncInvoker1< Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m710B4FA4F36D0A564FE708633236364E4983D53E (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mA923C6AA7115FB17D5F43D8F5EFAB906CD573191(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< Painter2DJobDataU5BU5D_t357073CDDC47FE6B5DAC4A45876119B855E0BC44*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_35;
			L_35 = InterfaceFuncInvoker1< Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m9ACD4349EA9F8A276BBE84785B429C7FD00250F0 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_2;
		L_2 = InterfaceFuncInvoker1< Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m17EE888747F53315F45BD98410940E0BC662DFB9 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF));
		Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m0DE6912F036961EF92B691D2076B45F1B6D22F57 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m17EE888747F53315F45BD98410940E0BC662DFB9(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m91259BF5D56B9D4993F7E2209D58F860DC46FD2A(__this, ((*(Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m176DBD6BC18D402C9765879E4AC0B31D717009C6 (ReadOnlyCollection_1_tD5FF144210E35CDCBBC39150BD6EB93A6E0DBD1A* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m17EE888747F53315F45BD98410940E0BC662DFB9(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m4959B727178367FB71DDF85183AE6B42896A6968(__this, ((*(Painter2DJobData_t227572FEAE4A071ED0378501E752A72FF0ACC4EF*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE31E6450162F6E9B618AAC3AC422BA73138F2DF2 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ReadOnlyCollection_1_get_Item_m132DCFF193762D3CAD7C52269975CEEF884DCAEA (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_2;
		L_2 = InterfaceFuncInvoker1< BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3E387EA2DD8EE68F91476C1CFC4FB56DB16FE901 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mF3BC784E622D7F6C8DB66152DD44A940BE3EF933 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m95F697101E9CCDA4A18F1FEF1129F5B87744A369 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB2EE20AD2CF899F6D963C508EB10B05E9DBAAFD1 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m2ADF39EAA11EDED4E6B6FE975CB977671F21A20C (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_2;
		L_2 = InterfaceFuncInvoker1< BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mF5A1B7352740CCF3BF5F4EE0B5406179B84CB1FC (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mE31E6450162F6E9B618AAC3AC422BA73138F2DF2(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< BrickChunkAllocU5BU5D_t67316E3C7BB0F8E26AB0D8AD7B8CC62FD533F6AE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_35;
			L_35 = InterfaceFuncInvoker1< BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m425FA0CF5BB531266E8B272474E22B793C16217C (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_2;
		L_2 = InterfaceFuncInvoker1< BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m1584B4A5D71D0BD68DC0B608E63CE74E81094A13 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B));
		BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m9CCECDE0CEF98FA060360974EDF5457467B9B66D (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m1584B4A5D71D0BD68DC0B608E63CE74E81094A13(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m3E387EA2DD8EE68F91476C1CFC4FB56DB16FE901(__this, ((*(BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mCD70A4D5F566D2C96465CDD51373CA26C1F28A22 (ReadOnlyCollection_1_t60075704E4AC0EE9C6A477EFA7FDB046ED3A199D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m1584B4A5D71D0BD68DC0B608E63CE74E81094A13(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mB2EE20AD2CF899F6D963C508EB10B05E9DBAAFD1(__this, ((*(BrickChunkAlloc_t95EB283E186F5DA1E74A8DDE415EB8E7ABFDF51B*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m2278DB015831D3852A1ECDC9C8E44CA52E94A010 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ReadOnlyCollection_1_get_Item_mB18A3E26533B720F56902716C58B3A46532BB5A3 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_2;
		L_2 = InterfaceFuncInvoker1< SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mB732A9E350D9E3CD2C7840CC90E0CD38529A5C1C (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m850573B05FD0B45287F263F8D4FFA6C2D8315C1F (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m1D6BB9CBE4FE3DE704D9379D7E898D80072A9056 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m002E2463EC869D6B730B00CF9A1A973007B41B35 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mA78C5A09FE79C6FDE01D95A4ED9DF83DACFB096D (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_2;
		L_2 = InterfaceFuncInvoker1< SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m720C3B05304C9D4C04E6516DF0CC49854171BF9A (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m2278DB015831D3852A1ECDC9C8E44CA52E94A010(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< SerializedPerSceneCellListU5BU5D_tF4A784BCC24343A482BE15CBF415A68F3B353D6F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_35;
			L_35 = InterfaceFuncInvoker1< SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m65AEF26CCBD4B5E5AB39874A2B66F1A5D617627B (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_2;
		L_2 = InterfaceFuncInvoker1< SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m6679EEE84E9BBDBE8761CF44B8294155AB69A45E (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591));
		SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mF39A00AAC6A77065B1DA51AF1D2982D7C0C86041 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m6679EEE84E9BBDBE8761CF44B8294155AB69A45E(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mB732A9E350D9E3CD2C7840CC90E0CD38529A5C1C(__this, ((*(SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m6D60BAE0CFECCCF35688404A896616CC998B7905 (ReadOnlyCollection_1_tF8522889690BC1839B3C279644A00A0E8F789DEC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m6679EEE84E9BBDBE8761CF44B8294155AB69A45E(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m002E2463EC869D6B730B00CF9A1A973007B41B35(__this, ((*(SerializedPerSceneCellList_tDF6654463D2F5052472326DE949ABE002ED92591*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m98DEFEBAE637436EEDC27C55AE2C19B076DE090F (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ReadOnlyCollection_1_get_Item_m32124F321123E04C9273B3ED7186012C0F73AEC0 (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_2;
		L_2 = InterfaceFuncInvoker1< ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6453D07CDC6264E9F4FEBF425DFA817487EE9723 (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mC9837DF3E941CF61A337DB2C33D5434A08F4967C (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m23D535A49E78F3C159D13A0BD34BE9C4D571505C (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB98D3656FF7E5F1A67C4FB181C9A4A3D309087FA (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mF4AEE2A281B2BD48ECFEA466EC462CBD88CAA9CF (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_2;
		L_2 = InterfaceFuncInvoker1< ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m6766457A1DB2E8F45E4AD7F8EF149B2BF26F6F0F (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m98DEFEBAE637436EEDC27C55AE2C19B076DE090F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< ObsoleteSerializablePerScenarioDataItemU5BU5D_t28ABF785278BD4BAD3D8A00B4EE4F247361A22F3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_35;
			L_35 = InterfaceFuncInvoker1< ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m34737255FF46AD70F519BBFF48F00F9ACD351067 (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_2;
		L_2 = InterfaceFuncInvoker1< ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m2762EABC097FB2A997370146E5E61C2A197552CE (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7));
		ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m486E7A76855399E9EAB093694494620A5396FED8 (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2762EABC097FB2A997370146E5E61C2A197552CE(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m6453D07CDC6264E9F4FEBF425DFA817487EE9723(__this, ((*(ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m5F70ABC2563E7A3D1ACA11DF15FE1E3AA2671A53 (ReadOnlyCollection_1_tC344EA24C72FF0194C07947E811476F242841216* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m2762EABC097FB2A997370146E5E61C2A197552CE(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mB98D3656FF7E5F1A67C4FB181C9A4A3D309087FA(__this, ((*(ObsoleteSerializablePerScenarioDataItem_t4DB1ADB8C2522C62B43309AF1874419D8572EEB7*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m2CC3246BF9378F698D206586E815F940BDFF3A4F (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ReadOnlyCollection_1_get_Item_mEE5E5637BE9785010B3A21EF121ABD5A0261442D (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_2;
		L_2 = InterfaceFuncInvoker1< StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m47AEA24C0ACE4F3899592E7466AEEAEC7C8677AB (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mDA247EBE5E4425CADB40177CF792579541303F4E (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m247154DEDE05E4EB209AD57F0A87AFB0408AE7BB (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2C11317DDF1B10C32280199980586FF267E163F6 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mE21BC76810E498D1A97DB58F486DEDC10E193299 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_2;
		L_2 = InterfaceFuncInvoker1< StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m0F24B9B8E0075C128ED5C42A638B781F8F7AE2E8 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m2CC3246BF9378F698D206586E815F940BDFF3A4F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< StreamableCellDescU5BU5D_tDAAACF4DEEFB9A39DD6E17E66EB55EC8A41258B7*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_35;
			L_35 = InterfaceFuncInvoker1< StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m784006CE053BEF0549101CE68D3A3537C92F5101 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_2;
		L_2 = InterfaceFuncInvoker1< StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAD7E8A171AFE7CD86454D7E8BFDE0CD9D216060C (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A));
		StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m6D0E86731C4B7060C2F4FBBB69FCF7C455238CA7 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAD7E8A171AFE7CD86454D7E8BFDE0CD9D216060C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m47AEA24C0ACE4F3899592E7466AEEAEC7C8677AB(__this, ((*(StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mA0500C0627796558DA81F0945C81B61610540396 (ReadOnlyCollection_1_t80B210113B317228123ECCEA2A496292D5A546B4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAD7E8A171AFE7CD86454D7E8BFDE0CD9D216060C(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m2C11317DDF1B10C32280199980586FF267E163F6(__this, ((*(StreamableCellDesc_t30C9692E80F3E2FD12CF286548763F9F4DE5048A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mD9D82410CB95D4FE5C14BACB7022BFC0B090CB23 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ReadOnlyCollection_1_get_Item_m47C9C15DA6295A4D3205BB3DF6706E714754C5BE (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_2;
		L_2 = InterfaceFuncInvoker1< SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m913E4228E930667ED05C69E275781B4D65AD6377 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m858A6F6B62C63990989FBEB02C82B3AB723D9C05 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mFA24EA6DA76344F50A16777637DC62C58EAE49F7 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m05146C24F41FA016ABE609031F1CCDF60E768619 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mF1CEF15879CE0766AB2D52E18BAB760BD390A1B4 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_2;
		L_2 = InterfaceFuncInvoker1< SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mB5C7194DC6DB6217A91C0C87EB20DD179B46013A (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mD9D82410CB95D4FE5C14BACB7022BFC0B090CB23(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_35;
			L_35 = InterfaceFuncInvoker1< SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mB7719C09C00A3DC120B4DBAD4F4051DA0F2D429E (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_2;
		L_2 = InterfaceFuncInvoker1< SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mA31AC1D905D65EE27428ABA47C90CFA51CA93BA8 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC));
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m66E6055368525A72DCCC69258DE70D1A6DF4F01D (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mA31AC1D905D65EE27428ABA47C90CFA51CA93BA8(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m913E4228E930667ED05C69E275781B4D65AD6377(__this, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mEA821C50AEAA88BFB68B38FC52D7A12B7EDEC746 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mA31AC1D905D65EE27428ABA47C90CFA51CA93BA8(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m05146C24F41FA016ABE609031F1CCDF60E768619(__this, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m95E8E1F55501F640B52A5AD4E73DE9CB674CA074 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ReadOnlyCollection_1_get_Item_mCB2DAD592707EC93120F0AD493A9EA30B7887EB8 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_2;
		L_2 = InterfaceFuncInvoker1< ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m983620D9F4A7313CEB1B1AEFFEDC8DB2DF1600F3 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m40BC7F09113CF3778DD9CE61159EAA8A62872F22 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m5EB776BC8FA7C980F555614D77D18288C66839E7 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mAB5A5EADC7E5E50497A3B7584352D42B28CE3C69 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mEC91C61631281A228CD6D39445182F6E66DEC9C9 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_2;
		L_2 = InterfaceFuncInvoker1< ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m2AE3E1B1E59B2E2882D52A6BA4697F89C963E541 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m95E8E1F55501F640B52A5AD4E73DE9CB674CA074(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< ElementInsertionDataU5BU5D_tC694C1E86CD6BF2A280620FDE4C8A6F02EC3F7FB*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_35;
			L_35 = InterfaceFuncInvoker1< ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m0B2A6F557628FA85BBD21D837688D84AECA13566 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_2;
		L_2 = InterfaceFuncInvoker1< ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mAB1EFE8A5D353B131BBE9EB34B74A6BAE06F9599 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959));
		ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mCA9FE786A4205269188C6A4BF84029E0FF903A8F (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAB1EFE8A5D353B131BBE9EB34B74A6BAE06F9599(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m983620D9F4A7313CEB1B1AEFFEDC8DB2DF1600F3(__this, ((*(ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m536D38B178BA32CB2F6C5CFB8CA3A164574146C3 (ReadOnlyCollection_1_t778705179F5558E3A20AA29622B7B6CF3430C9F5* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mAB1EFE8A5D353B131BBE9EB34B74A6BAE06F9599(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mAB5A5EADC7E5E50497A3B7584352D42B28CE3C69(__this, ((*(ElementInsertionData_tA691432209201F6E803ADDFD410186B673527959*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0EEB9CC7A903E35B3737942EFF99016D288DDED6 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ReadOnlyCollection_1_get_Item_m7415C820C0D80497D667E7E8E1D21D38A86333F3 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_2;
		L_2 = InterfaceFuncInvoker1< MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC67C7EF96296B0DE1C19FDEEDBABA0FFBD67CB03 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mF9234048E6B173728F12D5D69C5881BB9E123ECA (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m73970EA5B885D292B5D238D8D85D6FCB0B325855 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m716BA7D21054B1D77515F421EE50AD75DB3EACBE (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m07DC4180FC629AEF8A747CA4CA539A13C1D04EC1 (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_2;
		L_2 = InterfaceFuncInvoker1< MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m7EED9AAA73BBCCB5B4031DCB332410B3D2431D5D (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m0EEB9CC7A903E35B3737942EFF99016D288DDED6(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< MinMaxBoundsU5BU5D_tBCCC38EDCBA810A447297E68EF7A3B22AE8A25C3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_35;
			L_35 = InterfaceFuncInvoker1< MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mD8030423A389CA050AF9715D5C7385D1BA1E78CA (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_2;
		L_2 = InterfaceFuncInvoker1< MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0DDEE58D13E8FB5B2766AC7DA0C55DAC13584B77 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537));
		MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m673461D6E3EEDCF81DA81A18BBA7DD2CA2566E1C (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0DDEE58D13E8FB5B2766AC7DA0C55DAC13584B77(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mC67C7EF96296B0DE1C19FDEEDBABA0FFBD67CB03(__this, ((*(MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m5035A77F0C55B000B56E7B9CEFB52524919CB42E (ReadOnlyCollection_1_t5E28CD01FD3AD826ADA55DFBBFCB6EBA5A07C214* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0DDEE58D13E8FB5B2766AC7DA0C55DAC13584B77(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m716BA7D21054B1D77515F421EE50AD75DB3EACBE(__this, ((*(MinMaxBounds_t35E6E7F057C2DA166CB55DB2865E06EC1E344537*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8DB78ECCD7FE15165D37E8B1BEE1E0CE961646B8 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ReadOnlyCollection_1_get_Item_mFBC147792A35DA0024349EAE543F02DA9CC280A8 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_2;
		L_2 = InterfaceFuncInvoker1< TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m41DE6354C6777FCC2A9A07D4EEBA1EDED633DF95 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m7B4BA4301921B4F811993D0E307A17FDB1237027 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m3EBECF593E97322DCE668D7A658522EEB2F25631 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB3BC65B35BADE231093A41C12901EA81455B7C7A (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m2F3B8B37F092A6AF74E5CEA0E27869878108DF3D (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_2;
		L_2 = InterfaceFuncInvoker1< TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m28F3C463EB06744E132B4974576F6DDF31B81197 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m8DB78ECCD7FE15165D37E8B1BEE1E0CE961646B8(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< TransformDataU5BU5D_t9C6552848CAA1DCDD99EC5141171F72E5E8FA322*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_35;
			L_35 = InterfaceFuncInvoker1< TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m04D51D41FF54AFA3BDCEB7F9C7745E16762C4409 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_2;
		L_2 = InterfaceFuncInvoker1< TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0E3D36FD434C8509FA5456EC472A90892333EBB3 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646));
		TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m033ABAA741690D649C9122A91E6BC049C5BE8010 (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0E3D36FD434C8509FA5456EC472A90892333EBB3(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m41DE6354C6777FCC2A9A07D4EEBA1EDED633DF95(__this, ((*(TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mECCFF7D6ADE37DF7A5E12F84137B6449875DD66C (ReadOnlyCollection_1_t79B2FEEBA1B14690FEC20ADEEB70296187AE1A3D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0E3D36FD434C8509FA5456EC472A90892333EBB3(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mB3BC65B35BADE231093A41C12901EA81455B7C7A(__this, ((*(TransformData_t1EB326D4F0A7D2FABB34DAB3D379349B5F623646*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mF8F286601D8EED13DACAB99C02259324E49C6DA1 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ReadOnlyCollection_1_get_Item_m1D74069955A7C0AE2F04D75AD99E619602CC9191 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_2;
		L_2 = InterfaceFuncInvoker1< Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m947A3FA40F7BF31EEE550BB315172BE53B38F22F (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mB3E14D2ED861B1E3772607ADED57151D60A76DC6 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mAE7EF09A63B12DB9F2AAD6F7B8588C42317449D4 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m0A4F50958D471DC760F266D8D2A1EE200DF52C2E (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m685CEBD77D747F24BAAD44D969400299D11D8CEB (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_2;
		L_2 = InterfaceFuncInvoker1< Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mA2981F55B76AA271CC7FFBA9A081F63C6F9B6A2A (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mF8F286601D8EED13DACAB99C02259324E49C6DA1(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< PageU5BU5D_tDFA5009590467C6D992272922113C6230D341CE4*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_35;
			L_35 = InterfaceFuncInvoker1< Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m393B60BAB8CEA427AFA24D38A8A71A4510A77C49 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_2;
		L_2 = InterfaceFuncInvoker1< Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m95712CD049C6EEB0E90DB244AC3171FA85166DB6 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981));
		Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mDBB06A616B5CB5D091360CD1C26ED9550A2A9B3F (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m95712CD049C6EEB0E90DB244AC3171FA85166DB6(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m947A3FA40F7BF31EEE550BB315172BE53B38F22F(__this, ((*(Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m828A009F4EA01F066405C27334BA7DA1E5EAABA7 (ReadOnlyCollection_1_t94B813926D2C4CA835FE4DF72FAEED427A8294F5* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m95712CD049C6EEB0E90DB244AC3171FA85166DB6(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m0A4F50958D471DC760F266D8D2A1EE200DF52C2E(__this, ((*(Page_tF4CAEB005DC95E53F6992D59C12E548C3C2DE981*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mBB2B7BF08D287E2667F29836FCF9E439551DBE8F (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ReadOnlyCollection_1_get_Item_m7D6E7F9A7B2DCA2865C2320EAD02C97BFA7057E1 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_2;
		L_2 = InterfaceFuncInvoker1< AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m638A809E5C72AB15EDA998647FE19E464E709DEF (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m388483269164B7D2D2C0DFC1E1CA02135AFA2984 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m7747E7F55D0427D07FEBE057396F3C0C34361BFF (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC3926319976609BD7A37B3FD87A61906A26C54B6 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mADA35CDF24AA2C23D47899052C6B14D9E15D936D (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_2;
		L_2 = InterfaceFuncInvoker1< AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m1117466AFAE6686A4A21825C6F8BCF74E029F8F3 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mBB2B7BF08D287E2667F29836FCF9E439551DBE8F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< AttributeOverrideU5BU5D_t4D2E0B93EF3A1A1EB58AC1F48E6CFE20A0EA27E8*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_35;
			L_35 = InterfaceFuncInvoker1< AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m6A6FB3510D880798441A249753DD53712D2A4E64 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_2;
		L_2 = InterfaceFuncInvoker1< AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m11348500F34A92ED3E4F57AA0233784078379771 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF));
		AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mC4DA23437E5F7D1AECD4DCE05731DF55CFECED0B (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m11348500F34A92ED3E4F57AA0233784078379771(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m638A809E5C72AB15EDA998647FE19E464E709DEF(__this, ((*(AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mE3C28CE739EDDCA049F7767F48C3C8511722BFE4 (ReadOnlyCollection_1_tDC2EF30575D579ECA71384FC25F70D7736968631* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m11348500F34A92ED3E4F57AA0233784078379771(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mC3926319976609BD7A37B3FD87A61906A26C54B6(__this, ((*(AttributeOverride_t58F1DF22E69714D48ECBEEAD266D443A858BADEF*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mE24114E67C1515ED8C4F81DBE65B00B6B917A279 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ReadOnlyCollection_1_get_Item_m8CBA9F3CACB0C9BC25CD4273AFA26E930A2CF53F (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_2;
		L_2 = InterfaceFuncInvoker1< UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m23A5C68995E101E0D2EB2F9483D609514BBDBD2E (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mBE33CDCA2DDF586C7685B7DBE8BA2ABC295D2C03 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m59F7964D59B5A1EDC84520847B54446AA599F2A6 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE9844C779BE6775172325AFACCE26458ABB4B8C0 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mFB5FD819475E9D3F4A7BC8F80A0ACE57AAD94321 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_2;
		L_2 = InterfaceFuncInvoker1< UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m63D503B8D2F7D6F1325ADC9EDC871334C3688B2B (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mE24114E67C1515ED8C4F81DBE65B00B6B917A279(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< UxmlSerializedDataOverrideU5BU5D_t31FF90782892C74FA1E1C67897A3E6C0BB0A5B9A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_35;
			L_35 = InterfaceFuncInvoker1< UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m13FA31BF41D1D1B7AF8E72467D245D9D009191DD (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_2;
		L_2 = InterfaceFuncInvoker1< UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m5F2B05B1740F553E40DFC6DED6A468B45B9316FF (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67));
		UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m4732772C9917871E0AE5CE98C6B7BC615756A6D8 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m5F2B05B1740F553E40DFC6DED6A468B45B9316FF(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m23A5C68995E101E0D2EB2F9483D609514BBDBD2E(__this, ((*(UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mEF5D70A735D715F8387FEF70F747911CB25B92A4 (ReadOnlyCollection_1_t558A7922925B11EDC9269DCBDDF8FF3619D03318* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m5F2B05B1740F553E40DFC6DED6A468B45B9316FF(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mE9844C779BE6775172325AFACCE26458ABB4B8C0(__this, ((*(UxmlSerializedDataOverride_t612A2DF19F1F3AF231244900F30A331CFB9CAD67*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m294CA4038F05C8500E78F059A44B5C74556DBBF8 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ReadOnlyCollection_1_get_Item_m2649CF44A90207A705DB7598D1F3ED59015BAE33 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_2;
		L_2 = InterfaceFuncInvoker1< FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m07FD564014E69D4B40CE0B12AFAA93929EC83137 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m84897558F2E8B698A890328B3743B8152B705EA5 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m2F522FCFF4FB833C077DBD0C3241FB9ABEAF313F (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mB2559896BC5F11800B0108BEBA9EAB2A6C95EE0F (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mFCCCBEBF08B4DFA4BC4940F0B95F77412AF94B06 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_2;
		L_2 = InterfaceFuncInvoker1< FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mBB9AB186341D4FCEB4AC500C094E494CB11F3A06 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m294CA4038F05C8500E78F059A44B5C74556DBBF8(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< FontReferenceMapU5BU5D_tFA470305A1935D0EBE0F74758328811439915118*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_35;
			L_35 = InterfaceFuncInvoker1< FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m2C38C1D01ADFC930A6D3D7347FBCC1E811B466EF (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_2;
		L_2 = InterfaceFuncInvoker1< FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mFCD2A54038776E3951F71F390645766807267DE5 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831));
		FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m1785004310E9CBE7B7AB3212BA94D45F563A488D (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFCD2A54038776E3951F71F390645766807267DE5(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m07FD564014E69D4B40CE0B12AFAA93929EC83137(__this, ((*(FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m68AD8C2D1BA9FC51DA3959193D79B789D818ABC4 (ReadOnlyCollection_1_tF9BDC7A725517ED0439C01A1532E809C474C0D32* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mFCD2A54038776E3951F71F390645766807267DE5(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mB2559896BC5F11800B0108BEBA9EAB2A6C95EE0F(__this, ((*(FontReferenceMap_t1C0CECF3F0F650BE4A881A50A25EFB26965E7831*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m9759E4E426E53E8DD9400478BA7D6F81C7045498 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ReadOnlyCollection_1_get_Item_m1140A77AD970C4BA0905BBBC9990D0141389AC91 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_2;
		L_2 = InterfaceFuncInvoker1< BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mF080F0FA34F8F5E175F6E4DEDD178B75394CF519 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mB1F5787AFF61E469135D7C826492721AD3306D11 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m9A53384E819CDAFA059ED39C6576E0768FC4A691 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m2B98BD0E648DADFDD364421B9F9FC9936A394B91 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m95546CBB81EC37D208264CB0855C267AF0F3108C (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_2;
		L_2 = InterfaceFuncInvoker1< BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mA7ACF524BEA113BD7316A7A994719B45E71B6432 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m9759E4E426E53E8DD9400478BA7D6F81C7045498(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< BlitInfoU5BU5D_t090EAE36AF18528B2F72B1D3BBA4831E32F287BA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_35;
			L_35 = InterfaceFuncInvoker1< BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mC6CEC9A11949D24A58641BF7DA672BB534306C77 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_2;
		L_2 = InterfaceFuncInvoker1< BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m77E7B5A08971CD505FF41765E78B811AAB31B492 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357));
		BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mC79FE472B90507EB6060FADA994F3B6BF7DBBA0B (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m77E7B5A08971CD505FF41765E78B811AAB31B492(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mF080F0FA34F8F5E175F6E4DEDD178B75394CF519(__this, ((*(BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m11CC29E43CE84BC14316BA7FEE64B488823D11B9 (ReadOnlyCollection_1_tEDA5A8E1827AB831F1A307CC5CFFEDD2E0F2F501* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m77E7B5A08971CD505FF41765E78B811AAB31B492(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m2B98BD0E648DADFDD364421B9F9FC9936A394B91(__this, ((*(BlitInfo_t6D4C0580BBEF65F5EAD39FB6DBC85F360CF6A357*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m9755643A08D11F86D78C24879A20FA6B7A92EF03 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ReadOnlyCollection_1_get_Item_m65012F3FFE6E3AEC967987A2C8165310CA1D978A (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_2;
		L_2 = InterfaceFuncInvoker1< Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3950355F5CE2667D4D6E45F1236436E1D59D65BA (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mC279D2144EC707AD681A67F40B68FD82860CC28C (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m2DECCFB8C520E1F9F767B1B6DBE52E4F26799F5F (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE665276036AA8B4551F37184CDA5DB0F5FB3E144 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m06C596AA7A2D53FAA8F654B45BE427C3BD54300B (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_2;
		L_2 = InterfaceFuncInvoker1< Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m5DDF220031A533E71194983A622D272D835AC6BE (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m9755643A08D11F86D78C24879A20FA6B7A92EF03(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< FrameU5BU5D_tED4B6DE19C37177FEDD77F466E6807E1D5288F25*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_35;
			L_35 = InterfaceFuncInvoker1< Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m77C0FE1F8E2110E95D48042BD5D1AF3F2967F09D (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_2;
		L_2 = InterfaceFuncInvoker1< Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m8408613E90585C543FF86E0D19765A06036A7DB1 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD));
		Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m8EF9C6555484D25E1BC3481C413AD1C3DC574BE3 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m8408613E90585C543FF86E0D19765A06036A7DB1(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m3950355F5CE2667D4D6E45F1236436E1D59D65BA(__this, ((*(Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m6EFB70092641BFA5A7B0668F7FD1D3EC49E0AB60 (ReadOnlyCollection_1_t84E63FC18400336175812408C442A552EE840F73* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m8408613E90585C543FF86E0D19765A06036A7DB1(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mE665276036AA8B4551F37184CDA5DB0F5FB3E144(__this, ((*(Frame_tE254B3BDA010B9114EF1F470C177342FAF3E8FFD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mA3718CBDAD334D0C3B3B3D9C2FBFFC64CB9C1280 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ReadOnlyCollection_1_get_Item_m8B59DAF06D65CB643DEBC41E31022C94ABFCF201 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_2;
		L_2 = InterfaceFuncInvoker1< TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m226D99000078C09F61A5D23C9D572EEFD2C1F3AB (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m0F0C917FD1406F4F32851B6001728D34FCF8F916 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mE67F3699969AF5E867F200CCB537315190D8F228 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m38FC28A8D172A809848EBBE17B7593C9A4AC5309 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m068D9D53938421BE65EC1E68460FE317576DE399 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_2;
		L_2 = InterfaceFuncInvoker1< TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m017BA78B6833B8E2C2CF7825DB54DAC7A82CF0AA (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mA3718CBDAD334D0C3B3B3D9C2FBFFC64CB9C1280(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< TextureInfoU5BU5D_t0571178EAC2A0DE9A1F27F2C00A9301E04AAFB83*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_35;
			L_35 = InterfaceFuncInvoker1< TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m42D884E04404CA71A624FD38BE1668900821FBBB (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_2;
		L_2 = InterfaceFuncInvoker1< TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD22DEE1877768FD46CF1D7BE9E64A9BBF4762858 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B));
		TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m061D2F5226F935C163FEAC10BC96B6061FC7B3B4 (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mD22DEE1877768FD46CF1D7BE9E64A9BBF4762858(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m226D99000078C09F61A5D23C9D572EEFD2C1F3AB(__this, ((*(TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mE47DC91D620407A1DB7FB76011716B2E6E93D88B (ReadOnlyCollection_1_t82FFA6508CB53CD9CD9774F8D35B5FA03F04049E* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mD22DEE1877768FD46CF1D7BE9E64A9BBF4762858(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m38FC28A8D172A809848EBBE17B7593C9A4AC5309(__this, ((*(TextureInfo_t581C305A0444F786E0E7405054714685BE3A5A5B*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0AFB680989F7183252C477DD7EB9EF59D9C88ECC (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ReadOnlyCollection_1_get_Item_m5884CA8614092EDE0411FE4E4BA9EE0533AD968C (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_2;
		L_2 = InterfaceFuncInvoker1< RaycastHitData_t5EAB266730389AB27715962670C2512800451841, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m37A8647602E0715AC27FDFF43DABCCEF7701AEAB (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m5F082B47628439FCF310B67488B7BAC95F226B6F (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m62AFB23540393AE6D40811F4B02DF2FB51F4BA4B (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE1ABD3A991704C640186283F3DD505E3B9A77BB6 (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, RaycastHitData_t5EAB266730389AB27715962670C2512800451841 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RaycastHitData_t5EAB266730389AB27715962670C2512800451841 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m33916FAE71F1DA5215615B4EDDEC7EC00AB57E2B (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_2;
		L_2 = InterfaceFuncInvoker1< RaycastHitData_t5EAB266730389AB27715962670C2512800451841, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mAC87670FB05B0AAEDFA8540073A293C7B7692088 (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m0AFB680989F7183252C477DD7EB9EF59D9C88ECC(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< RaycastHitDataU5BU5D_t98BBA3CE354036B88621172C27ED5C5DD7CB9279*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_35;
			L_35 = InterfaceFuncInvoker1< RaycastHitData_t5EAB266730389AB27715962670C2512800451841, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m330DB679D829648ECF5DEE0E33721487E7FF9595 (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_2;
		L_2 = InterfaceFuncInvoker1< RaycastHitData_t5EAB266730389AB27715962670C2512800451841, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m052B85911C70FD4FE70D220FF791FAF6C6479F83 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	RaycastHitData_t5EAB266730389AB27715962670C2512800451841 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(RaycastHitData_t5EAB266730389AB27715962670C2512800451841));
		RaycastHitData_t5EAB266730389AB27715962670C2512800451841 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mAD0F6827C00D83F54DE41A24AF223A40737989B5 (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m052B85911C70FD4FE70D220FF791FAF6C6479F83(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m37A8647602E0715AC27FDFF43DABCCEF7701AEAB(__this, ((*(RaycastHitData_t5EAB266730389AB27715962670C2512800451841*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m6DBCEC9DA9D6432848242D4594243B56DBD7A15A (ReadOnlyCollection_1_t73DCD6C4D5F3100950AD53A9D36C7DFD67E9D0A6* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m052B85911C70FD4FE70D220FF791FAF6C6479F83(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mE1ABD3A991704C640186283F3DD505E3B9A77BB6(__this, ((*(RaycastHitData_t5EAB266730389AB27715962670C2512800451841*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m409F5776BEB430BE72273C433CC1850CD93700A7 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ReadOnlyCollection_1_get_Item_mC89B10C454A992A80E70F460707E3A96AE6AE1ED (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_2;
		L_2 = InterfaceFuncInvoker1< WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mDF174A6917D3D93C8D7910C91080D253891A1AC5 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m34129B777F4C0D729638A29403265448F67AAB7E (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m3AE0234C0DA1C378A676F109CCB2CE268E405AB4 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mC7204EA734A903659BFE12EFC2FD358391419441 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mB501D0309F1CC0BF9203CF948994D438621201BD (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_2;
		L_2 = InterfaceFuncInvoker1< WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m44BBB5AB33E2C90225D466FD249C45ACCD42465C (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m409F5776BEB430BE72273C433CC1850CD93700A7(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< WorkRequestU5BU5D_t1B912B8BE58CF60CAF3A4FEC0A5C0F5BB6D99577*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_35;
			L_35 = InterfaceFuncInvoker1< WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m6177EFE8D98E3D7B7B5475B10665A5B4A0CED868 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_2;
		L_2 = InterfaceFuncInvoker1< WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m297F49BCB3FD33C8DE274BA917FFF7B708758DB7 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44));
		WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m7BD692E11177D43D9730EE9D3CAE473ED0901007 (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m297F49BCB3FD33C8DE274BA917FFF7B708758DB7(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mDF174A6917D3D93C8D7910C91080D253891A1AC5(__this, ((*(WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mDC76BD09F10EE0179D32F61859653C019393CD2B (ReadOnlyCollection_1_tB59426B63A6357E19EEB6EAD530B26D450DAAD07* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m297F49BCB3FD33C8DE274BA917FFF7B708758DB7(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mC7204EA734A903659BFE12EFC2FD358391419441(__this, ((*(WorkRequest_t8AF542F2E248D9234341817CDB5F76C27D348B44*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m31B5E7F8E3D51CB370BE05608F7B2C3C11EE0C55 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ReadOnlyCollection_1_get_Item_m5AB43596F44CC288DA87BCA19EC8D9CF352BC830 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_2;
		L_2 = InterfaceFuncInvoker1< AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m6057F27D1ACAA9CBF4A9FFC87FDAA2ACC117A809 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m3D5D6472653F81CBBF60F1A4F5FB285FE8FD81F4 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m73A5FD2B15474679BE446FD212642A0DFA1BDACC (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mD865206564138ED88C746288B0A9A6EB96555FC2 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m5CAA0592F9EEFE14B9D85A067D8A48E463BD0255 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_2;
		L_2 = InterfaceFuncInvoker1< AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mE829AA0EB6560D334DE747097153F5A357D552D3 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m31B5E7F8E3D51CB370BE05608F7B2C3C11EE0C55(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< AssetEntryU5BU5D_t83ECF66F13D78425A1AF86967D10F3FA0A0C123F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_35;
			L_35 = InterfaceFuncInvoker1< AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mDA2999BA621C7C5B8E399FFFEBBFEC2075F03CFB (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_2;
		L_2 = InterfaceFuncInvoker1< AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m496DFF37E9CC6DE59F0E2B4E2A5DBEAA32DEAD94 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D));
		AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m01E51474F8560A28BE0B3BC89A91337DBA7CF7D3 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m496DFF37E9CC6DE59F0E2B4E2A5DBEAA32DEAD94(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m6057F27D1ACAA9CBF4A9FFC87FDAA2ACC117A809(__this, ((*(AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mF018250B690D9925EADF086DD08D674AFB5B8D59 (ReadOnlyCollection_1_t32D3583BA30824B44FED94CE41C1088BA7F66C69* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m496DFF37E9CC6DE59F0E2B4E2A5DBEAA32DEAD94(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mD865206564138ED88C746288B0A9A6EB96555FC2(__this, ((*(AssetEntry_tEB6FC90E5BB63DCA4FF932F2D64595339A28806D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m15D679310A0AC97586C8124180F5EB3E1D40A2BC (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ReadOnlyCollection_1_get_Item_m6397C9E0F57C3E4112047E50BA57CF877EF7AA5E (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_2;
		L_2 = InterfaceFuncInvoker1< SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9ADA09E692C504A400AF0D8E4BF59A7C3C2C8F93 (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m9CEC885D66A757E55A1BCAAA81EE56C3331F7C80 (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m5281DA7E199DAF2110C2E3AC674BF46ED6E5A909 (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m942BE9C1C9D8A0392F495981442E058E887308CF (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mADAE772B4BD15F8285463DB5CE3C374B3886B620 (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_2;
		L_2 = InterfaceFuncInvoker1< SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mC35A16F6E2DB9422F719776935632AAC1B8CEF43 (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m15D679310A0AC97586C8124180F5EB3E1D40A2BC(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< SlotDefinitionU5BU5D_t9003D04EBDD74C44DD8490A99624A727154E1299*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_35;
			L_35 = InterfaceFuncInvoker1< SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m1FF003DF50C41FA0FE8F95E3E98170E1AC8394BB (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_2;
		L_2 = InterfaceFuncInvoker1< SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m948DB26D5A8A2DF64E9700A6DEB6F836B10749A3 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8));
		SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m4DABD32E7AACFC8A0443D40D2F09D045E7AE944B (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m948DB26D5A8A2DF64E9700A6DEB6F836B10749A3(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m9ADA09E692C504A400AF0D8E4BF59A7C3C2C8F93(__this, ((*(SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m85B208EB89FC3FC4D4874377BB2FABD4DDB604AB (ReadOnlyCollection_1_tF2ABA1656E36C231EEBB5C7CEED077E4AC8239B7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m948DB26D5A8A2DF64E9700A6DEB6F836B10749A3(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m942BE9C1C9D8A0392F495981442E058E887308CF(__this, ((*(SlotDefinition_t2E39E965BBE5A336DD1B93A115DD01044D1A66F8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m299B4E260E97612F6BFD1965863F5EDB0D80889F (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ReadOnlyCollection_1_get_Item_m60E6A62D890747F1AC1DC730E0D3FCE9D4E02F01 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_2;
		L_2 = InterfaceFuncInvoker1< SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m705B2717517A6E1493976E0F972CEC791692FF97 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mC1257C5457DDC4F101CB1C6E13C3918EDA840EAA (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mE2C132C56C7624052D3E4DD98373FEC71D0C7CB4 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mBE061D69DECDF68D566C15E465E25ECFCE11FCD3 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m10F1544185B2CAC61276C7FC78D4A1E5250030AE (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_2;
		L_2 = InterfaceFuncInvoker1< SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m0AE5422374BE07A750F53B941582E1D7881D19C9 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m299B4E260E97612F6BFD1965863F5EDB0D80889F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< SlotUsageEntryU5BU5D_t02CCAC4881F115443BE39FCBE8439A9DCFC1C67A*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_35;
			L_35 = InterfaceFuncInvoker1< SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m2E8461F31879EC0FA0F5D99691AFAFB5A7346225 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_2;
		L_2 = InterfaceFuncInvoker1< SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mBF48FC95A670E75A65647A9F7520AEB9AE4A0FE6 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76));
		SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m64537CE10B51851FBE9771726AFCC8AAF5CF02C8 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mBF48FC95A670E75A65647A9F7520AEB9AE4A0FE6(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m705B2717517A6E1493976E0F972CEC791692FF97(__this, ((*(SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m199CADD8D916A7510EF043D4D33ADE50B0DFFD37 (ReadOnlyCollection_1_tB75E264D1AFFBCE0E99EF3B6508A1772E4F74135* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mBF48FC95A670E75A65647A9F7520AEB9AE4A0FE6(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mBE061D69DECDF68D566C15E465E25ECFCE11FCD3(__this, ((*(SlotUsageEntry_t73A628038C799E4FD44436E093EC19D2B9EA1B76*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m05F05C64F32981A1BF2CEC3E7589604A188B612B (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ReadOnlyCollection_1_get_Item_mF2270136C87C6CD47C4ED8B9CB895254931977C9 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_2;
		L_2 = InterfaceFuncInvoker1< UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD887308D8602D0A6C687F8B588F772CB0D0911A2 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mDA466383B01D8262103FE86D1BFABC09CADECA76 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m8F53882B80F14E008D7286F26BBF322554B99DBA (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mCC0B8F0541328E20D9E516ACE2AF53B44AA502ED (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m4FF40A61AEA113EF82D13F16B3B2C6BF18B677E3 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_2;
		L_2 = InterfaceFuncInvoker1< UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m26C1285E73FDD195193E87CAE2B53B9D1237EB84 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m05F05C64F32981A1BF2CEC3E7589604A188B612B(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< UsingEntryU5BU5D_t3E321CB1464DE1D2F7FDE3790BD4AD8B72FBE811*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_35;
			L_35 = InterfaceFuncInvoker1< UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mA86767BE1489730FEEF7C9B2F51CADDCB1AFE68A (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_2;
		L_2 = InterfaceFuncInvoker1< UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mBA2972FFD773AA00EC4BAD22D43C97C5FFFD31EA (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484));
		UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mB58F33AA4E890E1EB6DC1BFAA71B1EAE2F5E5B48 (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mBA2972FFD773AA00EC4BAD22D43C97C5FFFD31EA(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mD887308D8602D0A6C687F8B588F772CB0D0911A2(__this, ((*(UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m45B400C577803964484B6C2318A986085887DF6E (ReadOnlyCollection_1_t03DF8DEE56271CB6F01A668065CE8A667D463CC4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mBA2972FFD773AA00EC4BAD22D43C97C5FFFD31EA(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mCC0B8F0541328E20D9E516ACE2AF53B44AA502ED(__this, ((*(UsingEntry_t0454AD34026FDFD1733CE07BD4AE807B0FBCE484*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCB408C9C0EF8BB4EAF3BD9D74210EA1BF645DF9F (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ReadOnlyCollection_1_get_Item_mFD65FE8672CF437F4E56553136F3296603743E5B (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_2;
		L_2 = InterfaceFuncInvoker1< VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mA07C916646443F7E600B771BA5B6E3276CF6F38D (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m373BF4F61459CBD0614937565D50D38211EC389D (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m627A159A926F95C24D2FC6C0A665BAE6B31C6210 (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m24635AF1EE0DBE26C00D1E919C331F3EC3514442 (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mF2CBAC673542C78C4E66A0B63AB25F7E23E426F4 (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_2;
		L_2 = InterfaceFuncInvoker1< VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mB9E303B104B18F639A07B580FCDCB916D8C5F43A (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mCB408C9C0EF8BB4EAF3BD9D74210EA1BF645DF9F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< VersionInfoU5BU5D_tA86713FC86D1EDA523BC741A17D81B20A869AE64*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_35;
			L_35 = InterfaceFuncInvoker1< VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m7FF73F40502F4224B0A39DC1C6E21D7F62ED5320 (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_2;
		L_2 = InterfaceFuncInvoker1< VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mCB5B8ABED8FAA81E9313462E91E846577DBF79E7 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8));
		VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m21250661C6C1891AA59CA1F5DB154974346EB45E (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mCB5B8ABED8FAA81E9313462E91E846577DBF79E7(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mA07C916646443F7E600B771BA5B6E3276CF6F38D(__this, ((*(VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mBDF6671029CE751A5B90318650A9E1266C9FFBAC (ReadOnlyCollection_1_t8D2DFE1EAD5470CAE23C2E0016BE260592A57C65* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mCB5B8ABED8FAA81E9313462E91E846577DBF79E7(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m24635AF1EE0DBE26C00D1E919C331F3EC3514442(__this, ((*(VersionInfo_tD8EF94E6EB7FCB9167CE193F9FFAAB6DE0518DE8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m95888730659343F372198CD5B3EE35B001150127 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ReadOnlyCollection_1_get_Item_m7CD152BDDD7716D36C1C41279EC65D85E8CB336E (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_2;
		L_2 = InterfaceFuncInvoker1< PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m25DB18C9E908096B821F4C692B9190E3B812A1FA (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mB72E3ECC1BD7BE6EF41EAB69D61D4D551D5D7B89 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m25FE1E3664407CBA72B82B60D79E2295FAC8291E (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4D6C6D23DE1E2EE6057F94BDBD946631CC5B2EBC (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mA5BE02C34F89A35C9EB327E73EB8E920D45F7AD0 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_2;
		L_2 = InterfaceFuncInvoker1< PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m4D2D02DA14D0D7C5D53BFB7522B954AD7F0258D9 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m95888730659343F372198CD5B3EE35B001150127(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< PTLightU5BU5D_t9592476161BA9F6C7956249ABC75077F03983DEA*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_35;
			L_35 = InterfaceFuncInvoker1< PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m0ED2777C1644BA763D2847C20D0EB95164641148 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_2;
		L_2 = InterfaceFuncInvoker1< PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mE94C5A9A40442783E8EE309CDBA6395F4842EEB3 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778));
		PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m37A23B07BDB72251DDBBBA222C1B0C5A82E3F8CF (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mE94C5A9A40442783E8EE309CDBA6395F4842EEB3(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m25DB18C9E908096B821F4C692B9190E3B812A1FA(__this, ((*(PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mDC3A7E0D7DDCBBAA2C8CDC52F00594BB83BED3F2 (ReadOnlyCollection_1_t3B7FA21C526038C7FD1E057F004ECA81EF8C6DEF* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mE94C5A9A40442783E8EE309CDBA6395F4842EEB3(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m4D6C6D23DE1E2EE6057F94BDBD946631CC5B2EBC(__this, ((*(PTLight_tBEB70EAD4BA181C3FDAFE151BEB34830CFF92778*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCB4FF2AFAA94D01923F9242ACB66F817F7CF18C7 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ReadOnlyCollection_1_get_Item_m4534A86754FC3150BB56EE056CF44694CFD57C47 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_2;
		L_2 = InterfaceFuncInvoker1< XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m116AE421F0EB30927F6725D62792FFA5A6065627 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m8AA5CBAE562679AFCE7394F17B403AAF1B7890E2 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m183CC0AE8D94E74219F7F9C2466D2F7804BA497B (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mF523F5C22B1C3DFB9577177B1C50F9DC3B9704C2 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m00D2C57ECBF88B874CB68F5C81534469F56A4FEF (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_2;
		L_2 = InterfaceFuncInvoker1< XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m4C097801325D2332FC1A226D23825CFF771B6ED6 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mCB4FF2AFAA94D01923F9242ACB66F817F7CF18C7(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< XmlSchemaObjectEntryU5BU5D_tBCEE5881A0EF3ACBC998EFA679ACBF1ED8256E27*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_35;
			L_35 = InterfaceFuncInvoker1< XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mEA0B17247D97DD5D3CB64691624A04D50BCA99A1 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_2;
		L_2 = InterfaceFuncInvoker1< XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC5B4A17FCA21C2DF1F66767E828535AD34B90513 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD));
		XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mBD795131F32122B764751DC7B95C0ED36D0371AA (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC5B4A17FCA21C2DF1F66767E828535AD34B90513(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m116AE421F0EB30927F6725D62792FFA5A6065627(__this, ((*(XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mCCDA3835E895D0768BB7B32D130DDF9C4FD557C8 (ReadOnlyCollection_1_t9309D20294B0D49BDEA1E5D7CF07BB04A6F32568* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC5B4A17FCA21C2DF1F66767E828535AD34B90513(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mF523F5C22B1C3DFB9577177B1C50F9DC3B9704C2(__this, ((*(XmlSchemaObjectEntry_t79D1310E1F5CA860FAD243853E59A3C2ACDB83CD*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8458978F11950358DAF515D9793F94E96E164867 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ReadOnlyCollection_1_get_Item_m27C60ADC9D3F27B6DE1E527CB213B2F315F09971 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_2;
		L_2 = InterfaceFuncInvoker1< VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mE296E176CF781CFBEDEA890CD7B7438707C5CBC2 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m242D80A80BCA864DE06422CE7A0AD846E91870C3 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mBCFE48F26F4626AE0ECC7E048A8CE902E619C243 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m25AC6AFADC9DA3C7616FB3DF2538489069FE82FF (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m79AFAF6B4C025D04CED3F7A6CEEE4C0AEDF09FC0 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_2;
		L_2 = InterfaceFuncInvoker1< VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mC52C7CC07686EB43525D65DC943ACD1CF6E38106 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m8458978F11950358DAF515D9793F94E96E164867(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< VolumeParameterChainU5BU5D_t0474622D9FD8B1CC198D56824468949D1E1C680F*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_35;
			L_35 = InterfaceFuncInvoker1< VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m1B4F3750ED4A1C2557520A532E4AE71F1F78870E (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_2;
		L_2 = InterfaceFuncInvoker1< VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m0F15E0EC055DA3F521E73184206A61A28D6E1C0F (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E));
		VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m30D3408DB81CC07D32C804A176F112FD8627B192 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0F15E0EC055DA3F521E73184206A61A28D6E1C0F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mE296E176CF781CFBEDEA890CD7B7438707C5CBC2(__this, ((*(VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m70B38A80F2FAF67F7336339F89B2A3851478DA77 (ReadOnlyCollection_1_t94E1EAD664D431DAF5233CA9EF20FF855C992227* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m0F15E0EC055DA3F521E73184206A61A28D6E1C0F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m25AC6AFADC9DA3C7616FB3DF2538489069FE82FF(__this, ((*(VolumeParameterChain_tF0AF946FA26C5D61B2713BA220DD70D041EAA35E*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_mCFEB25EF1344B976A050CB6937362A3F5DF0199A (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ReadOnlyCollection_1_get_Item_mB4FBA6653B45B885F77168D2A31246E86A61239C (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_2;
		L_2 = InterfaceFuncInvoker1< ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3CAC4C8BA133B39A5BA9FA0A1E0E711E09BD7694 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m98B2AA9918F58E13BC7615C283CD2A2B5AC5BA2F (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mAA1BF20823EFD08F455F9177A2BADBCF07470285 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mE8080B23EA1AD670E7D7D77D172A6973A222ED2C (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mD2A608FF40630292908E8D69A6102C27001FC717 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_2;
		L_2 = InterfaceFuncInvoker1< ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mCF1AC1CDAFDA110866DACF9EE9A70AEC9AA0BE4D (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_mCFEB25EF1344B976A050CB6937362A3F5DF0199A(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< ContextMenuItemU5BU5D_tFD4FC81929646BCD206377E2AC8E290E93FEE279*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_35;
			L_35 = InterfaceFuncInvoker1< ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m8EAA569D28A7BEE2BF68701BDCE7E3F7230F0A39 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_2;
		L_2 = InterfaceFuncInvoker1< ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m3A0010FDAC2908AF80DDEB4BA4458869F0FE9F8F (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9));
		ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m67E991E768D997905AAE39961F6EE846E0859535 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m3A0010FDAC2908AF80DDEB4BA4458869F0FE9F8F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m3CAC4C8BA133B39A5BA9FA0A1E0E711E09BD7694(__this, ((*(ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mDE2CF32E3C5F436DD6FA819744A0876F36859728 (ReadOnlyCollection_1_t4E57872B64C17ACE2E87B5BBEEB28AB5B627DDBC* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m3A0010FDAC2908AF80DDEB4BA4458869F0FE9F8F(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mE8080B23EA1AD670E7D7D77D172A6973A222ED2C(__this, ((*(ContextMenuItem_t0D29D1ECB0C1F769EFC9ACA2D0AE6B1A8A4736A9*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m88DC99D667337D16893CDF63694D22FEAF331E05 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ReadOnlyCollection_1_get_Item_m0A91A846BBC91E711D2FD276F926C8622F725207 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_2;
		L_2 = InterfaceFuncInvoker1< LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m9FE5CCC2B059229D4C97248D4F5E82C20ECB5FBE (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m2E2F7FE9FE98257542D040CCB5A505040BB765DD (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m77826D7B702325BB85B22D685A41A3BDBF2E6DFE (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m093DAAF13F65B6DE09B24D00F36FCC13F61E6E15 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m00749260A028B5DAE550D78E7C08AA80CB178383 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_2;
		L_2 = InterfaceFuncInvoker1< LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m97E025565D89BA957D0D7595F9930CB1EBA802FD (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m88DC99D667337D16893CDF63694D22FEAF331E05(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< LayoutMatcherU5BU5D_t790C71C3787F12C3EE9F7ABDC24DFCEB5281F90E*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_35;
			L_35 = InterfaceFuncInvoker1< LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m91FB5557DA051340EECCD4F9A13275A509B5379B (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_2;
		L_2 = InterfaceFuncInvoker1< LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m9E692C71C0193F22ACD65EEFBA4ECA75E5C53AAD (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6));
		LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m07AAC581ACA363E09C760153D0F5634069AAEF43 (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m9E692C71C0193F22ACD65EEFBA4ECA75E5C53AAD(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m9FE5CCC2B059229D4C97248D4F5E82C20ECB5FBE(__this, ((*(LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m28EE46B044CC3F881E8EEF91F1FB3C37C601376C (ReadOnlyCollection_1_t219F9DE246A267F098345182628B7967858ED247* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m9E692C71C0193F22ACD65EEFBA4ECA75E5C53AAD(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m093DAAF13F65B6DE09B24D00F36FCC13F61E6E15(__this, ((*(LayoutMatcher_t0D8F5E32A7C82BC292EBA0FAA3EB2D9F1F72A0A6*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m283266AC4D77DC2424BDBD9CB125A1A61AB55E1C (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ReadOnlyCollection_1_get_Item_m7AC6E00BD2F6EA75A1E1B09ED4B82A4098110EF3 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_2;
		L_2 = InterfaceFuncInvoker1< InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m7535255C244884FCE69E71A597A10D82C38A21AB (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mA1B55098F63BA27BE711D1D31130C38B32CB2736 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mDAEDE4966E056491EDD88CFC26EDCADE3C46EA26 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m07CEF5EB192EFDA22EC079165EEE0F82A03E5FD7 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m1B2ADAE698787A805757D5552B8621296703F2E9 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_2;
		L_2 = InterfaceFuncInvoker1< InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m9742AA735CF66DE2EBB0A96F4D32E09171B49041 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m283266AC4D77DC2424BDBD9CB125A1A61AB55E1C(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< InstructionViewU5BU5D_t2A200DCB627CD67C1DDBD22595A355894F2646A3*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_35;
			L_35 = InterfaceFuncInvoker1< InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_m24710EB1D21C4B8F4BB3D9D2056EFCB3DE939181 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_2;
		L_2 = InterfaceFuncInvoker1< InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mD7979063F69DBCBBA075F88868B40DE92ED347FC (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D));
		InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mC2D64D9B1CEC419CEF540449FBC051217E2AA963 (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mD7979063F69DBCBBA075F88868B40DE92ED347FC(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m7535255C244884FCE69E71A597A10D82C38A21AB(__this, ((*(InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mF41F8CBA905BB1AB7C399429BF5691110460D2BB (ReadOnlyCollection_1_tB919AFBB5D00764975FBCFA46BD779234DFFA466* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mD7979063F69DBCBBA075F88868B40DE92ED347FC(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m07CEF5EB192EFDA22EC079165EEE0F82A03E5FD7(__this, ((*(InstructionView_tA381D8A27DEDDEE43C71B3BB3A2FADC0CD059A3D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m818A3E47FE33091DD1275D2DFDF70695E715E185 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ReadOnlyCollection_1_get_Item_m6EB60D34CA0BE21AE6C2908D8CE1058DEFEC7ACC (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_2;
		L_2 = InterfaceFuncInvoker1< PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_m3006B42AEF364FAED734490926CA034ED5348569 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_m2D5B34537E9E88D61CE6DE65DA8E4ED641EB3412 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m21221C7CFD70D8A1E5963C9CDB0967B1361B8862 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m4D42E127F9A2F6A6D223785F8CA656A4930B87C2 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mF564FD5A7A7060A271DCFBBC8A415AB7A76F20C1 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_2;
		L_2 = InterfaceFuncInvoker1< PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_mF9EA85ACDC0EF457938D363BAFC351F38291161D (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m818A3E47FE33091DD1275D2DFDF70695E715E185(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< PassDataU5BU5D_tF21A03049926F4AE1289DBF568C76ED64042A9FC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_35;
			L_35 = InterfaceFuncInvoker1< PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mB766727BF7DB38B182F8140AA0BFF30A2876EE26 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_2;
		L_2 = InterfaceFuncInvoker1< PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m9E090EF8DAC5EB1362F55C11AC2FD29FE307A954 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F));
		PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mBB60F8752EE0A063BE174C1034872A826F05E331 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m9E090EF8DAC5EB1362F55C11AC2FD29FE307A954(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_m3006B42AEF364FAED734490926CA034ED5348569(__this, ((*(PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mEAFE167288B6716BC550C1AEDEC66E25A61C8E18 (ReadOnlyCollection_1_t5B9BEDC95C484389997D167F070E30505719DE4D* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m9E090EF8DAC5EB1362F55C11AC2FD29FE307A954(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m4D42E127F9A2F6A6D223785F8CA656A4930B87C2(__this, ((*(PassData_t70EFDE0ED44B50E9E144E803C17DE2373723887F*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m0730B9BAC8092A41B1C48042F79C306FD18E553F (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ReadOnlyCollection_1_get_Item_mF9FA72847D5DA338D66D016E4FB297385FB9A42E (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_2;
		L_2 = InterfaceFuncInvoker1< ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD6916963F70388076B4D8A005C8C1AC7DB630642 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mA42C7EDA1BAF578D320D80F48E0647C110ADD681 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mB84E20F8BA5119B21FD4984601C9A70C64C57C52 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mEAC3EE66A5CB94BE471210EA64A682C55D8463D0 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mA1A935A7DA00C54303DF2E52B8AFCFC4BA64E51A (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_2;
		L_2 = InterfaceFuncInvoker1< ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m3CC70612B859C690D9C3531703CE753DF1B647EC (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m0730B9BAC8092A41B1C48042F79C306FD18E553F(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< ResourceDataU5BU5D_t7EB547044DA870E25BACFEDEFCCD7821FE72022B*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_35;
			L_35 = InterfaceFuncInvoker1< ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mB71CAA326A4ACDF03E75906564872A478196DBF9 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_2;
		L_2 = InterfaceFuncInvoker1< ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_m718A868545EA0ABD0015911A27C3815E8A95752D (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3));
		ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mCE36C4978C8E258E0C77969A66E4C55E374D1CB8 (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m718A868545EA0ABD0015911A27C3815E8A95752D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mD6916963F70388076B4D8A005C8C1AC7DB630642(__this, ((*(ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m5DADB45967A9C3E8795B4E777233868592A3956E (ReadOnlyCollection_1_t6354AFE67B5ECFE646A867BDA68157E8795ED5B4* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_m718A868545EA0ABD0015911A27C3815E8A95752D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mEAC3EE66A5CB94BE471210EA64A682C55D8463D0(__this, ((*(ResourceData_t78BFD0FF4432C51882F5558EEDF6A8925F4F28B3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m8B2AEA509E07E389B797D3576C0DDF9A5551E3A4 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ReadOnlyCollection_1_get_Item_m586F777658B145682E70A3FCE202B5FEE78F8F18 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_2;
		L_2 = InterfaceFuncInvoker1< EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mD750C5DD43B49E3369FF1CC3778B43D83F58636E (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mF318B9F02EA7AE7C2734AC064B64ED94C16F8798 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_m7C08CE459BEEDC1DF2952F054F69A3482C2433F6 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_mDA0A610D1FE508DC17DABD5A4D5D861295857416 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_m5D48D4159D5115984C187FE5B07D9140556FDA49 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_2;
		L_2 = InterfaceFuncInvoker1< EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m8958097E6E660BACA1709F0424DE966BF89439FD (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m8B2AEA509E07E389B797D3576C0DDF9A5551E3A4(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< EntryProcessingInfoU5BU5D_tAB0CBF4A4379F39BA667FBBFCB22E4174C4D319B*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_35;
			L_35 = InterfaceFuncInvoker1< EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mAC7741CB7BECB294DA1E38E3745C58853F0A197A (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_2;
		L_2 = InterfaceFuncInvoker1< EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC9A90AF46B6E7EC8BC710283B87EB110801FAB1B (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289));
		EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_mC6029EF4ADA5CF37C75A5D189C30F6EEF696996C (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC9A90AF46B6E7EC8BC710283B87EB110801FAB1B(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mD750C5DD43B49E3369FF1CC3778B43D83F58636E(__this, ((*(EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_mF634A5AA11D90AB73EE09FC2DA892D8C98BD76E1 (ReadOnlyCollection_1_t537840A047E12157FC8F008F8986460D6E1ED235* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC9A90AF46B6E7EC8BC710283B87EB110801FAB1B(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_mDA0A610D1FE508DC17DABD5A4D5D861295857416(__this, ((*(EntryProcessingInfo_tE4803801829E2739380552B9DE313B056A9C9289*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11152
// Method Definition Index: 11153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_get_Count_m5BD62585103C935CC4B20021B610D1D480BE6F19 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ReadOnlyCollection_1_get_Item_mDB5391F21C03A541CD55AAEEDE20775B401A9B0F (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_2;
		L_2 = InterfaceFuncInvoker1< PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_Contains_mC061A8BAB0855DF9F3365468CFE7C6897B27DB66 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_1 = ___0_value;
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1< bool, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_CopyTo_mDCD28C7482420D9DBA17845A440A0928A68429FA (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317* L_1 = ___0_array;
		int32_t L_2 = ___1_index;
		NullCheck(L_0);
		InterfaceActionInvoker2< PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_GetEnumerator_mD96010D6ACA8DBED4391371570F48D8592665CE9 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 11158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_IndexOf_m91DD8D51560F4B4A6690B2B4DCF114816973A693 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InterfaceFuncInvoker1< int32_t, PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11159
// Method Definition Index: 11160
// Method Definition Index: 11161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 ReadOnlyCollection_1_System_Collections_Generic_IListU3CTU3E_get_Item_mFDAFCF3888D2F84E5825B20EB17C904A41553B12 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_2;
		L_2 = InterfaceFuncInvoker1< PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11162
// Method Definition Index: 11163
// Method Definition Index: 11164
// Method Definition Index: 11165
// Method Definition Index: 11166
// Method Definition Index: 11167
// Method Definition Index: 11168
// Method Definition Index: 11169
// Method Definition Index: 11170
// Method Definition Index: 11171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1_System_Collections_ICollection_CopyTo_m47B9326BE9528881CB7336D37DFE3226E23E55FE (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317* V_0 = NULL;
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
		L_9 = ReadOnlyCollection_1_get_Count_m5BD62585103C935CC4B20021B610D1D480BE6F19(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
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
		V_0 = ((PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317*)IsInstSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)));
		PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317* L_11 = V_0;
		if (!L_11)
		{
			goto IL_005e;
		}
	}
	{
		RuntimeObject* L_12 = __this->___list;
		PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317* L_13 = V_0;
		int32_t L_14 = ___1_index;
		NullCheck(L_12);
		InterfaceActionInvoker2< PassCompatibilityInfoU5BU5D_t7B46D72837B465DBE4D623FD609B34DE43FE3317*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_12, L_13, L_14);
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
			PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_35;
			L_35 = InterfaceFuncInvoker1< PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_33, L_34);
			PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_36 = L_35;
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
// Method Definition Index: 11172
// Method Definition Index: 11173
// Method Definition Index: 11174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyCollection_1_System_Collections_IList_get_Item_mFB260CCC81131D42BBC60B530874B1242ACE93FB (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___list;
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_2;
		L_2 = InterfaceFuncInvoker1< PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_0, L_1);
		PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4), &L_3);
		return L_4;
	}
}
// Method Definition Index: 11175
// Method Definition Index: 11176
// Method Definition Index: 11177
// Method Definition Index: 11178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_IsCompatibleObject_mC38E543F0BA4C1931B8FDCDA225802CE37FBD971 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 V_0;
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
		il2cpp_codegen_initobj((&V_0), sizeof(PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3));
		PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3 L_2 = V_0;
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
// Method Definition Index: 11179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyCollection_1_System_Collections_IList_Contains_m8711E20808D5FAEED1F14B95371E43C309AD8B31 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC38E543F0BA4C1931B8FDCDA225802CE37FBD971(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		bool L_3;
		L_3 = ReadOnlyCollection_1_Contains_mC061A8BAB0855DF9F3365468CFE7C6897B27DB66(__this, ((*(PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyCollection_1_System_Collections_IList_IndexOf_m3A46C0E6A81DD7844E346E5E9A60C5AB27538505 (ReadOnlyCollection_1_tC4D78C5AC16950429CBABEB2E20BE027AD31F434* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = ReadOnlyCollection_1_IsCompatibleObject_mC38E543F0BA4C1931B8FDCDA225802CE37FBD971(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_value;
		int32_t L_3;
		L_3 = ReadOnlyCollection_1_IndexOf_m91DD8D51560F4B4A6690B2B4DCF114816973A693(__this, ((*(PassCompatibilityInfo_tD79DCD78EC09F9D22A9E203048C684EEC9C237F3*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 4)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
// Method Definition Index: 11181
// Method Definition Index: 11182
// Method Definition Index: 11183
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11200
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* ReadOnlyDictionary_2_get_Keys_m3D38C4849A0CBA72A3BEC65E1F8DBBEA252E34F0_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_001e;
		}
	}
	{
		RuntimeObject* L_1 = __this->___m_dictionary;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(2, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_1);
		KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* L_3 = (KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2));
		((  void (*) (KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3)))(L_3, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		__this->____keys = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_3);
	}

IL_001e:
	{
		KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* L_4 = __this->____keys;
		return L_4;
	}
}
// Method Definition Index: 11201
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* ReadOnlyDictionary_2_get_Values_m8896F49C0945D79E3B09562D2CDC7582F2FD7328_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_001e;
		}
	}
	{
		RuntimeObject* L_1 = __this->___m_dictionary;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(3, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_1);
		ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* L_3 = (ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5));
		((  void (*) (ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))(L_3, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		__this->____values = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_3);
	}

IL_001e:
	{
		ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* L_4 = __this->____values;
		return L_4;
	}
}
// Method Definition Index: 11202
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_ContainsKey_mE23701A23F87A60B1BCF98D9292D94BB14ADE64C_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, Il2CppFullySharedGenericAny ___0_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? ___0_key : &___0_key), SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
		NullCheck(L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1Invoker< bool, Il2CppFullySharedGenericAny >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? L_1: *(void**)L_1));
		return L_2;
	}
}
// Method Definition Index: 11203
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_Generic_IDictionaryU3CTKeyU2CTValueU3E_get_Keys_mBEBC84C1F5E1B11D0450837253B41C389D74FABF_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* L_0;
		L_0 = ((  KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* (*) (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 11204
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_TryGetValue_m1E53DEAAC0A4FA6EA9A62FD6CAE08C28094D206B_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, Il2CppFullySharedGenericAny ___0_key, Il2CppFullySharedGenericAny* ___1_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? ___0_key : &___0_key), SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
		Il2CppFullySharedGenericAny* L_2 = ___1_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = InterfaceFuncInvoker2Invoker< bool, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(7, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? L_1: *(void**)L_1), L_2);
		return L_3;
	}
}
// Method Definition Index: 11205
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_Generic_IDictionaryU3CTKeyU2CTValueU3E_get_Values_m48CD0FA2868BA87C697AA1271790FCFD0D38ED69_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* L_0;
		L_0 = ((  ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* (*) (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 11206
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_get_Item_m7C1B738861802341266E872538431A816B1507A2_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, Il2CppFullySharedGenericAny ___0_key, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const uint32_t SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? ___0_key : &___0_key), SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
		NullCheck(L_0);
		InterfaceActionInvoker2Invoker< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? L_1: *(void**)L_1), (Il2CppFullySharedGenericAny*)L_2);
		il2cpp_codegen_memcpy(il2cppRetVal, L_2, SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1);
		return;
	}
}
// Method Definition Index: 11207
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_Generic_IDictionaryU3CTKeyU2CTValueU3E_Add_m760232769BCF4D542ADC3675CDFB72C49999896D_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, Il2CppFullySharedGenericAny ___0_key, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11208
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_Generic_IDictionaryU3CTKeyU2CTValueU3E_Remove_mD8EBB6AFBE0B504354FA2AD3C925191E6609F731_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, Il2CppFullySharedGenericAny ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11209
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_Generic_IDictionaryU3CTKeyU2CTValueU3E_get_Item_m9574ECF6ECDBFB0B78285A7C8AFF03FD2B4013D6_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, Il2CppFullySharedGenericAny ___0_key, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const uint32_t SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? ___0_key : &___0_key), SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
		NullCheck(L_0);
		InterfaceActionInvoker2Invoker< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 0), L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? L_1: *(void**)L_1), (Il2CppFullySharedGenericAny*)L_2);
		il2cpp_codegen_memcpy(il2cppRetVal, L_2, SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1);
		return;
	}
}
// Method Definition Index: 11210
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_Generic_IDictionaryU3CTKeyU2CTValueU3E_set_Item_m04BE92540AEBDD07DF1A30D6736F68317A8086B1_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, Il2CppFullySharedGenericAny ___0_key, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11211
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyDictionary_2_get_Count_m570BC218FBF8EE3D7E5551E874DF20638F397CA7_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		NullCheck((RuntimeObject*)L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 14), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11212
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m1911E89A7546D2C7F1DD67B61404C8B3D00A36EE_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_1 = alloca(SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		il2cpp_codegen_memcpy(L_1, ___0_item, SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
		NullCheck((RuntimeObject*)L_0);
		bool L_2;
		L_2 = InterfaceFuncInvoker1Invoker< bool, KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 >::Invoke(4, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 14), (RuntimeObject*)L_0, L_1);
		return L_2;
	}
}
// Method Definition Index: 11213
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_mF57A320EF60929F01E8B81CEA0B003EFF819CB79_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57* L_1 = ___0_array;
		int32_t L_2 = ___1_arrayIndex;
		NullCheck((RuntimeObject*)L_0);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 14), (RuntimeObject*)L_0, L_1, L_2);
		return;
	}
}
// Method Definition Index: 11214
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_get_IsReadOnly_m95064FB8DE29991E11D317B1112868234B687EB6_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)1;
	}
}
// Method Definition Index: 11215
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_mE36881BC770002B4BFB810CDD84B88FE8500A55F_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11216
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Clear_mFB7C727CCCA77F742773A4537B99A5042C48DBF3_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11217
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_mD21C9806294C21C66C48BBCC7124FF9F72753A08_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11218
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_GetEnumerator_m3FFC97D7546675C2514644991A7E196D5039E5AB_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 19), (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11219
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_IEnumerable_GetEnumerator_mE28E564A8649570EA9A1CE7107DF7E5FE7A21EFD_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		NullCheck((RuntimeObject*)L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var, (RuntimeObject*)L_0);
		return L_1;
	}
}
// Method Definition Index: 11220
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_IsCompatibleKey_m4D74774D18B06ACA450E3D355EF8398353B677EE_fshared (RuntimeObject* ___0_key, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7D028CCE3B6E7B61AE2C752D7AE970DA04AB7C6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeObject* L_2 = ___0_key;
		return (bool)((!(((RuntimeObject*)(RuntimeObject*)((RuntimeObject*)IsInst((RuntimeObject*)L_2, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)))) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
	}
}
// Method Definition Index: 11221
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_IDictionary_Add_mFD7ED5C86355FB8D05C1209AFBB8A79B6E0BA797_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11222
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_IDictionary_Clear_mFAE5622F79BFAADCDA0C21C758D1B6AA49D32017_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11223
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_IDictionary_Contains_m24123A7F88C2C800C9037836C4773B3A18A54275_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_key;
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_key;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7), L_3);
		bool L_5;
		L_5 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		return L_5;
	}

IL_0015:
	{
		return (bool)0;
	}
}
// Method Definition Index: 11224
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_IDictionary_GetEnumerator_m0285CEE9474EAA483097CF2480942BC24E6E3BF7_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	{
		RuntimeObject* L_0 = __this->___m_dictionary;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_0, IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220_il2cpp_TypeInfo_var));
		RuntimeObject* L_1 = V_0;
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		RuntimeObject* L_2 = V_0;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(9, IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220_il2cpp_TypeInfo_var, L_2);
		return L_3;
	}

IL_0016:
	{
		RuntimeObject* L_4 = __this->___m_dictionary;
		DictionaryEnumerator_tA07B53C91CCF243B3DDF48825CD4F71A6835CD77 L_5;
		memset((&L_5), 0, sizeof(L_5));
		DictionaryEnumerator__ctor_mA1A62AF5ED8AB1B514BBAAAEA9BB3D081C3AA4ED((&L_5), L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		DictionaryEnumerator_tA07B53C91CCF243B3DDF48825CD4F71A6835CD77 L_6 = L_5;
		RuntimeObject* L_7 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24), &L_6);
		return (RuntimeObject*)L_7;
	}
}
// Method Definition Index: 11225
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_IDictionary_get_IsFixedSize_mADA2A7D8798B25E2D5AA76D0DB7B68F18BB4FF70_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)1;
	}
}
// Method Definition Index: 11226
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_IDictionary_get_IsReadOnly_mCADBA490FFA90323B8FEDC38CD78141C54CC10DF_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)1;
	}
}
// Method Definition Index: 11227
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_IDictionary_get_Keys_m203F3078EE234F53D90604EFDC9609D2B90B219B_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* L_0;
		L_0 = ((  KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* (*) (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 11228
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_IDictionary_Remove_mCC94C51FD44D29ACE9EBBA8BF55A9BED1EE617D8_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11229
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_IDictionary_get_Values_m4592B94799170DC13E0F5BDD221769C548BCD680_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* L_0;
		L_0 = ((  ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* (*) (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 11230
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_IDictionary_get_Item_m5EB78E7B173088D4B73585597F8C1AA9A61E2720_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	const uint32_t SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_key;
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		if (!L_1)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject* L_2 = ___0_key;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7), L_3);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))), (Il2CppFullySharedGenericAny*)L_5);
		RuntimeObject* L_6 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13), L_5);
		return L_6;
	}

IL_001a:
	{
		return NULL;
	}
}
// Method Definition Index: 11231
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_IDictionary_set_Item_mCFEB082FB514C3C58C6C908B833CC7FF5B5A6D6A_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE7AF8BCE7F42000322C784E007AAB43CA3E3D9AB)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
// Method Definition Index: 11232
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyDictionary_2_System_Collections_ICollection_CopyTo_mB747FA5969557062AD3E00EF54BC5185C08504E7_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
	const uint32_t SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const uint32_t SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13));
	const Il2CppFullySharedGenericAny L_34 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	const Il2CppFullySharedGenericAny L_53 = L_34;
	const Il2CppFullySharedGenericAny L_55 = alloca(SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3);
	const Il2CppFullySharedGenericAny L_36 = alloca(SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1);
	const Il2CppFullySharedGenericAny L_54 = L_36;
	const Il2CppFullySharedGenericAny L_56 = alloca(SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1);
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_30 = alloca(SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_49 = L_30;
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_57 = alloca(SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
	//<source_info:<no-source>:1>
	KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 V_3 = alloca(SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
	memset(V_3, 0, SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 V_5 = alloca(SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
	memset(V_5, 0, SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
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
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0022:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0036;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0036:
	{
		int32_t L_8 = ___1_index;
		if ((((int32_t)L_8) < ((int32_t)0)))
		{
			goto IL_0043;
		}
	}
	{
		int32_t L_9 = ___1_index;
		RuntimeArray* L_10 = ___0_array;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = il2cpp_codegen_array_get_length(L_10);
		if ((((int32_t)L_9) <= ((int32_t)L_11)))
		{
			goto IL_0053;
		}
	}

IL_0043:
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_12 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mE5B2755F0BEA043CACF915D5CE140859EE58FA66(L_12, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_12, method);
	}

IL_0053:
	{
		RuntimeArray* L_13 = ___0_array;
		NullCheck(L_13);
		int32_t L_14;
		L_14 = il2cpp_codegen_array_get_length(L_13);
		int32_t L_15 = ___1_index;
		int32_t L_16;
		L_16 = ((  int32_t (*) (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_14, L_15))) >= ((int32_t)L_16)))
		{
			goto IL_006e;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_17 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3ECE023333DCF45DE7B1FEAFFE30E295210DDD9B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_006e:
	{
		RuntimeArray* L_18 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57*)IsInstSealed((RuntimeObject*)L_18, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 27)));
		KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57* L_19 = V_0;
		if (!L_19)
		{
			goto IL_0086;
		}
	}
	{
		RuntimeObject* L_20 = __this->___m_dictionary;
		KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57* L_21 = V_0;
		int32_t L_22 = ___1_index;
		NullCheck((RuntimeObject*)L_20);
		InterfaceActionInvoker2< KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 14), (RuntimeObject*)L_20, L_21, L_22);
		return;
	}

IL_0086:
	{
		RuntimeArray* L_23 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_23, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_24 = V_1;
		if (!L_24)
		{
			goto IL_00e2;
		}
	}
	{
		RuntimeObject* L_25 = __this->___m_dictionary;
		NullCheck((RuntimeObject*)L_25);
		RuntimeObject* L_26;
		L_26 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 19), (RuntimeObject*)L_25);
		V_2 = L_26;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00d8:
			{
				{
					RuntimeObject* L_27 = V_2;
					if (!L_27)
					{
						goto IL_00e1;
					}
				}
				{
					RuntimeObject* L_28 = V_2;
					NullCheck((RuntimeObject*)L_28);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_28);
				}

IL_00e1:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00ce_1;
			}

IL_009e_1:
			{
				RuntimeObject* L_29 = V_2;
				NullCheck(L_29);
				InterfaceActionInvoker1Invoker< KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 28), L_29, (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)L_30);
				il2cpp_codegen_memcpy(V_3, L_30, SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
				DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_31 = V_1;
				int32_t L_32 = ___1_index;
				int32_t L_33 = L_32;
				___1_index = ((int32_t)il2cpp_codegen_add(L_33, 1));
				InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_3, (Il2CppFullySharedGenericAny*)L_34);
				RuntimeObject* L_35 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7), L_34);
				InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_3, (Il2CppFullySharedGenericAny*)L_36);
				RuntimeObject* L_37 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13), L_36);
				DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_38;
				memset((&L_38), 0, sizeof(L_38));
				DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_38), L_35, L_37, NULL);
				NullCheck(L_31);
				(L_31)->SetAt(static_cast<il2cpp_array_size_t>(L_33), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_38);
			}

IL_00ce_1:
			{
				RuntimeObject* L_39 = V_2;
				NullCheck((RuntimeObject*)L_39);
				bool L_40;
				L_40 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_39);
				if (L_40)
				{
					goto IL_009e_1;
				}
			}
			{
				goto IL_0153;
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

IL_00e2:
	{
		RuntimeArray* L_41 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_41, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_42 = V_4;
		if (L_42)
		{
			goto IL_00f9;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_43 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_43, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_43, method);
	}

IL_00f9:
	{
	}
	try
	{
		{
			RuntimeObject* L_44 = __this->___m_dictionary;
			NullCheck((RuntimeObject*)L_44);
			RuntimeObject* L_45;
			L_45 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 19), (RuntimeObject*)L_44);
			V_2 = L_45;
		}
		{
			auto __finallyBlock = il2cpp::utils::Finally([&]
			{

FINALLY_013b_1:
				{
					{
						RuntimeObject* L_46 = V_2;
						if (!L_46)
						{
							goto IL_0144_1;
						}
					}
					{
						RuntimeObject* L_47 = V_2;
						NullCheck((RuntimeObject*)L_47);
						InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_47);
					}

IL_0144_1:
					{
						return;
					}
				}
			});
			try
			{
				{
					goto IL_0131_2;
				}

IL_0108_2:
				{
					RuntimeObject* L_48 = V_2;
					NullCheck(L_48);
					InterfaceActionInvoker1Invoker< KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 28), L_48, (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)L_49);
					il2cpp_codegen_memcpy(V_5, L_49, SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
					ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_50 = V_4;
					int32_t L_51 = ___1_index;
					int32_t L_52 = L_51;
					___1_index = ((int32_t)il2cpp_codegen_add(L_52, 1));
					InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_5, (Il2CppFullySharedGenericAny*)L_53);
					InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_5, (Il2CppFullySharedGenericAny*)L_54);
					memset(L_57, 0, SizeOf_KeyValuePair_2_t0239F3881F4C8BE84CFABF0F90DFD19A583B6C95);
					KeyValuePair_2__ctor_mD82E516936D2BDE6D46C8C45270250647986231E((KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)L_57, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) ? il2cpp_codegen_memcpy(L_55, L_53, SizeOf_TKey_t6CF24411882409C9C594E33E1DFE77DBD6BBA1B3): *(void**)L_53), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13)) ? il2cpp_codegen_memcpy(L_56, L_54, SizeOf_TValue_t43EDFC56FE2495E1ED9690FFC4BE75C460E759B1): *(void**)L_54), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
					RuntimeObject* L_58 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16), L_57);
					NullCheck(L_50);
					ArrayElementTypeCheck (L_50, L_58);
					(L_50)->SetAt(static_cast<il2cpp_array_size_t>(L_52), (RuntimeObject*)L_58);
				}

IL_0131_2:
				{
					RuntimeObject* L_59 = V_2;
					NullCheck((RuntimeObject*)L_59);
					bool L_60;
					L_60 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_59);
					if (L_60)
					{
						goto IL_0108_2;
					}
				}
				{
					goto IL_0145_1;
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

IL_0145_1:
		{
			goto IL_0153;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0147;
		}
		throw e;
	}

CATCH_0147:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_61 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_62 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_62, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_62, method);
	}

IL_0153:
	{
		return;
	}
}
// Method Definition Index: 11233
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyDictionary_2_System_Collections_ICollection_get_IsSynchronized_m775918D51697D5404B898ACB89208A1498A46CB3_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return (bool)0;
	}
}
// Method Definition Index: 11234
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_ICollection_get_SyncRoot_mE06D92F6EEC7E9C3245A31B7B75DE348212F59F7_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	RuntimeObject* V_0 = NULL;
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_0037;
		}
	}
	{
		RuntimeObject* L_1 = __this->___m_dictionary;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0025;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(2, ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var, L_3);
		__this->____syncRoot = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____syncRoot), (void*)L_4);
		goto IL_0037;
	}

IL_0025:
	{
		RuntimeObject** L_5 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_6 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_6, NULL);
		RuntimeObject* L_7;
		L_7 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, NULL);
	}

IL_0037:
	{
		RuntimeObject* L_8 = __this->____syncRoot;
		return L_8;
	}
}
// Method Definition Index: 11235
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_Generic_IReadOnlyDictionaryU3CTKeyU2CTValueU3E_get_Keys_m5517F5B43EFB878E6A1DB24A9DA5C2B0A6C2FB65_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* L_0;
		L_0 = ((  KeyCollection_t77347D5E6080A99487985EFA49C429DAC62A4221* (*) (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 11236
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnlyDictionary_2_System_Collections_Generic_IReadOnlyDictionaryU3CTKeyU2CTValueU3E_get_Values_mFD4DE52E42982BE1C72AB6314736968DEA611E37_fshared (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* L_0;
		L_0 = ((  ValueCollection_tBD303C20E55147B0A354B6AD8C7779ABBC77D849* (*) (ReadOnlyDictionary_2_tC043257AB947D9A94D4AF6916DD67B7C30D3F734*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return (RuntimeObject*)L_0;
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
// Method Definition Index: 2384
// Method Definition Index: 2385
// Method Definition Index: 2386
// Method Definition Index: 2387
// Method Definition Index: 2388
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 ReadOnlyMemory_1_op_Implicit_mA6861A79CD44D21A65CCAF74685D980C61538C0C (ArraySegment_1_t3DC888623B720A071D69279F1FCB95A109195093 ___0_segment, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(ArraySegment_1_tBD802968EF59B432CE080ACA6DA2DBE15D3AE784_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(ArraySegment_1_tBD802968EF59B432CE080ACA6DA2DBE15D3AE784_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)),il2cpp_codegen_runtime_class_init_inline);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = ArraySegment_1_get_Array_m85F374406C1E34FDEFA7F160336A247891AF8105_inline((&___0_segment), NULL);
		int32_t L_1;
		L_1 = ArraySegment_1_get_Offset_m28FEFF65E8FA9A92DF84966071346BFD426CC3AA_inline((&___0_segment), NULL);
		int32_t L_2;
		L_2 = ArraySegment_1_get_Count_m7B026228B16D905890B805EA70E9114D1517B053_inline((&___0_segment), NULL);
		ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 L_3;
		memset((&L_3), 0, sizeof(L_3));
		ReadOnlyMemory_1__ctor_m3727B8B598D6E2BDC484D8B20FE81585C449AD30_inline((&L_3), L_0, L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 2389
// Method Definition Index: 2390
// Method Definition Index: 2391
// Method Definition Index: 2392
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlyMemory_1_ToString_m0C4DF727B39C613F84AC56D6FDAF7ACFF9E39720 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral958BF5561D89C9A90653416FCB65BBE72DADDE1E);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	//<source_info:<no-source>:1>
	String_t* V_0 = NULL;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		goto IL_0058;
	}

IL_0058:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		NullCheck(L_1);
		String_t* L_2;
		L_2 = VirtualFuncInvoker0< String_t* >::Invoke(8, L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4 = ((int32_t)(L_3&((int32_t)2147483647LL)));
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral958BF5561D89C9A90653416FCB65BBE72DADDE1E, L_2, L_5, NULL);
		return L_6;
	}
}
IL2CPP_EXTERN_C  String_t* ReadOnlyMemory_1_ToString_m0C4DF727B39C613F84AC56D6FDAF7ACFF9E39720_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399>(__this);
	String_t* _returnValue;
	_returnValue = ReadOnlyMemory_1_ToString_m0C4DF727B39C613F84AC56D6FDAF7ACFF9E39720(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 2393
// Method Definition Index: 2394
// Method Definition Index: 2395
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ReadOnlyMemory_1_get_Span_mA087C8160638E6581A03C1BDAF2803AC88834762 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0039;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_2;
		L_2 = VirtualFuncInvoker0< Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 >::Invoke(4, ((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		V_0 = L_2;
		int32_t L_3 = __this->____index;
		int32_t L_4 = __this->____length;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_5;
		L_5 = Span_1_Slice_m9D8BA8245B8DC9BFB4A4164759CBAAEAD1318CD6_inline((&V_0), ((int32_t)(L_3&((int32_t)2147483647LL))), L_4, NULL);
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_6;
		L_6 = Span_1_op_Implicit_mD249188242C0C9D3192A31E9F7FA74C683F05B84(L_5, NULL);
		return L_6;
	}

IL_0039:
	{
		goto IL_008e;
	}

IL_008e:
	{
		RuntimeObject* L_7 = __this->____object;
		if (!L_7)
		{
			goto IL_00b9;
		}
	}
	{
		RuntimeObject* L_8 = __this->____object;
		int32_t L_9 = __this->____index;
		int32_t L_10 = __this->____length;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_11;
		memset((&L_11), 0, sizeof(L_11));
		ReadOnlySpan_1__ctor_m7B5C2765879EA5E8D1617D834CC465A39540A913_inline((&L_11), ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_8, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16))), L_9, ((int32_t)(L_10&((int32_t)2147483647LL))), NULL);
		return L_11;
	}

IL_00b9:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D));
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_12 = V_2;
		return L_12;
	}
}
// Method Definition Index: 2396
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyMemory_1_CopyTo_m636823FFDFBA21CBEB9482D32A178A058377DE87 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036 ___0_destination, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_0;
		L_0 = ReadOnlyMemory_1_get_Span_mA087C8160638E6581A03C1BDAF2803AC88834762_inline(__this, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		V_0 = L_0;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_1;
		L_1 = Memory_1_get_Span_mA0CAB13956D6FA3BBF9F9176CB647933F88E034E_inline((&___0_destination), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 18));
		ReadOnlySpan_1_CopyTo_m8144AA3941DF7B7C2C665680221977E1D15D1462((&V_0), L_1, NULL);
		return;
	}
}
// Method Definition Index: 2397
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_TryCopyTo_mD51D216A5F8019EC81C7CC03ED53009674F773BA (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036 ___0_destination, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_0;
		L_0 = ReadOnlyMemory_1_get_Span_mA087C8160638E6581A03C1BDAF2803AC88834762_inline(__this, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		V_0 = L_0;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_1;
		L_1 = Memory_1_get_Span_mA0CAB13956D6FA3BBF9F9176CB647933F88E034E_inline((&___0_destination), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 18));
		bool L_2;
		L_2 = ReadOnlySpan_1_TryCopyTo_m2C902AB57D2363B06C42BDDE761F3E0DFD5541B3((&V_0), L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 2398
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD ReadOnlyMemory_1_Pin_mC8F72AD23857A4BBE24437D5CCA08032B33E6555 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	String_t* V_0 = NULL;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_2 = NULL;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC V_3;
	memset((&V_3), 0, sizeof(V_3));
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC V_4;
	memset((&V_4), 0, sizeof(V_4));
	MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD V_5;
	memset((&V_5), 0, sizeof(V_5));
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0026;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		int32_t L_2 = __this->____index;
		NullCheck(((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_3;
		L_3 = VirtualFuncInvoker1< MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD, int32_t >::Invoke(5, ((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))), ((int32_t)(L_2&((int32_t)2147483647LL))));
		return L_3;
	}

IL_0026:
	{
		goto IL_0076;
	}

IL_0076:
	{
		RuntimeObject* L_4 = __this->____object;
		V_2 = ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)IsInst((RuntimeObject*)L_4, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16)));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_2;
		if (!L_5)
		{
			goto IL_00dc;
		}
	}
	{
		int32_t L_6 = __this->____length;
		if ((((int32_t)L_6) >= ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_2;
		NullCheck((RuntimeArray*)L_7);
		uint8_t* L_8;
		L_8 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_7, NULL);
		void* L_9;
		L_9 = il2cpp_unsafe_as_pointer(L_8);
		int32_t L_10 = __this->____index;
		void* L_11;
		L_11 = il2cpp_unsafe_add<uint8_t,int32_t>(L_9, L_10, sizeof(uint8_t));
		il2cpp_codegen_initobj((&V_3), sizeof(GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC));
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_12 = V_3;
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_13;
		memset((&L_13), 0, sizeof(L_13));
		MemoryHandle__ctor_mBC4C2B7E7F10F5F93EFCF6A3A24D41CE79916C91((&L_13), L_11, L_12, (RuntimeObject*)NULL, NULL);
		return L_13;
	}

IL_00b4:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14 = V_2;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_15;
		L_15 = GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC((RuntimeObject*)L_14, 3, NULL);
		V_4 = L_15;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_16 = V_2;
		NullCheck((RuntimeArray*)L_16);
		uint8_t* L_17;
		L_17 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_16, NULL);
		void* L_18;
		L_18 = il2cpp_unsafe_as_pointer(L_17);
		int32_t L_19 = __this->____index;
		void* L_20;
		L_20 = il2cpp_unsafe_add<uint8_t,int32_t>(L_18, L_19, sizeof(uint8_t));
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_21 = V_4;
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_22;
		memset((&L_22), 0, sizeof(L_22));
		MemoryHandle__ctor_mBC4C2B7E7F10F5F93EFCF6A3A24D41CE79916C91((&L_22), L_20, L_21, (RuntimeObject*)NULL, NULL);
		return L_22;
	}

IL_00dc:
	{
		il2cpp_codegen_initobj((&V_5), sizeof(MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD));
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_23 = V_5;
		return L_23;
	}
}
// Method Definition Index: 2399
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ReadOnlyMemory_1_ToArray_mBFD6B4F56D00E1106EDA0EB98FD38D318B2A4522 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_0;
		L_0 = ReadOnlyMemory_1_get_Span_mA087C8160638E6581A03C1BDAF2803AC88834762_inline(__this, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		V_0 = L_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = ReadOnlySpan_1_ToArray_mF805FAE3816BCFA5C63592CA173237F9B1E4566E((&V_0), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 22));
		return L_1;
	}
}
// Method Definition Index: 2400
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_Equals_mD0C4947B91FD3864C476B6CA8BA929A6F5B01175 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeObject* L_0 = ___0_obj;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 23))))
		{
			goto IL_0017;
		}
	}
	{
		RuntimeObject* L_1 = ___0_obj;
		V_0 = ((*(ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 23))));
		ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 L_2 = V_0;
		bool L_3;
		L_3 = ReadOnlyMemory_1_Equals_mC3969DE0744A246E0576FEDE51191A0D3F5F69A9(__this, L_2, NULL);
		return L_3;
	}

IL_0017:
	{
		RuntimeObject* L_4 = ___0_obj;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_4, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 25))))
		{
			goto IL_0033;
		}
	}
	{
		RuntimeObject* L_5 = ___0_obj;
		V_1 = ((*(Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036*)UnBox(L_5, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 25))));
		Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036 L_6 = V_1;
		ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 L_7;
		L_7 = Memory_1_op_Implicit_m7B80A71310A3EA9F99CB1774CAFED254811599CD(L_6, NULL);
		bool L_8;
		L_8 = ReadOnlyMemory_1_Equals_mC3969DE0744A246E0576FEDE51191A0D3F5F69A9(__this, L_7, NULL);
		return L_8;
	}

IL_0033:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C  bool ReadOnlyMemory_1_Equals_mD0C4947B91FD3864C476B6CA8BA929A6F5B01175_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399>(__this);
	bool _returnValue;
	_returnValue = ReadOnlyMemory_1_Equals_mD0C4947B91FD3864C476B6CA8BA929A6F5B01175(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// Method Definition Index: 2401
// Method Definition Index: 2402
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_GetHashCode_mE47597BBDBFFBC9185DE65261A7388207854ADE6 (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->____object;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return 0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = VirtualFuncInvoker0< int32_t >::Invoke(2, L_1);
		int32_t* L_3 = (int32_t*)(&__this->____index);
		int32_t L_4;
		L_4 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_3, NULL);
		int32_t* L_5 = (int32_t*)(&__this->____length);
		int32_t L_6;
		L_6 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_5, NULL);
		int32_t L_7;
		L_7 = ReadOnlyMemory_1_CombineHashCodes_mC20EA69C2706DE824529A0506BD45837E26C6980(L_2, L_4, L_6, NULL);
		return L_7;
	}
}
IL2CPP_EXTERN_C  int32_t ReadOnlyMemory_1_GetHashCode_mE47597BBDBFFBC9185DE65261A7388207854ADE6_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399>(__this);
	int32_t _returnValue;
	_returnValue = ReadOnlyMemory_1_GetHashCode_mE47597BBDBFFBC9185DE65261A7388207854ADE6(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 2403
// Method Definition Index: 2404
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_CombineHashCodes_mC20EA69C2706DE824529A0506BD45837E26C6980 (int32_t ___0_h1, int32_t ___1_h2, int32_t ___2_h3, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_h1;
		int32_t L_1 = ___1_h2;
		int32_t L_2;
		L_2 = ReadOnlyMemory_1_CombineHashCodes_mAD75C6BDDB231C42D8A846F50E2B081E244108DA(L_0, L_1, NULL);
		int32_t L_3 = ___2_h3;
		int32_t L_4;
		L_4 = ReadOnlyMemory_1_CombineHashCodes_mAD75C6BDDB231C42D8A846F50E2B081E244108DA(L_2, L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 2405
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 2384
// Method Definition Index: 2385
// Method Definition Index: 2386
// Method Definition Index: 2387
// Method Definition Index: 2388
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 ReadOnlyMemory_1_op_Implicit_m1C97D3D48C4B5CAC4A710F701A9648C9D9E37242 (ArraySegment_1_t0E7B908700EEEA520D2B9E74D248D602CD1B32B3 ___0_segment, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(ArraySegment_1_tBD802968EF59B432CE080ACA6DA2DBE15D3AE784_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(ArraySegment_1_tBD802968EF59B432CE080ACA6DA2DBE15D3AE784_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)),il2cpp_codegen_runtime_class_init_inline);
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0;
		L_0 = ArraySegment_1_get_Array_mAB134498A82AD590967BDB7C71136238AA980AD8_inline((&___0_segment), NULL);
		int32_t L_1;
		L_1 = ArraySegment_1_get_Offset_m0C181BD19C4ED1F046320674D18CAEA6C3445EFB_inline((&___0_segment), NULL);
		int32_t L_2;
		L_2 = ArraySegment_1_get_Count_m41C56DC7483456EE6281ACF18BD801F6C23F16B8_inline((&___0_segment), NULL);
		ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 L_3;
		memset((&L_3), 0, sizeof(L_3));
		ReadOnlyMemory_1__ctor_m01C92ACEFF41B2945760FBBE73C5761736F117C8_inline((&L_3), L_0, L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 2389
// Method Definition Index: 2390
// Method Definition Index: 2391
// Method Definition Index: 2392
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ReadOnlyMemory_1_ToString_m4676D3AFBC120B54C2B53171F9C7DE3B4E753F68 (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	String_t* V_0 = NULL;
	ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
	}
	{
		RuntimeObject* L_0 = __this->____object;
		V_0 = ((String_t*)IsInstSealed((RuntimeObject*)L_0, String_t_il2cpp_TypeInfo_var));
		String_t* L_1 = V_0;
		if (L_1)
		{
			goto IL_003f;
		}
	}
	{
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_2;
		L_2 = ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA_inline(__this, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		V_1 = L_2;
		String_t* L_3;
		L_3 = ReadOnlySpan_1_ToString_mB13A913EF211B14B719EE62133C15C298642E34D((&V_1), NULL);
		return L_3;
	}

IL_003f:
	{
		String_t* L_4 = V_0;
		int32_t L_5 = __this->____index;
		int32_t L_6 = __this->____length;
		NullCheck(L_4);
		String_t* L_7;
		L_7 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_4, L_5, ((int32_t)(L_6&((int32_t)2147483647LL))), NULL);
		return L_7;
	}
}
IL2CPP_EXTERN_C  String_t* ReadOnlyMemory_1_ToString_m4676D3AFBC120B54C2B53171F9C7DE3B4E753F68_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6>(__this);
	String_t* _returnValue;
	_returnValue = ReadOnlyMemory_1_ToString_m4676D3AFBC120B54C2B53171F9C7DE3B4E753F68(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 2393
// Method Definition Index: 2394
// Method Definition Index: 2395
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0039;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_2;
		L_2 = VirtualFuncInvoker0< Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D >::Invoke(4, ((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		V_0 = L_2;
		int32_t L_3 = __this->____index;
		int32_t L_4 = __this->____length;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_5;
		L_5 = Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_inline((&V_0), ((int32_t)(L_3&((int32_t)2147483647LL))), L_4, NULL);
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_6;
		L_6 = Span_1_op_Implicit_m03D0CEDC1BC95844236105D1DE24A702B956BFE4(L_5, NULL);
		return L_6;
	}

IL_0039:
	{
	}
	{
		RuntimeObject* L_7 = __this->____object;
		V_1 = ((String_t*)IsInstSealed((RuntimeObject*)L_7, String_t_il2cpp_TypeInfo_var));
		String_t* L_8 = V_1;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		String_t* L_9 = V_1;
		NullCheck(L_9);
		Il2CppChar* L_10;
		L_10 = String_GetRawStringData_m87BC50B7B314C055E27A28032D1003D42FDE411D(L_9, NULL);
		Il2CppChar* L_11;
		L_11 = il2cpp_unsafe_as_ref<Il2CppChar>(L_10);
		String_t* L_12 = V_1;
		NullCheck(L_12);
		int32_t L_13;
		L_13 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_12, NULL);
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_14;
		memset((&L_14), 0, sizeof(L_14));
		ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_inline((&L_14), L_11, L_13, NULL);
		V_2 = L_14;
		int32_t L_15 = __this->____index;
		int32_t L_16 = __this->____length;
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_17;
		L_17 = ReadOnlySpan_1_Slice_mDEEA4C304B13C8F7A63BC3D60B62FF17BBEE282B_inline((&V_2), L_15, L_16, NULL);
		return L_17;
	}

IL_008e:
	{
		RuntimeObject* L_18 = __this->____object;
		if (!L_18)
		{
			goto IL_00b9;
		}
	}
	{
		RuntimeObject* L_19 = __this->____object;
		int32_t L_20 = __this->____index;
		int32_t L_21 = __this->____length;
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_22;
		memset((&L_22), 0, sizeof(L_22));
		ReadOnlySpan_1__ctor_mDADE08E6B4594775C6675B389078E5FE98C745D5_inline((&L_22), ((CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)Castclass((RuntimeObject*)L_19, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16))), L_20, ((int32_t)(L_21&((int32_t)2147483647LL))), NULL);
		return L_22;
	}

IL_00b9:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1));
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_23 = V_2;
		return L_23;
	}
}
// Method Definition Index: 2396
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyMemory_1_CopyTo_mB8AA6E1E2B9B22B148F4C0DEE1D1126650167332 (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E ___0_destination, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_0;
		L_0 = ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA_inline(__this, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		V_0 = L_0;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_1;
		L_1 = Memory_1_get_Span_m926BDF0BE2BAC67BB057415AE70537AFCB4FE3B8_inline((&___0_destination), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 18));
		ReadOnlySpan_1_CopyTo_m42F1668DECE40277D97A37705EA6BE27CF7D5030((&V_0), L_1, NULL);
		return;
	}
}
// Method Definition Index: 2397
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_TryCopyTo_m9A4FBBC05DC6579655DE294DAC5C3048A47CA956 (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E ___0_destination, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_0;
		L_0 = ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA_inline(__this, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		V_0 = L_0;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_1;
		L_1 = Memory_1_get_Span_m926BDF0BE2BAC67BB057415AE70537AFCB4FE3B8_inline((&___0_destination), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 18));
		bool L_2;
		L_2 = ReadOnlySpan_1_TryCopyTo_m22E885FE905F1306DDE8000F155109F7F4987666((&V_0), L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 2398
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD ReadOnlyMemory_1_Pin_m178F67C6161C21637F205EEA39170CBD43DFD8BA (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	String_t* V_0 = NULL;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC V_1;
	memset((&V_1), 0, sizeof(V_1));
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* V_2 = NULL;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC V_3;
	memset((&V_3), 0, sizeof(V_3));
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC V_4;
	memset((&V_4), 0, sizeof(V_4));
	MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD V_5;
	memset((&V_5), 0, sizeof(V_5));
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0026;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		int32_t L_2 = __this->____index;
		NullCheck(((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_3;
		L_3 = VirtualFuncInvoker1< MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD, int32_t >::Invoke(5, ((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))), ((int32_t)(L_2&((int32_t)2147483647LL))));
		return L_3;
	}

IL_0026:
	{
	}
	{
		RuntimeObject* L_4 = __this->____object;
		V_0 = ((String_t*)IsInstSealed((RuntimeObject*)L_4, String_t_il2cpp_TypeInfo_var));
		String_t* L_5 = V_0;
		if (!L_5)
		{
			goto IL_0076;
		}
	}
	{
		String_t* L_6 = V_0;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_7;
		L_7 = GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC(L_6, 3, NULL);
		V_1 = L_7;
		String_t* L_8 = V_0;
		NullCheck(L_8);
		Il2CppChar* L_9;
		L_9 = String_GetRawStringData_m87BC50B7B314C055E27A28032D1003D42FDE411D(L_8, NULL);
		void* L_10;
		L_10 = il2cpp_unsafe_as_pointer(L_9);
		int32_t L_11 = __this->____index;
		void* L_12;
		L_12 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_10, L_11, sizeof(Il2CppChar));
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_13 = V_1;
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_14;
		memset((&L_14), 0, sizeof(L_14));
		MemoryHandle__ctor_mBC4C2B7E7F10F5F93EFCF6A3A24D41CE79916C91((&L_14), L_12, L_13, (RuntimeObject*)NULL, NULL);
		return L_14;
	}

IL_0076:
	{
		RuntimeObject* L_15 = __this->____object;
		V_2 = ((CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)IsInst((RuntimeObject*)L_15, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16)));
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_16 = V_2;
		if (!L_16)
		{
			goto IL_00dc;
		}
	}
	{
		int32_t L_17 = __this->____length;
		if ((((int32_t)L_17) >= ((int32_t)0)))
		{
			goto IL_00b4;
		}
	}
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_18 = V_2;
		NullCheck((RuntimeArray*)L_18);
		uint8_t* L_19;
		L_19 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_18, NULL);
		void* L_20;
		L_20 = il2cpp_unsafe_as_pointer(L_19);
		int32_t L_21 = __this->____index;
		void* L_22;
		L_22 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_20, L_21, sizeof(Il2CppChar));
		il2cpp_codegen_initobj((&V_3), sizeof(GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC));
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_23 = V_3;
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_24;
		memset((&L_24), 0, sizeof(L_24));
		MemoryHandle__ctor_mBC4C2B7E7F10F5F93EFCF6A3A24D41CE79916C91((&L_24), L_22, L_23, (RuntimeObject*)NULL, NULL);
		return L_24;
	}

IL_00b4:
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_25 = V_2;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_26;
		L_26 = GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC((RuntimeObject*)L_25, 3, NULL);
		V_4 = L_26;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_27 = V_2;
		NullCheck((RuntimeArray*)L_27);
		uint8_t* L_28;
		L_28 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_27, NULL);
		void* L_29;
		L_29 = il2cpp_unsafe_as_pointer(L_28);
		int32_t L_30 = __this->____index;
		void* L_31;
		L_31 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_29, L_30, sizeof(Il2CppChar));
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_32 = V_4;
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_33;
		memset((&L_33), 0, sizeof(L_33));
		MemoryHandle__ctor_mBC4C2B7E7F10F5F93EFCF6A3A24D41CE79916C91((&L_33), L_31, L_32, (RuntimeObject*)NULL, NULL);
		return L_33;
	}

IL_00dc:
	{
		il2cpp_codegen_initobj((&V_5), sizeof(MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD));
		MemoryHandle_t505785861D4FF84F850A3FF775BE6AE1833D2AFD L_34 = V_5;
		return L_34;
	}
}
// Method Definition Index: 2399
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ReadOnlyMemory_1_ToArray_m301AA507E5C985A67593C03AD34B66930FF3C9C7 (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_0;
		L_0 = ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA_inline(__this, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		V_0 = L_0;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_1;
		L_1 = ReadOnlySpan_1_ToArray_m3CC38C41E9FB235D0C9D24033DE4D561B1017488((&V_0), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 22));
		return L_1;
	}
}
// Method Definition Index: 2400
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnlyMemory_1_Equals_mE4EA5DC4ACF51E07F85C4A55A3281E580903506F (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeObject* L_0 = ___0_obj;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 23))))
		{
			goto IL_0017;
		}
	}
	{
		RuntimeObject* L_1 = ___0_obj;
		V_0 = ((*(ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 23))));
		ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 L_2 = V_0;
		bool L_3;
		L_3 = ReadOnlyMemory_1_Equals_mC4A7615E6A8C3467783EB6D9FBDA06A1B9745117(__this, L_2, NULL);
		return L_3;
	}

IL_0017:
	{
		RuntimeObject* L_4 = ___0_obj;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_4, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 25))))
		{
			goto IL_0033;
		}
	}
	{
		RuntimeObject* L_5 = ___0_obj;
		V_1 = ((*(Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E*)UnBox(L_5, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 25))));
		Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E L_6 = V_1;
		ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6 L_7;
		L_7 = Memory_1_op_Implicit_m2A354E866CDB4F77671ADADD234CFF9A31DAB8FB(L_6, NULL);
		bool L_8;
		L_8 = ReadOnlyMemory_1_Equals_mC4A7615E6A8C3467783EB6D9FBDA06A1B9745117(__this, L_7, NULL);
		return L_8;
	}

IL_0033:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C  bool ReadOnlyMemory_1_Equals_mE4EA5DC4ACF51E07F85C4A55A3281E580903506F_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6>(__this);
	bool _returnValue;
	_returnValue = ReadOnlyMemory_1_Equals_mE4EA5DC4ACF51E07F85C4A55A3281E580903506F(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// Method Definition Index: 2401
// Method Definition Index: 2402
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_GetHashCode_m7D885665B2C6E9B5B157129A6CCAFC4938400D0D (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = __this->____object;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return 0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = VirtualFuncInvoker0< int32_t >::Invoke(2, L_1);
		int32_t* L_3 = (int32_t*)(&__this->____index);
		int32_t L_4;
		L_4 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_3, NULL);
		int32_t* L_5 = (int32_t*)(&__this->____length);
		int32_t L_6;
		L_6 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_5, NULL);
		int32_t L_7;
		L_7 = ReadOnlyMemory_1_CombineHashCodes_m90089D22A29124B5DFB7253B5795FBBBA2E17BC1(L_2, L_4, L_6, NULL);
		return L_7;
	}
}
IL2CPP_EXTERN_C  int32_t ReadOnlyMemory_1_GetHashCode_m7D885665B2C6E9B5B157129A6CCAFC4938400D0D_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6>(__this);
	int32_t _returnValue;
	_returnValue = ReadOnlyMemory_1_GetHashCode_m7D885665B2C6E9B5B157129A6CCAFC4938400D0D(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 2403
// Method Definition Index: 2404
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ReadOnlyMemory_1_CombineHashCodes_m90089D22A29124B5DFB7253B5795FBBBA2E17BC1 (int32_t ___0_h1, int32_t ___1_h2, int32_t ___2_h3, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_h1;
		int32_t L_1 = ___1_h2;
		int32_t L_2;
		L_2 = ReadOnlyMemory_1_CombineHashCodes_mE36B3B07DCBC22779CDDB94D35E0D00AD8568028(L_0, L_1, NULL);
		int32_t L_3 = ___2_h3;
		int32_t L_4;
		L_4 = ReadOnlyMemory_1_CombineHashCodes_mE36B3B07DCBC22779CDDB94D35E0D00AD8568028(L_2, L_3, NULL);
		return L_4;
	}
}
// Method Definition Index: 2405
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 3278
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t* Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline (RuntimeArray* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0* L_0;
		L_0 = il2cpp_unsafe_as<RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0*>(__this);
		NullCheck(L_0);
		uint8_t* L_1 = (uint8_t*)(&L_0->___Data);
		return L_1;
	}
}
// Method Definition Index: 707
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____stringLength;
		return L_0;
	}
}
// Method Definition Index: 970
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ArraySegment_1_get_Array_mE4A35DFD81ABF447350B9A05C0F4BF0248A3CFF2_fshared_inline (ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____array;
		return L_0;
	}
}
// Method Definition Index: 971
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ArraySegment_1_get_Offset_m4FAFF061AB36BF278BA8DC37B6D13718A06301E6_fshared_inline (ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____offset;
		return L_0;
	}
}
// Method Definition Index: 972
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ArraySegment_1_get_Count_mEF96248898C14F3687A5C72B920F841701E4E13C_fshared_inline (ArraySegment_1_t00CCB00D2C671984CD055C219135EB0500C79178* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____count;
		return L_0;
	}
}
// Method Definition Index: 2385
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlyMemory_1__ctor_m1FD19CA8A2CB8A92DC095EE34D414ADE2FD39A12_fshared_inline (ReadOnlyMemory_1_t192441E248CAB66088AAEDBD64DFEE110ADBEED4* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(ReadOnlyMemory_1_t192441E248CAB66088AAEDBD64DFEE110ADBEED4));
		return;
	}

IL_0016:
	{
		int32_t L_3 = ___1_start;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = ___0_array;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) <= ((uint32_t)L_5))))
		{
			goto IL_0024;
		}
	}
	{
		int32_t L_6 = ___2_length;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		int32_t L_9 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_8, L_9))))))
		{
			goto IL_0029;
		}
	}

IL_0024:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0029:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = ___0_array;
		__this->____object = (RuntimeObject*)L_10;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____object), (void*)(RuntimeObject*)L_10);
		int32_t L_11 = ___1_start;
		__this->____index = L_11;
		int32_t L_12 = ___2_length;
		__this->____length = L_12;
		return;
	}
}
// Method Definition Index: 2516
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m9D8BA8245B8DC9BFB4A4164759CBAAEAD1318CD6_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_5 = __this->____pointer;
		V_0 = L_5;
		uint8_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		uint8_t* L_8;
		L_8 = il2cpp_unsafe_add<uint8_t,int32_t>(L_6, L_7, sizeof(uint8_t));
		int32_t L_9 = ___1_length;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_inline((&L_10), L_8, L_9, NULL);
		return L_10;
	}
}
// Method Definition Index: 2407
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m7B5C2765879EA5E8D1617D834CC465A39540A913_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D));
		return;
	}

IL_0016:
	{
		int32_t L_3 = ___1_start;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = ___0_array;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) <= ((uint32_t)L_5))))
		{
			goto IL_0024;
		}
	}
	{
		int32_t L_6 = ___2_length;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		int32_t L_9 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_8, L_9))))))
		{
			goto IL_0029;
		}
	}

IL_0024:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0029:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10 = ___0_array;
		NullCheck((RuntimeArray*)L_10);
		uint8_t* L_11;
		L_11 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_10, NULL);
		uint8_t* L_12;
		L_12 = il2cpp_unsafe_as_ref<uint8_t>(L_11);
		int32_t L_13 = ___1_start;
		uint8_t* L_14;
		L_14 = il2cpp_unsafe_add<uint8_t,int32_t>(L_12, L_13, sizeof(uint8_t));
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_15;
		memset((&L_15), 0, sizeof(L_15));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_15), L_14);
		__this->____pointer = L_15;
		int32_t L_16 = ___2_length;
		__this->____length = L_16;
		return;
	}
}
// Method Definition Index: 2395
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ReadOnlyMemory_1_get_Span_mA087C8160638E6581A03C1BDAF2803AC88834762_inline (ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0039;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_2;
		L_2 = VirtualFuncInvoker0< Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 >::Invoke(4, ((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		V_0 = L_2;
		int32_t L_3 = __this->____index;
		int32_t L_4 = __this->____length;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_5;
		L_5 = Span_1_Slice_m9D8BA8245B8DC9BFB4A4164759CBAAEAD1318CD6_inline((&V_0), ((int32_t)(L_3&((int32_t)2147483647LL))), L_4, NULL);
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_6;
		L_6 = Span_1_op_Implicit_mD249188242C0C9D3192A31E9F7FA74C683F05B84(L_5, NULL);
		return L_6;
	}

IL_0039:
	{
		goto IL_008e;
	}

IL_008e:
	{
		RuntimeObject* L_7 = __this->____object;
		if (!L_7)
		{
			goto IL_00b9;
		}
	}
	{
		RuntimeObject* L_8 = __this->____object;
		int32_t L_9 = __this->____index;
		int32_t L_10 = __this->____length;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_11;
		memset((&L_11), 0, sizeof(L_11));
		ReadOnlySpan_1__ctor_m7B5C2765879EA5E8D1617D834CC465A39540A913_inline((&L_11), ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_8, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16))), L_9, ((int32_t)(L_10&((int32_t)2147483647LL))), NULL);
		return L_11;
	}

IL_00b9:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D));
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_12 = V_2;
		return L_12;
	}
}
// Method Definition Index: 2159
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Memory_1_get_Span_mA0CAB13956D6FA3BBF9F9176CB647933F88E034E_inline (Memory_1_tB7CEF4416F5014E364267478CEF016A4AC5C0036* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0034;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13))));
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_2;
		L_2 = VirtualFuncInvoker0< Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 >::Invoke(4, ((MemoryManager_1_tB90442C8E0A1B9C0F8A3B603FD50501A1BADAC6E*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13))));
		V_0 = L_2;
		int32_t L_3 = __this->____index;
		int32_t L_4 = __this->____length;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_5;
		L_5 = Span_1_Slice_m9D8BA8245B8DC9BFB4A4164759CBAAEAD1318CD6_inline((&V_0), ((int32_t)(L_3&((int32_t)2147483647LL))), L_4, NULL);
		return L_5;
	}

IL_0034:
	{
		goto IL_0089;
	}

IL_0089:
	{
		RuntimeObject* L_6 = __this->____object;
		if (!L_6)
		{
			goto IL_00b4;
		}
	}
	{
		RuntimeObject* L_7 = __this->____object;
		int32_t L_8 = __this->____index;
		int32_t L_9 = __this->____length;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m698EC79E2E44AFF16BA096D0861CFB129FBF8218_inline((&L_10), ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_7, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2))), L_8, ((int32_t)(L_9&((int32_t)2147483647LL))), NULL);
		return L_10;
	}

IL_00b4:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305));
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_11 = V_0;
		return L_11;
	}
}
// Method Definition Index: 2395
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 ReadOnlyMemory_1_get_Span_m21E4F67DBB43CC122008ADE132AB9213723588EA_inline (ReadOnlyMemory_1_t9495785584BC99CFCF956B34621F038E83C257D6* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0039;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_2;
		L_2 = VirtualFuncInvoker0< Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D >::Invoke(4, ((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 11))));
		V_0 = L_2;
		int32_t L_3 = __this->____index;
		int32_t L_4 = __this->____length;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_5;
		L_5 = Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_inline((&V_0), ((int32_t)(L_3&((int32_t)2147483647LL))), L_4, NULL);
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_6;
		L_6 = Span_1_op_Implicit_m03D0CEDC1BC95844236105D1DE24A702B956BFE4(L_5, NULL);
		return L_6;
	}

IL_0039:
	{
	}
	{
		RuntimeObject* L_7 = __this->____object;
		V_1 = ((String_t*)IsInstSealed((RuntimeObject*)L_7, String_t_il2cpp_TypeInfo_var));
		String_t* L_8 = V_1;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		String_t* L_9 = V_1;
		NullCheck(L_9);
		Il2CppChar* L_10;
		L_10 = String_GetRawStringData_m87BC50B7B314C055E27A28032D1003D42FDE411D(L_9, NULL);
		Il2CppChar* L_11;
		L_11 = il2cpp_unsafe_as_ref<Il2CppChar>(L_10);
		String_t* L_12 = V_1;
		NullCheck(L_12);
		int32_t L_13;
		L_13 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_12, NULL);
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_14;
		memset((&L_14), 0, sizeof(L_14));
		ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_inline((&L_14), L_11, L_13, NULL);
		V_2 = L_14;
		int32_t L_15 = __this->____index;
		int32_t L_16 = __this->____length;
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_17;
		L_17 = ReadOnlySpan_1_Slice_mDEEA4C304B13C8F7A63BC3D60B62FF17BBEE282B_inline((&V_2), L_15, L_16, NULL);
		return L_17;
	}

IL_008e:
	{
		RuntimeObject* L_18 = __this->____object;
		if (!L_18)
		{
			goto IL_00b9;
		}
	}
	{
		RuntimeObject* L_19 = __this->____object;
		int32_t L_20 = __this->____index;
		int32_t L_21 = __this->____length;
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_22;
		memset((&L_22), 0, sizeof(L_22));
		ReadOnlySpan_1__ctor_mDADE08E6B4594775C6675B389078E5FE98C745D5_inline((&L_22), ((CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)Castclass((RuntimeObject*)L_19, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 16))), L_20, ((int32_t)(L_21&((int32_t)2147483647LL))), NULL);
		return L_22;
	}

IL_00b9:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1));
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_23 = V_2;
		return L_23;
	}
}
// Method Definition Index: 2516
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5 = __this->____pointer;
		V_0 = L_5;
		Il2CppChar* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		Il2CppChar* L_8;
		L_8 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_6, L_7, sizeof(Il2CppChar));
		int32_t L_9 = ___1_length;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_inline((&L_10), L_8, L_9, NULL);
		return L_10;
	}
}
// Method Definition Index: 2409
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mFA6EE52BCF39100AE30C79E73F0F972182D0CA2A_fshared_inline (ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC* __this, Il2CppFullySharedGenericAny* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_ptr;
		ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
// Method Definition Index: 2417
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 ReadOnlySpan_1_Slice_mDEEA4C304B13C8F7A63BC3D60B62FF17BBEE282B_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5 = __this->____pointer;
		V_0 = L_5;
		Il2CppChar* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		Il2CppChar* L_8;
		L_8 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_6, L_7, sizeof(Il2CppChar));
		int32_t L_9 = ___1_length;
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_10;
		memset((&L_10), 0, sizeof(L_10));
		ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_inline((&L_10), L_8, L_9, NULL);
		return L_10;
	}
}
// Method Definition Index: 2407
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mDADE08E6B4594775C6675B389078E5FE98C745D5_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1));
		return;
	}

IL_0016:
	{
		int32_t L_3 = ___1_start;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_4 = ___0_array;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) <= ((uint32_t)L_5))))
		{
			goto IL_0024;
		}
	}
	{
		int32_t L_6 = ___2_length;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		int32_t L_9 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_8, L_9))))))
		{
			goto IL_0029;
		}
	}

IL_0024:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0029:
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_10 = ___0_array;
		NullCheck((RuntimeArray*)L_10);
		uint8_t* L_11;
		L_11 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_10, NULL);
		Il2CppChar* L_12;
		L_12 = il2cpp_unsafe_as_ref<Il2CppChar>(L_11);
		int32_t L_13 = ___1_start;
		Il2CppChar* L_14;
		L_14 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_12, L_13, sizeof(Il2CppChar));
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_15;
		memset((&L_15), 0, sizeof(L_15));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_15), L_14);
		__this->____pointer = L_15;
		int32_t L_16 = ___2_length;
		__this->____length = L_16;
		return;
	}
}
// Method Definition Index: 2159
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Memory_1_get_Span_m926BDF0BE2BAC67BB057415AE70537AFCB4FE3B8_inline (Memory_1_t48D1B1093D181D6F37155EB644659FD7D1DF616E* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	{
		int32_t L_0 = __this->____index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0034;
		}
	}
	{
		RuntimeObject* L_1 = __this->____object;
		NullCheck(((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13))));
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_2;
		L_2 = VirtualFuncInvoker0< Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D >::Invoke(4, ((MemoryManager_1_t9E713A8E4F8473E685FE4A73C98D29C9DB1EE583*)CastclassClass((RuntimeObject*)L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13))));
		V_0 = L_2;
		int32_t L_3 = __this->____index;
		int32_t L_4 = __this->____length;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_5;
		L_5 = Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_inline((&V_0), ((int32_t)(L_3&((int32_t)2147483647LL))), L_4, NULL);
		return L_5;
	}

IL_0034:
	{
	}
	{
		RuntimeObject* L_6 = __this->____object;
		V_1 = ((String_t*)IsInstSealed((RuntimeObject*)L_6, String_t_il2cpp_TypeInfo_var));
		String_t* L_7 = V_1;
		if (!L_7)
		{
			goto IL_0089;
		}
	}
	{
		String_t* L_8 = V_1;
		NullCheck(L_8);
		Il2CppChar* L_9;
		L_9 = String_GetRawStringData_m87BC50B7B314C055E27A28032D1003D42FDE411D(L_8, NULL);
		Il2CppChar* L_10;
		L_10 = il2cpp_unsafe_as_ref<Il2CppChar>(L_9);
		String_t* L_11 = V_1;
		NullCheck(L_11);
		int32_t L_12;
		L_12 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_11, NULL);
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_13;
		memset((&L_13), 0, sizeof(L_13));
		Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_inline((&L_13), L_10, L_12, NULL);
		V_0 = L_13;
		int32_t L_14 = __this->____index;
		int32_t L_15 = __this->____length;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_16;
		L_16 = Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_inline((&V_0), L_14, L_15, NULL);
		return L_16;
	}

IL_0089:
	{
		RuntimeObject* L_17 = __this->____object;
		if (!L_17)
		{
			goto IL_00b4;
		}
	}
	{
		RuntimeObject* L_18 = __this->____object;
		int32_t L_19 = __this->____index;
		int32_t L_20 = __this->____length;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_21;
		memset((&L_21), 0, sizeof(L_21));
		Span_1__ctor_m5BFF79141064122141ED34283347A634B9DF577D_inline((&L_21), ((CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)Castclass((RuntimeObject*)L_18, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2))), L_19, ((int32_t)(L_20&((int32_t)2147483647LL))), NULL);
		return L_21;
	}

IL_00b4:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D));
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 2505
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mBA868F06359701D9950DEB1B10F52F848E9FF6DA_fshared_inline (Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54* __this, Il2CppFullySharedGenericAny* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_ptr;
		ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
// Method Definition Index: 2503
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m698EC79E2E44AFF16BA096D0861CFB129FBF8218_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint8_t V_0 = 0x0;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(uint8_t));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		if ((!(((uint32_t)L_4) <= ((uint32_t)L_6))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_7 = ___2_length;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		int32_t L_10 = ___1_start;
		if ((!(((uint32_t)L_7) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = ___0_array;
		NullCheck((RuntimeArray*)L_11);
		uint8_t* L_12;
		L_12 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_11, NULL);
		uint8_t* L_13;
		L_13 = il2cpp_unsafe_as_ref<uint8_t>(L_12);
		int32_t L_14 = ___1_start;
		uint8_t* L_15;
		L_15 = il2cpp_unsafe_add<uint8_t,int32_t>(L_13, L_14, sizeof(uint8_t));
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_16;
		memset((&L_16), 0, sizeof(L_16));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_16), L_15);
		__this->____pointer = L_16;
		int32_t L_17 = ___2_length;
		__this->____length = L_17;
		return;
	}
}
// Method Definition Index: 2503
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m5BFF79141064122141ED34283347A634B9DF577D_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Il2CppChar V_0 = 0x0;
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppChar));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		if ((!(((uint32_t)L_4) <= ((uint32_t)L_6))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_7 = ___2_length;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		int32_t L_10 = ___1_start;
		if ((!(((uint32_t)L_7) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_11 = ___0_array;
		NullCheck((RuntimeArray*)L_11);
		uint8_t* L_12;
		L_12 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_11, NULL);
		Il2CppChar* L_13;
		L_13 = il2cpp_unsafe_as_ref<Il2CppChar>(L_12);
		int32_t L_14 = ___1_start;
		Il2CppChar* L_15;
		L_15 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_13, L_14, sizeof(Il2CppChar));
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_16;
		memset((&L_16), 0, sizeof(L_16));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_16), L_15);
		__this->____pointer = L_16;
		int32_t L_17 = ___2_length;
		__this->____length = L_17;
		return;
	}
}
