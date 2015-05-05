#!/bin/sh
if [ $DEPLOYMENT_LOCATION = "YES" ]
then
cp -R GestureSample/Binaries/IOS/Payload/GestureSample.app/ $DSTROOT/$LOCAL_APPS_DIR/GestureSample.app
fi
