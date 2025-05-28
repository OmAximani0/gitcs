echo "The present working directory is "
pwd

echo "Enter the directory name which you want to be a current directory"

read dir
cd $dir
mkdir os_lab

echo "The directory named os_lab is created"
echo "Enter the name of the directory to be removed"
read r
rmdir $r

echo "Enter the source and destination file name"
read s1
read s2
cp $s1 $s2
mv $s1 $s2
echo "Both the files have moved to os_lab"
ls -l os_lab

echo "Enter the name of the file to be removed"
read f
rm $f
echo "The file $f is removed successfully"
