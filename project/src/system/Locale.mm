#ifdef HX_MACOS
#import <Cocoa/Cocoa.h>
#else
#import <UIKit/UIKit.h>
#endif

#include <system/Locale.h>


namespace lime {


	std::string* Locale::GetSystemLocale () {

		#ifndef OBJC_ARC
		NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
		#endif

		NSString* localeLanguage = [[NSLocale preferredLanguages] firstObject];
		NSString* localeRegion = [[NSLocale currentLocale] countryCode];
		NSString* locale = [[localeLanguage stringByAppendingString:@"_"] stringByAppendingString:localeRegion];

		std::string* result = 0;

		if (locale) {

			const char* ptr = [locale UTF8String];
			result = new std::string (ptr);

		}

		#ifndef OBJC_ARC
		[pool drain];
		#endif

		return result;

	}


}