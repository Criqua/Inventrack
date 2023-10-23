#pragma once
#include <string>

namespace conversion{

	inline std::string to_stdstring(System::String^ str) {
		using System::Runtime::InteropServices::Marshal;
		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(str);
		char* charptr = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charptr, str->Length);
		Marshal::FreeHGlobal(pointer);

		return returnString;
	}

	/*string to_sysString(string str) {
		return gcnew String(str.c_str());
	}*/
}