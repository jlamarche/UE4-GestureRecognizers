#!/bin/sh
if [ $DEPLOYMENT_LOCATION = "YES" ]
then
cp -R Engine/Binaries/IOS/Payload/libUE4XcodeHelper.a/ $DSTROOT/$LOCAL_APPS_DIR/libUE4XcodeHelper.a
fi
