using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace CodeQualityChecker
{
    class Tester
    {
        //List of file names
        private readonly List<CodeFile> fileList;
        //List of arrays of file contents separated by line
        //private Tuple<List<string>,List<string[]>> fileListContent;
        

        public Tester(ref List<CodeFile> fileList)
        {
            this.fileList = fileList;
        }
        /**
         * Runs the tests for each file which has been selected
         */
        public List<CodeFile> RunTests() 
        {
            foreach(CodeFile file in fileList)
            {
                InitializeFileListContent(file);
                CheckSpaces(file);
                EqualityOperatorCheck(file);
                SemicolonCheck(file);
                ClassFinder(file);
                EmptyLineChecker(file);
            }
            return fileList;
        }
        
        /**
         * Accesses each file and turns the file contents into an array where each line is one string
         */
        private void InitializeFileListContent(CodeFile file)
        {

            string[] textFileContent;
            textFileContent = File.ReadAllLines(file.FileName, Encoding.UTF8);
            file.FileContent = textFileContent;

        }
        private void CheckSpaces(CodeFile file)
        {
            var fileContent = file.FileContent;
            int spaceCount = 0;
            int lineNum = 1;
            file.FileIndentations = new int[fileContent.Length];
            foreach (string line in fileContent)
            {
                spaceCount = line.TakeWhile(Char.IsWhiteSpace).Count();
                file.FileIndentations[lineNum-1] = spaceCount;
                lineNum++;
            }
        }


        /**
         * Checks line by line if the code contains a conditional or loop statement using comparisons as well as incorrect = operators.
         * It then through those comparisons to see which ones act more like a variable declaration.
         * Regex adapted from here: https://stackoverflow.com/questions/30108567/regex-for-comparison-expression
         */
        private void EqualityOperatorCheck(CodeFile file)
        {
            file.ComparisonStatements.Clear();
            //This pattern checks for all kinds of comparisons which may happen within conditional or loop statements,
                //but also including an accidental variable declaration in the form of "=" to be processed later
            string pattern = @"\((?>(?![<>=]=|!=|[<>]).)*?(?:[<>=]=|=|!=|[<>])(?>(?![<>=]=|!=|[<>]).)*?\)";
            Regex r = new Regex(pattern, RegexOptions.IgnoreCase);
            string errorPattern = @"\((?>(?![<>=]=|!=|[<>]).)*?(?:=)(?>(?![<>=]|!=|[<>]).)[^;]*?\)";
            Regex e = new Regex(errorPattern, RegexOptions.IgnoreCase);
            int lineNumber;
            lineNumber = 1;
            foreach (string text in file.FileContent)
            {
                //Matches with lines that use comparison operators
                Match m = r.Match(text);
                if (m.Success)
                {
                    Match errorMatch = e.Match(text);
                    if (errorMatch.Success)
                    {
                        file.ComparisonStatements.Add(new Tuple<int, bool>(lineNumber, true));
                        Console.WriteLine(errorMatch.Value);
                    }
                    else
                    {
                        file.ComparisonStatements.Add(new Tuple<int, bool>(lineNumber, false));  
                    }
                }    
                lineNumber++;
            }
        }  
        /**
         * Checks for misplaced semicolons in the middle of lines. Unfortunately also catches them in for loops
         */
        private void SemicolonCheck(CodeFile file)
        {
            string pattern = @";([^\s|/])";
            Regex r = new Regex(pattern, RegexOptions.IgnoreCase);
            int lineNumber = 1;
            foreach(string text in file.FileContent)
            {
                Match m = r.Match(text);
                if (m.Success)
                {
                    file.SemicolonErrors.Add(lineNumber);
                }
                lineNumber++;
            }
        }
        /**
         * An attempt at recognizing method declarations in the code.
         * Does not work given how in C++, methods can simply be declared with: int a(){}, and the {} dont have to be on the same line
         */
        private void MethodFinder(CodeFile file)
        {
            string pattern = @"^(^|\s)(public|private|protected)\s\w+";
            Regex r = new Regex(pattern, RegexOptions.IgnoreCase);
            int lineNumber = 1;
            foreach(string text in file.FileContent)
            {
                Match m = r.Match(text);
                if (m.Success)
                {

                }
                lineNumber++;
            }
        }
        /**
         * Checks through each line for if it uses class declaration language, and then checks if its name starts with a capital letter
         */
        private void ClassFinder(CodeFile file)
        {
            string pattern = @"^(^|\s*)(class|struct)\s(\w+)\s*({|:|$|\/)";
            Regex r = new Regex(pattern, RegexOptions.IgnoreCase);
            int lineNumber = 1;
            foreach (string text in file.FileContent)
            {
                Match m = r.Match(text);
                if (m.Success)
                {
                    string className = m.Groups[3].Value;
                    bool badClassName = char.IsLower(className.ToCharArray()[0]);
                    file.ClassInstances.Add(new Tuple<int,bool,string>(lineNumber, badClassName, className));
                }
                lineNumber++;
            }
        }

        /**
         * Records how many lines of each file are empty
         */
        private void EmptyLineChecker(CodeFile file)
        {
            string pattern = @"^\s*$";
            Regex r = new Regex(pattern, RegexOptions.IgnoreCase);
            foreach (string text in file.FileContent)
            {
                Match m = r.Match(text);
                if (m.Success)
                {
                    file.EmptyLineCount++;
                }
                
            }
        }
    }


}
