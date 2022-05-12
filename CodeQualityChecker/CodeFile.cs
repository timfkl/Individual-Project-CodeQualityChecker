using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeQualityChecker
{
    public class CodeFile
    {
        
        private string _fileName;
        private string[] _fileContent;
        private int[] _fileIndentations;
        private List<Tuple<int, bool>> _comparisonStatements;
        private List<int> _semicolonErrors;
        private List<Tuple<int, bool, string>> _classInstances;
        private int _emptyLineCount;
        public CodeFile(string fileName)
        {
            FileName = fileName;
            _comparisonStatements = new List<Tuple<int, bool>>();
            _semicolonErrors = new List<int>();
            _classInstances = new List<Tuple<int, bool, string>>();

        }
        /**
         * The name of the file including directory
         */
        public string FileName { get => _fileName; set => _fileName = value; }
        /**
         * An array containing the contents of the file where each string is a line
         */
        public string[] FileContent { get => _fileContent; set => _fileContent = value; }
        /**
         * An array of how much each line is indented, most of the times a tab is counted as two spaces
         */
        public int[] FileIndentations { get => _fileIndentations; set => _fileIndentations = value; }
        /**
         * A List of Tuples of an int + a bool.
         *The integer is the line number (starting from 0), and the bool being true means that the comparison uses = instead of a normal operator
         */
        public List<Tuple<int, bool>> ComparisonStatements { get => _comparisonStatements; set => _comparisonStatements = value; }
        /**
         * List of line numbers that have incorrectly placed semicolons
         */
        public List<int> SemicolonErrors { get => _semicolonErrors; set => _semicolonErrors = value; }
        public List<Tuple<int,bool, string>> ClassInstances { get => _classInstances; set => _classInstances = value; }
        public int EmptyLineCount { get => _emptyLineCount; set => _emptyLineCount = value; }
    }
}
