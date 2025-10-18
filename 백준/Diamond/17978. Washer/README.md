# [Diamond IV] Washer - 17978 

[문제 링크](https://www.acmicpc.net/problem/17978) 

### 성능 요약

메모리: 2024 KB, 시간: 448 ms

### 분류

수학, 브루트포스 알고리즘, 기하학, 3차원 기하학

### 제출 일자

2025년 10월 18일 21:47:24

### 문제 설명

<p>You have <em>n</em> clothes and a washer. The washer is large enough to wash all clothes at once. However, we should worry about the color transfer: if we put clothes of different colors in the washer, the dye from one may stain another. Precisely, let <em>r<sub>i</sub></em>, <em>g<sub>i</sub></em>, <em>b<sub>i</sub></em> denote the amount of red, green, blue color of the <em>i</em>-th clothes. When <em>n</em> clothes are washed together, the <em>color transfer</em> <em>c</em> is defined by</p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;" display="true"> <mjx-math display="true" style="margin-left: 0px; margin-right: 0px;" class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-munderover space="4"><mjx-over style="padding-bottom: 0.192em; padding-left: 0.51em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-over><mjx-box><mjx-munder><mjx-row><mjx-base><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em; padding-left: 0.148em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-under></mjx-row></mjx-munder></mjx-box></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.413em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D454 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D454 TEX-I"></mjx-c></mjx-mi><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.413em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44F TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D44F TEX-I"></mjx-c></mjx-mi><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.413em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>c</mi><mo>=</mo><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>i</mi><mo>=</mo><mn>1</mn></mrow><mrow data-mjx-texclass="ORD"><mi>n</mi></mrow></munderover><mrow data-mjx-texclass="ORD"><mo stretchy="false">(</mo><msub><mi>r</mi><mi>i</mi></msub><mo>−</mo><mi>r</mi><msup><mo stretchy="false">)</mo><mn>2</mn></msup><mo>+</mo><mo stretchy="false">(</mo><msub><mi>g</mi><mi>i</mi></msub><mo>−</mo><mi>g</mi><msup><mo stretchy="false">)</mo><mn>2</mn></msup><mo>+</mo><mo stretchy="false">(</mo><msub><mi>b</mi><mi>i</mi></msub><mo>−</mo><mi>b</mi><msup><mo stretchy="false">)</mo><mn>2</mn></msup></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[c = \sum_{i=1}^{n}{(r_i - r)^2 + (g_i - g)^2 + (b_i - b)^2}\]</span> </mjx-container></p>

<p>where <em>r</em>, <em>g</em>, and <em>b</em> are the averages of <em>r<sub>i</sub></em>, <em>g<sub>i</sub></em>, <em>b<sub>i</sub></em>, respectively. The <em>i</em>-th clothes with <em>r<sub>i</sub></em>, <em>g<sub>i</sub></em>, and <em>b<sub>i</sub></em> is defined as a point (<em>r<sub>i</sub></em>, <em>g<sub>i</sub></em>, <em>b<sub>i</sub></em>) in 3-dimensional RGB space. You can assume that no three points (clothes) are on a same line and no four points (clothes) are on a same plane in RGB space.</p>

<p>The washer consumes a lot of electricity, and you have to partition <em>n</em> clothes into at most <em>k</em> groups, and run the washer for each group. The total color transfer is the sum of color transfers from each run. Given the color information of <em>n</em> clothes and <em>k</em>, write a program to calculate the minimum total color transfer.</p>

### 입력 

 <p>Your program is to read from standard input. The first line contains two integers <em>n</em> (1 ≤ <em>n</em> ≤ 100) and <em>k</em> (1 ≤ <em>k</em> ≤ 2). In the following <em>n</em> lines, the <em>i</em>-th line contains three integers <em>r<sub>i</sub></em>, <em>g<sub>i</sub></em>, <em>b<sub>i</sub></em> (0 ≤ <em>r<sub>i</sub></em>, <em>g<sub>i</sub></em>, <em>b<sub>i</sub></em> ≤ 1,000).</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line containing the minimum total color transfer, rounded to the sixth decimal point.</p>

