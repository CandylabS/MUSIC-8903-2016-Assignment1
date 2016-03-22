# CMake generated Testfile for 
# Source directory: /Users/ssmilkshake/Documents/MUSIC-8903-2016
# Build directory: /Users/ssmilkshake/Documents/MUSIC-8903-2016-Assignment1
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AudioIo "/Users/ssmilkshake/Documents/MUSIC-8903-2016/bin/TestExec" "AudioIo" "/Users/ssmilkshake/Documents/MUSIC-8903-2016/src/Tests/TestData/")
add_test(CombFilter "/Users/ssmilkshake/Documents/MUSIC-8903-2016/bin/TestExec" "CombFilter")
add_test(Dtw "/Users/ssmilkshake/Documents/MUSIC-8903-2016/bin/TestExec" "Dtw")
add_test(RingBuff "/Users/ssmilkshake/Documents/MUSIC-8903-2016/bin/TestExec" "RingBuff")
add_test(Vibrato "/Users/ssmilkshake/Documents/MUSIC-8903-2016/bin/TestExec" "Vibrato")
subdirs(MUSI8903Exec)
subdirs(AudioFileIO)
subdirs(CombFilter)
subdirs(Dtw)
subdirs(Vibrato)
subdirs(TestExec)
