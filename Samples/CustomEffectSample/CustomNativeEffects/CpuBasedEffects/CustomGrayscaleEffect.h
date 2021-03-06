//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
#pragma once

#pragma warning(push)
#pragma warning(disable: 4973)

namespace CustomNativeEffects {

	using namespace Lumia::Imaging;

	public ref class CustomGrayscaleEffect sealed : IImageProvider2, IImageConsumer2
	{
	internal:
		struct Properties final
		{
			Properties()
			{
				
			}		
		};

	public:
		CustomGrayscaleEffect();


#pragma region IImageConsumer implementation

		virtual property IImageProvider^ Source
		{
			IImageProvider^ get();
			void set(IImageProvider^ value);
		}

#pragma endregion

#pragma region IImageConsumer2 implementation

		virtual property uint32 SourceCount
		{
			uint32 get();
		}

		virtual void GetSources(Platform::WriteOnlyArray<IImageProvider2^>^ sources);

		virtual void SetSource(uint32 sourceIndex, IImageProvider2^ source);

#pragma endregion

#pragma region IImageProvider implementation

		virtual Windows::Foundation::IAsyncAction^ PreloadAsync()
		{
			throw ref new Platform::NotImplementedException();
		}

		virtual Windows::Foundation::IAsyncOperation<Bitmap^>^ GetBitmapAsync(Bitmap^ bitmap, OutputOption outputOption)
		{
			throw ref new Platform::NotImplementedException();
		}

		virtual Windows::Foundation::IAsyncOperation<ImageProviderInfo^>^ GetInfoAsync()
		{
			throw ref new Platform::NotImplementedException();
		}

		virtual bool Lock(RenderRequest^ renderRequest)
		{
			throw ref new Platform::NotImplementedException();
		}

#pragma endregion

#pragma region IImageProvider2 implementation

		virtual property RenderOptions SupportedRenderOptions
		{
			RenderOptions get();
		}

		virtual IImageProvider2^ Clone();

		virtual Workers::IImageWorker^ CreateImageWorker(Workers::IImageWorkerRequest^ imageWorkerRequest);

#pragma endregion

	
	private:
		concurrency::critical_section m_criticalSection;
		IImageProvider2^ m_source;
		Properties m_properties;
	};
}

#pragma warning(pop)
