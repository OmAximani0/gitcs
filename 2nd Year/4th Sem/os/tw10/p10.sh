echo "Enter the current working directory name"

read dir
ls -l > f2.txt
grep '^d' f2.txt > g1.txt

echo "The Number of Directories in the Current Working Directory is"
wc -l g1.txt 
grep '^-' f2.txt > g1.txt

echo "The number of files in the current working directory is"
wc -l g1.txt

echo "Enter The Name of the file"
read file
ls -l $file

chmod u+x,g+w $file
echo " The file after changing the permission is"
ls -l $file
