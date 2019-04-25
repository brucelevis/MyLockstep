#include "be_file_manager.h"
#include "be_file.h"
#include "world.h"
using namespace lockstep;

BeFileManager::BeFileManager()
{

}

BeFileManager::~BeFileManager()
{
}

behaviac::IFile* BeFileManager::FileOpen(const char* fileName, behaviac::CFileSystem::EOpenMode iOpenAccess)
{
	// ��Ҫʵ���Լ��Ĵ��룬����ֱ�ӵ��û���ķ���������ʾ
	return BEHAVIAC_NEW BeFile(fileName);
}

void BeFileManager::FileClose(behaviac::IFile* file)
{
	BEHAVIAC_DELETE file;
}

bool BeFileManager::FileExists(const behaviac::string& filePath, const behaviac::string& ext)
{
	return false;
}

bool BeFileManager::FileExists(const char* fileName)
{
	return false;
}

uint64_t BeFileManager::FileGetSize(const char* fileName)
{

	return 0;
}

behaviac::wstring BeFileManager::GetCurrentWorkingDirectory()
{
	return CFileManager::GetCurrentWorkingDirectory();
}