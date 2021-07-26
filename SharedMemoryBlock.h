#pragma once

#include <Windows.h>

template < class T > class SharedMemoryBlock
{
public:
   SharedMemoryBlock() : mMapView( NULL ), mMemHandle( NULL ) {}
   SharedMemoryBlock( const std::string &blockName )
   {
      Open( blockName );
   }

   ~SharedMemoryBlock()
   {
      Close();
   }

   void Close( void )
   {
      if ( mMapView )
      {
         UnmapViewOfFile( mMapView );
         mMapView = NULL;
      }
      if ( mMemHandle )
      {
         CloseHandle( mMemHandle );
         mMemHandle = NULL;
      }
   }

   T* Open( const std::string &blockName )
   {
      if ( blockName.empty() )
         return NULL;

      if ( mMapView )
         Close();

      mMemHandle = CreateFileMapping( INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof( T ), blockName.c_str() );
      if ( mMemHandle == NULL )
      {
         std::stringstream tStream;
         tStream << "Unable to create file mapping for " << blockName << ". " << GetLastError();
         throw (const char*)tStream.str().c_str();
         return NULL;
      }

      mMapView = ( T * ) MapViewOfFile( mMemHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof( T ) );
      if ( mMapView == NULL )
      {
         std::stringstream tStream;
         tStream << "Unable to map shared memory to " << blockName << ". " << GetLastError();
         throw (const char*)tStream.str().c_str();
         return NULL;
      }

      return mMapView;
   }

   bool IsOpen() { return ( ( mMapView != NULL ) && ( mMemHandle != NULL ) ); }

   T* operator->()
   {
      return mMapView;
   }

   T* operator()()
   {
      return mMapView;
   }

private:
   T* mMapView;
   HANDLE mMemHandle;
};