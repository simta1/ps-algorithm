# [Platinum IV] Beauty of tree - 23911 

[문제 링크](https://www.acmicpc.net/problem/23911) 

### 성능 요약

메모리: 121068 KB, 시간: 1004 ms

### 분류

수학, 다이나믹 프로그래밍, 그래프 이론, 자료 구조, 그래프 탐색, 트리, 깊이 우선 탐색, 트리에서의 다이나믹 프로그래밍, 확률론, 방향 비순환 그래프, 희소 배열, 기댓값의 선형성

### 제출 일자

2025년 10월 16일 21:13:43

### 문제 설명

<p>Amadea and Bilva are decorating a rooted tree containing <b>N</b> nodes, labelled from 1 to <b>N</b>. Node 1 is the root of the tree, and all other nodes have a node with a numerically smaller label as their parent.</p>

<p>Amadea and Bilva's decorate the tree as follows:</p>

<ul>
	<li>Amadea picks a node of the tree uniformly at random and paints it. Then, she travels up the tree painting every <b>A</b>-th node until she reaches the root.</li>
	<li>Bilva picks a node of the tree uniformly at random and paints it. Then, she travels up the tree painting every <b>B</b>-th node until she reaches the root.</li>
</ul>

<p>The <i>beauty</i> of the tree is equal to the number of nodes painted <i>at least once</i> by either Amadea or Bilva. Note that even if they both paint a node, it only counts once.</p>

<p>What is the <a href="https://en.wikipedia.org/wiki/Expected_value">expected</a> beauty of the tree?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. Each test case begins with a line containing the three integers <b>N</b>, <b>A</b> and <b>B</b>. The second line contains <b>N</b>-1 integers. The i-th integer is the parent of node i+1.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is the expected beauty of the tree.</p>

<p><code>y</code> will be considered correct if it is within an absolute or relative error of 10<sup>-6</sup> of the correct answer.</p>

