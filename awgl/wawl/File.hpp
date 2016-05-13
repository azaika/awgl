﻿#pragma once
#define ENABLE_WAWL_FILE

#include "WawlBase.hpp"
#include "FileBaseType.hpp"
#include "SecurityObjects.hpp"

namespace wawl {
	namespace fs {

		// init file handle
		inline FileHandle createFile(
			const Tstring fileName,
			FileCreateProv* createProv,
			AccessDesc* accessDesc,
			FileSharePermit* shareMode,
			SecurityAttr* secAttr,
			FileAttr* fileAttr,
			FileHandle baseFile
			) {
			SecurityAttr sa = (secAttr ? *secAttr : SecurityAttr());

			return ::CreateFile(
				fileName.c_str(),
				(accessDesc ? unpackEnum(*accessDesc) : GENERIC_ALL),
				(shareMode ? unpackEnum(*shareMode) : 0),
				&sa,
				(createProv ? unpackEnum(*createProv) : CREATE_ALWAYS),
				(fileAttr ? unpackEnum(*fileAttr) : FILE_ATTRIBUTE_NORMAL),
				baseFile
				);
		}
		inline FileHandle createFile(
			const Tstring fileName
			) {
			return createFile(
				fileName,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				nullptr
				);
		}
		inline FileHandle createFile(
			const Tstring fileName,
			FileCreateProv createProv
			) {
			return createFile(
				fileName,
				&createProv,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				nullptr
				);
		}
		inline FileHandle createFile(
			const Tstring fileName,
			FileCreateProv createProv,
			FileHandle baseFile
			) {
			return createFile(
				fileName,
				&createProv,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				baseFile
				);
		}
		inline FileHandle createFile(
			const Tstring fileName,
			FileCreateProv createProv,
			AccessDesc accessDesc,
			FileSharePermit shareMode
			) {
			return createFile(
				fileName,
				&createProv,
				&accessDesc,
				&shareMode,
				nullptr,
				nullptr,
				nullptr
				);
		}
		inline FileHandle createFile(
			const Tstring fileName,
			FileCreateProv createProv,
			AccessDesc accessDesc,
			FileSharePermit shareMode,
			SecurityAttr secAttr,
			FileAttr fileAttr
			) {
			return createFile(
				fileName,
				&createProv,
				&accessDesc,
				&shareMode,
				&secAttr,
				&fileAttr,
				nullptr
				);
		}
		inline FileHandle createFile(
			const Tstring fileName,
			FileCreateProv createProv,
			AccessDesc accessDesc,
			FileSharePermit shareMode,
			SecurityAttr secAttr,
			FileAttr fileAttr,
			FileHandle baseFile
			) {
			return createFile(
				fileName,
				&createProv,
				&accessDesc,
				&shareMode,
				&secAttr,
				&fileAttr,
				baseFile
				);
		}


		// get file size in byte 
		inline Int64 getFileSize(FileHandle file) {
			::LARGE_INTEGER li;

			if (::GetFileSizeEx(file, &li))
				throw static_cast<Error>(::GetLastError());

			return static_cast<Int64>(li.QuadPart);
		}

		// read text from file and write it buffer
		inline bool readFile(
			FileHandle file,
			Tstring& buf,
			Uint32 n
			) {
			Uint32 readSize;

			buf.resize(n + 1);

			bool isSuccess =
				::ReadFile(
					file,
					&buf[0],
					n,
					&readSize,
					nullptr
					) != 0;

			buf.resize(readSize);

			return isSuccess;
		}

		// write text to file
		inline bool writeFile(FileHandle file, const Tstring& str) {
			Uint32 writtenSize;

			return
				::WriteFile(
					file,
					str.c_str(),
					static_cast<Uint32>(str.size() + 1),
					&writtenSize,
					nullptr
					) != 0;
		}

		// copy a file (not an async function)
		inline bool copyFile(
			const Tstring& baseFileName,
			const Tstring& newFileName,
			bool isOverwrite = true
			) {
			return ::CopyFile(
				baseFileName.c_str(),
				newFileName.c_str(),
				isOverwrite
				) != 0;
		}

		inline bool deleteFile(const Tstring& fileName) {
			return ::DeleteFile(fileName.c_str()) != 0;
		}

		inline FileType getFileType(FileHandle file) {
			return static_cast<FileType>(::GetFileType(file));
		}

		inline FileAttr getFileAttr(const Tstring& fileName) {
			return static_cast<FileAttr>(
				::GetFileAttributes(fileName.c_str())
				);
		}

		// get full filepath of specified filepath
		inline Tstring getFileFullPath(const Tstring& fileName) {
			Uint32 needSize =
				::GetFullPathName(
					fileName.c_str(), 0, nullptr, nullptr
					);

			Tstring ret;
			ret.resize(needSize);

			::GetFullPathName(
				fileName.c_str(),
				needSize + 1,
				&ret[0],
				nullptr
				);

			return ret;
		}

	} // ::wawl::fs
} // ::wawl