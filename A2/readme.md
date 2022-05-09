This is a project that I forgot for quite some time and I am now doing the last bits with a different mind. A2 MS4 can look very different from the prior milestones.

In both MS3 and MS4, there are certain entries of birth year that align with the current year (time.h):

```Enter birth year (current age must be between 18 and 110): 2004```

```ERROR: Value must be between 1911 and 2003 inclusive: 1910```

```ERROR: Value must be between 1911 and 2003 inclusive: 2003```

This was back in 2021. For your output to align the best with this output from 2021, use

```Current year - 110, such as 1912 for the year 2022```

```Current year - 18, such as 2004 for the year 2022```

The lowest birth year and highest should be 1911 and 2003 for 2021, and 1912 and 2004 for 2022, and so on.
In MS4, apart from birth years, there is the change of file content for accounts.txt and tickets.txt whose content will be transferred into accounts_arc.txt and tickets_arc.txt. If you want to test the original expected output again, try to reset using the original files that I keep. Consider a batch file for this.
