clear
echo ==================
echo [BUILDING PROJECT]
echo ==================

if [ -z ${clearbin} ]; then 
    clearbin=0
fi
if [ -z ${autoexec} ]; then 
    autoexec=0
fi

if [ 1 -eq ${clearbin} ]; then
    echo Clearing bin/bin-int dirs
    rm -rf bin bin-int
else 
    echo Caching bin/bin-int dirs
fi

premake5 gmake
make $1
echo ================
echo [FINISHED BUILD]
echo ================
if [ 1 -eq ${autoexec} ]; then
    config=$1
    if [ -z "$config" ]; then 
        config="config=debug"
    fi
    if [ "config=debug" == "$config" ]; then
        echo
        echo ==============
        echo [STARTING APP]
        echo ==============
        echo Config: Debug
        bin/linux-x86_64-Debug/sandbox/sandbox
    elif [ "config=release" == "$config" ]; then 
            echo [STARTING APP]
            echo [Config: Release]
            bin/linux-x86_64-Release/sandbox/sandbox
    else
        echo [Aborted Launch]
        echo [Config Unknown]
    fi
fi